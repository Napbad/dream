//
// Created by napbad on 9/26/24.
//

#include "Hierarchy.h"

#include <ranges>
#include <utility>
#include <bits/streambuf_iterator.h>

Hierarchy* Hierarchy::get_child(const int i) const
{
    if (_children == nullptr || i >= _children->size())
    {
        return nullptr;
    }
    return _children->at(i);
}

Hierarchy::Hierarchy(
    std::string name,
    const HierarchyType type,
    Hierarchy* parent,
    std::vector<Hierarchy*>* children)
    : _name(std::move(name)),
      _type(type),
      _parent(parent),
      _children(children)
{
}

void Hierarchy::add_child(Hierarchy* hierarchy) const
{
    _children->push_back(hierarchy);
}

Hierarchy* Hierarchy::find_child_by_name(const std::string& name) const
{
    for (const auto& child : *_children)
    {
        if (child->name() == name)
        {
            return child;
        }
    }

    return nullptr;
}

void Hierarchy::set_parent(Hierarchy* hierarchy)
{
    _parent = hierarchy;
}

Hierarchy* Hierarchy::merge_hierarchy(Hierarchy* root, Hierarchy* package)
{
    Hierarchy* root_tmp = root;
    Hierarchy* package_tmp = package;

    if (root_tmp == nullptr || package_tmp == nullptr)
    {
        return nullptr;
    }

    while (root_tmp->name() == package_tmp->name())
    {
        Hierarchy* tmp = package_tmp->get_child(0);
        if (tmp == nullptr)
        {
            throw std::runtime_error("merge_hierarchy: package hierarchy is empty at: " +
                package_tmp->name() + "'s child");
        }
        delete package_tmp;
        package_tmp = tmp;

        // root hierarchy contains the package hierarchy
        if (root_tmp->exist_child(package_tmp))
        {
            root_tmp = root_tmp->find_child_by_name(package_tmp->name());
        }
        else
        {
            break;
        }
    }

    root_tmp->add_child(package_tmp);
    package_tmp->set_parent(root_tmp);

    while (package_tmp->get_child(0) != nullptr)
    {
        package_tmp = package_tmp->get_child(0);
    }
    return package_tmp;
}

Hierarchy* Hierarchy::root_hierarchy()
{
    return new Hierarchy("root", HierarchyType::ROOT, nullptr, new std::vector<Hierarchy*>);
}

Hierarchy* Hierarchy::file_hierarchy(const std::string& file_name)
{
    return new Hierarchy(file_name, HierarchyType::FILE, nullptr, new std::vector<Hierarchy*>);
}

void Hierarchy::add_child_pkg_hierarchy(std::vector<std::string> &value)
{
    if (value.empty())
        return;

    Hierarchy* hierarchy = new Hierarchy(value[0], HierarchyType::PACKAGE, this, new std::vector<Hierarchy*>);
    value.erase(value.begin());
    hierarchy->add_child_pkg_hierarchy(value);
    _children->push_back(hierarchy);
}

Hierarchy* Hierarchy::parent() const
{
    return _parent;
}

std::string Hierarchy::name() const
{
    return _name;
}

HierarchyType Hierarchy::type() const
{
    return _type;
}

bool Hierarchy::exist_child(const Hierarchy* hierarchy) const
{
    for (const auto& child : *_children)
    {
        if (child->name() == hierarchy->name())
        {
            return true;
        }
    }

    return false;
}
