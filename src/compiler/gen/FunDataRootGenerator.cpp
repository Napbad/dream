//
// Created by napbad on 10/20/24.
//

#include "FunDataRootGenerator.h"

#include "common/dream_define.h"

FunDataRootGenerator::FunDataRootGenerator()
{
    _name = "";
}

void FunDataRootGenerator::set_name(const std::string& name)
{
    _name = name;
}

std::string FunDataRootGenerator::name() const
{
    return _name;
}

std::string FunDataRootGenerator::generate_code() const
{
    return ("FunDataRoot *data_root_fun = new FunDataRoot();\n"
        "GLOBAL_DATA_ROOT->add_fun_data_root(data_root_fun);\n");
}

std::string FunDataRootGenerator::generate_root_link_code(const std::string& type, const std::string& name)
{
    return ("data_root_fun->add_data( " DATA_NODE_PREFIX + name + " );\n");
}
