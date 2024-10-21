//
// Created by napbad on 10/22/24.
//

#include "FileBaseClass.h"
#include "FileBaseClass.h"
#include <fstream>
#include <utility>

FileBaseClass::FileBaseClass(std::string  path) : path(std::move(path)) {}

std::string FileBaseClass::getPath() const {
    return path;
}

bool FileBaseClass::exists() const {
    return fs::exists(path);
}

bool FileBaseClass::isFile() const {
    return fs::is_regular_file(path);
}

bool FileBaseClass::isDirectory() const {
    return fs::is_directory(path);
}

bool FileBaseClass::createFile() const
{
    if (exists()) {
        return false;
    }
    std::ofstream file(path);
    return file.is_open();
}

bool FileBaseClass::createDirectory() const
{
    return fs::create_directory(path);
}

bool FileBaseClass::deleteFile() const
{
    return fs::remove(path);
}

std::vector<std::string> FileBaseClass::listFiles() const {
    std::vector<std::string> files;
    if (isDirectory()) {
        for (const auto& entry : fs::directory_iterator(path)) {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

uintmax_t FileBaseClass::length() const {
    if (isFile()) {
        return fs::file_size(path);
    }
    return 0;
}
