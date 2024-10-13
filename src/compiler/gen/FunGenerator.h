//
// Created by napbadsen on 24-10-11.
//

#ifndef FUNGENERATOR_H
#define FUNGENERATOR_H

// Include the standard string library
#include <string>

// Include the base code generator class and necessary parsing utilities
#include "CodeGenerator.h"
#include "parse/DreamParser.h"
#include "util/parser_util.h"

/**
 * @brief Generator for functions
 *
 * This class generates code for functions based on the provided parsing context.
 */
class FunGenerator : public CodeGenerator
{
    // Parameters of the function
    std::vector<FUN_PARAM_TYPE> _params{};

    // Name of the function
    std::string _name;

    // Return type of the function
    std::string _return_type;

public:

    /**
     * @brief Default constructor for FunGenerator
     */
    FunGenerator();

    /**
     * @brief Initializes the generator with a parsing context
     *
     * @param ctx Parsing context for the function declaration
     */
    void init(DreamParser::FunctionDeclarationContext* ctx);

    /**
     * @brief Generates the source code for the function
     *
     * @return Generated source code as a string
     */
    [[nodiscard]] std::string generate_code() const override;
};

#endif //FUNGENERATOR_H
