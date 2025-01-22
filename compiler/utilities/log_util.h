

#ifndef LOG_UTIL_H
#define LOG_UTIL_H

#include <string>

#include "common/define_d.h"

// namespace dap::inter_gen
// {
// class InterGenContext;
// };

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
 * @return On Windows, returns an IntegerNode color code; on other platforms,
 * returns an ANSI colovoid err(const std::string &msg, inter_gen::InterGenContext *ctx, const std::string &file, int
 * line)r code.
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

void printHelpMsg();

#ifdef D_DEBUG

void logErr(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line);

void logWarn(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line);

void logInfo(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line);

#else

void logErr(const std::string &msg);

void logWarn(const std::string &msg);

void logInfo();

#endif
} // namespace dap::util
#endif