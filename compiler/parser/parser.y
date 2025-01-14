%{
#include <string>
#include <cstdio>
#include <cstring>

#include "parser/ASTNode.h"
#include "parser/parser.hpp"
#include "common/define_d.h"
#include "utilities/file_util.h"
#include "utilities/log_util.h"

extern int yylineno;

extern int yylex();

dap::parser::ProgramNode* program;

namespace dap::parser {
extern std::string currentParsingFile;
}

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n at %s:%d \n", s, dap::parser::currentParsingFile.c_str(), yylineno);
}
void parserLog(const char *msg) {
#ifdef D_DEBUG
    dap::util::log(msg, dap::parser::currentParsingFile, yylineno);
#endif
}

void parserLog(std::string msg) {
#ifdef D_DEBUG
    dap::util::log(msg, dap::parser::currentParsingFile, yylineno);
#endif
}
%}

%union {
#include <vector>
#include "parser/ASTNode.h"

    // dap::parser::ASTNode *node;
    // dap::parser::BlockStmt *block;
    dap::parser::Expression *expr;
    dap::parser::Statement *stmt;
    dap::parser::QualifiedName *ident;
    dap::parser::TypeNode *typeNode;
    std::vector<dap::parser::TypeNode*> *typeNodeVec;
    dap::parser::Integer *intExpr;
    dap::parser::String *strExpr;
    dap::parser::Float *floatExpr;
    std::vector<dap::parser::Expression*> *exprVec;
    std::vector<dap::parser::Statement*> *stmtVec;
    std::string *str;
    char charVal;
    int integer;
    double floatVal;
    bool boolval;
    int token;
}

// Define the tokens
%token PACKAGE IMPORT FUN VOID FOR IF ELSE MATCH STRUCT TRAIT TYPEDEF IMT VAR INSTANCEOF RETURN
%token INT BYTE SHORT LONG FLOAT DOUBLE BOOL UINT USHORT ULONG LLONG ULLONG
%token IDENTIFIER INTEGER BINARY_LITERAL OCTAL_LITERAL HEXADECIMAL_LITERAL
%token STRING_LITERAL CHAR_LITERAL FLOAT_LITERAL
%token PLUS MINUS MUL DIV MOD BIT_AND BIT_OR BIT_XOR BIT_NOT SHIFT_LEFT SHIFT_RIGHT LOGIC_SHIFT_LEFT
%token ASSIGN ADD_ASSIGN MUL_ASSIGN DIV_ASSIGN MINUS_ASSIGN MOD_ASSIGN
%token BIT_AND_ASSIGN BIT_OR_ASSIGN BIT_XOR_ASSIGN SHIFT_LEFT_ASSIGN SHIFT_RIGHT_ASSIGN LOGIC_SHIFT_LEFT_ASSIGN
%token INCREMENT DECREMENT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%token AND OR
%token COMMA SEMICOLON COLON LEFT_BRACE RIGHT_BRACE LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET
%token DOT ELLIPSIS QUESTION BANG LBRACK RBRACK

%type <str> IDENTIFIER INTEGER BINARY_LITERAL OCTAL_LITERAL HEXADECIMAL_LITERAL FLOAT_LITERAL STRING_LITERAL
%type <ident> identifier
%type <expr> expression
%type <stmt> importStmt packageDecl statement funDecl variableDecl
%type <stmtVec> statements
%type <exprVec> expressions
%type <typeNode> type
%type <boolval> mutableModifier nullableModifier

%type <intExpr> integer
%type <floatExpr> float_
%type <strExpr> string_ CHAR_LITERAL

%start program
%%
program:
    packageDecl importStmt statements {
        // Create a new program node
        program = new dap::parser::ProgramNode();
        // Log message when parsing a program node
        parserLog("Parsed program node");
    };

variableDecl:
    mutableModifier type identifier nullableModifier ASSIGN expression SEMICOLON {
        $$ = new dap::parser::VariableDeclarationNode($2, $6, $3, $4, $1);
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
    }
    | mutableModifier identifier nullableModifier ASSIGN expression SEMICOLON {
        $$ = new dap::parser::VariableDeclarationNode(nullptr, $5, $2, $3, $1);
        // Log message when parsing a variable declaration node without explicit type
        parserLog("Parsed variable declaration node without explicit type");
    };

