#include "node.h"

#include "src/core/utilities/file_util.h"

namespace dap::parser
{
std::string VarDecl::getName() const
{
    return name->getName();
}

const QualifiedName *VarDecl::getQualifiedName() const
{
    return name;
}

const QualifiedName *VarDecl::getType() const
{
    return type;
}

bool Node::isa(const NodeMetaDataType type)
{
    return metadata->getNodeType() == type;
}

bool QualifiedName::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::QualifiedName;
}

bool DoubleExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::DoubleExpr;
}

bool IntegerExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::IntegerExpr;
}

bool StringExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::StringExpr;
}

bool VarExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::VarExpr;
}

bool BinaryExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::BinaryExpr;
}

bool UnaryExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::UnaryExpr;
}

bool ListExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ListExpr;
}

bool PointerExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::PointerExpr;
}

bool ArrayExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ArrayExpr;
}

bool CallExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::CallExpr;
}

bool AssignExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::AssignExpr;
}

bool ArrayAssignExpr::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ArrayAssignExpr;
}

bool BlockStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::BlockStmt;
}

bool IncludeStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::IncludeStmt;
}

bool PackageStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::PackageStmt;
}

bool ExprStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ExprStmt;
}

bool ReturnStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ReturnStmt;
}

bool BreakStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::BreakStmt;
}

bool VarDecl::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::VarDecl;
}

bool ProtoDecl::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ProtoDecl;
}

bool FuncDecl::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::FuncDecl;
}

bool ExternDecl::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ExternDecl;
}

bool Program::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::Program;
}

bool IfStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::IfStmt;
}

bool ElifStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ElifStmt;
}

bool ForStmt::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::ForStmt;
}

bool StructDecl::isa(const NodeMetaDataType type)
{
    return type == NodeMetaDataType::StructDecl;
}

bool DeleteStmt::isa(NodeMetaDataType type)
{
    return type == NodeMetaDataType::DeleteStmt;
}

} // namespace dap::parser