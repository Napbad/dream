// create by napbad 

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <vector>


enum class HierarchyType {
    ROOT,
    FUN,
    CLASS
};

class DataSource
{
    HierarchyType _hierarchy;
public:
    DataSource();
    ~DataSource();

    [[nodiscard]] HierarchyType hierarchy() const;

};

#endif