//
// Created by napbad on 9/18/24.
//



#include <numeric>
#include <regex>
#include <utility>

#include <bits/chrono.h>
#include <cstring>
#include "string_util.h"
#include "src/core/common/reserve.h"
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

bool strIsNum(const std::string &s)
{
    for (char const &ch : s)
    {
        if (!std::isdigit(ch))
            return false;
    }
    return !s.empty();
}

bool strIsOp(const std::string &oper)
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

bool strIsBool(const std::string &string)
{
    return string == D_TRUE || string == D_FALSE;
}

bool strIsStr(const std::string &string)
{
    return string.size() >= 2 && string[0] == '"' && string[string.size() - 1] == '"';
}

bool strIsFloat(const std::string &string)
{
    const std::regex floatRegex("^[-+]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([eE][-+]?[0-9]+)?$");

    return std::regex_match(string, floatRegex);
}

bool strIsChar(const std::string &string, char c)
{
    if (string.size() == 1 && string.at(0) == c)
    {
        return true;
    }
    return false;
}

bool strIsChar(const std::string &string)
{
    return string.size() == 3 && string.at(0) == '\'' && string.at(2) == '\'';
}

bool strIsIdent(const std::string &ident)
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

bool strIsOnlyIdent(const std::string &ident)
{
    return strIsIdent(ident) && !strIsOp(ident) && !strIsBool(ident) && !strIsStr(ident) &&
           !strIsFloat(ident) && !strIsChar(ident);
}

std::string getTextFromVec(const std::vector<std::string> &vec)
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

std::string getLinesFromVec(const std::vector<std::string> &vector)
{
    string res;

    for (const auto &str : vector)
    {
        res += str;
        res += "\n";
    }

    return res;
}

bool strIsCommonType(const std::string &type)
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

bool strValIsCommonType(const std::string &string)
{
    return strIsBool(string) || strIsChar(string) || strIsFloat(string) || strIsNum(string) ||
           strIsStr(string);
}

void replaceAll(std::string &str, const std::string &from, const std::string &to)
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

std::string genUniqueName()
{
    auto timestamp = std::chrono::system_clock::now().time_since_epoch().count();
    auto random_num = random();

    std::stringstream ss;
    ss << timestamp << "_" << random_num;

    return ss.str();
}

void replaceAllWithoutStr(std::string &str, const char *from, const char *to)
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

bool findExpectStr(std::string value, const std::string &basic_string)
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