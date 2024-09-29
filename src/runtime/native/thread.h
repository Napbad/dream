//
// Created by napbadsen on 24-9-28.
//

// this file implements the threading functions
#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <functional>

// Starts a new thread with the given function and argument
std::thread start_thread(std::function<void(void*)> func, void* arg);

// Waits for all threads to finish
void wait_for_threads(std::vector<std::thread>& threads);

// Joins a thread safely
void safe_join_thread(std::thread& t);

// Sets the priority of a thread
void set_thread_priority(std::thread& t, int priority);

// Checks if a thread has been interrupted
bool is_thread_interrupted(const std::thread& t);


#endif //THREAD_H   
