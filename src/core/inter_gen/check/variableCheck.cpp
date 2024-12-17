//
// Created by napbad on 12/8/24.
//

#include "variableCheck.h"

bool dap::inter_gen::isNullable(parser::Expr *valToCheck, InterGenContext *ctx)
{
    if (valToCheck->isa(parser::NodeMetaDataType::VarExpr)) {
        const auto *varExpr = dynamic_cast<parser::VarExpr *>(valToCheck);
        auto [val, metadata] = ctx->getValWithMetadata(varExpr->name->getFirstName());
        if (metadata->isNullable()) {
            return true;
        }
    }

    if (valToCheck->isa(parser::NodeMetaDataType::CallExpr)) {
        const auto *callExpr = dynamic_cast<parser::CallExpr *>(valToCheck);
        FunctionMetaData *functionMetaData = ctx->metaData->getFunction(callExpr->callee->getName());
        VariableMetaData *varMetaData = functionMetaData->getReturnMetaData();

        if (varMetaData == nullptr) {
            return false;
        }

        if (varMetaData->isNullable()) {
            return true;
        }
    }

    return false;
}