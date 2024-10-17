//
// Created by napbadsen on 24-10-2.
//

#include "ClassCodeGenerator.h"

#include "util/string_util.h"


ClassCodeGenerator::ClassCodeGenerator(const std::string& class_name)
    : _class_struct(ClassStructGenerator(class_name))
{
    _public_methods = {};
    _private_methods = {};
    _protected_methods = {};
    _public_fields = {};
    _private_fields = {};
    _protected_fields = {};

    _current_converting = new std::vector<std::string>;

    _current_visibility = ClassMemberVisibility::PUBLIC;
    _current_member_type = ClassMemberType::FIELD;

    _class_name = class_name;
}

ClassCodeGenerator::~ClassCodeGenerator()
{
    delete _current_converting;
}

void ClassCodeGenerator::add_public_method(const std::string& method)
{
    _public_methods.push_back(method);
}

void ClassCodeGenerator::add_private_method(const std::string& method)
{
    _private_methods.push_back(method);
}

void ClassCodeGenerator::add_protected_method(const std::string& method)
{
    _protected_methods.push_back(method);
}

void ClassCodeGenerator::add_public_field(const std::string& field)
{
    _public_fields.push_back(field);
}

void ClassCodeGenerator::add_private_field(const std::string& field)
{
    _private_fields.push_back(field);
}

void ClassCodeGenerator::add_protected_field(const std::string& field)
{
    _protected_fields.push_back(field);
}

void ClassCodeGenerator::set_current_visibility(ClassMemberVisibility visibility)
{
    _current_visibility = visibility;
}

void ClassCodeGenerator::set_current_member_type(ClassMemberType type)
{
    _current_member_type = type;
}

ClassMemberType ClassCodeGenerator::current_member_type() const
{
    return _current_member_type;
}

ClassMemberVisibility ClassCodeGenerator::current_visibility() const
{
    return _current_visibility;
}

std::string ClassCodeGenerator::generate_code() const
{
    std::string code;

    if (!_public_fields.empty() || !_public_methods.empty())
    {
        // code += "public:\n";
        // code += string_util::get_lines_from_vector(_public_fields);
        code += string_util::get_lines_from_vector(_public_methods);
    }

    if (!_protected_fields.empty() || !_protected_methods.empty())
    {
        // code += "protected:\n";
        // code += string_util::get_lines_from_vector(_protected_fields);
        code += string_util::get_lines_from_vector(_protected_methods);
    }

    if (!_private_fields.empty() || !_private_methods.empty())
    {
        // code += "private:\n";
        // code += string_util::get_lines_from_vector(_private_fields);
        code += string_util::get_lines_from_vector(_private_methods);
    }

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
    switch (_current_visibility)
    {
    case ClassMemberVisibility::PUBLIC:
        // switch (_current_member_type)
        // {
        // case ClassMemberType::FIELD:
        //     add_public_field(string_util::get_text_from_vector(*_current_converting));
        //     current_converting()->clear();
        //
        //     break;
        // case ClassMemberType::METHOD:
            add_public_method(string_util::get_text_from_vector(*_current_converting));
            current_converting()->clear();

            // break;
        // default: current_converting()->clear();

            // response_util::report_error("Unknown visibility", "ClassCodeGenerator", 0);
        // }
        break;

    case ClassMemberVisibility::PRIVATE:
        // switch (_current_member_type)
        // {
        // case ClassMemberType::FIELD:
        //     add_private_field(string_util::get_text_from_vector(*_current_converting));
        //     current_converting()->clear();
        //
        //     break;
        // case ClassMemberType::METHOD:
            add_private_method(string_util::get_text_from_vector(*_current_converting));
            current_converting()->clear();
        //
        //     break;
        // default:
        //     current_converting()->clear();
        //     response_util::report_error("Unknown visibility", "ClassCodeGenerator", 0);
        // }
        break;

    case ClassMemberVisibility::PROTECTED:
        // switch (_current_member_type)
        // {
        // case ClassMemberType::FIELD:
        //     add_protected_field(string_util::get_text_from_vector(*_current_converting));
        //     current_converting()->clear();
        //
        //     break;
        // case ClassMemberType::METHOD:
            add_protected_method(string_util::get_text_from_vector(*_current_converting));
            current_converting()->clear();
        //
        //     break;
        // default:
        //     current_converting()->clear();
        //     response_util::report_error("Unknown visibility", "ClassCodeGenerator", 0);
        // }
        break;
    }
}

std::string ClassCodeGenerator::class_name() const
{
    return _class_name;
}
