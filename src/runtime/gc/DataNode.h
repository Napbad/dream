//
// Created by napbadsen on 24-10-17.
//

#ifndef DATANODE_H
#define DATANODE_H
#include <functional>

#include "GCable.h"

template<typename T>
class DataNode final : public GCable {
    T *_data;
    short _data_cnt_size = 1;

    explicit DataNode(T *data) : _data(data){}
public:

    ~DataNode() override;

    void gc() override;

    void add_ref();

    void remove_ref();

    static  DataNode* create(T *data);
};



#endif //DATANODE_H
