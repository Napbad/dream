//
// Created by napbadsen on 24-10-18.
//

#include "gc_relative_util.h"

ushrt gc_relative_util::get_new_gc_root_id()
{
    std::lock_guard lock(id_mutex);
    while (_gc_root_id_usage[current_sequence++])
    {
        if (current_sequence >= USHRT_MAX)
        {
            current_sequence = 0;
        }
    }
    _gc_root_id_usage[current_sequence] = true;
    return current_sequence;
}

void gc_relative_util::free_gc_root_id(ushrt id)
{
    std::lock_guard lock(id_mutex);
    _gc_root_id_usage[id] = false;
}
