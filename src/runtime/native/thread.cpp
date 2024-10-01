//
// Created by napbadsen on 24-9-28.
//

#include "thread.h"

// Starts a new thread with the given function and argument
std::thread start_thread(std::function<void(void*)> func, void* arg)
{
    return std::thread(func, arg);
}

// Waits for all threads to finish
void wait_for_threads(std::vector<std::thread>& threads)
{
    for (auto& t : threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

// Joins a thread safely
void safe_join_thread(std::thread& t)
{
    if (t.joinable())
    {
        t.join();
    }
}

// Sets the priority of a thread
void set_thread_priority(std::thread& t, int priority)
{
#if defined(_WIN32)
    HANDLE handle = reinterpret_cast<HANDLE>(t.native_handle());
    SetThreadPriority(handle, priority);
#elif defined(__linux__)
    int policy;
    sched_param param{};

    if (pthread_t thread_id = t.native_handle(); pthread_getschedparam(thread_id, &policy, &param) == 0)
    {
        param.sched_priority = priority;
        pthread_setschedparam(thread_id, policy, &param);
    }
#else
    // Unsupported platform
    throw std::runtime_error("Setting thread priority is not supported on this platform.");
#endif
}

// // Checks if a thread has been interrupted
// bool is_thread_interrupted(const std::thread& t)
// {
//     try
//     {
//         const std::thread::id res = t.get_id();
//         (void)res;
//         return false;
//     }
//     catch (const std::system_error& e)
//     {
//         if (e.code().value() == EINTR)
//         {
//             return true;
//         }
//         throw;
//     }
// }
