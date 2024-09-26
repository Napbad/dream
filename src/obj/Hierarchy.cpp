//
// Created by napbad on 9/26/24.
//

#include "Hierarchy.h"

Hierarchy::Hierarchy(
    const std::string &name,
    const HierarchyType type,
    Hierarchy *parent) {
    _name = name;
    _type = type;
    _parent = parent;
}

Hierarchy *Hierarchy::root_hierarchy() {
    return new Hierarchy("root", HierarchyType::ROOT, nullptr);
}

Hierarchy * Hierarchy::file_hierarchy(const std::string &file_name) {
    return new Hierarchy(file_name, HierarchyType::FILE, nullptr);
}

