// //
// // Created by napbad on 10/24/24.
// //

#include <fstream>
#include <iostream>

#include <llvm/Bitstream/BitstreamReader.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/IR/BasicBlock.h>
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

#include "codeGen_inter.h"

#include "common/config.h"
#include "metadata.h"
#include "parser/ASTNode.h"
#include "parser/parser.hpp"
#include "utilities/file_util.h"
#include "utilities/llvm_util.h"
#include "utilities/log_util.h"
#include "utilities/name_format_util.h"
#include "utilities/string_util.h"

namespace dap
{

using llvm::BasicBlock;
using llvm::ConstantInt;
using llvm::Function;
using llvm::Module;
using llvm::Type;
using llvm::Value;

namespace parser
{
using std::map;
using std::string;

// QualifiedNameNode is considered as an expression which represent the variable
Value *QualifiedNameNode::codeGen(inter_gen::InterGenContext *ctx) const
{
    // sync the context
    ctx->currLine = this->lineNum;

    // get the value from exist variables
    Value *value = ctx->getVal(this->getName());

    // return it
    return value;
}

Value *ProgramNode::codeGen(inter_gen::InterGenContext *ctx) const
{
    // get the package and set the package directory
    ctx->currLine = this->lineNum;
    util::create_package_dir(util::getStrFromVec(*packageName->name_parts, "."));
    for (Statement *stmt : *statements) {
        stmt->codeGen(ctx);
    }
    util::create_package_dir(util::getStrFromVec(*packageName->name_parts, "."));

    for (const auto statement : *statements) {
        statement->codeGen(ctx);
    }

    // Generate code for program statements
    return nullptr;
}

bool detectType(const TypeNode *typeNode, const VariableDeclarationNode *node, inter_gen::InterGenContext *ctx,
                Type *varType)
{
    if (typeNode == nullptr) {
        // auto detect type
        if (node->value == nullptr) {
            varType = nullptr;
            return false;
        }
        // TODO: precise type detect, pointer to some type, array of some type
        const Value *expressionValue = node->value->codeGen(ctx);
        varType = expressionValue->getType();
        return true;
    }

    varType = util::typeOf(node->type, ctx);
    if (!varType) {
        varType = nullptr;
#ifdef D_DEBUG
        util::logErr("unknown type: " + node->type->getName(), ctx, __FILE__, __LINE__);
#else
        util::logErr("unknown type: " + node->type->getName(), ctx);
#endif
        return false;
    }
    return true;
}

Value *VariableDeclarationNode::codeGen(inter_gen::InterGenContext *ctx) const
{
    // sync the context position
    ctx->currLine = this->lineNum;
    ctx->setDefiningVariable(true);

    // find the type of variable
    Type *varType = nullptr;

    if (detectType(type, this, ctx, varType)) {
#ifdef D_DEBUG
        util::logErr("can not detect type [no initial expression]: " + variableName->getName(), ctx, __FILE__,
                     __LINE__);
#else
        util::logErr("can not detect type [no initial expression]: " + variableName->getName(), ctx);
#endif
        return nullptr;
    }

    // generate the variable
    AllocaInst *allocaVar = BUILDER.CreateAlloca(varType, nullptr, this->variableName->getName());

    auto varMetaData = new inter_gen::VariableMetaData(variableName->getName(), varType, mutable_, nullable_, ctx);
    ctx->locals().emplace(this->variableName->getName(),
                          std::pair<Value *, inter_gen::VariableMetaData *>(allocaVar, varMetaData));

#ifdef D_DEBUG
    util::logInfo("Variable Declaration: " + this->variableName->getName(), ctx, __FILE__, __LINE__);
#endif

    if (this->variableGenerated) {
        BUILDER.CreateStore(this->variableGenerateValue, allocaVar, false);
    }

    ctx->setDefiningVariable(false);

    // return the value
    return allocaVar;
}

Value *FunctionDeclarationNode::codeGen(inter_gen::InterGenContext *ctx) const
{
    // sync the context of the node
    ctx->currLine = this->lineNum;

    // get the function declaration info
    auto params = std::vector<Type *>();
    for (const auto param : *this->parameterList) {
        const auto node = dynamic_cast<VariableDeclarationNode *>(param);
        params.push_back(util::typeOf(node->type, ctx));
    }

    // generate the function info
    const auto type = FunctionType::get(util::typeOf(this->returnType, ctx), params, false);
    Function *function = Function::Create(type, Function::ExternalLinkage, 0, this->name, MODULE);

    ctx->setCurrFun(function);

    const auto funMetaData = new inter_gen::FunctionMetaData(this->name, type, ctx);

    // generate the basic block
    const auto basicBlock = BasicBlock::Create(LLVMCTX, util::getFunBasicBlockName(&this->name), function);
    ctx->pushBlock(basicBlock);

    if (this->block) {


    for (const auto stmt : *this->block) {
        stmt->codeGen(ctx);
    }
    }
#ifdef D_DEBUG
    util::logInfo("Function Declaration: " + this->name, ctx, __FILE__, __LINE__);
#endif // D_DEBUG

    // register the function
    ctx->addFunctionToMetaData(funMetaData);

    // pop the block
    ctx->popBlock();

    return function;
}

Value *BinaryExpressionNode::codeGen(inter_gen::InterGenContext *ctx) const
{

    ctx->currLine = this->lineNum;
    // Generate code for left-hand side and right-hand side Expressions
    Value *lhsVal = left->codeGen(ctx);
    Value *rhsVal = right->codeGen(ctx);

    // Check for null results from the code generation
    if (!lhsVal || !rhsVal) {
        return nullptr;
    }

    // Check if both expressions are of the same type
    const auto lhsType = lhsVal->getType();
    if (const auto rhsType = rhsVal->getType(); lhsType != rhsType) {
        if (llvm::isa<IntegerType>(lhsType) && llvm::isa<IntegerType>(rhsType)) {
            if (lhsType->getIntegerBitWidth() > rhsType->getIntegerBitWidth()) {
                rhsVal = BUILDER.CreateSExtOrTrunc(rhsVal, lhsType, "sext_or_trunc");
            } else if (lhsType->getIntegerBitWidth() < rhsType->getIntegerBitWidth()) {
                lhsVal = BUILDER.CreateSExtOrTrunc(lhsVal, rhsType, "sext_or_trunc");
            }
        } else {
#ifdef D_DEBUG
            util::logErr("Type mismatch in binary Expression", ctx, __FILE__, __LINE__);
#else
            util::logErr("Type mismatch in binary Expression", ctx);
#endif

            return nullptr;
        }
    }

    const bool isFloatingPoint = lhsType->isFloatingPointTy();

    switch (operatorType) {
        // Arithmetic operators
    case PLUS:
        return isFloatingPoint ? BUILDER.CreateFAdd(lhsVal, rhsVal, "addtmp")
                               : BUILDER.CreateAdd(lhsVal, rhsVal, "addtmp");
    case MINUS:
        return isFloatingPoint ? BUILDER.CreateFSub(lhsVal, rhsVal, "subtmp")
                               : BUILDER.CreateSub(lhsVal, rhsVal, "subtmp");
    case MUL:
        return isFloatingPoint ? BUILDER.CreateFMul(lhsVal, rhsVal, "multmp")
                               : BUILDER.CreateMul(lhsVal, rhsVal, "multmp");
    case DIV:
        return isFloatingPoint ? BUILDER.CreateFDiv(lhsVal, rhsVal, "divtmp")
                               : BUILDER.CreateSDiv(lhsVal, rhsVal, "divtmp");
    case MOD:
        return isFloatingPoint ? BUILDER.CreateFRem(lhsVal, rhsVal, "modtmp")
                               : BUILDER.CreateSRem(lhsVal, rhsVal, "modtmp");

    // Comparison operators
    case LESS_THAN:
        return isFloatingPoint ? BUILDER.CreateFCmpOLT(lhsVal, rhsVal, "ltcmp")
                               : BUILDER.CreateICmpSLT(lhsVal, rhsVal, "ltcmp");
    case GREATER_THAN:
        return isFloatingPoint ? BUILDER.CreateFCmpOGT(lhsVal, rhsVal, "gtcmp")
                               : BUILDER.CreateICmpSGT(lhsVal, rhsVal, "gtcmp");
    case LESS_THAN_EQUAL:
        return isFloatingPoint ? BUILDER.CreateFCmpOLE(lhsVal, rhsVal, "lecmp")
                               : BUILDER.CreateICmpSLE(lhsVal, rhsVal, "lecmp");
    case GREATER_THAN_EQUAL:
        return isFloatingPoint ? BUILDER.CreateFCmpOGE(lhsVal, rhsVal, "gecmp")
                               : BUILDER.CreateICmpSGE(lhsVal, rhsVal, "gecmp");
    case EQUAL:
        return isFloatingPoint ? BUILDER.CreateFCmpOEQ(lhsVal, rhsVal, "eqcmp")
                               : BUILDER.CreateICmpEQ(lhsVal, rhsVal, "eqcmp");
    case NOT_EQUAL:
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
    case SHIFT_LEFT:
        return BUILDER.CreateShl(lhsVal, rhsVal, "lshifttmp");
    case SHIFT_RIGHT:
        return BUILDER.CreateAShr(lhsVal, rhsVal, "urshifttmp");

    // Assignment operators
    case ASSIGN:
        return BUILDER.CreateStore(rhsVal, lhsVal, false);
    case ADD_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFAdd(lhsVal, rhsVal, "addassigntmp")
                                        : BUILDER.CreateAdd(lhsVal, rhsVal, "addassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case MINUS_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFSub(lhsVal, rhsVal, "subassigntmp")
                                        : BUILDER.CreateSub(lhsVal, rhsVal, "subassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case MUL_ASSIGN: {
        Value *result = isFloatingPoint ? BUILDER.CreateFMul(lhsVal, rhsVal, "mulassigntmp")
                                        : BUILDER.CreateMul(lhsVal, rhsVal, "mulassigntmp");
        return BUILDER.CreateStore(result, lhsVal);
    }
    case DIV_ASSIGN: {
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
#ifdef D_DEBUG
        util::logErr("Unknown binary operator", ctx, __FILE__, __LINE__);
#else
        util::logErr("Unknown binary operator", ctx);
#endif
        return nullptr;
    }
}

Value *UnaryExpressionNode::codeGen(inter_gen::InterGenContext *ctx) const
{

    ctx->currLine = this->lineNum;
    // Generate code for the expression of the unary operation
    Value *operVal = expression->codeGen(ctx);

    Value *res;
    Value *var;
    Value *varPtr;
    // Handle increment or decrement
    switch (operatorType) {
    case DECREMENT:
        operVal = BUILDER.CreateSub(operVal, ConstantInt::get(LLVMCTX, APInt(1, 1)), "decrease"); // Decrement
        return operVal;
    case INCREMENT:
        operVal = BUILDER.CreateAdd(operVal, ConstantInt::get(operVal->getType(), 1), "increase"); // Increment
        return operVal;
    case MUL:
        //
        // if (llvm::isa<PointerType>(operVal->getType())) {
        //     operVal = BUILDER.CreateLoad(expectDerefType_d->top(), operVal, "dereference");
        //     return operVal;
        // }

#ifdef D_DEBUG
        util::logErr("Invalid pointer dereference", ctx, __FILE__, __LINE__);
#else
        util::logErr("Invalid pointer dereference", ctx);
#endif

    case MINUS:
        return BUILDER.CreateNeg(operVal, "negate");
    case BIT_AND:

        if (LoadInst *loadInst = dyn_cast<LoadInst>(operVal)) {
            Value *ptr = loadInst->getOperand(0);
            return ptr;
        }

        if (dyn_cast<AllocaInst>(operVal)) {
            return operVal;
        }
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
    case DIV_ASSIGN:
        res = BUILDER.CreateSDiv(expression->codeGen(ctx), operVal);
        var = expression->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);
    case ADD_ASSIGN:
        res = BUILDER.CreateAdd(expression->codeGen(ctx), operVal);
        var = expression->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case MINUS_ASSIGN:
        res = BUILDER.CreateSub(expression->codeGen(ctx), operVal);
        var = expression->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case MUL_ASSIGN:
        res = BUILDER.CreateMul(expression->codeGen(ctx), operVal);
        var = expression->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));
        return BUILDER.CreateStore(res, varPtr);

    case MOD_ASSIGN:
        res = BUILDER.CreateSRem(expression->codeGen(ctx), operVal);
        var = expression->codeGen(ctx);
        varPtr = BUILDER.CreateGEP(var->getType(), var, ConstantInt::get(LLVMCTX, APInt(1, 0)));

        return BUILDER.CreateStore(res, varPtr);
    case BANG:
        return BUILDER.CreateNot(operVal, "not");
    default:
        return nullptr;
    }
}

Value *FunctionCallExpressionNode::codeGen(inter_gen::InterGenContext *ctx) const
{
    // context sync
    ctx->currLine = this->lineNum;

    // find the function, create the function
    Function *function = MODULE->getFunction(name->getName());
    if (!function) {
#ifdef D_DEBUG
        util::logErr("Function " + name->getName() + " not found", ctx, __FILE__, __LINE__);
#else
        util::logErr("Function " + name->getName() + " not found", ctx);
#endif
    }

    // build args
    std::vector<Value *> functionArgs;
    for (auto arg : *args) {
        functionArgs.push_back(arg->codeGen(ctx));
    }

    // call
    Value *callResult = BUILDER.CreateCall(function, functionArgs, "call");

    // return the value
    return callResult;
}

} // namespace parser

