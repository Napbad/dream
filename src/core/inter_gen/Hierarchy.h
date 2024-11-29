//
// Created by napbad on 11/4/24.
//

#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <map>
#include <string>
#include <utility>
#include <vector>

enum class HierarchyType
{
    PROGRAM,
    MODULE_,
    FUNCTION,
    BASIC_BLOCK,
    STATEMENT
};

// this file is used to store some data,
// and represent the hierarchy of the program
class Hierarchy
{
    HierarchyType type = HierarchyType::MODULE_;
    std::string name;
    Hierarchy *parent = nullptr;
    std::vector<Hierarchy *> children;
    std::map<std::string, std::string> strValues;
    std::map<std::string, std::string> structVals;

  public:
    Hierarchy(Hierarchy *parent, const HierarchyType type, std::string name)
    {
        this->parent = parent;
        this->type = type;
        this->name = std::move(name);
    }

    [[nodiscard]] HierarchyType getType() const
    {
        return type;
    }

    [[nodiscard]] std::string getName() const
    {
        return name;
    }

    [[nodiscard]] Hierarchy *getParent() const
    {
        return parent;
    }

    [[nodiscard]] std::vector<Hierarchy *> getChildren() const
    {
        return children;
    }
    void addChild(Hierarchy *child)
    {
        children.push_back(child);
    }

    void removeChild(Hierarchy *child)
    {
        for (auto it = children.begin(); it != children.end(); ++it)
        {
            if (*it == child)
            {
                children.erase(it);
                return;
            }
        }
    }
};

#endif // HIERARCHY_H
