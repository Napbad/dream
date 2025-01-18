//
// Created by napbad on 1/9/25.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include "common/reserve.h"
#include <llvm/IR/Value.h>
#include <string>
#include <utility>
#include <vector>

namespace dap
{

namespace inter_gen
{
class InterGenContext;
}

namespace parser
{

class TypeNode;

// Basic AST Node
class ASTNode
{
  public:
    std::string sourceFilePath;
    int lineNum;

    // Constructor for ASTNode
    ASTNode() : lineNum(0)
    {
    }

    // Destructor for ASTNode
    virtual ~ASTNode() = default;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx);
};

// Base class for all AST nodes related to expressions
class Expression : public ASTNode
{
  public:
    // Constructor for Expression
    explicit Expression() = default;
    // Destructor for Expression
    ~Expression() override
    {
        for (const ASTNode *child : children) {
            delete child;
        }
    }
    std::vector<ASTNode *> children;
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx)
    {
        return nullptr;
    }
};

// Base class for all AST nodes related to statements
class Statement : public ASTNode
{
  public:
    // Constructor for Statement

    Expression *value = nullptr;

    explicit Statement() = default;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx)
    {
        if (value != nullptr) {
            return value->codeGen(ctx);
        }

        return nullptr;
    }
};

class QualifiedNameNode final : public Expression
{
  public:
    std::vector<std::string> *name_parts;

    // Constructor for QualifiedNameNode
    QualifiedNameNode() : name_parts(new std::vector<std::string>)
    {
    }

    // Constructor for QualifiedNameNode with a given name
    explicit QualifiedNameNode(std::string names) : name_parts(new std::vector{std::move(names)})
    {
        name_parts->at(0) = std::string(name_parts->at(0).c_str());
    }

    [[nodiscard]] std::string getName() const;
};

class IntegerNode final : public Expression
{
  public:
    explicit IntegerNode(int value)
    {
        this->intType = INT;
        this->intValue.signedVal = value;
        this->isSigned = true;
    }

    explicit IntegerNode(unsigned int value)
    {
        this->intType = INT;
        this->intValue.unsignedVal = value;
        this->isSigned = false;
    }

    explicit IntegerNode(short value)
    {
        this->intType = SHORT;
        this->intValue.shortVal = value;
        this->isSigned = true;
    }

    explicit IntegerNode(unsigned short value)
    {
        this->intType = SHORT;
        this->intValue.unsignedShortVal = value;
        this->isSigned = false;
    }

    explicit IntegerNode(char value)
    {
        this->intType = CHAR;
        this->intValue.charVal = value;
        this->isSigned = true;
    }

    explicit IntegerNode(unsigned char value)
    {
        this->intType = CHAR;
        this->intValue.unsignedCharVal = value;
        this->isSigned = false;
    }

    explicit IntegerNode(long value)
    {
        this->intType = LONG;
        this->intValue.longVal = value;
        this->isSigned = true;
    }

    explicit IntegerNode(unsigned long value)
    {
        this->intType = LONG;
        this->intValue.unsignedLongVal = value;
        this->isSigned = false;
    }

    explicit IntegerNode(long long value)
    {
        this->intType = LONG_LONG;
        this->intValue.longLongVal = value;
        this->isSigned = true;
    }

    explicit IntegerNode(unsigned long long value)
    {
        this->intType = LONG_LONG;
        this->intValue.unsignedLongLongVal = value;
        this->isSigned = false;
    }

    /// @brief Retrieves the string representation of the value.
    /// @return Returns a string that represents the current state of the value.
    std::string getVal();

  private:
    union value {
        int signedVal;
        unsigned int unsignedVal;
        short shortVal;
        unsigned short unsignedShortVal;
        char charVal; // used as byte type
        unsigned char unsignedCharVal;
        long longVal;
        unsigned long unsignedLongVal;
        long long longLongVal;
        unsigned long long unsignedLongLongVal;
    } intValue{};

    bool isSigned;

