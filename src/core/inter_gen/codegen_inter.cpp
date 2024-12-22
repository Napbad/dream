//
// Created by napbad on 10/24/24.
//

#include <iostream>
#include <unordered_set>

#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Pass.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/TargetParser/Host.h>
#include <optional>

#include "codegen_inter.h"

#include "basicElementGen_d.h"
#include "check/variableCheck.h"
#include "funGen_sys.h"
#include "preprocessing/includeAnaylize.h"
#include "src/core/common/define_d.h"
#include "src/core/common/derived_type.h"
#include "src/core/common/reserve.h"
#include "src/core/parser/node.h"
#include "src/core/parser/parser.hpp"
#include "src/core/utilities/data_struct_util.h"
#include "src/core/utilities/file_util.h"
#include "src/core/utilities/llvm_util.h"

namespace dap
{
namespace parser
{
using std::map;
using std::string;

// Generates code for an Integer Expression (integer constant)
Value *IntegerExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Return an integer constant (64-bit)
    return ConstantInt::get(LLVMCTX, APInt(INT_BIT_WIDTH, value, true));
}

// Generates code for a Double Expression (floating-point constant)
Value *DoubleExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Return a floating-point constant
    return ConstantFP::get(LLVMCTX, APFloat(value));
}

// Generates code for a String Expression (string constant)
Value *StringExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;

    // Create a constant string (true for null-terminated)
    Constant *stringConstant = ConstantDataArray::getString(LLVMCTX, value, true);
    // Return the pointer to the string constant
    return stringConstant;
}

Value *handleStructName(const QualifiedName *name, inter_gen::InterGenContext *ctx);

// Generates code for a Qualified Name (variable lookup and access)
Value *QualifiedName::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // check the functions
    if (Function *parentFun = ctx->currBlock()->getParent()) {
        for (auto &arg : parentFun->args()) {
            if (arg.getName() == getName()) {
                return &arg;
            }
        }
    }
    // Check if the variable is declared in the current scope
    if (!ctx->getVal(getFirstName())) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnknown variable name " + getFirstName(),
                     __FILE__, __LINE__);
        return nullptr;
    }

    if (name_parts->size() > 1) {
        return handleStructName(this, ctx);
    }

    if (const auto inst = dyn_cast<AllocaInst>(ctx->getVal(getFirstName()))) {
        return BUILDER.CreateLoad(inst->getAllocatedType(), inst, false, getFirstName());
    }

    if (llvm::isa<PointerType>(ctx->getVal(getFirstName())->getType())) {
        return ctx->getVal(getFirstName());
    }

    // Handle the case where the variable is an array, and we need to return a pointer
    if (dyn_cast<AllocaInst>(ctx->getVal(getFirstName()))->getAllocatedType()->isArrayTy()) {
        return BUILDER.CreateGEP(PointerType::getInt8Ty(LLVMCTX), ctx->getVal(getFirstName()),
                                 {ConstantInt::get(IntegerType::get(LLVMCTX, 64), 0)});
    }

    // If it's a pointer type, return a pointer to it
    auto *val = dyn_cast<AllocaInst>(ctx->getVal(getFirstName()));
    const Type *allocatedType = val->getAllocatedType();
    if (llvm::isa<StructType>(allocatedType)) {
        return handleStructName(this, ctx);
    }
    if (allocatedType == PointerType::get(IntegerType::get(LLVMCTX, 8), 0)) {
        return BUILDER.CreateInBoundsGEP(PointerType::getInt8Ty(LLVMCTX), ctx->getVal(getFirstName()),
                                         {ConstantInt::get(IntegerType::get(LLVMCTX, 64), 0)});
    }

    return BUILDER.CreateLoad(val->getAllocatedType(), val, false, getFirstName());
}

Value *handleStructName(const QualifiedName *name, inter_gen::InterGenContext *ctx)
{
    auto [value, metadata] = ctx->locals()[name->getFirstName()];
    Value *currentPtr = value;

    StringRef structName;
    if (gepMapping->contains(value)) {
        structName =
            dyn_cast<StructType>(dyn_cast<AllocaInst>(gepMapping->at(value))->getAllocatedType())->getStructName();
    } else {
        const AllocaInst *allocaInst = dyn_cast<AllocaInst>(ctx->locals()[name->getFirstName()].first);
        if (!allocaInst) {
            REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                             " \nUnknown variable name " + name->getFirstName(),
                         __FILE__, __LINE__);
            return nullptr;
        }
        structName = dyn_cast<StructType>(allocaInst->getAllocatedType())->getStructName();
    }
    const string str = structName.str();
    const inter_gen::StructMetaData *metaData = ctx->structs[str];

    // Traverse through the struct fields
    for (int i = 1; i < name->name_parts->size(); ++i) {
        // Get the field index based on the current struct's metadata
        const unsigned int fieldIndex = metaData->getFieldIndex(name->getName(i));

        // Generate the GEP to get the field pointer
        if (Type *elementType = metaData->getStructType()->getElementType(fieldIndex);
            llvm::isa<StructType>(elementType)) {
            currentPtr = BUILDER.CreateStructGEP(metaData->getStructType(), currentPtr, fieldIndex,
                                                 "struct_" + metaData->getName());
        } else if (llvm::isa<PointerType>(elementType)) {
            currentPtr = BUILDER.CreateStructGEP(elementType, currentPtr, fieldIndex, "struct_" + metaData->getName());
            currentPtr = BUILDER.CreateBitCast(currentPtr, elementType);
            return currentPtr;
        } else {
            currentPtr = BUILDER.CreateLoad(metaData->getStructType()->getElementType(fieldIndex), currentPtr, false,
                                            "struct_" + metaData->getName());
            return currentPtr;
        }

        // If this field is a nested struct, update the struct type and
        // metadata
        if (i < name->name_parts->size() - 1) {
            const auto *nestedStructType = dyn_cast<StructType>(metaData->getStructType()->getElementType(fieldIndex));
            if (!nestedStructType) {
                return nullptr; // Error: not a valid nested struct
            }
            // Update metadata for the nested struct
            metaData = ctx->structs[nestedStructType->getStructName().str()];
            if (!metaData) {
                REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                                 " \nUnknown struct name " + str,
                             __FILE__, __LINE__);
                return nullptr; // Error: metadata for nested struct not
            }
        } else if (i == name->name_parts->size() - 1) {
            if (ctx->structs[name->getName(i)]) {
                return BUILDER.CreateStructGEP(metaData->getFieldType(name->getName(i)), currentPtr,
                                               metaData->getFieldIndex(name->getName(i)),
                                               "struct_" + metaData->getName());
            }
            return BUILDER.CreateGEP(metaData->getFieldType(name->getName(i)), currentPtr,
                                     ConstantInt::get(Type::getInt32Ty(LLVMCTX), fieldIndex), name->getName(i));
        } else {
            REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                             " \nUnknown variable name " + name->getName(i),
                         __FILE__, __LINE__);
        }
    }
    return nullptr;
}

