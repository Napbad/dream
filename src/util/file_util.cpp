//
// Created by napbad on 9/18/24.
//

#include "file_util.h"

#include <fstream>
#include <filesystem>

#include "string_util.h"
#include "common/reserve.h"
#include "obj/Global.h"

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

void file_util::dbg_print(std::ostream& stream, const std::string& message, FileColor color)
{
    print(stream, "DEBUG: ", FileColor::BRIGHT_YELLOW);
    print(stream, message, color);
}

void file_util::warn_print(std::ostream& stream, const std::string& message, FileColor color)
{
    print(stream, ">>>>WARNING:\n", FileColor::YELLOW);
    print(stream, message, color);
}

void file_util::err_print(std::ostream& stream, const std::string& message, FileColor color)
{
    print(stream, ">>>>>>>>ERROR:\n", FileColor::BRIGHT_RED);
    print(stream, message, color);
}

void file_util::dbg_print(std::ostream& stream, const std::string& message)
{
    print(stream, "DEBUG: ", FileColor::BRIGHT_YELLOW);
    print(stream, message, FileColor::WHITE);
}

void file_util::warn_print(std::ostream& stream, const std::string& message)
{
    print(stream, ">>>>WARNING:\n", FileColor::YELLOW);
    print(stream, message, FileColor::WHITE);
}

void file_util::err_print(std::ostream& stream, const std::string& message)
{
    print(stream, ">>>>>>>>ERROR:\n", FileColor::BRIGHT_RED);
    print(stream, message, FileColor::WHITE);
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
        setColor(colorCode(FileColor::BLACK).c_str()); // Reset color
#endif
    }

    stream.flush();
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
    try
    {
        for (const auto& entry : filesystem::recursive_directory_iterator(dir_path))
        {
            if (entry.is_regular_file())
            {
                files.push_back(entry.path().string());
            }
        }
    }
    catch (const filesystem::filesystem_error& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

std::vector<std::string> file_util::get_all_files_in_dir(const std::string& dir_path)
{
    std::vector<std::string> files;
    collect_files_recursive(dir_path, files);
    return files;
}

std::vector<std::string> file_util::get_file_content(const std::string& file)
{
    std::ifstream ifstream(file);
    std::string line;
    std::vector<std::string> content;

    while (std::getline(ifstream, line))
        content.push_back(line);

    ifstream.close();
    return content;
}

void file_util::delete_directory(const std::string& dir_path)
{
    std::filesystem::remove_all(dir_path);
}

std::vector<std::filesystem::path> file_util::find_cpp_files(const std::filesystem::path& directory)
{
    std::vector<std::filesystem::path> cppFiles;

    // Iterate over all files and subdirectories
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory))
    {
        // Check if the file has a .cpp extension and is a regular file
        if (entry.is_regular_file() && entry.path().extension() == ".cpp")
        {
            cppFiles.push_back(entry.path());
        }
    }

    return cppFiles;
}

bool file_util::is_clang_format_available()
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

void file_util::format_file(const std::filesystem::path& filePath)
{
    // Construct the clang-format command
    const std::string command = "clang-format -i \"" + filePath.string() + "\"";

    // Execute the command

    if (const int result = std::system(command.c_str()); result == 0)
    {
        if (global_flag_is_debug)
            dbg_print(cout, "Formatted: " + filePath.string() + "\n");
    }
    else
        dbg_print(cout, "Failed to format: " + filePath.string() + "\n");
}

void file_util::format_all_cpp_files(const std::filesystem::path& directory)
{
    // First, check if clang-format is available
    if (!is_clang_format_available())
    {
        warn_print(
            cout,
            "Warn: clang-format is not available on this system."
            " The generated code can not be formatted automatically. "
            "If you want to format is automatically"
            "Please install it.");
        return;
    }

    // Check if the provided path is a valid directory
    if (!exists(directory) || !is_directory(directory))
    {
        err_print(cout, "Invalid directory path: " + directory.string());
        return;
    }

    // Find all .cpp files in the directory

    // Format each .cpp file found
    for (std::vector<filesystem::path> cppFiles = find_cpp_files(directory);
         const auto& file : cppFiles)
    {
        format_file(file);
    }

    print(cout, "All .cpp files in directory \"" + directory.string() + "\" have been formatted.", FileColor::WHITE);
}

#ifdef _WIN32
inline int file_util::colorCode(FileColor color) {
    switch (color) {
        case FileColor::GREEN: return FOREGROUND_GREEN;
        case FileColor::WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::RED: return FOREGROUND_RED;
        case FileColor::YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN;
        case FileColor::BLUE: return FOREGROUND_BLUE;
        case FileColor::BLACK: return 0;
        case FileColor::MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE;
        case FileColor::CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::BRIGHT_GREEN: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_RED: return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_BLUE: return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        default: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
}
#else
std::string file_util::colorCode(FileColor color)
{
    switch (color)
    {
    case FileColor::GREEN: return "\033[32m";
    case FileColor::WHITE: return "\033[37m";
    case FileColor::RED: return "\033[31m";
    case FileColor::YELLOW: return "\033[33m";
    case FileColor::BLUE: return "\033[34m";
    case FileColor::BLACK: return "\033[30m";
    case FileColor::MAGENTA: return "\033[35m";
    case FileColor::CYAN: return "\033[36m";
    case FileColor::BRIGHT_GREEN: return "\033[92m";
    case FileColor::BRIGHT_WHITE: return "\033[97m";
    case FileColor::BRIGHT_RED: return "\033[91m";
    case FileColor::BRIGHT_YELLOW: return "\033[93m";
    case FileColor::BRIGHT_BLUE: return "\033[94m";
    case FileColor::BRIGHT_MAGENTA: return "\033[95m";
    case FileColor::BRIGHT_CYAN: return "\033[96m";
    default: return "\033[37m";
    }
}
#endif
