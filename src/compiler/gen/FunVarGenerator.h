//
// Created by napbadsen on 24-10-11.
//

#ifndef FUNVARGENERATOR_H
#define FUNVARGENERATOR_H
#include <string>

#include "parse/DreamParser.h"
#include "parse/DreamParserListenerCompiler.h"

class DreamParserListenerCompiler;

class FunVarGenerator final : public CodeGenerator
{
    std::string _name;
    std::string _type;
    std::string _value;
    bool _is_mutable = false;
    bool _is_nullable = false;

    DreamParserListenerCompiler* _listener_compiler;

    void init_with_7_part(DreamParser::FunVarDeclarationContext* ctx);
    void init_with_5_part(DreamParser::FunVarDeclarationContext* ctx);
    void init_with_6_part(DreamParser::FunVarDeclarationContext* ctx);

public:
    explicit FunVarGenerator(DreamParserListenerCompiler* listener_compiler) :
        _listener_compiler(listener_compiler)
    {
    }

    void init(DreamParser::FunVarDeclarationContext* ctx);

    [[nodiscard]] const std::string& name() const;
    [[nodiscard]] const std::string& type() const;
    [[nodiscard]] const std::string& value() const;
    [[nodiscard]] bool is_mutable() const;
    [[nodiscard]] bool is_nullable() const;

    [[nodiscard]] std::string generate_code() const override;
};


#endif //FUNVARGENERATOR_H
