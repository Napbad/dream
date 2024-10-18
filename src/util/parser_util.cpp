//
// Created by napbadsen on 24-10-9.
//

#include "parser_util.h"

#include "file_util.h"
#include "response_util.h"
#include "string_util.h"
#include "common/reserve.h"
#include "obj/Global.h"
#include "common/dream_define.h"

using namespace std;

// TODO support Ternary symbol
bool parser_util::find_nullable(Hierarchy* hierarchy, antlr4::tree::ParseTree* expr)
{
    if (expr == nullptr)
        return true;

    if (expr->getText().starts_with("new"))
        return false;

    bool result = true;

    if (global_flag_is_debug) // if debug mode
    {
        std::string expr_str = string_util::convert_parser_tree_to_string(expr);
        dbg_print(cout, "find_nullable: " + expr_str
                  + "\n\tunder hierarchy: "
                  + hierarchy->get_full_hierarchy_name() + "\n",
                  file_util::FileColor::WHITE);
    }

    for (const auto child : expr->children)
    {
        // if child has children, then it is not a leaf node, so we need to check its children
        if (!child->children.empty())
        {
            result = find_nullable(hierarchy, child) && result;
        }

        // if child is a common type, then it must not be null
        if (string_util::str_val_is_common_type(child->getText()))
        {
            return false;
        }

        // if child is an identifier, then we need to check its value
        if (string_util::str_is_only_ident(child->getText()))
        {
            const Hierarchy* tmp = hierarchy;
            const string val_name = tmp->get_full_hierarchy_name() + "." + child->getText();

            if (global->is_var_exists_in_nullable_list(val_name))
                return result && !global->is_var_nullable(val_name);

            while (tmp->parent() != nullptr)
            {
                tmp = tmp->parent();
                if (global->is_var_exists_in_nullable_list(val_name))
                    return result && !global->is_var_nullable(val_name);
            }

            response_util::report_error(
                "Cannot find variable: "
                + child->getText() +
                " in hierarchy: "
                + hierarchy->get_full_hierarchy_name() +
                "\n"
            );

            return false;
        }
    }

    return result;
}

bool parser_util::parse_tree_is_null(antlr4::tree::ParseTree* expr)
{
    if (expr == nullptr)
        return true;
    return expr->getText().empty();
}


std::string parser_util::convert_type_to_cpp(std::string& type_name)
{
    if (type_name == D_STRING)
        return "std::string";

    if (type_name == D_STRING_ARR)
        return "std::string[]";


    // Type mapping from dream types to C++ types
    static const std::unordered_map<std::string, std::string> type_mapping = {
        {"byte", "uint8_t"},
        {"short", "short"},
        {"int", "int"},
        {"uint", "unsigned int"},
        {"ushort", "unsigned short"},
        {"long", "long"},
        {"ulong", "unsigned long"},
        {"llong", "long long"},
        {"ullong", "unsigned long long"},
        {"float", "float"},
        {"double", "double"},
        {"bool", "bool"},
        {"char", "char"},
        {"string", "std::string"},
        {"void", "void"}
    };


    if (const auto it = type_mapping.find(type_name); it != type_mapping.end())
    {
        return it->second;
    }

    return type_name + "*";
}

std::string parser_util::convert_type_list_to_tuple(DreamParser::ReturnTypeContext* ctx)
{
    if (ctx == nullptr)
        return CPP_VOID;

    const vector<antlr4::tree::ParseTree*> types = ctx->children;

    if (types.empty())
        return CPP_VOID;

    string res = "std::tuple<";

    for (auto i = 0; i < types.size(); i++)
    {
        string type_ = types[i]->getText();
        res.append(convert_type_to_cpp(type_))
           .append(i == types.size() - 1 ? ">" : ", ");
    }

    return res;
}

std::string parser_util::generate_default_value(std::string& type)
{
    // Map of supported types and their default values
    static const std::unordered_map<std::string, std::string> default_values = {
        {"int", "0"},
        {"float", "0.0"},
        {"double", "0.0"},
        {"std::string", "\"\""},
        {"char", "'\\0'"},
        {"bool", "false"},
        {"byte", "0"},
        {"short", "0"},
        {"long", "0L"},
        {"unsigned int", "0U"},
        {"unsigned short", "0U"},
        {"long long", "0LL"},
        {"unsigned long long", "0ULL"}
    };

    // Find the default value for the given type
    if (const auto it = default_values.find(type); it != default_values.end())
        return it->second;

    const string type_to_cpp = convert_type_to_cpp(type);
    if (const auto it = default_values.find(type_to_cpp); it != default_values.end())
        return it->second;

    // Return an empty string if the type is not supported
    return "new " + type + "()";
}
