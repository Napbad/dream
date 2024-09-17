//
// Created by napbad on 9/10/24.
//

#include "Package.h"

#include "util/parse_util.h"

Package::Package(const std::string &name, const std::vector<Package *> &children) {
    _name = name;
    _children = new std::vector(children);
    _env = new Denv();
    _value = dval::dval_package(this);
}

Package::Package(const std::string &name) {
        _name = name;
        _children = new std::vector<Package*>();
        _env = new Denv();
        _value = dval::dval_package(this);
}

std::string Package::name() const {
    return _name;
}

std::vector<Package *> *Package::children() const {
    return _children;
}

void Package::add_child(const Package *child) const {
    _children->push_back(const_cast<vector<Package *>::value_type>(child));
}

bool Package::exists_package(const std::string &packageName) const {
    vector<string> *package = util::parse::parsePackage(packageName);

    if (package == nullptr || package->empty()) {
        return false;
    }

    if (_name == package->at(0)) {
        package->erase(package->begin());
        for (const auto &child: *_children) {
            if (child->exists_package(package->at(0))) {
                return true;
            }
        }
    }

    delete package;

    return false;
}

Package *Package::has_child(std::vector<std::string>::const_reference at) const {
    for (const auto &child: *_children) {
        if (child->name() == at) {
            return child;
        }
    }
    return nullptr;
}

void Package::add_package(std::vector<std::string> *pkgs) const {
    if (pkgs == nullptr || pkgs->empty()) {
        return;
    }
    if (const Package *child = has_child(pkgs->at(0)); child != nullptr) {
        pkgs->erase(pkgs->begin());
        child->add_package(pkgs);
        return;
    }

    _children->push_back(new Package(pkgs->at(0)));

    Package * tmp = _children->at((_children->size() - 1));
    pkgs->erase(pkgs->begin());
    _children->at((_children->size() - 1))->add_package(pkgs);
}
