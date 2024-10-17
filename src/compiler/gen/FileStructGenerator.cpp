//
// Created by napbadsen on 24-10-17.
//

#include "FileStructGenerator.h"

FileStructGenerator::FileStructGenerator(const std::string& name)
{
    _name = name;
}

std::string FileStructGenerator::generate_code() const
{
    string res;
    for (auto& class_code_generator : _class_struct_generators)
        res.append(class_code_generator.generate_code());
    res.append("\n");

    for (auto& decl : _var_decl)
        res.append(decl);
    res.append("\n");

    for (auto& decl : _fun_decl)
        res.append(decl);
    res.append("\n");
    return res;
}

void FileStructGenerator::add_var_decl(const string& decl)
{
    _var_decl.push_back(decl);
}

void FileStructGenerator::add_fun_decl(const string& decl)
{
    _fun_decl.push_back(decl);
}

ClassStructGenerator& FileStructGenerator::get_newest_class_struct_generator()
{
    return _class_struct_generators.back();
}


void FileStructGenerator::add_new_class_code_generator(const std::string& name)
{
    _class_struct_generators.emplace_back(name);
}
