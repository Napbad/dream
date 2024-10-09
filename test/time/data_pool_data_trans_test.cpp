//
// Created by napbadsen on 24-10-9.
//

#include <queue>
#include <cstring>

class DataPool {
    std::queue<char*> _pool;
public:
    char* pop() {
        char* tmp = _pool.front();
        _pool.pop();
        return tmp;
    }

    void push(char* data) {
        _pool.push(data);
    }

    bool empty() {
        return _pool.empty();
    }
};

DataPool data_pool;

void test(char* chars) {
    strlen(chars);
}

void _test_(char* chars) {
    strlen(chars);
}

void test_() {
    _test_(data_pool.pop());
}



void data_pool_data_trans_test() {
    char chars[1024]{0};

    
}