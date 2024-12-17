%{
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include "node.h"
#include "src/core/utilities/file_util.h"
#include "src/core/common/define_d.h"

using namespace dap::parser;

Program *program; /* the top level root node of our final AST */

    

extern int yylineno;

extern int yylex();
void yyerror(const char *s) {
    std::printf("Error at line %d: %s\n", yylineno, s);
    std::exit(1);
}
// if define this macro then output the parse info, with line number, and the rule that was used, the value parsed

void printParseInfo(const char* ruleName, int lineNumber, const std::string& value = "") {
#ifdef PARSE_DBG
    std::ostringstream oss;
    oss << "<Parsed> at line " << lineNumber << ":\t" << ruleName;
    if (!value.empty()) {
        oss << " with value:\t" << value;
    }
    try {
        dap::util::dbg_print(std::cout, oss.str());
    } catch (const std::exception& e) {
        std::cerr << "Error in printParseInfo: " << e.what() << std::endl;
    }
#endif
}

%}

%union {
#include <vector>
#include "node.h"

    dap::parser::Node *node;
    dap::parser::BlockStmt *block;
    dap::parser::Expr *expr;
    dap::parser::Stmt *stmt;
    dap::parser::QualifiedName *ident;
    dap::parser::VarDecl *var_decl;
    std::vector<dap::parser::VarDecl*> *varvec;
    std::vector<dap::parser::Expr*> *exprvec;
    std::vector<dap::parser::Stmt*> *stmtvec;
    std::string *string;
    bool boolval;
    int token;
}

/* Define the tokens and their types */

%token <string> STRING_LITERAL IDENTIFIER INT_TOKEN DOUBLE_TOKEN STRUCT BREAK
%token <token>  DOT
%token <token> PLUS MINUS TIMES DIVIDE MOD
%token <token> ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token <token> LT LE GT GE EQ NE AND OR NOT XOR UMINUS UPLUS
%token <token> PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN
%token <token> INC DEC BIT_AND
%token <token> IF ELSE ELIF FOR RETURN
%token <token> FUN EXTERN INCLUDE PACKAGE
%token <token> VAR IMT NULLABLE NON_NULLABLE
%token <token> LSHIFT RSHIFT URSHIFT

/* Define the non-terminals and their types */
%type <token> binary_operator unary_operator
%type <node> program
%type <block> block
%type <expr> expression binary_expression unary_expression
%type <stmt> stmt
%type <stmt> if_statement elif_statement for_statement function_declaration
%type <stmt> extern_decl struct_decl assign_expr array_assign_stmt include_stmt
%type <stmt> break_statement package_stmt
%type <ident> qualified_name
%type <var_decl> var_decl for_var_decl
%type <varvec> var_decl_list struct_field_list
%type <exprvec> expr_list
%type <stmtvec> stmt_list elif_stmts
%type <boolval> assign_nullable_flag var_mutable_flag

%start program

%left OR
%left AND
%left LSHIFT RSHIFT URSHIFT
%left PLUS MINUS
%left TIMES DIVIDE MOD
%left XOR
%left LT LE GT GE
%left EQ NE
%right NOT UMINUS UPLUS
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN DIVIDE_ASSIGN MOD_ASSIGN
%left INC DEC

%%

program:
    stmt_list {
        program = new Program(new BlockStmt(*$1));
        $$->line = yylineno;

        printParseInfo("program", yylineno);
    }
;

stmt_list:
    /* empty */ {
        $$ = new std::vector<Stmt*>();
        printParseInfo("stmt_list (empty)", yylineno);
    }
    | stmt_list stmt {
        $1->push_back($2);
        $$ = $1;
        printParseInfo("stmt_list", yylineno);
    }
;

stmt:
    expression SEMICOLON {
        $$ = new ExprStmt($1);
        $$->line = yylineno;

        printParseInfo("stmt (expression SEMICOLON)", yylineno);
    }
    | var_decl SEMICOLON {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (var_decl SEMICOLON)", yylineno);
    }
    | RETURN expression SEMICOLON {
        $$ = new ReturnStmt($2);
        $$->line = yylineno;

        printParseInfo("stmt (RETURN expression SEMICOLON)", yylineno);
    }
    | RETURN SEMICOLON {
        $$ = new ReturnStmt(nullptr);
        $$->line = yylineno;

        printParseInfo("stmt (RETURN void SEMICOLON)", yylineno);
    }
    | if_statement {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (if_statement)", yylineno);
    }
    | elif_statement {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (elif_statement)", yylineno);
    }
    | for_statement {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (for_statement)", yylineno);
    }
    | function_declaration {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (function_declaration)", yylineno);
    }
    | assign_expr SEMICOLON {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (assignment)", yylineno);
    }
    | array_assign_stmt {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (array_assign_stmt)", yylineno);
    }
    | extern_decl {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (extern_decl)", yylineno);
    }
    | break_statement SEMICOLON {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (break_statement)", yylineno);
    }
    | block {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (block)", yylineno);
    }
    | struct_decl {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("stmt (struct_decl)", yylineno);
    }
    | include_stmt {
    	$$ = $1;
        $$->line = yylineno;

    	printParseInfo("stmmt (include_stmt)", yylineno);
    }
    | package_stmt {
    	$$ = $1;
        $$->line = yylineno;

    	printParseInfo("stmt (package_stmt)", yylineno);
    }
