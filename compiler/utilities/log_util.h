

#ifndef LOG_UTIL_H
#define LOG_UTIL_H



#include <string>

#include "compiler/common/define_d.h"
namespace dap::util {
#ifdef D_DEBUG

void err(const std::string &msg, const std::string &file, int line);

void warn(const std::string &msg, const std::string &file, int line);

void log(const std::string &msg, const std::string &file, int line);

#else 

void err(const std::string &msg);

void warn(const std::string &msg);

void log();

#endif
}
#endif 