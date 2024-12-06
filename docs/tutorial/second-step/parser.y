%{
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include "ast.hpp"

ast_::Program *program; /* the top level root node of our final AST */

extern int yylineno;

extern int yylex();
void yyerror(const char *s) {
    std::printf("Error at line %d: %s\n", yylineno, s);
    std::exit(1);
}

%}


%union {
#include "ast.hpp"

#include <vector>
#include <string>
    ast_::Node *node;
    ast_::BlockStmt *block;
    ast_::Expr *expr;
    ast_::Stmt *stmt;
    ast_::QualifiedName *ident;
    ast_::VarDecl *var_decl;
    std::vector<ast_::VarDecl*> *varvec;
    std::vector<ast_::Expr*> *exprvec;
    std::vector<ast_::Stmt*> *stmtvec;
    std::string *string;
    bool boolval;
    int token;
}

%token <token> FUN RETURN VAR COMMA LBRACE RBRACE LPAREN RPAREN COLON SEMICOLON ASSIGN

%token <string> IDENTIFIER INT_TOKEN STRING_LITERAL

%type <ident> qualified_name 
%type <exprvec> expr_list
%type <stmtvec> stmt_list
%type <var_decl> var_decl 
%type <stmt> function_declaration stmt
%type <expr> expression 
%type <node> program
%type <block> block
%type <varvec> var_decl_list

%start program

%%
program:
    stmt_list {
        program = new ast_::Program(new ast_::BlockStmt(*$1));
    }
;



stmt_list:
    /* empty */ {
        $$ = new std::vector<ast_::Stmt*>();
    }
    | stmt_list stmt {
        $1->push_back($2);
        $$ = $1;
    }
;

stmt:
    expression SEMICOLON {
        $$ = new ast_::ExprStmt($1);
    }
    | var_decl SEMICOLON {
        $$ = $1;
    }
    | RETURN expression SEMICOLON {
        $$ = new ast_::ReturnStmt($2);
    }
    | RETURN SEMICOLON {
        $$ = new ast_::ReturnStmt(nullptr);
    }
    | function_declaration {
        $$ = $1;
    }
;


block:
    LBRACE stmt_list RBRACE {
        $$ = new ast_::BlockStmt(*$2);
        delete $2;
    }
;


function_declaration:
    FUN qualified_name LPAREN var_decl_list RPAREN block {
        $$ = new ast_::FuncDecl(new ast_::QualifiedName(), $2, *$4, $6);
        delete $4;
    }
    | FUN qualified_name LPAREN var_decl_list RPAREN qualified_name block  {
        $$ = new ast_::FuncDecl($6, $2, *$4, $7);
        delete $4;
    }
;

var_decl_list:
    /* empty list */ {
    	$$ = new std::vector<ast_::VarDecl*>();
    }
    | var_decl {
        $$ = new std::vector<ast_::VarDecl*>{$1};
    }
    | var_decl_list COMMA var_decl {
        $1->push_back($3);
        $$ = $1;
    }
;

qualified_name:
    IDENTIFIER {
        $$ = new ast_::QualifiedName({*$1});
        delete $1; // Clean up the string
    }
;


expression:
    INT_TOKEN {
        $$ = new ast_::IntegerExpr(atol($1->c_str()));
    }
    | STRING_LITERAL {
        $$ = new ast_::StringExpr($1->substr(1, $1->length() - 2));
        delete $1; // Clean up the string
    }
    | qualified_name {
        $$ = new ast_::VarExpr($1);
    }
    | qualified_name LPAREN expr_list RPAREN {
        $$ = new ast_::CallExpr($1, *$3);
    }
;

expr_list:
    /* empty */ {
	$$ = new std::vector<ast_::Expr*>();
    }
    |expression {
        $$ = new std::vector<ast_::Expr*>{$1};
    }
    |expr_list COMMA expression {
        $1->push_back($3);
        $$ = $1;
    }
;


var_decl:
    qualified_name IDENTIFIER ASSIGN expression {
        $$ = new ast_::VarDecl($1, new ast_::QualifiedName(new std::vector<std::string>({*$2})),$4);
        delete $2;
    }
    | qualified_name IDENTIFIER  {
        $$ = new ast_::VarDecl($1, new ast_::QualifiedName(new std::vector<std::string>({*$2})), nullptr);
        delete $2;
    }
%%

int main() {
	return 0;
}