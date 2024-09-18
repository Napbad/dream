//
// Created by napbad on 9/12/24.
//

#ifndef GC_H
#define GC_H
#include "DataSource.h"

class GC {
public:
    static void collect(const DataSource *ds);
    static void collect(const Dval *val);
};

#endif //GC_H
