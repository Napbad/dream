//
// Created by napbad on 11/24/24.
//
#ifndef NODE_META_DATA_H
#define NODE_META_DATA_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "node.h"
namespace dap::parser
{
class Node;

enum class NodeMetaDataType
{
    None,
    QualifiedName,
    DoubleExpr,
    IntegerExpr,
    StringExpr,
    VarExpr,
    BinaryExpr,
    UnaryExpr,
    ListExpr,
    PointerExpr,
    ArrayExpr,
    CallExpr,
    AssignExpr,
    IncludeStmt,
    PackageStmt,
    BlockStmt,
    ExprStmt,
    ReturnStmt,
    BreakStmt,
    VarDecl,
    ProtoDecl,
    FuncDecl,
    ExternDecl,
    Program,
    IfStmt,
    ElifStmt,
    ForStmt,
    StructDecl
};

class NodeMetadata
{
  public:
    virtual ~NodeMetadata() = default;
    virtual Node *getNode();

    virtual NodeMetaDataType getNodeType()
    {
        return type;
    };

  protected:
    NodeMetaDataType type = NodeMetaDataType::None;
    Node *node = nullptr;
};

extern std::unordered_map<Node *, NodeMetadata *> *nodeMetadataMapping;

class QualifiedNameMetadata final : public NodeMetadata
{
  public:
    std::vector<std::string> name_parts;

    explicit QualifiedNameMetadata(const std::vector<std::string> &name_parts) : name_parts(name_parts)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::QualifiedName;
    }
};

class DoubleExprMetadata final : public NodeMetadata
{
  public:
    double value;

    explicit DoubleExprMetadata(const double value) : value(value)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::DoubleExpr;
    }
};

class IntegerExprMetadata final : public NodeMetadata
{
  public:
    long long value;

    explicit IntegerExprMetadata(const long long value) : value(value)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::IntegerExpr;
    }
};

class StringExprMetadata final : public NodeMetadata
{
  public:
    std::string value;

    explicit StringExprMetadata(std::string value) : value(std::move(value))
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::StringExpr;
    }
};

class VarExprMetadata final : public NodeMetadata
{
  public:
    QualifiedNameMetadata name;

    explicit VarExprMetadata(QualifiedNameMetadata name) : name(std::move(name))
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::VarExpr;
    }
};

class BinaryExprMetadata final : public NodeMetadata
{
  public:
    int op;
    NodeMetadata *lhs;
    NodeMetadata *rhs;

    BinaryExprMetadata(const int op, NodeMetadata *lhs, NodeMetadata *rhs) : op(op), lhs(lhs), rhs(rhs)
    {
    }

    ~BinaryExprMetadata() override
    {
        delete lhs;
        delete rhs;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::BinaryExpr;
    }
};

class UnaryExprMetadata final : public NodeMetadata
{
  public:
    int op;
    NodeMetadata *operand;

    UnaryExprMetadata(const int op, NodeMetadata *operand) : op(op), operand(operand)
    {
    }

    ~UnaryExprMetadata() override
    {
        delete operand;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::UnaryExpr;
    }
};

class ListExprMetadata final : public NodeMetadata
{
  public:
    std::vector<NodeMetadata *> elements;

    explicit ListExprMetadata(const std::vector<NodeMetadata *> &elements) : elements(elements)
    {
    }

    ~ListExprMetadata() override
    {
        for (const auto *element : elements)
        {
            delete element;
        }
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ListExpr;
    }
};

class PointerExprMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *baseVal;

    explicit PointerExprMetadata(NodeMetadata *baseVal) : baseVal(baseVal)
    {
    }

    ~PointerExprMetadata() override
    {
        delete baseVal;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::PointerExpr;
    }
};

class ArrayExprMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *idx;
    QualifiedNameMetadata name;

    ArrayExprMetadata(NodeMetadata *idx, QualifiedNameMetadata name) : idx(idx), name(std::move(name))
    {
    }

    ~ArrayExprMetadata() override
    {
        delete idx;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ArrayExpr;
    }
};

class CallExprMetadata final : public NodeMetadata
{
  public:
    QualifiedNameMetadata callee;
    std::vector<NodeMetadata *> args;

    CallExprMetadata(QualifiedNameMetadata callee, const std::vector<NodeMetadata *> &args)
        : callee(std::move(callee)), args(args)
    {
    }

    ~CallExprMetadata() override
    {
        for (const auto *arg : args)
        {
            delete arg;
        }
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::CallExpr;
    }
};

class AssignExprMetadata final : public NodeMetadata
{
  public:
    QualifiedNameMetadata lhs;
    NodeMetadata *rhs;

    AssignExprMetadata(QualifiedNameMetadata lhs, NodeMetadata *rhs) : lhs(std::move(lhs)), rhs(rhs)
    {
    }

    ~AssignExprMetadata() override
    {
        delete rhs;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::AssignExpr;
    }
};

class BlockStmtMetadata final : public NodeMetadata
{
  public:
    std::vector<NodeMetadata *> stmts;

    explicit BlockStmtMetadata(const std::vector<NodeMetadata *> &stmts) : stmts(stmts)
    {
    }

    ~BlockStmtMetadata() override
    {
        for (const auto *stmt : stmts)
        {
            delete stmt;
        }
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::BlockStmt;
    }
};

class IncludeStmtMetatata final : public NodeMetadata
{
  public:
    QualifiedNameMetadata *name;
    explicit IncludeStmtMetatata(QualifiedNameMetadata *name) : name(name)
    {
    }

