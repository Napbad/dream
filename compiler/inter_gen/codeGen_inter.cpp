// //
// // Created by napbad on 10/24/24.
// //

#include <fstream>
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

#include "codeGen_inter.h"

#include "common/config.h"
#include "parser/ASTNode.h"
#include "utilities/file_util.h"
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

llvm::Value *ProgramNode::codeGen(inter_gen::InterGenContext *ctx)
{
    // get the package and setup the package directory
    ctx->currLine = this->lineNum;
    util::create_package_dir(util::getStrFromVec(*packageName->name_parts, "."));
    for (Statement *stmt : *statements) {
        stmt->codeGen(ctx);
    }
    util::create_package_dir(util::getStrFromVec(*packageName->name_parts, "."));

    for (auto statement : *statements) {
        statement->codeGen(ctx);
    }

    // Generate code for program statements
    return nullptr;
}
} // namespace parser

namespace inter_gen
{
FunctionMetaData *InterGenContext::getFunMetaData(const std::string &name, const InterGenContext *ctx) const
{
    // for (const auto &fun : metaData->getFunctions()) {
    //     if (fun->getName() == name) {
    //         return fun;
    //     }
    // }
    // REPORT_ERROR("error at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) + " \nFunction " + name +
    //                  " not found",
    //              __FILE__, __LINE__);
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
    // program->codeGen(this);

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
    llvm::raw_fd_ostream outfile(outputPath, EC, llvm::sys::fs::OF_Text);

    if (EC) {
        llvm::errs() << "Error opening output file: " << EC.message() << "\n";
        return;
    }
    llvm::legacy::PassManager pm;
    pm.add(llvm::createPrintModulePass(outfile));
    pm.run(*module);

    outfile.flush();
    outfile.close();
}

void InterGenContext::genExec(parser::ProgramNode *program)
{
    // Initialize LLVM targets
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

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
    const std::string targetTriple = llvm::sys::getDefaultTargetTriple();
    module->setTargetTriple(targetTriple);

    std::string error;
    const llvm::Target *target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        llvm::errs() << "Error: " << error;
        return;
    }

    // CPU and features
    const std::string cpu = "generic";
    const std::string features;

    const llvm::TargetOptions opt;
    std::optional<llvm::Reloc::Model>();
    llvm::TargetMachine *targetMachine =
        target->createTargetMachine(targetTriple, cpu, features, opt, llvm::Reloc::PIC_);

    module->setDataLayout(targetMachine->createDataLayout());

    // Create the MCJIT execution engine
    std::unique_ptr<Module> modulePtr(module);
    auto mem_mgr = std::make_unique<llvm::SectionMemoryManager>();

    // Save the generated code to a file
    std::error_code EC;
    util::replaceAll(package, ".", "/");
    std::string outputPath = buildDir + package + "/" + fileName + ".o";
    std::fstream outputFile(outputPath, std::ios::out);
    outputFile.close();
    filesToCompile->push_back(outputPath);
    llvm::raw_fd_ostream dest(outputPath, EC, llvm::sys::fs::OF_None);

    if (EC) {
        llvm::errs() << "Could not open file for writing: " << EC.message() << "\n";
        return;
    }

    llvm::legacy::PassManager pass;
    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, llvm::CodeGenFileType::ObjectFile)) {
        llvm::errs() << "TargetMachine can't emit a file of this type\n";
        return;
    }

    pass.run(*module);
    dest.flush();

    llvm::outs() << "Object file emitted to " << outputPath << "\n";
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
            const auto &funMetadata = functions[fun->getName().str()];
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