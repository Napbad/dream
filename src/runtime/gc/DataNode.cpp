//
// Created by napbadsen on 24-10-17.
//

#include "DataNode.h"


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
DataNode<T>* DataNode<T>::create(T* data)
{
    return new DataNode(data);
}