;

include_stmt:
    INCLUDE qualified_name SEMICOLON {
	$$ = new IncludeStmt($2);
        $$->line = yylineno;

	printParseInfo("include_stmt", yylineno);
    }
;

package_stmt:
    PACKAGE qualified_name SEMICOLON {
	$$ = new PackageStmt($2);
        $$->line = yylineno;

	printParseInfo("package_stmt", yylineno);
    }
;

block:
    LBRACE stmt_list RBRACE {
        $$ = new BlockStmt(*$2);
        $$->line = yylineno;

        printParseInfo("block", yylineno);
    }
;

var_decl:
    var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag ASSIGN expression {
        $$ = new VarDecl($2, new QualifiedName(new std::vector<std::string>({*$3})), $1, $4, $6);
        delete $3;
        $$->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag ASSIGN expression)", yylineno);
    }
    | var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag {
        $$ = new VarDecl($2, new QualifiedName(new std::vector<std::string>({*$3})), $1, $4, nullptr);
        delete $3;
        $$->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag)", yylineno);
    }
    | var_mutable_flag qualified_name TIMES IDENTIFIER assign_nullable_flag ASSIGN expression {
    	$2->name_parts->push_back("*");
        $$ = new VarDecl($2, new QualifiedName(new std::vector<std::string>({*$4})), $1, $5, $7);
        delete $4;
        $$->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag ASSIGN expression)", yylineno);
    }
    | var_mutable_flag qualified_name TIMES IDENTIFIER assign_nullable_flag {
    	$2->name_parts->push_back("*");
        $$ = new VarDecl($2, new QualifiedName(new std::vector<std::string>({*$4})), $1, $5, nullptr);
        delete $4;
        $$->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag qualified_name IDENTIFIER assign_nullable_flag)", yylineno);
    }
    | var_mutable_flag qualified_name LBRACKET RBRACKET IDENTIFIER assign_nullable_flag {
    	$2->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*$5}));
    	$$ = new VarDecl($2, name, $1, $6, nullptr);
    	delete $5;
        $$->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag qualified_name LBRACKET RBRACKET IDENTIFIER)", yylineno);
    }
    | var_mutable_flag qualified_name LBRACKET RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression {
    	$2->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*$5}));
    	$$ = new VarDecl($2, name, $1, $6, $8);
    	delete $5;
        $$->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag qualified_name LBRACKET RBRACKET IDENTIFIER assign", yylineno);
    }
    | var_mutable_flag qualified_name LBRACKET expression RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression {
    	$2->name_parts->push_back("[]");
    	$$ = new VarDecl($2, new QualifiedName(new std::vector<std::string>({*$6})), $1, $6, $9, $4);
    	$$->size = $4;
    	delete $6;
        $$->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag qualified_name LBRACKET RBRACKET IDENTIFIER assign", yylineno);
    }
;

var_mutable_flag:
    VAR { $$ = { true }; }
    | IMT { $$ = { false }; }
    | /* empty */ { $$ = { false }; }
;

assign_nullable_flag:
    NULLABLE { $$ = { true }; }
    | NON_NULLABLE { $$ = { false }; }
    | /* empty */ { $$ = { false }; }  // Treat as NON_NULLABLE if empty
;

extern_decl:
    EXTERN FUN qualified_name LPAREN var_decl_list RPAREN qualified_name SEMICOLON {
        $$ = new ProtoDecl($7, $3, *$5);
        delete $5;
        $$->line = yylineno;

        printParseInfo("extern_decl", yylineno);
    }
;

