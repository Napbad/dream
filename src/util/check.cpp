//
// Created by napbad on 9/7/24.
//

#include "check.h"

bool strIsNum(const std::string &s) {
    for (char const &ch : s) {
        if (!std::isdigit(ch)) return false;
    }
    return !s.empty();
}
