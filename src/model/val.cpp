#include "enum.h"
#include "val.h"
#include <cstring>
#include <iostream>
#include <utility>

#include "reserved.h"
/* =======dval======== */


// Constructor implementation
Dval::Dval(
    const int type,
    const long long_value,
    const float f,
    const std::byte byte_value,
    const int int_value,
    const short short_value,
    const char char_value,
    std::string value,
    std::string identifier,
    builtin *fun,
    const int count,
    std::vector<Dval *> *child)

    : _type(type),
      _long_value(long_value),
      _byte_value(byte_value),
      _int_value(int_value),
      _char_value(char_value),
      _short_value(short_value),
      _value(std::move(value)),
      _float_value(f),
      _arr_val(nullptr),
      _identifier(std::move(identifier)),
      _fun(fun),
      _count(count),
      _child(child) {
    _val_mutable = static_cast<std::byte>(IMMUTABLE);
    _val_nullable = static_cast<std::byte>(NON_NULLABLE);
    _package = nullptr;
    _parent = nullptr;
}

Dval::Dval(
    const int type,
    const long long_value,
    const float f,
    const std::byte byte_value,
    const int int_value,
    const short short_value,
    const char char_value,
    const std::string &value,
    const std::string &identifier,
    builtin *fun,
    const int count,
    std::vector<Dval *> *child,
    int val_mutable,
    int val_nullable) {
    _type = type;
    _long_value = long_value;
    _float_value = f;
    _byte_value = byte_value;
    _int_value = int_value;
    _short_value = short_value;
    _char_value = char_value;
    _value = value;
    _arr_val = nullptr,
            _identifier = identifier;
    _fun = fun;
    _count = count;
    _child = child;
    _val_mutable = static_cast<std::byte>(val_mutable);
    _val_nullable = static_cast<std::byte>(val_nullable);
    _package = nullptr;
    _parent = nullptr;
}

Dval::Dval(
    const int type,
    const long long_value,
    const float f,
    const std::byte byte_value,
    const int int_value,
    const short short_value,
    const char char_value,
    const std::string &value,
    std::vector<Dval *> *arr_val,
    const std::string &identifier,
    builtin *fun,
    const int count,

    std::vector<Dval *> *child,
    int val_mutable,
    int val_nullable,
    Package *package,
    Dval *parent) {
    _type = type;
    _long_value = long_value;
    _float_value = f;
    _byte_value = byte_value;
    _int_value = int_value;
    _short_value = short_value;
    _char_value = char_value;
    _value = value;
    _arr_val = arr_val;
    _identifier = identifier;
    _fun = fun;
    _count = count;
    _child = child;
    _val_mutable = static_cast<std::byte>(val_mutable);
    _val_nullable = static_cast<std::byte>(val_nullable);
    _package = package;
    _parent = parent;
}

Dval::Dval() {
    _type = 0;
    _long_value = 0;
    _float_value = 0;
    _value = "";
    _byte_value = static_cast<std::byte>(0);
    _int_value = 0;
    _short_value = 0;
    _char_value = 0;
    _arr_val = nullptr;
    _identifier = "";
    _fun = nullptr;
    _count = 0;
    _child = nullptr;
    _val_mutable = static_cast<std::byte>(IMMUTABLE);
    _val_nullable = static_cast<std::byte>(NON_NULLABLE);
    _package = nullptr;
    _parent = nullptr;
}

Dval::Dval(const Dval &other)
    : _type(other._type),
      _long_value(other._long_value),
      _byte_value(other._byte_value),
      _int_value(other._int_value),
      _char_value(other._char_value),
      _short_value(other._short_value),
      _value(other._value),
      _identifier(other._identifier),
      _fun(other._fun),
      _count(other._count),
      _child(new std::vector<Dval *>(other.child() == nullptr ? std::vector<Dval *>() : *other.child())) {
    if (other._child != nullptr && other._count > 0) {
        for (int i = 0; i < other._count; ++i) {
        }
    }

    _arr_val = new std::vector<Dval *>(other._arr_val == nullptr ? std::vector<Dval *>() : *other._arr_val);
    _float_value = 0;
    _val_mutable = other._val_mutable;
    _val_nullable = other._val_nullable;
    _package = nullptr;
    _parent = nullptr;
};

