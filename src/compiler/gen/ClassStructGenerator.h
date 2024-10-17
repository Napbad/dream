//
// Created by napbadsen on 24-10-17.
//

#ifndef CLASSSTRUCTGENERATOR_H
#define CLASSSTRUCTGENERATOR_H
#include <string>
#include <vector>

#include "common/dream_const.h"
#include "./CodeGenerator.h"
#include "ClassFunGenerator.h"

// record the class definition to be used in the generation of header file

class ClassStructGenerator final : public CodeGenerator
{
    std::string _class_name;
    /// Public methods list
    std::vector<std::string> _public_methods;
    /// Private methods list
    std::vector<std::string> _private_methods;
    /// Protected methods list
    std::vector<std::string> _protected_methods;
    /// Public fields list
    std::vector<std::string> _public_fields;
    /// Private fields list
    std::vector<std::string> _private_fields;
    /// Protected fields list
    std::vector<std::string> _protected_fields;
    /// Pointer to the current converting member list
    std::vector<std::string>* _current_converting;

    /// Current member visibility
    ClassMemberVisibility _current_visibility;
    /// Current member type
    ClassMemberType _current_member_type;

public:
    /**
     * @brief Constructs a ClassStructGenerator instance with the specified class name.
     * @param class_name The name of the class to generate code for.
     */
    explicit ClassStructGenerator(const std::string& class_name);

    /**
     * @brief Destructor for ClassStructGenerator.
     */
    ~ClassStructGenerator() override;

    /**
     * @brief Adds a public method to the class.
     * @param method The name of the method to add.
     */
    void add_public_method(const std::string& method);

    /**
     * @brief Adds a private method to the class.
     * @param method The name of the method to add.
     */
    void add_private_method(const std::string& method);

    /**
     * @brief Adds a protected method to the class.
     * @param method The name of the method to add.
     */
    void add_protected_method(const std::string& method);

    /**
     * @brief Adds a public field to the class.
     * @param field The name of the field to add.
     */
    void add_public_field(const std::string& field);

    /**
     * @brief Adds a private field to the class.
     * @param field The name of the field to add.
     */
    void add_private_field(const std::string& field);

    /**
     * @brief Adds a protected field to the class.
     * @param field The name of the field to add.
     */
    void add_protected_field(const std::string& field);

    /**
     * @brief Sets the current visibility for members.
     * @param visibility The visibility to set.
     */
    void set_current_visibility(ClassMemberVisibility visibility);

    /**
     * @brief Sets the current member type.
     * @param type The type to set.
     */
    void set_current_member_type(ClassMemberType type);

    /**
     * @brief Gets the current member type.
     * @return The current member type.
     */
    [[nodiscard]] ClassMemberType current_member_type() const;

    /**
     * @brief Gets the current visibility.
     * @return The current visibility.
     */
    [[nodiscard]] ClassMemberVisibility current_visibility() const;

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
     * @brief Adds the current member to the appropriate list.
     */
    void add_current();

    /**
     * @brief Gets the class name.
     * @return The name of the class.
     */
    std::string class_name();

    /**
       * @brief Adds the stmt to the current converting list.
       */
    void add_to_current(const char* stmt) const;

    /**
      * @brief Adds the stmt to the current converting list.
      */
    void add_to_current(const string& stmt) const;

    /**
     * @brief Adds the stmt to the current converting list.
     */
    void add_to_current(ClassMemberVisibility visibility, const string& stmt);
};


#endif //CLASSSTRUCTGENERATOR_H
