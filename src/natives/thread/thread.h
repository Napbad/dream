//
// Created by napbadsen on 24-9-28.
//

// This file implements the threading functions
#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <functional>

class Thread {
public:
    // Constructor
    Thread();

    // Destructor
    ~Thread();

    // Starts a new thread with the given function and argument
    void start(const std::function<void(void*)>& func, void* arg);

    // Waits for the thread to finish
    void wait();

    // Joins the thread safely
    void join();

    // Sets the priority of the thread (Platform-specific implementation needed)
    static void setPriority(int priority);

private:
    std::thread thread_;
};

#endif //THREAD_H
