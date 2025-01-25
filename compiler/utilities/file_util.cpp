//
// Created by napbad on 9/18/24.
//

#include <filesystem>
#include <fstream>

#include "file_util.h"

#include "common/config.h"

using namespace std;
namespace dap::util
{
std::fstream create_file(const std::string &file_name)
{
    filesystem::path _path(file_name);

    filesystem::path _parent_path = _path.parent_path();

    create_directories(_parent_path);

    if (!exists(_parent_path)) {
        throw std::runtime_error("Failed to create directory: " + _parent_path.string());
    }

    std::fstream file_stream;
    file_stream.open(file_name, std::ios::out | std::ios::in | std::ios::trunc);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Failed to create file: " + file_name);
    }

    return file_stream;
}

void create_package_dir(string pkg_dir_name)
{
    string::size_type pos = 0;
    pos = pkg_dir_name.find('.');
    const string split = "/";
    while (pos != string::npos) {
        pkg_dir_name.replace(pos, 1, split);

        pos = pkg_dir_name.find('.', pos + 1);
    }

    pkg_dir_name = buildDir + pkg_dir_name;

    try {
        if (!std::filesystem::exists(pkg_dir_name)) {
            std::filesystem::create_directories(pkg_dir_name);
        }
    } catch (const std::filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to create directory: " + pkg_dir_name + ". Error: " + e.what());
    }
}

std::string convert_pkg_to_path(const std::string &pkg_name)
{
    string res = pkg_name;

    for (auto &c : res)
        if (c == '.')
            c = '/';

    res = buildDir + res + "/";

    return res;
}

std::string read_line(std::fstream *opened_file, const string &file_name, const int line)
{
    if (opened_file == nullptr || !opened_file->is_open())
        return ""; // Return an empty string if the opened_file pointer is null or
    // the opened_file is not open

    opened_file->close();

    int i = 0;
    string temp;
    fstream file;
    file.open(file_name, ios::in);

    while (getline(file, temp, '\n') && i < line - 1)
        i++;
    file.close();

    opened_file->open(file_name, std::ios::in | std::ios::out | std::ios::ate | std::ios::app);
    return temp;
}

void copy_directory(const std::string &source_dir, const std::string &destination_dir)
{
    if (!filesystem::exists(source_dir) || !filesystem::is_directory(source_dir))
        throw std::runtime_error("Source directory does not exist or is not a directory: " + source_dir);

    if (!filesystem::exists(destination_dir))
        filesystem::create_directories(destination_dir);

    try {
        filesystem::copy(source_dir, destination_dir,
                         filesystem::copy_options::overwrite_existing | filesystem::copy_options::recursive);
    } catch (const filesystem::filesystem_error &e) {
        throw std::runtime_error("Failed to copy directory: " + source_dir + " to " + destination_dir +
                                 ". Error: " + e.what());
    }
}

void collect_files_recursive(const std::string &dir_path, std::vector<std::string> &files)
{
    try {
        for (const auto &entry : filesystem::recursive_directory_iterator(dir_path)) {
            if (entry.is_regular_file()) {
                files.push_back(entry.path().string());
            }
        }
    } catch (const filesystem::filesystem_error &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

std::vector<std::string> get_all_files_in_dir(const std::string &dir_path)
{
    std::vector<std::string> files;
    collect_files_recursive(dir_path, files);
    return files;
}

std::vector<std::string> get_file_content(const std::string &file)
{
    std::ifstream ifstream(file);
    std::string line;
    std::vector<std::string> content;

    while (std::getline(ifstream, line))
        content.push_back(line);

    ifstream.close();
    return content;
}

void delete_directory(const std::string &dir_path)
{
    std::filesystem::remove_all(dir_path);
}

std::vector<std::filesystem::path> find_cpp_files(const std::filesystem::path &directory)
{
    std::vector<std::filesystem::path> cppFiles;

    // Iterate over all files and subdirectories
    for (const auto &entry : std::filesystem::recursive_directory_iterator(directory)) {
        // Check if the file has a .cpp extension and is a regular file
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            cppFiles.push_back(entry.path());
        }
    }

    return cppFiles;
}

bool is_clang_format_available()
{
#ifdef _WIN32
    // On Windows, redirect output to NUL
    int result = std::system(("clang-format --version > " + DEV_NULL + " 2>&1").c_str());
#else
    // On Unix-like systems, redirect output to /dev/null
    int result = std::system(("clang-format --version > " + DEV_NULL + " 2>&1").c_str());
#endif
    return result == 0;
}

bool create_dir(const std::string &path)
{
    try {
        // Create the directory and its parent directories if they do not exist
        if (filesystem::create_directories(path)) {
            std::cout << "Directory created: " << path << std::endl;
            return true;
        }
        std::cout << "Directory already exists: " << path << std::endl;
        return false;
    } catch (const filesystem::filesystem_error &e) {
        std::cerr << "Error creating directory: " << e.what() << std::endl;
        return false;
    }
}

YAMLNode parseYAML(const std::string &yamlString)
{
    YAMLNode root;
    std::istringstream iss(yamlString);
    std::string line;
    std::vector<YAMLNode *> currentNodes;
    currentNodes.push_back(&root);

    while (std::getline(iss, line)) {
        size_t indent = 0;
        while (indent < line.size() && std::isspace(line[indent])) {
            indent++;
        }
        line = line.substr(indent);

        if (line.empty() || line[0] == '#') {
            continue;
        }

        if (line.find(':') != std::string::npos) {
            size_t colonPos = line.find(':');
            std::string key = line.substr(0, colonPos);
            std::string value = line.substr(colonPos + 1);
            trim(key);
            trim(value);

            YAMLNode node;
            node.value = value;
            while (currentNodes.size() > indent) {
                currentNodes.pop_back();
            }
            currentNodes.back()->map[key] = node;
        } else if (line[0] == '-') {
            YAMLNode node;
            std::string value = line.substr(1);
            trim(value);
            node.value = value;
            while (currentNodes.size() > indent) {
                currentNodes.pop_back();
            }
            currentNodes.back()->sequence.push_back(node);
        } else {
            std::cerr << "Invalid YAML line: " << line << std::endl;
        }
    }
    return root;
}

void trim(std::string &str)
{
    size_t start = 0;
    size_t end = str.size() - 1;
    while (start < str.size() && std::isspace(str[start])) {
        start++;
    }
    while (end > start && std::isspace(str[end])) {
        end--;
    }
    str = str.substr(start, end - start + 1);
}

} // namespace dap::util
