//
// Created by napbad on 9/26/24.
//

#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <string>
#include <vector>

enum class HierarchyType {
    ROOT,
    FILE,
    FILE_CLASS,
    FILE_FUN,
    FILE_CLASS_FUN,
    FILE_CLASS_FUN_BLOCK,
    FILE_VAR
};

class Hierarchy {
    std::string _name;
    HierarchyType _type;
    Hierarchy *_parent;
    std::vector<Hierarchy *> _children;
public:
    Hierarchy(const std::string &name, HierarchyType type, Hierarchy *parent);

    static Hierarchy *root_hierarchy();

    static Hierarchy * file_hierarchy(const std::string &file_name);
};



#endif //HIERARCHY_H
