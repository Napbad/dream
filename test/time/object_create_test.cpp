//
// Created by napbadsen on 24-10-3.
//
#include <iostream>
#include <chrono>
#include <cstring> // 用于memset

// 普通类
class MyClass {
public:
    char data[500]; // 50字节的数据

    void doSomething() {
        // 这里可以添加一些需要执行的操作
        std::cout << "MyClass doing something..." << std::endl;
    }

    MyClass() {
        // 构造函数，这里只是进行简单的初始化
        std::memset(data, 0, sizeof(data));
    }
};

// 结构体
struct MyStruct {
    char data[500]; // 50字节的数据
};

void object_create_test() {
    // 测试创建普通对象所需时间
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        MyClass obj;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "创建100万个MyClass对象所需时间: " << elapsed_seconds.count() << " 秒" << std::endl;

    // 测试创建结构体所需时间
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        MyStruct str;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "创建100万个MyStruct结构体所需时间: " << elapsed_seconds.count() << " 秒" << std::endl;

}