//
// Created by napbad on 11/1/24.
//

#include "funGen_sys.h"

#include "../utilities/file_util.h"

#include <llvm/ADT/StringExtras.h>
#include <llvm/IR/Verifier.h>

namespace dream::inter_gen
{
void genSysFun(const InterGenContext *ctx)
{
    Function *writeFunc = genSysWrite(ctx);
    Function *fsyncFunc = genSysFSync(ctx);
    Function *readFunc = genSysRead(ctx);
    Function *openFunc = genSysOpen(ctx);
    Function *closeFunc = genSysClose(ctx);

    Function *forkFunc = genSysFork(ctx);
    Function *execveFunc = genSysExecve(ctx);
    Function *waitFunc = genSysWait(ctx);
    Function *listenFunc = genSysListen(ctx);
    Function *mmapFunc = genSysMmap(ctx);

    Function *munmapFunc = genSysMunmap(ctx);
    Function *sbrkFunc = genSysSbrk(ctx);
    Function *brkFunc = genSysBrk(ctx);
    Function *acceptFunc = genSysAccept(ctx);
    Function *bindFunc = genSysBind(ctx);

    Function *socketFunc = genSysSocket(ctx);
    Function *connectFunc = genSysConnect(ctx);

    Function * init = genInit(ctx);
    Function *exit = genExit(ctx);
    Function *f = genFini(ctx);
}

void registerSysFunctions(const InterGenContext *ctx)
{
    struct SysFunctionMetadata
    {
        std::string name;
        FunctionType *type;
    };

    std::vector<SysFunctionMetadata> sysFunctions = {
        {"write", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                    {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                     Type::getInt32Ty(LLVMCTX)},
                                    false)},
        {"fsync", FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false)},
        {"read", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                   {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                    Type::getInt32Ty(LLVMCTX)},
                                   false)},
        {"open", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                   {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt32Ty(LLVMCTX),
                                    Type::getInt32Ty(LLVMCTX)},
                                   false)},
        {"close", FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false)},
        {"fork", FunctionType::get(Type::getInt32Ty(LLVMCTX), {}, false)},
        {"execve", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                     {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                      PointerType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), 0),
                                      PointerType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), 0)},
                                     false)},
        {"wait", FunctionType::get(Type::getInt32Ty(LLVMCTX), {PointerType::get(Type::getInt32Ty(LLVMCTX), 0)}, false)},
        {"mmap", FunctionType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                   {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt64Ty(LLVMCTX),
                                    Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX),
                                    Type::getInt64Ty(LLVMCTX)},
                                   false)},
        {"munmap",
         FunctionType::get(Type::getInt32Ty(LLVMCTX),
                           {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt64Ty(LLVMCTX)}, false)},
        {"socket",
         FunctionType::get(Type::getInt32Ty(LLVMCTX),
                           {Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)}, false)},
        {"bind", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                   {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                    Type::getInt32Ty(LLVMCTX)},
                                   false)},
        {"listen",
         FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)}, false)},
        {"accept", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                     {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                      PointerType::get(Type::getInt32Ty(LLVMCTX), 0)},
                                     false)},
        {"connect", FunctionType::get(Type::getInt32Ty(LLVMCTX),
                                      {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                                       Type::getInt32Ty(LLVMCTX)},
                                      false)},
        {"brk",
         FunctionType::get(Type::getInt32Ty(LLVMCTX), {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0)}, false)},
        {"sbrk",
         FunctionType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), {Type::getInt32Ty(LLVMCTX)}, false)}};

    for (const auto &[name, type] : sysFunctions)
    {
        Function *func = Function::Create(type, Function::ExternalLinkage, name, ctx->module);
    }
}

Function *genSysWrite(const InterGenContext *ctx)
{
    // Define the pointer type for the buffer argument
    PointerType *i8PtrType = PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0);

    // Define the function type for the `write` system call
    FunctionType *writeType = FunctionType::get(
        Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX), i8PtrType, Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `write` function with external linkage
    Function *writeFunc = Function::Create(writeType, Function::ExternalLinkage, "write", ctx->module);

    return writeFunc;
}

Function *genSysFSync(const InterGenContext *ctx)
{
    // Define the function type for the `fsync` system call
    FunctionType *fsyncType = FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `fsync` function with external linkage
    Function *fsyncFunc = Function::Create(fsyncType, Function::ExternalLinkage, "fsync", ctx->module);

    return fsyncFunc;
}

