//
// Created by napbadsen on 24-10-17.
//

#ifndef DATANODE_H
#define DATANODE_H
#include <functional>
#include <iostream>

#include "GCable.h"
#include "../reserve/d_define.h"
#include "../../runtime/dbg/debug_util.h"

template <typename T>
class DataNode final : public GCable
{
    T _data; /// T must be a pointer
    short _data_cnt_size = 1;

    explicit DataNode(T* data) : _data(*data)
    {
    }

    explicit DataNode(T data) : _data(data)
    {
    }

public:
    ~DataNode() override;

    void gc() override;
    void destroy() override;

    void add_ref();

    void remove_ref();

    T get();

    static DataNode* create(T* data);
    static DataNode* create(T data);
};


template <typename T>
DataNode<T>::~DataNode()
{
    delete _data;
}

template <typename T>
void DataNode<T>::gc()
{
    if (_data_cnt_size != 0)
        delete _data;
}

template <typename T>
void DataNode<T>::destroy()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Destroy DataNode: %p \n\0", *_data);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    if (_data_cnt_size != 0)
    {
        delete _data;
        _data_cnt_size = 0;
    }
}

template <typename T>
void DataNode<T>::add_ref()
{
    _data_cnt_size++;
}

template <typename T>
void DataNode<T>::remove_ref()
{
    _data_cnt_size--;
}

template <typename T>
T DataNode<T>::get()
{
    return _data;
}

template <typename T>
DataNode<T>* DataNode<T>::create(T* data)
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Creating DataNode: %p \n\0", *data);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    return new DataNode(*data);
}

template <typename T>
DataNode<T>* DataNode<T>::create(T data)
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Creating DataNode: %p \n\0", data);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    return new DataNode(data);
}


#endif //DATANODE_H
