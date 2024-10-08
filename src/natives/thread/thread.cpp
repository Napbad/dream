#include "thread.h"
#include <iostream>

// Constructor
Thread::Thread() : thread_()
{
}

// Destructor
Thread::~Thread()
{
    if (thread_.joinable())
    {
        thread_.join();
    }
}

// Starts a new thread with the given function and argument
void Thread::start(const std::function<void(void*)>& func, void* arg)
{
    thread_ = std::thread(func, arg);
}

// Waits for the thread to finish
void Thread::wait()
{
    if (thread_.joinable())
    {
        thread_.join();
    }
}

// Joins the thread safely
void Thread::join()
{
    if (thread_.joinable())
    {
        thread_.join();
    }
}

// Sets the priority of the thread (Platform-specific implementation)
void Thread::setPriority(int priority)
{
#if defined(_WIN32)
    HANDLE currentThread = GetCurrentThread();
    if (!SetThreadPriority(currentThread, priority)) {
        std::cerr << "Failed to set thread priority: " << GetLastError() << std::endl;
    }
#elif defined(__linux__) || defined(__APPLE__)
    int policy;
    struct sched_param param{};

    if (pthread_getschedparam(pthread_self(), &policy, &param) != 0)
    {
        std::cerr << "Failed to get thread scheduling parameters" << std::endl;
        return;
    }

    param.sched_priority = priority;
    if (pthread_setschedparam(pthread_self(), policy, &param) != 0)
    {
        std::cerr << "Failed to set thread scheduling parameters" << std::endl;
        return;
    }
#else
    std::cerr << "Thread priority setting not supported on this platform" << std::endl;
#endif
}

