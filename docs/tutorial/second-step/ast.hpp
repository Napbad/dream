#ifndef AST_HPP
#define AST_HPP

#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
using namespace std;

namespace ast_ {
class Node
{
public:
    Node() = default;
    virtual ~Node() = default;
};

class Stmt : public Node
{
};
typedef std::vector<Stmt *> stmt_list;

class Expr : public Node
{
};

class QualifiedNameNode : public Expr
{
public:
    std::vector<std::string> *name_parts;

    QualifiedNameNode();
    explicit QualifiedNameNode(std::vector<std::string> *names);
    explicit QualifiedNameNode(std::string names);

    [[nodiscard]] std::string getName(int idx) const;
    [[nodiscard]] std::string getFirstName() const;
};

class IntegerNodeExpr : public Expr
{
public:
    long long value;

    explicit IntegerNodeExpr(long long value);
};

class StringExpr : public Expr
{
public:
    std::string value;

    explicit StringExpr(std::string value);
};

class VarExpr : public Expr
{
public:
    QualifiedNameNode *name;

    explicit VarExpr(QualifiedNameNode *name);
    ~VarExpr() override;
};

class CallExpr : public Expr
{
public:
    QualifiedNameNode *callee;
    std::vector<Expr *> args;

    CallExpr(QualifiedNameNode *callee, std::vector<Expr *> args);
    ~CallExpr() override;
};

class BlockStmt : public Stmt
{
public:
    std::vector<Stmt *> stmts;

    BlockStmt();
    explicit BlockStmt(std::vector<Stmt *> stmts);
    ~BlockStmt() override;
};

class ReturnStmt : public Stmt
{
public:
    Expr *expr;

    explicit ReturnStmt(Expr *expr);
    ~ReturnStmt() override;
};

class VarDecl : public Stmt
{
public:
    QualifiedNameNode *type;
    QualifiedNameNode *name;
    Expr *init;

    VarDecl(QualifiedNameNode *type, QualifiedNameNode *name, Expr *init);
    ~VarDecl() override;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] const QualifiedNameNode *getQualifiedNameNode() const;
    [[nodiscard]] const QualifiedNameNode *getType() const;
};

class ProtoDecl : public Stmt
{
public:
    std::vector<VarDecl *> params;
    const QualifiedNameNode *return_type;
    QualifiedNameNode *name;

    ProtoDecl(const QualifiedNameNode *return_type, QualifiedNameNode *name, std::vector<VarDecl *> params);
    ~ProtoDecl() override;
};

class FuncDecl : public Stmt
{
public:
    ProtoDecl *proto;
    BlockStmt *body;

    FuncDecl(QualifiedNameNode *type, QualifiedNameNode *name, std::vector<VarDecl *> params, BlockStmt *body);
    ~FuncDecl() override;
};

class ExprStmt : public Stmt
{
public:
    Expr *expr;

    explicit ExprStmt(Expr *expr);
    ~ExprStmt() override;
};

class Program : public Stmt
{
public:
    BlockStmt *stmts;

    explicit Program(BlockStmt *stmts);
    ~Program() override;
};
}
#endif // AST_HPP