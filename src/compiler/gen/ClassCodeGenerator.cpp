//
// Created by napbadsen on 24-10-2.
//

#include "ClassCodeGenerator.h"

#include "util/string_util.h"

ClassCodeGenerator::ClassCodeGenerator(const std::string& class_name)
    : _class_struct(ClassStructGenerator(class_name))
{
    _current_converting = new std::vector<std::string>;

    _class_name = class_name;
}

ClassCodeGenerator::~ClassCodeGenerator()
{
    delete _current_converting;
}


std::string ClassCodeGenerator::generate_code() const
{
    std::string code;

    code += string_util::get_lines_from_vector(_methods);

    // code += "};\n";

    return code;
}

std::vector<std::string>* ClassCodeGenerator::current_converting() const
{
    return _current_converting;
}

ClassStructGenerator ClassCodeGenerator::class_struct() const
{
    return _class_struct;
}

void ClassCodeGenerator::add_to_current(const std::string& stmt) const
{
    _current_converting->push_back(stmt);
}

void ClassCodeGenerator::add_to_current(const char* stmt) const
{
    _current_converting->emplace_back(stmt);
}

void ClassCodeGenerator::add_current()
{
    _methods.insert(_methods.end(),
        current_converting()->begin(), current_converting()->end());

    current_converting()->clear();
}

std::string ClassCodeGenerator::class_name() const
{
    return _class_name;
}
