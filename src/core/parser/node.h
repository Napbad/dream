//
// Created by napbad on 10/25/24.
//
#ifndef NODE_H
#define NODE_H

#include <llvm/IR/Function.h>
#include <llvm/IR/Value.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "node_meta_data.h"
#include "src/core/inter_gen/codegen_inter.h"
#include "src/core/utilities/string_util.h"

namespace dap
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
    int line = -1;
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
class QualifiedName final : public Expr
{
  public:
    std::vector<std::string> *name_parts;

    QualifiedName() : name_parts(new std::vector<std::string>)
    {
    }
    explicit QualifiedName(std::vector<std::string> *names) : name_parts(names)
    {
    }
    explicit QualifiedName(std::string names) : name_parts(new std::vector{std::move(names)})
    {
    }

    [[nodiscard]] std::string getName() const
    {
        return util::getTextFromVec(*name_parts);
    }

    [[nodiscard]] std::string getName(const int idx) const
    {
        return name_parts->at(idx);
    }

    [[nodiscard]] std::string getFirstName() const
    {
        return name_parts->at(0);
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class DoubleExpr final : public Expr
{
  public:
    double value;

    explicit DoubleExpr(double value) : value(value)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class IntegerExpr final : public Expr
{
  public:
    long long value;

    explicit IntegerExpr(long long value) : value(value)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class StringExpr final : public Expr
{
  public:
    std::string value;

    explicit StringExpr(std::string value) : value(std::move(value))
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class VarExpr final : public Expr
{
  public:
    QualifiedName *name;

    explicit VarExpr(QualifiedName *name) : name(name)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;

    ~VarExpr() override
    {
        delete name;
    }
};

class BinaryExpr final : public Expr
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
    bool isa(NodeMetaDataType type) override;
};

class UnaryExpr final : public Expr
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
    bool isa(NodeMetaDataType type) override;
};

class ListExpr final : public Expr
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
    bool isa(NodeMetaDataType type) override;
};

class PointerExpr final : public Node
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
    bool isa(NodeMetaDataType type) override;
};

class ArrayExpr final : public Expr
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
    bool isa(NodeMetaDataType type) override;
};

class CallExpr final : public Expr
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
        for (auto *arg : args) {
            delete arg;
        }
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class AssignExpr final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ArrayAssignExpr final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class BlockStmt final : public Stmt
{
  public:
    std::vector<Stmt *> stmts;

    BlockStmt() = default;
    explicit BlockStmt(std::vector<Stmt *> stmts) : stmts(std::move(stmts))
    {
    }

    ~BlockStmt() override
    {
        for (auto *stmt : stmts) {
            delete stmt;
        }
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class IncludeStmt final : public Stmt
{
  public:
    QualifiedName *path;

    explicit IncludeStmt(QualifiedName *path) : path(path)
    {
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class PackageStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ExprStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ReturnStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class BreakStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class VarDecl final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ProtoDecl final : public Stmt
{
  public:
    std::vector<VarDecl *> params{};
    const QualifiedName *return_type;
    QualifiedName *name = nullptr;
    ProtoDecl(const QualifiedName *return_type, QualifiedName *name, std::vector<VarDecl *> params)
        : return_type(return_type), name(name), params(params)
    {
    }

    ~ProtoDecl() override
    {
        for (auto *param : params) {
            delete param;
        }
        delete name;
        delete return_type;
    };

    llvm::Function *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class FuncDecl final : public Stmt
{
  public:
    ProtoDecl *proto;
    BlockStmt *body;

    FuncDecl(QualifiedName *type, QualifiedName *name, std::vector<VarDecl *> params, BlockStmt *body)
        : proto(new ProtoDecl(type, name, params)), body(body)
    {
    }

    ~FuncDecl() override
    {
        delete proto;
        delete body;
    }

    llvm::Function *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};

class ExternDecl final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class Program final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class IfStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ElifStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class ForStmt final : public Stmt
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
    bool isa(NodeMetaDataType type) override;
};

class StructDecl final : public Stmt
{
  public:
    std::vector<VarDecl *> fields;
    QualifiedName *name;

    StructDecl(QualifiedName *name, std::vector<VarDecl *> fields) : fields(std::move(fields)), name(name)
    {
    }

    ~StructDecl() override
    {
        for (auto *field : fields) {
            delete field;
        }
        delete name;
    }

    llvm::Value *codeGen(inter_gen::InterGenContext *ctx) override;
    bool isa(NodeMetaDataType type) override;
};
} // namespace parser
} // namespace dap
#endif