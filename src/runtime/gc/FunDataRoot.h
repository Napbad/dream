//
// Created by napbadsen on 24-10-17.
//

#ifndef FUNDATAROOT_H
#define FUNDATAROOT_H
#include <string>
#include <vector>

#include "GCable.h"


class FunDataRoot final : public GCable {

    std::string _name;
    std::vector<GCable> _data;

public:
    void add_data(const GCable& data);

    void gc() override;
};



#endif //FUNDATAROOT_H
