//
// Created by napbadsen on 24-10-8.
//

#include "ExecutePool.h"

#include "ExecuteUnit.h"


void ExecutePool::add_execute_unit(const ExecuteUnit& unit)
{
    _execute_queue.push(unit);
}

[[noreturn]] void ExecutePool::start_running()
{
    while (true)
    {
        while (!_execute_queue.empty())
        {
            ExecuteUnit unit = _execute_queue.front();
            unit.run();
            _execute_queue.pop();
        }
    }
}
