
#include <llvm/IR/DerivedTypes.h>
#include <llvm/Pass.h>
#include <llvm/Support/TargetSelect.h>

#include "llvm_util.h"

#include "inter_gen/codeGen_inter.h"
#include "string_util.h"

namespace dap::util
{
static std::unordered_map<std::string, llvm::Type *> typeMap = {};

llvm::Type *typeOf(const parser::TypeNode *type, const inter_gen::InterGenContext *ctx, parser::Expression *size)
{
    if (type == nullptr) {
        return llvm::Type::getVoidTy(LLVMCTX);
    }

    llvm::Type *res = nullptr;

    for (auto &[key, val] : typeMap) {
        if (key == type->getName()) {
            res = val;
        }
    }

    if (llvm::StructType *structType = llvm::StructType::getTypeByName(LLVMCTX, type->getName())) {
        res = structType;
    }

    if (type->isArray) {
        res = llvm::ArrayType::get(res, type->arraySize);
    }

    if (type->isPointer) {
        if (res) {
            auto tmpRes = llvm::PointerType::get(res, 0);
            inter_gen::pointerMap.emplace(tmpRes, res);
            res = tmpRes;
        }
        res = llvm::PointerType::get(LLVMCTX, 0);
    }

    return res;
}

void initTypeMap(llvm::LLVMContext &llvmCtx)
{
    typeMap.emplace(std::string("int"), llvm::Type::getInt32Ty(llvmCtx));
    typeMap.emplace(std::string("int"), llvm::Type::getInt32Ty(llvmCtx));
    typeMap.emplace(std::string("byte"), llvm::Type::getInt8Ty(llvmCtx));
    typeMap.emplace(std::string("short"), llvm::Type::getInt16Ty(llvmCtx));
    typeMap.emplace(std::string("long"), llvm::Type::getInt64Ty(llvmCtx));
    typeMap.emplace(std::string("char"), llvm::Type::getInt8Ty(llvmCtx));
    typeMap.emplace(std::string("float"), llvm::Type::getFloatTy(llvmCtx));
    typeMap.emplace(std::string("string"), llvm::PointerType::get(llvm::Type::getInt8Ty(llvmCtx), 0));
    typeMap.emplace(std::string("bool"), llvm::Type::getInt1Ty(llvmCtx));
    typeMap.emplace(std::string("uint"), llvm::Type::getInt32Ty(llvmCtx));
    typeMap.emplace(std::string("ushort"), llvm::Type::getInt16Ty(llvmCtx));
    typeMap.emplace(std::string("ulong"), llvm::Type::getInt64Ty(llvmCtx));
    typeMap.emplace(std::string("llong"), llvm::Type::getInt128Ty(llvmCtx));
    typeMap.emplace(std::string("ullong"), llvm::Type::getInt128Ty(llvmCtx));
    typeMap.emplace(std::string("double"), llvm::Type::getDoubleTy(llvmCtx));
    typeMap.emplace(std::string("void"), llvm::Type::getVoidTy(llvmCtx));
}

void initTargets()
{

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();
}

llvm::AllocaInst *createAllocaInst(llvm::Type *type, llvm::IRBuilder<> &builder, const std::string &name,
                                   llvm::LLVMContext *llvmContext)
{
    if (type->isArrayTy()) {
        const uint64_t array_num_elements = type->getArrayNumElements();
        return builder.CreateAlloca(
            type, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*llvmContext), llvm::APInt(32, array_num_elements)),
            name);
    }
    return builder.CreateAlloca(type, nullptr, name);
}

llvm::Value *toBool(llvm::Value *src, inter_gen::InterGenContext *ctx)
{
    // Normalize condition to boolean (for integer, floating point, or pointer
    // types)
    if (llvm::Type *condType = src->getType(); condType->isIntegerTy()) {
        src = BUILDER.CreateICmpNE(src, llvm::ConstantInt::get(condType, 0), "boolValue");
        return src;
    } else {
        if (condType->isFloatingPointTy()) {
            src = BUILDER.CreateFCmpONE(src, llvm::ConstantFP::get(condType, 0.0), "boolValue");
            return src;
        }
        if (condType->isPointerTy() || condType->isArrayTy()) {
            src = BUILDER.CreateICmpNE(src, llvm::ConstantPointerNull::get(cast<llvm::PointerType>(condType)),
                                       "boolValue");
            return src;
        }
    }
#ifdef D_DEBUG
    logWarn("Unsupported type for boolean conversion: " + util::getTypeName(src->getType(), ctx), ctx, __FILE__,
            __LINE__);
#else
    logWarn("Unsupported type for boolean conversion: " + util::getTypeName(src->getType(), ctx), ctx);
#endif
    return llvm::ConstantInt::getBool(LLVMCTX, false);
}

bool basicBlockEndWithBranchStatement(const llvm::BasicBlock *bb, const inter_gen::InterGenContext *ctx)
{
    auto bbIterator = bb->end();

    --bbIterator;
    if (bbIterator->getOpcode() == llvm::Instruction::Br || bbIterator->getOpcode() == llvm::Instruction::Ret) {
        return true;
    }

    return false;
}

llvm::Value *getLastValue(llvm::BasicBlock *src, inter_gen::InterGenContext *ctx)
{
    auto basicBlockIterator = src->end();
    --basicBlockIterator;

    if (basicBlockIterator->getOpcode() == llvm::Instruction::Ret) {
        return basicBlockIterator->getOperand(0);
    }

    if (basicBlockIterator->getOpcode() == llvm::Instruction::Br) {
        return nullptr;
    }

    return (*basicBlockIterator).getOperand(0);
}

llvm::Constant *createNullValue(llvm::LLVMContext &context, llvm::Type *type)
{
    if (!type)
        return nullptr;

    if (type->isPointerTy()) {
        return llvm::Constant::getNullValue(type);
    }
    if (type->isStructTy()) {
        auto *structType = llvm::cast<llvm::StructType>(type);
        const unsigned numElements = structType->getNumElements();
        std::vector<llvm::Constant *> nullMembers;
        for (unsigned i = 0; i < numElements; ++i) {
            llvm::Type *memberType = structType->getElementType(i);
            if (llvm::Constant *nullMember = createNullValue(context, memberType)) {
                nullMembers.push_back(nullMember);
            }
        }
        return llvm::ConstantStruct::get(structType, nullMembers);
    }
    return llvm::Constant::getNullValue(type);
}

} // namespace dap::util
