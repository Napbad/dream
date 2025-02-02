

#ifndef NAME_FORMAT_UTIL
#define NAME_FORMAT_UTIL

#include <string>
namespace dap::util
{
std::string getFunBasicBlockName(const std::string *funName);

std::string getIfBasicBlockName(const std::string &funName);

std::string getElseBasicBlockName(const std::string &funName);

std::string getMergeBasicBlockName(const std::string &funName);
} // namespace dap::util
#endif // !NAME_FORMAT_UTIL
