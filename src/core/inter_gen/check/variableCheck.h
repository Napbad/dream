//
// Created by napbad on 12/8/24.
//

#ifndef VARIABLE_CHECK
#define VARIABLE_CHECK
#include "src/core/parser/node.h"

namespace dap::inter_gen
{
bool checkValueMutable();

bool isNullable(parser::Expr *valToCheck, InterGenContext *ctx);
} // namespace dap::inter_gen

#endif // VARIABLE_CHECK
