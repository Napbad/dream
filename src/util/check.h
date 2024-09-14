//
// Created by napbad on 9/7/24.
//

#ifndef CHECK_H
#define CHECK_H
#include <string>

#include "model/val.h"


namespace util::check {
    bool str_is_num(const std::string &s);

    bool val_is_zero(const Dval *val);

    bool is_val(const Dval *val);

    bool str_is_op(const std::string & string);

    bool str_is_bool(const std::string & string);

    bool str_is_str(const std::string & string);

    bool str_is_float(const std::string & string);

    bool str_is_char(const std::string & string, char c);
}


#endif //CHECK_H
