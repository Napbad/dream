#pragma once

#ifndef DVAL_H
#define DVAL_H

#include <string>
#include <unordered_map>
#include <vector>
#include <tree/ParseTree.h>

#include "Package.h"

class Denv;
class Dval;
class Package;

inline enum {
    FUN_ARGS,
    FUN_RETURN,
    FUN_BODY
} FUN_ELEMENT_POS;

// Helper functions
namespace dval {
    Dval *dval_identifier(const std::string &s);

    Dval * dval_identifier_call(const std::string & val);

    Dval *dval_int(int x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_byte(std::byte x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_short(short x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_long(long x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_char(char x, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_bool(const std::string &val, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_bool(const bool &val, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_str(const std::string &val, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_float(float f, const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_op(std::string op);

    Dval *dval_int_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_byte_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_short_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_long_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_char_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_bool_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_float_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_str_arr(const std::string &identifier, int val_mutable, int val_nullable);

    Dval *dval_package(Package *pkg);

    Dval *dval_import(const std::string &identifier, Denv *env);

    Dval *dval_fun(const std::string &identifier);

    Dval *dval_fun_native(const std::string &identifier);

    Dval *dval_gen(const std::string &val, const std::string &type, const std::string &identifier, int val_mutable,
                   int val_nullable);

    Dval *dval_gen_default(const std::string &type, const std::string &identifier, int val_mutable,
                   int val_nullable);

    Dval *dval_array_gen(const std::string &type, const std::string &identifier, int val_mutable,
                         int val_nullable);

    Denv *dval_fun_get_args(const Dval* dval);

    Dval *dval_fun_get_body(const Dval* dval);

    Denv *dval_fun_get_return(const Dval* dval);

    void dval_fun_set_args(const Dval *sub, Dval* dval);

    void dval_fun_set_body(const Dval* sub, Dval* dval);

    void dval_fun_set_return(const Dval* sub, Dval* dval);

    void denv_add_int(const std::string &num, const std::string &identifier, Denv *env);

    void denv_add_bool(const std::string &val, const std::string &identifier, Denv *env);

    Dval *dval_err(const char *str);

    Dval * dval_err(const std::string & err);

    int get_type(const std::string & type);

    void call(const Dval * dval);

    Dval * dval_fun_block(const std::string &ident);
}

// Define the type for built-in functions
typedef Dval *(*builtin)(const Denv *, std::initializer_list<Dval *> vals);

// dval Class
class Dval {
    int _type;
    long _long_value;
    std::byte _byte_value;
    int _int_value;
    char _char_value;
    short _short_value;
    std::string _string_value;
    float _float_value;
    std::vector<Dval *> *_arr_val;

    std::any _any_value;

    std::string _identifier;
    std::string _err;
    builtin *_fun;
    int _count;

    std::vector<Dval *> *_child;
    Package *_package;
    Dval *_parent;
    Denv *_env;

    bool _val_mutable;
    bool _val_nullable;

public:
    // Constructors
    Dval(int type,
         long long_value,
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
         long long_value,
         float f,
         std::byte byte_value,
         int int_value,
         short short_value,
         char char_value,
         const std::string &string_value,
         const std::string &identifier,
         builtin *fun,
         int count,
         std::vector<Dval *> *child,
         int val_mutable,
         int val_nullable);

    Dval(int type,
         long long_value,
         float f,
         std::byte byte_value,
         int int_value,
         short short_value,
         char char_value,
         const std::string &string_value,
         std::vector<Dval *> *arr_val,
         const std::string &identifier,
         builtin *fun,
         int count,
         std::vector<Dval *> *child,
         int val_mutable,
         int val_nullable,
         Package *package,
         Dval *parent);

    explicit Dval(int type);

    Dval();

    Dval(const Dval &other);

    // Destructor
    ~Dval();

    // Accessor methods
    [[nodiscard]] int type() const;

    [[nodiscard]] std::string string_value() const;

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

    [[nodiscard]] std::byte byte_value() const;

    [[nodiscard]] char char_value() const;

    [[nodiscard]] short short_value() const;

    [[nodiscard]] std::vector<Dval *> *arr_val() const;

    [[nodiscard]] bool bool_value() const;

    [[nodiscard]] int int_value() const;

    [[nodiscard]] std::string get_string_value() const;

    [[nodiscard]] float get_float_value() const;

    [[nodiscard]] long get_long_value() const;

    [[nodiscard]] int get_int_value() const;

    [[nodiscard]] short get_short_value() const;

    [[nodiscard]] char get_char_value() const;

    [[nodiscard]] std::byte get_byte_value() const;

    [[nodiscard]] bool is_mutable() const;

    [[nodiscard]] bool is_nullable() const;

    [[nodiscard]] Denv *env() const;

    [[nodiscard]] std::any any_value() const;

    void set_any_value(const std::any &any_value);

    void set_env(Denv *env);

    void set_arr_val(std::vector<Dval *> *arr_val);

    void set_string_value(std::string value);

    void set_long_value(long long_value);

    void set_float(float f);

    void print_value();

    void add_child(Dval *dval);

    void set_fun(builtin *builtin);

    void set_int_value(int i);

    void set_short_value(int i);

    void set_char_value(int i);

    void set_byte_value(std::byte byte);

    void set_val_nullable(bool cond);

    void set_val_mutable(bool cond);

    void set_identifier(const std::string & string);

    void set_value(const std::string &val);

    void set_parent(Dval * dval);
};

// denv Class
class Denv {
    int _count;
    std::string _identifier;
    std::unordered_map<std::string, Dval *> *_identifiers;
    std::vector<Denv *> *_children;
    Denv *_parent;

public:
    // Constructors
    explicit Denv(int count);

    explicit Denv(const std::string &identifier);

    Denv();

    // Destructor
    ~Denv();

    // Accessor methods
    [[nodiscard]] int count() const;

    [[nodiscard]] Denv *children(int index) const;

    [[nodiscard]] std::vector<Denv *> *children() const;

    [[nodiscard]] Denv *parent() const;

    [[nodiscard]] Dval *get(const std::string &identifier) const;

    void set_count(int count);

    void add_child(Denv *child) const;

    void set_parent(Denv *parent);

    void add(const std::string &identifier, Dval *val);

    void remove_child(const Denv * denv) const;
};
#endif
