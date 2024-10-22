//
// Created by napbad on 10/22/24.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>
#include <string>

class System {
public:
    // Get the current time in milliseconds
    static long currentTimeMillis();

    // Get the current time in nanoseconds
    static long nanoTime();

    // Get system properties
    static std::string getProperty(const std::string& key);

private:
    System(); // Prevent instantiation
};

#endif // SYSTEM_H
