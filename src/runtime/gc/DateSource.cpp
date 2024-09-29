// created by napbad

#include "DataSource.h"

DataSource::DataSource()
{
    _data_nodes = std::vector<DataNode*>();
    _hierarchy = HierarchyType::ROOT;
}

DataSource::~DataSource()
{
    for (const auto it : _data_nodes)
        delete it;
}

HierarchyType DataSource::hierarchy() const
{
    return _hierarchy;
}



