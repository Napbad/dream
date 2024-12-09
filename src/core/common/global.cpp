//
// Created by napbad on 11/20/24.
//
#include "global.h"

#include "../utilities/file_util.h"

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>

heap_d *globalHeap_d = nullptr;

std::map<Value *, AllocaInst *> *gepMapping_d = new std::map<Value *, AllocaInst *>();

std::map<BasicBlock *, Value *> *blockMappingRet_d = new std::map<BasicBlock *, Value *>();

std::stack<Type *> *expectDerefType_d = new std::stack<Type *>();

std::unordered_map<std::string, dap::inter_gen::ModuleMetaData *> *moduleMetadataMap_d =
    new std::unordered_map<std::string, dap::inter_gen::ModuleMetaData *>();

std::unordered_map<dap::parser::Program *, dap::inter_gen::InterGenContext *> *programMap_d =
    new std::unordered_map<dap::parser::Program *, dap::inter_gen::InterGenContext *>();

std::vector<std::string> *filesToCompile = new std::vector<std::string>();

std::string buildDir = "./build/";

std::string targetExecName = "main";

dap::inter_gen::ModuleMetaData *getModuleMetaData(const std::string &name)
{
    for (const auto&[moduleName, metaData] : *moduleMetadataMap_d)
    {
        if (moduleName == name)
        {
            return metaData;
        }
    }

    return nullptr;
}