//
// Created by napbadsen on 24-10-2.
//

#ifndef NATIVECONVERTER_H
#define NATIVECONVERTER_H

#include <string>
#include <vector>

/**
 * @file NativeConverter.h
 * @brief Contains the NativeConverter class for generating native code.
 *
 * This file defines the NativeConverter class, which is used to generate native code
 * from files in the natives folder.
 */

// Path to the natives folder where native code is stored
const std::string native_file_path = "../build/natives";

/**
 * @class NativeConverter
 * @brief Provides functionality to convert native classes into code.
 *
 * This class offers a static method to retrieve the code for a given native class.
 */
class NativeConverter
{
public:
    /**
     * @brief Retrieves the native class code.
     * @param class_name Name of the native class.
     * @return A vector of strings representing the lines of code for the native class.
     */
    static std::vector<std::string> get_native_class_code(const std::string& class_name);
};

#endif //NATIVECONVERTER_H
