//
// Created by napbadsen on 24-10-2.
//

#ifndef CLASSCODEGENERATOR_H
#define CLASSCODEGENERATOR_H
#include <string>
#include <vector>

#include "common/dream_const.h"


class ClassCodeGenerator {
    std::vector<std::string> _public_methods;
    std::vector<std::string> _private_methods;
    std::vector<std::string> _protected_methods;
    std::vector<std::string> _public_fields;
    std::vector<std::string> _private_fields;
    std::vector<std::string> _protected_fields;
    std::vector<std::string> *_current_converting;

    ClassMemberVisibility _current_visibility;
    ClassMemberType _current_member_type;

    std::string _class_name;
public:
    explicit ClassCodeGenerator(const std::string &class_name);

    ~ClassCodeGenerator();

    void add_public_method(const std::string &method);

    void add_private_method(const std::string &method);

    void add_protected_method(const std::string &method);

    void add_public_field(const std::string &field);

    void add_private_field(const std::string &field);

    void add_protected_field(const std::string &field);

    void set_current_visibility(ClassMemberVisibility visibility);

    void set_current_member_type(ClassMemberType type);

    [[nodiscard]] ClassMemberType current_member_type() const;

    [[nodiscard]] ClassMemberVisibility current_visibility() const;

    [[nodiscard]] std::string generate_code() const;

    [[nodiscard]] std::vector<std::string> *current_converting() const;

    void add_current();

    std::string class_name();
};



#endif //CLASSCODEGENERATOR_H
