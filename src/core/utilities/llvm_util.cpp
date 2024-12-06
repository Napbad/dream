//
// Created by napbad on 10/28/24.
//


#include <unordered_map>
#include "llvm_util.h"

#include "src/core/common/derived_type.h"
#include "src/core/common/global.h"
#include "src/core/common/reserve.h"
#include "data_struct_util.h"
#include "file_util.h"
namespace dap::util
{
static const std::unordered_map<std::string, std::function<Type *(LLVMContext &)>> typeMap = {
    {"int", &Type::getInt32Ty},
    {"byte", &Type::getInt8Ty},
    {"short", &Type::getInt16Ty},
    {"long", &Type::getInt64Ty},
    {"char", &Type::getInt8Ty},
    {"float", &Type::getFloatTy},
    {"string", [](LLVMContext &ctx) { return getPointerOf(Type::getInt8Ty(ctx)); }},
    {"bool", &Type::getInt1Ty},
    {"uint", &Type::getInt32Ty},
    {"ushort", &Type::getInt16Ty},
    {"ulong", &Type::getInt64Ty},
    {"llong", &Type::getInt128Ty},
    {"ullong", &Type::getInt128Ty},
    {"double", &Type::getDoubleTy}};

Type *typeOf(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size)
{
    if (type.name_parts == nullptr || type.name_parts->empty() || type.getName()=="void")
    {
        return Type::getVoidTy(LLVMCTX);
    }

    if (type.name_parts->back() == D_POINTER_SUFIX)
    {
        const std::vector<std::string> *nameParts = type.name_parts;
        std::vector<std::string> vec = getSubVector(*nameParts, 0, type.name_parts->size() - 1);
        return getPointerOf(typeOf(parser::QualifiedName(&vec), ctx, nullptr));
    }

    if (type.name_parts->back() == D_ARR_SUFIX)
    {
        const parser::IntegerExpr *integerExpr = dynamic_cast<parser::IntegerExpr *>(size);
        if (integerExpr == nullptr)
        {
            REPORT_ERROR("array size must be integer", __FILE__, __LINE__);
            return ArrayType::get(typeOf(parser::QualifiedName(type.getName(0)), ctx, nullptr), 1);
        }
        return ArrayType::get(typeOf(parser::QualifiedName(type.getName(0)), ctx, nullptr), integerExpr->value);
    }
    if (const auto it = typeMap.find(type.getName()); it != typeMap.end())
    {
        return it->second(LLVMCTX);
    }
    // Handle custom types or return nullptr for unsupported types

    if (StructType *structType = StructType::getTypeByName(LLVMCTX, type.getName()))
    {
        return structType;
    }

    return nullptr;
}

Type *typeOf_d(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size)
{
    if (type.name_parts == nullptr || type.name_parts->empty())
    {
        return Type::getVoidTy(LLVMCTX);
    }

    if (type.name_parts->back() == D_POINTER_SUFIX)
    {
        const std::vector<std::string> *nameParts = type.name_parts;
        std::vector<std::string> vec = getSubVector(*nameParts, 0, type.name_parts->size() - 1);
        return PointerType_d::get(LLVMCTX, typeOf(parser::QualifiedName(&vec), ctx, nullptr));
    }

    if (type.name_parts->back() == D_ARR_SUFIX)
    {
        const parser::IntegerExpr *integerExpr = dynamic_cast<parser::IntegerExpr *>(size);
        if (integerExpr == nullptr)
        {
            REPORT_ERROR("array size must be integer", __FILE__, __LINE__);
            return ArrayType::get(typeOf(parser::QualifiedName(type.getName(0)), ctx, nullptr), 1);
        }
        return ArrayType::get(typeOf(parser::QualifiedName(type.getName(0)), ctx, nullptr), integerExpr->value);
    }
    if (const auto it = typeMap.find(type.getName()); it != typeMap.end())
    {
        return it->second(LLVMCTX);
    }
    // Handle custom types or return nullptr for unsupported types

    if (StructType *structType = StructType::getTypeByName(LLVMCTX, type.getName()))
    {
        return structType;
    }

    return nullptr;
}

inline Type *getPointerOf(Type *type)
{
    PointerType *pointer = PointerType::get(type, 0);
    return pointer;
}
} // namespace dap::util