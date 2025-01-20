//
// Created by napbad on 1/11/25.
//

#include "config.h"
#include "utilities/llvm_util.h"

#include <llvm/IR/LLVMContext.h>
#include <vector>

namespace dap
{
std::string buildDir = DEFUALT_BUILD_DIR;

std::string targetExecName = DEFAULT_TARGET_NAME;

std::string D_VERSION = "0.0.1";

void readConfig(std::string configPath)
{
}

int initCompiler(llvm::LLVMContext *llvmCtx)
{

    util::initTypeMap(llvmCtx);
}

std::vector<std::string> *filesToCompile = new std::vector<std::string>();
} // namespace dap
