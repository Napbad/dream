//
// Created by napbad on 12/8/24.
//

#include "variableCheck.h"

#include "inter_gen/metadata.h"

// TODO: fill this function to implement the nullable check
bool dap::inter_gen::isNullable(parser::Expression *valToCheck, InterGenContext *ctx)
{
    // if (valToCheck->isa(parser::NodeMetaDataType::VarExpr)) {
    const auto *varExpr = dynamic_cast<parser::QualifiedNameNode *>(valToCheck);
    // auto [val, metadata] = ctx->getValWithMetadata(varExpr->getFirstName());
    // if (metadata->isNullable()) {
    //     return true;
    // }
    // }

    // if (valToCheck->isa(parser::NodeMetaDataType::CallExpr)) {
    const auto *callExpr = dynamic_cast<parser::FunctionCallExpressionNode *>(valToCheck);
    // FunctionMetaData *functionMetaData = ctx->metaData->getFunction(callExpr->callee->getName());
    // VariableMetaData *varMetaData = functionMetaData->getReturnMetaData();

    // if (varMetaData == nullptr) {
    // return false;
    // }

    // if (varMetaData->isNullable()) {
    // return true;
    // }
    // }

    return false;
}