#include <iostream>

#include "inter_gen/codeGen_inter.h"
#include "log_util.h"

namespace dap::util
{

using std::cerr;
using std::cout;
using std::endl;

void printHelpMsg()
{
    cout << endl;
    cout << "Usage: "
         << " [-h] [-d <directory>] [-D] [-i] [-e] [-o <output_directory>] [-n <executable_name>]" << endl;
    cout << "  -h, --help            Show this help message and exit" << endl;
    cout << "  -d, --directory       Compile the specified directory" << endl;
    cout << "  -D, --debug           Enable debug mode" << endl;
    cout << "  -i, --generate-ir     Generate LLVM IR" << endl;
    cout << "  -e, --generate-exec   Generate executable" << endl;
    cout << "  -v, --version         Print version information and exit" << endl;
    cout << "  -o, --output          Specify the output directory" << endl;
    cout << "  -n, --output-exec-name Specify the name of the generated executable" << endl;
#ifdef D_DEBUG
    cout << "  -s, --source-runtime-dir Source directory of runtime" << endl;
#endif
    cout << endl;
}

#ifdef D_DEBUG

void logErr(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line)
{
    if (!ctx) {
        cerr << colorCode(FileColor::BRIGHT_YELLOW) << "Error: [ " << msg << " ] in " << file << ":" << line << endl;
        return;
    }
    cerr << colorCode(FileColor::BRIGHT_YELLOW) << "Error: [ " << msg << " ] in " << file << ":" << line << endl
         << "    Source: " << ctx->sourcePath << ":" << ctx->currLine << endl;
}

void logWarn(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line)
{
    if (!ctx) {
        cout << colorCode(FileColor::BRIGHT_YELLOW) << "Warning: [ " << msg << " ] in " << file << ":" << line << endl;
        return;
    }
    cout << colorCode(FileColor::BRIGHT_YELLOW) << "Warning: [ " << msg << " ] in " << file << ":" << line << endl
         << "    Source: " << ctx->sourcePath << ":" << ctx->currLine << endl;
}

void logInfo(const std::string &msg, const inter_gen::InterGenContext *ctx, const std::string &file, int line)
{
    if (!ctx) {
        cout << "Log: [ " << msg << " ] in " << file << ":" << line << endl;
        return;
    }
    cout << "Log: [ " << msg << " ] in " << file << ":" << line << endl
         << "    Source: " << ctx->sourcePath << ":" << ctx->currLine << endl;
}

#else

void logErr(const std::string &msg);

void logWarn(const std::string &msg);

void logInfo();

#endif

#ifdef _WIN32
inline int colorCode(FileColor color)
{
    switch (color) {
    case FileColor::GREEN:
        return FOREGROUND_GREEN;
    case FileColor::WHITE:
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    case FileColor::RED:
        return FOREGROUND_RED;
    case FileColor::YELLOW:
        return FOREGROUND_RED | FOREGROUND_GREEN;
    case FileColor::BLUE:
        return FOREGROUND_BLUE;
    case FileColor::BLACK:
        return 0;
    case FileColor::MAGENTA:
        return FOREGROUND_RED | FOREGROUND_BLUE;
    case FileColor::CYAN:
        return FOREGROUND_GREEN | FOREGROUND_BLUE;
    case FileColor::BRIGHT_GREEN:
        return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_WHITE:
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_RED:
        return FOREGROUND_RED | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_YELLOW:
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_BLUE:
        return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_MAGENTA:
        return FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    case FileColor::BRIGHT_CYAN:
        return FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    default:
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
}
#else
std::string colorCode(const FileColor color)
{
    switch (color) {
    case FileColor::GREEN:
        return "\033[32m";
    case FileColor::WHITE:
        return "\033[37m";
    case FileColor::RED:
        return "\033[31m";
    case FileColor::YELLOW:
        return "\033[33m";
    case FileColor::BLUE:
        return "\033[34m";
    case FileColor::BLACK:
        return "\033[30m";
    case FileColor::MAGENTA:
        return "\033[35m";
    case FileColor::CYAN:
        return "\033[36m";
    case FileColor::BRIGHT_GREEN:
        return "\033[92m";
    case FileColor::BRIGHT_WHITE:
        return "\033[97m";
    case FileColor::BRIGHT_RED:
        return "\033[91m";
    case FileColor::BRIGHT_YELLOW:
        return "\033[93m";
    case FileColor::BRIGHT_BLUE:
        return "\033[94m";
    case FileColor::BRIGHT_MAGENTA:
        return "\033[95m";
    case FileColor::BRIGHT_CYAN:
        return "\033[96m";
    default:
        return "\033[37m";
    }
}

#endif

} // namespace dap::util