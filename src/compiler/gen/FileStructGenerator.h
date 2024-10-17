//
// Created by napbadsen on 24-10-17.
//

#ifndef FILESTRUCTGENERATOR_H
#define FILESTRUCTGENERATOR_H
#include <string>
#include <vector>

#include "./CodeGenerator.h"
#include "ClassCodeGenerator.h"


class FileStructGenerator final : public CodeGenerator {

    std::string _name;

    std::vector<std::string> _fun_decl;
    std::vector<std::string> _var_decl;
    std::vector<std::string> _class_decl;

    std::vector<ClassStructGenerator> _class_struct_generators;

public:
    explicit FileStructGenerator(const std::string& name);

    [[nodiscard]] std::string generate_code() const override;

    void add_var_decl(const string& decl);
    void add_fun_decl(const string& decl);

    [[nodiscard]] ClassStructGenerator& get_newest_class_struct_generator();

    void add_new_class_code_generator(const std::string& name);
};



#endif //FILESTRUCTGENERATOR_H
