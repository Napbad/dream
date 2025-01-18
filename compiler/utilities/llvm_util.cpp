// //
// // Created by napbad on 10/28/24.
// //

// #include "llvm_util.h"
// #include <unordered_map>

// #include "data_struct_util.h"
// #include "file_util.h"
// namespace dap::util
// {
// static const std::unordered_map<std::string, llvm::Type> typeMap = {
//     {"int", llvm::Type::getInt32Ty()},
//     {"byte", llvm::Type::getInt8Ty()},
//     {"short", llvm::Type::getInt16Ty()},
//     {"long", llvm::Type::getInt64Ty()},
//     {"char", llvm::Type::getInt8Ty()},
//     {"float", llvm::Type::getFloatTy()},
//     {"string", [](llvm::LLVMContext &ctx) { return getPointerOf(llvm::Type::getInt8Ty(ctx)); }},
//     {"bool", llvm::Type::getInt1Ty()},
//     {"uint", llvm::Type::getInt32Ty()},
//     {"ushort", llvm::Type::getInt16Ty()},
//     {"ulong", llvm::Type::getInt64Ty()},
//     {"llong", llvm::Type::getInt128Ty()},
//     {"ullong", llvm::Type::getInt128Ty()},
//     {"double", llvm::Type::getDoubleTy()}};

// llvm::Type *typeOf(const parser::QualifiedNameNode &type, const inter_gen::InterGenContext *ctx, parser::Expr *size)
// {

//     if (type.name_parts == nullptr || type.name_parts->empty() || type.getName() == "void") {
//         return llvm::Type::getVoidTy(LLVMCTX);
//     }

//     if (const auto it = typeMap.find(type.getName()); it != typeMap.end()) {
//         return it->second(LLVMCTX);
//     }

//     // Handle custom types or return nullptr for unsupported types
//     if (type.getName() == "Point") {
//         StructType *structType = StructType::getTypeByName(LLVMCTX, type.getName());
//         return StructType::getTypeByName(LLVMCTX, "Point");
//     }

//     if (StructType *structType = StructType::getTypeByName(LLVMCTX, type.getName())) {
//         return structType;
//     }

//     if (type.name_parts->size() == 2 &&
//         type.name_parts->at(0) == "void" &&
//         type.name_parts->at(1) == "*"){
//         return PointerType::get(LLVMCTX, 0);
//     }

//     if (type.name_parts->back() == D_POINTER_SUFIX) {
//         const std::vector<std::string> *nameParts = type.name_parts;
//         std::vector<std::string> vec = getSubVector(*nameParts, 0, type.name_parts->size() - 1);
//         return getPointerOf(typeOf(parser::QualifiedNameNode(&vec), ctx, nullptr), ctx);
//     }

//     if (type.name_parts->back() == D_ARR_SUFIX) {
//         const parser::IntegerNodeExpr *IntegerNodeExpr = dynamic_cast<parser::IntegerNodeExpr *>(size);
//         if (IntegerNodeExpr == nullptr) {
//             REPORT_ERROR("warn at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
//                          " \n array size must be IntegerNode", __FILE__, __LINE__);
//             return ArrayType::get(typeOf(parser::QualifiedNameNode(type.getName(0)), ctx, nullptr), 1);
//         }
//         return ArrayType::get(typeOf(parser::QualifiedNameNode(type.getName(0)), ctx, nullptr),
//         IntegerNodeExpr->value);
//     }

//     return nullptr;
// }

// llvm::Type *typeOf_d(const parser::QualifiedNameNode &type, const inter_gen::InterGenContext *ctx, parser::Expr
// *size)
// {
//     if (type.name_parts == nullptr || type.name_parts->empty()) {
//         return llvm::Type::getVoidTy(LLVMCTX);
//     }

//     if (type.name_parts->back() == D_POINTER_SUFIX) {
//         const std::vector<std::string> *nameParts = type.name_parts;
//         std::vector<std::string> vec = getSubVector(*nameParts, 0, type.name_parts->size() - 1);
//         return PointerType_d::get(LLVMCTX, typeOf(parser::QualifiedNameNode(&vec), ctx, nullptr));
//     }

//     if (type.name_parts->back() == D_ARR_SUFIX) {
//         const parser::IntegerNodeExpr *IntegerNodeExpr = dynamic_cast<parser::IntegerNodeExpr *>(size);
//         if (IntegerNodeExpr == nullptr) {
//             REPORT_ERROR("array size must be IntegerNode", __FILE__, __LINE__);
//             return ArrayType::get(typeOf(parser::QualifiedNameNode(type.getName(0)), ctx, nullptr), 1);
//         }
//         return ArrayType::get(typeOf(parser::QualifiedNameNode(type.getName(0)), ctx, nullptr),
//         IntegerNodeExpr->value);
//     }
//     if (const auto it = typeMap.find(type.getName()); it != typeMap.end()) {
//         return it->second(LLVMCTX);
//     }
//     // Handle custom types or return nullptr for unsupported types

//     if (StructType *structType = StructType::getTypeByName(LLVMCTX, type.getName())) {
//         return structType;
//     }

//     return nullptr;
// }

// inline llvm::Type *getPointerOf(llvm::Type *type, const inter_gen::InterGenContext *ctx)
// {
//     if (!type) {
//         REPORT_WARNING("warn at: " + ctx->sourcePath + ":" + std::to_string(ctx->currLine) +
//                          " \ntype is null", __FILE__, __LINE__);
//         return PointerType::get(LLVMCTX, 0);
//     }
//     PointerType *pointer = PointerType::get(type, 0);
//     return pointer;
// }
// Value *getVal(Value *src, inter_gen::InterGenContext* ctx)
// {
//     if (const auto alloc = dyn_cast<AllocaInst>(src)) {
//         return BUILDER.CreateLoad(alloc->getAllocatedType(), alloc, "cal_alloc");
//     }

//     if (src->getType()->isPointerTy()) {
//         return BUILDER.CreateLoad(getEPSrcVal(src)->getAllocatedType(), getEPSrcVal(src), "cal_alloc");
//     }

//     return src;
// }
// } // namespace dap::util