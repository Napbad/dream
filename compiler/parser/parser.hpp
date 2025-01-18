/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PACKAGE = 258,                 /* PACKAGE  */
    IMPORT = 259,                  /* IMPORT  */
    FUN = 260,                     /* FUN  */
    VOID = 261,                    /* VOID  */
    FOR = 262,                     /* FOR  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    MATCH = 265,                   /* MATCH  */
    STRUCT = 266,                  /* STRUCT  */
    TRAIT = 267,                   /* TRAIT  */
    TYPEDEF = 268,                 /* TYPEDEF  */
    IMT = 269,                     /* IMT  */
    VAR = 270,                     /* VAR  */
    INSTANCEOF = 271,              /* INSTANCEOF  */
    RETURN = 272,                  /* RETURN  */
    CONST = 273,                   /* CONST  */
    INT = 274,                     /* INT  */
    BYTE = 275,                    /* BYTE  */
    SHORT = 276,                   /* SHORT  */
    LONG = 277,                    /* LONG  */
    FLOAT = 278,                   /* FLOAT  */
    DOUBLE = 279,                  /* DOUBLE  */
    BOOL = 280,                    /* BOOL  */
    UINT = 281,                    /* UINT  */
    USHORT = 282,                  /* USHORT  */
    ULONG = 283,                   /* ULONG  */
    LLONG = 284,                   /* LLONG  */
    ULLONG = 285,                  /* ULLONG  */
    IDENTIFIER = 286,              /* IDENTIFIER  */
    INTEGER = 287,                 /* INTEGER  */
    BINARY_LITERAL = 288,          /* BINARY_LITERAL  */
    OCTAL_LITERAL = 289,           /* OCTAL_LITERAL  */
    HEXADECIMAL_LITERAL = 290,     /* HEXADECIMAL_LITERAL  */
    STRING_LITERAL = 291,          /* STRING_LITERAL  */
    CHAR_LITERAL = 292,            /* CHAR_LITERAL  */
    FLOAT_LITERAL = 293,           /* FLOAT_LITERAL  */
    TRUE = 294,                    /* TRUE  */
    FALSE = 295,                   /* FALSE  */
    PLUS = 296,                    /* PLUS  */
    MINUS = 297,                   /* MINUS  */
    MUL = 298,                     /* MUL  */
    DIV = 299,                     /* DIV  */
    MOD = 300,                     /* MOD  */
    BIT_AND = 301,                 /* BIT_AND  */
    BIT_OR = 302,                  /* BIT_OR  */
    BIT_XOR = 303,                 /* BIT_XOR  */
    BIT_NOT = 304,                 /* BIT_NOT  */
    SHIFT_LEFT = 305,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 306,             /* SHIFT_RIGHT  */
    LOGIC_SHIFT_LEFT = 307,        /* LOGIC_SHIFT_LEFT  */
    ASSIGN = 308,                  /* ASSIGN  */
    ADD_ASSIGN = 309,              /* ADD_ASSIGN  */
    MUL_ASSIGN = 310,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 311,              /* DIV_ASSIGN  */
    MINUS_ASSIGN = 312,            /* MINUS_ASSIGN  */
    MOD_ASSIGN = 313,              /* MOD_ASSIGN  */
    BIT_AND_ASSIGN = 314,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 315,           /* BIT_OR_ASSIGN  */
    BIT_XOR_ASSIGN = 316,          /* BIT_XOR_ASSIGN  */
    SHIFT_LEFT_ASSIGN = 317,       /* SHIFT_LEFT_ASSIGN  */
    SHIFT_RIGHT_ASSIGN = 318,      /* SHIFT_RIGHT_ASSIGN  */
    LOGIC_SHIFT_LEFT_ASSIGN = 319, /* LOGIC_SHIFT_LEFT_ASSIGN  */
    INCREMENT = 320,               /* INCREMENT  */
    DECREMENT = 321,               /* DECREMENT  */
    LESS_THAN = 322,               /* LESS_THAN  */
    GREATER_THAN = 323,            /* GREATER_THAN  */
    LESS_THAN_EQUAL = 324,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 325,      /* GREATER_THAN_EQUAL  */
    EQUAL = 326,                   /* EQUAL  */
    NOT_EQUAL = 327,               /* NOT_EQUAL  */
    AND = 328,                     /* AND  */
    OR = 329,                      /* OR  */
    COMMA = 330,                   /* COMMA  */
    SEMICOLON = 331,               /* SEMICOLON  */
    COLON = 332,                   /* COLON  */
    LEFT_BRACE = 333,              /* LEFT_BRACE  */
    RIGHT_BRACE = 334,             /* RIGHT_BRACE  */
    LEFT_PAREN = 335,              /* LEFT_PAREN  */
    RIGHT_PAREN = 336,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 337,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 338,           /* RIGHT_BRACKET  */
    DOT = 339,                     /* DOT  */
    ELLIPSIS = 340,                /* ELLIPSIS  */
    QUESTION = 341,                /* QUESTION  */
    BANG = 342                     /* BANG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"

#include <vector>
#include "parser/ASTNode.h"

    // dap::parser::ASTNode *node;
    // dap::parser::BlockStmt *block;
    dap::parser::Expression *expr;
    dap::parser::Statement *stmt;
    dap::parser::QualifiedNameNode *ident;
    dap::parser::TypeNode *typeNode;
    std::vector<dap::parser::TypeNode*> *typeNodeVec;
    dap::parser::IntegerNode *intExpr;
    dap::parser::String *strExpr;
    dap::parser::FloatNode *floatExpr;
    std::vector<dap::parser::Expression*> *exprVec;
    std::vector<dap::parser::Statement*> *stmtVec;
    std::vector<dap::parser::VariableDeclarationNode*> *varDeclVec;
    std::string *str;
    char charVal;
    int IntegerNode;
    double floatVal;
    bool boolval;
    int token;

#line 176 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED  */
