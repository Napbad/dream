//
// Created by napbadsen on 24-10-3.
//

#include "DataPool.h"

#include <utility>

#include "DataPath.h"

template <typename T>
DataPool<T>::DataPool(const DataPoolType type, std::string name)
    : _type(type), _name(std::move(name))
{
}

template <typename T>
DataPool<T>::~DataPool()
{
    gc();
    for (auto data : _data)
    {
        delete data.second;
    }
}

template <typename T>
bool DataPool<T>::link_data(T* data, const std::string& name)
{
    _data[name] = data;
    _data_status[data] = USING;
    return false;
}

template <typename T>
T* DataPool<T>::get_data(const std::string& name)
{
    if (_data.find(name) == _data.end())
        return nullptr;

    return _data[name];
}

template <typename T>
void DataPool<T>::add_child(const DataPool<T>& child)
{
    _childs.push_back(child);
}

template <typename T>
DataPoolType DataPool<T>::type() const
{
    return _type;
}

template <typename T>
std::string DataPool<T>::name() const
{
    return _name;
}

template <typename T>
void DataPool<T>::deserve_data(const std::string& name, DataPool<T>* to)
{
    T* data = get_data(name);
    if (data != nullptr)
    {
        to->link_data(data, name);
        _data.erase(name);
    }
}

template <typename T>
void DataPool<T>::gc()
{
    for (auto& [name, data] : _data)
    {
        if (data_path::data_end(name, _name) && _data_status.at(data))
        {
            delete data;
            _data.erase(name);
        }
    }
}
