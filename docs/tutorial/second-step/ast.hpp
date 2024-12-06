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

class QualifiedName : public Expr
{
public:
    std::vector<std::string> *name_parts;

    QualifiedName();
    explicit QualifiedName(std::vector<std::string> *names);
    explicit QualifiedName(std::string names);

    [[nodiscard]] std::string getName(int idx) const;
    [[nodiscard]] std::string getFirstName() const;
};

class IntegerExpr : public Expr
{
public:
    long long value;

    explicit IntegerExpr(long long value);
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
    QualifiedName *name;

    explicit VarExpr(QualifiedName *name);
    ~VarExpr() override;
};

class CallExpr : public Expr
{
public:
    QualifiedName *callee;
    std::vector<Expr *> args;

    CallExpr(QualifiedName *callee, std::vector<Expr *> args);
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
    QualifiedName *type;
    QualifiedName *name;
    Expr *init;

    VarDecl(QualifiedName *type, QualifiedName *name, Expr *init);
    ~VarDecl() override;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] const QualifiedName *getQualifiedName() const;
    [[nodiscard]] const QualifiedName *getType() const;
};

class ProtoDecl : public Stmt
{
public:
    std::vector<VarDecl *> params;
    const QualifiedName *return_type;
    QualifiedName *name;

    ProtoDecl(const QualifiedName *return_type, QualifiedName *name, std::vector<VarDecl *> params);
    ~ProtoDecl() override;
};

class FuncDecl : public Stmt
{
public:
    ProtoDecl *proto;
    BlockStmt *body;

    FuncDecl(QualifiedName *type, QualifiedName *name, std::vector<VarDecl *> params, BlockStmt *body);
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