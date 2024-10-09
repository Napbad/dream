//
// Created by napbad on 9/18/24.
//

#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H


#include <string>

using namespace std;

const string PACKAGE = "// package ";

class CodeGenerator {
public:
    virtual ~CodeGenerator() = default;
    [[nodiscard]] virtual  std::string generate_code() const = 0;
};



#endif //CODEGENERATOR_H