namespace inter_gen
{
FunctionMetaData *InterGenContext::getFunMetaData(const std::string &name, const InterGenContext *ctx)const
{

    if (FunctionMetaData *funMetaData = metaData->getFunction(name)) {
        return funMetaData;
    }
#ifdef D_DEBUG
    util::logErr("Function " + name + " not found", ctx, __FILE__, __LINE__);
#else
    util::logErr("Function " + name + " not found", ctx);
#endif

    return nullptr;
}

std::pair<Value *, VariableMetaData *> InterGenContext::getValWithMetadata(const parser::QualifiedNameNode *name)
{
    // int idx = 0;
    // std::pair<Value *, VariableMetaData *> val_with_metadata = this->getValWithMetadata(name->getName(idx));
    // while (val_with_metadata.first && val_with_metadata.second) {
    //     if (name->name_parts->size() == idx + 1) {
    //         return val_with_metadata;
    //     }
    //     idx++;
    // }
    // {
    //     // REPORT_ERROR(errMsg("Value not found" + name->getName()), __FILE__, __LINE__);
    // }
    return {nullptr, nullptr};
}

void InterGenContext::genIR(parser::ProgramNode *program)
{
    program->codeGen(this);

    if (!mainFunction && (sourcePath.ends_with("/main.dap") || sourcePath == "main.dap")) {
        constexpr std::vector<Type *> argTypes;
        // FunctionType *ftype = FunctionType::get(Type::getInt32Ty(module->getContext()), llvm::ArrayRef(argTypes),
        // false); mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);
        BasicBlock *bblock = BasicBlock::Create(module->getContext(), "entry", mainFunction, nullptr);

        builder.SetInsertPoint(bblock);
        pushBlock(bblock);

        builder.CreateRet(llvm::ConstantInt::get(module->getContext(), llvm::APInt(32, 0)));

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

void InterGenContext::genExec(parser::ProgramNode *program)
{
    // Initialize LLVM targets
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    // program->codeGen(this);

    if (!mainFunction && (sourcePath.ends_with("/main.dap") || sourcePath == "main.dap")) {
        // Define the main function (i32 @main())
        // FunctionType *ftype = FunctionType::get(Type::getInt32Ty(module->getContext()), false);
        // mainFunction = Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);

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
    TargetMachine *targetMachine =
        target->createTargetMachine(targetTriple, cpu, features, opt, Reloc::PIC_);

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
    // if (!node->getIncludes().empty()) {
    //     for (const auto oneNode : node->getIncludes()) {
    //         interGen_oneFile(oneNode);
    //     }
    // }
    // programMap_d->at(node->getProgram())->genIR(node->getProgram());
    // visited.insert({node, true});
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
            const auto &funMetadata = metaData->getFunction(fun->getName().str());
            for (auto &arg : fun->args()) {
                if (arg.getName() == name) {
                    // return {&arg, funMetadata->getArgMetaData(arg.getName().str())};
                }
            }
        }
        tmp.push(blocks.top());
        blocks.pop();
    }

    if (module->getGlobalVariable(name)) {
        // return {module->getGlobalVariable(name), getModuleMetaData(name)->getGlobalValMetaData(name)};
    }

    return {nullptr, nullptr};
}

void InterGenContext::addFunctionToMetaData(FunctionMetaData *function_meta_data) const
{
    metaData->addFunction(function_meta_data);
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