Function *genSysRead(const InterGenContext *ctx)
{
    // Define the function type for the `read` system call
    FunctionType *readType = FunctionType::get(
        Type::getInt32Ty(LLVMCTX),
        {Type::getInt32Ty(LLVMCTX), PointerType::getInt8Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `read` function with external linkage
    Function *readFunc = Function::Create(readType, Function::ExternalLinkage, "read", ctx->module);

    return readFunc;
}

Function *genSysOpen(const InterGenContext *ctx)
{
    // Define the function type for the `open` system call
    FunctionType *openType = FunctionType::get(
        Type::getInt32Ty(LLVMCTX),
        {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)},
        false);

    // Create the `open` function with external linkage
    Function *openFunc = Function::Create(openType, Function::ExternalLinkage, "open", ctx->module);

    return openFunc;
}

Function *genSysClose(const InterGenContext *ctx)
{
    // Define the function type for the `close` system call
    FunctionType *closeType = FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `close` function with external linkage
    Function *closeFunc = Function::Create(closeType, Function::ExternalLinkage, "close", ctx->module);

    return closeFunc;
}

Function *genSysFork(const InterGenContext *ctx)
{
    // Define the function type for the `fork` system call
    FunctionType *forkType = FunctionType::get(Type::getInt32Ty(LLVMCTX), {}, false);

    // Create the `fork` function with external linkage
    Function *forkFunc = Function::Create(forkType, Function::ExternalLinkage, "fork", ctx->module);

    return forkFunc;
}

Function *genSysExecve(const InterGenContext *ctx)
{
    // Define the function type for the `execve` system call
    FunctionType *execveType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX),
                          {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                           PointerType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), 0),
                           PointerType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), 0)},
                          false);

    // Create the `execve` function with external linkage
    Function *execveFunc = Function::Create(execveType, Function::ExternalLinkage, "execve", ctx->module);

    return execveFunc;
}

Function *genSysWait(const InterGenContext *ctx)
{
    // Define the function type for the `wait` system call
    FunctionType *waitType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX), {PointerType::get(Type::getInt32Ty(LLVMCTX), 0)}, false);

    // Create the `wait` function with external linkage
    Function *waitFunc = Function::Create(waitType, Function::ExternalLinkage, "wait", ctx->module);

    return waitFunc;
}

Function *genSysMmap(const InterGenContext *ctx)
{
    // Define the function type for the `mmap` system call
    FunctionType *mmapType = FunctionType::get(
        PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
        {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt64Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX),
         Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX), Type::getInt64Ty(LLVMCTX)},
        false);

    // Create the `mmap` function with external linkage
    Function *mmapFunc = Function::Create(mmapType, Function::ExternalLinkage, "mmap", ctx->module);

    return mmapFunc;
}

Function *genSysMunmap(const InterGenContext *ctx)
{
    // Define the function type for the `munmap` system call
    FunctionType *munmapType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX),
                          {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt64Ty(LLVMCTX)}, false);

    // Create the `munmap` function with external linkage
    Function *munmapFunc = Function::Create(munmapType, Function::ExternalLinkage, "munmap", ctx->module);

    return munmapFunc;
}

Function *genSysSocket(const InterGenContext *ctx)
{
    // Define the function type for the `socket` system call
    FunctionType *socketType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX),
                          {Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `socket` function with external linkage
    Function *socketFunc = Function::Create(socketType, Function::ExternalLinkage, "socket", ctx->module);

    return socketFunc;
}

Function *genSysBind(const InterGenContext *ctx)
{
    // Define the function type for the `bind` system call
    FunctionType *bindType = FunctionType::get(
        Type::getInt32Ty(LLVMCTX),
        {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt32Ty(LLVMCTX)},
        false);

    // Create the `bind` function with external linkage
    Function *bindFunc = Function::Create(bindType, Function::ExternalLinkage, "bind", ctx->module);

    return bindFunc;
}

Function *genSysListen(const InterGenContext *ctx)
{
    // Define the function type for the `listen` system call
    FunctionType *listenType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX), {Type::getInt32Ty(LLVMCTX), Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `listen` function with external linkage
    Function *listenFunc = Function::Create(listenType, Function::ExternalLinkage, "listen", ctx->module);

    return listenFunc;
}