expression:
    integer {
        $$ = $1;
        // Log message when parsing an integer expression node
        parserLog("Parsed integer expression node");
    }
    | identifier {
        $$ = $1;

        parserLog("Parsed identifier expression node: [" + $1->getName() + "]");
    };

funDecl:
    FUN identifier LEFT_PAREN RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE {
        if ($2->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        $$ = new dap::parser::FunctionDeclarationNode($2->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        $6);
        // Log message when parsing a function declaration node without parameters
        parserLog("Parsed function declaration node without parameters");
    }
    | FUN identifier LEFT_PAREN RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE {
        if ($2->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        $$ = new dap::parser::FunctionDeclarationNode($2->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        $7);
        // Log message when parsing a function declaration node without parameters
        parserLog("Parsed function declaration node without parameters");
    }
    | FUN identifier LEFT_PAREN expressions RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE {
        if ($2->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        $$ = new dap::parser::FunctionDeclarationNode($2->name_parts->at(0),
                                                        $4,
                                                        nullptr,
                                                        $7);
        // Log message when parsing a function declaration node with parameters
        parserLog("Parsed function declaration node with parameters");

    }
    | FUN identifier LEFT_PAREN expressions RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE {
        if ($2->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        $$ = new dap::parser::FunctionDeclarationNode($2->name_parts->at(0),
                                                        $4,
                                                        $6,
                                                        $8);
        // Log message when parsing a function declaration node with parameters and return type
        parserLog("Parsed function declaration node with parameters and return type");
    };


nullableModifier:
    /* empty */ {
        $$ = false;
        // Log message when parsing a variable declaration node without explicit type
        parserLog("Parsed variable declaration node without explicit nullablity");
    }
    | QUESTION {
        $$ = true;
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
        $$ = true;
    }
    | BANG {
        $$ = false;
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
    };

mutableModifier:
    /* empty */ {
        $$ = false;
        parserLog("Parsed variable declaration node without explicit mutability");
    }
    | IMT {
        $$ = false;
        parserLog("Parsed variable declaration node");
    }
    | VAR {
        $$ = true;
        parserLog("Parsed variable declaration node");
    };


identifier:
    IDENTIFIER {
        $$ = new dap::parser::QualifiedName(*$1);
        delete $1;
        // Log message when parsing an identifier node
        parserLog("Parsed identifier node");
    }
    | identifier DOT IDENTIFIER {
        $1->name_parts->push_back(*$3);
        $$ = $1;
        delete $3;
        // Log message when parsing a qualified identifier node
        parserLog("Parsed qualified identifier node");
    };

integer:
    INTEGER {
        $$ = new dap::parser::Integer(atol($1->c_str()));
        // Log message when parsing an integer node
        parserLog("Parsed integer node");
    };

float_:
    FLOAT_LITERAL {
        $$ = new dap::parser::Float(atof($1->c_str()));
        // Log message when parsing a float node
        parserLog("Parsed float node");
    };

string_:
    STRING_LITERAL {
        $$ = new dap::parser::String(*$1);
        // Log message when parsing a string node
        parserLog("Parsed string node");
    };
type:
    identifier {
        $$ = new dap::parser::TypeNode($1);
        // Log message when parsing a type node
        parserLog("Parsed type node");
    }
    | type MUL {
        $$ = $1;
        $$->isPointer = true;
        // Log message when parsing a pointer type node
        parserLog("Parsed pointer type node");
    }
    | type LBRACK RBRACK {
        $$ = $1;
        $$->isArray = true;
        // Log message when parsing an array type node without size
        parserLog("Parsed array type node without size");
    }
    | type LBRACK integer RBRACK {
        $$ = $1;
        $$->isArray = true;
        $$->arraySize = std::stoi($3->getVal());
        // Log message when parsing an array type node with size
        parserLog("Parsed array type node with size");
    }
    | INT {
        $$ = new dap::parser::TypeNode(BasicType::INT);
        // Log message when parsing an int type node
        parserLog("Parsed int type node");
    }
    | BYTE {
        $$ = new dap::parser::TypeNode(BasicType::BYTE);
        // Log message when parsing a byte type node
        parserLog("Parsed byte type node");
    }
    | SHORT {
        $$ = new dap::parser::TypeNode(BasicType::SHORT);
        // Log message when parsing a short type node
        parserLog("Parsed short type node");
    }
    | LONG {
        $$ = new dap::parser::TypeNode(BasicType::LONG);
        // Log message when parsing a long type node
        parserLog("Parsed long type node");
    }
    | FLOAT {
        $$ = new dap::parser::TypeNode(BasicType::FLOAT);
        // Log message when parsing a float type node
        parserLog("Parsed float type node");
    }
    | DOUBLE {
        $$ = new dap::parser::TypeNode(BasicType::DOUBLE);
        // Log message when parsing a double type node
        parserLog("Parsed double type node");
    }
    | BOOL {
        $$ = new dap::parser::TypeNode(BasicType::BOOL);
        // Log message when parsing a bool type node
        parserLog("Parsed bool type node");
    }
    | UINT {
        $$ = new dap::parser::TypeNode(BasicType::UINT);
        // Log message when parsing a uint type node
        parserLog("Parsed uint type node");
    }
    | USHORT {
        $$ = new dap::parser::TypeNode(BasicType::USHORT);
        // Log message when parsing a ushort type node
        parserLog("Parsed ushort type node");
    }
    | ULONG {
        $$ = new dap::parser::TypeNode(BasicType::ULONG);
        // Log message when parsing a ulong type node
        parserLog("Parsed ulong type node");
    }
    | LLONG {
        $$ = new dap::parser::TypeNode(BasicType::LLONG);
        // Log message when parsing a lllong type node
        parserLog("Parsed lllong type node");
    }
    | ULLONG {
        $$ = new dap::parser::TypeNode(BasicType::ULLONG);
        // Log message when parsing a ullong type node
        parserLog("Parsed ullong type node");
    };

packageDecl:
    /* empty */ {

    } |
    PACKAGE identifier SEMICOLON {
        program->packageName = $2;
        // Log message when parsing a package declaration node
        parserLog("Parsed package declaration node: package [" + $2->getName() + "]");
    };

importStmt:
    /* empty */ {

    }
    | IMPORT identifier SEMICOLON {
        auto info = new dap::parser::ProgramNode::importedPackageInfo($2, false);
        program->importedPackages.push_back(info);
        // Log message when parsing an import statement node
        parserLog("Parsed import statement node: import [" + $2->getName() + "]");
    }
    | IMPORT identifier DOT MUL SEMICOLON {
        auto info = new dap::parser::ProgramNode::importedPackageInfo($2, true);
        program->importedPackages.push_back(info);
        // Log message when parsing an import wildcard statement node
        parserLog("Parsed import wildcard statement node: import [" + $2->getName() + "] [all]");
    };

statement:
    expression SEMICOLON {
        // Log message when parsing an expression statement node
        parserLog("Parsed expression statement node");
    }
    | funDecl {
        $$ = $1;
        // Log message when parsing a function declaration statement node
        parserLog("Parsed function declaration statement node: [" + (dynamic_cast<dap::parser::FunctionDeclarationNode*>($1))->name + "]");
    }
    | variableDecl {
        $$ = $1;
        // Log message when parsing a variable declaration statement node
        parserLog("Parsed variable declaration statement node: [" + (dynamic_cast<dap::parser::VariableDeclarationNode*>($1))->variableName->getName() + "]");
    };

statements:
    /* empty */ {
        $$ = new std::vector<dap::parser::Statement*>();
        // Log message when starting to parse a list of statements
        parserLog("Started parsing statements list");
    }
    | statements statement {
        $$->push_back($2);
        // Log message when adding a statement to the statements list
        parserLog("Added statement to statements list");
    };

expressions:
    /* empty */ {
        $$ = new std::vector<dap::parser::Expression*>();
        // Log message when starting to parse a list of expressions
        parserLog("Started parsing expressions list");
    }
    | expressions COMMA expression {
        $$->push_back($3);
        // Log message when adding an expression to the expressions list
        parserLog("Added expression to expressions list");
    };
%%