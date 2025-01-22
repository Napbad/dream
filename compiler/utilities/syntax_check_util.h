//
// Created by napbad on 1/20/25.
//

#ifndef SYNTAX_CHECK_UTIL_H
#define SYNTAX_CHECK_UTIL_H
#include "inter_gen/codeGen_inter.h"

namespace dap::inter_gen
{
class InterGenContext;
}

namespace dap::util
{
bool canDeclareMainFun(inter_gen::InterGenContext *ctx);
}

#endif // SYNTAX_CHECK_UTIL_H