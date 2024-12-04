//
// Created by napbad on 9/18/24.
//

#include "string_util.h"

#include <numeric>
#include <regex>
#include <utility>

#include "../common/reserve.h"
#include <bits/chrono.h>
#include <cstring>

using namespace std;

namespace dap::util
{
vector<string> split(const string &str, const char delimiter)
{
    if (str.empty())
        return {};

    auto pos = str.find(delimiter);
    string _str = str;
    vector<string> result;

    while (pos != string::npos)
    {
        result.push_back(_str.substr(0, pos));
        _str = _str.substr(pos + 1);
        pos = _str.find(delimiter);
    }

    result.push_back(_str);

    return result;
}

bool str_is_num(const std::string &s)
{
    for (char const &ch : s)
    {
        if (!std::isdigit(ch))
            return false;
    }
    return !s.empty();
}

bool str_is_op(const std::string &oper)
{
    for (const auto &op : ops)
    {
        if (op == oper)
        {
            return true;
        }
    }

    return false;
}

bool str_is_bool(const std::string &string)
{
    return string == D_TRUE || string == D_FALSE;
}

bool str_is_str(const std::string &string)
{
    return string.size() >= 2 && string[0] == '"' && string[string.size() - 1] == '"';
}

bool str_is_float(const std::string &string)
{
    const std::regex floatRegex("^[-+]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([eE][-+]?[0-9]+)?$");

    return std::regex_match(string, floatRegex);
}

bool str_is_char(const std::string &string, char c)
{
    if (string.size() == 1 && string.at(0) == c)
    {
        return true;
    }
    return false;
}

bool str_is_char(const std::string &string)
{
    return string.size() == 3 && string.at(0) == '\'' && string.at(2) == '\'';
}

bool str_is_ident(const std::string &ident)
{
    if (ident.empty())
    {
        // Return false if the identifier is empty
        return false;
    }

    // Check if the first character is a letter or an underscore
    if (!std::isalpha(ident[0]) && ident[0] != '_')
    {
        return false;
    }

    // Check if the subsequent characters are letters, digits, or underscores
    for (size_t i = 1; i < ident.size(); ++i)
    {
        if (!std::isalnum(ident[i]) && ident[i] != '_')
        {
            return false;
        }
    }

    // If all checks pass, the identifier is valid
    return true;
}

bool str_is_only_ident(const std::string &ident)
{
    return str_is_ident(ident) && !str_is_op(ident) && !str_is_bool(ident) && !str_is_str(ident) &&
           !str_is_float(ident) && !str_is_char(ident);
}

std::string get_text_from_vector(const std::vector<std::string> &vec)
{
    string res;

    for (int i = 0; i < vec.size(); i++)
    {
        res += vec[i];
        res += ((i == vec.size() - 1) ? "" : " ");
    }

    return res;
}

std::string getStrFromVec(const std::vector<std::string> &vec, const std::string &delimiter)
{
    std::string res;
    for (auto i = 0; i < vec.size(); i++)
    {
        res.append(vec[i]);
        res.append(i == vec.size() - 1 ? "" : delimiter);
    }
    return res;
}

std::string get_str_from_param_vector(
    const std::vector<std::tuple<std::string, std::string, bool, bool>> &vector, const std::string &delimiter)
{
    string res;

    for (auto i = 0; i < vector.size(); i++)
    {
        auto [type, name, nullable, mutable_] = vector.at(i);
        if (!str_is_common_cpp_type(type))
        {
            type = "DataNode<" + type + ">";
        }
        res.append(mutable_ ? "const " : " ").append(type).append(" ").append(name);

        res += (i == (vector.size() - 1) ? "" : delimiter);
    }

    return res;
}

std::string get_lines_from_vector(const std::vector<std::string> &vector)
{
    string res;

    for (const auto &str : vector)
    {
        res += str;
        res += "\n";
    }

    return res;
}

bool str_is_common_type(const std::string &type)
{
    for (const auto &type_d : common_type_map)
    {
        if (type == type_d.first)
            return true;
    }

    return false;
}

bool str_is_common_cpp_type(const std::string &type)
{
    for (const auto &type_d : common_type_map)
    {
        if (type == type_d.first)
            return true;
    }

    return false;
}

bool str_val_is_common_type(const std::string &string)
{
    return str_is_bool(string) || str_is_char(string) || str_is_float(string) || str_is_num(string) ||
           str_is_str(string);
}

void replace_all(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while (true)
    {
        start_pos = str.find(from, start_pos);
        if (start_pos == std::string::npos)
            break;
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

std::string gen_unique_name()
{
    auto timestamp = std::chrono::system_clock::now().time_since_epoch().count();
    auto random_num = random();

    std::stringstream ss;
    ss << timestamp << "_" << random_num;

    return ss.str();
}

void replace_all_without_str(std::string &str, const char *from, const char *to)
{
    bool in_str = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '"')
            in_str = !in_str;
        if (in_str)
            continue;
        if (str.substr(i, strlen(from)) == from)
        {
            str.replace(i, strlen(from), to);
        }
    }
}

bool find_expect_str(std::string value, const std::string &basic_string)
{
    bool is_in_str = false;
    for (int i = 0; i < value.size(); i++)
    {
        if (value.at(i) == '"')
            is_in_str = !is_in_str;
        if (is_in_str)
            continue;
        if (basic_string.starts_with(value.at(i)))
        {
            if (value.substr(i, basic_string.size()) == basic_string)
            {
                return true;
            }
        }
    }
    return false;
}
}