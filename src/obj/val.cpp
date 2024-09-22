#include "./common/dval_enum.h"
#include "val.h"
#include <cfloat>
#include <iostream>
#include <climits>
#include <complex>
#include <utility>

#include "./common/reserved.h"
#include "common/native_fun.h"
#include "util/parse_util.h"
/* =======dval======== */

using namespace std;

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
      _string_value(std::move(value)),
      _float_value(f),
      _arr_val(nullptr),
      _identifier(std::move(identifier)),
      _fun(fun),
      _count(count),
      _child(child) {
    _val_mutable = IMMUTABLE;
    _val_nullable = NON_NULLABLE;
    _package = nullptr;
    _parent = nullptr;
    _env = nullptr;
}

Dval::Dval(
    const int type,
    const long long_value,
    const float f,
    const std::byte byte_value,
    const int int_value,
    const short short_value,
    const char char_value,
    const std::string &string_value,
    const std::string &identifier,
    builtin *fun,
    const int count,
    std::vector<Dval *> *child,
    const int val_mutable,
    const int val_nullable) {
    _type = type;
    _long_value = long_value;
    _float_value = f;
    _byte_value = byte_value;
    _int_value = int_value;
    _short_value = short_value;
    _char_value = char_value;
    _string_value = string_value;
    _arr_val = nullptr;
    _identifier = identifier;
    _fun = fun;
    _count = count;
    _child = child;
    _val_mutable = val_mutable == MUTABLE;
    _val_nullable = val_nullable == NULLABLE;
    _package = nullptr;
    _parent = nullptr;
    _env = nullptr;
}

Dval::Dval(
    const int type,
    const long long_value,
    const float f,
    const std::byte byte_value,
    const int int_value,
    const short short_value,
    const char char_value,
    const std::string &string_value,
    std::vector<Dval *> *arr_val,
    const std::string &identifier,
    builtin *fun,
    const int count,
    std::vector<Dval *> *child,
    const int val_mutable,
    const int val_nullable,
    Package *package,
    Dval *parent) {
    _type = type;
    _long_value = long_value;
    _float_value = f;
    _byte_value = byte_value;
    _int_value = int_value;
    _short_value = short_value;
    _char_value = char_value;
    _string_value = string_value;
    _arr_val = arr_val;
    _identifier = identifier;
    _fun = fun;
    _count = count;
    _child = child;
    _val_mutable = val_mutable;
    _val_nullable = val_nullable;
    _package = package;
    _parent = parent;
    _env = nullptr;
}

Dval::Dval(const int type): _long_value(0),
                            _byte_value(),
                            _int_value(0),
                            _char_value(0),
                            _short_value(0),
                            _float_value(0),
                            _arr_val(nullptr),
                            _fun(nullptr),
                            _count(0),
                            _child(nullptr),
                            _package(nullptr),
                            _parent(nullptr),
                            _env(nullptr),
                            _val_mutable(false),
                            _val_nullable(false) {
    _type = type;
}

Dval::Dval() {
    _type = -1;
    _long_value = 0;
    _float_value = 0;
    _string_value = "";
    _byte_value = static_cast<std::byte>(0);
    _int_value = 0;
    _short_value = 0;
    _char_value = 0;
    _arr_val = nullptr;
    _identifier = "";
    _fun = nullptr;
    _count = 0;
    _child = new std::vector<Dval *>;
    _val_mutable = IMMUTABLE;
    _val_nullable = NON_NULLABLE;
    _package = nullptr;
    _parent = nullptr;
    _env = nullptr;
}

Dval::Dval(const Dval &other)
    : _type(other._type),
      _long_value(other._long_value),
      _byte_value(other._byte_value),
      _int_value(other._int_value),
      _char_value(other._char_value),
      _short_value(other._short_value),
      _string_value(other._string_value),
      _identifier(other._identifier),
      _fun(other._fun),
      _count(other._count) {

    if (other.arr_val() != nullptr) {
        _arr_val = new vector<Dval *>;
        for (const auto val : *other._arr_val) {
            _arr_val->push_back(new Dval(*val));
        }
    } else {
        _arr_val = nullptr;
    }
    _float_value = 0;
    _val_mutable = other._val_mutable;
    _val_nullable = other._val_nullable;
    _package = other._package;
    _parent = other._parent;
    _env = other._env;

    _child = new std::vector<Dval *>();
    if (other._child != nullptr && other._count > 0) {
        for (int i = 0; i < other._count; ++i) {
            if (other._child->at(i) == nullptr) {
                _child->push_back(nullptr);
                continue;
            }
            _child->push_back(new Dval(*other._child->at(i)));
        }
    }
};

