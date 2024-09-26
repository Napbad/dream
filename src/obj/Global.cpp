//
// Created by napbad on 9/23/24.
//

#include "Global.h"

#include "util/file_util.h"

Global::Global() {
    _var_nullable = new std::unordered_map<std::string, bool>();
    _hierarchy = Hierarchy::root_hierarchy();
}

void Global::add_var_nullable(const std::string &identifier, const bool nullable) const {
    _var_nullable->insert({identifier, nullable});
}

bool Global::is_var_nullable(const std::string &identifier) const {
    if (!_var_nullable->contains(identifier)) return false;
    print(std::cout, "identifier " + identifier + " is undefined", file_util::FileColor::BLUE);
    return _var_nullable->at(identifier);
}

bool Global::is_var_exists_in_nullable_list(const std::string &identifier) const {
    return _var_nullable->contains(identifier);
}

Hierarchy * Global::hierarchy() const {
    return _hierarchy;
}

