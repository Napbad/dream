//
// Created by napbadsen on 24-10-18.
//

#ifndef CLASSVARGENERATOR_H
#define CLASSVARGENERATOR_H

#include "CodeGenerator.h"
#include "common/dream_const.h"
#include "parse/DreamParser.h"

class ClassVarGenerator final : public CodeGenerator
{
    ClassMemberVisibility _visibility = ClassMemberVisibility::PRIVATE;
    std::string _type;
    std::string _name;
    bool _static = false;
    bool _is_mutable = false;
    bool _is_nullable = false;
    std::string _value;

public:
    ClassVarGenerator();

    ClassVarGenerator(ClassMemberVisibility visibility, std::string type, std::string name,
                      bool is_mutable,
                      bool is_nullable, std::string value);
    void setVisibility(ClassMemberVisibility visibility);
    void setType(const std::string& type);
    void setName(const std::string& name);
    void setIsMutable(bool is_mutable);
    void setIsNullable(bool is_nullable);
    void setValue(const std::string& value);

    [[nodiscard]] ClassMemberVisibility visibility() const;
    [[nodiscard]] std::string type() const;
    [[nodiscard]] std::string name() const;
    [[nodiscard]] bool is_mutable() const;
    [[nodiscard]] bool is_nullable() const;
    [[nodiscard]] std::string value() const;

    [[nodiscard]] std::string generate_code() const override;
    void init(DreamParser::ClassVarDeclContext* ctx);
};

#endif //CLASSVARGENERATOR_H
