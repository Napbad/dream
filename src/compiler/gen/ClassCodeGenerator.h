/**
 * @file ClassCodeGenerator.h
 * @brief Defines the ClassCodeGenerator class, which is responsible for generating class code.
 * Created by napbadsen on 24-10-2.
 */

#ifndef CLASSCODEGENERATOR_H
#define CLASSCODEGENERATOR_H

#include <string>
#include <vector>

#include "ClassStructGenerator.h"
#include "CodeGenerator.h"
#include "common/dream_const.h"

/**
 * @class ClassCodeGenerator
 * @brief A specialized code generator for generating class code.
 * This class extends CodeGenerator and provides functionality to manage and generate code for class members.
 */
class ClassCodeGenerator final : public CodeGenerator
{
public:
    /// methods list
    std::vector<std::string> _methods;
    std::vector<std::string>* _current_converting;



    /// Class name
    std::string _class_name;

    /// ClassStructGenerator instance
    ClassStructGenerator _class_struct;

public:
    /**
     * @brief Constructs a ClassCodeGenerator instance with the specified class name.
     * @param class_name The name of the class to generate code for.
     */
    explicit ClassCodeGenerator(const std::string& class_name);

    /**
     * @brief Destructor for ClassCodeGenerator.
     */
    ~ClassCodeGenerator() override;


    /**
     * @brief Generates the code for the class.
     * @return The generated code as a string.
     */
    [[nodiscard]] std::string generate_code() const override;

    /**
     * @brief Gets the current converting member list.
     * @return Pointer to the current converting member list.
     */
    [[nodiscard]] std::vector<std::string>* current_converting() const;

    /**
    * @brief Returns an instance of ClassStructGenerator.
    * This method provides access to the ClassStructGenerator instance, which can be used to generate or manipulate class structures.
    * @return An instance of ClassStructGenerator.
    */
    [[nodiscard]] ClassStructGenerator class_struct() const;

    /**
    * @brief Adds the stmt to the current converting list.
    */
    void add_to_current(const std::string& stmt) const;

 /**
    * @brief Adds the stmt to the current converting list.
    */
    void add_to_current(const char * stmt) const;

    /**
     * @brief Adds the current member to the appropriate list.
     */
    void add_current();

    /**
     * @brief Gets the class name.
     * @return The name of the class.
     */
    [[nodiscard]] std::string class_name() const;
};

#endif //CLASSCODEGENERATOR_H
