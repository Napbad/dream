//
// Created by napbad on 9/18/24.
//

#include "file_util.h"

#include <fstream>
#include <filesystem>

#include "string_util.h"
#include "common/reserve.h"

using namespace std;


std::fstream file_util::create_file(const std::string& file_name)
{
    filesystem::path _path(file_name);

    filesystem::path _parent_path = _path.parent_path();

    create_directories(_parent_path);

    if (!exists(_parent_path))
    {
        throw std::runtime_error("Failed to create directory: " + _parent_path.string());
    }

    std::fstream file_stream;
    file_stream.open(file_name, std::ios::out | std::ios::in | std::ios::trunc);


    if (!file_stream.is_open())
    {
        throw std::runtime_error("Failed to create file: " + file_name);
    }

    return file_stream;
}

void file_util::create_package_dir(string pkg_dir_name)
{
    string::size_type pos = 0;
    pos = pkg_dir_name.find('.');
    const string split = "/";
    while (pos != string::npos)
    {
        pkg_dir_name.replace(pos, 1, split);

        pos = pkg_dir_name.find('.', pos + 1);
    }

    pkg_dir_name = OUTPUT_DIR + pkg_dir_name;

    try
    {
        if (!std::filesystem::exists(pkg_dir_name))
        {
            std::filesystem::create_directories(pkg_dir_name);
        }
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        throw std::runtime_error("Failed to create directory: " + pkg_dir_name + ". Error: " + e.what());
    }
}

std::string file_util::convert_pkg_to_path(const std::string& pkg_name)
{
    string res = pkg_name;

    for (auto& c : res)
        if (c == '.')
            c = '/';

    res = OUTPUT_DIR + res + "/";

    return res;
}

std::string file_util::convert_type_to_cpp(std::string& type_name)
{
    if (type_name == D_STRING)
        return "std::string";

    if (type_name == D_STRING_ARR)
        return "std::string[]";

    if (type_name.starts_with("u"))
        type_name.replace(0, 1, "unsigned ");
    return type_name;
}

std::string file_util::read_line(std::fstream* opened_file, string& file_name, const int line)
{
    if (opened_file == nullptr || !opened_file->is_open())
        return ""; // Return an empty string if the opened_file pointer is null or the opened_file is not open

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

void file_util::print(std::ostream& stream, const std::string& message, FileColor color)
{
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        setColor(colorCode(color));
#else
        std::cout << colorCode(color);
#endif
    }
    stream << message;
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        setColor(color); // Default white
#else
        setColor(colorCode(color).c_str()); // Reset color
#endif
    }
}

void file_util::copy_directory(const std::string& source_dir, const std::string& destination_dir)
{
    if (!filesystem::exists(source_dir) || !filesystem::is_directory(source_dir))
        throw std::runtime_error("Source directory does not exist or is not a directory: " + source_dir);

    if (!filesystem::exists(destination_dir))
        filesystem::create_directories(destination_dir);

    try
    {
        filesystem::copy(source_dir, destination_dir,
                         filesystem::copy_options::overwrite_existing | filesystem::copy_options::recursive);
    }
    catch (const filesystem::filesystem_error& e)
    {
        throw std::runtime_error(
            "Failed to copy directory: " + source_dir + " to " + destination_dir + ". Error: " + e.what());
    }
}

Hierarchy* file_util::get_package_hierarchy(const std::string& package_name)
{
    std::vector<std::string> split = string_util::split(package_name, '.');

    Hierarchy* hierarchy = Hierarchy::root_hierarchy();

    hierarchy->add_child_pkg_hierarchy(split);

    return hierarchy;
}

void file_util::collect_files_recursive(const std::string& dir_path, std::vector<std::string>& files)
{
    try {
        for (const auto& entry : filesystem::recursive_directory_iterator(dir_path)) {
            if (entry.is_regular_file()) {
                files.push_back(entry.path().string());
            }
        }
    } catch (const filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

std::vector<std::string> file_util::get_all_files_in_dir(const std::string& dir_path)
{
    std::vector<std::string> files;
    collect_files_recursive(dir_path, files);
    return files;
}

#ifdef _WIN32

int file_util::colorCode(FileColor color) {
    static std::map<FileColor, int> winColors = {
        {FileColor::GREEN, 2},
        {FileColor::WHITE, 7},
        {FileColor::RED, 4},
        {FileColor::YELLOW, 6},
        {FileColor::BLUE, 1}
    };
    static std::map<FileColor, const char*> ansiColors = {
        {FileColor::GREEN, "\x1b[32m"},
        {FileColor::WHITE, "\x1b[37m"},
        {FileColor::RED, "\x1b[31m"},
        {FileColor::YELLOW, "\x1b[33m"},
        {FileColor::BLUE, "\x1b[34m"}
    };

    if (const char* ansi = ansiColors.find(color)->second) {
        return *ansi;
    }
    return winColors.at(color);

    return -1; // ANSI colors are handled via string return
}

#else
std::string file_util::colorCode(const FileColor color)
{
    static std::map<FileColor, const char*> ansiColors = {
        {FileColor::GREEN, "\x1b[32m"},
        {FileColor::WHITE, "\x1b[37m"},
        {FileColor::RED, "\x1b[31m"},
        {FileColor::YELLOW, "\x1b[33m"},
        {FileColor::BLUE, "\x1b[34m"}
    };

    if (const char* ansi = ansiColors.find(color)->second)
        return ansi;

    return "\x1b[34m";
}


#endif
