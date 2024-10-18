/**
 * @file FunVarGenerator.h
 * @brief Defines the FunVarGenerator class for generating function variable code.
 *
 * This file contains the declaration of the FunVarGenerator class, which is responsible
 * for generating code for function variables based on different declaration contexts.
 * The FunVarGenerator class inherits from the CodeGenerator class.
 */

#ifndef FUNVARGENERATOR_H
#define FUNVARGENERATOR_H

#include <string>
#include "parse/DreamParser.h"
#include "parse/DreamParserListenerCompiler.h"

class DreamParserListenerCompiler;

class FunVarGenerator final : public CodeGenerator
{
    std::string _name; /**< Variable name */
    std::string _type; /**< Variable type */
    std::string _value; /**< Variable value or initialization expression */
    bool _is_mutable = false; /**< Indicates if the variable is mutable */
    bool _is_nullable = false; /**< Indicates if the variable can be null */

    DreamParserListenerCompiler* _listener_compiler; /**< Pointer to the listener compiler */

    /**
     * @brief Initializes the generator with a seven-part declaration context.
     * @param ctx Pointer to the declaration context.
     */
    void init_with_7_part(const DreamParser::FunVarDeclarationContext* ctx);

    /**
     * @brief Initializes the generator with a five-part declaration context.
     * @param ctx Pointer to the declaration context.
     */
    void init_with_5_part(const DreamParser::FunVarDeclarationContext* ctx);

    /**
     * @brief Initializes the generator with a six-part declaration context.
     * @param ctx Pointer to the declaration context.
     */
    void init_with_6_part(const DreamParser::FunVarDeclarationContext* ctx);
    /**
    * @brief Initializes the generator with a parsing context
    *
    * @param ctx Parsing context for the variable declaration
    */
    void init_with_4_part(const DreamParser::FunVarDeclarationContext* ctx);

    /**
    * @brief Initializes the generator with a parsing context
    *
    * @param ctx Parsing context for the variable declaration
    */
    void init_with_3_part(const DreamParser::FunVarDeclarationContext* ctx);

public:
    /**
     * @brief Constructs a FunVarGenerator object.
     * @param listener_compiler Pointer to the listener compiler.
     */
    explicit FunVarGenerator(DreamParserListenerCompiler* listener_compiler) :
        _listener_compiler(listener_compiler)
    {
    }

    /**
     * @brief Initializes the generator with the given declaration context.
     * @param ctx Pointer to the declaration context.
     */
    void init(const DreamParser::FunVarDeclarationContext* ctx);

    /**
     * @brief Returns the variable name.
     * @return A reference to the variable name string.
     */
    [[nodiscard]] const std::string& name() const;

    /**
     * @brief Returns the variable type.
     * @return A reference to the variable type string.
     */
    [[nodiscard]] const std::string& type() const;

    /**
     * @brief Returns the variable value or initialization expression.
     * @return A reference to the variable value string.
     */
    [[nodiscard]] const std::string& value() const;

    /**
     * @brief Checks if the variable is mutable.
     * @return True if the variable is mutable, false otherwise.
     */
    [[nodiscard]] bool is_mutable() const;

    /**
     * @brief Checks if the variable is nullable.
     * @return True if the variable is nullable, false otherwise.
     */
    [[nodiscard]] bool is_nullable() const;

    /**
     * @brief Generates the code for the function variable.
     * @return The generated code as a string.
     */
    [[nodiscard]] std::string generate_code() const override;
};

#endif //FUNVARGENERATOR_H
