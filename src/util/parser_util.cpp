//
// Created by napbadsen on 24-10-9.
//

#include "parser_util.h"

std::vector<std::string> parser_util::gen_data_pool_define(std::string name, DataPoolType type)
{
    return {"DataPool<"+ name + ">* datapool_" + name +
        " = new DataPool(DataPoolType::" + (type == DataPoolType::INPUT ? "INPUT" : "OWN") + ", \"" + name + "\");"};
}
