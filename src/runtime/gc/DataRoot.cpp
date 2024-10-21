//
// Created by napbadsen on 24-10-17.
//

#include "../reserve/d_define.h"
#include "DataRoot.h"
#include "FunDataRoot.h"

DataRoot* GLOBAL_DATA_ROOT = new DataRoot("root");

DataRoot::DataRoot(const std::string& name)
{
    _name = name;
    _data = {};
    _fun_data = {};
}

void DataRoot::add_data(GCable* data)
{
    _data.push_back(data);
}

void DataRoot::add_fun_data_root(FunDataRoot* data)
{
        _fun_data.push_back(data);
}

void DataRoot::destroy()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Destroy DataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif

    for (const auto data : _data)
    {
        data->destroy();
    }
    for (const auto data: _fun_data)
    {
        data->destroy();
    }
}

void DataRoot::gc()
{
    for (const auto& data : _fun_data)
    {
        data->gc();
    }
    for (const auto& data : _data)
    {
        data->gc();
    }
}
