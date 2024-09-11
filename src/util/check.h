//
// Created by napbad on 9/7/24.
//

#ifndef CHECK_H
#define CHECK_H
#include <string>

#include "model/val.h"


namespace util::check {
    bool strIsNum(const std::string &s);

    bool valIsZero(const Dval *val);

    bool isVal(const Dval *val);
}


#endif //CHECK_H
