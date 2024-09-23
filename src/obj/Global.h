//
// Created by napbad on 9/23/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H
#include <string>
#include <unordered_map>

// this class is recording the global information

class Global {
    std::unordered_map<std::string, bool> _var_nullable;

public:
    Global();
    void add_var_nullable(const std::string &identifier, bool nullable);
    [[nodiscard]] bool is_var_nullable(const std::string &identifier);
    [[nodiscard]] bool is_var_exists_in_nullable_list(const std::string &identifier) const;
};



#endif //GLOBAL_H
