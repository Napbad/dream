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
#include "common/dream_const.h"
#include "common/dream_define.h"
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

    ClassMemberVisibility _visibility = ClassMemberVisibility::PROTECTED;

    // Indicates whether the function is const
    bool _const = false;

    // Name of the function
    std::string _name;

    bool _static = false;

    // Return type of the function
    std::string _return_type;

    std::string _class_name;

    std::vector<std::string> _stmts{};

public:
    /**
     * @brief Initializes the generator with a parsing context
     *
     * @param ctx Parsing context for the class function declaration
     */
    void init(DreamParser::ClassFuncDeclContext* ctx, const std::string& class_name);

    /**
     * @brief Generates the source code for the method
     *
     * @return Generated source code as a string
     */
    [[nodiscard]] std::string generate_code() const override;

    /**
     * @brief Generates the source code for the method
     *
     * @return Generated source code as a string
     */
    [[nodiscard]] std::string generate_decl_code() const;

    [[nodiscard]] ClassMemberVisibility visibility() const;
    void add_stmt(const string& string);
    std::string name();
};

#endif //METHODGENERATOR_H
