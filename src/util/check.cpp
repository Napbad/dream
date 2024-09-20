//
// Created by napbad on 9/7/24.
//

#include <regex>

#include "check.h"

#include "common/dval_enum.h"
#include "common/reserved.h"

bool util::check::str_is_num(const std::string &s) {
    for (char const &ch: s) {
        if (!std::isdigit(ch)) return false;
    }
    return !s.empty();
}

bool util::check::val_is_zero(const Dval *val) {
    switch (val->type()) {
        case DVAL_INT: return val->int_value() == 0;
        case DVAL_LONG: return val->long_value() == 0;
        case DVAL_FLOAT: return val->float_value() == 0;
        case DVAL_CHAR: return val->char_value() == 0;
        case DVAL_SHORT: return val->short_value() == 0;

        case DVAL_BYTE:
        default: return false;
    }
}

bool util::check::is_val(const Dval *val) {
    return val != nullptr &&
           (val->type() == DVAL_INT
            || val->type() == DVAL_LONG
            || val->type() == DVAL_FLOAT
            || val->type() == DVAL_CHAR
            || val->type() == DVAL_SHORT
            || val->type() == DVAL_BYTE);
}

bool util::check::str_is_op(const std::string &oper) {

    for (const auto& op : ops) {
        if (op == oper) {
            return true;
        }
    }

    return false;
}

bool util::check::str_is_bool(const std::string &string) {
    return string == D_TRUE || string == D_FALSE;
}

bool util::check::str_is_str(const std::string &string) {
    return string.size() >= 2 && string[0] == '"' && string[string.size() - 1] == '"';
}

bool util::check::str_is_float(const std::string &string) {
    const std::regex floatRegex("^[-+]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([eE][-+]?[0-9]+)?$");

    return std::regex_match(string, floatRegex);
}

bool util::check::str_is_char(const std::string &string, char c) {

    if (string.size() == 1 && string.at(0) == c) {
        return true;
    }
    return false;
}

bool util::check::str_is_char(const std::string &string) {
    return string.size() == 3 && string.at(0) == '\'' && string.at(2) == '\'';
}
