//
// Created by napbadsen on 24-10-17.
//

#ifndef DATAROOT_H
#define DATAROOT_H
#include <string>
#include <vector>

#include "DataNode.h"

class FunDataRoot;

class DataRoot final : public GCable{
    std::string _name;
    std::vector<GCable> _data;
    std::vector<FunDataRoot> _fun_data;

    explicit DataRoot(const std::string& name);

public:
    void add_data(const GCable& data);
    void add_fun_data_root(FunDataRoot& data);

    void gc() override;
};



#endif //DATAROOT_H
