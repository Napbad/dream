//
// Created by napbad on 9/18/24.
//

#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <ranges>
#include <string>
#include <vector>
#include <tree/ParseTree.h>
#include "parser_util.h"
#include <antlr4-runtime.h>

namespace string_util
{
    /**
     * Splits a string by a delimiter and returns a vector of substrings.
     *
     * @param str The input string to split.
     * @param delimiter The delimiter used to split the string.
     * @return A vector of substrings obtained by splitting the input string.
     */
    std::vector<std::string> split(const std::string& str, char delimiter);

    /**
     * Joins a vector of strings with a delimiter and returns the concatenated string.
     *
     * @param strs The vector of strings to join.
     * @param delimiter The delimiter used to join the strings.
     * @return The concatenated string.
     */
    std::string join(const std::vector<std::string>& strs, char delimiter);

    /**
     * Checks if the string represents a numeric value.
     *
     * @param s The string to check.
     * @return True if the string represents a numeric value, false otherwise.
     */
    bool str_is_num(const std::string& s);

    /**
     * Checks if the string represents an operator.
     *
     * @param string The string to check.
     * @return True if the string represents an operator, false otherwise.
     */
    bool str_is_op(const std::string& string);

    /**
     * Checks if the string represents a boolean value.
     *
     * @param string The string to check.
     * @return True if the string represents a boolean value, false otherwise.
     */
    bool str_is_bool(const std::string& string);

    /**
     * Checks if the string represents a string literal.
     *
     * @param string The string to check.
     * @return True if the string represents a string literal, false otherwise.
     */
    bool str_is_str(const std::string& string);

    /**
     * Checks if the string represents a floating-point number.
     *
     * @param string The string to check.
     * @return True if the string represents a floating-point number, false otherwise.
     */
    bool str_is_float(const std::string& string);

    /**
     * Checks if the string represents a single character.
     *
     * @param string The string to check.
     * @param c The character to match.
     * @return True if the string represents the specified character, false otherwise.
     */
    bool str_is_char(const std::string& string, char c);

    /**
     * Checks if the string represents a single character (without specifying the character).
     *
     * @param string The string to check.
     * @return True if the string represents a single character, false otherwise.
     */
    bool str_is_char(const std::string& string);

    /**
     * Checks if the string represents a valid identifier.
     *
     * @param ident The string to check.
     * @return True if the string represents a valid identifier, false otherwise.
     */
    bool str_is_ident(const std::string& ident);

    /**
     * Checks if the string represents only a valid identifier.
     *
     * @param ident The string to check.
     * @return True if the string represents only a valid identifier, false otherwise.
     */
    bool str_is_only_ident(const std::string& ident);

    /**
     * Converts a parse tree to a string.
     *
     * @param tree The parse tree to convert.
     * @return The string representation of the parse tree.
     */
    std::string convert_parser_tree_to_string(antlr4::tree::ParseTree* tree);

    /**
     * Gets text from a vector of strings.
     *
     * @param vec The vector of strings to process.
     * @return The concatenated text from the vector.
     */
    std::string get_text_from_vector(const std::vector<std::string>& vec);

    /**
     * Gets a string from a vector of parameters with a delimiter.
     *
     * @param vector The vector of parameters to process.
     * @param delimiter The delimiter used to join the parameters.
     * @return The concatenated string from the vector of parameters.
     */
    std::string get_str_from_param_vector(const std::vector<std::tuple<std::string, std::string, bool, bool>>& vector,
                                          const std::string& delimiter);

    /**
     * Gets lines from a vector of strings.
     *
     * @param vector The vector of strings to process.
     * @return The concatenated lines from the vector.
     */
    std::string get_lines_from_vector(const std::vector<std::string>& vector);

    /**
     * Checks if the string represents a common type.
     *
     * @param string The string to check.
     * @return True if the string represents a common type, false otherwise.
     */
    bool str_is_common_type(const std::string& string);

    /**
     * Checks if the string value represents a common type.
     *
     * @param string The string to check.
     * @return True if the string value represents a common type, false otherwise.
     */
    bool str_val_is_common_type(const std::string& string);

    /**
     * Replaces all occurrences of a substring within a string.
     *
     * @param str The original string.
     * @param from The substring to find and replace.
     * @param to The substring to replace with.
     */
    void replace_all(std::string& str, const std::string& from, const std::string& to);


    /**
     * Generates a unique name.
     *
     * This function generates a unique string name within the system. The mechanism ensures the uniqueness of the name,
     * which is useful when assigning unique identifiers to objects, users, or other entities. Through a complex algorithm
     * and possible random number generation, this function effectively reduces the probability of name conflicts.
     *
     * @return Returns a unique string name.
     */
    std::string gen_unique_name();
    void replace_all_without_str(std::string& str, const char* from, const char* to);
} // namespace string_util

#endif // STRING_UTIL_H