Value *handleArgumentArrayExpr(const ArrayExpr *Expr, Value *arrVal, inter_gen::InterGenContext *ctx,
                               const Function *fun, Value *idxVal)
{
    auto *arr = dyn_cast<Argument>(arrVal);
    Type *ptrType = arr->getType();

    if (llvm::isa<PointerType>(ptrType)) {

        Type *baseType = nullptr;
        for (const auto funMetaData : ctx->metaData->getFunctions()) {
            if (funMetaData->getName() == fun->getName() && funMetaData->getArg(Expr->name->getName())) {
                baseType = funMetaData->getArgType(Expr->name->getName());
                if (dyn_cast<PointerType_d>(baseType)) {
                    const PointerType_d *ptr = dyn_cast<PointerType_d>(baseType);
                    baseType = ptr->getBaseTy();
                }
            }
        }
        if (!baseType) {
            REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) + " \nUnknown base type",
                         __FILE__, __LINE__);
            return nullptr;
        }

        // Step 2: Create a GEP instruction to access the array element
        const std::vector indices = {
            idxVal // Index
        };
        Value *ptrAdd = BUILDER.CreatePtrAdd(arr, idxVal, "array_access_ptr");

        return BUILDER.CreateLoad(baseType, ptrAdd, "array_access_load");
    }
    if (llvm::isa<ArrayType>(ptrType)) {
        Value *arrayPtr = BUILDER.CreateLoad(ptrType->getPointerTo(), arr, "array_ptr");

        // Step 2: Create a GEP instruction to access the array element
        const std::vector<Value *> indices = {
            ConstantInt::get(Type::getInt32Ty(LLVMCTX), 0),
            idxVal // Index
        };
        Value *elementValue = BUILDER.CreateGEP(ptrType, arrayPtr, indices, "array_access");

        return BUILDER.CreateLoad(ptrType->getArrayElementType(), elementValue, "array_access_load");
    }
    REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                     " \nVariable must be of array type or pointerType",
                 __FILE__, __LINE__);
    return nullptr;
}

Value *handleAllocaArrayExpr(Value *arrVal, inter_gen::InterGenContext *ctx, Value *idxVal)
{
    auto *arr = dyn_cast<AllocaInst>(arrVal);
    if (llvm::isa<ArrayType>(arr->getAllocatedType())) {
        Type *arrType = arr->getAllocatedType();
        Value *arrayPtr = BUILDER.CreateLoad(arrType->getPointerTo(), arr, "array_ptr");

        // Step 2: Create a GEP instruction to access the array element
        const std::vector<Value *> indices = {
            ConstantInt::get(Type::getInt32Ty(LLVMCTX), 0),
            idxVal // Index
        };
        Value *elementValue = BUILDER.CreateGEP(arrType, arrayPtr, indices, "array_access");

        return BUILDER.CreateLoad(arrType->getArrayElementType(), elementValue, "array_access_load");
    }
    Type *arrType = arr->getAllocatedType();
    if (!llvm::isa<PointerType>(arrType)) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nVariable must be of array type",
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Step 3: Load the pointer to the array (dereference the alloca)
    Value *arrayPtr = BUILDER.CreateLoad(arrType->getPointerTo(), arr, "array_ptr");

    // Step 2: Create a GEP instruction to access the array element
    const std::vector indices = {
        idxVal // Index
    };

    Value *elementValue = BUILDER.CreateGEP(arrType, arrayPtr, indices, "array_access");

    return BUILDER.CreateLoad(arrType->getArrayElementType(), elementValue, "array_access_load");
}

Value *ArrayExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Step 1: Generate code for the index Expression
    Value *indexValue = idx->codeGen(ctx);
    if (!indexValue) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nError in generating code for the index Expression",
                     __FILE__, __LINE__);
        return nullptr;
    }
    if (!llvm::isa<IntegerType>(indexValue->getType()) && !llvm::isa<ConstantInt>(indexValue) &&
        !llvm::isa<IntegerType>(indexValue->getType())) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nIndex Expression must evaluate to an integer",
                     __FILE__, __LINE__);
        return nullptr; // Error in generating code for the index
    }
    Value *arrVal = ctx->getVal(name->getName());
    if (!llvm::isa<AllocaInst>(arrVal) && !llvm::isa<Argument>(arrVal)) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nMapped value must be an alloca instruction or argument",
                     __FILE__, __LINE__);
        return nullptr;
    }

    if (llvm::isa<Argument>(arrVal)) {
        return handleArgumentArrayExpr(this, arrVal, ctx, ctx->currBlock()->getParent(), indexValue);
    }
    if (llvm::isa<AllocaInst>(arrVal)) {
        return handleAllocaArrayExpr(arrVal, ctx, indexValue);
    }

    REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) + " \nUnknown variable type",
                 __FILE__, __LINE__);
    return nullptr;
}

// generate the value of the Pointer
Value *PointerExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Generate the LLVM IR value for the base Expression
    Value *base_value = baseVal->codeGen(ctx);

    if (!base_value) {
        // If the base Expression does not generate a valid value, return null
        return nullptr;
    }

    // Get the type of the base value
    Type *base_type = base_value->getType();

    // If the base value is already a pointer, return it directly
    if (base_type->isPointerTy()) {
        return base_value;
    }

    // If the base value is not a pointer, create a pointer to it
    // For example, if base_value is an integer, create a pointer to that integer

    // Create an alloca instruction to allocate space for the base value on the stack
    AllocaInst *alloca = BUILDER.CreateAlloca(base_type, nullptr, "ptr_temp");

    // Store the base value in the allocated space
    BUILDER.CreateStore(base_value, alloca);

    // Return the address of the allocated space, which is a pointer to the base value
    return alloca;
}

