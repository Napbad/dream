%{
#include "node.h"
#include "compiler/parser/parser.hpp"
#include "compiler/common/define_d.h"
#include <string>
#include <cstring>
#include "compiler/utilities/file_util.h"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng); \
    std::cout << "Token: " << yytext << " size: " << std::to_string(yyleng) << std::endl;\
    for (int i = 0;i < 2147483647; ++i ) { \
        if (yytext[i]!= '\0') { yytext[i] = '\0'; } \
        else { break; }\
    }
#define TOKEN(t)    (yylval.token = t)

int llcolumn = 0;

// Function to handle string literals
std::string *handle_string_literal(const char *str) {
    std::string *result = new std::string(str);
    return result;
}
%}

// 声明token
%token PACKAGE IMPORT FUN VOID FOR IF ELSE MATCH STRUCT TRAIT TYPEDEF IMT VAR INSTANCEOF RETURN
%token INT BYTE SHORT LONG CHAR FLOAT DOUBLE BOOL UINT USHORT ULONG LLLONG ULLONG
%token IDENTIFIER INTEGER BINARY_LITERAL OCTAL_LITERAL HEXADECIMAL_LITERAL LITERAL FLOAT_LITERAL
%token STRING_LITERAL CHAR_LITERAL
%token ASSIGN ADD_ASSIGN MINUS_ASSIGN INCREMENT LESS_THAN
%token COMMA SEMICOLON COLON LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET DOT ELLIPSIS QUESTION BANG

// 定义优先级和结合性
%left ASSIGN ADD_ASSIGN MINUS_ASSIGN
%left INCREMENT
%left LESS_THAN

%%

// 语法规则
program
    : package_declaration import_declarations function_declarations struct_declarations trait_declarations type_definitions {
        $$ = new Node("program", "");
        if ($1) $$->children.push_back($1);
        if ($2) {
            for (auto child : *static_cast<vector<Node*>*>( $2)) {
                $$->children.push_back(child);
            }
        }
        if ($3) {
            for (auto child : *static_cast<vector<Node*>*>( $3)) {
                $$->children.push_back(child);
            }
        }
        if ($4) {
            for (auto child : *static_cast<vector<Node*>*>( $4)) {
                $$->children.push_back(child);
            }
        }
        if ($5) {
            for (auto child : *static_cast<vector<Node*>*>( $5)) {
                $$->children.push_back(child);
            }
        }
        if ($6) {
            for (auto child : *static_cast<vector<Node*>*>( $6)) {
                $$->children.push_back(child);
            }
        }
    }
    ;

package_declaration
    : PACKAGE IDENTIFIER SEMICOLON {
        $$ = new Node("package_declaration", $2->value);
    }
    | /* empty */ {
        $$ = nullptr;
    }
    ;

import_declarations
    : import_declaration import_declarations {
        vector<Node*>* v = new vector<Node*>();
        v->push_back($1);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( $2);
        for (auto child : *v2) {
            v->push_back(child);
        }
        $$ = v;
    }
    | /* empty */ {
        $$ = new vector<Node*>();
    }
    ;

import_declaration
    : IMPORT IDENTIFIER SEMICOLON {
        $$ = new Node("import_declaration", $2->value);
    }
    ;

function_declarations
    : function_declaration function_declarations {
        vector<Node*>* v = new vector<Node*>();
        v->push_back($1);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( $2);
        for (auto child : *v2) {
            v->push_back(child);
        }
        $$ = v;
    }
    | /* empty */ {
        $$ = new vector<Node*>();
    }
    ;

function_declaration
    : FUN IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN return_type block {
        Node* funcNode = new Node("function_declaration", $2->value);
        funcNode->children.push_back($4);
        funcNode->children.push_back($6);
        funcNode->children.push_back($7);
        $$ = funcNode;
    }
    ;

parameter_list
    : parameter COMMA parameter_list {
        Node* paramListNode = new Node("parameter_list", "");
        paramListNode->children.push_back($1);
        paramListNode->children.push_back($3);
        $$ = paramListNode;
    }
    | parameter {
        Node* paramListNode = new Node("parameter_list", "");
        paramListNode->children.push_back($1);
        $$ = paramListNode;
    }
    | /* empty */ {
        $$ = new Node("parameter_list", "");
    }
    ;

