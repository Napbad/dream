//
// Created by napbad on 9/18/24.
//

#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#define OUTPUT_DIR "../build/"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "obj/Hierarchy.h"

// Platform-specific color setting functions
#ifdef _WIN32
#include <windows.h>
inline void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
inline void setColor(const char *ansiCode) {
    std::cout << ansiCode;
}
#endif


namespace file_util {

    // Define a scoped enum for file colors
    enum class FileColor {
        GREEN,
        WHITE,
        RED,
        YELLOW,
        BLUE,
        BLACK
    };

    // Utility function to convert FileColor to Windows console color or ANSI color code
#ifdef _WIN32
    inline int colorCode(FileColor color);
#else
    std::string colorCode(FileColor color);
#endif
    std::fstream create_file(const std::string &file_name);

    void create_package_dir(std::string pkg_dir_name);

    std::string convert_pkg_to_path(const std::string &pkg_name);


    void insert_front_of_file(std::fstream *file, const std::string &content, const std::string& file_name);

    std::string read_line(std::fstream *opened_file, std::string &file_name, int line);

    void print(std::ostream &stream, const std::string &message, FileColor color);

    void copy_directory(const std::string &source_dir, const std::string &destination_dir);

    Hierarchy* get_package_hierarchy(const std::string& package_name);

    void collect_files_recursive(const std::string& dir_path, std::vector<std::string>& files);

    std::vector<std::string> get_all_files_in_dir(const std::string& dir_path);

    std::vector<std::string> get_file_content(const std::string& file);

    void delete_directory(const std::string& dir_path);
}


#endif //FILE_UTIL_H
