//
// Created by napbadsen on 24-10-11.
//

#include "FileVarGenerator.h"

#include "common/reserve.h"
#include "util/parser_util.h"
#include "util/response_util.h"
#include "util/string_util.h"

using namespace std;

void FileVarGenerator::init_with_7_part(DreamParser::VarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;


    const string var_mut = child[0]->getText();
    const string var_null = child[3]->getText();
    const string var_val = child[5]->getText();
    string var_type = child[1]->getText();

    if (var_val.starts_with("new"))
        var_type = var_type + "*";

    _name = child[2]->getText();
    _type = parser_util::convert_type_to_cpp(var_type);
    _value = string_util::convert_parser_tree_to_string(child[5]);


    if (var_null == D_NULLABLE)
        _is_nullable = true;
    else
        _is_nullable = false;
}

void FileVarGenerator::init_with_5_part(DreamParser::VarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;


    const string var_val = child[3]->getText();
    string var_type = child[0]->getText();
    _name = child[2]->getText();

    if (var_val.starts_with("new"))
        var_type = var_type + "*";

    _type = parser_util::convert_type_to_cpp(var_type);

    _value = string_util::convert_parser_tree_to_string(child[3]);
}

void FileVarGenerator::init_with_6_part(DreamParser::VarDeclarationContext* ctx)
{
    const std::vector<antlr4::tree::ParseTree*> children = ctx->children;
    if (children.at(0)->getText() == D_VAR || children.at(0)->getText() == D_IMT)
    {
        const string var_name = children[2]->getText();
        const string var_mut = children[0]->getText();
        const string var_val = children[4]->getText();
        string var_type = children[1]->getText();

        if (var_mut == D_IMT)
            _is_mutable = false;
        else
            _is_mutable = true;

        if (var_val == D_NULL)
        {
            response_util::report_error(
                "Cannot assign null to non-nullable variable",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));
            return;
        }

        if (parser_util::find_nullable(_listener_compiler->current_hierarchy(), ctx))
            response_util::report_error(
                "Cannot assign null to non-nullable variable ( " +
                var_name + " ) \n because <" +
                var_val +
                "> might be null \n ",
                _listener_compiler->file_source(),
                static_cast<int>(ctx->getStart()->getLine()));

        return;
    }
    const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

    const string var_name = child[1]->getText();
    const string var_null = child[2]->getText();
    const string var_val = child[4]->getText();
    string var_type = child[0]->getText();

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

void FileVarGenerator::init(DreamParser::VarDeclarationContext* ctx)
{
    if (ctx->children.size() == 7)
        init_with_7_part(ctx);
    else if (ctx->children.size() == 6)
        init_with_6_part(ctx);
    else if (ctx->children.size() == 5)
        init_with_5_part(ctx);
}

std::string FileVarGenerator::generate_code() const
{
    return (_is_mutable ? "const " : "") + _type + " " + _name + " = " + _value + ";\n";
}

std::string FileVarGenerator::generate_decl() const
{
    return static_cast<std::string>("extern ") + (_is_mutable ? "const " : "") + _type + " " + _name + ";\n";
}


[[nodiscard]] const std::string& FileVarGenerator::name() const
{
    return _name;
}

[[nodiscard]] const std::string& FileVarGenerator::type() const
{
    return _type;
}

[[nodiscard]] const std::string& FileVarGenerator::value() const
{
    return _value;
}

[[nodiscard]] bool FileVarGenerator::is_mutable() const
{
    return _is_mutable;
}

[[nodiscard]] bool FileVarGenerator::is_nullable() const
{
    return _is_nullable;
}
