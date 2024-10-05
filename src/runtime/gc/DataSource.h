// create by napbad 

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <vector>

#include "DataNode.h"

enum class HierarchyType {
    ROOT,
    FUN,
    CLASS
};

class DataSource
{
    HierarchyType _hierarchy;
    std::vector<DataNode*> _data_nodes;
public:
    DataSource();
    ~DataSource();

    [[nodiscard]] HierarchyType hierarchy() const;

};

#endif