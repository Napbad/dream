//
// Created by napbad on 11/16/24.
//

#include "basicElementGen_d.h"

#include "../common/define_d.h"
#include "../utilities/file_util.h"
#include "../utilities/obj_util.h"

#include <iostream>
#include <llvm/IR/Verifier.h>
#include <sstream>

namespace dap::inter_gen
{
Function *genIntToChar(InterGenContext *ctx)
{
    // Define the function type for the `intToChar` conversion
    FunctionType *intToCharType = FunctionType::get(Type::getInt8Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `int_to_char` function with internal linkage
    Function *intToChar = Function::Create(intToCharType, Function::ExternalLinkage, "intToChar", ctx->module);

    const auto funMetadata = new FunctionMetaData("intToChar", intToCharType);
    ctx->metaData->addFunction(funMetadata);
    // Create the entry block
    BasicBlock *entry = BasicBlock::Create(LLVMCTX, "entry", intToChar, nullptr);
    BUILDER.SetInsertPoint(entry);
    ctx->pushBlock(entry);
    ctx->setCurrFun(intToChar);
    // Get the function argument

    // Check the argument type
    if (Argument *arg = intToChar->getArg(0); arg->getType()->getTypeID() == Type::IntegerTyID)
    {
        arg->setName("i");
        funMetadata->addArg("i", arg, Type::getInt32Ty(LLVMCTX));
        // Truncate the integer to a character
        Value *charCast = BUILDER.CreateTrunc(arg, Type::getInt8Ty(LLVMCTX), "int_cast");

        BUILDER.CreateRet(
            BUILDER.CreateAdd(charCast, ConstantInt::get(Type::getInt8Ty(LLVMCTX), APInt(8, 48, true)), "int_add"));
    }
    else
    {
        // Print an error message if the argument type is invalid
        REPORT_ERROR("invalid arg type", __FILE__, __LINE__);
        return nullptr;
    }

    // Verify the function
    verifyFunction(*intToChar);

    // Pop the current block and set the current function to null
    ctx->popBlock();
    ctx->setCurrFun(nullptr);

    return intToChar;
}

Function *genCharToInt(InterGenContext *ctx)
{
    // Define the function type for the `char_to_int` conversion
    FunctionType *charToIntType = FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt8Ty(LLVMCTX)}, false);

    // Create the `char_to_int` function with internal linkage
    Function *charToInt = Function::Create(charToIntType, Function::ExternalLinkage, "charToInt", ctx->module);
    const auto funMetadata = new FunctionMetaData("charToInt", charToIntType);
    ctx->metaData->addFunction(funMetadata);
    // Create the entry block
    BasicBlock *entry = BasicBlock::Create(LLVMCTX, "entry", charToInt, nullptr);
    BUILDER.SetInsertPoint(entry);
    ctx->pushBlock(entry);
    ctx->setCurrFun(charToInt);

    // Check the argument type
    if (Argument *arg = charToInt->getArg(0); arg->getType()->getTypeID() == Type::IntegerTyID)
    {
        // Cast the character to an integer
        arg->setName("ch");
        funMetadata->addArg("ch", arg, Type::getInt8Ty(LLVMCTX));
        Value *intCast_ret = BUILDER.CreateIntCast(arg, Type::getInt32Ty(LLVMCTX), false, "char_cast");
        BUILDER.CreateRet(intCast_ret);
    }
    else
    {
        // Print an error message if the argument type is invalid
        std::stringstream ss;
        ss << "invalid arg type: expect Integer8, but get: " << arg->getType()->getTypeID();
        REPORT_ERROR("invalid arg type" + ss.str(), __FILE__, __LINE__);
        return nullptr;
    }

    // Verify the function
    verifyFunction(*charToInt);

    // Pop the current block and set the current function to null
    ctx->popBlock();
    ctx->setCurrFun(nullptr);

    return charToInt;
}

