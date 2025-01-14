//
// Created by napbad on 1/9/25.
//

#include "ASTNode.h"

#include "utilities/llvm_util.h"
#include "utilities/string_util.h"

std::string dap::parser::Integer::getVal()
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

std::string dap::parser::QualifiedName::getName() const
{
    return util::getStrFromVec(*name_parts, ".");
}
