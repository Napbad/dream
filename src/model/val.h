#pragma once

#ifndef DVAL_H
#define DVAL_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Package.h"

class Denv;
class Dval;
class Package;

// Helper functions
namespace dval {
    Dval *dval_identifier(const std::string &s);

    Dval *dval_int(long x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_byte(std::byte x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_short(short x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_long(long x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_char(char x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_bool(const std::string &val, const std::string &string, int val_mutable, int val_nullable);

    Dval *dval_str(const std::string &val, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_package(Package *pkg);

    Dval *dval_import(const std::string &identifier, Denv *env);

    Dval *dval_gen(const std::string &val, const std::string &type, const std::string &identifier, int val_mutable,
                   int val_nullable);

    Dval *dval_float(float f, const std::string &identifier, int val_mutable, int val_nullable);

    void denv_add_int(const std::string &num, const std::string &identifier, Denv *env);

    void denv_add_bool(const std::string &val, const std::string &identifier, Denv *env);
}

// Define the type for built-in functions
typedef Dval *(*builtin)(Denv *, Dval *);

// dval Class
class Dval {
    int _type;
    long _long_value;
    std::byte _byte_value;
    int _int_value;
    char _char_value;
    short _short_value;
    std::string _value;
    float _float_value;
    std::vector<Dval *> *_arr_val;

    std::string _identifier;
    std::string _err;
    builtin *_fun;
    int _count;
    std::vector<Dval *> *_child;
    Package *_package;
    Dval *_parent;
    std::byte _val_mutable;
    std::byte _val_nullable;

public:
    // Constructors
    Dval(int type,
         long num,
         float f,
         std::byte byte_value,
         int int_value,
         short short_value,
         char char_value,
         std::string value,
         std::string identifier,
         builtin *fun,
         int count,
         std::vector<Dval *> *child);

    Dval(int type,
         long num,
         float f,
         std::byte byte_value,
         int int_value,
         short short_value,
         char char_value,
         const std::string &value,
         const std::string &identifier,
         builtin *fun,
         int count,
         std::vector<Dval *> *child,
         int val_mutable,
         int val_nullable);

    Dval(int type,
         long num,
         float f,
         std::byte byte_value,
         int int_value,
         short short_value,
         char char_value,
         const std::string &value,
         std::vector<Dval*> *arr_val,
         const std::string &identifier,
         builtin *fun,
         int count,
         std::vector<Dval *> *child,
         int val_mutable,
         int val_nullable,
         Package *package,
         Dval *parent);

    Dval();

    Dval(const Dval &other);

    // Destructor
    ~Dval();

    // Accessor methods
    [[nodiscard]] int type() const;

    [[nodiscard]] std::string value() const;

    [[nodiscard]] std::string identifier() const;

    [[nodiscard]] builtin *fun() const;

    [[nodiscard]] int count() const;

    [[nodiscard]] std::vector<Dval *> *child() const;

    [[nodiscard]] long long_value() const;

    [[nodiscard]] std::string err() const;

    [[nodiscard]] int val_mutable() const;

    [[nodiscard]] int val_nullable() const;

    [[nodiscard]] Package *package() const;

    [[nodiscard]] Dval *parent() const;

    [[nodiscard]] float float_value() const;

    [[nodiscard]] std::vector<Dval *> *arr_val() const;
    void set_arr_val(std::vector<Dval *> *arr_val);
    
    void set_value(std::string value);

    void set_num(long num);

    void set_float(float f);

    void print_value();
};

// denv Class
class Denv {
    int _count;
    std::unordered_map<std::string, const Dval *> *_identifier_str;
    std::unordered_map<const Dval *, Dval *> *_identifiers;
    std::vector<Denv *> *_children;
    Denv *_parent;

public:
    // Constructors
    explicit Denv(int count);

    Denv();

    // Destructor
    ~Denv();

    // Accessor methods
    [[nodiscard]] int count() const;

    void set_count(int count);

    [[nodiscard]] std::unordered_map<const Dval *, Dval *> *identifiers() const;

    [[nodiscard]] std::unordered_map<std::string, const Dval *> *identifiers_str() const;

    void add(const Dval *identifier, Dval *val);

    [[nodiscard]] Dval *get(const Dval *identifier) const;

    [[nodiscard]] std::vector<Denv *> *children(int index) const;

    void add_child(Denv *child) const;

    [[nodiscard]] Denv *parent() const;

    void set_parent(Denv *parent);

    void add(const std::string &identifier, Dval *val);

    [[nodiscard]] Dval *get(const std::string &identifier) const;
};
#endif