    enum {
        INT,
        LONG,
        SHORT,
        CHAR,
        BYTE,
        FLOAT,
        DOUBLE,
        LONG_LONG,
    } intType;
};

class FloatNode : public Expression
{
  public:
    union value {
        float floatVal;
        double doubleVal;
    } floatValue{};

    bool isDouble;

    explicit FloatNode(float value)
    {
        this->floatValue.floatVal = value;
        this->isDouble = false;
    }

    explicit FloatNode(double value)
    {
        this->floatValue.doubleVal = value;
        this->isDouble = true;
    }
};

class String final : public Expression
{
  public:
    std::string stringValue;

    explicit String(std::string value)
    {
        this->stringValue = std::move(value);
    }
};

class BoolNode final : public Expression
{
  public:
    bool boolValue;

    explicit BoolNode(bool value)
    {
        this->boolValue = value;
    }
};

// Represents a program in the AST
class ProgramNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> children{}; // List of child nodes

    QualifiedNameNode *packageName = nullptr;

    struct importedPackageInfo {
        QualifiedNameNode *packageName;
        bool all;
    };

    std::vector<importedPackageInfo *> importedPackages{};

    std::vector<Statement *> statements{};

    // Constructor for ProgramNode
    ProgramNode() = default;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx);

    // Destructor for ProgramNode
    ~ProgramNode() override
    {
        for (const ASTNode *child : children) {
            delete child;
        }
    }
};

// Represents a package declaration in the AST
class PackageDeclarationNode final : public Statement
{
  public:
    // Constructor for PackageDeclarationNode
    explicit PackageDeclarationNode(const std::string &name);
};

// Represents an import declaration in the AST
class ImportDeclarationNode final : public ASTNode
{
  public:
    // Constructor for ImportDeclarationNode
    explicit ImportDeclarationNode(const std::string &name);
};

// Represents a function declaration in the AST
class FunctionDeclarationNode final : public Statement
{
  public:
    std::string name;
    std::vector<Expression *> *parameterList;
    TypeNode *returnType;
    std::vector<Statement *> *block;

    // Constructor for FunctionDeclarationNode
    FunctionDeclarationNode(std::string &name, std::vector<Expression *> *parameterList, TypeNode *returnType,
                            std::vector<Statement *> *block)
        : name(std::move(name)), parameterList(parameterList), returnType(returnType), block(block)
    {
    }

    // Destructor for FunctionDeclarationNode
    ~FunctionDeclarationNode() override;
};

// Represents a parameter list in the AST
class ParameterListNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> parameters;

    // Constructor for ParameterListNode
    ParameterListNode();

    // Destructor for ParameterListNode
    ~ParameterListNode() override
    {
        for (const ASTNode *param : parameters) {
            delete param;
        }
    }
};

// Represents a parameter in the AST
class ParameterNode final : public ASTNode
{
  public:
    ASTNode *modifier;
    ASTNode *type;

    // Constructor for ParameterNode
    explicit ParameterNode(const std::string &name) : modifier(nullptr), type(nullptr)
    {
    }

    // Destructor for ParameterNode
    ~ParameterNode() override
    {
        delete modifier;
        delete type;
    }
};

class FunctionCallExpressionNode final : public Expression
{
  public:
    QualifiedNameNode *name;
    std::vector<Expression *> *args;

    // Constructor for FunctionCallExpressionNode
    FunctionCallExpressionNode(QualifiedNameNode *name, std::vector<Expression *> *args) : name(name), args(args)
    {
    }

    // Destructor for FunctionCallExpressionNode
    ~FunctionCallExpressionNode() override
    {
        delete name;
        for (auto arg : *args) {
            delete arg;
        }
        delete args;
    }
};

// Represents a return type in the AST
class ReturnTypeNode final : public ASTNode
{
  public:
    // Constructor for ReturnTypeNode
    explicit ReturnTypeNode(const std::string &type);
};

// Represents a type in the AST
class TypeNode final : public ASTNode
{
  public:
    // Constructor for TypeNode
    bool isArray{};
    bool isPointer{};
    bool isBasicType;
    int arraySize{};

