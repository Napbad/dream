//
// Created by napbad on 9/18/24.
//

#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

// Include the standard string library
#include <string>

// Use the standard namespace for convenience
using namespace std;

// Constant string for package declaration
const string PACKAGE = "// package ";

/**
 * @brief Base class for code generators
 *
 * This class provides an interface for generating code.
 */
class CodeGenerator {
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~CodeGenerator() = default;

    /**
     * @brief Generates the source code
     *
     * This pure virtual function must be implemented by derived classes to generate the actual code.
     *
     * @return The generated source code as a string
     */
    [[nodiscard]] virtual std::string generate_code() const = 0;
};

#endif //CODEGENERATOR_H