    ~IncludeStmtMetatata() override
    = default;

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::IncludeStmt;
    }
};

class PackageStmtMetadata final : public NodeMetadata
{
  public:
    QualifiedNameMetadata *name;
    explicit PackageStmtMetadata(QualifiedNameMetadata *name) : name(name)
    {
    }
    ~PackageStmtMetadata() override
    = default;
    Node *getNode() override
    {
        return node;
    }
    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::PackageStmt;
    }
};

class ExprStmtMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *Expr;

    explicit ExprStmtMetadata(NodeMetadata *Expr) : Expr(Expr)
    {
    }

    ~ExprStmtMetadata() override
    {
        delete Expr;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ExprStmt;
    }
};

class ReturnStmtMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *Expr;

    explicit ReturnStmtMetadata(NodeMetadata *Expr) : Expr(Expr)
    {
    }

    ~ReturnStmtMetadata() override
    {
        delete Expr;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ReturnStmt;
    }
};

class BreakStmtMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *Expr;

    explicit BreakStmtMetadata(NodeMetadata *Expr = nullptr) : Expr(Expr)
    {
    }

    ~BreakStmtMetadata() override
    {
        delete Expr;
    }

    Node *getNode() override
    {
        if (Expr)
        {
            return node;
        }
        return nullptr;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::BreakStmt;
    }
};

class VarDeclMetadata final : public NodeMetadata
{
  public:
    bool is_mutable;
    bool is_nullable;
    QualifiedNameMetadata type;
    QualifiedNameMetadata name;
    NodeMetadata *init;
    NodeMetadata *size; // only for array types

    VarDeclMetadata(const bool is_mutable, const bool is_nullable, QualifiedNameMetadata type,
                    QualifiedNameMetadata name, NodeMetadata *init, NodeMetadata *size = nullptr)
        : is_mutable(is_mutable), is_nullable(is_nullable), type(std::move(type)), name(std::move(name)), init(init),
          size(size)
    {
    }

    ~VarDeclMetadata() override
    {
        delete init;
        delete size;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::VarDecl;
    }
};

class ProtoDeclMetadata final : public NodeMetadata
{
  public:
    std::vector<VarDeclMetadata> params;
    QualifiedNameMetadata return_type;
    QualifiedNameMetadata name;

    ProtoDeclMetadata(QualifiedNameMetadata return_type, QualifiedNameMetadata name,
                      const std::vector<VarDeclMetadata> &params)
        : return_type(std::move(return_type)), name(std::move(name)), params(params)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ProtoDecl;
    }
};

class FuncDeclMetadata final : public NodeMetadata
{
  public:
    ProtoDeclMetadata proto;
    BlockStmtMetadata body;

    FuncDeclMetadata(ProtoDeclMetadata proto, const BlockStmtMetadata &body) : proto(std::move(proto)), body(body)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::FuncDecl;
    }
};

class ExternDeclMetadata final : public NodeMetadata
{
  public:
    ProtoDeclMetadata proto;

    explicit ExternDeclMetadata(ProtoDeclMetadata proto) : proto(std::move(proto))
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ExternDecl;
    }
};

class ProgramMetadata final : public NodeMetadata
{
  public:
    BlockStmtMetadata stmts;

    explicit ProgramMetadata(const BlockStmtMetadata &stmts) : stmts(stmts)
    {
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::Program;
    }
};

class IfStmtMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *cond;
    BlockStmtMetadata body;
    BlockStmtMetadata *else_body;
    std::vector<NodeMetadata *> elif_stmts;

    IfStmtMetadata(NodeMetadata *cond, const BlockStmtMetadata &body, BlockStmtMetadata *else_body = nullptr,
                   const std::vector<NodeMetadata *> &elif_stmts = {})
        : cond(cond), body(body), else_body(else_body), elif_stmts(elif_stmts)
    {
    }

    ~IfStmtMetadata() override
    {
        delete cond;
        delete else_body;
        for (const auto *stmt : elif_stmts)
        {
            delete stmt;
        }
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::IfStmt;
    }
};

class ElifStmtMetadata final : public NodeMetadata
{
  public:
    NodeMetadata *cond;
    BlockStmtMetadata body;

    ElifStmtMetadata(NodeMetadata *cond, const BlockStmtMetadata &body) : cond(cond), body(body)
    {
    }

    ~ElifStmtMetadata() override
    {
        delete cond;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ElifStmt;
    }
};

class ForStmtMetadata final : public NodeMetadata
{
  public:
    VarDeclMetadata *init;
    NodeMetadata *cond;
    NodeMetadata *step;
    BlockStmtMetadata body;

    ForStmtMetadata(VarDeclMetadata *init, NodeMetadata *cond, NodeMetadata *step, const BlockStmtMetadata &body)
        : init(init), cond(cond), step(step), body(body)
    {
    }

    ~ForStmtMetadata() override
    {
        delete init;
        delete cond;
        delete step;
    }

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::ForStmt;
    }
};

class StructDeclMetadata final : public NodeMetadata
{
  public:
    std::vector<VarDeclMetadata> fields;
    QualifiedNameMetadata name;

    StructDeclMetadata(QualifiedNameMetadata name, const std::vector<VarDeclMetadata> &fields)
        : fields(fields), name(std::move(name))
    {
    }

    ~StructDeclMetadata() override = default;

    Node *getNode() override
    {
        return node;
    }

    NodeMetaDataType getNodeType() override
    {
        return NodeMetaDataType::StructDecl;
    }
};
} // namespace dap::inter_gen

#endif // NODE_META_DATA_H