function_declaration:
    FUN qualified_name LPAREN var_decl_list RPAREN block {

        $$ = new FuncDecl(new QualifiedName(), $2, *$4, $6);
        $$->line = yylineno;

        delete $4;
        printParseInfo("function_declaration (without return type)", yylineno);
    }
    | FUN qualified_name LPAREN var_decl_list RPAREN qualified_name block  {
        $$ = new FuncDecl($6, $2, *$4, $7);
        delete $4;
        $$->line = yylineno;

        printParseInfo("function_declaration (with return type)", yylineno);
    }
;

var_decl_list:
    /* empty list */ {
    	$$ = new std::vector<VarDecl*>();
    	printParseInfo("var_decl_list (empty list)", yylineno);
    }
    | var_decl {
        $$ = new std::vector<VarDecl*>{$1};
        printParseInfo("var_decl_list (single var_decl)", yylineno);
    }
    | var_decl_list COMMA var_decl {
        $1->push_back($3);
        std::cout << "Added " << $3->name->getName() << " to var_decl_list" << std::endl;
        $$ = $1;
        printParseInfo("var_decl_list (multiple var_decl)", yylineno);
    }
;

qualified_name:
    IDENTIFIER {
        $$ = new QualifiedName({*$1});
        delete $1; // Clean up the string
        $$->line = yylineno;

        printParseInfo("qualified_name (single IDENTIFIER)", yylineno);
    }
    | qualified_name DOT IDENTIFIER {
        $$ = $1;
        $$->name_parts->push_back(*$3);
        delete $3; // Clean up the string
        $$->line = yylineno;

        printParseInfo("qualified_name (nested)", yylineno);
    }
;


binary_expression:
   expression binary_operator expression {
        $$ = new BinaryExpr($2, $1, $3);
        $$->line = yylineno;

        printParseInfo("binary_expression", yylineno);
    }
;


expression:
    INT_TOKEN {
        $$ = new IntegerExpr(atol($1->c_str()));
        $$->line = yylineno;

        printParseInfo("expression (INT_TOKEN)", yylineno);
    }
    | DOUBLE_TOKEN {
        $$ = new DoubleExpr(atof($1->c_str()));
        $$->line = yylineno;

        printParseInfo("expression (DOUBLE_TOKEN)", yylineno);
    }
    | STRING_LITERAL {
        $$ = new StringExpr($1->substr(1, $1->length() - 2));
        delete $1; // Clean up the string
        $$->line = yylineno;

        printParseInfo("expression (STRING_LITERAL)", yylineno);
    }
    | qualified_name {
        $$ = new VarExpr($1);
        $$->line = yylineno;

        printParseInfo("expression (qualified_name)", yylineno);
    }
    | LPAREN expression RPAREN {
        $$ = $2;
        $$->line = yylineno;

        printParseInfo("expression (parenthesized)", yylineno);
    }
    | qualified_name LPAREN expr_list RPAREN {
        $$ = new CallExpr($1, *$3);
        $$->line = yylineno;

        printParseInfo("expression (function call)", yylineno);
    }
    | binary_expression {
	$$ = $1;
        $$->line = yylineno;

        printParseInfo("expression (binary_expression)", yylineno);
    }
    | unary_expression {
        $$ = $1;
        $$->line = yylineno;

        printParseInfo("expression (unary_expression)", yylineno);
    }
    | LBRACKET expr_list RBRACKET {
        $$ = new ListExpr($2);
        $$->line = yylineno;

        printParseInfo("expression (list)", yylineno);
    }
    | qualified_name LBRACKET expression RBRACKET {
        $$ = new ArrayExpr($3, $1);
        $$->line = yylineno;

        printParseInfo("expression (array access)", yylineno);
    }
;

unary_expression:
    unary_operator expression {
        $$ = new UnaryExpr($1, $2);
        $$->line = yylineno;

        printParseInfo("unary_expression", yylineno);
    }
;

binary_operator:
    PLUS { $$ = PLUS; }
    | MINUS { $$ = MINUS; }
    | TIMES { $$ = TIMES; }
    | DIVIDE { $$ = DIVIDE; }
    | MOD { $$ = MOD; }
    | LT { $$ = LT; }
    | LE { $$ = LE; }
    | GT { $$ = GT; }
    | GE { $$ = GE; }
    | EQ { $$ = EQ; }
    | NE { $$ = NE; }
    | AND { $$ = AND; }
    | OR { $$ = OR; }
    | PLUS_ASSIGN { $$ = PLUS_ASSIGN; }
    | MINUS_ASSIGN { $$ = MINUS_ASSIGN; }
    | TIMES_ASSIGN { $$ = TIMES_ASSIGN; }
    | DIVIDE_ASSIGN { $$ = DIVIDE_ASSIGN; }
    | MOD_ASSIGN { $$ = MOD_ASSIGN; }
    | LSHIFT { $$ = LSHIFT; }
    | RSHIFT { $$ = RSHIFT; }
    | URSHIFT { $$ = URSHIFT; }
    | XOR { $$ = XOR; }
