//
// Created by napbad on 10/24/24.
//

//
// Created by napbad on 9/18/24.
//

#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#define OUTPUT_DIR "./build/"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define SPACE_STR std::string("")

// Report a warning message with a specific color (default yellow)
#define REPORT_WARNING(msg, file, line)                                                                                \
    util::warn_print(std::cout, (SPACE_STR + (msg) + " \nat file: " file + ":" + std::to_string(line) + "\n"),    \
                          util::FileColor::YELLOW)

// Report an error message with a specific color (default red)
#define REPORT_ERROR(msg, file, line)                                                                                  \
    util::err_print(std::cout, (SPACE_STR + (msg) + " \nat file: " file + ":" + std::to_string(line) + "\n"),     \
                         util::FileColor::RED)

// Report a debug message with a specific color (default white)
#define REPORT_DEBUG(msg, file, line)                                                                                  \
    util::dbg_print(std::cout, (SPACE_STR + (msg) + " \nat file: " file + ":" + std::to_string(line) + "\n"),     \
                         util::FileColor::WHITE)

// Report a success message with a specific color (default green)
#define REPORT_SUCCESS(msg, file, line)                                                                                \
    util::print(std::cout, (SPACE_STR + (msg) + " \nat file: " file + ":" + std::to_string(line) + "\n"),         \
                     util::FileColor::GREEN)

// Report a warning message with a specific color (default yellow)
#define LOG_WARNING(msg)                                                                                \
    util::warn_print(std::cout, (SPACE_STR + (msg) + "\n"),    \
                          util::FileColor::YELLOW)

// Report an error message with a specific color (default red)
#define LOG_ERROR(msg)                                                                                  \
    util::err_print(std::cout, (SPACE_STR + (msg) + "\n"),     \
                         util::FileColor::RED)

// Report a debug message with a specific color (default white)
#define LOG_DEBUG(msg)                                                                                  \
    util::dbg_print(std::cout, (SPACE_STR + (msg) + "\n"),     \
                         util::FileColor::WHITE)

// Report a success message with a specific color (default green)
#define LOG_SUCCESS(msg)                                                                                \
    util::print(std::cout, (SPACE_STR + (msg) + "\n"),         \
                     util::FileColor::GREEN)

// Platform-specific color setting functions
#ifdef _WIN32
#include <windows.h>
inline void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
inline void setColor(const char *ansiCode)
{
    std::cout << ansiCode;
}
#endif

namespace dap::util
{
/**
 * @enum FileColor
 * @brief Enum for file colors.
 */
enum class FileColor
{
    GREEN,
    WHITE,
    RED,
    YELLOW,
    BLUE,
    BLACK,
    MAGENTA,
    CYAN,
    BRIGHT_GREEN,
    BRIGHT_WHITE,
    BRIGHT_RED,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN
};

/**
 * @brief Converts FileColor to Windows console color or ANSI color code.
 * @param color The FileColor enum value.
 * @return On Windows, returns an integer color code; on other platforms,
 * returns an ANSI color code.
 */
#ifdef _WIN32
inline int colorCode(FileColor color);
#else
std::string colorCode(FileColor color);
#endif

/**
 * @brief Prints a message with a specified color.
 * @param stream Output stream.
 * @param message Message to print.
 * @param color Color of the message.
 */
void print(std::ostream &stream, const std::string &message, FileColor color);

/**
 * @brief Prints a debug message with a specified color.
 * @param stream Output stream.
 * @param message Message to print.
 * @param color Color of the message.
 */
void dbg_print(std::ostream &stream, const std::string &message, FileColor color);

/**
 * @brief Prints a warning message with a specified color.
 * @param stream Output stream.
 * @param message Message to print.
 * @param color Color of the message.
 */
void warn_print(std::ostream &stream, const std::string &message, FileColor color);

/**
 * @brief Prints an error message with a specified color.
 * @param stream Output stream.
 * @param message Message to print.
 * @param color Color of the message.
 */
void err_print(std::ostream &stream, const std::string &message, FileColor color);

/**
 * @brief Prints a debug message with default color (WHITE).
 * @param stream Output stream.
 * @param message Message to print.
 */
void dbg_print(std::ostream &stream, const std::string &message);

/**
 * @brief Prints a warning message with default color (WHITE).
 * @param stream Output stream.
 * @param message Message to print.
 */
void warn_print(std::ostream &stream, const std::string &message);

/**
 * @brief Prints an error message with default color (WHITE).
 * @param stream Output stream.
 * @param message Message to print.
 */
void err_print(std::ostream &stream, const std::string &message);

/**
 * @brief Reads a line from an opened file.
 * @param opened_file Pointer to the opened file.
 * @param file_name Name of the file.
 * @param line Line number.
 * @return The read line.
 */
std::string read_line(std::fstream *opened_file, std::string &file_name, int line);

/**
 * @brief Creates a new file and returns a file stream.
 * @param file_name Name of the file to create.
 * @return A file stream object.
 */
std::fstream create_file(const std::string &file_name);

/**
 * @brief Creates a directory for a package.
 * @param pkg_dir_name Name of the package directory to create.
 */
void create_package_dir(std::string pkg_dir_name);

/**
 * @brief Converts a package name to a path.
 * @param pkg_name Name of the package.
 * @return The corresponding path.
 */
std::string convert_pkg_to_path(const std::string &pkg_name);

/**
 * @brief Copies a directory recursively.
 * @param source_dir Source directory path.
 * @param destination_dir Destination directory path.
 */
void copy_directory(const std::string &source_dir, const std::string &destination_dir);

/**
 * @brief Collects all files recursively in a directory.
 * @param dir_path Directory path.
 * @param files Reference to a vector to store the collected files.
 */
void collect_files_recursive(const std::string &dir_path, std::vector<std::string> &files);

/**
 * @brief Gets all files in a directory.
 * @param dir_path Directory path.
 * @return A vector of file paths.
 */
std::vector<std::string> get_all_files_in_dir(const std::string &dir_path);

/**
 * @brief Gets the content of a file.
 * @param file Path to the file.
 * @return A vector of strings representing the lines of the file.
 */
std::vector<std::string> get_file_content(const std::string &file);

/**
 * @brief Deletes a directory recursively.
 * @param dir_path Directory path.
 */
void delete_directory(const std::string &dir_path);

#ifdef _WIN32
const std::string DEV_NULL = "NUL"; // Windows null device
#else
const std::string DEV_NULL = "/dev/null"; // Unix-like null device
#endif

// Recursively scan the directory to find all .cpp files
std::vector<std::filesystem::path> find_cpp_files(const std::filesystem::path &directory);

// Check if clang-format is installed on the system
bool is_clang_format_available();

bool create_dir(const std::string &path);
} // namespace util

#endif // FILE_UTIL_H