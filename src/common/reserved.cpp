#include "reserved.h"

#include <cmath>
#include <stdexcept>
#include <vector>

#include "dval_enum.h"
#include "./obj/val.h"
#include "util/check.h"


std::vector<std::string> ops = {
    D_NOT,
    D_MUL, D_DIV, D_MOD,
    D_ADD, D_SUB,
    D_LT, D_GT, D_LTE, D_GTE,
    D_EQ, D_NEQ,
    D_AND, D_OR,
    D_XOR,
    D_ASSIGN,
    D_PLUS_ASSIGN,
    D_MINUS_ASSIGN,
    D_MUL_ASSIGN,
    D_DIV_ASSIGN,
    D_MOD_ASSIGN
};

std::vector<char> ops_c = {
    D_CHAR_MUL, D_CHAR_DIV, D_CHAR_MOD,
    D_CHAR_ADD, D_CHAR_SUB,
    D_CHAR_LT, D_CHAR_GT,
    D_CHAR_XOR,
    D_CHAR_ASSIGN,
};

