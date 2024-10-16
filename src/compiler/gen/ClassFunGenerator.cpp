//
// Created by napbadsen on 24-10-11.
//

#include "ClassFunGenerator.h"

#include <numeric>

#include "util/parser_util.h"
#include "util/string_util.h"

using namespace parser_util;

void ClassFunGenerator::init(DreamParser::ClassFuncDeclContext* ctx)
{
    _name = ctx->IDENTIFIER()->getText();
    _const = ctx->CONST() != nullptr;

    _return_type = convert_type_list_to_tuple(ctx->returnType());


    if (ctx->paramList() == nullptr)
    {
        return;
    }

    for (DreamParser::ParamListContext* param_list_context = ctx->paramList();
         const auto param : param_list_context->param())
    {
        bool nullable = false;
        bool mutable_ = false;

        if (parse_tree_is_null(param->QUESTION()))
            nullable = true;
        if (parse_tree_is_null(param->VAR()))
            mutable_ = true;

        std::string type_name = param->type()->getText();
        _params.emplace_back(
            convert_type_to_cpp(type_name),
            param->IDENTIFIER()->getText(),
            nullable,
            mutable_
        );
    }
}

std::string ClassFunGenerator::generate_code() const
{
    return _return_type + " " + _name
        + "("
        + string_util::get_str_from_param_vector(_params, ", ")
        + ")"
        + (_const ? " const" : "");
}
