//
// Created by napbad on 9/18/24.
//

#include "file_util.h"

#include <fstream>
#include <filesystem>

#include "common/reserve.h"

using namespace std;

std::fstream file_util::create_file(const std::string &file_name) {
    filesystem::path _path(file_name);

    filesystem::path _parent_path = _path.parent_path();

    create_directories(_parent_path);

    if (!exists(_parent_path)) {
        throw std::runtime_error("Failed to create directory: " + _parent_path.string());
    }

    std::fstream file_stream(file_name, std::ios::out | std::ios::in);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Failed to create file: " + file_name);
    }

    return file_stream;
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
    } catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to create directory: " + pkg_dir_name + ". Error: " + e.what());
    }
}

std::string file_util::convert_pkg_to_path(const std::string &pkg_name) {
    string res = pkg_name;

    for (auto &c: res) {
        if (c == '.') {
            c = '/';
        }
    }

    res = OUTPUT_DIR + res + "/";

    return res;
}

std::string file_util::convert_type_to_cpp(std::string &type_name) {
    if (type_name == D_STRING) {
        return "std::string";
    }

    if (type_name == D_STRING_ARR) {
        return "std::string[]";
    }

    if (type_name.starts_with("u")) {
        type_name.replace(0, 1, "unsigned ");
    }
    return type_name;
}


std::string file_util::read_line(std::fstream *opened_file, string &file_name, const int line) {
    if (opened_file == nullptr || !opened_file->is_open()) {
        return ""; // Return an empty string if the opened_file pointer is null or the opened_file is not open
    }

    opened_file->close();

    int lines, i = 0;
    string temp;
    fstream file;
    file.open(file_name, ios::in);

    while (getline(file, temp, '\n') && i < line - 1) {
        i++;
    }
    file.close();

    opened_file->open(file_name, std::ios::in | std::ios::out | std::ios::ate | std::ios::app);
    return temp;
}
