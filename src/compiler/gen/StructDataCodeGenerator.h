//
// Created by napbadsen on 24-10-9.
//

#ifndef STRUCTDATACODEGENERATOR_H
#define STRUCTDATACODEGENERATOR_H

#include <vector>
#include "CodeGenerator.h"

/**
 * @class StructDataCodeGenerator
 * @brief Generates code for a C++ struct data type.
 *
 * This class is responsible for generating code that defines a C++ struct with specified fields.
 * It inherits from the CodeGenerator class and provides methods to add and remove fields.
 */
class StructDataCodeGenerator final : public CodeGenerator
{
    std::string _struct_name;       /**< Name of the struct */
    std::vector<std::string> _fields; /**< Vector containing the struct fields */

public:
    /**
     * @brief Constructs a StructDataCodeGenerator object.
     * @param struct_name Name of the struct.
     */
    explicit StructDataCodeGenerator(const std::string& struct_name);

    /**
     * @brief Generates the code for the struct.
     * @return The generated code as a string.
     */
    [[nodiscard]] std::string generate_code() const override;

    /**
     * @brief Adds a field to the struct.
     * @param type Type of the field.
     * @param name Name of the field.
     */
    void add_field(std::string type, const std::string& name);

    /**
     * @brief Removes a field from the struct.
     * @param field Name of the field to remove.
     */
    void remove(const std::string& field);
};

#endif //STRUCTDATACODEGENERATOR_H
