//
// Created by napbadsen on 24-10-3.
//

#ifndef DATAPOOL_H
#define DATAPOOL_H
#include <string>
#include <unordered_map>
#include <vector>

// type
enum class DataPoolType
{
    INPUT,
    OWN
};

class DataPool {
    DataPoolType _type;

    std::string _name;

    std::vector<DataPool> _childs;

    std::unordered_map<std::string, void*> _data;

public:
    DataPool(const DataPoolType type, const std::string& name);

    bool link_data(void* data, std::string name);

    void* get_data(const std::string& name);

    void add_child(const DataPool& child);

    DataPoolType type() const;

    std::string name() const;
};

#endif //DATAPOOL_H
