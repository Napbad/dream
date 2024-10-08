// created by napbad

#include "DataSource.h"


DataSource::DataSource(HierarchyType type, const std::string& name)
{
    _hierarchy = type;
    _name = name;
}

DataSource::~DataSource()
{
    for (auto pool : _data_pools)
    {
        delete pool;
    }
}

HierarchyType DataSource::hierarchy() const
{
    return _hierarchy;
}

void DataSource::link_data(GCable* data_pool)
{
    _data_pools.push_back(data_pool);
}

void DataSource::gc()
{
    for (const auto& pool : _data_pools)
    {
        pool->gc();
    }
}
