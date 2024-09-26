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
        WHITE, // Renamed WRITE to WHITE for clarity
        RED,
        YELLOW,
        BLUE
    };

    // Utility function to convert FileColor to Windows console color or ANSI color code
#ifdef _WIN32
    inline int colorCode(FileColor color) {
        static std::map<FileColor, int> winColors = {
            {FileColor::GREEN, 2},
            {FileColor::WHITE, 7},
            {FileColor::RED, 4},
            {FileColor::YELLOW, 6},
            {FileColor::BLUE, 1}
        };
        static std::map<FileColor, const char*> ansiColors = {
            {FileColor::GREEN, "\x1b[32m"},
            {FileColor::WHITE, "\x1b[37m"},
            {FileColor::RED, "\x1b[31m"},
            {FileColor::YELLOW, "\x1b[33m"},
            {FileColor::BLUE, "\x1b[34m"}
        };

        if (const char* ansi = ansiColors.find(color)->second) {
            return *ansi;
        }
        return winColors.at(color);

        return -1; // ANSI colors are handled via string return
    }
#else
    inline std::string colorCode(FileColor color) {
        static std::map<FileColor, const char*> ansiColors = {
            {FileColor::GREEN, "\x1b[32m"},
            {FileColor::WHITE, "\x1b[37m"},
            {FileColor::RED, "\x1b[31m"},
            {FileColor::YELLOW, "\x1b[33m"},
            {FileColor::BLUE, "\x1b[34m"}
        };

        if (const char* ansi = ansiColors.find(color)->second) {
            return ansi;
        }

        return "\x1b[34m";
    }
#endif
    std::fstream create_file(const std::string &file_name);

    void create_package_dir(std::string pkg_dir_name);

    std::string convert_pkg_to_path(const std::string &pkg_name);

    std::string convert_type_to_cpp(std::string &type_name);

    void insert_front_of_file(std::fstream *file, const std::string &content, const std::string& file_name);

    std::string read_line(std::fstream *opened_file, std::string &file_name, int line);

    // For Windows systems
    inline void print(std::ostream &stream, const std::string &message, FileColor color) {
        if (stream.rdbuf() == std::cout.rdbuf()) {
#ifdef _WIN32
            setColor(colorCode(color));
#else
            std::cout << colorCode(color);
#endif
        }
        stream << message;
        if (stream.rdbuf() == std::cout.rdbuf()) {
#ifdef _WIN32
            setColor(color); // Default white
#else
            setColor(colorCode(color).c_str()); // Reset color
#endif
        }
    }
}


#endif //FILE_UTIL_H
