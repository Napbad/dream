
#include <llvm/IR/DerivedTypes.h>
#include <llvm/Pass.h>
#include <llvm/Support/TargetSelect.h>

#include "llvm_util.h"

#include "inter_gen/codeGen_inter.h"

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

    if (type->isArray) {
        res = llvm::ArrayType::get(res, type->arraySize);
    }

    if (type->isPointer) {
        res = llvm::PointerType::get(res, 0);
    }

    // maybe struct type
    llvm::StructType *structType = llvm::StructType::getTypeByName(LLVMCTX, type->getName());
    if (structType) {
        return structType;
    }

    return res;
}

void initTypeMap(llvm::LLVMContext *llvmCtx)
{
    typeMap.emplace(std::string("int"), llvm::Type::getInt32Ty(*llvmCtx));
    typeMap.emplace(std::string("int"), llvm::Type::getInt32Ty(*llvmCtx));
    typeMap.emplace(std::string("byte"), llvm::Type::getInt8Ty(*llvmCtx));
    typeMap.emplace(std::string("short"), llvm::Type::getInt16Ty(*llvmCtx));
    typeMap.emplace(std::string("long"), llvm::Type::getInt64Ty(*llvmCtx));
    typeMap.emplace(std::string("char"), llvm::Type::getInt8Ty(*llvmCtx));
    typeMap.emplace(std::string("float"), llvm::Type::getFloatTy(*llvmCtx));
    typeMap.emplace(std::string("string"), llvm::PointerType::get(llvm::Type::getInt8Ty(*llvmCtx), 0));
    typeMap.emplace(std::string("bool"), llvm::Type::getInt1Ty(*llvmCtx));
    typeMap.emplace(std::string("uint"), llvm::Type::getInt32Ty(*llvmCtx));
    typeMap.emplace(std::string("ushort"), llvm::Type::getInt16Ty(*llvmCtx));
    typeMap.emplace(std::string("ulong"), llvm::Type::getInt64Ty(*llvmCtx));
    typeMap.emplace(std::string("llong"), llvm::Type::getInt128Ty(*llvmCtx));
    typeMap.emplace(std::string("ullong"), llvm::Type::getInt128Ty(*llvmCtx));
    typeMap.emplace(std::string("double"), llvm::Type::getDoubleTy(*llvmCtx));
}

void initTargets()
{

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();
}

llvm::AllocaInst *createAllocaInst(llvm::Type *type, llvm::Value *arraySize, llvm::IRBuilder<> &builder,
                                   const std::string &name, llvm::LLVMContext *llvmContext)
{
    if (type->isArrayTy()) {
        const uint64_t array_num_elements = type->getArrayNumElements();
        return builder.CreateAlloca(
            type, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*llvmContext), llvm::APInt(32, array_num_elements)),
            name);
    }
    return builder.CreateAlloca(type, nullptr, name);
}

} // namespace dap::util
