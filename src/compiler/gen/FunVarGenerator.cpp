//
// Created by napbadsen on 24-10-11.
//

#include "FunVarGenerator.h"

#include "common/reserve.h"
#include "util/file_util.h"
#include "util/parser_util.h"
#include "util/response_util.h"
#include "util/string_util.h"

using namespace std;

void FunVarGenerator::init_with_7_part(const DreamParser::FunVarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;


    const string var_mut = child[0]->getText();
    const string var_null = child[3]->getText();
    const string var_val = child[5]->getText();
    string var_type = child[1]->getText();

    _name = child[2]->getText();
    _type = parser_util::convert_type_to_cpp(var_type);
    _value = string_util::convert_parser_tree_to_string(child[5]);


    if (var_null == D_NULLABLE)
        _is_nullable = true;
    else
        _is_nullable = false;
}

void FunVarGenerator::init_with_5_part(const DreamParser::FunVarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

    const string var_val = child[3]->getText();
    string var_type = child[0]->getText();
    _name = child[1]->getText();

    _type = parser_util::convert_type_to_cpp(var_type);

    _value = string_util::convert_parser_tree_to_string(child[3]);
}

void FunVarGenerator::init_with_6_part(const DreamParser::FunVarDeclarationContext* ctx)
{
    if (const std::vector<antlr4::tree::ParseTree*> children = ctx->children;
        children.at(0)->getText() == D_VAR || children.at(0)->getText() == D_IMT)
    {
        _name = children[2]->getText();
        const string var_mut = children[0]->getText();
        const string var_val = string_util::convert_parser_tree_to_string(children[4]);
        string var_type = children[1]->getText();

        _value = var_val;
        _type = parser_util::convert_type_to_cpp(var_type);
        if (var_mut == D_VAR)
        {
            _is_mutable = true;
            return;
        }

        if (var_val == D_NULL)
        {
            response_util::report_error(
                "Cannot assign null to non-nullable variable",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));
            return;
        }

        if (parser_util::find_nullable(_listener_compiler->current_hierarchy(), ctx->children[4]))
            response_util::report_error(
                "Cannot assign null to non-nullable variable ( " +
                _name + " ) \n because <" +
                var_val +
                "> might be null \n ",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));

        return;
    }
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

    const string var_name = child[1]->getText();
    const string var_null = child[2]->getText();
    const string var_val = string_util::convert_parser_tree_to_string(child[4]);
    string var_type = child[0]->getText();

    _name = var_name;
    _value = var_val;
    _type = parser_util::convert_type_to_cpp(var_type);

    if (var_null == D_NON_NULLABLE)
    {
        _is_nullable = false;
        if (var_val == D_NULL)
            response_util::report_error(
                "Cannot assign null to non-nullable variable",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));

        if (parser_util::find_nullable(_listener_compiler->current_hierarchy(), ctx->children[4]))
            response_util::report_error(
                "Cannot assign null to non-nullable variable ( " +
                var_name + " ) \n because <" +
                var_val +
                "> might be null \n ",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));
    }
}

void FunVarGenerator::init_with_4_part(const DreamParser::FunVarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

    const string var_mut = child[0]->getText();
    _name = child[2]->getText();
    _type = child[1]->getText();

    if (var_mut == D_IMT)
        file_util::warn_print(cout, "declare a immutable object with no value, will use default value\n");
    else
        _is_mutable = true;

    _type = parser_util::convert_type_to_cpp(_type);

    _value = parser_util::generate_default_value(_type);
}

void FunVarGenerator::init_with_3_part(const DreamParser::FunVarDeclarationContext* ctx)
{
    file_util::warn_print(cout, "declare a immutable variable with no value, will use default value\n");
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;
    _name = child[1]->getText();
    string var_type = child[0]->getText();
    _type = parser_util::convert_type_to_cpp(var_type);
    _value = parser_util::generate_default_value(_type);
}

void FunVarGenerator::init(const DreamParser::FunVarDeclarationContext* ctx)
{
    if (ctx->children.size() == 7)
        init_with_7_part(ctx);
    else if (ctx->children.size() == 6)
        init_with_6_part(ctx);
    else if (ctx->children.size() == 5)
        init_with_5_part(ctx);
    else if (ctx->children.size() == 4)
        init_with_4_part(ctx);
    else if (ctx->children.size() == 3)
        init_with_3_part(ctx);
}

std::string FunVarGenerator::generate_code() const
{
    string tmp = _value;
    string_util::replace_all_without_str(tmp, ".", "->");
    return (_is_mutable ? "const " : "") + _type + " " + _name + " = " + tmp + ";\n";
}


[[nodiscard]] const std::string& FunVarGenerator::name() const
{
    return _name;
}

[[nodiscard]] const std::string& FunVarGenerator::type() const
{
    return _type;
}

[[nodiscard]] const std::string& FunVarGenerator::value() const
{
    return _value;
}

[[nodiscard]] bool FunVarGenerator::is_mutable() const
{
    return _is_mutable;
}

[[nodiscard]] bool FunVarGenerator::is_nullable() const
{
    return _is_nullable;
}
