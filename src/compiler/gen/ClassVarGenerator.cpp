//
// Created by napbadsen on 24-10-18.
//

#include "ClassVarGenerator.h"
#include <sstream>
#include <utility>

#include "util/parser_util.h"

ClassVarGenerator::ClassVarGenerator()
{
}

ClassVarGenerator::ClassVarGenerator(const ClassMemberVisibility visibility, std::string type, std::string name,
                                     const bool is_mutable, const bool is_nullable, std::string value)
    : _visibility(visibility), _type(std::move(type)), _name(std::move(name)), _is_mutable(is_mutable),
      _is_nullable(is_nullable),
      _value(std::move(value))
{
}

void ClassVarGenerator::setVisibility(ClassMemberVisibility visibility)
{
    _visibility = visibility;
}

void ClassVarGenerator::setType(const std::string& type)
{
    _type = type;
}

void ClassVarGenerator::setName(const std::string& name)
{
    _name = name;
}

void ClassVarGenerator::setIsMutable(bool is_mutable)
{
    _is_mutable = is_mutable;
}

void ClassVarGenerator::setIsNullable(bool is_nullable)
{
    _is_nullable = is_nullable;
}

void ClassVarGenerator::setValue(const std::string& value)
{
    _value = value;
}

ClassMemberVisibility ClassVarGenerator::visibility() const
{
    return _visibility;
}

std::string ClassVarGenerator::type() const
{
    return _type;
}

std::string ClassVarGenerator::name() const
{
    return _name;
}

bool ClassVarGenerator::is_mutable() const
{
    return _is_mutable;
}

bool ClassVarGenerator::is_nullable() const
{
    return _is_nullable;
}

std::string ClassVarGenerator::value() const
{
    return _value;
}

std::string ClassVarGenerator::generate_code() const
{
    std::ostringstream oss;
    // Determine visibility keyword
    // Add mutable keyword if needed
    if (_is_mutable)
        oss << "const ";

    // Add type and name
    oss << _type << " " << _name;

    // Add nullable keyword if needed
    // To Add initial value if provided
    if (!_value.empty())
    {
        oss << " = " << _value;
    }

    // Add semicolon at the end
    oss << "; \n ";

    return oss.str();
}

void ClassVarGenerator::init(DreamParser::ClassVarDeclContext* ctx)
{
    // set up the member modifiers
    vector<DreamParser::ClassMemberModifierContext*> class_member_modifier_contexts = ctx->classMemberModifier();
    for (const auto it : class_member_modifier_contexts)
    {
        if (it->visibilityModifier() != nullptr)
        {
            if (it->visibilityModifier()->PRIVATE())
                setVisibility(ClassMemberVisibility::PRIVATE);
            else if (it->visibilityModifier()->PUBLIC())
                setVisibility(ClassMemberVisibility::PUBLIC);
            else if (it->visibilityModifier()->PROTECTED())
                setVisibility(ClassMemberVisibility::PROTECTED);
        }
        if (it->staticModifier() != nullptr && it->staticModifier()->STATIC())
            _static = true;
    }
    // fill the main body
    string type = ctx->type()->getText();
    setType(parser_util::convert_type_to_cpp(type));
    _name = ctx->IDENTIFIER()->getText();
    if (ctx->VAR())
        _is_mutable = true;
    if (ctx->QUESTION())
        _is_nullable = true;
}