// Generates code for a Binary Expression (arithmetic, comparison, etc.)
Value *BinaryExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Generate code for left-hand side and right-hand side Expressions
    Value *lhsVal = lhs->codeGen(ctx);
    Value *rhsVal = rhs->codeGen(ctx);

    // Check for null results from the code generation
    if (!lhsVal || !rhsVal)
        return nullptr;

    if (llvm::isa<PointerType>(lhsVal->getType())) {
        lhsVal = BUILDER.CreatePtrToInt(lhsVal, Type::getInt64Ty(LLVMCTX));
    }
    if (llvm::isa<PointerType>(rhsVal->getType())) {
        rhsVal = BUILDER.CreatePtrToInt(rhsVal, Type::getInt64Ty(LLVMCTX));
    }

    // Check if both operands are of the same type
    const auto lhsType = lhsVal->getType();
    if (const auto rhsType = rhsVal->getType(); lhsType != rhsType) {
        if (llvm::isa<IntegerType>(lhsType) && llvm::isa<IntegerType>(rhsType)) {
            if (lhsType->getIntegerBitWidth() > rhsType->getIntegerBitWidth()) {
                rhsVal = BUILDER.CreateSExtOrTrunc(rhsVal, lhsType, "sext_or_trunc");
            } else if (lhsType->getIntegerBitWidth() < rhsType->getIntegerBitWidth()) {
                lhsVal = BUILDER.CreateSExtOrTrunc(lhsVal, rhsType, "sext_or_trunc");
            }
        } else {
            REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                             " \nType mismatch in binary Expression",
                         __FILE__, __LINE__);
            return nullptr;
        }
    }

    const bool isFloatingPoint = lhsType->isFloatingPointTy();

    // Handle each operator type (arithmetic, comparison, logical, etc.)
    switch (op) {
    // Arithmetic operators
    case PLUS:
        return isFloatingPoint ? BUILDER.CreateFAdd(lhsVal, rhsVal, "addtmp")
                               : BUILDER.CreateAdd(lhsVal, rhsVal, "addtmp");
    case MINUS:
        return isFloatingPoint ? BUILDER.CreateFSub(lhsVal, rhsVal, "subtmp")
                               : BUILDER.CreateSub(lhsVal, rhsVal, "subtmp");
    case TIMES:
        return isFloatingPoint ? BUILDER.CreateFMul(lhsVal, rhsVal, "multmp")
                               : BUILDER.CreateMul(lhsVal, rhsVal, "multmp");
    case DIVIDE:
        return isFloatingPoint ? BUILDER.CreateFDiv(lhsVal, rhsVal, "divtmp")
                               : BUILDER.CreateSDiv(lhsVal, rhsVal, "divtmp");
    case MOD:
        return isFloatingPoint ? BUILDER.CreateFRem(lhsVal, rhsVal, "modtmp")
                               : BUILDER.CreateSRem(lhsVal, rhsVal, "modtmp");

    // Comparison operators
    case LT:
        return isFloatingPoint ? BUILDER.CreateFCmpOLT(lhsVal, rhsVal, "ltcmp")
                               : BUILDER.CreateICmpSLT(lhsVal, rhsVal, "ltcmp");
    case GT:
        return isFloatingPoint ? BUILDER.CreateFCmpOGT(lhsVal, rhsVal, "gtcmp")
                               : BUILDER.CreateICmpSGT(lhsVal, rhsVal, "gtcmp");
    case LE:
        return isFloatingPoint ? BUILDER.CreateFCmpOLE(lhsVal, rhsVal, "lecmp")
                               : BUILDER.CreateICmpSLE(lhsVal, rhsVal, "lecmp");
    case GE:
        return isFloatingPoint ? BUILDER.CreateFCmpOGE(lhsVal, rhsVal, "gecmp")
                               : BUILDER.CreateICmpSGE(lhsVal, rhsVal, "gecmp");
    case EQ:
        return isFloatingPoint ? BUILDER.CreateFCmpOEQ(lhsVal, rhsVal, "eqcmp")
                               : BUILDER.CreateICmpEQ(lhsVal, rhsVal, "eqcmp");
    case NE:
        return isFloatingPoint ? BUILDER.CreateFCmpONE(lhsVal, rhsVal, "necmp")
                               : BUILDER.CreateICmpNE(lhsVal, rhsVal, "necmp");

    // Logical operators
    case AND:
        return BUILDER.CreateAnd(lhsVal, rhsVal, "andtmp");
    case OR:
        return BUILDER.CreateOr(lhsVal, rhsVal, "ortmp");
    case XOR:
        return BUILDER.CreateXor(lhsVal, rhsVal, "xortmp");

    // Bitwise operators
    case LSHIFT:
        return BUILDER.CreateShl(lhsVal, rhsVal, "lshifttmp");
    case RSHIFT:
        return BUILDER.CreateAShr(lhsVal, rhsVal, "rshifttmp");
    case URSHIFT:
        return BUILDER.CreateLShr(lhsVal, rhsVal, "urshifttmp");

    // Assignment operators
    case ASSIGN:
        return BUILDER.CreateStore(rhsVal, lhsVal);
    case PLUS_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFAdd(lhsVal, rhsVal, "addassigntmp")
                                        : BUILDER.CreateAdd(lhsVal, rhsVal, "addassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case MINUS_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFSub(lhsVal, rhsVal, "subassigntmp")
                                        : BUILDER.CreateSub(lhsVal, rhsVal, "subassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case TIMES_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFMul(lhsVal, rhsVal, "mulassigntmp")
                                        : BUILDER.CreateMul(lhsVal, rhsVal, "mulassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case DIVIDE_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFDiv(lhsVal, rhsVal, "divassigntmp")
                                        : BUILDER.CreateSDiv(lhsVal, rhsVal, "divassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case MOD_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFRem(lhsVal, rhsVal, "modassigntmp")
                                        : BUILDER.CreateSRem(lhsVal, rhsVal, "modassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }

    default:
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnknown binary operator",
                     __FILE__, __LINE__);
        return nullptr;
    }
}

Value *ListExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    if (elements->empty())
        return nullptr;
    const Value *firstVal = elements->at(0)->codeGen(ctx);
    // new a list object
    std::vector<Value *> vals;
    vals.reserve(elements->size());
    for (const auto &e : *elements) {
        vals.push_back(e->codeGen(ctx));
    }

    ArrayType *array = ArrayType::get(firstVal->getType(), vals.size());
    Value *array_val = BUILDER.CreateAlloca(array, nullptr, "array");
    for (unsigned i = 0; i < vals.size(); i++) {
        BUILDER.CreateStore(vals[i], BUILDER.CreateGEP(firstVal->getType(), array_val,
                                                       {ConstantInt::get(LLVMCTX, APInt(INT_BIT_WIDTH, i))},
                                                       "list_elem_" + std::to_string(i)));
    }

    return array_val;
}

// Generates code for a function call Expression
Value *CallExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Look up the callee function by name
    Function *calleeFun = MODULE->getFunction(callee->getName());

    if (calleeFun == nullptr) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnknown function referenced: " + callee->getName(),
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Check if the correct number of arguments are passed
    if (calleeFun->arg_size() != args.size()) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nIncorrect arguments passed",
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Handle system calls if applicable
    if (CallInst *res = handleSys(this, ctx, calleeFun)) {
        return res;
    }

    const inter_gen::FunctionMetaData *funMetaData = ctx->getFunMetaData(callee->getName(), ctx);
    if (funMetaData == nullptr) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnknown function referenced: " + callee->getName(),
                     __FILE__, __LINE__);
        return nullptr;
    }
    // Generate code for each argument
    std::vector<Value *> args_v;
    int argIdx = 0;
    for (const auto &e : args) {
        Type *argType = funMetaData->getArgType(argIdx++);
        if (argType->isPointerTy()) {
            const PointerType_d *pointerType_d = dyn_cast<PointerType_d>(argType);
            expectDerefType_d->push(pointerType_d->getBaseTy());
        } else {
            expectDerefType_d->push(argType);
        }
        args_v.push_back(e->codeGen(ctx));
        if (!args_v.back()) {
            if (argType->isPointerTy()) {
                expectDerefType_d->pop();
            }
            REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                             " \nError in argument " + std::to_string(argIdx - 1),
                         __FILE__, __LINE__);
            return nullptr;
        }
        if (argType->isPointerTy()) {
            expectDerefType_d->pop();
        }
    }

    // Create the function call instruction
    if (calleeFun->getReturnType() == Type::getVoidTy(LLVMCTX)) {
        return BUILDER.CreateCall(calleeFun, args_v);
    }
    return BUILDER.CreateCall(calleeFun, args_v, "calltmp");
}

