// create by napbad 

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <any>
#include <string>
#include <vector>

#include "DataPool.h"


enum class HierarchyType {
    ROOT,
    FUN,
    CLASS
};

class DataSource: public GCable
{
    HierarchyType _hierarchy;

    std::vector<GCable*> _data_pools;

    std::string _name;
public:
    DataSource(HierarchyType type, const std::string& name);
    ~DataSource() override;

    [[nodiscard]] HierarchyType hierarchy() const;

    void link_data(GCable* data_pool);

    void gc() override;
};

#endif