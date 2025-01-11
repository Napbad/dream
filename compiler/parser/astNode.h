//
// Created by napbad on 1/9/25.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>
#include <vector>

namespace dap {
namespace parser {

// 基础AST节点类
class ASTNode {
public:
    std::string type; // 节点类型
    std::string value; // 节点值

    std::string sourceFilePath;
    int lineNum;

    ASTNode(const std::string& t, const std::string& v) : type(t), value(v) {}
    virtual ~ASTNode() {}
};

// 程序节点
class ProgramNode : public ASTNode {
public:
    std::vector<ASTNode*> children; // 子节点列表

    ProgramNode() : ASTNode("program", "") {}
    ~ProgramNode() {
        for (ASTNode* child : children) {
            delete child;
        }
    }
};

// 包声明节点
class PackageDeclarationNode : public ASTNode {
public:
    PackageDeclarationNode(const std::string& name) : ASTNode("package_declaration", name) {}
};

// 导入声明节点
class ImportDeclarationNode : public ASTNode {
public:
    ImportDeclarationNode(const std::string& name) : ASTNode("import_declaration", name) {}
};

// 函数声明节点
class FunctionDeclarationNode : public ASTNode {
public:
    ASTNode* parameterList;
    ASTNode* returnType;
    ASTNode* block;

    FunctionDeclarationNode(const std::string& name) : ASTNode("function_declaration", name) {}
    ~FunctionDeclarationNode() {
        delete parameterList;
        delete returnType;
        delete block;
    }
};

// 参数列表节点
class ParameterListNode : public ASTNode {
public:
    std::vector<ASTNode*> parameters;

    ParameterListNode() : ASTNode("parameter_list", "") {}
    ~ParameterListNode() {
        for (ASTNode* param : parameters) {
            delete param;
        }
    }
};

// 参数节点
class ParameterNode : public ASTNode {
public:
    ASTNode* modifier;
    ASTNode* type;

    ParameterNode(const std::string& name) : ASTNode("parameter", name) {}
    ~ParameterNode() {
        delete modifier;
        delete type;
    }
};

// 返回类型节点
class ReturnTypeNode : public ASTNode {
public:
    ReturnTypeNode(const std::string& type) : ASTNode("return_type", type) {}
};

// 类型节点
class TypeNode : public ASTNode {
public:
    TypeNode(const std::string& type) : ASTNode("type", type) {}
};

// 代码块节点
class BlockNode : public ASTNode {
public:
    ASTNode* statementList;

    BlockNode() : ASTNode("block", "") {}
    ~BlockNode() {
        delete statementList;
    }
};

// 语句列表节点
class StatementListNode : public ASTNode {
public:
    std::vector<ASTNode*> statements;

    StatementListNode() : ASTNode("statement_list", "") {}
    ~StatementListNode() {
        for (ASTNode* stmt : statements) {
            delete stmt;
        }
    }
};

// 语句节点
class StatementNode : public ASTNode {
public:
    StatementNode(const std::string& type) : ASTNode("statement", type) {}
};

// 变量声明节点
class VariableDeclarationNode : public ASTNode {
public:
    ASTNode* modifier;
    ASTNode* type;
    ASTNode* expression;

    VariableDeclarationNode(const std::string& name) : ASTNode("variable_declaration", name) {}
    ~VariableDeclarationNode() {
        delete modifier;
        delete type;
        if (expression) delete expression;
    }
};

// 表达式节点
class ExpressionNode : public ASTNode {
public:
    std::vector<ASTNode*> children;

    ExpressionNode(const std::string& value) : ASTNode("expression", value) {}
    ~ExpressionNode() {
        for (ASTNode* child : children) {
            delete child;
        }
    }
};

// for循环节点
class ForLoopNode : public ASTNode {
public:
    ASTNode* type;
    ASTNode* identifier;
    ASTNode* initExpression;
    ASTNode* conditionExpression;
    ASTNode* incrementExpression;
    ASTNode* block;

    ForLoopNode() : ASTNode("for_loop", "") {}
    ~ForLoopNode() {
        delete type;
        delete identifier;
        delete initExpression;
        delete conditionExpression;
        delete incrementExpression;
        delete block;
    }
};

// if语句节点
class IfStatementNode : public ASTNode {
public:
    ASTNode* conditionExpression;
    ASTNode* thenBlock;
    ASTNode* elseBlock;

    IfStatementNode() : ASTNode("if_statement", "") {}
    ~IfStatementNode() {
        delete conditionExpression;
        delete thenBlock;
        if (elseBlock) delete elseBlock;
    }
};

// match语句节点
class MatchStatementNode : public ASTNode {
public:
    ASTNode* expression;
    ASTNode* matchCaseList;

    MatchStatementNode() : ASTNode("match_statement", "") {}
    ~MatchStatementNode() {
        delete expression;
        delete matchCaseList;
    }
};

// match case列表节点
class MatchCaseListNode : public ASTNode {
public:
    std::vector<ASTNode*> matchCases;

    MatchCaseListNode() : ASTNode("match_case_list", "") {}
    ~MatchCaseListNode() {
        for (ASTNode* matchCase : matchCases) {
            delete matchCase;
        }
    }
};

// match case节点
class MatchCaseNode : public ASTNode {
public:
    ASTNode* block;

    MatchCaseNode(const std::string& name) : ASTNode("match_case", name) {}
    ~MatchCaseNode() {
        if (block) delete block;
    }
};

// 结构体声明节点
class StructDeclarationNode : public ASTNode {
public:
    ASTNode* structMemberList;

    StructDeclarationNode(const std::string& name) : ASTNode("struct_declaration", name) {}
    ~StructDeclarationNode() {
        if (structMemberList) delete structMemberList;
    }
};

// 结构体成员列表节点
class StructMemberListNode : public ASTNode {
public:
    std::vector<ASTNode*> structMembers;

    StructMemberListNode() : ASTNode("struct_member_list", "") {}
    ~StructMemberListNode() {
        for (ASTNode* structMember : structMembers) {
            delete structMember;
        }
    }
};

// 结构体成员节点
class StructMemberNode : public ASTNode {
public:
    ASTNode* modifier;
    ASTNode* type;

    StructMemberNode(const std::string& name) : ASTNode("struct_member", name) {}
    ~StructMemberNode() {
        delete modifier;
        delete type;
    }
};

// 特征声明节点
class TraitDeclarationNode : public ASTNode {
public:
    ASTNode* traitMethodList;

    TraitDeclarationNode(const std::string& name) : ASTNode("trait_declaration", name) {}
    ~TraitDeclarationNode() {
        if (traitMethodList) delete traitMethodList;
    }
};

// 特征方法列表节点
class TraitMethodListNode : public ASTNode {
public:
    std::vector<ASTNode*> traitMethods;

    TraitMethodListNode() : ASTNode("trait_method_list", "") {}
    ~TraitMethodListNode() {
        for (ASTNode* traitMethod : traitMethods) {
            delete traitMethod;
        }
    }
};

// 特征方法节点
class TraitMethodNode : public ASTNode {
public:
    ASTNode* parameterList;
    ASTNode* returnType;

    TraitMethodNode(const std::string& name) : ASTNode("trait_method", name) {}
    ~TraitMethodNode() {
        delete parameterList;
        delete returnType;
    }
};

// 类型定义节点
class TypeDefinitionNode : public ASTNode {
public:
    ASTNode* type;

    TypeDefinitionNode(const std::string& name) : ASTNode("type_definition", name) {}
    ~TypeDefinitionNode() {
        if (type) delete type;
    }
};

} // namespace parser
} // namespace dap

#endif //ASTNODE_H