// Generates code for function prototype (declaration)
Function *ProtoDecl::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Prepare argument types for the function signature
    std::vector<Type *> args_types;
    args_types.reserve(params.size());
    for (const auto &p : params)
        args_types.push_back(util::typeOf(*p->getType(), ctx));

    // Create the functions type (no varargs)
    FunctionType *funTy = FunctionType::get(util::typeOf(*return_type, ctx), args_types, false);

    // Create the functions with external linkage
    Function *fun = Function::Create(funTy, Function::ExternalLinkage, name->getName(), MODULE);

    const auto funMetaData = new inter_gen::FunctionMetaData(name->getName(), funTy);
    ctx->metaData->addFunction(funMetaData);

    // Name the function arguments based on the parameters
    unsigned idx = 0;
    for (auto &arg : fun->args()) {
        funMetaData->addArg(
            params[idx]->getName(), &arg, util::typeOf_d(*params[idx]->type, ctx, nullptr),
            new inter_gen::VariableMetaData(params[idx]->getName(), util::typeOf_d(*params[idx]->type, ctx, nullptr)));
        arg.setName(params[idx++]->getName());
    }

#ifdef D_DEBUG
    LOG_DEBUG("Function " + name->getName() + " defined in " + ctx->module->getName().str());
#endif

    return fun;
}

// Generates code for function definition
Function *FuncDecl::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    std::vector<Type *> argTy;
    argTy.reserve(proto->params.size());
    for (const auto &p : proto->params) {
        argTy.push_back(util::typeOf(*p->getType(), ctx));
    }

    // Create the function proto
    FunctionType *funTy = FunctionType::get(util::typeOf(*proto->return_type, ctx), ArrayRef(argTy), false);
    Function *fun = Function::Create(funTy, Function::ExternalLinkage, proto->name->getName(), MODULE);

    // create the metadata of the function
    const auto funMetaData = new inter_gen::FunctionMetaData(proto->name->getName(), funTy);
    ctx->setCurrFunMetaData(funMetaData);

    // Create the entry basic block and set insert point for the builder
    BasicBlock *bblock = BasicBlock::Create(LLVMCTX, "entry", fun, nullptr);
    BUILDER.SetInsertPoint(bblock);
    ctx->pushBlock(bblock);
    ctx->setCurrFun(fun);
    ctx->metaData->addFunction(funMetaData);

    // Assign names to the function's arguments
    Argument *argsVal = fun->arg_begin();
    for (const auto &param : proto->params) {
        Value *argVal = argsVal++;
        Type *typeOfArg = util::typeOf_d(*param->type, ctx, nullptr);
        funMetaData->addArg(
            param->name->getName(), argVal, typeOfArg,
            new inter_gen::VariableMetaData(param->name->getName(), typeOfArg, param->is_mutable, param->is_nullable));
        argVal->setName(param->getName());
    }

    if (fun->getName() == "main") {
        ctx->setMainFun(fun);
    }

    // Generate the function body
    body->codeGen(ctx);
    if (!blockMappingRet_d->contains(bblock)) {
        BUILDER.CreateRetVoid();
    }
    ctx->popBlock();

    // Verify the function
    verifyFunction(*fun, &errs());
    ctx->metaData->addFunction(funMetaData);
    ctx->setCurrFun(nullptr);

    // If this is the main function, set it in the context
    if (fun->getName() == "main") {
        if (ctx->fileName.ends_with("/main.dap") || ctx->fileName == "main.dap") {
            ctx->setMainFun(fun);
        }
    }

    return fun;
}

// ExternDecl: Generates code for an external function declaration
Function *ExternDecl::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Delegate code generation to the function prototype
    return proto->codeGen(ctx);
}

// Program: Generates code for the entire program, including system functions
// and statements
Value *Program::codeGen(inter_gen::InterGenContext *ctx)
{
    // get the package and setup the package directory
    ctx->currLine = this->line;
    Stmt *stmt = stmts->stmts.at(0);
    stmt->codeGen(ctx);
    const auto packageStmt = dynamic_cast<PackageStmt *>(stmt);
    util::create_package_dir(util::getStrFromVec(*packageStmt->name->name_parts, "."));
    stmts->stmts.erase(stmts->stmts.begin());

    const auto stmtRes = stmts->codeGen(ctx);

    if (ctx->package == "dap.runtime.sys" && ctx->sourcePath.ends_with("/sysFun.dap")) {
        genSysFun(ctx);
    }

    if (ctx->package == "dap.std.type" && ctx->sourcePath.ends_with("/convert.dap")) {
        genCharToInt(ctx);
        genIntToChar(ctx);
        genCharToStr(ctx);
        genInt32To8(ctx);
    }

    // Generate code for program statements
    return stmtRes;
}

Value *mergeBlock(Value *thenBody, BasicBlock *thenBB, BasicBlock::iterator thenBBEndIter, Value *elseBody,
                  BasicBlock *elseBB, BasicBlock::iterator elseBBEndIter, inter_gen::InterGenContext *ctx)
{
    PHINode *phi;

    if (thenBody != nullptr && thenBBEndIter->getOpcode() != Instruction::Ret &&
        thenBBEndIter->getType() != Type::getVoidTy(LLVMCTX)) {
        // If there is a result from the then block, create a PHI node to merge
        phi = BUILDER.CreatePHI(thenBody->getType(), 2, "iftmp");
        phi->addIncoming(thenBody, thenBB);
        if (elseBody)
            phi->addIncoming(elseBody, elseBB);
        else
            phi->addIncoming(ConstantInt::get(thenBody->getType(), 0), elseBB);
    } else if (elseBody != nullptr && elseBBEndIter->getOpcode() != Instruction::Ret &&
               elseBBEndIter->getType() != Type::getVoidTy(LLVMCTX)) {
        // If there is no result from the then block but there is from the else
        // block
        phi = BUILDER.CreatePHI(elseBody->getType(), 2, "iftmp");
        phi->addIncoming(ConstantInt::get(elseBody->getType(), 0), thenBB);
        phi->addIncoming(elseBody, elseBB);
    } else {
        return ConstantInt::get(IntegerType::get(LLVMCTX, 0), 0); // Return 0 (no result)
    }

    return phi; // Return the result of the condition
}

