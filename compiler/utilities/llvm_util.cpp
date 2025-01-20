#include "llvm_util.h"

#include <llvm/IR/DerivedTypes.h>
// //
// // Created by napbad on 10/28/24.
// //

// #include "llvm_util.h"
// #include <unordered_map>

// #include "data_struct_util.h"
// #include "file_util.h"
namespace dap::util
{
static std::unordered_map<std::string, llvm::Type *> typeMap = {};

llvm::Type *typeOf(const parser::TypeNode *type, const inter_gen::InterGenContext *ctx, parser::Expression *size)
{

    return nullptr;
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

} // namespace dap::util
