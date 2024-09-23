//
// Created by napbad on 9/23/24.
//

#include "Global.h"

Global::Global() {
    _var_nullable = std::unordered_map<std::string, bool>();
}

void Global::add_var_nullable(const std::string &identifier, bool nullable) {
    _var_nullable[identifier] = nullable;
}

bool Global::is_var_nullable(const std::string &identifier) {
    return _var_nullable[identifier];
}

bool Global::is_var_exists_in_nullable_list(const std::string &identifier) const {
    return _var_nullable.contains(identifier);
}