// Destructor implementation
Dval::~Dval() {
    delete _child;
}

// Accessor method for type
int Dval::type() const {
    return _type;
}

// Accessor method for value
std::string Dval::value() const {
    return _value;
}

// Accessor method for identifier
std::string Dval::identifier() const {
    return _identifier;
}

// Accessor method for function pointer
builtin *Dval::fun() const {
    return _fun;
}

// Accessor method for count
int Dval::count() const {
    return _count;
}

// Accessor method for child
std::vector<Dval *> *Dval::child() const {
    return _child;
}

long Dval::long_value() const {
    return _long_value;
}

std::string Dval::err() const {
    return _err;
}

int Dval::val_mutable() const {
    return static_cast<int>(_val_mutable);
}

int Dval::val_nullable() const {
    return static_cast<int>(_val_nullable);
}

Package *Dval::package() const {
    return _package;
}

Dval *Dval::parent() const {
    return _parent;
}

float Dval::float_value() const {
    return _float_value;
}

std::byte Dval::byte_value() const {
    return _byte_value;
}

char Dval::char_value() const {
    return _char_value;
}

short Dval::short_value() const {
    return _short_value;
}

std::vector<Dval *> *Dval::arr_val() const {
    return _arr_val;
}

void Dval::set_arr_val(std::vector<Dval *> *arr_val) {
    _arr_val = arr_val;
}

void Dval::set_value(std::string value) {
    _value = std::move(value);
}

void Dval::set_long_value(const long long_value) {
    _long_value = long_value;
}

void Dval::set_float(const float f) {
    _float_value = f;
}

