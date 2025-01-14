

#ifndef LOG_UTIL_H
#define LOG_UTIL_H

#include <string>

#include "common/define_d.h"
namespace dap::util
{
/**
 * @enum FileColor
 * @brief Enum for file colors.
 */
enum class FileColor {
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

#ifdef D_DEBUG

void err(const std::string &msg, const std::string &file, int line);

void warn(const std::string &msg, const std::string &file, int line);

void log(const std::string &msg, const std::string &file, int line);

void printHelpMsg();

#else

void err(const std::string &msg);

void warn(const std::string &msg);

void log();

#endif
} // namespace dap::util
#endif