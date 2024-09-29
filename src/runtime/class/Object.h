//
// Created by napbadsen on 24-9-28.
//

#ifndef OBJECT_H
#define OBJECT_H


#include <iostream>
#include <string>

// Base class mimicking Java's Object class
class Object {
public:
    // Constructor
    Object();

    // Destructor (virtual for proper cleanup in derived classes)
    virtual ~Object();

    // Equality check
    [[nodiscard]] virtual bool equals(const Object& other) const;

    // String representation
    [[nodiscard]] virtual std::string toString() const;

    // Hash code generation
    [[nodiscard]] virtual size_t hashCode() const;

    // Clone method (pure virtual for polymorphism)
    [[nodiscard]] virtual Object* clone() const = 0;

    // Helper function to compare two objects
    static bool isEqual(const Object* obj1, const Object* obj2);

};

#endif // OBJECT_H