Function *genSysAccept(const InterGenContext *ctx)
{
    // Define the function type for the `accept` system call
    FunctionType *acceptType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX),
                          {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0),
                           PointerType::get(Type::getInt32Ty(LLVMCTX), 0)},
                          false);

    // Create the `accept` function with external linkage
    Function *acceptFunc = Function::Create(acceptType, Function::ExternalLinkage, "accept", ctx->module);

    return acceptFunc;
}

Function *genSysConnect(const InterGenContext *ctx)
{
    // Define the function type for the `connect` system call
    FunctionType *connectType = FunctionType::get(
        Type::getInt32Ty(LLVMCTX),
        {Type::getInt32Ty(LLVMCTX), PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), Type::getInt32Ty(LLVMCTX)},
        false);

    // Create the `connect` function with external linkage
    Function *connectFunc = Function::Create(connectType, Function::ExternalLinkage, "connect", ctx->module);

    return connectFunc;
}

Function *genSysBrk(const InterGenContext *ctx)
{
    // Define the function type for the `brk` system call
    FunctionType *brkType =
        FunctionType::get(Type::getInt32Ty(LLVMCTX), {PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0)}, false);

    // Create the `brk` function with external linkage
    Function *brkFunc = Function::Create(brkType, Function::ExternalLinkage, "brk", ctx->module);

    return brkFunc;
}

