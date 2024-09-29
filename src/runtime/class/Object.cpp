//
// Created by napbadsen on 24-9-28.
//

#include "Object.h"

#include <cstddef>
#include <cstdint>

// Constructor
Object::Object() = default;

// Destructor
Object::~Object() = default;

// Equality check
bool Object::equals(const Object& other) const {
    // Default implementation checks if the addresses are the same
    return this == &other;
}

// String representation
std::string Object::toString() const {
    // Default implementation returns the class name and address
    return "Object@" + std::to_string(reinterpret_cast<uintptr_t>(this));
}

// Hash code generation
size_t Object::hashCode() const {
    // Default implementation uses the address of the object
    return reinterpret_cast<size_t>(this);
}

// Helper function to compare two objects
bool Object::isEqual(const Object* obj1, const Object* obj2) {
    if (obj1 == nullptr || obj2 == nullptr) return false;
    return obj1->equals(*obj2);
}