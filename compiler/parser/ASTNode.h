//
// Created by napbad on 1/9/25.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include <llvm/IR/Value.h>
#include <string>
#include <vector>
#include "common/reserve.h"

namespace dap::parser
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

    llvm::Value *gen();
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
};

// Base class for all AST nodes related to statements
class Statement : public ASTNode
{
  public:
    // Constructor for Statement
    explicit Statement() = default;
};

class QualifiedName final : public Expression
{
  public:
    std::vector<std::string> *name_parts;

    // Constructor for QualifiedName
    QualifiedName() : name_parts(new std::vector<std::string>)
    {
    }

    // Constructor for QualifiedName with a given name
    explicit QualifiedName(std::string names) : name_parts(new std::vector{std::move(names)})
    {
        name_parts->at(0) = std::string(name_parts->at(0).c_str());
    }

    std::string getName() const;
};

class Integer : public Expression
{
  public:
    explicit Integer(int value)
    {
        this->intType = INT;
        this->intValue.signedVal = value;
        this->isSigned = true;
    }

    explicit Integer(unsigned int value)
    {
        this->intType = UNSIGNED_INT;
        this->intValue.unsignedVal = value;
        this->isSigned = false;
    }

    explicit Integer(short value)
    {
        this->intType = SHORT;
        this->intValue.shortVal = value;
        this->isSigned = true;
    }

    explicit Integer(unsigned short value)
    {
        this->intType = UNSIGNED_SHORT;
        this->intValue.unsignedShortVal = value;
        this->isSigned = false;
    }

    explicit Integer(char value)
    {
        this->intType = CHAR;
        this->intValue.charVal = value;
        this->isSigned = true;
    }

    explicit Integer(unsigned char value)
    {
        this->intType = UNSIGNED_CHAR;
        this->intValue.unsignedCharVal = value;
        this->isSigned = false;
    }

    explicit Integer(long value)
    {
        this->intType = LONG;
        this->intValue.longVal = value;
        this->isSigned = true;
    }

    explicit Integer(unsigned long value)
    {
        this->intType = UNSIGNED_LONG;
        this->intValue.unsignedLongVal = value;
        this->isSigned = false;
    }

    explicit Integer(long long value)
    {
        this->intType = LONG_LONG;
        this->intValue.longLongVal = value;
        this->isSigned = true;
    }

    explicit Integer(unsigned long long value)
    {
        this->intType = UNSIGNED_LONG_LONG;
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
        UNSIGNED_INT,
        UNSIGNED_LONG,
        UNSIGNED_LONG_LONG,
        UNSIGNED_SHORT,
        UNSIGNED_CHAR,
        UNSIGNED_BYTE,
        UNSIGNED_FLOAT,
    } intType;
};

class Float : public Expression
{
  public:
    union value {
        float floatVal;
        double doubleVal;
    } floatValue;

    Float(float value)
    {
        this->floatValue.floatVal = value;
    }

    Float(double value)
    {
        this->floatValue.doubleVal = value;
    }
};

class String : public Expression
{
  public:
    std::string stringValue;

    String(std::string value)
    {
        this->stringValue = value;
    }
};

// Represents a program in the AST
class ProgramNode final : public ASTNode
{
  public:
    std::vector<ASTNode *> children{}; // List of child nodes

    QualifiedName *packageName = nullptr;

    struct importedPackageInfo {
        QualifiedName *packageName;
        bool all;
    };

    std::vector<importedPackageInfo *> importedPackages{};

    std::vector<Statement *> statements{};

    // Constructor for ProgramNode
    ProgramNode() = default;

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
    ~FunctionDeclarationNode() override
    {
        delete parameterList;
        delete returnType;
        for (const Statement *stmt : *block) {
            delete stmt;
        }
        delete block;
    }
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
    bool isArray;
    bool isPointer;
    bool isBasicType;
    int arraySize;
    

    BasicType basicType;

    QualifiedName *typeBase;

    TypeNode(QualifiedName *typeBase, bool isArray = false, bool isPointer = false, int arraySize = 0)
        : typeBase(typeBase), isArray(isArray), isPointer(isPointer), arraySize(arraySize)
    {
        isBasicType = false;
    }

    TypeNode(BasicType basicType) : basicType(basicType) {
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
    QualifiedName* variableName;
    bool nullable_;
    bool mutable_;
    TypeNode *type;
    Expression *expression;

    // Constructor for VariableDeclarationNode
    VariableDeclarationNode(
      TypeNode *type,
      Expression *expression,
      QualifiedName* variableName,
      bool nullable = false,
      bool mutable_ = false
    ) :
      nullable_(nullable),
      mutable_(mutable_),
      type(type),
      variableName(variableName),
      expression(expression)
    {
    }

    // Destructor for VariableDeclarationNode
    ~VariableDeclarationNode() override
    {
        delete type;
        if (expression)
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
        if (elseBlock)
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
        if (block)
            delete block;
    }
};

// Represents a struct declaration in the AST
class StructDeclarationNode final : public Statement
{
  public:
    ASTNode *structMemberList;

    // Constructor for StructDeclarationNode
    explicit StructDeclarationNode(const std::string &name) : structMemberList(nullptr)
    {
    }

    // Destructor for StructDeclarationNode
    ~StructDeclarationNode() override
    {
        if (structMemberList)
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
        if (traitMethodList)
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
        if (type)
            delete type;
    }
};
} // namespace dap::parser

#endif // ASTNODE_H