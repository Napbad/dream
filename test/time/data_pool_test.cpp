#include <iostream>
#include <chrono>
#include <coroutine>
#include <queue>
#include <thread>
#include <cstring> 

bool test_running_flag = false;
int test_run_time_count = 0;
const int MAX_RUN_TIME = 100000;

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

void test(const char* str) {
    strlen(str);
}
void _test_(const char* str) {
    strlen(str);
}
void test_() {
    while (test_running_flag && !data_pool.empty() && test_run_time_count < MAX_RUN_TIME) {
        
        strlen("safasfgldfl");
        test_run_time_count++;
    }
    
}

void data_pool_test() {
    
    char* testData = new char[100];
    memset(testData, 'a', 99);
    testData[99] = '\0';
    data_pool.push(testData);

    int run_count = 100000;

    auto start_test = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < run_count; i++) 
        {test(testData);}
    auto end_test = std::chrono::high_resolution_clock::now();
    auto duration_test = std::chrono::duration_cast<std::chrono::nanoseconds>(end_test - start_test);
    std::cout << "Function test took " << duration_test.count() << " nanoseconds." << std::endl;

    
    auto start_test_ = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < run_count; i++) 
        _test_(testData);
    auto end_test_ = std::chrono::high_resolution_clock::now();
    auto duration_test_ = std::chrono::duration_cast<std::chrono::nanoseconds>(end_test_ - start_test_);
    std::cout << "Function _test_ took " << duration_test_.count() << " nanoseconds." << std::endl;

    
    test_running_flag = true;
    for (int i = 0; i < run_count; i++) 
        data_pool.push(testData);
    std::cout << "Thread test_ running..." << std::endl;

    auto start_test__ = std::chrono::high_resolution_clock::now();
    std::thread t(test_);
    t.join();
    auto end_test__ = std::chrono::high_resolution_clock::now();
    auto duration_test__ = std::chrono::duration_cast<std::chrono::nanoseconds>(end_test__ - start_test__);
    std::cout << "Function test_ took " << duration_test__.count() << " nanoseconds." << std::endl;

    delete[] testData; 
}