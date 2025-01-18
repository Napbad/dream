#include "ast.hpp"
namespace ast_
{
QualifiedNameNode::QualifiedNameNode() : name_parts(new std::vector<std::string>) {}

QualifiedNameNode::QualifiedNameNode(std::vector<std::string> *names) : name_parts(names) {}

QualifiedNameNode::QualifiedNameNode(std::string names) : name_parts(new std::vector<std::string>{std::move(names)}) {}

std::string QualifiedNameNode::getName(int idx) const
{
    return name_parts->at(idx);
}

std::string QualifiedNameNode::getFirstName() const
{
    return name_parts->at(0);
}

IntegerNodeExpr::IntegerNodeExpr(long long value) : value(value) {}

StringExpr::StringExpr(std::string value) : value(std::move(value)) {}

VarExpr::VarExpr(QualifiedNameNode *name) : name(name) {}

VarExpr::~VarExpr()
{
    delete name;
}

CallExpr::CallExpr(QualifiedNameNode *callee, std::vector<Expr *> args) : callee(callee), args(std::move(args)) {}

CallExpr::~CallExpr()
{
    delete callee;
    for (auto *arg : args)
    {
        delete arg;
    }
}

BlockStmt::BlockStmt() = default;

BlockStmt::BlockStmt(std::vector<Stmt *> stmts) : stmts(std::move(stmts)) {}

BlockStmt::~BlockStmt()
{
    for (auto *stmt : stmts)
    {
        delete stmt;
    }
}

ReturnStmt::ReturnStmt(Expr *expr) : expr(expr) {}

ReturnStmt::~ReturnStmt()
{
    delete expr;
}

VarDecl::VarDecl(QualifiedNameNode *type, QualifiedNameNode *name, Expr *init)
    : type(type), name(name), init(init) {}

VarDecl::~VarDecl()
{
    delete type;
    delete name;
    delete init;
}

std::string VarDecl::getName() const
{
    return name->getFirstName();
}

const QualifiedNameNode *VarDecl::getQualifiedNameNode() const
{
    return name;
}

const QualifiedNameNode *VarDecl::getType() const
{
    return type;
}

ProtoDecl::ProtoDecl(const QualifiedNameNode *return_type, QualifiedNameNode *name, std::vector<VarDecl *> params)
    : return_type(return_type), name(name), params(std::move(params)) {}

ProtoDecl::~ProtoDecl()
{
    for (auto *param : params)
    {
        delete param;
    }
    delete name;
    delete return_type;
}

FuncDecl::FuncDecl(QualifiedNameNode *type, QualifiedNameNode *name, std::vector<VarDecl *> params, BlockStmt *body)
    : proto(new ProtoDecl(type, name, std::move(params))), body(body) {}

FuncDecl::~FuncDecl()
{
    delete proto;
    delete body;
}

ExprStmt::ExprStmt(Expr *expr) : expr(expr) {}

ExprStmt::~ExprStmt()
{
    delete expr;
}

Program::Program(BlockStmt *stmts) : stmts(stmts) {}

Program::~Program()
{
    delete stmts;
}
}