//
// Created by napbad on 10/22/24.
//

#include "System.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>

// Get the current time in milliseconds
long System::currentTimeMillis()
{
    return std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
}

// Get the current time in nanoseconds
long System::nanoTime()
{
    return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

// Get system properties based on the key
std::string System::getProperty(const std::string& key)
{
    if (key == "os.name")
    {
#ifdef _WIN32
            return "Windows";
#elif __APPLE__ || __MACH__
            return "Mac OS X";
#elif __linux__
        return "Linux";
#elif __FreeBSD__
            return "FreeBSD";
#else
            return "Unknown";
#endif
    }

    if (key == "os.version")
    {
#ifdef _WIN32
            // Windows version
            OSVERSIONINFOEX osvi;
            ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
            osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
            if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
                std::ostringstream oss;
                oss << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << " (Build " << osvi.dwBuildNumber << ")";
                return oss.str();
            }
            return "Unknown";

#elif __APPLE__ || __MACH__
            // macOS version
            std::ifstream file("/System/Library/CoreServices/SystemVersion.plist");
            std::string line;
            while (std::getline(file, line)) {
                if (line.find("<key>ProductVersion</key>") != std::string::npos) {
                    std::getline(file, line); // Skip to the next line
                    size_t start = line.find("<string>") + 8;
                    size_t end = line.find("</string>");
                    return line.substr(start, end - start);
                }
            }
            return "Unknown";

#elif __linux__
        // Linux version
        std::ifstream file("/etc/os-release");
        std::string line;
        while (std::getline(file, line))
        {
            if (line.find("VERSION_ID=") != std::string::npos)
            {
                size_t start = line.find('=') + 1;
                size_t end = line.find_last_of('"');
                return line.substr(start, end - start);
            }
        }
        return "Unknown";

#elif __FreeBSD__
            // FreeBSD version
            char buf[1024];
            if (sysctlbyname("kern.osrelease", buf, sizeof(buf), NULL, 0) == 0) {
                return std::string(buf);
            }
            return "Unknown";

#else
            return "Unknown";
#endif
    }

    if (key == "user.name")
    {
        if (const char* user_name = std::getenv("USER"); user_name != nullptr)
        {
            return user_name;
        }
        return "Unknown";
    }

    return "Unknown";
}

System::System()
= default;
