//
// Created by napbadsen on 24-10-11.
//

#ifndef METHODGENERATOR_H
#define METHODGENERATOR_H
#include <string>
#include <vector>

#include "CodeGenerator.h"
#include "parse/DreamParser.h"
#include "util/parser_util.h"


class ClassFunGenerator final : public CodeGenerator
{
    std::vector<FUN_PARAM_TYPE> _params{};

    bool _const = false;
    std::string _name;
    std::string _return_type;

public:

    void init(DreamParser::ClassFuncDeclContext* ctx);

    [[nodiscard]] std::string generate_code() const override;
};

#endif //METHODGENERATOR_H
