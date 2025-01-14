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
    PLUS = 294,                    /* PLUS  */
    MINUS = 295,                   /* MINUS  */
    MUL = 296,                     /* MUL  */
    DIV = 297,                     /* DIV  */
    MOD = 298,                     /* MOD  */
    BIT_AND = 299,                 /* BIT_AND  */
    BIT_OR = 300,                  /* BIT_OR  */
    BIT_XOR = 301,                 /* BIT_XOR  */
    BIT_NOT = 302,                 /* BIT_NOT  */
    SHIFT_LEFT = 303,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 304,             /* SHIFT_RIGHT  */
    LOGIC_SHIFT_LEFT = 305,        /* LOGIC_SHIFT_LEFT  */
    ASSIGN = 306,                  /* ASSIGN  */
    ADD_ASSIGN = 307,              /* ADD_ASSIGN  */
    MUL_ASSIGN = 308,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 309,              /* DIV_ASSIGN  */
    MINUS_ASSIGN = 310,            /* MINUS_ASSIGN  */
    MOD_ASSIGN = 311,              /* MOD_ASSIGN  */
    BIT_AND_ASSIGN = 312,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 313,           /* BIT_OR_ASSIGN  */
    BIT_XOR_ASSIGN = 314,          /* BIT_XOR_ASSIGN  */
    SHIFT_LEFT_ASSIGN = 315,       /* SHIFT_LEFT_ASSIGN  */
    SHIFT_RIGHT_ASSIGN = 316,      /* SHIFT_RIGHT_ASSIGN  */
    LOGIC_SHIFT_LEFT_ASSIGN = 317, /* LOGIC_SHIFT_LEFT_ASSIGN  */
    INCREMENT = 318,               /* INCREMENT  */
    DECREMENT = 319,               /* DECREMENT  */
    LESS_THAN = 320,               /* LESS_THAN  */
    GREATER_THAN = 321,            /* GREATER_THAN  */
    LESS_THAN_EQUAL = 322,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 323,      /* GREATER_THAN_EQUAL  */
    EQUAL = 324,                   /* EQUAL  */
    NOT_EQUAL = 325,               /* NOT_EQUAL  */
    AND = 326,                     /* AND  */
    OR = 327,                      /* OR  */
    COMMA = 328,                   /* COMMA  */
    SEMICOLON = 329,               /* SEMICOLON  */
    COLON = 330,                   /* COLON  */
    LEFT_BRACE = 331,              /* LEFT_BRACE  */
    RIGHT_BRACE = 332,             /* RIGHT_BRACE  */
    LEFT_PAREN = 333,              /* LEFT_PAREN  */
    RIGHT_PAREN = 334,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 335,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 336,           /* RIGHT_BRACKET  */
    DOT = 337,                     /* DOT  */
    ELLIPSIS = 338,                /* ELLIPSIS  */
    QUESTION = 339,                /* QUESTION  */
    BANG = 340,                    /* BANG  */
    LBRACK = 341,                  /* LBRACK  */
    RBRACK = 342                   /* RBRACK  */
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

#line 175 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED  */
