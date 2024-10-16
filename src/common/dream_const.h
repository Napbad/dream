//
// Created by napbadsen on 24-9-28.
//

#ifndef DREAM_CONST_H
#define DREAM_CONST_H
#include <string>

#include "reserve.h"
#include "util/response_util.h"

inline const std::string DREAM_VERSION = "0.1";

inline const std::string ROOT_HIERARCHY = "root";

inline const std::string RUNTIME_DIR = "runtime";

inline const std::string MAIN_FILE = "main.cpp";

inline const std::string MAIN_PACKAGE = "main";

inline const std::string MAIN_CLASS = "Main";

inline const std::string CONVERT_DESTINATION_FILE_TYPE = ".cpp";

inline const std::string CONVERT_SOURCE_FILE_TYPE = ".dream";

inline const std::string ROOT_DATASOURCE = "ROOT";

inline const std::string FOR_STMT = "for_stmt";
inline const std::string IF_STMT = "if_stmt";
inline const std::string WHILE_STMT = "while_stmt";
inline const std::string SWITCH_STMT = "switch_stmt";
inline const std::string DEFAULT_STMT = "default_stmt";
inline const std::string CASE_STMT = "case_stmt";
inline const std::string FUN_STMT = "fun_stmt";


enum class ClassMemberVisibility
{
    PUBLIC,
    PRIVATE,
    PROTECTED
};

enum class ClassType
{
    CLASS,
    INTERFACE
};

enum class ClassMemberType
{
    FIELD,
    METHOD
};

ClassMemberVisibility getClassMemberVisibility(const std::string& value);


#endif //DREAM_CONST_H
