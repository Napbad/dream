//
// Created by napbad on 9/15/24.
//

#ifndef COMPILER_H
#define COMPILER_H
#include "obj/val.h"


class Compiler {
public:
    void compile(const Dval *ast_root, std::string *target);

};



#endif //COMPILER_H
