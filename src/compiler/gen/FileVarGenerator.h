//
// Created by napbadsen on 24-10-11.
//

#ifndef FILEVARGENERATOR_H
#define FILEVARGENERATOR_H

// Include the base code generator class
#include "CodeGenerator.h"

// Include necessary parsing components
#include "parse/DreamParser.h"
#include "parse/DreamParserListenerCompiler.h"

/**
 * @brief Listener compiler for the DreamParser
 */
class DreamParserListenerCompiler;

/**
 * @brief Generator for file variables
 *
 * This class generates code for file variables based on the provided parsing context.
 */
class FileVarGenerator : public CodeGenerator
{
    std::string _name;          // Name of the variable
    std::string _type;          // Type of the variable
    std::string _value;         // Value of the variable
    bool _is_mutable = false;   // Indicates if the variable is mutable
    bool _is_nullable = false;  // Indicates if the variable is nullable

    DreamParserListenerCompiler* _listener_compiler;  // Listener compiler for parsing

    // Initialization functions for different parts of the variable declaration
    void init_with_7_part(DreamParser::VarDeclarationContext* ctx);
    void init_with_5_part(DreamParser::VarDeclarationContext* ctx);
    void init_with_6_part(DreamParser::VarDeclarationContext* ctx);

public:
    /**
     * @brief Constructor for FileVarGenerator
     *
     * @param listener_compiler Pointer to the listener compiler
     */
    explicit FileVarGenerator(DreamParserListenerCompiler* listener_compiler) :
        _listener_compiler(listener_compiler)
    {
    }

    /**
     * @brief Initializes the generator with a parsing context
     *
     * @param ctx Parsing context for the variable declaration
     */
    void init(DreamParser::VarDeclarationContext* ctx);

    /**
     * @brief Gets the name of the variable
     *
     * @return Name of the variable
     */
    [[nodiscard]] const std::string& name() const;

    /**
     * @brief Gets the type of the variable
     *
     * @return Type of the variable
     */
    [[nodiscard]] const std::string& type() const;

    /**
     * @brief Gets the value of the variable
     *
     * @return Value of the variable
     */
    [[nodiscard]] const std::string& value() const;

    /**
     * @brief Checks if the variable is mutable
     *
     * @return True if the variable is mutable, false otherwise
     */
    [[nodiscard]] bool is_mutable() const;

    /**
     * @brief Checks if the variable is nullable
     *
     * @return True if the variable is nullable, false otherwise
     */
    [[nodiscard]] bool is_nullable() const;

    /**
     * @brief Generates the source code for the variable
     *
     * @return Generated source code as a string
     */
    [[nodiscard]] std::string generate_code() const override;

    /**
     * @brief Generates the declaration for the variable
     *
     * @return Declaration code as a string
     */
    [[nodiscard]] std::string generate_decl() const;


};

#endif //FILEVARGENERATOR_H
