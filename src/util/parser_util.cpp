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

std::vector<std::string> parser_util::gen_data_pool_define(const std::string& name, const DataPoolType type)
{
    return {
        "DataPool<" + name + ">* datapool_" + name +
        " = new DataPool(DataPoolType::" + (type == DataPoolType::INPUT ? "INPUT" : "OWN") + ", \"" + name + "\");"
    };
}

// TODO support Ternary symbol
bool parser_util::find_nullable(Hierarchy* hierarchy, antlr4::tree::ParseTree* expr)
{
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

    if (type_name.starts_with("u"))
        type_name.replace(0, 1, "unsigned ");

    return type_name;
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
