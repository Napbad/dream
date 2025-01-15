//
// Created by napbad on 1/9/25.
//

#include "ASTNode.h"

#include "utilities/llvm_util.h"
#include "utilities/string_util.h"

std::string dap::parser::IntegerNode::getVal()
{
    switch (intType) {
    case INT:
        return std::to_string(intValue.signedVal);

    case UNSIGNED_INT:
        return std::to_string(intValue.unsignedVal);

    default:
        break;
    }
    return "";
}

std::string dap::parser::QualifiedNameNode::getName() const
{
    return util::getStrFromVec(*name_parts, ".");
}

dap::parser::FunctionDeclarationNode::~FunctionDeclarationNode()
{
    delete parameterList;
    delete returnType;
    for (const Statement *stmt : *block) {
        delete stmt;
    }
    delete block;
}