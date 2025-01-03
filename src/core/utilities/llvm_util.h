//
// Created by napbad on 10/28/24.
//

#ifndef LLVM_UTIL_H
#define LLVM_UTIL_H

#include "src/core/parser/node.h"
#include <llvm/IR/Type.h>
namespace dap::util
{
/* Returns an LLVM type based on the identifier */
Type *typeOf(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size = nullptr);

/* Returns an LLVM type based on the identifier, which returns type for metadata (specially for pointer cause that
 * llvm's pointer do not have type  info) */
Type *typeOf_d(const parser::QualifiedName &type, const inter_gen::InterGenContext *ctx, parser::Expr *size);

Type *getPointerOf(Type *type, const inter_gen::InterGenContext *ctx = nullptr);

Value *getVal(Value *src, inter_gen::InterGenContext *ctx);
} // namespace dap::util

#endif // LLVM_UTIL_H