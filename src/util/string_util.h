//
// Created by napbad on 9/18/24.
//

#ifndef STRING_UTIL_H
#define STRING_UTIL_H
#include <ranges>
#include <string>
#include <vector>
#include <tree/ParseTree.h>

#include "parser_util.h"

namespace string_util {
    std::vector<std::string> split(const std::string& str, char delimiter);

    std::string join(const std::vector<std::string>& strs, char delimiter);

    bool str_is_num(const std::string &s);

    bool str_is_op(const std::string & string);

    bool str_is_bool(const std::string & string);

    bool str_is_str(const std::string & string);

    bool str_is_float(const std::string & string);

    bool str_is_char(const std::string & string, char c);

    bool str_is_char(const std::string & string);

    bool str_is_ident(const std::string & ident);

    bool str_is_only_ident(const std::string & ident);

    std::string convert_parser_tree_to_string(antlr4::tree::ParseTree *tree);

    std::string get_text_from_vector(const std::vector<std::string> &vec);

    std::string get_str_from_param_vector(const std::vector<FUN_PARAM_TYPE>& vector, std::string delimiter);

    std::string get_lines_from_vector(const std::vector<std::string>& vector);

    bool str_is_common_type(const std::string& string);


    void replace_all(std::string &str, const std::string &from, const std::string &to);
}

#endif //STRING_UTIL_H
