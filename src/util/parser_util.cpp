//
// Created by napbadsen on 24-10-9.
//

#include "parser_util.h"

#include "response_util.h"
#include "string_util.h"
#include "common/reserve.h"
#include "obj/Global.h"

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
    for (const auto child : expr->children)
    {
        if (!child->children.empty())
        {
            result = find_nullable(hierarchy, child) && result;
        }

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
                "Cannot find variable: " + child->getText() + " in hierarchy: " + hierarchy->get_full_hierarchy_name()
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