;

unary_operator:
    MINUS { $$ = MINUS; }
    | PLUS { $$ = PLUS; }
    | NOT { $$ = NOT; }
    | INC { $$ = INC; }
    | DEC { $$ = DEC; }
    | TIMES { $$ = TIMES; }
    | BIT_AND { $$ = BIT_AND; }
;

expr_list:
    /* empty */ {
        $$ = new std::vector<Expr*>();
        printParseInfo("expr_list (empty)", yylineno);
    }
    |expression {
        $$ = new std::vector<Expr*>{$1};
        printParseInfo("expr_list (singleexpression)", yylineno);
    }
    |expr_list COMMA expression {
        $1->push_back($3);
        $$ = $1;
        printParseInfo("expr_list (multipleexpressions)", yylineno);
    }
;

if_statement:
    IF expression block {
        $$ = new IfStmt($2, $3, nullptr);
        $$->line = yylineno;

        printParseInfo("if_statement (no else)", yylineno);
    }
    | IF expression block ELSE block {
        $$ = new IfStmt($2, $3, $5);
        $$->line = yylineno;

        printParseInfo("if_statement (with else)", yylineno);
    }
    | IF expression block elif_stmts {
        $$ = new IfStmt($2, $3, nullptr, $4);
        $$->line = yylineno;

        printParseInfo("if_statement (with elif_stmts)", yylineno);
    }
    | IF expression block elif_stmts ELSE block {
        $$ = new IfStmt($2, $3, $6, $4);
        $$->line = yylineno;

        printParseInfo("if_statement (with elif_stmts)", yylineno);
    }
;

elif_stmts:
    /* empty */ {
        $$ = new std::vector<Stmt*>();

        printParseInfo("elif_stmts (empty)", yylineno);
    }
    | elif_statement elif_stmts {
        $$->push_back($1);

        printParseInfo("elif_stmts (with elif_statement)", yylineno);
    }
;

elif_statement:
    ELIF expression block {
        $$ = new ElifStmt($2, $3);
        $$->line = yylineno;
        printParseInfo("elif_statement", yylineno);
    }
;

for_statement:
    FOR for_var_decl SEMICOLON expression SEMICOLON expression block {
        $$ = new ForStmt($2, $4, $6, $7);
        $$->line = yylineno;
        printParseInfo("for_statement", yylineno);
    }
;

break_statement:
    BREAK {
        $$->line = yylineno;
        $$ = new BreakStmt();
        printParseInfo("break_statement", yylineno);
    }
    | BREAK expression {
        $$->line = yylineno;
        $$ = new BreakStmt($2);
        printParseInfo("break_statement", yylineno);
    }
;

for_var_decl:
    qualified_name IDENTIFIER ASSIGN expression {
        $$ = new VarDecl($1, new QualifiedName(new std::vector<std::string>({*$2})), true, true, $4);
        printParseInfo("for_var_decl (qualified_name qualified_name IDENTIFIER ASSIGN expression)", yylineno);
    }
    | qualified_name IDENTIFIER {
        $$ = new VarDecl($1, new QualifiedName(new std::vector<std::string>({*$2})), true, true, nullptr);
        printParseInfo("for_var_decl (qualified_name qualified_name IDENTIFIER)", yylineno);
    }
;

struct_decl:
    STRUCT IDENTIFIER LBRACE struct_field_list RBRACE SEMICOLON {
        $$->line = yylineno;
        $$ = new StructDecl(new QualifiedName({*$2}), *$4);
        delete $2;
        delete $4;
        printParseInfo("struct_decl", yylineno);
    }
;

struct_field_list:
    /* empty */ {
        $$ = new std::vector<VarDecl*>();
        printParseInfo("struct_field_list (empty)", yylineno);
    }
    | struct_field_list var_decl SEMICOLON {
        $1->push_back($2);
        $$ = $1;
        printParseInfo("struct_field_list (with var_decl)", yylineno);
    }
;

assign_expr:
    qualified_name ASSIGN expression {
        $$ = new AssignExpr($1, $3);
        $$->line = yylineno;
        printParseInfo("assignment", yylineno);
    }
;

array_assign_stmt:
    qualified_name LBRACKET expression RBRACKET ASSIGN expression SEMICOLON {
        $$ = new ArrayAssignExpr($1, $3, $6);
        $$->line = yylineno;
        printParseInfo("array_assign_expr", yylineno);
    }
;

%%