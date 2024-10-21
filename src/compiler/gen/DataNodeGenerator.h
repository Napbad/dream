//
// Created by napbad on 10/21/24.
//

#ifndef DATANODEGENERATOR_H
#define DATANODEGENERATOR_H
#include "CodeGenerator.h"
#include "common/dream_define.h"
#include "util/parser_util.h"


class DataNodeGenerator : public CodeGenerator{

public:
    static std::string generate(const std::string& type, const std::string& name);

    static std::string generate_denode_fun_param(FUN_PARAM_TYPE param);
};



#endif //DATANODEGENERATOR_H
