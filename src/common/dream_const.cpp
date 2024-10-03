//
// Created by napbadsen on 24-9-28.
//

#include "dream_const.h"

ClassMemberVisibility getClassMemberVisibility(const std::string& value)
{
    if (value == D_PUBLIC)
    {
        return ClassMemberVisibility::PUBLIC;
    }
    else if (value == D_PRIVATE)
    {
        return ClassMemberVisibility::PRIVATE;
    }
    else if (value == D_PROTECTED)
    {
        return ClassMemberVisibility::PROTECTED;
    }
    else
    {
        response_util::report_error("Invalid class member visibility", "", 0);
    }
    return ClassMemberVisibility::PRIVATE;

}