Function *genInt32To8(InterGenContext *ctx)
{
    // Define the function type for the `int32To8` conversion
    FunctionType *int32To8Type = FunctionType::get(Type::getInt8Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `int32To8` function with internal linkage
    Function *int32To8 = Function::Create(int32To8Type, Function::ExternalLinkage, "int32To8", ctx->module);
    const auto funMetadata = new FunctionMetaData("int32To8", int32To8Type);
    ctx->metaData->addFunction(funMetadata);
    // Create the entry block
    BasicBlock *entry = BasicBlock::Create(LLVMCTX, "entry", int32To8, nullptr);
    BUILDER.SetInsertPoint(entry);
    ctx->pushBlock(entry);
    ctx->setCurrFun(int32To8);


    // Check the argument type
    if (Argument *arg = int32To8->getArg(0); arg->getType()->getTypeID() == Type::IntegerTyID)
    {
        // Set argument name
        arg->setName("input");
        funMetadata->addArg("input", arg, Type::getInt32Ty(LLVMCTX));

        // Perform the truncation operation
        Value *truncatedValue = ctx->builder.CreateTrunc(arg, Type::getInt8Ty(LLVMCTX), "truncated_value");

        // Return the result
        BUILDER.CreateRet(truncatedValue);
    }
    else
    {
        // Print an error message if the argument type is invalid
        std::stringstream ss;
        ss << "invalid arg type: expect Integer32, but get: " << arg->getType()->getTypeID();
        REPORT_ERROR("invalid arg type" + ss.str(), __FILE__, __LINE__);
        return nullptr;
    }

    // Verify the function
    verifyFunction(*int32To8);

    // Pop the current block and set the current function to null
    ctx->popBlock();
    ctx->setCurrFun(nullptr);

    return int32To8;
}

Function *genCharToStr(InterGenContext *ctx)
{
    // Create the function type: char* intToStr(int)
    FunctionType *charToStrType =
        FunctionType::get(PointerType::get(Type::getInt8Ty(LLVMCTX), 0), {Type::getInt8Ty(LLVMCTX)}, false);
    // Create the function and add it to the module
    Function *charToStr = Function::Create(charToStrType, Function::ExternalLinkage, "charToStr", MODULE);
    ctx->setCurrFun(charToStr);
    const auto funMetadata = new FunctionMetaData("charToStr", charToStrType);
    ctx->metaData->addFunction(funMetadata);
    // Create a basic block and attach it to the function
    BasicBlock *entryBlock = BasicBlock::Create(LLVMCTX, "entry", charToStr);
    BUILDER.SetInsertPoint(entryBlock);
    ctx->pushBlock(entryBlock);

    // Allocate memory for the string buffer
    Value *strBuffer =
        new GlobalVariable(*MODULE, ArrayType::get(Type::getInt8Ty(LLVMCTX), 2), false, GlobalValue::ExternalLinkage,
                           ConstantDataArray::getString(LLVMCTX, " ", true), "str");

    // Get the function's argument (the integer to be converted)
    const auto args = charToStr->arg_begin();
    Value *inputInt = &*args;
    inputInt->setName("inputInt");
    funMetadata->addArg("inputInt", inputInt, Type::getInt8Ty(LLVMCTX));

    // Return the pointer to the buffer (for now, we just return the buffer's address)
    Value *gep = BUILDER.CreateGEP(Type::getInt8Ty(LLVMCTX), strBuffer, ConstantInt::get(Type::getInt32Ty(LLVMCTX), 0),
                                   "charToStr", false);
    BUILDER.CreateStore(inputInt, gep);
    Value *gep2 = BUILDER.CreateGEP(Type::getInt8Ty(LLVMCTX), strBuffer, ConstantInt::get(Type::getInt32Ty(LLVMCTX), 1),
                                    "charToStr", false);
    BUILDER.CreateStore(ConstantInt::get(Type::getInt8Ty(LLVMCTX), 0), gep2);
    BUILDER.CreateRet(gep);

    // Verify the function
    verifyFunction(*charToStr);

    // Pop the current block and set the current function to null
    ctx->popBlock();
    ctx->setCurrFun(nullptr);

    return charToStr;
}

Function *genMalloc(InterGenContext *ctx)
{

    return nullptr;
}

Function *genFree(InterGenContext *ctx)
{
    return nullptr;
}

void genHeap(const InterGenContext *ctx)
{
    const auto irHeap_d = new GlobalVariable(
        *MODULE, ArrayType::get(Type::getInt8Ty(LLVMCTX), DEFAULT_HEAP_SIZE), false, GlobalValue::ExternalLinkage,
        ConstantArray::get(ArrayType::get(Type::getInt8Ty(LLVMCTX), DEFAULT_HEAP_SIZE), ArrayRef<Constant *>()),
        "heap");

    obj_util::delayedDeleteObjVector.push_back(new obj_util::DelayDeleteObj(irHeap_d));

    auto *heap = new heap_d{new GlobalVariable(*MODULE, Type::getInt8Ty(LLVMCTX), false, GlobalValue::ExternalLinkage,
                                               dyn_cast<Constant>(irHeap_d), "heapStart_d"),
                            new GlobalVariable(*MODULE, Type::getInt8Ty(LLVMCTX), false, GlobalValue::ExternalLinkage,
                                               ConstantInt::get(Type::getInt8Ty(LLVMCTX), 0), "heapEnd_d"),
                            irHeap_d, ConstantInt::get(Type::getInt8Ty(LLVMCTX), DEFAULT_HEAP_SIZE)};

    globalHeap = heap;
}
} // namespace dap::inter_gen