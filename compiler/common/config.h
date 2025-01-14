//
// Created by napbad on 1/11/25.
//

#ifndef CONFIG_H
#define CONFIG_H
#include <string>

namespace dap
{
const std::string DEFUALT_BUILD_DIR = "./build";
const std::string DEFAULT_TARGET_NAME = "executable";

extern std::string buildDir;

extern std::string targetExecName;

extern std::string D_VERSION;

void readConfig(std::string configPath);
} // namespace dap

#endif // CONFIG_H
