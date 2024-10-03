//
// Created by napbad on 9/18/24.
//

#include "string_util.h"

#include <numeric>
#include <regex>

#include "common/reserve.h"

using namespace std;

vector<string> string_util::split(const string &str, const char delimiter) {

    if (str.empty())
        return {};

    auto pos = str.find(delimiter);
    string _str = str;
    vector<string> result;

    while (pos != string::npos) {
        result.push_back(_str.substr(0, pos));
        _str = _str.substr(pos + 1);
        pos = _str.find(delimiter);
    }

    result.push_back(_str);

    return result;
}

bool string_util::str_is_num(const std::string &s) {
    for (char const &ch: s) {
        if (!std::isdigit(ch)) return false;
    }
    return !s.empty();
}


bool string_util::str_is_op(const std::string &oper) {
    for (const auto &op: ops) {
        if (op == oper) {
            return true;
        }
    }

    return false;
}

bool string_util::str_is_bool(const std::string &string) {
    return string == D_TRUE || string == D_FALSE;
}

bool string_util::str_is_str(const std::string &string) {
    return string.size() >= 2 && string[0] == '"' && string[string.size() - 1] == '"';
}

bool string_util::str_is_float(const std::string &string) {
    const std::regex floatRegex("^[-+]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([eE][-+]?[0-9]+)?$");

    return std::regex_match(string, floatRegex);
}

bool string_util::str_is_char(const std::string &string, char c) {
    if (string.size() == 1 && string.at(0) == c) {
        return true;
    }
    return false;
}

bool string_util::str_is_char(const std::string &string) {
    return string.size() == 3 && string.at(0) == '\'' && string.at(2) == '\'';
}

bool string_util::str_is_ident(const std::string &ident) {
    if (ident.empty()) {
        // Return false if the identifier is empty
        return false;
    }

    // Check if the first character is a letter or an underscore
    if (!std::isalpha(ident[0]) && ident[0] != '_') {
        return false;
    }

    // Check if the subsequent characters are letters, digits, or underscores
    for (size_t i = 1; i < ident.size(); ++i) {
        if (!std::isalnum(ident[i]) && ident[i] != '_') {
            return false;
        }
    }

    // If all checks pass, the identifier is valid
    return true;
}

bool string_util::str_is_only_ident(const std::string &ident) {
    return str_is_ident(ident)
           && !str_is_op(ident)
           && !str_is_bool(ident)
           && !str_is_str(ident)
           && !str_is_float(ident)
           && !str_is_char(ident);
}

std::string string_util::convert_parser_tree_to_string(antlr4::tree::ParseTree *tree) {
    string text;
    if (tree->children.empty()) {
        if (const string text_ = tree->getText(); text_.starts_with("string")) {
            return "std::" + tree->getText() + " ";
        }
        return tree->getText() + " ";
    }
    for (const auto child : tree->children) {
        text += convert_parser_tree_to_string(child);
    }
    return  text;
}

std::string string_util::get_text_from_vector(const std::vector<std::string>& vec)
{
    string res;

    for (const auto& str : vec)
    {
        res += " ";
        res += str;
    }

    return res;
}

std::string string_util::get_lines_from_vector(const std::vector<std::string>& vector)
{
    string res;

    for (const auto& str : vector)
    {
        res += str;
        res += "\n";
    }

    return res;
}

bool string_util::str_is_common_type(const std::string& string)
{
    for (const auto &type : common_types)
    {

    }
}


std::string string_util::convert_type_to_cpp(std::string& type_name)
{
    if (type_name == D_STRING)
        return "std::string";

    if (type_name == D_STRING_ARR)
        return "std::string[]";

    if (type_name.starts_with("u"))
        type_name.replace(0, 1, "unsigned ");
    return type_name;
}