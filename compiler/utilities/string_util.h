//
// Created by napbad on 9/18/24.
//

#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <string>
#include <vector>

#include "common/reserve.h"

namespace dap::util
{
/**
 * Splits a string by a delimiter and returns a vector of substrings.
 *
 * @param str The input string to split.
 * @param delimiter The delimiter used to split the string.
 * @return A vector of substrings obtained by splitting the input string.
 */
std::vector<std::string> split(const std::string &str, char delimiter);

/**
 * Joins a vector of strings with a delimiter and returns the concatenated
 * string.
 *
 * @param strs The vector of strings to join.
 * @param delimiter The delimiter used to join the strings.
 * @return The concatenated string.
 */
std::string join(const std::vector<std::string> &strs, char delimiter);

/**
 * Checks if the string represents a numeric value.
 *
 * @param s The string to check.
 * @return True if the string represents a numeric value, false otherwise.
 */
bool strIsNum(const std::string &s);

/**
 * Checks if the string represents an operator.
 *
 * @param string The string to check.
 * @return True if the string represents an operator, false otherwise.
 */
bool strIsOp(const std::string &string);

/**
 * Checks if the string represents a boolean value.
 *
 * @param string The string to check.
 * @return True if the string represents a boolean value, false otherwise.
 */
bool strIsBool(const std::string &string);

/**
 * Checks if the string represents a string literal.
 *
 * @param string The string to check.
 * @return True if the string represents a string literal, false otherwise.
 */
bool strIsStr(const std::string &string);

/**
 * Checks if the string represents a floating-point number.
 *
 * @param string The string to check.
 * @return True if the string represents a floating-point number, false
 * otherwise.
 */
bool strIsFloat(const std::string &string);

/**
 * Checks if the string represents a single character.
 *
 * @param string The string to check.
 * @param c The character to match.
 * @return True if the string represents the specified character, false
 * otherwise.
 */
bool strIsChar(const std::string &string, char c);

/**
 * Checks if the string represents a single character (without specifying the
 * character).
 *
 * @param string The string to check.
 * @return True if the string represents a single character, false otherwise.
 */
bool strIsChar(const std::string &string);

/**
 * Checks if the string represents a valid identifier.
 *
 * @param ident The string to check.
 * @return True if the string represents a valid identifier (including string, char ...), false otherwise.
 */
bool strIsIdent(const std::string &ident);

/**
 * Checks if the string represents only a valid identifier.
 *
 * @param ident The string to check.
 * @return True if the string represents only a valid identifier (do not include string ...), false
 * otherwise.
 */
bool strIsOnlyIdent(const std::string &ident);

/**
 * Gets text from a vector of strings.
 *
 * @param vec The vector of strings to process.
 * @return The concatenated text from the vector.
 */
std::string getTextFromVec(const std::vector<std::string> &vec);

std::string getStrFromVec(const std::vector<std::string> &vec, const std::string &delimiter);

std::string basicTypeToString(BasicType type);

/**
 * Gets lines from a vector of strings.
 *
 * @param vector The vector of strings to process.
 * @return The concatenated lines from the vector.
 */
std::string getLinesFromVec(const std::vector<std::string> &vector);

/**
 * Checks if the string represents a common type.
 *
 * @param type The string to check.
 * @return True if the string represents a common type, false otherwise.
 */
bool strIsCommonType(const std::string &type);

/**
 * Checks if the string value represents a common type.
 *
 * @param string The string to check.
 * @return True if the string value represents a common type, false otherwise.
 */
bool strValIsCommonType(const std::string &string);

/**
 * Replaces all occurrences of a substring within a string.
 *
 * @param str The original string.
 * @param from The substring to find and replace.
 * @param to The substring to replace with.
 */
void replaceAll(std::string &str, const std::string &from, const std::string &to);

/**
 * Generates a unique name.
 *
 * This function generates a unique string name within the system. The
 * mechanism ensures the uniqueness of the name, which is useful when assigning
 * unique identifiers to objects, users, or other entities. Through a complex
 * algorithm and possible random number generation, this function effectively
 * reduces the probability of name conflicts.
 *
 * @return Returns a unique string name.
 */
std::string genUniqueName();

/**
 * Replaces all occurrences of a substring within a string without string
 *
 * e.g.
 * replace 'b' in "aaa"bb"ababa" to c
 *  => "aaac"bb"acaca"
 *
 * @param str The original string.
 * @param from The substring to find and replace.
 * @param to The substring to replace with.
 */
void replaceAllWithoutStr(std::string &str, const char *from, const char *to);

/**
 * Finds a string within a string but exclude string.
 *
 * e.g.
 * find "aaa"bb"ababa" with "b"
 * it will find:
 *
 *  "aaa"bb"ababa"
 *
 *  -------->b
 * @param value The string to search within.
 * @param basic_string The string to find.
 * @return True if the string is found, false otherwise.
 */
bool findExpectStr(std::string value, const std::string &basic_string);

std::string *getPureStr(std::string *sourceStr);

} // namespace dap::util

#endif // STRING_UTIL_H
