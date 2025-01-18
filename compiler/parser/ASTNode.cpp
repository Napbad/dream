//
// Created by napbad on 1/9/25.
//

#include "ASTNode.h"

#include "utilities/llvm_util.h"
#include "utilities/string_util.h"

std::string dap::parser::IntegerNode::getVal()
{
    switch (intType)
    {
    case INT:
        if (isSigned)
        {
            return std::to_string(intValue.signedVal);
        }
        else
        {
            return std::to_string(intValue.unsignedVal);
        }
    case LONG:
        if (isSigned)
        {
            return std::to_string(intValue.longVal);
        }
        else
        {
            return std::to_string(intValue.unsignedLongVal);
        }
    case SHORT:
        if (isSigned)
        {
            return std::to_string(intValue.shortVal);
        }
        else
        {
            return std::to_string(intValue.unsignedShortVal);
        }
    case CHAR:
        if (isSigned)
        {
            return std::to_string(intValue.charVal);
        }
        else
        {
            return std::to_string(intValue.unsignedCharVal);
        }
    case LONG_LONG:
        if (isSigned)
        {
            return std::to_string(intValue.longLongVal);
        }
        else
        {
            return std::to_string(intValue.unsignedLongLongVal);
        }
    default:
        return "";
    }
}

std::string dap::parser::QualifiedNameNode::getName() const
{
    return util::getStrFromVec(*name_parts, ".");
}

dap::parser::FunctionDeclarationNode::~FunctionDeclarationNode()
{
    delete parameterList;
    delete returnType;
    for (const Statement *stmt : *block)
    {
        delete stmt;
    }
    delete block;
}