// IfStmt: Generates code for an if statement
Value *IfStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Generate code for the condition Expression
    Value *condVal = cond->codeGen(ctx);
    if (!condVal)
        return nullptr;

    // Normalize condition to boolean (for integer, floating point, or pointer
    // types)
    if (Type *condType = condVal->getType(); condType->isIntegerTy()) {
        condVal = BUILDER.CreateICmpNE(condVal, ConstantInt::get(condType, 0), "ifcond");
    } else if (condType->isFloatingPointTy()) {
        condVal = BUILDER.CreateFCmpONE(condVal, ConstantFP::get(condType, 0.0), "ifcond");
    } else if (condType->isPointerTy() || condType->isArrayTy()) {
        condVal = BUILDER.CreateICmpNE(condVal, ConstantPointerNull::get(cast<PointerType>(condType)), "ifcond");
    } else {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnsupported type for conditional Expression",
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Create the blocks for then, else, and merge
    BasicBlock *thenBB = BasicBlock::Create(LLVMCTX, "then", ctx->getCurrFun());
    BasicBlock *elseBB = BasicBlock::Create(LLVMCTX, "else");
    BasicBlock *mergeBB = BasicBlock::Create(LLVMCTX, "merge");

    // Create conditional branch based on the condition value
    BUILDER.CreateCondBr(condVal, thenBB, elseBB);

    // Then block: Execute the body of the if statement
    BUILDER.SetInsertPoint(thenBB);
    ctx->pushBlock(thenBB);

    // the top level ifstmt
    if (elseIf && !ctx->mergeBBInNestIf) {
        ctx->mergeBBInNestIf = mergeBB;
    }

    Value *thenBody = body->codeGen(ctx);
    auto thenBBEndIter = thenBB->end();
    if ((--thenBBEndIter)->getOpcode() != Instruction::Br && thenBBEndIter->getOpcode() != Instruction::Ret) {
        BUILDER.CreateBr(mergeBB); // Unconditionally branch to merge
    }
    ctx->popBlock();

    if (elseIf) {
        // merge else If and the then val
        ctx->getCurrFun()->insert(ctx->getCurrFun()->end(), elseBB);
        BUILDER.SetInsertPoint(elseBB);
        ctx->pushBlock(elseBB);
        Value *elifVal = elseIf->codeGen(ctx);

        ctx->popBlock(); // pop else block

        if (elifVal) {

            // Merge block: Combine the results of the then and else branches
            ctx->getCurrFun()->insert(ctx->getCurrFun()->end(), mergeBB);
            BUILDER.SetInsertPoint(mergeBB);
            ctx->pushBlock(mergeBB);

            Value *phi = mergeBlock(thenBody, thenBB, thenBBEndIter, ctx->mergeBBInNestIfSrcVal,
                                    ctx->mergeBBInNestIfSource, ctx->mergeBBInNestIfSource->end(), ctx);
            ctx->mergeBBInNestIfSource = nullptr;

            ctx->popBlock(); // pop merge block

            return phi;
        }
    }

    if (elseBB) {
        // Else block: Execute the body of the else statement (if present)
        ctx->getCurrFun()->insert(ctx->getCurrFun()->end(), elseBB);
        BUILDER.SetInsertPoint(elseBB);
        ctx->pushBlock(elseBB);
        Value *elseBody = else_body ? else_body->codeGen(ctx) : nullptr;
        auto elseBBEndIter = elseBB->end();
        if ((--elseBBEndIter)->getOpcode() != Instruction::Br && elseBBEndIter->getOpcode() != Instruction::Ret) {
            BUILDER.CreateBr(mergeBB); // Unconditionally branch to merge
        }
        ctx->popBlock(); // pop else block

        // Merge block: Combine the results of the then and else branches
        ctx->getCurrFun()->insert(ctx->getCurrFun()->end(), mergeBB);
        BUILDER.SetInsertPoint(mergeBB);
        ctx->pushBlock(mergeBB);

        Value *phi = mergeBlock(thenBody, thenBB, thenBBEndIter, elseBody, elseBB, elseBBEndIter, ctx);

        if (auto mergeBBEndIter = mergeBB->end(); (--mergeBBEndIter)->getOpcode() != Instruction::Br &&
                                                  mergeBBEndIter->getOpcode() != Instruction::Ret // with no jump stmt
                                                  &&
                                                  ctx->mergeBBInNestIf) { // and it is a nested ifStatement's merge stmt
            // then jump to the top ifStmt merge Block
            BUILDER.CreateBr(ctx->mergeBBInNestIf); // Unconditionally branch to merge
            ctx->mergeBBInNestIfSource = mergeBB;
            ctx->mergeBBInNestIfSrcVal = phi;
            ctx->mergeBBInNestIf = nullptr;
        }
        ctx->popBlock(); // pop merge block

        return phi; // Return the result of the condition
    }
    return thenBody;
}

// ElifStmt: Currently not implemented, but potentially used for "elif" (else
// if) statements
Value *ElifStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    return nullptr;
}

// ForStmt: Generates code for a for loop
Value *ForStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Generate code for initialization Expression
    Value *initGen = init->codeGen(ctx);

    // Generate code for loop condition
    Value *condVal = cond->codeGen(ctx);
    Value *brCond;

    // Handle different types for loop condition: integer, floating point, or
    // pointer
    switch (condVal->getType()->getTypeID()) {
    case Type::IntegerTyID:
        brCond = BUILDER.CreateICmp(CmpInst::ICMP_NE, condVal, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        break;
    case Type::DoubleTyID:
    case Type::FloatTyID:
        brCond = BUILDER.CreateFCmp(CmpInst::FCMP_ONE, condVal, ConstantFP::get(LLVMCTX, APFloat(0.0)));
        break;
    case Type::PointerTyID:
        brCond = BUILDER.CreateICmp(CmpInst::ICMP_NE, condVal, ConstantPointerNull::get(PointerType::get(LLVMCTX, 0)));
        break;
    default:
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nUnknown type for conditional Expression",
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Create the loop and exit basic blocks
    Function *fun = ctx->getCurrFun();
    BasicBlock *loopBB = BasicBlock::Create(LLVMCTX, "loop", fun);
    BasicBlock *exitBB = BasicBlock::Create(LLVMCTX, "exit");
    ctx->topBlock()->loopExitBlocks.push(exitBB);
    BUILDER.CreateCondBr(brCond, loopBB, exitBB);

    // Insert the loop body and conditional branch back to loop or exit
    BUILDER.SetInsertPoint(loopBB);
    if (body->codeGen(ctx)) {
        BUILDER.CreateStore(step->codeGen(ctx),
                            initGen); // Update the loop step variable
        brCond = cond->codeGen(ctx);  // Re-check the loop condition
        BUILDER.CreateCondBr(brCond, loopBB, exitBB);
    }

    // Insert the exit block after the loop ends
    fun->insert(fun->end(), exitBB);
    BUILDER.SetInsertPoint(exitBB);

    ctx->topBlock()->loopExitBlocks.pop();

    return nullptr;
}

// VarDecl: Generates code for a variable declaration
Value *VarDecl::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;

    ctx->setDefiningVariable(true);
    // If no block exists, it's a global variable
    if (!ctx->hasBlock() && !ctx->isDefStruct()) {

        // TODO support more types of global variable
        assert(init && "No init in Variable Declaration!");
        auto *constant = dyn_cast<Constant>(init->codeGen(ctx));

        // Handle global variables, assuming non-pointer types
        if (util::typeOf(*type, ctx, size) != Type::getInt8Ty(LLVMCTX)) {
            ctx->setDefiningVariable(false);
            const string name_ = name->getName();
            const char *c_str = name_.c_str();
            return new GlobalVariable(*MODULE, util::typeOf(*type, ctx, size), false, GlobalValue::InternalLinkage,
                                      constant, c_str);
        }
    }

    // Declare a local variable with the specified type
    Type *valType = util::typeOf(*type, ctx, size);
    if (llvm::isa<PointerType>(valType)) {
        auto baseTypeName = util::getSubVector(*type->name_parts, 0, type->name_parts->size() - 1);
        Type *baseType = util::typeOf(QualifiedName(&baseTypeName), ctx);

        AllocaInst *allocaInst = BUILDER.CreateAlloca(baseType, nullptr, name->getName());

        Value *gep = BUILDER.CreateGEP(baseType, dyn_cast<Value>(allocaInst), ConstantInt::get(LLVMCTX, APInt(32, 0)));
        ctx->locals()[name->getName()] = {
            gep, new inter_gen::VariableMetaData(name->getName(), gep->getType(), is_mutable, is_nullable)};
        ctx->addPtrValBaseTypeMapping(allocaInst, baseType);
        gepMapping->insert(std::make_pair(gep, allocaInst));

        // If there's an initializer Expression, evaluate it
        if (init != nullptr) {
            AssignExpr assign(name, init);
            assign.codeGen(ctx);
        }

        ctx->setDefiningVariable(false);
        return gep;
    }

    // For other variable types, just allocate memory
    AllocaInst *alloc = BUILDER.CreateAlloca(valType, nullptr, name->getName());
    ctx->locals()[name->getName()] = {
        alloc, new inter_gen::VariableMetaData(name->getName(), alloc->getAllocatedType(), is_mutable, is_nullable)};

    // If there's an initializer Expression, evaluate it
    if (init != nullptr) {
        AssignExpr assign(name, init);
        assign.codeGen(ctx);
    }
    ctx->setDefiningVariable(false);

    return alloc; // Return the allocated variable
}

