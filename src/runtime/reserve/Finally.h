//
// Created by napbadsen on 24-9-29.
//

#ifndef FINALLY_H
#define FINALLY_H

#include <functional>
#include <utility>

class Finally {
public:
    explicit Finally(std::function<void()> cleanupFunc) : _cleanupFunc(std::move(cleanupFunc)) {}
    ~Finally() {
        _cleanupFunc();
    }

private:
    std::function<void()> _cleanupFunc;
};

#endif //FINALLY_H
