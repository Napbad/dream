/**
 * @brief Method Generator Header File
 *
 * This header file defines a class `ClassFunGenerator` used for generating class method code.
 * It inherits from `CodeGenerator` and is used to generate source code for methods within a given parsing context.
 *
 * Created by napbadsen on 24-10-11.
 */

#ifndef METHODGENERATOR_H
#define METHODGENERATOR_H

// Includes standard library headers for string and vector operations
#include <string>
#include <vector>

// Include necessary headers for the code generation framework
#include "CodeGenerator.h"
#include "parse/DreamParser.h"
#include "util/parser_util.h"

/**
 * @brief Class for generating class methods
 *
 * This class is responsible for initializing and generating the source code for class methods.
 */
class ClassFunGenerator final : public CodeGenerator
{
    // Stores parameters of the function
    std::vector<FUN_PARAM_TYPE> _params{};

    // Indicates whether the function is const
    bool _const = false;

    // Name of the function
    std::string _name;

    // Return type of the function
    std::string _return_type;

public:

    /**
     * @brief Initializes the generator with a parsing context
     *
     * @param ctx Parsing context for the class function declaration
     */
    void init(DreamParser::ClassFuncDeclContext* ctx);

    /**
     * @brief Generates the source code for the method
     *
     * @return Generated source code as a string
     */
    [[nodiscard]] std::string generate_code() const override;
};

#endif //METHODGENERATOR_H
