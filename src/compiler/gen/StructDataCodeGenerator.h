//
// Created by napbadsen on 24-10-9.
//

#ifndef STRUCTDATACODEGENERATOR_H
#define STRUCTDATACODEGENERATOR_H
#include <vector>

#include "CodeGenerator.h"


class StructDataCodeGenerator final : public CodeGenerator{

    std::string _struct_name;
    vector<std::string> _fields;

public:
    StructDataCodeGenerator(const std::string& struct_name);

    [[nodiscard]] std::string generate_code() const override;

    void add_field(std::string type, const std::string& name);
};



#endif //STRUCTDATACODEGENERATOR_H
