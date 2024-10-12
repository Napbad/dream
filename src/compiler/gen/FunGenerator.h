//
// Created by napbadsen on 24-10-11.
//

#ifndef FUNGENERATOR_H
#define FUNGENERATOR_H
#include <string>

#include "CodeGenerator.h"
#include "parse/DreamParser.h"
#include "util/parser_util.h"


class FunGenerator : public CodeGenerator{
    std::vector<FUN_PARAM_TYPE> _params{};
    std::string _name;
    std::string _return_type;

public:
    FunGenerator();

    void init(DreamParser::FunctionDeclarationContext* ctx);

    [[nodiscard]] std::string generate_code() const override;
};


#endif //FUNGENERATOR_H
