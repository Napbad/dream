//
// Created by napbadsen on 24-10-11.
//

#ifndef FILEVARGENERATOR_H
#define FILEVARGENERATOR_H
#include "CodeGenerator.h"
#include "parse/DreamParser.h"
#include "parse/DreamParserListenerCompiler.h"

class DreamParserListenerCompiler;

class FileVarGenerator : public CodeGenerator
{
    std::string _name;
    std::string _type;
    std::string _value;
    bool _is_mutable = false;
    bool _is_nullable = false;

    DreamParserListenerCompiler* _listener_compiler;

    void init_with_7_part(DreamParser::VarDeclarationContext* ctx);
    void init_with_5_part(DreamParser::VarDeclarationContext* ctx);
    void init_with_6_part(DreamParser::VarDeclarationContext* ctx);

public:
    explicit FileVarGenerator(DreamParserListenerCompiler* listener_compiler) :
        _listener_compiler(listener_compiler)
    {
    }

    void init(DreamParser::VarDeclarationContext* ctx);

    [[nodiscard]] const std::string& name() const;
    [[nodiscard]] const std::string& type() const;
    [[nodiscard]] const std::string& value() const;
    [[nodiscard]] bool is_mutable() const;
    [[nodiscard]] bool is_nullable() const;

    [[nodiscard]] std::string generate_code() const override;
};



#endif //FILEVARGENERATOR_H