parameter
    : IMT type IDENTIFIER {
        Node* paramNode = new Node("parameter", $3->value);
        paramNode->children.push_back(new Node("modifier", "imt"));
        paramNode->children.push_back($2);
        $$ = paramNode;
    }
    | VAR type IDENTIFIER {
        Node* paramNode = new Node("parameter", $3->value);
        paramNode->children.push_back(new Node("modifier", "var"));
        paramNode->children.push_back($2);
        $$ = paramNode;
    }
    ;

return_type
    : type {
        $$ = $1;
    }
    | VOID {
        $$ = new Node("return_type", "void");
    }
    ;

type
    : INT {
        $$ = new Node("type", "int");
    }
    | BYTE {
        $$ = new Node("type", "byte");
    }
    | SHORT {
        $$ = new Node("type", "short");
    }
    | LONG {
        $$ = new Node("type", "long");
    }
    | CHAR {
        $$ = new Node("type", "char");
    }
    | FLOAT {
        $$ = new Node("type", "float");
    }
    | DOUBLE {
        $$ = new Node("type", "double");
    }
    | BOOL {
        $$ = new Node("type", "bool");
    }
    | UINT {
        $$ = new Node("type", "uint");
    }
    | USHORT {
        $$ = new Node("type", "ushort");
    }
    | ULONG {
        $$ = new Node("type", "ulong");
    }
    | LLLONG {
        $$ = new Node("type", "lllong");
    }
    | ULLONG {
        $$ = new Node("type", "ullong");
    }
    | IDENTIFIER {
        $$ = new Node("type", $1->value);
    }
    ;

block
    : LEFT_BRACE statement_list RIGHT_BRACE {
        Node* blockNode = new Node("block", "");
        blockNode->children.push_back($2);
        $$ = blockNode;
    }
    ;

statement_list
    : statement statement_list {
        Node* stmtListNode = new Node("statement_list", "");
        stmtListNode->children.push_back($1);
        stmtListNode->children.push_back($2);
        $$ = stmtListNode;
    }
    | /* empty */ {
        $$ = new Node("statement_list", "");
    }
    ;

statement
    : variable_declaration SEMICOLON {
        $$ = $1;
    }
    | expression SEMICOLON {
        $$ = $1;
    }
    | for_loop {
        $$ = $1;
    }
    | if_statement {
        $$ = $1;
    }
    | match_statement {
        $$ = $1;
    }
    | RETURN expression SEMICOLON {
        Node* returnStmtNode = new Node("return_statement", "");
        returnStmtNode->children.push_back(new Node("keyword", "return"));
        returnStmtNode->children.push_back($2);
        $$ = returnStmtNode;
    }
    ;

variable_declaration
    : IMT type IDENTIFIER ASSIGN expression {
        Node* varDeclNode = new Node("variable_declaration", $3->value);
        varDeclNode->children.push_back(new Node("modifier", "imt"));
        varDeclNode->children.push_back($2);
        varDeclNode->children.push_back(new Node("operator", "="));
        varDeclNode->children.push_back($5);
        $$ = varDeclNode;
    }
    | VAR type IDENTIFIER ASSIGN expression {
        Node* varDeclNode = new Node("variable_declaration", $3->value);
        varDeclNode->children.push_back(new Node("modifier", "var"));
        varDeclNode->children.push_back($2);
        varDeclNode->children.push_back(new Node("operator", "="));
        varDeclNode->children.push_back($5);
        $$ = varDeclNode;
    }
    | IMT type IDENTIFIER {
        Node* varDeclNode = new Node("variable_declaration", $3->value);
        varDeclNode->children.push_back(new Node("modifier", "imt"));
        varDeclNode->children.push_back($2);
        $$ = varDeclNode;
    }
    | VAR type IDENTIFIER {
        Node* varDeclNode = new Node("variable_declaration", $3->value);
        varDeclNode->children.push_back(new Node("modifier", "var"));
        varDeclNode->children.push_back($2);
        $$ = varDeclNode;
    }
    ;

