//
// Created by napbad on 10/20/24.
//

#include "../reserve/d_define.h"

#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H

#ifdef DEBUG_MODE

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

// Platform-specific color setting functions
#ifdef _WIN32
#include <windows.h>
inline void dbg_set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
inline void dbg_set_color(const char* ansiCode)
{
    std::cout << ansiCode;
}
#endif

namespace dbg_util
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
     * @return On Windows, returns an integer color code; on other platforms, returns an ANSI color code.
     */
#ifdef _WIN32
    inline int dbg_colorCode(FileColor color);
#else
    std::string dbg_colorCode(FileColor color);
#endif


    /**
     * @brief Prints a message with a specified color.
     * @param stream Output stream.
     * @param message Message to print.
     * @param color Color of the message.
     */
    void print(std::ostream& stream, const std::string& message, FileColor color);

    /**
     * @brief Prints a debug message with a specified color.
     * @param stream Output stream.
     * @param message Message to print.
     * @param color Color of the message.
     */
    void dbg_print(std::ostream& stream, const std::string& message, FileColor color);

    /**
 * @brief Prints a debug message with default color (WHITE).
 * @param stream Output stream.
 * @param message Message to print.
 */
    void dbg_print(std::ostream& stream, const std::string& message);
}
#endif


#endif //DEBUG_UTIL_H
