//
// Created by napbad on 9/10/24.
//

#ifndef PACK_H
#define PACK_H
#include <string>
#include <vector>

#include "val.h"
class Dval;
class Denv;

class Package {
    std::string _name;
    std::vector<Package*>* _children;
    Dval *_value;
    Denv *_env;

public:
    Package(const std::string &name, const std::vector<Package*>& children) ;

    explicit Package(const std::string &name);

    [[nodiscard]] std::string name() const;
    [[nodiscard]] std::vector<Package *> *children() const;
    void add_child(const Package *child) const;

    [[nodiscard]] bool exists_package(const std::string &packageName) const;
    bool is_child_exists(const std::string & string);
    bool child_exists_package(const std::vector<std::string> &packageName);

    [[nodiscard]] Package* has_child(std::vector<std::string>::const_reference at) const;

    void add_package(std::vector<std::string> *pkgs) const;
};

#endif //PACK_H