// ReturnStmt: Generates code for a return statement
Value *ReturnStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    if (expr == nullptr) {
        BUILDER.CreateRetVoid();
        ctx->setCurrRetVal(nullptr);
        return nullptr;
    }
    // Generate code for the return expression
    Value *retVal = expr->codeGen(ctx);

    const bool isNullable = inter_gen::isNullable(expr, ctx);
    ctx->getCurrFunMetaData()->setReturnMetaData(
        retVal, new inter_gen::VariableMetaData("", retVal->getType(), true, isNullable));

    BUILDER.CreateRet(retVal);
    ctx->setCurrRetVal(retVal);
    blockMappingRet_d->insert({ctx->currBlock(), retVal});
    return retVal;
}

// ExprStmt: Generates code for an Expression statement
Value *ExprStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Simply evaluate the Expression
    return expr->codeGen(ctx);
}

Value *IncludeStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    const std::string target = util::getStrFromVec(*path->name_parts, ".");
    if (!moduleMetadataMap_d->contains(target)) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nInclude statement failed: " + target,
                     __FILE__, __LINE__);
        return nullptr;
    }

    for (const auto moduleMetaData = moduleMetadataMap_d->at(target); const auto fun : moduleMetaData->getFunctions()) {
        if (!ctx->metaData->getFunction(fun->getName())) {
            Function::Create(fun->getType(), Function::ExternalLinkage, fun->getName(), MODULE);
            ctx->metaData->addFunction(fun);
        }
    }
    return nullptr;
}

Value *PackageStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    if (!ctx->package.empty()) {
        return nullptr;
    }
    const std::string pkg = util::getStrFromVec(*name->name_parts, ".");
    util::create_package_dir(pkg);

    ctx->module =
        new Module(pkg + "." + ctx->fileName.substr(0, ctx->fileName.find_last_of('.')), *inter_gen::llvmContext);
    ctx->metaData = new inter_gen::ModuleMetaData(ctx->module);
    moduleMetadataMap_d->insert({pkg + "." + ctx->fileName.substr(0, ctx->fileName.find_last_of('.')), ctx->metaData});

    ctx->package = pkg;

    return nullptr;
}

// BlockStmt: Generates code for a block of statements
Value *BlockStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    Value *last = nullptr;
    for (const auto &s : stmts) {
        last = s->codeGen(ctx); // Generate code for each statement in the block
    }
    return last; // Return the result of the last statement
}

Value *BreakStmt::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    BUILDER.CreateBr(ctx->topBlock()->loopExitBlocks.top());
    if (expr) {
        Value *value = expr->codeGen(ctx);

        return value;
    }
    return nullptr;
}

Value *handleStructAssign(const QualifiedName *var, Expr *val, inter_gen::InterGenContext *ctx);

// AssignExpr: Generates code for an assignment statement
Value *AssignExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;

    if (lhs->name_parts->size() > 1) {
        return handleStructAssign(lhs, rhs, ctx);
    }

    // check whether the value can be assigned or a value can be assigned to null
    auto [val, valMetaData] = ctx->getValWithMetadata(lhs->getName());

    if (!val) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \ncan not find value: " + lhs->getName(),
                     __FILE__, __LINE__);
        return nullptr;
    }
    if (!valMetaData->isMutable() && !ctx->isDefiningVariable()) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \ncan not assign to a immutable value: " + lhs->getName(),
                     __FILE__, __LINE__);
        return nullptr;
    }

    if (!valMetaData->isNullable() && isNullable(rhs, ctx)) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \ncan not assign a nullable value to a non-nullable value: " + lhs->getName(),
                     __FILE__, __LINE__);
        return nullptr;
    }

    // Store the result of the right-hand side Expression in the left-hand side
    // variable
    Value *lhsVal = ctx->getVal(lhs->getName());
    if (dyn_cast<AllocaInst>(lhsVal)) {
        return BUILDER.CreateStore(rhs->codeGen(ctx), ctx->getVal(lhs->getName()), false);
    }
    if (lhsVal->getType()->isPointerTy()) {
        BUILDER.CreateLoad(ctx->getPtrValBaseTy(gepMapping->at(lhsVal)), lhsVal, "lhs");
        return BUILDER.CreateStore(rhs->codeGen(ctx), ctx->getVal(lhs->getName()), false);
    }
    return BUILDER.CreateStore(rhs->codeGen(ctx), ctx->getVal(lhs->getName()), false);
}

Value *ArrayAssignExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    Value *base = lhs->codeGen(ctx);
    if (!base) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nVariable not found in local context",
                     __FILE__, __LINE__);
        return nullptr;
    }

    Value *idxVal = idx->codeGen(ctx);
    if (!idxVal) {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nIndex value not found in local context",
                     __FILE__, __LINE__);
        return nullptr;
    }
    if (llvm::isa<PointerType>(base->getType())) {
        Value *ptrAdd = BUILDER.CreatePtrAdd(base, idxVal, "ptrAccess_");
        return BUILDER.CreateStore(rhs->codeGen(ctx), ptrAdd);
    }
    if (llvm::isa<ArrayType>(base->getType())) {
        const std::vector<Value *> idxList = {ConstantInt::get(LLVMCTX, APInt(32, 0)), idxVal};
        Value *ptrAdd = BUILDER.CreateGEP(base->getType(), base, idxList, "ptrAccess_");
        return BUILDER.CreateStore(rhs->codeGen(ctx), ptrAdd);
    }
    return nullptr;
}

