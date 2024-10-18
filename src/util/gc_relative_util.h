//
// Created by napbadsen on 24-10-18.
//

#ifndef GC_RELATIVE_UTIL_H
#define GC_RELATIVE_UTIL_H
#include <bitset>
#include <climits>
#include <mutex>

#include "runtime/gc/DataRoot.h"

typedef unsigned short ushrt;

namespace gc_relative_util
{
    std::bitset<USHRT_MAX> _gc_root_id_usage{0};
    unsigned short current_sequence = 0;
    std::mutex id_mutex;

    ushrt get_new_gc_root_id();

    void free_gc_root_id(ushrt id);
}

#endif //GC_RELATIVE_UTIL_H
