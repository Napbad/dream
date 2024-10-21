//
// Created by napbadsen on 24-10-8.
//

#ifndef GCABLE_H
#define GCABLE_H


class GCable
{
public:
    virtual ~GCable() = default;

    virtual void gc() {};

    virtual void destroy() {};
};


#endif //GCABLE_H
