//
// Created by napbad on 1/9/25.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include <llvm/IR/Value.h>
#include <string>
#include <utility>
#include <vector>

#include "common/define_d.h"
#include "common/reserve.h"

#include "utilities/log_util.h"

namespace dap
{

namespace inter_gen
{
class InterGenContext;
}

namespace parser
{

class VariableDeclarationNode;
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

    virtual llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const
    {

#ifdef D_DEBUG
        util::logErr("Unimplement code generation function", ctx, __FILE__, __LINE__);
#else
        util::logErr("Unimplement code generation function", ctx);
#endif
        return nullptr;
    }
};

// Base class for all AST nodes related to expressions
class Expression : public ASTNode
{
};

// Base class for all AST nodes related to statements
class Statement : public ASTNode
{
  public:
    Expression *value = nullptr;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override
    {
        if (value) {
            return value->codeGen(ctx);
        }

#ifdef D_DEBUG
        util::logErr("Unimplement code generation function", ctx, __FILE__, __LINE__);
#else
        util::logErr("Unimplement code generation function", ctx);
#endif
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

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class IntegerNode final : public Expression
{
  public:
    explicit IntegerNode(std::string *value, BasicType type)
    {
        // Check if the value is null
        if (!value) {
            throw std::invalid_argument("Value cannot be null");
        }

        // Determine if the value is signed or unsigned based on the type
        isSigned = (type != BasicType::UBYTE && type != BasicType::USHORT && type != BasicType::UINT &&
                    type != BasicType::ULONG && type != BasicType::ULLONG);

        // Convert the string to the appropriate type based on BasicType
        try {
            switch (type) {
            case BasicType::BYTE:
            case BasicType::UBYTE:
                intValue.charVal = static_cast<char>(std::stoi(*value));
                intType = CHAR;
                break;
            case BasicType::SHORT:
            case BasicType::USHORT:
                intValue.shortVal = static_cast<short>(std::stoi(*value));
                intType = SHORT;
                break;
            case BasicType::INT:
            case BasicType::UINT:
                intValue.signedVal = std::stoi(*value);
                intType = INT;
                break;
            case BasicType::LONG:
            case BasicType::ULONG:
                intValue.longVal = std::stol(*value);
                intType = LONG;
                break;
            case BasicType::LLONG:
            case BasicType::ULLONG:
                intValue.longLongVal = std::stoll(*value);
                intType = LONG_LONG;
                break;
            default:
                throw std::invalid_argument("Unsupported BasicType for IntegerNode");
            }
        } catch (const std::out_of_range &) {
            throw std::out_of_range("Value out of range for the specified BasicType");
        } catch (const std::invalid_argument &) {
            throw std::invalid_argument("Invalid integer value for the specified BasicType");
        }
    }
    /// @brief Retrieves the string representation of the value.
    /// @return Returns a string that represents the current state of the value.
    [[nodiscard]] std::string getVal() const;

    [[nodiscard]] int getBits() const;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;

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
    [[nodiscard]] std::string getValue() const;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class StringNode final : public Expression
{
  public:
    std::string stringValue;

    explicit StringNode(std::string value)
    {
        this->stringValue = std::move(value);
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
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

class BinaryExpressionNode final : public Expression
{
  public:
    Expression *left = nullptr;
    Expression *right = nullptr;
    int operatorType;

    BinaryExpressionNode(Expression *left, int operatorType, Expression *right)
    {
        this->left = left;
        this->right = right;
        this->operatorType = operatorType;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class ArrayExpressionNode final : public Expression
{
  public:
    QualifiedNameNode *expression;
    Expression *index;

    ArrayExpressionNode(QualifiedNameNode *expression, Expression *index) : expression(expression), index(index)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class UnaryExpressionNode final : public Expression
{
  public:
    int operatorType;
    Expression *expression;

    UnaryExpressionNode(int operatorType, Expression *expression) : operatorType(operatorType), expression(expression)
    {
    }
    ~UnaryExpressionNode() override
    {
        delete expression;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class TruncExpressionNode final : public Expression
{
  public:
    Expression *expression;
    TypeNode *targetType;

    explicit TruncExpressionNode(TypeNode *targetType, Expression *expression)
        : targetType(targetType), expression(expression)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

// Represents a program in the AST
class ProgramNode final : public ASTNode
{
  public:
    QualifiedNameNode *packageName = nullptr;

    struct importedPackageInfo {
        QualifiedNameNode *packageName;
        bool all;
    };

    std::vector<importedPackageInfo *> *importedPackages{};

    std::vector<Statement *> *statements{};

    // Constructor for ProgramNode
    ProgramNode()
    {
        importedPackages = new std::vector<importedPackageInfo *>();
    };

    explicit ProgramNode(std::vector<Statement *> *statements) : statements(statements)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;

    // Destructor for ProgramNode
    ~ProgramNode() override
    {
        for (const ASTNode *statement : *statements) {
            delete statement;
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
    std::vector<VariableDeclarationNode *> *parameterList;
    TypeNode *returnType;
    std::vector<Statement *> *block;

    // Constructor for FunctionDeclarationNode
    FunctionDeclarationNode(std::string &name, std::vector<VariableDeclarationNode *> *parameterList,
                            TypeNode *returnType, std::vector<Statement *> *block)
        : name(std::move(name)), parameterList(parameterList), returnType(returnType), block(block)
    {
    }

    // Destructor for FunctionDeclarationNode
    ~FunctionDeclarationNode() override;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
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
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
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
    [[nodiscard]]
    std::string getName() const;

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
    Expression *initialValue;

    // Constructor for VariableDeclarationNode
    VariableDeclarationNode(TypeNode *type, Expression *initialValue, QualifiedNameNode *variableName,
                            bool nullable = false, bool mutable_ = false)
        : nullable_(nullable), mutable_(mutable_), type(type), variableName(variableName), initialValue(initialValue)
    {
    }

    // Destructor for VariableDeclarationNode
    ~VariableDeclarationNode() override
    {
        delete type;
        delete initialValue;
    }
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;

    void generateVariable(llvm::Value *value);

  private:
    bool variableGenerated = false;
    llvm::Value *variableGenerateValue = nullptr;
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

    // Destructor for F

    // Destructor foorLoopNode
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
    Expression *conditionExpression;
    std::vector<Statement *> *thenBlock;
    std::vector<Statement *> *elseBlock;
    Statement *elseIf;

    // Constructor for IfStatementNode
    IfStatementNode(Expression *conditionExpression, std::vector<Statement *> *thenBlock,
                    std::vector<Statement *> *elseBlock = nullptr, Statement *elseIf = nullptr)
        : conditionExpression(conditionExpression), thenBlock(thenBlock), elseBlock(elseBlock), elseIf(elseIf)
    {
    }

    // Destructor for IfStatementNode
    ~IfStatementNode() override
    {
        delete conditionExpression;
        delete thenBlock;
        delete elseBlock;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};

class ForStatementNode final : public Statement
{
  public:
    VariableDeclarationNode *conditionDeclaration;
    Expression *condition;
    Expression *variableChange;
    std::vector<Statement *> *block;

    // Constructor for ForStatementNode
    ForStatementNode(VariableDeclarationNode *conditionDeclaration, Expression *condition, Expression *variableChange,
                     std::vector<Statement *> *block)
        : conditionDeclaration(conditionDeclaration), condition(condition), variableChange(variableChange), block(block)
    {
    }

    // Destructor for ForStatementNode
    ~ForStatementNode() override
    {
        delete condition;
        delete block;
        delete variableChange;
        delete conditionDeclaration;
    }
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
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

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
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

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) const override;
};
} // namespace parser
} // namespace dap

#endif // ASTNODE_H