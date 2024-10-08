//
// Created by napbadsen on 24-10-3.
//

#include "DataPool.h"

DataPool::DataPool(const DataPoolType type, const std::string& name)
{
    _type = type;
    _name = name;
}

bool DataPool::link_data(void* data, std::string name)
{
    _data.insert(std::pair<std::string, void*>(name, data));
    return true;
}

void* DataPool::get_data(const std::string& name)
{
    if (_data.find(name) == _data.end())
        return nullptr;

    return _data[name];
}

void DataPool::add_child(const DataPool& child)
{
    _childs.push_back(child);
}

DataPoolType DataPool::type() const
{
    return _type;
}

std::string DataPool::name() const
{
    return _name;
}
