#include "DataPath.h"

#include <utility>


// Constructor
DataPath::DataPath(std::string  name) : _name(std::move(name))
{
}

std::string DataPath::name()
{
    return _name;
}

// Define
std::unordered_map<std::string, DataPath*> data_path::_paths;
std::unordered_map<std::string, std::vector<DataPath*>> data_path::_data_path_map;

bool data_path::register_path(const std::string& path_name)
{
    // Implementation
    return _paths.insert({path_name, new DataPath(path_name)}).second;
}

bool data_path::add_path(const std::string& data_name, const std::string& path_name)
{
    // Implementation
    if (const auto it = _data_path_map.find(data_name); it == _data_path_map.end())
    {
        _data_path_map[data_name] = {new DataPath(path_name)};
    }
    else
    {
        it->second.push_back(new DataPath(path_name));
    }
    return true;
}

bool data_path::data_end(const std::string& data_name, const std::string& path_name)
{
    // Implementation
    if (const auto it = _data_path_map.find(data_name);
        it != _data_path_map.end())
    {
        if (const std::vector<DataPath*> data_paths = it->second;
            data_paths.at(data_paths.size() - 1)->name() == path_name)
        {
            return true;
        }
        return false;
    }


    return false;
}

void data_path::delete_paths(const std::string& path_name)
{
    // Implementation
    for (auto& pair : _data_path_map)
    {
        auto& paths = pair.second;
        for (auto it = paths.begin(); it != paths.end();)
        {
            if ((*it)->name() == path_name)
            {
                delete *it;
                it = paths.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}
