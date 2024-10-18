//
// Created by napbadsen on 24-9-29.
//

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>
#include <utility>

#include "../../runtime/class/Object.h"

class Exception : public std::exception, public Object {
public:
    // Constructor that takes a message
    explicit Exception(std::string  message) : _message(std::move(message)) {}

    // Override the what() method to return the message
    [[nodiscard]] const char* what() const noexcept override {
        return _message.c_str();
    }

private:
    std::string _message;
};



#endif //EXCEPTION_H
