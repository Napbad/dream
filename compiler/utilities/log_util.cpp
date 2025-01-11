#include <iostream>

#include "log_util.h"

namespace dap::util {
#ifdef D_DEBUG

void err(const std::string &msg, const std::string &file, int line) {
    std::cerr << "Error: " << msg << " in " << file << ":" << line << std::endl;
}

void warn(const std::string &msg, const std::string &file, int line);

void log(const std::string &msg, const std::string &file, int line);

#else 

void err(const std::string &msg);

void warn(const std::string &msg);

void log();

#endif
}