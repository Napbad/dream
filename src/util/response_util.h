//
// Created by napbad on 9/23/24.
//

// \brief this file is used to handler the response of the compiler

#ifndef RESPONSE_UTIL_H
#define RESPONSE_UTIL_H
#include <string>

namespace response_util {
    void report_error(const std::string &msg, const std::string &file_name, int line);
    void report_error(const std::string& msg);
}

#endif //RESPONSE_UTIL_H
