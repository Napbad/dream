//
// Created by napbad on 9/15/24.
//

#include "Compiler.h"

#include "common/enum.h"


void Compiler::compile(const Dval *ast_root, std::string *target) {
    std::cout << "Compiling" << std::endl;

    target->append(
        "#include <iostream>"
        "#include <string>"
        );
    target->append(
        "using namespace std;"
    );

    for (const std::vector<Dval *> * child = ast_root->child(); const auto node : *child) {
        switch (node->type()) {
            case DVAL_INT:
                target->append("int");
                target->append(node->identifier());
                target->append(" = ");
                target->append(node->string_value());
                target->append(";");
                break;
            case DVAL_STR:
                target->append("string");
                target->append(node->identifier());
                target->append(" = ");
                target->append(node->string_value());
                target->append(";");
                break;
            default:
                std::cout << "Unknown type" << std::endl;
        }
    }

    target->append(
        "int main() {"
    );

    target->append(
        "   return 0;"
        "}"
    );
}
