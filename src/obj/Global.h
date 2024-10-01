//
// Created by napbad on 9/23/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <unordered_map>

#include "Hierarchy.h"

// this class is recording the global information

class Global {
    std::unordered_map<std::string, bool> *_var_nullable;
    Hierarchy *_hierarchy;
    std::vector<std::string> _file_to_compile_list;

public:
    Global();
    void add_var_nullable(const std::string &identifier, bool nullable) const;

    [[nodiscard]] bool is_var_nullable(const std::string &identifier) const;

    [[nodiscard]] bool is_var_exists_in_nullable_list(const std::string &identifier) const;

    [[nodiscard]] Hierarchy* hierarchy() const;

    void add_file_compile(const std::string& string);

    [[nodiscard]]std::vector<std::string> file_to_compile_list();

};

#endif //GLOBAL_H
