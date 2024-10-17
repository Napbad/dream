//
// Created by napbadsen on 24-10-17.
//

#include "DataRoot.h"

#include "FunDataRoot.h"

DataRoot::DataRoot(const std::string& name)
{
    _name = name;
    _data = {};
    _fun_data = {};
}

void DataRoot::add_data(const GCable& data)
{
    _data.push_back(data);
}

void DataRoot::add_fun_data_root(FunDataRoot& data)
{
        _fun_data.push_back(data);
}

void DataRoot::gc()
{
    for (auto& data : _fun_data)
    {
        data.gc();
    }
    for (auto& data : _data)
    {
        data.gc();
    }
}
