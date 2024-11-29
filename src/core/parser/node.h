//
// Created by napbad on 10/25/24.
//
#ifndef NODE_H
#define NODE_H

#include "../inter_gen/codegen_inter.h"
#include "../utilities/string_util.h"
#include "node_meta_data.h"
#include <llvm/IR/Function.h>
#include <llvm/IR/Value.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace dream
{
namespace inter_gen
{
class InterGenContext;
} // namespace inter_gen

namespace parser
{

class ElifStmt;
class Stmt;
class Program;
class BlockStmt;
class NodeMetadata;
enum class NodeMetaDataType;

typedef std::vector<Stmt *> stmt_list;

class Node
{
  public:
    Node() = default;
    NodeMetadata *metadata = nullptr;
    virtual ~Node() = default;
    virtual llvm::Value *codeGen(inter_gen::InterGenContext *ctx)
    {
        return nullptr;
    }
    virtual bool isa(NodeMetaDataType type);
};

class Stmt : public Node
{
};

class Expr : public Node
{
};
// for a qualifiedName, its' result of codeGen function is a value, rather than its's address
class QualifiedName : public Expr
{
  public:
    std::vector<std::string> *name_parts;

    QualifiedName() : name_parts(new std::vector<std::string>)
    {
    }
    explicit QualifiedName(std::vector<std::string> *names) : name_parts(names)
    {
    }
    explicit QualifiedName(std::string names) : name_parts(new std::vector<std::string>{std::move(names)})
    {
    }

    [[nodiscard]] std::string getName() const
    {
        return util::get_text_from_vector(*name_parts);
    }

    [[nodiscard]] std::string getName(int idx) const
    {
        return name_parts->at(idx);
    }

    [[nodiscard]] std::string getFirstName() const
    {
        return name_parts->at(0);
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class DoubleExpr : public Expr
{
  public:
    double value;

    explicit DoubleExpr(double value) : value(value)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class IntegerExpr : public Expr
{
  public:
    long long value;

    explicit IntegerExpr(long long value) : value(value)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class StringExpr : public Expr
{
  public:
    std::string value;

    explicit StringExpr(std::string value) : value(std::move(value))
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class VarExpr : public Expr
{
  public:
    QualifiedName *name;

    explicit VarExpr(QualifiedName *name) : name(name)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;

    ~VarExpr() override
    {
        delete name;
    }
};

class BinaryExpr : public Expr
{
  public:
    int op;
    Expr *lhs;
    Expr *rhs;

    BinaryExpr(int op, Expr *lhs, Expr *rhs) : op(op), lhs(lhs), rhs(rhs)
    {
    }

    ~BinaryExpr() override
    {
        delete lhs;
        delete rhs;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class UnaryExpr : public Expr
{
  public:
    int op;
    Expr *operand;

    UnaryExpr(int op, Expr *operand) : op(op), operand(operand)
    {
    }

    ~UnaryExpr() override
    {
        delete operand;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ListExpr : public Expr
{
  public:
    std::vector<Expr *> *elements;

    explicit ListExpr(std::vector<Expr *> *elements) : elements(elements)
    {
    }

    ~ListExpr() override
    {
        delete elements;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class PointerExpr : public Node
{
  public:
    Node *baseVal;

    // Constructor that initializes the base type
    explicit PointerExpr(Node *baseVal) : baseVal(baseVal)
    {
    }

    // Destructor that deletes the base type to avoid memory leaks
    ~PointerExpr() override
    {
        delete baseVal;
    }

    // Generates the corresponding LLVM IR type for the pointer
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ArrayExpr : public Expr
{
  public:
    Expr *idx;
    QualifiedName *name;

    ArrayExpr(Expr *idx, QualifiedName *name) : idx(idx), name(name)
    {
    }

    ~ArrayExpr() override
    {
        delete name;
        delete idx;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class CallExpr : public Expr
{
  public:
    QualifiedName *callee;
    std::vector<Expr *> args;

    CallExpr(QualifiedName *callee, std::vector<Expr *> args) : callee(callee), args(std::move(args))
    {
    }

    ~CallExpr() override
    {
        delete callee;
        for (auto *arg : args)
        {
            delete arg;
        }
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class AssignExpr : public Stmt
{
  public:
    QualifiedName *lhs;
    Expr *rhs;

    AssignExpr(QualifiedName *lhs, Expr *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    ~AssignExpr() override
    {
        delete lhs;
        delete rhs;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ArrayAssignExpr: public Stmt
{
public:
    QualifiedName *lhs;
    Expr *idx;
    Expr *rhs;
    ArrayAssignExpr(QualifiedName *lhs, Expr *idx, Expr *rhs) : lhs(lhs), idx(idx), rhs(rhs)
    {
    }
    ~ArrayAssignExpr() override
    {
        delete lhs;
        delete idx;
        delete rhs;
    }
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class BlockStmt : public Stmt
{
  public:
    std::vector<Stmt *> stmts;

    BlockStmt() = default;
    explicit BlockStmt(std::vector<Stmt *> stmts) : stmts(std::move(stmts))
    {
    }

    ~BlockStmt() override
    {
        for (auto *stmt : stmts)
        {
            delete stmt;
        }
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class IncludeStmt : public Stmt
{
  public:
    QualifiedName* path;

    explicit IncludeStmt(QualifiedName* path) : path(path)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class PackageStmt : public Stmt
{
  public:
    QualifiedName *name;

    explicit PackageStmt(QualifiedName *name) : name(name)
    {
    }

    ~PackageStmt() override
    {
        delete name;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ExprStmt : public Stmt
{
  public:
    Expr *expr;

    explicit ExprStmt(Expr *expr) : expr(expr)
    {
    }

    ~ExprStmt() override
    {
        delete expr;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ReturnStmt : public Stmt
{
  public:
    Expr *expr;

    explicit ReturnStmt(Expr *expr) : expr(expr)
    {
    }

    ~ReturnStmt() override
    {
        delete expr;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class BreakStmt : public Stmt
{
  public:
    Expr *expr;
    BreakStmt() : expr(nullptr)
    {
    }
    explicit BreakStmt(Expr *expr) : expr(expr)
    {
    }
    ~BreakStmt() override
    {
        delete expr;
    }
    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class VarDecl : public Stmt
{
  public:
    bool is_mutable;
    bool is_nullable;
    QualifiedName *type;
    QualifiedName *name;
    Expr *init;
    Expr *size; // only for array types

    VarDecl(QualifiedName *type, QualifiedName *name, const bool is_mutable, const bool is_nullable, Expr *init,
            Expr *size = nullptr)
        : is_mutable(is_mutable), is_nullable(is_nullable), type(type), name(name), init(init), size(size)
    {
    }

    ~VarDecl() override
    {
        delete type;
        delete name;
        delete init;
    }

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] const QualifiedName *getQualifiedName() const;

    [[nodiscard]] const QualifiedName *getType() const;

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ProtoDecl : public Stmt
{
  public:
    std::vector<VarDecl *> params;
    const QualifiedName *return_type;
    QualifiedName *name;
    ProtoDecl(const QualifiedName *return_type, QualifiedName *name, std::vector<VarDecl *> params)
        : return_type(return_type), name(name), params(std::move(params))
    {
    }

    ~ProtoDecl() override
    {
        for (auto *param : params)
        {
            delete param;
        }
        delete name;
        delete return_type;
    };

    llvm::Function *codeGen(inter_gen::InterGenContext *ctx) override;
};

class FuncDecl : public Stmt
{
  public:
    ProtoDecl *proto;
    BlockStmt *body;

    FuncDecl(QualifiedName *type, QualifiedName *name, std::vector<VarDecl *> params, BlockStmt *body)
        : proto(new ProtoDecl(type, name, std::move(params))), body(body)
    {
    }

    ~FuncDecl() override
    {
        delete proto;
        delete body;
    }

    llvm::Function *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ExternDecl : public Stmt
{
  public:
    ProtoDecl *proto;
    ExternDecl(QualifiedName *type, QualifiedName *name, std::vector<VarDecl *> params)
        : proto(new ProtoDecl(type, name, std::move(params)))
    {
    }

    ~ExternDecl() override
    {
        delete proto;
    }

    llvm::Function *codeGen(inter_gen::InterGenContext *ctx) override;
};

class Program : public Stmt
{
  public:
    BlockStmt *stmts;

    explicit Program(BlockStmt *stmts) : stmts(stmts)
    {
    }

    ~Program() override
    {
        delete stmts;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class IfStmt : public Stmt
{
  public:
    Expr *cond;
    BlockStmt *body;
    BlockStmt *else_body;

    std::vector<Stmt *> *elif_stmts{};

    IfStmt(Expr *cond, BlockStmt *body, BlockStmt *else_body = nullptr, std::vector<Stmt *> *elif_stmts = {})
        : cond(cond), body(body), else_body(else_body)
    {
    }

    ~IfStmt() override
    {
        delete cond;
        delete body;
        delete else_body;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ElifStmt : public Stmt
{
  public:
    Expr *cond;
    BlockStmt *body;

    ElifStmt(Expr *cond, BlockStmt *body) : cond(cond), body(body)
    {
    }

    ~ElifStmt() override
    {
        delete cond;
        delete body;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class ForStmt : public Stmt
{
  public:
    VarDecl *init;
    Expr *cond;
    Expr *step;
    BlockStmt *body;

    ForStmt(VarDecl *init, Expr *cond, Expr *step, BlockStmt *body) : init(init), cond(cond), step(step), body(body)
    {
    }

    ~ForStmt() override
    {
        delete init;
        delete cond;
        delete step;
        delete body;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};

class StructDecl : public Stmt
{
  public:
    std::vector<VarDecl *> fields;
    QualifiedName *name;

    StructDecl(QualifiedName *name, std::vector<VarDecl *> fields) : fields(std::move(fields)), name(name)
    {
    }

    ~StructDecl() override
    {
        for (auto *field : fields)
        {
            delete field;
        }
        delete name;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
};
} // namespace parser
} // namespace dream
#endif
