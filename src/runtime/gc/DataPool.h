//
// Created by napbadsen on 24-10-3
//

#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <string>
#include <unordered_map>
#include <vector>

#include "GCable.h"

constexpr bool USING = false;
constexpr bool USED = true;

// Type
enum class DataPoolType {
    INPUT,
    OWN
};

template<typename T>
struct DataWrapper {
    T* data;
    bool status;
};

template<typename T>
class DataPool : public GCable {
    DataPoolType _type;
    std::string _name;
    std::vector<DataPool> _childs;
    std::unordered_map<std::string, T*> _data;
    std::unordered_map<T*, bool> _data_status;

public:
    DataPool(DataPoolType type, std::string  name);

    ~DataPool() override;

    bool link_data(T* data, const std::string& name);

    T* get_data(const std::string& name);

    void add_child(const DataPool& child);

    [[nodiscard]] DataPoolType type() const;

    [[nodiscard]] std::string name() const;

    void deserve_data(const std::string& name, DataPool* to);

    void gc() override;
};

#endif //DATAPOOL_H

