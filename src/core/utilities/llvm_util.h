//
// Created by napbad on 10/28/24.
//

#ifndef LLVM_UTIL_H
#define LLVM_UTIL_H
#include "../parser/node.h"

#include <llvm/IR/Type.h>

namespace dream::util
{
/* Returns an LLVM type based on the identifier */
Type *typeOf(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size = nullptr);

Type *typeOf_d(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size);

Type *getPointerOf(Type *type);
} // namespace dream::util

#endif // LLVM_UTIL_H