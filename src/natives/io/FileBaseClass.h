//
// Created by napbad on 10/22/24.
//

#ifndef FILEBASECLASS_H
#define FILEBASECLASS_H

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class FileBaseClass {
public:
    // Constructor
    explicit FileBaseClass(std::string  path);

    // Get the file path
    [[nodiscard]] std::string getPath() const;

    // Check if the file exists
    [[nodiscard]] bool exists() const;

    // Check if it is a file
    [[nodiscard]] bool isFile() const;

    // Check if it is a directory
    [[nodiscard]] bool isDirectory() const;

    // Create a file
    [[nodiscard]] bool createFile() const;

    // Create a directory
    [[nodiscard]] bool createDirectory() const;

    // Delete a file or directory
    [[nodiscard]] bool deleteFile() const;

    // List files and subdirectories in a directory
    [[nodiscard]] std::vector<std::string> listFiles() const;

    // Get the file size
    [[nodiscard]] uintmax_t length() const;

protected:
    std::string path;
};

#endif // FILEBASECLASS_H

