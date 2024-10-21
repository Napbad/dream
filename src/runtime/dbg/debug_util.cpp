//
// Created by napbad on 10/20/24.
//

#include "debug_util.h"


void dbg_util::dbg_print(std::ostream& stream, const std::string& message, FileColor color)
{
    print(stream, "DEBUG: ", FileColor::BRIGHT_YELLOW);
    print(stream, message, color);
}

void dbg_util::dbg_print(std::ostream& stream, const std::string& message)
{
    print(stream, "DEBUG: ", FileColor::BRIGHT_YELLOW);
    print(stream, message, FileColor::WHITE);
}

void dbg_util::print(std::ostream& stream, const std::string& message, FileColor color)
{
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        dbgSetColor(colorCode(color));
#else
        std::cout << dbg_colorCode(color);
#endif
    }
    stream << message;
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        setColor(color); // Default white
#else
        dbg_set_color(dbg_colorCode(FileColor::BLACK).c_str()); // Reset color
#endif
    }

    stream.flush();
}

#ifdef _WIN32
inline int file_util::colorCode(FileColor color) {
    switch (color) {
        case FileColor::GREEN: return FOREGROUND_GREEN;
        case FileColor::WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::RED: return FOREGROUND_RED;
        case FileColor::YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN;
        case FileColor::BLUE: return FOREGROUND_BLUE;
        case FileColor::BLACK: return 0;
        case FileColor::MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE;
        case FileColor::CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::BRIGHT_GREEN: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_RED: return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_BLUE: return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        default: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
}
#else
std::string dbg_util::dbg_colorCode(FileColor color)
{
    switch (color)
    {
    case FileColor::GREEN: return "\033[32m";
    case FileColor::WHITE: return "\033[37m";
    case FileColor::RED: return "\033[31m";
    case FileColor::YELLOW: return "\033[33m";
    case FileColor::BLUE: return "\033[34m";
    case FileColor::BLACK: return "\033[30m";
    case FileColor::MAGENTA: return "\033[35m";
    case FileColor::CYAN: return "\033[36m";
    case FileColor::BRIGHT_GREEN: return "\033[92m";
    case FileColor::BRIGHT_WHITE: return "\033[97m";
    case FileColor::BRIGHT_RED: return "\033[91m";
    case FileColor::BRIGHT_YELLOW: return "\033[93m";
    case FileColor::BRIGHT_BLUE: return "\033[94m";
    case FileColor::BRIGHT_MAGENTA: return "\033[95m";
    case FileColor::BRIGHT_CYAN: return "\033[96m";
    default: return "\033[37m";
    }
}

#endif
