//
// Created by napbad on 9/18/24.
//

#include "file_util.h"

#include <fstream>
#include <filesystem>

#include "common/reserve.h"

using namespace std;

void file_util::create_file(const std::string &file_name) {

    string _file_name = file_name.substr(0, file_name.size() - 4);

    string::size_type pos = 0;
    pos =_file_name.find('.');
    const string split = "/";
    while (pos != string::npos) {
        _file_name.replace(pos, 1, split);

        pos =_file_name.find('.', pos + 1);
    }

    _file_name += ".cpp";

    if (std::ofstream file(OUTPUT_DIR + _file_name); !file.is_open()) {
        throw std::runtime_error("Failed to create file: " + _file_name);
    }
}

void file_util::create_package_dir(string pkg_dir_name) {
    string::size_type pos = 0;
    pos = pkg_dir_name.find('.');
    const string split = "/";
    while (pos != string::npos) {
        pkg_dir_name.replace(pos, 1, split);

        pos = pkg_dir_name.find('.', pos + 1);
    }

    pkg_dir_name = OUTPUT_DIR + pkg_dir_name;

    try {
        if (!std::filesystem::exists(pkg_dir_name)) {
            std::filesystem::create_directories(pkg_dir_name);
        }
    } catch (const std::filesystem::filesystem_error& e) {
        throw std::runtime_error("Failed to create directory: " + pkg_dir_name + ". Error: " + e.what());
    }
}

std::string file_util::convert_pkg_file_to_path(const std::string &pkg_name) {
    string res = pkg_name;
    bool is_file = false;
    if (pkg_name.find('.') != string::npos) {
        res = pkg_name.substr(0, pkg_name.size() - 4);
        is_file = true;
    }

    string::size_type pos = 0;
    pos = res.find('.');
    const string split = "/";
    while (pos != string::npos) {
        res.replace(pos, 1, split);

        pos = res.find('.', pos + 1);
    }

    res = OUTPUT_DIR + res + (is_file ? ".cpp":"");

    return res;
}
