//
// Created by napbad on 10/20/24.
//

#ifndef FUNDATAROOTGENERATOR_H
#define FUNDATAROOTGENERATOR_H
#include "CodeGenerator.h"


class FunDataRootGenerator final : public CodeGenerator
{
    std::string _name;
public:

    FunDataRootGenerator();

    void set_name(const std::string& name);

    [[nodiscard]] std::string name() const;

    [[nodiscard]] std::string generate_code() const override;

    static std::string generate_root_link_code(const std::string& type, const std::string& name) ;
};


#endif //FUNDATAROOTGENERATOR_H