expression
    : INTEGER {
        $$ = new Node("expression", to_string($1->integer));
    }
    | BINARY_LITERAL {
        $$ = new Node("expression", to_string($1->integer));
    }
    | OCTAL_LITERAL {
        $$ = new Node("expression", to_string($1->integer));
    }
    | HEXADECIMAL_LITERAL {
        $$ = new Node("expression", to_string($1->integer));
    }
    | FLOAT_LITERAL {
        $$ = new Node("expression", to_string($1->float_val));
    }
    | STRING_LITERAL {
        $$ = new Node("expression", $1->string->c_str());
    }
    | CHAR_LITERAL {
        $$ = new Node("expression", string(1, $1->char_val));
    }
    | IDENTIFIER {
        $$ = new Node("expression", $1->value);
    }
    | expression ADD_ASSIGN expression {
        Node* expNode = new Node("expression", "+=");
        expNode->children.push_back($1);
        expNode->children.push_back($3);
        $$ = expNode;
    }
    | expression INCREMENT {
        Node* expNode = new Node("expression", "++");
        expNode->children.push_back($1);
        $$ = expNode;
    }
    | expression LESS_THAN expression {
        Node* expNode = new Node("expression", "<");
        expNode->children.push_back($1);
        expNode->children.push_back($3);
        $$ = expNode;
    }
    | LEFT_PAREN expression RIGHT_PAREN {
        Node* expNode = new Node("expression", "");
        expNode->children.push_back($2);
        $$ = expNode;
    }
    ;

for_loop
    : FOR type IDENTIFIER ASSIGN expression SEMICOLON expression SEMICOLON expression block {
        Node* forLoopNode = new Node("for_loop", "");
        forLoopNode->children.push_back(new Node("keyword", "for"));
        forLoopNode->children.push_back($2);
        forLoopNode->children.push_back($3);
        forLoopNode->children.push_back(new Node("operator", "="));
        forLoopNode->children.push_back($5);
        forLoopNode->children.push_back($7);
        forLoopNode->children.push_back($9);
        forLoopNode->children.push_back($10);
        $$ = forLoopNode;
    }
    ;

if_statement
    : IF LEFT_PAREN expression RIGHT_PAREN block {
        Node* ifStmtNode = new Node("if_statement", "");
        ifStmtNode->children.push_back(new Node("keyword", "if"));
        ifStmtNode->children.push_back($3);
        ifStmtNode->children.push_back($5);
        $$ = ifStmtNode;
    }
    | IF LEFT_PAREN expression RIGHT_PAREN block ELSE block {
        Node* ifStmtNode = new Node("if_statement", "");
        ifStmtNode->children.push_back(new Node("keyword", "if"));
        ifStmtNode->children.push_back($3);
        ifStmtNode->children.push_back($5);
        ifStmtNode->children.push_back(new Node("keyword", "else"));
        ifStmtNode->children.push_back($7);
        $$ = ifStmtNode;
    }
    ;

match_statement
    : MATCH LEFT_PAREN expression RIGHT_PAREN match_case_list {
        Node* matchStmtNode = new Node("match_statement", "");
        matchStmtNode->children.push_back(new Node("keyword", "match"));
        matchStmtNode->children.push_back($3);
        matchStmtNode->children.push_back($5);
        $$ = matchStmtNode;
    }
    ;

match_case_list
    : match_case match_case_list {
        Node* matchCaseListNode = new Node("match_case_list", "");
        matchCaseListNode->children.push_back($1);
        matchCaseListNode->children.push_back($2);
        $$ = matchCaseListNode;
    }
    | /* empty */ {
        $$ = new Node("match_case_list", "");
    }
    ;

match_case
    : IDENTIFIER COLON block {
        Node* matchCaseNode = new Node("match_case", $1->value);
        matchCaseNode->children.push_back(new Node("colon", ":"));
        matchCaseNode->children.push_back($3);
        $$ = matchCaseNode;
    }
    | LEFT_PAREN RIGHT_PAREN COLON block {
        Node* matchCaseNode = new Node("match_case", "default");
        matchCaseNode->children.push_back(new Node("colon", ":"));
        matchCaseNode->children.push_back($4);
        $$ = matchCaseNode;
    }
    ;

struct_declarations
    : struct_declaration struct_declarations {
        vector<Node*>* v = new vector<Node*>();
        v->push_back($1);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( $2);
        for (auto child : *v2) {
            v->push_back(child);
        }
        $$ = v;
    }
    | /* empty */ {
        $$ = new vector<Node*>();
    }
    ;

