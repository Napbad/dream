//
// Created by napbadsen on 24-10-9.
//

#include <iostream>
#include <chrono>
#include <cstring> // 用于memset

// 结构体
struct MyStruct {
    char data[500]; // 50字节的数据
};

// 普通类
class MyClass {
public:
    MyStruct data;

    void doSomething() {
        // 这里可以添加一些需要执行的操作
        std::cout << "MyClass doing something..." << std::endl;
    }

    MyClass() {
    }
};

void object_assign_test() {
    MyClass cls;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        cls.data = MyStruct{};
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "创建100万个MyClass对象所需时间: " << elapsed_seconds.count() << " 秒" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        MyStruct str{};
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "创建100万个MyStruct结构体所需时间: " << elapsed_seconds.count() << " 秒" << std::endl;

}