//
// Created by napbad on 9/23/24.
//

#include "response_util.h"

#include "file_util.h"

void response_util::report_error(const std::string &msg, const std::string &file_name, const int line) {
    file_util::print(std::cout, "===========ERROR=============\n", file_util::FileColor::YELLOW);
    print(std::cout, msg, file_util::FileColor::RED);
    print(std::cout, "Error in file " + file_name + " at line " + std::to_string(line) + "\n",
                     file_util::FileColor::WHITE);
    file_util::print(std::cout, "=============================\n", file_util::FileColor::YELLOW);
}