struct_declaration
    : STRUCT IDENTIFIER LEFT_BRACE struct_member_list RIGHT_BRACE {
        Node* structDeclNode = new Node("struct_declaration", $2->value);
        structDeclNode->children.push_back($4);
        $$ = structDeclNode;
    }
    | STRUCT IDENTIFIER LEFT_BRACE RIGHT_BRACE {
        Node* structDeclNode = new Node("struct_declaration", $2->value);
        $$ = structDeclNode;
    }
    ;

struct_member_list
    : struct_member SEMICOLON struct_member_list {
        Node* structMemberListNode = new Node("struct_member_list", "");
        structMemberListNode->children.push_back($1);
        structMemberListNode->children.push_back($3);
        $$ = structMemberListNode;
    }
    | struct_member SEMICOLON {
        Node* structMemberListNode = new Node("struct_member_list", "");
        structMemberListNode->children.push_back($1);
        $$ = structMemberListNode;
    }
    | /* empty */ {
        $$ = new Node("struct_member_list", "");
    }
    ;

struct_member
    : IMT type IDENTIFIER {
        Node* structMemberNode = new Node("struct_member", $3->value);
        structMemberNode->children.push_back(new Node("modifier", "imt"));
        structMemberNode->children.push_back($2);
        $$ = structMemberNode;
    }
    | VAR type IDENTIFIER {
        Node* structMemberNode = new Node("struct_member", $3->value);
        structMemberNode->children.push_back(new Node("modifier", "var"));
        structMemberNode->children.push_back($2);
        $$ = structMemberNode;
    }
    ;

trait_declarations
    : trait_declaration trait_declarations {
        vector<Node*>* v = new vector<Node*>();
        v->push_back($1);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( $2);
        for (auto child : *v2) {
            v->push_back(child);
        }
        $$ = v;
    }
    | /* empty */ {
        $$ = new vector<Node*>();
    }
    ;

trait_declaration
    : TRAIT IDENTIFIER LEFT_BRACE trait_method_list RIGHT_BRACE {
        Node* traitDeclNode = new Node("trait_declaration", $2->value);
        traitDeclNode->children.push_back($4);
        $$ = traitDeclNode;
    }
    | TRAIT IDENTIFIER LEFT_BRACE RIGHT_BRACE {
        Node* traitDeclNode = new Node("trait_declaration", $2->value);
        $$ = traitDeclNode;
    }
    ;

trait_method_list
    : trait_method SEMICOLON trait_method_list {
        Node* traitMethodListNode = new Node("trait_method_list", "");
        traitMethodListNode->children.push_back($1);
        traitMethodListNode->children.push_back($3);
        $$ = traitMethodListNode;
    }
    | trait_method SEMICOLON {
        Node* traitMethodListNode = new Node("trait_method_list", "");
        traitMethodListNode->children.push_back($1);
        $$ = traitMethodListNode;
    }
    | /* empty */ {
        $$ = new Node("trait_method_list", "");
    }
    ;

trait_method
    : FUN IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN return_type {
        Node* traitMethodNode = new Node("trait_method", $2->value);
        traitMethodNode->children.push_back($4);
        traitMethodNode->children.push_back($6);
        $$ = traitMethodNode;
    }
    ;

type_definitions
    : type_definition type_definitions {
        vector<Node*>* v = new vector<Node*>();
        v->push_back($1);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( $2);
        for (auto child : *v2) {
            v->push_back(child);
        }
        $$ = v;
    }
    | /* empty */ {
        $$ = new vector<Node*>();
    }
    ;

type_definition
    : TYPEDEF type IDENTIFIER {
        Node* typeDefNode = new Node("type_definition", $3->value);
        typeDefNode->children.push_back(new Node("keyword", "typedef"));
        typeDefNode->children.push_back($2);
        $$ = typeDefNode;
    }
    ;
%%

namespace dap::parser {
Node* parseProgram() {
    // 这里yyparse是由yacc生成的函数，用于启动语法分析
    if (yyparse() == 0) {
        // 假设语法分析成功，返回语法树的根节点
        // 这里根据实际情况从全局变量获取根节点
        // 例如，如果根节点存储在某个全局变量root中
        // return root;
        // 这里简单返回nullptr，实际应正确设置根节点
        return nullptr;
    } else {
        return nullptr;
    }
}
}