    BasicType basicType = BasicType::UNKNOWN;

    QualifiedNameNode *typeBase{};

    explicit TypeNode(QualifiedNameNode *typeBase, bool isArray = false, bool isPointer = false, int arraySize = 0)
        : typeBase(typeBase), isArray(isArray), isPointer(isPointer), arraySize(arraySize)
    {
        isBasicType = false;
    }

    explicit TypeNode(BasicType basicType) : basicType(basicType)
    {
        isBasicType = true;
    }

    explicit TypeNode(const std::string &type);
};

// Represents a code block in the AST
class BlockNode final : public Statement
{
  public:
    ASTNode *statementList;

    // Constructor for BlockNode
    BlockNode() : statementList(nullptr)
    {
    }

    // Destructor for BlockNode
    ~BlockNode() override
    {
        delete statementList;
    }
};

class ConstantDeclarationNode final : public Statement
{
  public:
    TypeNode *type;
    QualifiedNameNode *name;
    Expression *value;

    // Constructor for StatementListNode
    ConstantDeclarationNode(TypeNode *typeInput, QualifiedNameNode *nameInput, Expression *valueInput)
        : type(typeInput), name(nameInput), value(valueInput)
    {
    }

    // Destructor for StatementListNode
    ~ConstantDeclarationNode() override
    {
        delete name;
        delete value;
    }
};

// Represents a statement list in the AST
class StatementListNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> statements;

    // Constructor for StatementListNode
    StatementListNode();

    // Destructor for StatementListNode
    ~StatementListNode() override
    {
        for (const ASTNode *stmt : statements) {
            delete stmt;
        }
    }
};

// Represents a variable declaration in the AST
class VariableDeclarationNode final : public Statement
{
  public:
    QualifiedNameNode *variableName;
    bool nullable_;
    bool mutable_;
    TypeNode *type;
    Expression *expression;

    // Constructor for VariableDeclarationNode
    VariableDeclarationNode(TypeNode *type, Expression *expression, QualifiedNameNode *variableName,
                            bool nullable = false, bool mutable_ = false)
        : nullable_(nullable), mutable_(mutable_), type(type), variableName(variableName), expression(expression)
    {
    }

    // Destructor for VariableDeclarationNode
    ~VariableDeclarationNode() override
    {
        delete type;
        delete expression;
    }
};

// Represents a for loop in the AST
class ForLoopNode final : public Statement
{
  public:
    ASTNode *type;
    ASTNode *identifier;
    ASTNode *initExpression;
    ASTNode *conditionExpression;
    ASTNode *incrementExpression;
    ASTNode *block;

    // Constructor for ForLoopNode
    ForLoopNode()
        : type(nullptr), identifier(nullptr), initExpression(nullptr), conditionExpression(nullptr),
          incrementExpression(nullptr), block(nullptr)
    {
    }

    // Destructor for ForLoopNode
    ~ForLoopNode() override
    {
        delete type;
        delete identifier;
        delete initExpression;
        delete conditionExpression;
        delete incrementExpression;
        delete block;
    }
};

// Represents an if statement in the AST
class IfStatementNode final : public Statement
{
  public:
    ASTNode *conditionExpression;
    ASTNode *thenBlock;
    ASTNode *elseBlock;

    // Constructor for IfStatementNode
    IfStatementNode() : conditionExpression(nullptr), thenBlock(nullptr), elseBlock(nullptr)
    {
    }

    // Destructor for IfStatementNode
    ~IfStatementNode() override
    {
        delete conditionExpression;
        delete thenBlock;
        delete elseBlock;
    }
};

// Represents a match statement in the AST
class MatchStatementNode final : public Statement
{
  public:
    ASTNode *expression;
    ASTNode *matchCaseList;

    // Constructor for MatchStatementNode
    MatchStatementNode() : expression(nullptr), matchCaseList(nullptr)
    {
    }

    // Destructor for MatchStatementNode
    ~MatchStatementNode() override
    {
        delete expression;
        delete matchCaseList;
    }
};

