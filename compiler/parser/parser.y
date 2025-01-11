%{
#include "parser/ASTNode.h"
#include "parser/parser.hpp"
#include "common/define_d.h"
#include <string>
#include <cstring>
#include "utilities/file_util.h"

extern int llcolumn;

extern int yylex();

dap::parser::ProgramNode* program;

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n", s);
}   

%}

%union {
#include <vector>
#include "parser/ASTNode.h"

    // dap::parser::ASTNode *node;
    // dap::parser::BlockStmt *block;
    // dap::parser::Expr *expr;
    // dap::parser::Stmt *stmt;
    // dap::parser::QualifiedName *ident;
    // dap::parser::VarDecl *var_decl;
    // std::vector<dap::parser::VarDecl*> *varvec;
    // std::vector<dap::parser::Expr*> *exprvec;
    // std::vector<dap::parser::Stmt*> *stmtvec;
    std::string *str;
    std::string *ident;
    char char_val;
    int integer;
    double float_val;
    // bool boolval;
    // int token;
}

%token PACKAGE IMPORT FUN VOID FOR IF ELSE MATCH STRUCT TRAIT TYPEDEF IMT VAR INSTANCEOF RETURN
%token INT BYTE SHORT LONG CHAR FLOAT DOUBLE BOOL UINT USHORT ULONG LLLONG ULLONG
%token IDENTIFIER INTEGER BINARY_LITERAL OCTAL_LITERAL HEXADECIMAL_LITERAL FLOAT_LITERAL
%token STRING_LITERAL CHAR_LITERAL
%token ASSIGN ADD_ASSIGN MINUS_ASSIGN INCREMENT LESS_THAN
%token COMMA SEMICOLON COLON LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET DOT ELLIPSIS QUESTION BANG


%start program


%%
program:
    {
        program = new dap::parser::ProgramNode();
    };


%%