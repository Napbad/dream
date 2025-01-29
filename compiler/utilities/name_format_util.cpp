

#include "name_format_util.h"
namespace dap::util
{
std::string getFunBasicBlockName(const std::string *funName)
{
    std::string result;
    result.append(*funName);
    return result;
}
std::string getIfBasicBlockName(const std::string &funName)
{
    std::string result;
    result.append(funName);
    result.append("IfBlock");
    return result;
}
std::string getElseBasicBlockName(const std::string &funName)
{
    std::string result;
    result.append(funName);
    result.append("ElseBlock");
    return result;
}

std::string getMergeBasicBlockName(const std::string &funName)
{
    std::string result;
    result.append(funName);
    result.append("MergeBlock");
    return result;
}
} // namespace dap::util