Function *genSysSbrk(const InterGenContext *ctx)
{
    // Define the function type for the `sbrk` system call
    FunctionType *sbrkType =
        FunctionType::get(PointerType::get(IntegerType::getInt8Ty(LLVMCTX), 0), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `sbrk` function with external linkage
    Function *sbrkFunc = Function::Create(sbrkType, Function::ExternalLinkage, "sbrk", ctx->module);

    return sbrkFunc;
}

Function *genInit(const InterGenContext *ctx)
{
    // Define the function type for the `init` function
    FunctionType *initType = FunctionType::get(Type::getVoidTy(LLVMCTX), {}, false);

    // Create the `init` function with external linkage
    Function *initFunc = Function::Create(initType, Function::ExternalLinkage, "init", ctx->module);

    return initFunc;
}

Function *genFini(const InterGenContext *ctx)
{
    // Define the function type for the `fini` function
    FunctionType *finiType = FunctionType::get(Type::getVoidTy(LLVMCTX), {}, false);

    // Create the `fini` function with external linkage
    Function *finiFunc = Function::Create(finiType, Function::ExternalLinkage, "fini", ctx->module);
    return finiFunc;
}


Function *genExit(const InterGenContext *ctx)
{
    // Define the function type for the `exit` function
    FunctionType *exitType = FunctionType::get(Type::getVoidTy(LLVMCTX), {Type::getInt32Ty(LLVMCTX)}, false);

    // Create the `exit` function with external linkage
    Function *exitFunc = Function::Create(exitType, Function::ExternalLinkage, "exit", ctx->module);

    return exitFunc;
}


CallInst *handleSys(const parser::CallExpr *call, InterGenContext *ctx, Function *fun)
{
    if (fun->getName() == "write")
    {
        std::vector<Value *> writeArgs;

        // Handle the file descriptor argument
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            writeArgs.push_back(ConstantInt::get(Type::getInt32Ty(LLVMCTX), APInt(32, intExpr->value)));
        }
        else if (auto *varExpr = dynamic_cast<parser::VarExpr *>(call->args[0]))
        {
            if (Value *codeGen = varExpr->codeGen(ctx); isa<ConstantInt>(codeGen))
            {
                if (auto *constantInt = dyn_cast<ConstantInt>(codeGen); constantInt->getBitWidth() != 32)
                {
                    writeArgs.push_back(codeGen);
                }
                else
                {
                    writeArgs.push_back(
                        ConstantInt::get(Type::getInt32Ty(LLVMCTX), APInt(32, constantInt->getSExtValue())));
                }
            }
            else
            {
                std::stringstream ss;
                ss << "invalid arg type: expect Integer32, but get: " << codeGen->getType()->getTypeID();
                util::err_print(std::cerr, ss.str());
            }
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
        }

        // Handle the buffer argument
        if (auto *strExpr = dynamic_cast<parser::StringExpr *>(call->args[1]))
        {
            auto *strPtr = BUILDER.CreateGlobalStringPtr(strExpr->value);
            writeArgs.push_back(strPtr);
        }
        else if (auto *expr = dynamic_cast<parser::Expr *>(call->args[1]))
        {
            writeArgs.push_back(expr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect String, but get: unknown", __FILE__, __LINE__);
        }

        // Handle the count argument
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            writeArgs.push_back(ConstantInt::get(Type::getInt32Ty(LLVMCTX), APInt(32, intExpr->value)));
        }
        else if (auto *varExpr = dynamic_cast<parser::VarExpr *>(call->args[2]))
        {
            if (Value *codeGen = varExpr->codeGen(ctx); isa<ConstantInt>(codeGen))
            {
                if (auto *constantInt = dyn_cast<ConstantInt>(codeGen); constantInt->getBitWidth() != 32)
                {
                    writeArgs.push_back(codeGen);
                }
                else
                {
                    writeArgs.push_back(
                        ConstantInt::get(Type::getInt32Ty(LLVMCTX), APInt(32, constantInt->getSExtValue())));
                }
            }
            else
            {
                std::stringstream ss;
                ss << "invalid arg type: expect Integer32, but get: " << codeGen->getType()->getTypeID();
                util::err_print(std::cerr, ss.str());
            }
        }
        else if (Value *size = call->args[2]->codeGen(ctx); isa<IntegerType>(size->getType()))
        {
            writeArgs.push_back(size);
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
        }

        // Create the call instruction
        return BUILDER.CreateCall(fun, writeArgs, "write_calltmp");
    }

    if (fun->getName() == "fsync")
    {
        std::vector<Value *> fsyncArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            fsyncArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        // Create the call instruction
        return BUILDER.CreateCall(fun, fsyncArgs, "fsync_calltmp");
    }

    if (fun->getName() == "read")
    {
        std::vector<Value *> readArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            readArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else if (auto *varExpr = dynamic_cast<parser::VarExpr *>(call->args[0]))
        {
            if (Value *codeGen = varExpr->codeGen(ctx); isa<ConstantInt>(codeGen))
            {
                if (auto *constantInt = dyn_cast<ConstantInt>(codeGen); constantInt->getBitWidth() != 32)
                {
                    readArgs.push_back(codeGen);
                }
                else
                {
                    readArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, constantInt->getSExtValue())));
                }
            }
            else
            {
                REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
                return nullptr;
            }
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            readArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            readArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else if (auto *varExpr = dynamic_cast<parser::VarExpr *>(call->args[2]))
        {
            if (Value *codeGen = varExpr->codeGen(ctx); isa<ConstantInt>(codeGen))
            {
                if (auto *constantInt = dyn_cast<ConstantInt>(codeGen); constantInt->getBitWidth() != 32)
                {
                    readArgs.push_back(codeGen);
                }
                else
                {
                    readArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, constantInt->getSExtValue())));
                }
            }
            else
            {
                REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
                return nullptr;
            }
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, readArgs, "read_calltmp");
    }

    if (fun->getName() == "open")
    {
        std::vector<Value *> openArgs;
        if (auto *strExpr = dynamic_cast<parser::StringExpr *>(call->args[0]))
        {
            auto *strPtr = BUILDER.CreateGlobalStringPtr(strExpr->value);
            openArgs.push_back(strPtr);
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect String, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[1]))
        {
            openArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            openArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, openArgs, "open_calltmp");
    }

    if (fun->getName() == "close")
    {
        std::vector<Value *> closeArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            closeArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, closeArgs, "close_calltmp");
    }

    if (fun->getName() == "fork")
    {
        return BUILDER.CreateCall(fun, {}, "fork_calltmp");
    }

    if (fun->getName() == "execve")
    {
        std::vector<Value *> execveArgs;
        if (auto *strExpr = dynamic_cast<parser::StringExpr *>(call->args[0]))
        {
            auto *strPtr = BUILDER.CreateGlobalStringPtr(strExpr->value);
            execveArgs.push_back(strPtr);
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect String, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *arrExpr = dynamic_cast<parser::ArrayExpr *>(call->args[1]))
        {
            execveArgs.push_back(arrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Array, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *arrExpr = dynamic_cast<parser::ArrayExpr *>(call->args[2]))
        {
            execveArgs.push_back(arrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Array, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, execveArgs, "execve_calltmp");
    }

    if (fun->getName() == "wait")
    {
        std::vector<Value *> waitArgs;
        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[0]))
        {
            waitArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, waitArgs, "wait_calltmp");
    }

    if (fun->getName() == "mmap")
    {
        std::vector<Value *> mmapArgs;
        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[0]))
        {
            mmapArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[1]))
        {
            mmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(64, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer64, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            mmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[3]))
        {
            mmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[4]))
        {
            mmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[5]))
        {
            mmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(64, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer64, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, mmapArgs, "mmap_calltmp");
    }

    if (fun->getName() == "munmap")
    {
        std::vector<Value *> munmapArgs;
        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[0]))
        {
            munmapArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[1]))
        {
            munmapArgs.push_back(ConstantInt::get(LLVMCTX, APInt(64, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer64, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, munmapArgs, "munmap_calltmp");
    }

    if (fun->getName() == "socket")
    {
        std::vector<Value *> socketArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            socketArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[1]))
        {
            socketArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            socketArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, socketArgs, "socket_calltmp");
    }

    if (fun->getName() == "bind")
    {
        std::vector<Value *> bindArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            bindArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            bindArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            bindArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, bindArgs, "bind_calltmp");
    }

    if (fun->getName() == "listen")
    {
        std::vector<Value *> listenArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            listenArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, listenArgs, "listen_calltmp");
    }

    if (fun->getName() == "accept")
    {
        std::vector<Value *> acceptArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            acceptArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            acceptArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[2]))
        {
            acceptArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, acceptArgs, "accept_calltmp");
    }

    if (fun->getName() == "connect")
    {
        std::vector<Value *> connectArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            connectArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            connectArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            connectArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, connectArgs, "connect_calltmp");
    }

    if (fun->getName() == "send")
    {
        std::vector<Value *> sendArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            sendArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            sendArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            sendArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[3]))
        {
            sendArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, sendArgs, "send_calltmp");
    }

    if (fun->getName() == "recv")
    {
        std::vector<Value *> recvArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            recvArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[1]))
        {
            recvArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[2]))
        {
            recvArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[3]))
        {
            recvArgs.push_back(ConstantInt::get(LLVMCTX, APInt(32, intExpr->value)));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        return BUILDER.CreateCall(fun, recvArgs, "recv_calltmp");
    }

    if (fun->getName() == "sbrk")
    {
        std::vector<Value *> sbrkArgs;
        if (auto *intExpr = dynamic_cast<parser::IntegerExpr *>(call->args[0]))
        {
            sbrkArgs.push_back(ConstantInt::get(Type::getInt32Ty(LLVMCTX), APInt(32, intExpr->value)));
        }
        else if (auto *varExpr = dynamic_cast<parser::VarExpr *>(call->args[0]))
        {
            if (Value *codeGen = varExpr->codeGen(ctx); isa<IntegerType>(codeGen->getType()))
            {
                sbrkArgs.push_back(codeGen);
            }
            else
            {
                std::stringstream ss;
                ss << "invalid arg type: expect Integer32, but get: " << codeGen->getType()->getTypeID();
                util::err_print(std::cerr, ss.str());
                return nullptr;
            }
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Integer32, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        // Create the call instruction
        return BUILDER.CreateCall(fun, sbrkArgs, "sbrk_calltmp");
    }

    if (fun->getName() == "brk")
    {
        std::vector<Value *> brkArgs;
        if (auto *ptrExpr = dynamic_cast<parser::PointerExpr *>(call->args[0]))
        {
            brkArgs.push_back(ptrExpr->codeGen(ctx));
        }
        else
        {
            REPORT_ERROR("invalid arg type: expect Pointer, but get: unknown", __FILE__, __LINE__);
            return nullptr;
        }

        // Create the call instruction
        return BUILDER.CreateCall(fun, brkArgs, "brk_calltmp");
    }

    // REPORT_ERROR("unknown system call: " + fun->getName().str(), __FILE__, __LINE__);
    return nullptr;
}
} // namespace dream::inter_gen