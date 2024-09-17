//
// Created by napbad on 9/10/24.
//

#include "Global.h"

#include "util/parse_util.h"

void Global::add_package(const Package *package) const {
    _root->add_child(package);
}

bool Global::is_package_exists(const std::string &packageName) const {
    return _root->exists_package(packageName);
}

Package * Global::package() const {
    return _root;
}

Package * Global::get_package(const std::string &packageName) const {
    vector<string> * package = util::parse::parsePackage(packageName);

    Package * pkg = _root;
    for (auto &child : *(pkg -> children())) {
        if (package->empty()) {
            return pkg;
        }

        if (child == *(pkg->children()->end())) {
            return nullptr;
        }

        if (child->name() == package->at(0)) {
            pkg = child;
            package->erase(package->begin());
        }
    }

    return pkg;
}

void Global::add_package(const std::string &string) const {
    vector<std::string> * pkgs = util::parse::parsePackage(string);
    if (pkgs == nullptr || pkgs->empty()) {
        return;
    }

    _root->add_package(pkgs);

    // for (auto &pkg : _root->children()) {
    //     for (auto &pkg1 : _root->children()) {
    //         for (auto &pkg2 : _root->children()) {
    //             for (auto &pkg3 : _root->children()) {
    //                 for (auto &pkg4 : _root->children()) {

    //                 }
    //             }
    //         }
    //     }
    // }
}

void Global::add_var(const std::string &identifier, Dval *val) const {
    _global_env->add(identifier, val);
}

void Global::add_env(Denv * env) const {
    _global_env->add_child(env);
}

Denv * Global::env() const {
        return _global_env;
}

Global *init() {
    return new Global();
}
