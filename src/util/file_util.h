//
// Created by napbad on 9/18/24.
//

#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#define OUTPUT_DIR "../build/"

#include <string>

namespace file_util {
    void create_file(const std::string &file_name);

    void create_package_dir(std::string pkg_dir_name);

    std::string convert_pkg_file_to_path(const std::string &pkg_name);
}


#endif //FILE_UTIL_H
