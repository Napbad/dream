//
// Created by napbad on 9/19/24.
//

#ifndef NATIVE_FUN_H
#define NATIVE_FUN_H
#include <thread>

#include "obj/val.h"



namespace native_fun {

    extern builtin start_thread_builtin;

    extern builtin add_builtin;
    extern builtin sub_builtin;
    extern builtin mul_builtin;
    extern builtin div_builtin;
    extern builtin mod_builtin;
    extern builtin lt_builtin;
    extern builtin gt_builtin;
    extern builtin lte_builtin;
    extern builtin gte_builtin;
    extern builtin eq_builtin;
    extern builtin neq_builtin;
    extern builtin and_builtin;
    extern builtin or_builtin;
    extern builtin xor_builtin;
    extern builtin lshift_builtin;
    extern builtin rshift_builtin;
    extern builtin urshift_builtin;

    inline std::unordered_map<std::string, builtin> native_map;

    void init_native_map();
}

#endif //NATIVE_FUN_H
