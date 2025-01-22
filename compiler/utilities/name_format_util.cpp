

#include "name_format_util.h"
namespace dap::util
{
std::string getFunBasicBlockName(const std::string *funName)
{
    std::string result;
    result.append(funName->c_str());
    return result;
}
} // namespace dap::util
