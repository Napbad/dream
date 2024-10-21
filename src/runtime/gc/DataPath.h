//
// Created by napbadsen on 24-10-8.
//

#pragma once

#ifndef DATEPATH_H
#define DATEPATH_H
#include <string>
#include <unordered_map>
#include <vector>

// this class records all the data transfer path

class DataPath;

namespace data_path
{
    // register a function's path (path node)
    bool register_path(const std::string& path_name);

    // add a path node to one data's path
    bool add_path(const std::string& data_name, const std::string& path_name);

    // checkout whether a data's transfer path is end in specific path node
    bool data_end(const std::string& data_name, const std::string& path_name);

    // delete all path node
    void delete_paths(const std::string& path_name);

    // record every function's data path name
    extern std::unordered_map<std::string, DataPath*> _paths;

    // record every data's transfer path
    extern std::unordered_map<std::string, std::vector<DataPath*>> _data_path_map;
}

class DataPath {
    std::string _name;

public:
    explicit DataPath(std::string name);
    std::string name();
};

#endif //DATEPATH_H