Value *handleStructAssign(const QualifiedName *var, Expr *val, inter_gen::InterGenContext *ctx)
{
    Value *currentPtr = nullptr;
    // Get the pointer to the struct
    if (Value *local = ctx->getVal(var->getFirstName())) {
        // if it is a pointer, then load it
        if (llvm::isa<StructType>(local->getType())) {
            currentPtr = local;
        } else if (llvm::isa<PointerType>(local->getType()) && gepMapping->contains(local)) {
            currentPtr = gepMapping->at(local);
        } else {
            // not a pointer, just get the val
            currentPtr = ctx->getVal(var->getFirstName());
        }
    } else {
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nVariable not found in local context",
                     __FILE__, __LINE__);
        return nullptr;
    }

    assert(currentPtr && "currentPtr is null");
    StringRef structName;
    if (const AllocaInst *allocaInst = dyn_cast<AllocaInst>(currentPtr)) {
        structName = dyn_cast<StructType>(allocaInst->getAllocatedType())->getStructName();
    } else {
        structName = dyn_cast<StructType>(currentPtr->getType())->getStructName();
    }

    string str = structName.str();
    const inter_gen::StructMetaData *metaData = ctx->structs[structName.str()];

    // Traverse through the struct fields
    for (int i = 1; i < var->name_parts->size(); ++i) {
        // Get the field index based on the current struct's metadata
        const unsigned int fieldIndex = metaData->getFieldIndex(var->getName(i));
        Type *fieldType = metaData->getFieldType(var->getName(i));
        // Generate the load to get the field pointer
        currentPtr = BUILDER.CreateStructGEP(metaData->getStructType(), currentPtr, fieldIndex);

        // this is the last field, so store the value
        if (i == var->name_parts->size() - 1) {
            return BUILDER.CreateStore(val->codeGen(ctx), currentPtr, false);
        }

        // If this field is a nested struct, update the struct type and metadata
        if (i < var->name_parts->size() - 1) {
            const auto *nestedStructType = dyn_cast<StructType>(fieldType);
            if (!nestedStructType) {
                return nullptr; // Error: not a valid nested struct
            }
            // Update metadata for the nested struct
            metaData = ctx->structs[nestedStructType->getStructName().str()];
            if (!metaData) {
                return nullptr; // Error: metadata for nested struct not
                // found
            }
        }
    }

    return BUILDER.CreateStore(val->codeGen(ctx), currentPtr, false);
}

// UnaryExpr: Generates code for a unary Expression (increment or decrement)
Value *UnaryExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Generate code for the operand of the unary operation
    Value *operVal = operand->codeGen(ctx);

    Value *res;
    Value *var;
    Value *varPtr;
    // Handle increment or decrement
    switch (op) {
    case DEC:
        operVal = BUILDER.CreateSub(operVal, ConstantInt::get(LLVMCTX, APInt(1, 1)), "decrease"); // Decrement
        return operVal;
    case INC:
        operVal = BUILDER.CreateAdd(operVal, ConstantInt::get(operVal->getType(), 1), "increase"); // Increment
        return operVal;
    case TIMES:
        if (llvm::isa<PointerType>(operVal->getType())) {
            operVal = BUILDER.CreateLoad(expectDerefType_d->top(), operVal, "dereference");
            return operVal;
        }
        REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
                         " \nInvalid pointer dereference",
                     __FILE__, __LINE__);
    case MINUS:
        return BUILDER.CreateNeg(operVal, "negate");
    case BIT_AND:
        if (operVal->getType()->isArrayTy()) {
            if (llvm::isa<LoadInst>(operVal)) {
                auto *castReturn = dyn_cast<LoadInst>(operVal);
                return castReturn->getPointerOperand();
            }
            Value *value = BUILDER.CreateGEP(
                PointerType::get(operVal->getType()->getArrayElementType(), 0), operVal,
                {ConstantInt::get(LLVMCTX, APInt(32, 0)), ConstantInt::get(LLVMCTX, APInt(32, 0))}, "arrAddress");
            return value;
        }
        return BUILDER.CreateGEP(operVal->getType(), operVal, ConstantInt::get(LLVMCTX, APInt(1, 0)), "address");
    case DIVIDE_ASSIGN:
        res = BUILDER.CreateSDiv(operand->codeGen(ctx), operVal);
        var = operand->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);
    case PLUS_ASSIGN:
        res = BUILDER.CreateAdd(operand->codeGen(ctx), operVal);
        var = operand->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case MINUS_ASSIGN:
        res = BUILDER.CreateSub(operand->codeGen(ctx), operVal);
        var = operand->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case TIMES_ASSIGN:
        res = BUILDER.CreateMul(operand->codeGen(ctx), operVal);
        var = operand->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case MOD_ASSIGN:
        res = BUILDER.CreateSRem(operand->codeGen(ctx), operVal);
        var = operand->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));

        return BUILDER.CreateStore(res, varPtr);
    case NOT:
        return BUILDER.CreateNot(operVal, "not");
    default:
        return nullptr;
    }
}

// VarExpr: Generates code for a variable Expression
Value *VarExpr::codeGen(inter_gen::InterGenContext *ctx)
{
    // Simply look up the value of the variable from the context
    ctx->currLine = this->line;
    return name->codeGen(ctx);
}

Value *StructDecl::codeGen(inter_gen::InterGenContext *ctx)
{
    ctx->currLine = this->line;
    // Create a struct type with the specified fields
    ctx->setDefStruct(true);
    auto *smd = new inter_gen::StructMetaData(ctx, name->getName());
    ctx->structs[name->getName()] = smd;

    std::vector<Type *> fieldTypes;
    fieldTypes.reserve(fields.size());
    // Generate the types of the fields and the metadata
    for (const auto &field : fields) {
        fieldTypes.push_back(util::typeOf(*field->getType(), ctx));
        smd->addField(field->getName(), new inter_gen::VariableMetaData(field->getName(), fieldTypes.back(),
                                                                        field->is_mutable, field->is_nullable));
    }

    StructType *dStruct = StructType::create(LLVMCTX, fieldTypes, name->getName());

    ctx->setDefStruct(false);
    // Create a global variable for the struct
    auto *globalStruct = new GlobalVariable(*MODULE, // Module in which to insert the global variable
                                            dStruct, // Type of the global variable (struct type)
                                            false,   // Whether it's constant
                                            GlobalValue::ExternalLinkage,    // Linkage type
                                            Constant::getNullValue(dStruct), // Initializer (null-initialized)
                                            name->getName()                  // Name of the global variable
    );

    smd->setStructType(dStruct);

    return globalStruct; // Return the global variable as Value*
}
} // namespace parser

namespace inter_gen
{
FunctionMetaData *InterGenContext::getFunMetaData(const std::string &name, const InterGenContext *ctx) const
{
    for (const auto &fun : metaData->getFunctions()) {
        if (fun->getName() == name) {
            return fun;
        }
    }
    REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) + " \nFunction " + name +
                     " not found",
                 __FILE__, __LINE__);
    return nullptr;
}

