/**
 * @file parser_util.h
 * @brief Utility functions for parsing operations.
 *
 * This header file contains utility functions used in the parsing process,
 * including generating data pool definitions and checking nullability of expressions.
 *
 * Created by napbadsen on 24-10-9.
 */

#ifndef PARSER_UTIL_H
#define PARSER_UTIL_H

#include <string>
#include <vector>
#include <tuple>

#include "obj/Hierarchy.h"
#include "parse/DreamParser.h"

/// Macros for function parameter types and properties
#define FUN_PARAM_TYPE_NAME std::string
#define FUN_PARAM_NAME std::string
#define FUN_PARAM_NULLABLE bool
#define FUN_PARAM_MUTABLE bool

/// Macro for a tuple representing a function parameter
#define FUN_PARAM_TYPE \
        std::tuple< \
            FUN_PARAM_TYPE_NAME, \
            FUN_PARAM_NAME, \
            FUN_PARAM_NULLABLE, \
            FUN_PARAM_MUTABLE \
        >

namespace parser_util
{
    /**
     * Checks if an expression is nullable within a given hierarchy.
     *
     * @param hierarchy The hierarchy object to check against.
     * @param expr The parse tree node representing the expression.
     * @return True if the expression is nullable, false otherwise.
     */
    bool find_nullable(Hierarchy* hierarchy, antlr4::tree::ParseTree* expr);

    /**
     * Determines if a parse tree node represents a null value.
     *
     * @param expr The parse tree node to check.
     * @return True if the parse tree node is null, false otherwise.
     */
    bool parse_tree_is_null(antlr4::tree::ParseTree* expr);

    /**
     * Converts a type name to its C++ representation.
     *
     * @param type_name The original type name as a string.
     * @return The C++ representation of the type name.
     */
    std::string convert_type_to_cpp(std::string& type_name);

    /**
     * Converts a list of return types to a tuple representation.
     *
     * @param ctx The context containing the return type information.
     * @return A string representing the tuple of return types.
     */
    std::string convert_type_list_to_tuple(DreamParser::ReturnTypeContext* ctx);

    /**
     * @brief Generates the default value for a specified type.
     *
     * This function generates a default value based on the provided type name. Supported types include but are not limited to `int`, `float`, `std::string`, etc.
     *
     * @param type The type name, e.g., "int", "float", "std::string".
     * @return The generated default value as a string.
     *
     * @note If the provided type is not supported, an empty string is returned.
     *
     * @example
     *
      */
    std::string generate_default_value(std::string& type);
} // namespace parser_util

#endif // PARSER_UTIL_H
