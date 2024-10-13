//
// Created by napbad on 9/23/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <unordered_map>
#include "Hierarchy.h"

/**
 * @file Global.h
 * @brief Defines the Global class for managing global information.
 *
 * This file contains the Global class, which records global information such as nullable variables,
 * hierarchy structures, and a list of files to compile.
 */

// Class for recording global information
class Global
{
    std::unordered_map<std::string, bool> *_var_nullable; /**< Map of variable names to their nullable status */
    Hierarchy *_hierarchy;                                 /**< Pointer to the hierarchy structure */
    std::vector<std::string> _file_to_compile_list;        /**< List of files to compile */

public:
    /**
     * @brief Constructs a Global object.
     */
    Global();

    /**
     * @brief Adds a nullable variable.
     * @param identifier Identifier of the variable.
     * @param nullable Nullable status of the variable.
     */
    void add_var_nullable(const std::string &identifier, bool nullable) const;

    /**
     * @brief Checks if a variable is nullable.
     * @param identifier Identifier of the variable.
     * @return True if the variable is nullable, false otherwise.
     */
    [[nodiscard]] bool is_var_nullable(const std::string &identifier) const;

    /**
     * @brief Checks if a variable exists in the nullable list.
     * @param identifier Identifier of the variable.
     * @return True if the variable exists in the nullable list, false otherwise.
     */
    [[nodiscard]] bool is_var_exists_in_nullable_list(const std::string &identifier) const;

    /**
     * @brief Returns the hierarchy structure.
     * @return Pointer to the hierarchy structure.
     */
    [[nodiscard]] Hierarchy* hierarchy() const;

    /**
     * @brief Adds a file to the compilation list.
     * @param string Path of the file to compile.
     */
    void add_file_compile(const std::string& string);

    /**
     * @brief Returns the list of files to compile.
     * @return A vector of strings representing the files to compile.
     */
    [[nodiscard]] std::vector<std::string> file_to_compile_list();
};

// Global pointer to the Global object
extern Global* global;

// Global flag indicating debug mode
extern bool global_flag_is_debug;

#endif //GLOBAL_H
