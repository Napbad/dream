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
    INT = 273,                     /* INT  */
    BYTE = 274,                    /* BYTE  */
    SHORT = 275,                   /* SHORT  */
    LONG = 276,                    /* LONG  */
    FLOAT = 277,                   /* FLOAT  */
    DOUBLE = 278,                  /* DOUBLE  */
    BOOL = 279,                    /* BOOL  */
    UINT = 280,                    /* UINT  */
    USHORT = 281,                  /* USHORT  */
    ULONG = 282,                   /* ULONG  */
    LLONG = 283,                   /* LLONG  */
    ULLONG = 284,                  /* ULLONG  */
    IDENTIFIER = 285,              /* IDENTIFIER  */
    INTEGER = 286,                 /* INTEGER  */
    BINARY_LITERAL = 287,          /* BINARY_LITERAL  */
    OCTAL_LITERAL = 288,           /* OCTAL_LITERAL  */
    HEXADECIMAL_LITERAL = 289,     /* HEXADECIMAL_LITERAL  */
    STRING_LITERAL = 290,          /* STRING_LITERAL  */
    CHAR_LITERAL = 291,            /* CHAR_LITERAL  */
    FLOAT_LITERAL = 292,           /* FLOAT_LITERAL  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    MUL = 295,                     /* MUL  */
    DIV = 296,                     /* DIV  */
    MOD = 297,                     /* MOD  */
    BIT_AND = 298,                 /* BIT_AND  */
    BIT_OR = 299,                  /* BIT_OR  */
    BIT_XOR = 300,                 /* BIT_XOR  */
    BIT_NOT = 301,                 /* BIT_NOT  */
    SHIFT_LEFT = 302,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 303,             /* SHIFT_RIGHT  */
    LOGIC_SHIFT_LEFT = 304,        /* LOGIC_SHIFT_LEFT  */
    ASSIGN = 305,                  /* ASSIGN  */
    ADD_ASSIGN = 306,              /* ADD_ASSIGN  */
    MUL_ASSIGN = 307,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 308,              /* DIV_ASSIGN  */
    MINUS_ASSIGN = 309,            /* MINUS_ASSIGN  */
    MOD_ASSIGN = 310,              /* MOD_ASSIGN  */
    BIT_AND_ASSIGN = 311,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 312,           /* BIT_OR_ASSIGN  */
    BIT_XOR_ASSIGN = 313,          /* BIT_XOR_ASSIGN  */
    SHIFT_LEFT_ASSIGN = 314,       /* SHIFT_LEFT_ASSIGN  */
    SHIFT_RIGHT_ASSIGN = 315,      /* SHIFT_RIGHT_ASSIGN  */
    LOGIC_SHIFT_LEFT_ASSIGN = 316, /* LOGIC_SHIFT_LEFT_ASSIGN  */
    INCREMENT = 317,               /* INCREMENT  */
    DECREMENT = 318,               /* DECREMENT  */
    LESS_THAN = 319,               /* LESS_THAN  */
    GREATER_THAN = 320,            /* GREATER_THAN  */
    LESS_THAN_EQUAL = 321,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 322,      /* GREATER_THAN_EQUAL  */
    EQUAL = 323,                   /* EQUAL  */
    NOT_EQUAL = 324,               /* NOT_EQUAL  */
    AND = 325,                     /* AND  */
    OR = 326,                      /* OR  */
    COMMA = 327,                   /* COMMA  */
    SEMICOLON = 328,               /* SEMICOLON  */
    COLON = 329,                   /* COLON  */
    LEFT_BRACE = 330,              /* LEFT_BRACE  */
    RIGHT_BRACE = 331,             /* RIGHT_BRACE  */
    LEFT_PAREN = 332,              /* LEFT_PAREN  */
    RIGHT_PAREN = 333,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 334,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 335,           /* RIGHT_BRACKET  */
    DOT = 336,                     /* DOT  */
    ELLIPSIS = 337,                /* ELLIPSIS  */
    QUESTION = 338,                /* QUESTION  */
    BANG = 339,                    /* BANG  */
    LBRACK = 340,                  /* LBRACK  */
    RBRACK = 341                   /* RBRACK  */
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

#line 174 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED  */
