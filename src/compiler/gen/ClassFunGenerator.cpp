//
// Created by napbadsen on 24-10-11.
//

#include "ClassFunGenerator.h"

#include <numeric>

#include "util/parser_util.h"
#include "util/string_util.h"

using namespace parser_util;

void ClassFunGenerator::init(DreamParser::ClassFuncDeclContext* ctx, const std::string& class_name)
{
    _name = ctx->IDENTIFIER()->getText();
    _const = ctx->CONST() != nullptr;
    _class_name = class_name;

    for (const auto modifier : ctx->classMemberModifier())
    {
        if (modifier->visibilityModifier() != nullptr)
            if (modifier->visibilityModifier()->PRIVATE())
                _visibility = ClassMemberVisibility::PRIVATE;
            else if (modifier->visibilityModifier()->PROTECTED())
                _visibility = ClassMemberVisibility::PROTECTED;
            else if (modifier->visibilityModifier()->PUBLIC())
                _visibility = ClassMemberVisibility::PUBLIC;
        if (modifier->staticModifier() != nullptr && modifier->staticModifier()->STATIC())
            _static = true;
    }

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
    return _return_type + " " + _class_name + "::" + _name
        + "("
        + string_util::get_str_from_param_vector(_params, ", ")
        + ")"
        + (_const ? " const" : "")
        + "{ \n"
        + string_util::get_lines_from_vector(_stmts)
        + "\n}\n";
}

std::string ClassFunGenerator::generate_decl_code() const
{
    return _return_type + " " + _name
        + "("
        + string_util::get_str_from_param_vector(_params, ", ")
        + ")"
        + (_const ? " const" : "");
}

ClassMemberVisibility ClassFunGenerator::visibility() const
{
    return _visibility;
}

void ClassFunGenerator::add_stmt(const string& string)
{
    _stmts.push_back(string);
}
