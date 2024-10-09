//
// Created by napbadsen on 24-10-9.
//

#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H
#include <string>
#include <vector>

#include "runtime/gc/DataPool.h"

namespace parser_util
{
    std::vector<std::string> gen_data_pool_define(std::string name, DataPoolType type);

}

#endif //PARSER_UTIL_H