std::pair<Value *, VariableMetaData *> InterGenContext::getValWithMetadata(const parser::QualifiedName *name)
{
    int idx = 0;
    std::pair<Value *, VariableMetaData *> val_with_metadata = this->getValWithMetadata(name->getName(idx));
    while (val_with_metadata.first && val_with_metadata.second) {
        if (name->name_parts->size() == idx + 1) {
            return val_with_metadata;
        }
        idx++;
    }
    {
        REPORT_ERROR(errMsg("Value not found" + name->getName()), __FILE__, __LINE__);
    }
    return {nullptr, nullptr};
}

void InterGenContext::genIR(parser::Program *program)
{
    program->codeGen(this);

    if (!mainFunction && (sourcePath.ends_with("/main.dap") || sourcePath == "main.dap")) {
        constexpr std::vector<Type *> argTypes;
        FunctionType *ftype = FunctionType::get(Type::getInt32Ty(module->getContext()), ArrayRef(argTypes), false);
        mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);
        BasicBlock *bblock = BasicBlock::Create(module->getContext(), "entry", mainFunction, nullptr);

        builder.SetInsertPoint(bblock);
        pushBlock(bblock);

        builder.CreateRet(ConstantInt::get(module->getContext(), APInt(32, 0)));

        popBlock();
    }

    std::error_code EC;
    util::replaceAll(package, ".", "/");
    std::string outputPath = buildDir + package + "/" + fileName + ".ll";
    std::fstream outputFile(outputPath, std::ios::out);
    outputFile.close();
    raw_fd_ostream outfile(outputPath, EC, sys::fs::OF_Text);

    if (EC) {
        errs() << "Error opening output file: " << EC.message() << "\n";
        return;
    }
    legacy::PassManager pm;
    pm.add(createPrintModulePass(outfile));
    pm.run(*module);

    outfile.flush();
    outfile.close();
}

void InterGenContext::genExec(parser::Program *program)
{
    // Initialize LLVM targets
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    program->codeGen(this);

    if (!mainFunction && (sourcePath.ends_with("/main.dap") || sourcePath == "main.dap")) {
        // Define the main function (i32 @main())
        FunctionType *ftype = FunctionType::get(Type::getInt32Ty(module->getContext()), false);
        mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);

        // Create the entry block and set the insertion point
        BasicBlock *bblock = BasicBlock::Create(module->getContext(), "entry", mainFunction);
        builder.SetInsertPoint(bblock);
        pushBlock(bblock);

        // Return 0 from the main function
        builder.CreateRet(ConstantInt::get(Type::getInt32Ty(module->getContext()), 0));

        // Verify the function
        verifyFunction(*mainFunction);
        popBlock();
    }

    // Target machine setup
    const std::string targetTriple = sys::getDefaultTargetTriple();
    module->setTargetTriple(targetTriple);

    std::string error;
    const Target *target = TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        errs() << "Error: " << error;
        return;
    }

    // CPU and features
    const std::string cpu = "generic";
    const std::string features;

    const TargetOptions opt;
    std::optional<Reloc::Model>();
    TargetMachine *targetMachine = target->createTargetMachine(targetTriple, cpu, features, opt, Reloc::PIC_);

    module->setDataLayout(targetMachine->createDataLayout());

    // Create the MCJIT execution engine
    std::unique_ptr<Module> modulePtr(module);
    auto mem_mgr = std::make_unique<SectionMemoryManager>();

    // Save the generated code to a file
    std::error_code EC;
    util::replaceAll(package, ".", "/");
    std::string outputPath = buildDir + package + "/" + fileName + ".o";
    std::fstream outputFile(outputPath, std::ios::out);
    outputFile.close();
    filesToCompile->push_back(outputPath);
    raw_fd_ostream dest(outputPath, EC, sys::fs::OF_None);

    if (EC) {
        errs() << "Could not open file for writing: " << EC.message() << "\n";
        return;
    }

    legacy::PassManager pass;
    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, CodeGenFileType::ObjectFile)) {
        errs() << "TargetMachine can't emit a file of this type\n";
        return;
    }

    pass.run(*module);
    dest.flush();

    outs() << "Object file emitted to " << outputPath << "\n";
}

std::unordered_map<IncludeGraphNode *, bool> visited{};

void interGen_oneFile(IncludeGraphNode *node)
{
    if (visited.contains(node)) {
        return;
    }
    visited.insert({node, false});
    if (!node->getIncludes().empty()) {
        for (const auto oneNode : node->getIncludes()) {
            interGen_oneFile(oneNode);
        }
    }
    programMap_d->at(node->getProgram())->genIR(node->getProgram());
    visited.insert({node, true});
}

void interGen(const std::set<IncludeGraphNode *> &map)
{
    for (const auto node : map) {
        interGen_oneFile(node);
    }
}

Value *InterGenContext::getVal(const std::string &name)
{
    std::stack<InterGenBlock *> tmp;
    while (!blocks.empty()) {
        if (blocks.top()->locals.contains(name)) {
            Value *res = blocks.top()->locals[name].first;

            while (!tmp.empty()) {
                blocks.push(tmp.top());
                tmp.pop();
            }
            return res;
        }
        if (Function *fun = blocks.top()->block->getParent()) {
            for (auto &arg : fun->args()) {
                if (arg.getName() == name) {
                    return &arg;
                }
            }
        }
        tmp.push(blocks.top());
        blocks.pop();
    }

    while (!tmp.empty()) {
        blocks.push(tmp.top());
        tmp.pop();
    }

    if (this->module->getGlobalVariable(name, true)) {
        return this->module->getGlobalVariable(name, true);
    }

    return nullptr;
}

std::pair<Value *, VariableMetaData *> InterGenContext::getValWithMetadata(const std::string &name)
{
    std::stack<InterGenBlock *> tmp;
    while (!blocks.empty()) {
        if (blocks.top()->locals.contains(name)) {
            std::map<std::string, std::pair<Value *, VariableMetaData *>>::mapped_type res = blocks.top()->locals[name];
            while (!tmp.empty()) {
                blocks.push(tmp.top());
                tmp.pop();
            }
            return res;
        }
        if (Function *fun = blocks.top()->block->getParent()) {
            const auto &funMetadata = functions[fun->getName().str()];
            for (auto &arg : fun->args()) {
                if (arg.getName() == name) {
                    return {&arg, funMetadata->getArgMetaData(arg.getName().str())};
                }
            }
        }
        tmp.push(blocks.top());
        blocks.pop();
    }

    if (module->getGlobalVariable(name)) {
        return {module->getGlobalVariable(name), getModuleMetaData(name)->getGlobalValMetaData(name)};
    }

    return {nullptr, nullptr};
}

FunctionMetaData *InterGenContext::getCurrFunMetaData() const
{
    return currentFunMetaData;
}

void InterGenContext::setCurrFunMetaData(FunctionMetaData *funMetaData)
{
    currentFunMetaData = funMetaData;
}

} // namespace inter_gen
} // namespace dap