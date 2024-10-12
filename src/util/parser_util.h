//
// Created by napbadsen on 24-10-9.
//

#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H

#include <string>
#include <vector>

#include "obj/Hierarchy.h"
#include "parse/DreamParser.h"
#include "runtime/gc/DataPool.h"

#define FUN_PARAM_TYPE_NAME std::string
#define FUN_PARAM_NAME std::string
#define FUN_PARAM_NULLABLE bool
#define FUN_PARAM_MUTABLE bool

#define FUN_PARAM_TYPE \
        std::tuple< \
            FUN_PARAM_TYPE_NAME, \
            FUN_PARAM_NAME, \
            FUN_PARAM_NULLABLE, \
            FUN_PARAM_MUTABLE \
        >

namespace parser_util
{
    std::vector<std::string> gen_data_pool_define(const std::string& name, DataPoolType type);

    bool find_nullable(Hierarchy* hierarchy, antlr4::tree::ParseTree* expr);

    bool parse_tree_is_null(antlr4::tree::ParseTree* expr);

    std::string convert_type_to_cpp(std::string& type_name);

    std::string convert_type_list_to_tuple(DreamParser::ReturnTypeContext* ctx);
}

#endif //PARSER_UTIL_H
