//
// Created by napbad on 9/10/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H
#include "Package.h"
#include "val.h"

class Global {
    Package *_root;
    Denv *_global_env;

public:
    Global() {
        _root = new Package("root", {});
        _global_env = new Denv();
    }

    void add_package(const Package *package) const;
    [[nodiscard]] bool is_package_exists(const std::string &packageName) const;
    [[nodiscard]] Package *package() const;
    [[nodiscard]] Package *get_package(const std::string &packageName) const;
    void add_package(const std::string & string) const;

    void add_var(const std::string &identifier, Dval *val) const;
    void add_env(Denv *) const;

    [[nodiscard]] Denv * env() const;

};

Global *init();

#endif //GLOBAL_H
