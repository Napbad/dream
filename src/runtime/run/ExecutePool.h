//
// Created by napbadsen on 24-10-8.
//

#ifndef EXECUTEPOOL_H
#define EXECUTEPOOL_H
#include <queue>

#include "ExecuteUnit.h"


class ExecutePool
{
    std::queue<ExecuteUnit> _execute_queue{};

public:
    void add_execute_unit(const ExecuteUnit& unit);

    [[noreturn]] void start_running();
};

ExecutePool *global_execute_pool = new ExecutePool();

#endif //EXECUTEPOOL_H