void Dval::print_value() {
    switch (this->type()) {
        case DVAL_INT:
            std::cout << "Integer: " << this->identifier() << " = " << this->_int_value << std::endl;
            break;
        case DVAL_BYTE:
            std::cout << "Byte: " << this->identifier() << " = " << static_cast<int>(this->_byte_value) << std::endl;
            break;
        case DVAL_SHORT:
            std::cout << "Short: " << this->identifier() << " = " << this->_short_value << std::endl;
            break;
        case DVAL_LONG:
            std::cout << "Long: " << this->identifier() << " = " << this->_long_value << std::endl;
            break;
        case DVAL_CHAR:
            std::cout << "Char: " << this->identifier() << " = " << this->_char_value << std::endl;
            break;
        case DVAL_BOOL:
            std::cout << "Bool: " << this->identifier() << " = " << (this->_value == "true" ? "true" : "false") <<
                    std::endl;
            break;
        case DVAL_STR:
            std::cout << "String: " << this->identifier() << " = " << this->_value << std::endl;
            break;
        case DVAL_FLOAT:
            std::cout << "Float: " << this->identifier() << " = " << this->_float_value << std::endl;
            break;
        case DVAL_SYM:
            std::cout << "Identifier: " << this->identifier() << " = " << this->_identifier << std::endl;
            break;
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}

int Dval::int_value() const {
    return _int_value;
}

void Dval::add_child(Dval *dval) const {
    _child->push_back(dval);
}

void Dval::set_fun(builtin *builtin) {
    _fun = builtin;
}

bool Dval::bool_value() const {
    return _value == "true";
}

void Dval::set_int_value(const int i) {
    _int_value = i;
}

void Dval::set_short_value(const int i) {
    _short_value = static_cast<short>(i);
}

void Dval::set_char_value(const int i) {
    _char_value = static_cast<char>(i);
}

void Dval::set_byte_value(const std::byte byte) {
    _byte_value = byte;
}

Denv::Denv(const int count) {
    _identifier_str = new std::unordered_map<std::string, const Dval *>;
    _identifiers = new std::unordered_map<const Dval *, Dval *>;
    _count = count;
    _children = new std::vector<Denv *>;
    _parent = nullptr;
}

Denv::Denv() {
    _count = 0;
    _identifiers = new std::unordered_map<const Dval *, Dval *>;
    _identifier_str = new std::unordered_map<std::string, const Dval *>;
    _children = new std::vector<Denv *>;
    _parent = nullptr;
}

// Destructor implementation
Denv::~Denv() {
    // Clean up resources if needed
    delete[] _identifiers; // Delete the identifier array if necessary
}

// Accessor method for count
int Denv::count() const {
    return _count;
}

void Denv::set_count(const int count) {
    _count = count;
}

std::unordered_map<const Dval *, Dval *> *Denv::identifiers() const {
    return _identifiers;
}

std::unordered_map<std::string, const Dval *> *Denv::identifiers_str() const {
    return _identifier_str;
}

void Denv::add(const Dval *identifier, Dval *val) {
    _identifier_str->insert(std::make_pair(identifier->identifier(), identifier));
    _identifiers->insert(std::make_pair(identifier, val));
    _count = count() + 1;
}

Dval *Denv::get(const Dval *identifier) const {
    if (!_identifiers->contains(identifier)) {
        return nullptr;
    }

    return _identifiers->at(identifier);
}

std::vector<Denv *> *Denv::children(int index) const {
    return _children;
}

void Denv::add_child(Denv *child) const {
    _children->push_back(child);
}

Denv *Denv::parent() const {
    return _parent;
}

void Denv::set_parent(Denv *parent) {
    _parent = parent;
}

void Denv::add(const std::string &identifier, Dval *val) {
    _count = count() + 1;
    const Dval *id = dval::dval_identifier(identifier);
    _identifier_str->insert(std::make_pair(identifier, id));
    _identifiers->insert(std::make_pair(id, val));
}

Dval *Denv::get(const std::string &identifier) const {
    if (!_identifier_str->contains(identifier)) {
        return nullptr;
    }
    const Dval *ident = _identifier_str->at(identifier);
    return get(ident);
}


namespace dval {
    Dval *dval_package(Package *pkg) {
        Dval *v = new Dval(DVAL_PACK, 0, 0,
                           static_cast<std::byte>(0), 0, 0, 0,
                           pkg->name(), nullptr, pkg->name(), nullptr, 0,
                           nullptr, NON_NULLABLE, IMMUTABLE, pkg,
                           nullptr);
        return v;
    }

    Dval *dval_import(const std::string &identifier, Denv *env) {
        Dval *v = new Dval(DVAL_IMPORT, 0, 0,
                           static_cast<std::byte>(0), 0, 0, 0,
                           identifier, identifier, nullptr, 0,
                           nullptr);
        return v;
    }

    Dval *dval_gen(const std::string &val, const std::string &type,
                   const std::string &identifier, const int val_mutable,
                   const int val_nullable) {
        if (type == D_BOOL) {
            return dval_bool(val, identifier, val_mutable, val_nullable);
        }
        if (type == D_FLOAT) {
            const float f = std::stof(val);
            return dval_float(f, identifier, val_mutable, val_nullable);
        }
        if (type == D_INT) {
            const long x = std::stol(val);
            return dval_int(x, identifier, val_mutable, val_nullable);
        }
        if (type == D_BYTE) {
            const std::byte b = static_cast<std::byte>(std::stoi(val));
            return dval_byte(b, identifier, val_mutable, val_nullable);
        }
        if (type == D_SHORT) {
            const short x = static_cast<short>(std::stoi(val));
            return dval_short(x, identifier, val_mutable, val_nullable);
        }
        if (type == D_LONG) {
            const long x = std::stol(val);
            return dval_long(x, identifier, val_mutable, val_nullable);
        }
        if (type == D_CHAR) {
            const char c = val[0];
            return dval_char(c, identifier, val_mutable, val_nullable);
        }
        if (type == D_STRING) {
            return dval_str(val, identifier, val_mutable, val_nullable);
        }


        return nullptr;
    }

    Dval *dval_float(const float f, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_FLOAT, 0, f, static_cast<std::byte>(0), 0, 0, '\0', "", nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_op(std::string op) {
        Dval *val = new Dval(DVAL_FUN, 0, 0, static_cast<std::byte>(0), 0, 0, 0, "", std::move(op), nullptr, 0,
                             new std::vector<Dval *>);

        if (op == D_ADD) {
            val->set_fun(&add_builtin);
        } else if (op == D_SUB) {
            val->set_fun(&sub_builtin);
        } else if (op == D_MUL) {
            val->set_fun(&mul_builtin);
        } else if (op == D_DIV) {
            val->set_fun(&div_builtin);
        } else if (op == D_MOD) {
            val->set_fun(&mod_builtin);
        } else if (op == D_LSHIFT) {
            val->set_fun(&lshift_builtin);
        } else if (op == D_RSHIFT) {
            val->set_fun(&rshift_builtin);
        }
        return val;
    }

    Dval *dval_err(const char *str) {
        return new Dval(DVAL_ERR, 0, 0, static_cast<std::byte>(0), 0, 0, 0, "", str, nullptr, 0, nullptr);
    }

    /* Construct a pointer to a new Symbol dval */
    Dval *dval_identifier(const std::string &s) {
        Dval *v = new Dval(DVAL_SYM, 0, 0, static_cast<std::byte>(0), 0, 0, 0, "", s, nullptr, 0, nullptr);
        return v;
    }

    Dval *dval_int(const long x, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_INT, 0, 0.0, static_cast<std::byte>(0),
                        static_cast<int>(x), 0, '\0', "", nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_byte(const std::byte x, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_BYTE, 0, 0.0, x, 0, 0, '\0', "", nullptr, identifier, nullptr, 0, nullptr, val_mutable,
                        val_nullable, nullptr, nullptr);
    }

    Dval *dval_short(const short x, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_SHORT, x, 0.0, static_cast<std::byte>(0), 0, x, '\0', "", nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_long(const long x, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_LONG, x, 0.0, static_cast<std::byte>(0), 0, 0, '\0', "", nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_char(const char x, const std::string &identifier, const int val_mutable, const int val_nullable) {
        return new Dval(DVAL_CHAR, 0, 0.0, static_cast<std::byte>(0), 0, 0, x, "", nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_bool(const std::string &val, const std::string &identifier, const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_BOOL, 0, 0.0, static_cast<std::byte>(0), 0, 0, '\0', val, nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_bool(const bool &val, const std::string &identifier, const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_BOOL, val, 0.0, static_cast<std::byte>(0), 0, 0, '\0', val ? "true" : "false", nullptr,
                        identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    Dval *dval_str(const std::string &val, const std::string &identifier, const int val_mutable,
                   const int val_nullable) {
        return new Dval(DVAL_STR, 0, 0.0, static_cast<std::byte>(0), 0, 0, '\0', val, nullptr, identifier, nullptr, 0,
                        nullptr,
                        val_mutable, val_nullable, nullptr, nullptr);
    }

    void dval_del(Dval *v) {
        switch (v->type()) {
            /* Do nothing special for number type */
            case DVAL_INT:
                break;

            /* For Err or Sym free the string data */
            case DVAL_ERR:
                break;
            case DVAL_SYM:
                break;

            /* If Sexpr then delete all elements inside */
            case DVAL_BOOL:
                break;

            case DVAL_FUN:
                break;
            default: break;
        }

        /* Free the memory allocated for the "dval" struct itself */
        free(v);
    }

    /* =======denv======== */

    Denv *denv_new() {
        Denv *e = new Denv(0);
        return e;
    }

    void denv_put(Denv *e, const Dval *k, Dval *v) {
        e->add(k, v);
        e->set_count(e->count() + 1);
    }
}
