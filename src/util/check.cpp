//
// Created by napbad on 9/7/24.
//

#include "check.h"

#include "model/enum.h"

bool util::check::strIsNum(const std::string &s) {
    for (char const &ch: s) {
        if (!std::isdigit(ch)) return false;
    }
    return !s.empty();
}

bool util::check::valIsZero(const Dval *val) {
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

bool util::check::isVal(const Dval *val) {
    return val != nullptr &&
           (val->type() == DVAL_INT
            || val->type() == DVAL_LONG
            || val->type() == DVAL_FLOAT
            || val->type() == DVAL_CHAR
            || val->type() == DVAL_SHORT
            || val->type() == DVAL_BYTE);
}
