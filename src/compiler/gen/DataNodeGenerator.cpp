//
// Created by napbad on 10/21/24.
//

#include "DataNodeGenerator.h"

#include "common/dream_define.h"
#include "util/string_util.h"

std::string DataNodeGenerator::generate(const std::string& type, const std::string& name)
{
    return
        "DataNode<" + type + ">*"
        + DATA_NODE_PREFIX + name + " ="
        " DataNode<" + type + ">::"
        "create(" + name + ");\n";
}

std::string DataNodeGenerator::generate_denode_fun_param(FUN_PARAM_TYPE param)
{
    string res;
    // if is common type, then just return it
    if (string_util::str_is_common_type(std::get<FUN_PARAM_TYPE_NAME_IDX>(param)))
        return res;

    // is not common type
    string name = std::get<FUN_PARAM_NAME_IDX>(param);
    string real_name = name.substr(DATA_NODE_PREFIX_LENGTH);
    // convert the DataNode to Real DataType
    res.append(std::get<FUN_PARAM_TYPE_NAME_IDX>(param))
       .append(" ")
       .append(real_name)
       .append(" = ")
       .append(name)
       .append(".get();\n");

    return res;
}
