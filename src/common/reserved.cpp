#include "reserved.h"

#include <cmath>
#include <stdexcept>
#include <vector>

#include "enum.h"
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

Dval *add_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_STR || type2 == DVAL_STR) {
        std::string const str1 = val->get_string_value();
        std::string const str2 = val2->get_string_value();
        if (util::check::str_is_str(str1)) {
            if (util::check::str_is_str(str2)) {
                std::string const result = str1.substr(0, str1.size() - 2) + str2.substr(1, str2.size() - 1);
                return dval::dval_str(result, val->identifier(), val->val_mutable(), val->val_nullable());
            }
            std::string const result = str1.substr(0, str1.size() - 2) + str2 + "\"";
            return dval::dval_str(result, val->identifier(), val->val_mutable(), val->val_nullable());
        }

        std::string const result = "\"" + str1 + str2.substr(1, str2.size() - 1);
        return dval::dval_str(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        float const result = val->get_float_value() + val2->get_float_value();
        return dval::dval_float(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() + val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() + val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() + val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() + val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) + static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for addition");
}

Dval *sub_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        float const result = val->get_float_value() - val2->get_float_value();
        return dval::dval_float(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() - val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() - val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() - val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() - val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) - static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for subtraction");
};

Dval *mul_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        float const result = val->get_float_value() * val2->get_float_value();
        return dval::dval_float(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() * val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() * val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() * val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() * val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) * static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for multiplication");
};

Dval *div_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (util::check::val_is_zero(val2)) {
        return dval::dval_err("Division by zero");
    }


    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        float const result = val->get_float_value() / val2->get_float_value();
        return dval::dval_float(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() / val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() / val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() / val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() / val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) / static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for division");
};

Dval *mod_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (util::check::val_is_zero(val2)) {
        return dval::dval_err("Modulo by zero");
    }


    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        float const result = std::fmod(val->get_float_value(), val2->get_float_value());
        return dval::dval_float(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() % val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() % val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() % val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() % val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) % static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for modulo operation");
};


Dval *lt_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() < val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() < val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() < val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) < static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) < static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) < static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for less than comparison");
};

Dval *gt_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() > val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() > val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() > val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) > static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) > static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) > static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for greater than comparison");
};

Dval *lte_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() <= val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() <= val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() <= val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) <= static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) <= static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) <= static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for less than or equal to comparison");
};

Dval *gte_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() >= val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() >= val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() >= val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) >= static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) >= static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) >= static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for greater than or equal to comparison");
};

Dval *eq_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_STR || type2 == DVAL_STR) {
        std::string const str1 = type1 == DVAL_STR ? val->string_value() : std::to_string(val->get_long_value());
        std::string const str2 = type2 == DVAL_STR ? val2->string_value() : std::to_string(val2->get_long_value());
        bool const result = str1 == str2;
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() == val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() == val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() == val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) == static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) == static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) == static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for equality comparison");
};

Dval *neq_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_STR || type2 == DVAL_STR) {
        std::string const str1 = type1 == DVAL_STR ? val->string_value() : std::to_string(val->get_long_value());
        std::string const str2 = type2 == DVAL_STR ? val2->string_value() : std::to_string(val2->get_long_value());
        bool const result = str1 != str2;
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        bool const result = val->get_float_value() != val2->get_float_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        bool const result = val->get_long_value() != val2->get_long_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        bool const result = val->get_int_value() != val2->get_int_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        bool const result = static_cast<long>(val->get_short_value()) != static_cast<long>(val2->get_short_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        bool const result = static_cast<long>(val->get_char_value()) != static_cast<long>(val2->get_char_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        bool const result = static_cast<long>(val->get_byte_value()) != static_cast<long>(val2->get_byte_value());
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for inequality comparison");
};

Dval *and_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();

    if (int const type2 = val2->type(); type1 == DVAL_BOOL || type2 == DVAL_BOOL) {
        bool const result = val->bool_value() || val2->bool_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for logical AND operation");
};

Dval *or_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }
    int const type1 = val->type();

    if (int const type2 = val2->type(); type1 == DVAL_BOOL || type2 == DVAL_BOOL) {
        bool const result = val->bool_value() || val2->bool_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for logical OR operation");
};

Dval *xor_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_BOOL || type2 == DVAL_BOOL) {
        bool const result = val->bool_value() != val2->bool_value();
        return dval::dval_bool(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() ^ val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() ^ val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() ^ val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() ^ val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = val->get_byte_value() ^ val2->get_byte_value();
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    throw std::runtime_error("Unsupported types for XOR operation");
};

Dval *lshift_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        return dval::dval_err("Unsupported types for left shift operation");
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() << val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() << val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() << val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() << val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) << static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    throw std::runtime_error("Unsupported types for left shift operation");
};

Dval *rshift_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();

    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        return dval::dval_err("Unsupported types for right shift operation");
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() >> val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() >> val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() >> val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() >> val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) >> static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }

    throw std::runtime_error("Unsupported types for right shift operation");
};

Dval *urshift_builtin_fun(const Denv *env, const std::initializer_list<Dval *> vals) {
    const Dval *val = new Dval();
    const Dval *val2 = new Dval();

    int count = 0;

    for (auto i: vals) {
        if (count == 0) {
            val = i;
            count++;
        } else if (count == 1) {
            val2 = i;
            count++;
        }
    }

    int const type1 = val->type();
    int const type2 = val2->type();


    if (type1 == DVAL_FLOAT || type2 == DVAL_FLOAT) {
        return dval::dval_err("Unsupported types for unsigned right shift operation");
    }
    if (type1 == DVAL_LONG || type2 == DVAL_LONG) {
        long const result = val->get_long_value() >> val2->get_long_value();
        return dval::dval_long(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_INT || type2 == DVAL_INT) {
        int const result = val->get_int_value() >> val2->get_int_value();
        return dval::dval_int(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_SHORT || type2 == DVAL_SHORT) {
        short const result = static_cast<short>(val->get_short_value() >> val2->get_short_value());
        return dval::dval_short(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_CHAR || type2 == DVAL_CHAR) {
        char const result = static_cast<char>(val->get_char_value() >> val2->get_char_value());
        return dval::dval_char(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    if (type1 == DVAL_BYTE || type2 == DVAL_BYTE) {
        std::byte const result = static_cast<std::byte>(
            static_cast<short>(val->get_byte_value()) >> static_cast<short>(val2->get_byte_value()));
        return dval::dval_byte(result, val->identifier(), val->val_mutable(), val->val_nullable());
    }
    throw std::runtime_error("Unsupported types for unsigned right shift operation");
};

builtin add_builtin = add_builtin_fun;
builtin sub_builtin = sub_builtin_fun;
builtin mul_builtin = mul_builtin_fun;
builtin div_builtin = div_builtin_fun;
builtin mod_builtin = mod_builtin_fun;
builtin and_builtin = and_builtin_fun;
builtin eq_builtin = eq_builtin_fun;
builtin gt_builtin = gt_builtin_fun;
builtin gte_builtin = gte_builtin_fun;
builtin lt_builtin = lt_builtin_fun;
builtin lte_builtin = lte_builtin_fun;
builtin neq_builtin = neq_builtin_fun;
builtin or_builtin = or_builtin_fun;
builtin xor_builtin = xor_builtin_fun;
builtin lshift_builtin = lshift_builtin_fun;
builtin rshift_builtin = rshift_builtin_fun;
builtin urshift_builtin = urshift_builtin_fun;
