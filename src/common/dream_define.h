//
// Created by napbadsen on 24-9-28.
//

#ifndef DREAM_DEFINE_H
#define DREAM_DEFINE_H

#include "../runtime/gc/DataRoot.h"

#define DREAM

#define DEBUG_COMPILE_MODE global_flag_is_debug

#define DATA_ROOT_NAME GLOBAL_DATA_ROOT

#define DATA_NODE_PREFIX "d__datanode_"
#define DATA_NODE_PREFIX_LENGTH 12

/// Macros for function parameter types and properties
#define FUN_PARAM_TYPE_NAME std::string
#define FUN_PARAM_NAME std::string
#define FUN_PARAM_NULLABLE bool
#define FUN_PARAM_MUTABLE bool

#define FUN_PARAM_TYPE_NAME_IDX 0
#define FUN_PARAM_NAME_IDX 1
#define FUN_PARAM_NULLABLE_IDX 2
#define FUN_PARAM_MUTABLE_IDX 3

/// Macro for a tuple representing a function parameter
#define FUN_PARAM_TYPE \
    std::tuple< \
    FUN_PARAM_TYPE_NAME, \
    FUN_PARAM_NAME, \
    FUN_PARAM_NULLABLE, \
    FUN_PARAM_MUTABLE \
    >


#endif //DREAM_DEFINE_H
