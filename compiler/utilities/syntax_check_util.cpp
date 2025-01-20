//
// Created by napbad on 1/20/25.
//

#include "syntax_check_util.h"
bool dap::util::canDeclareMainFun(inter_gen::InterGenContext *ctx){
    if (ctx && ctx->package == "main") {
        return true;
    }
    return false;
}