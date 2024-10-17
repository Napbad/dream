//
// Created by napbadsen on 24-10-17.
//

#include "FunDataRoot.h"

void FunDataRoot::add_data(const GCable& data)
{
    _data.push_back(data);
}

void FunDataRoot::gc()
{
    for (auto& d : _data)
    {
        d.gc();
    }
}