// Represents a match case list in the AST
class MatchCaseListNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> matchCases;

    // Constructor for MatchCaseListNode
    MatchCaseListNode();

    // Destructor for MatchCaseListNode
    ~MatchCaseListNode() override
    {
        for (const ASTNode *matchCase : matchCases) {
            delete matchCase;
        }
    }
};

// Represents a match case in the AST
class MatchCaseNode final : public ASTNode
{
  public:
    ASTNode *block;

    // Constructor for MatchCaseNode
    explicit MatchCaseNode(const std::string &name) : block(nullptr)
    {
    }

    // Destructor for MatchCaseNode
    ~MatchCaseNode() override
    {

        delete block;
    }
};

// Represents a struct declaration in the AST
class StructDeclarationNode final : public Statement
{
  public:
    QualifiedNameNode *name;
    std::vector<VariableDeclarationNode *> *structMemberList;

    // Constructor for StructDeclarationNode
    explicit StructDeclarationNode(QualifiedNameNode *nameInput,
                                   std::vector<VariableDeclarationNode *> *structMemberListInput)
        : name(nameInput), structMemberList(structMemberListInput)
    {
    }

    // Destructor for StructDeclarationNode
    ~StructDeclarationNode() override
    {

        delete structMemberList;
    }
};

// Represents a struct member list in the AST
class StructMemberListNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> structMembers;

    // Constructor for StructMemberListNode
    StructMemberListNode();

    // Destructor for StructMemberListNode
    ~StructMemberListNode() override
    {
        for (const ASTNode *structMember : structMembers) {
            delete structMember;
        }
    }
};

// Represents a struct member in the AST
class StructMemberNode final : public ASTNode
{
  public:
    ASTNode *modifier;
    ASTNode *type;

    // Constructor for StructMemberNode
    explicit StructMemberNode(const std::string &name) : modifier(nullptr), type(nullptr)
    {
    }

    // Destructor for StructMemberNode
    ~StructMemberNode() override
    {
        delete modifier;
        delete type;
    }
};

// Represents a trait declaration in the AST
class TraitDeclarationNode final : public Statement
{
  public:
    ASTNode *traitMethodList;

    // Constructor for TraitDeclarationNode
    explicit TraitDeclarationNode(const std::string &name) : traitMethodList(nullptr)
    {
    }

    // Destructor for TraitDeclarationNode
    ~TraitDeclarationNode() override
    {

        delete traitMethodList;
    }
};

// Represents a trait method list in the AST
class TraitMethodListNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> traitMethods;

    // Constructor for TraitMethodListNode
    TraitMethodListNode();

    // Destructor for TraitMethodListNode
    ~TraitMethodListNode() override
    {
        for (const ASTNode *traitMethod : traitMethods) {
            delete traitMethod;
        }
    }
};

// Represents a trait method in the AST
class TraitMethodNode final : public ASTNode
{
  public:
    ASTNode *parameterList;
    ASTNode *returnType;

    // Constructor for TraitMethodNode
    explicit TraitMethodNode(const std::string &name) : parameterList(nullptr), returnType(nullptr)
    {
    }

    // Destructor for TraitMethodNode
    ~TraitMethodNode() override
    {
        delete parameterList;
        delete returnType;
    }
};

// Represents a type definition in the AST
class TypeDefinitionNode final : public ASTNode
{
  public:
    ASTNode *type;

    // Constructor for TypeDefinitionNode
    explicit TypeDefinitionNode(const std::string &name) : type(nullptr)
    {
    }

    // Destructor for TypeDefinitionNode
    ~TypeDefinitionNode() override
    {

        delete type;
    }
};

class ReturnStatementNode final : public Statement
{
  public:
    Expression *expression;

    // Constructor for ReturnStatementNode
    explicit ReturnStatementNode(Expression *exprInput) : expression(exprInput)
    {
    }

    // Destructor for ReturnStatementNode
    ~ReturnStatementNode() override
    {

        delete expression;
    }
};
} // namespace parser
} // namespace dap

#endif // ASTNODE_H