// Destructor implementation
Dval::~Dval() {
    for (const auto &child: *_child) {
        delete child;
    }

    for (const auto &arr_val: *_arr_val) {
        delete arr_val;
    }

    delete _child;
    delete _arr_val;
}

// Accessor method for type
int Dval::type() const {
    return _type;
}

// Accessor method for value
std::string Dval::string_value() const {
    return _string_value;
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

void Dval::set_string_value(std::string value) {
    _string_value = std::move(value);
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
            std::cout << "Bool: " << this->identifier() << " = " << (this->_string_value == "true" ? "true" : "false")
                    <<
                    std::endl;
            break;
        case DVAL_STR:
            std::cout << "String: " << this->identifier() << " = " << this->_string_value << std::endl;
            break;
        case DVAL_FLOAT:
            std::cout << "Float: " << this->identifier() << " = " << this->_float_value << std::endl;
            break;
        case DVAL_IDENT:
            std::cout << "Identifier: " << this->identifier() << " = " << this->_identifier << std::endl;
            break;
        case DVAL_INT_ARR:
            std::cout << "Int Array: " << this->identifier() << " = [";
            for (int i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << this->_arr_val->at(i)->int_value();
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_BYTE_ARR:
            std::cout << "Byte Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << static_cast<int>((*this->_arr_val)[i]->_byte_value);
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_SHORT_ARR:
            std::cout << "Short Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << (*this->_arr_val)[i]->_short_value;
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_LONG_ARR:
            std::cout << "Long Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << (*this->_arr_val)[i]->_long_value;
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_CHAR_ARR:
            std::cout << "Char Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << (*this->_arr_val)[i]->_char_value;
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_BOOL_ARR:
            std::cout << "Bool Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << ((*this->_arr_val)[i]->_string_value == "true" ? "true" : "false");
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_STR_ARR:
            std::cout << "String Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << (*this->_arr_val)[i]->_string_value;
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        case DVAL_FLOAT_ARR:
            std::cout << "Float Array: " << this->identifier() << " = [";
            for (size_t i = 0; i < this->_arr_val->size(); ++i) {
                std::cout << (*this->_arr_val)[i]->_float_value;
                if (i != this->_arr_val->size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
            break;
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}

int Dval::int_value() const {
    return _int_value;
}

void Dval::add_child(Dval *dval) {
    _child->push_back(dval);
    _count++;
}

void Dval::set_fun(builtin *builtin) {
    _fun = builtin;
}

bool Dval::bool_value() const {
    return _string_value == "true";
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

void Dval::set_val_nullable(const bool cond) {
    _val_nullable = cond;
}

void Dval::set_val_mutable(const bool cond) {
    _val_mutable = cond;
}

void Dval::set_identifier(const std::string &string) {
    _identifier = string;
}

void Dval::set_value(const std::string &val) {
    switch (_type) {
        case DVAL_INT:
            _int_value = std::stoi(val);
            break;
        case DVAL_BYTE:
            _byte_value = static_cast<std::byte>(std::stoi(val));
            break;
        case DVAL_SHORT:
            _short_value = static_cast<short>(std::stoi(val));
            break;
        case DVAL_LONG:
            _long_value = std::stol(val);
            break;
        case DVAL_CHAR:
            _char_value = static_cast<char>(std::stoi(val));
            break;
        case DVAL_BOOL:
        case DVAL_STR:
            _string_value = val;
            break;
        case DVAL_FLOAT:
            _float_value = std::stof(val);
            break;
        case DVAL_IDENT:
            _identifier = val;
            break;
        default:
            break;
    }
}

void Dval::set_parent(Dval *dval) {
    _parent = dval;
}

void Dval::set_fun_args(Denv *denv) const {
    _child->at(FUN_ARGS)->set_env(denv);
}

void Dval::set_fun_return(Denv *denv) const {
    _child->at(FUN_RETURN)->set_env(denv);
}

void Dval::set_child(Dval *dval) {
    delete _child;
    _child = new std::vector<Dval *>;
    _child->push_back(dval);
    _count = 1;
}

std::string Dval::get_string_value() const {
    switch (_type) {
        case DVAL_INT:
            return std::to_string(_int_value);
        case DVAL_BYTE:
            return std::to_string(static_cast<int>(_byte_value));
        case DVAL_SHORT:
            return std::to_string(_short_value);
        case DVAL_LONG:
            return std::to_string(_long_value);
        case DVAL_CHAR:
            return std::to_string(_char_value);
        case DVAL_BOOL:
        case DVAL_STR:
            return _string_value;
        case DVAL_FLOAT:
            return std::to_string(_float_value);
        case DVAL_IDENT:
            return _identifier;
        default:
            return "";
    }
}

float Dval::get_float_value() const {
    switch (_type) {
        case DVAL_INT:
            return static_cast<float>(_int_value);
        case DVAL_BYTE:
            return static_cast<float>(_byte_value);
        case DVAL_SHORT:
            return _short_value;
        case DVAL_LONG:
            return static_cast<float>(_long_value);
        case DVAL_CHAR:
            return _char_value;
        case DVAL_BOOL:
            return _string_value == "true" ? 1 : 0;
        case DVAL_STR:
            return std::stof(_string_value);
        case DVAL_FLOAT:
            return _float_value;
        case DVAL_IDENT:
            return FLT_MIN;
        default:
            return 0;
    }
}

long Dval::get_long_value() const {
    switch (_type) {
        case DVAL_INT:
            return _int_value;
        case DVAL_BYTE:
            return static_cast<long>(_byte_value);
        case DVAL_SHORT:
            return _short_value;
        case DVAL_LONG:
            return _long_value;
        case DVAL_CHAR:
            return _char_value;
        case DVAL_BOOL:
            return _string_value == "true" ? 1 : 0;
        case DVAL_STR:
            return std::stol(_string_value);
        case DVAL_FLOAT:
            return static_cast<int>(_float_value);
        case DVAL_IDENT:
            return LONG_MIN;
        default:
            return 0;
    }
}

int Dval::get_int_value() const {
    switch (_type) {
        case DVAL_INT:
            return _int_value;
        case DVAL_BYTE:
            return static_cast<int>(_byte_value);
        case DVAL_SHORT:
            return _short_value;
        case DVAL_LONG:
            return _int_value;
        case DVAL_CHAR:
            return _char_value;
        case DVAL_BOOL:
            return _string_value == "true" ? 1 : 0;
        case DVAL_STR:
            return std::stoi(_string_value);
        case DVAL_FLOAT:
            return static_cast<int>(_float_value);
        case DVAL_IDENT:
            return INT_MIN;
        default:
            return 0;
    }
}

short Dval::get_short_value() const {
    switch (_type) {
        case DVAL_INT:
            return static_cast<short>(_int_value);
        case DVAL_BYTE:
            return static_cast<short>(_byte_value);
        case DVAL_SHORT:
            return _short_value;
        case DVAL_CHAR:
            return _char_value;
        case DVAL_BOOL:
            return _string_value == "true" ? 1 : 0;
        case DVAL_STR:
            return static_cast<short>(std::stoi(_string_value));
        case DVAL_FLOAT:
            return static_cast<short>(_float_value);
        case DVAL_IDENT:
            return SHRT_MIN;
        default:
            return 0;
    }
}

char Dval::get_char_value() const {
    switch (_type) {
        case DVAL_INT:
            return static_cast<char>(_int_value);
        case DVAL_BYTE:
            return static_cast<char>(_byte_value);
        case DVAL_SHORT:
            return static_cast<char>(_short_value);
        case DVAL_LONG:
            return static_cast<char>(_long_value);
        case DVAL_CHAR:
            return _char_value;
        case DVAL_BOOL:
            return _string_value == "true" ? 1 : 0;
        case DVAL_STR:
            return _string_value.empty() ? '\0' : _string_value.at(0);
        case DVAL_FLOAT:
            return static_cast<char>(_float_value);
        case DVAL_IDENT:
            return '\0';
        default:
            return 0;
    }
}

std::byte Dval::get_byte_value() const {
    switch (_type) {
        case DVAL_INT:
            return static_cast<std::byte>(_int_value);
        case DVAL_BYTE:
            return _byte_value;
        case DVAL_SHORT:
            return static_cast<std::byte>(_short_value);
        case DVAL_LONG:
            return static_cast<std::byte>(_long_value);
        case DVAL_CHAR:
            return static_cast<std::byte>(_char_value);
        case DVAL_BOOL:
            return _string_value == "true" ? static_cast<std::byte>(1) : static_cast<std::byte>(0);
        case DVAL_STR:
            return _string_value.empty() ? static_cast<std::byte>(1) : static_cast<std::byte>(_string_value.at(0));
        case DVAL_FLOAT:
            return static_cast<std::byte>(_float_value);
        case DVAL_IDENT:
        default:
            return static_cast<std::byte>(0);
    }
}

bool Dval::is_mutable() const {
    return _val_mutable;
}

bool Dval::is_nullable() const {
    return _val_mutable;
}

Denv *Dval::env() const {
    return _env;
}

std::any Dval::any_value() const {
    return _any_value;
}

void Dval::set_any_value(const std::any &any_value) {
    _any_value = any_value;
}

void Dval::set_env(Denv *env) {
    _env = env;
}

Denv::Denv(const int count) {
    _identifiers_index = new std::vector<std::string>;
    _identifiers = new std::unordered_map<std::string, Dval *>;
    _count = count;
    _children = new std::vector<Denv *>;
    _parent = nullptr;
}

Denv::Denv(const std::string &identifier) {
    _identifiers_index = new std::vector<std::string>;
    _identifiers = new std::unordered_map<std::string, Dval *>;
    _identifier = identifier;
    _count = 0;
    _children = new std::vector<Denv *>;
    _parent = nullptr;
}

Denv::Denv(const Denv *other) {
    _count = other->count();
    _identifier = other->_identifier;
    _identifiers = new std::unordered_map<std::string, Dval *>;
    _identifiers_index = new std::vector<std::string>;
    for (int i = 0; i < _count; i++) {
        _identifiers_index->push_back(other->_identifiers_index->at(i));
        _identifiers->insert({
            _identifiers_index->at(i),
            other->_identifiers->at(_identifiers_index->at(i))
        });
    }
    _children = new std::vector<Denv *>;
    for (int i = 0; i < other->children()->size(); i++) {
        add_child(new Denv(other->children(i)));
    }

    _parent = other->_parent;
}

Denv::Denv() {
    _count = 0;
    _identifiers_index = new std::vector<std::string>;
    _identifier = "";
    _identifiers = new std::unordered_map<std::string, Dval *>;
    _children = new std::vector<Denv *>;
    _parent = nullptr;
}

// Destructor implementation
Denv::~Denv() {
    // Clean up resources if needed
    delete _identifiers; // Delete the identifier array if necessary
    delete _identifiers_index;
    delete _children;
}

// Accessor method for count
int Denv::count() const {
    return _count;
}

void Denv::set_count(const int count) {
    _count = count;
}

Denv *Denv::children(const int index) const {
    return _children->at(index);
}

std::vector<Denv *> *Denv::children() const {
    return _children;
}

std::unordered_map<std::string, Dval *> *Denv::identifiers() const {
    return _identifiers;
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
    _identifiers_index->push_back(identifier);
    _count++;
    _identifiers->insert(std::pair(identifier, val));
}

void Denv::remove_child(const Denv *denv) const {
    for (auto it = _children->begin(); it != _children->end(); ++it) {
        if (*it == denv) {
            _children->erase(it);
            break;
        }
    }
}

void Denv::set(const std::string &ident, Dval *dval) const {
    _identifiers->at(ident) = dval;
}

Dval *Denv::get(const int idx) const {
    return _identifiers->at(_identifiers_index->at(idx));
}

Dval *Denv::get(const std::string &identifier) const {
    if (_identifiers->contains(identifier)) {
        return _identifiers->at(identifier);
    }

    if (_parent != nullptr) {
        return _parent->get(identifier);
    }

    return nullptr;
}


namespace dval {
    Dval *dval_package(Package *pkg) {
        Dval *v = new Dval(DVAL_PACK,
                           0,
                           0,
                           static_cast<std::byte>(0),
                           0,
                           0,
                           0,
                           pkg->name(),
                           nullptr,
                           pkg->name(),
                           nullptr,
                           0,
                           nullptr,
                           NON_NULLABLE,
                           IMMUTABLE,
                           pkg,
                           nullptr);
        return v;
    }

    Dval *dval_import(const std::string &identifier,
                      Denv *env) {
        Dval *v = new Dval(DVAL_IMPORT,
                           0,
                           0,
                           static_cast<std::byte>(0),
                           0,
                           0,
                           0,
                           identifier,
                           identifier,
                           nullptr,
                           0,
                           nullptr);
        return v;
    }

    Dval *dval_fun(const std::string &identifier) {
        Dval* val = new Dval(DVAL_FUN,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        identifier,
                        identifier,
                        nullptr,
                        3,
                        new std::vector<Dval *>(3));

        Dval* args = new Dval();
        args->set_env(new Denv);
        dval_fun_set_args(val, args);

        Dval* return_ = new Dval();
        return_->set_env(new Denv);
        dval_fun_set_return(val, return_);

        return val;
    }

    Dval *dval_fun_native(const std::string &identifier) {
        Dval *val = new Dval(DVAL_NATIVE_FUN,
                             0,
                             0,
                             static_cast<std::byte>(0),
                             0,
                             0,
                             0,
                             identifier,
                             identifier,
                             nullptr,
                             3,
                             new std::vector<Dval *>(3));
        auto tmp = native_fun::native_map;

        val->set_fun(&native_fun::native_map.at("__" + identifier));

        auto &&mapped = native_fun::native_map.at("__" + identifier);
        *mapped(nullptr, {nullptr});

        Dval* args = new Dval();
        args->set_env(new Denv);
        dval_fun_set_args(val, args);

        Dval* return_ = new Dval();
        return_->set_env(new Denv);
        dval_fun_set_return(val, return_);

        return val;
    }

    Dval *dval_gen(const std::string &val,
                   const std::string &type,
                   const std::string &identifier,
                   const int val_mutable,
                   const int val_nullable) {
        if (type == D_BOOL) {
            return dval_bool(val,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_FLOAT) {
            const float f = std::stof(val);
            return dval_float(f,
                              identifier,
                              val_mutable,
                              val_nullable);
        }
        if (type == D_INT) {
            const int x = std::stoi(val);
            return dval_int(x,
                            identifier,
                            val_mutable,
                            val_nullable);
        }
        if (type == D_BYTE) {
            const std::byte b = static_cast<std::byte>(std::stoi(val));
            return dval_byte(b,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_SHORT) {
            const short x = static_cast<short>(std::stoi(val));
            return dval_short(x,
                              identifier,
                              val_mutable,
                              val_nullable);
        }
        if (type == D_LONG) {
            const long x = std::stol(val);
            return dval_long(x,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_CHAR) {
            const char c = val[0];
            return dval_char(c,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_STRING) {
            return dval_str(val,
                            identifier,
                            val_mutable,
                            val_nullable);
        }
        if (type == D_IDENTIFIER) {
            return dval_identifier(identifier);
        }

        if (type == D_OPERATOR) {
            return dval_op(val);
        }

        if (type == D_IDENTIFIER_CALL) {
            Dval *dval = dval_identifier_call(val);
            return dval;
        }

        if (type == D_EXPR_CALL) {
            return dval_expr_call(val);
        }

        if (type == D_NATIVE) {
            return dval_fun_native(identifier);
        }

        if (type == D_FUN_ASSIGN) {
            return dval_fun_var_assign(identifier);
        }

        return nullptr;
    }

    Dval *dval_gen_default(const std::string &type, const std::string &identifier, int val_mutable, int val_nullable) {
        if (type == D_BOOL) {
            return dval_bool(false,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_FLOAT) {
            return dval_float(0.0,
                              identifier,
                              val_mutable,
                              val_nullable);
        }
        if (type == D_INT) {
            return dval_int(0,
                            identifier,
                            val_mutable,
                            val_nullable);
        }
        if (type == D_BYTE) {
            return dval_byte(static_cast<std::byte>(0),
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_SHORT) {
            return dval_short(0,
                              identifier,
                              val_mutable,
                              val_nullable);
        }
        if (type == D_LONG) {
            return dval_long(0,
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_CHAR) {
            return dval_char('\0',
                             identifier,
                             val_mutable,
                             val_nullable);
        }
        if (type == D_STRING) {
            return dval_str("",
                            identifier,
                            val_mutable,
                            val_nullable);
        }


        return nullptr;
    }

    Dval *dval_float(const float f,
                     const std::string &identifier,
                     const int val_mutable,
                     const int val_nullable) {
        return new Dval(DVAL_FLOAT,
                        0,
                        f,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_op(std::string op) {
        Dval *val = new Dval(DVAL_FUN,
                             0,
                             0,
                             static_cast<std::byte>(0),
                             0,
                             0,
                             0,
                             "",
                             std::move(op),
                             nullptr,
                             0,
                             new std::vector<Dval *>);

        if (val->identifier() == D_ADD) {
            val->set_fun(&native_fun::add_builtin);
            // std::cout << "Add operation selected." << std::endl;
        } else if (val->identifier() == D_SUB) {
            val->set_fun(&native_fun::sub_builtin);
            // std::cout << "Subtraction operation selected." << std::endl;
        } else if (val->identifier() == D_MUL) {
            val->set_fun(&native_fun::mul_builtin);
            // std::cout << "Multiplication operation selected." << std::endl;
        } else if (val->identifier() == D_DIV) {
            val->set_fun(&native_fun::div_builtin);
            // std::cout << "Division operation selected." << std::endl;
        } else if (val->identifier() == D_MOD) {
            val->set_fun(&native_fun::mod_builtin);
            // std::cout << "Modulo operation selected." << std::endl;
        } else if (val->identifier() == D_LSHIFT) {
            val->set_fun(&native_fun::lshift_builtin);
            // std::cout << "Left shift operation selected." << std::endl;
        } else if (val->identifier() == D_RSHIFT) {
            val->set_fun(&native_fun::rshift_builtin);
            // std::cout << "Right shift operation selected." << std::endl;
        }

        return val;
    }

    Dval *dval_err(const char *str) {
        return new Dval(DVAL_ERR,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        str,
                        nullptr,
                        0,
                        new std::vector<Dval *>);
    }

    Dval *dval_err(const std::string &err) {
        return new Dval(DVAL_ERR,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        err,
                        nullptr,
                        0,
                        new std::vector<Dval *>);
    }

    int get_type(const std::string &type) {
        if (type == D_BOOL) {
            return DVAL_BOOL;
        }
        if (type == D_FLOAT) {
            return DVAL_FLOAT;
        }
        if (type == D_INT) {
            return DVAL_INT;
        }
        if (type == D_BYTE) {
            return DVAL_BYTE;
        }
        if (type == D_SHORT) {
            return DVAL_SHORT;
        }
        if (type == D_LONG) {
            return DVAL_LONG;
        }
        if (type == D_CHAR) {
            return DVAL_CHAR;
        }
        if (type == D_STRING) {
            return DVAL_STR;
        }
        if (type == D_BOOL_ARR) {
            return DVAL_BOOL_ARR;
        }
        if (type == D_FLOAT_ARR) {
            return DVAL_FLOAT_ARR;
        }
        if (type == D_INT_ARR) {
            return DVAL_INT_ARR;
        }
        if (type == D_BYTE_ARR) {
            return DVAL_BYTE_ARR;
        }
        if (type == D_SHORT_ARR) {
            return DVAL_SHORT_ARR;
        }
        if (type == D_LONG_ARR) {
            return DVAL_LONG_ARR;
        }
        if (type == D_CHAR_ARR) {
            return DVAL_CHAR_ARR;
        }
        if (type == D_STRING_ARR) {
            return DVAL_STR_ARR;
        }
        if (type == D_IDENTIFIER) {
            return DVAL_IDENT;
        }
        if (type == D_FUN) {
            return DVAL_FUN;
        }
        if (type == D_OPERATOR) {
            return DVAL_OP;
        }
        if (type == D_PACKAGE) {
            return DVAL_PACKAGE;
        }

        return DVAL_ERR;
    }

    std::string type_to_string(int type) {
        if (type == DVAL_BOOL) {
            return D_BOOL;
        }
        if (type == DVAL_FLOAT) {
            return D_FLOAT;
        }
        if (type == DVAL_INT) {
            return D_INT;
        }
        if (type == DVAL_BYTE) {
            return D_BYTE;
        }
        if (type == DVAL_SHORT) {
            return D_SHORT;
        }
        if (type == DVAL_LONG) {
            return D_LONG;
        }
        if (type == DVAL_CHAR) {
            return D_CHAR;
        }
        if (type == DVAL_STR) {
            return D_STRING;
        }
        if (type == DVAL_BOOL_ARR) {
            return D_BOOL_ARR;
        }
        if (type == DVAL_FLOAT_ARR) {
            return D_FLOAT_ARR;
        }
        if (type == DVAL_INT_ARR) {
            return D_INT_ARR;
        }
        if (type == DVAL_BYTE_ARR) {
            return D_BYTE_ARR;
        }
        if (type == DVAL_SHORT_ARR) {
            return D_SHORT_ARR;
        }
        if (type == DVAL_LONG_ARR) {
            return D_LONG_ARR;
        }
        if (type == DVAL_CHAR_ARR) {
            return D_CHAR_ARR;
        }
        if (type == DVAL_STR_ARR) {
            return D_STRING_ARR;
        }
        if (type == DVAL_IDENT) {
            return D_IDENTIFIER;
        }
        if (type == DVAL_FUN) {
            return D_FUN;
        }
        if (type == DVAL_OP) {
            return D_OPERATOR;
        }
        if (type == DVAL_PACKAGE) {
            return D_PACKAGE;
        }

        return "unknown";
    }

    void call(Dval *dval) {
        if (dval->type() == DVAL_FUN) {
            Dval *body = dval_fun_get_body(dval);
            if (body->type() == DVAL_NATIVE_FUN) {
                call(body);
            }
            for (const auto &i: *body->child()) {
                call(i);
            }
        }

        if (dval->type() == DVAL_NATIVE_FUN) {
            (**dval->fun())(dval->parent()->env(), {});
        }

        if (dval->type() == DVAL_IDENT_CALL) {
            const Dval *val = dval->parent()->env()->get(dval->identifier());
            if (val == nullptr) {
                cout << "not found: " << dval->identifier() << endl;
                return;
            }
            cout << val->get_string_value() << endl;
        }

        if (dval->type() == DVAL_EXPR_CALL) {
            const Dval *expr = util::parse::calc_expr(dval->child()->at(0), dval->parent()->env());
            cout << expr->get_string_value() << endl;;
        }

        if (dval->type() == DVAL_FUN_VAR_ASSIGN) {
            Dval * var_to_assign = dval->parent()->env()->get(dval->identifier());
            if (!var_to_assign->is_mutable()) {
                cout << "cannot assign to a non-mutable variable" << endl;
                return;
            }

            Dval * res = util::parse::calc_expr(dval->child()->at(0), dval->parent()->env());

            var_to_assign->set_value(res->get_string_value());
        }
    }

    // this is the main call function body
    void call(Dval *body, const std::initializer_list<Denv *> envs, const Denv *denv, const Denv *return_) {
        vector<Dval *> *stmts = body->child();

        // the envs should contain the <body's env>
        // and the <args env>
        // and the <env where the fun defined>
        std::initializer_list<Denv *>::const_iterator it = envs.begin();
        Denv *body_env = new Denv(**it);
        Denv *args_env = new Denv(**++it);
        Denv *defined_env = new Denv(**++it);

        body_env->set_parent(args_env);
        args_env->set_parent(defined_env);

        // stmts is nullptr, this is a stmt
        if (stmts == nullptr) {
            const Dval *expr = nullptr;
            const Dval *val = nullptr;

            switch (body->type()) {
                case DVAL_EXPR_CALL:
                    expr = util::parse::calc_expr(body, body_env);
                    cout << expr->get_string_value() << endl;;
                    break;
                case DVAL_IDENT_CALL:
                    val = body_env->get(body->identifier());
                    if (val == nullptr) {
                        cout << "not found: " << body->identifier() << endl;
                        return;
                    }
                    cout << val->get_string_value() << endl;
                    break;
                case DVAL_FUN_VAR_ASSIGN:

                default:
                    break;
            }
            return;
        }

        // not a nullptr, this is a block
        for (const auto &i: *stmts) {
            call(i, envs, denv, return_);
        }

        // fill the return result
        for (const auto &[ident, val]: *return_->identifiers()) {
            if (const Dval *arg_val = args_env->get(ident); arg_val != nullptr) {
                return_->set(ident, new Dval(*arg_val));
                continue;
            }
            if (const Dval *body_val = body_env->get(ident); body_val != nullptr) {
                return_->set(ident, new Dval(*body_val));
                continue;
            }
            return_->set(ident, nullptr);
        }

        delete body_env;
        delete args_env;
        delete defined_env;
    }


    /**
     * \brief Executes the main body of a function call
     *
     * This function handles the execution of the given function and manages the associated environment variables.
     *
     * \param dval The function object to call
     * \param args_input The input arguments for the function
     * \return The result of the function call
     */
    Dval *call(const Dval *dval, const initializer_list<Dval *> *args_input) {
        // generate function and return values
        Denv *args = dval_fun_get_args(dval);

        // compose the args to the function
        if (args_input->size() != args->count()) {
            cout << "argument count mismatch" << endl;
            return nullptr;
        }

        const Denv *return_ = new Denv(*dval_fun_get_return(dval));
        Dval *body = new Dval(*dval_fun_get_body(dval));

        Denv *composed_arg = new Denv(*args);
        int idx = 0;;

        for (const auto val: *args_input) {
            Dval *res_dval = util::parse::calc_expr(val, dval->env()->parent());

            if (res_dval->type() != args->get(idx)->type()) {
                cout << "type mismatch at args list "
                        << idx
                        << "required --> "
                        << type_to_string(args->get(idx)->type())
                        << " but got --> "
                        << type_to_string(res_dval->type())
                        << endl;
            }

            composed_arg->add(val->identifier(), res_dval);
            idx++;
        }

        call(body, {args, body->env(), dval->env()->parent()}, args, return_);

        Dval *res = dval_fun(dval->identifier());
        res->set_fun_args(new Denv(*args));
        res->set_fun_return(new Denv(*return_));

        delete dval;

        return res;
    }

    Dval *dval_fun_block(const std::string &ident) {
        return new Dval(DVAL_FUN_BLOCK,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        ident,
                        nullptr,
                        0,
                        new std::vector<Dval *>);
    }

    Dval *dval_fun_var_assign(const std::string &string, Dval *dval) {
        return new Dval(DVAL_FUN_VAR_ASSIGN,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        string,
                        nullptr,
                        1,
                        new vector{dval});
    }


    Dval *dval_array_gen(const std::string &type,
                         const std::string &identifier,
                         const int val_mutable,
                         const int val_nullable) {
        if (type == D_BOOL_ARR) {
            return dval_bool_arr(identifier,
                                 val_mutable,
                                 val_nullable);
        }
        if (type == D_FLOAT_ARR) {
            return dval_float_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_INT_ARR) {
            return dval_int_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_BYTE_ARR) {
            return dval_byte_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_SHORT_ARR) {
            return dval_short_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_LONG_ARR) {
            return dval_long_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_CHAR_ARR) {
            return dval_char_arr(
                identifier,
                val_mutable,
                val_nullable);
        }
        if (type == D_STRING_ARR) {
            return dval_str_arr(
                identifier,
                val_mutable,
                val_nullable);
        }

        return nullptr;
    }

    Dval * dval_fun_var_assign(const std::string &string) {
        return new Dval(DVAL_FUN_VAR_ASSIGN,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        string,
                        nullptr,
                        0,
                        new std::vector<Dval *>);
    }

    Denv *dval_fun_get_args(const Dval *dval) {
        return dval->child()->at(FUN_ARGS)->env();
    }

    Dval *dval_fun_get_body(const Dval *dval) {
        return dval->child()->at(FUN_BODY);
    }

    Denv *dval_fun_get_return(const Dval *dval) {
        return dval->child()->at(FUN_RETURN)->env();
    }

    void dval_fun_set_args(Dval *sub, Dval *dval) {
        sub->child()->at(FUN_ARGS) = dval;
        dval->set_parent(sub);
    }

    void dval_fun_set_body(Dval *sub, Dval *dval) {
        sub->child()->at(FUN_BODY) = dval;
        dval->set_parent(sub);

    }

    void dval_fun_set_return(Dval *sub, Dval *dval) {
        sub->child()->at(FUN_RETURN) = dval;
        dval->set_parent(sub);

    }


    /* Construct a pointer to a new Symbol dval */
    Dval *dval_identifier(const std::string &s) {
        Dval *v = new Dval(DVAL_IDENT,
                           0,
                           0,
                           static_cast<std::byte>(0),
                           0,
                           0,
                           0,
                           "",
                           s,
                           nullptr,
                           0,
                           new std::vector<Dval *>);
        return v;
    }

    Dval *dval_identifier_call(const std::string &val) {
        return new Dval(DVAL_IDENT_CALL,
                        0,
                        0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        0,
                        "",
                        val,
                        nullptr,
                        0,
                        new std::vector<Dval *>);
    }

    Dval * dval_expr_call(const std::string &val) {
        return new Dval(DVAL_EXPR_CALL,
                0,
                0,
                static_cast<std::byte>(0),
                0,
                0,
                0,
                "",
                val,
                nullptr,
                0,
                new std::vector<Dval *>);
    }

    Dval *dval_int(const int x,
                   const std::string &identifier,
                   const int val_mutable,
                   const int val_nullable) {
        return new Dval(DVAL_INT,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        static_cast<int>(x),
                        0,
                        '\0',
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_byte(const std::byte x,
                    const std::string &identifier,
                    const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_BYTE,
                        0,
                        0.0,
                        x,
                        0,
                        0,
                        '\0',
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_short(const short x,
                     const std::string &identifier,
                     const int val_mutable,
                     const int val_nullable) {
        return new Dval(DVAL_SHORT,
                        x,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        x,
                        '\0',
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_long(const long x,
                    const std::string &identifier,
                    const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_LONG,
                        x,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_char(const char x,
                    const std::string &identifier,
                    const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_CHAR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        x,
                        "",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_bool(const std::string &val,
                    const std::string &identifier,
                    const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_BOOL,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        val,
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_bool(const bool &val,
                    const std::string &identifier,
                    const int val_mutable,
                    const int val_nullable) {
        return new Dval(DVAL_BOOL,
                        val,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        val ? "true" : "false",
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_str(const std::string &val,
                   const std::string &identifier,
                   const int val_mutable,
                   const int val_nullable) {
        return new Dval(DVAL_STR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        val,
                        nullptr,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_int_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_INT_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    auto dval_byte_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) -> Dval * {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_BYTE_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_short_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_SHORT_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_long_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_LONG_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_char_arr(const std::string &identifier,
                        const int val_mutable,
                        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();

        return new Dval(DVAL_CHAR_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_bool_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_BOOL_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_float_arr(const std::string &identifier,
                         const int val_mutable,
                         const int val_nullable) {
        return new Dval(DVAL_FLOAT_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        new std::vector<Dval *>,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    Dval *dval_str_arr(
        const std::string &identifier,
        const int val_mutable,
        const int val_nullable) {
        auto *array_val = new std::vector<Dval *>();
        return new Dval(DVAL_STR_ARR,
                        0,
                        0.0,
                        static_cast<std::byte>(0),
                        0,
                        0,
                        '\0',
                        "",
                        array_val,
                        identifier,
                        nullptr,
                        0,
                        new std::vector<Dval *>,
                        val_mutable,
                        val_nullable,
                        nullptr,
                        nullptr);
    }

    void dval_del(Dval *v) {
        switch (v->type()) {
            /* Do nothing special for number type */
            case DVAL_INT:
                break;

            /* For Err or Sym free the string data */
            case DVAL_ERR:
                break;
            case DVAL_IDENT:
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
}
