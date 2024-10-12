//
// Created by napbadsen on 24-10-9.
//

#include "StructDataCodeGenerator.h"

#include "util/parser_util.h"
#include "util/string_util.h"

StructDataCodeGenerator::StructDataCodeGenerator(const std::string& struct_name)
{
        _struct_name = struct_name;
}

std::string StructDataCodeGenerator::generate_code() const
{
    return _struct_name + "{ \n"
        + string_util::get_lines_from_vector(_fields)
        + "\n } \n";
}

void StructDataCodeGenerator::add_field(std::string type, const std::string& name)
{
    _fields.push_back(parser_util::convert_type_to_cpp(type) + " " + name + ";\n");
}

void StructDataCodeGenerator::remove(const std::string& field)
{
    if (const auto res = std::find(_fields.begin(), _fields.end(), field);
        res != _fields.end())
        _fields.erase(res);
}
