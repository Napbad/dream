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
    EXTERN = 274,                  /* EXTERN  */
    INT = 275,                     /* INT  */
    BYTE = 276,                    /* BYTE  */
    SHORT = 277,                   /* SHORT  */
    LONG = 278,                    /* LONG  */
    FLOAT = 279,                   /* FLOAT  */
    DOUBLE = 280,                  /* DOUBLE  */
    BOOL = 281,                    /* BOOL  */
    UINT = 282,                    /* UINT  */
    USHORT = 283,                  /* USHORT  */
    ULONG = 284,                   /* ULONG  */
    LLONG = 285,                   /* LLONG  */
    ULLONG = 286,                  /* ULLONG  */
    IDENTIFIER = 287,              /* IDENTIFIER  */
    INTEGER = 288,                 /* INTEGER  */
    BINARY_LITERAL = 289,          /* BINARY_LITERAL  */
    OCTAL_LITERAL = 290,           /* OCTAL_LITERAL  */
    HEXADECIMAL_LITERAL = 291,     /* HEXADECIMAL_LITERAL  */
    STRING_LITERAL = 292,          /* STRING_LITERAL  */
    CHAR_LITERAL = 293,            /* CHAR_LITERAL  */
    FLOAT_LITERAL = 294,           /* FLOAT_LITERAL  */
    TRUE = 295,                    /* TRUE  */
    FALSE = 296,                   /* FALSE  */
    PLUS = 297,                    /* PLUS  */
    MINUS = 298,                   /* MINUS  */
    MUL = 299,                     /* MUL  */
    DIV = 300,                     /* DIV  */
    MOD = 301,                     /* MOD  */
    BIT_AND = 302,                 /* BIT_AND  */
    BIT_OR = 303,                  /* BIT_OR  */
    BIT_XOR = 304,                 /* BIT_XOR  */
    BIT_NOT = 305,                 /* BIT_NOT  */
    SHIFT_LEFT = 306,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 307,             /* SHIFT_RIGHT  */
    LOGIC_SHIFT_RIGHT = 308,       /* LOGIC_SHIFT_RIGHT  */
    ASSIGN = 309,                  /* ASSIGN  */
    ADD_ASSIGN = 310,              /* ADD_ASSIGN  */
    MUL_ASSIGN = 311,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 312,              /* DIV_ASSIGN  */
    MINUS_ASSIGN = 313,            /* MINUS_ASSIGN  */
    MOD_ASSIGN = 314,              /* MOD_ASSIGN  */
    AND_ASSIGN = 315,              /* AND_ASSIGN  */
    OR_ASSIGN = 316,               /* OR_ASSIGN  */
    BIT_AND_ASSIGN = 317,          /* BIT_AND_ASSIGN  */
    BIT_OR_ASSIGN = 318,           /* BIT_OR_ASSIGN  */
    BIT_XOR_ASSIGN = 319,          /* BIT_XOR_ASSIGN  */
    SHIFT_LEFT_ASSIGN = 320,       /* SHIFT_LEFT_ASSIGN  */
    SHIFT_RIGHT_ASSIGN = 321,      /* SHIFT_RIGHT_ASSIGN  */
    LOGIC_SHIFT_RIGHT_ASSIGN = 322, /* LOGIC_SHIFT_RIGHT_ASSIGN  */
    INCREMENT = 323,               /* INCREMENT  */
    DECREMENT = 324,               /* DECREMENT  */
    LESS_THAN = 325,               /* LESS_THAN  */
    GREATER_THAN = 326,            /* GREATER_THAN  */
    LESS_THAN_EQUAL = 327,         /* LESS_THAN_EQUAL  */
    GREATER_THAN_EQUAL = 328,      /* GREATER_THAN_EQUAL  */
    EQUAL = 329,                   /* EQUAL  */
    NOT_EQUAL = 330,               /* NOT_EQUAL  */
    AND = 331,                     /* AND  */
    OR = 332,                      /* OR  */
    XOR = 333,                     /* XOR  */
    COMMA = 334,                   /* COMMA  */
    SEMICOLON = 335,               /* SEMICOLON  */
    COLON = 336,                   /* COLON  */
    LEFT_BRACE = 337,              /* LEFT_BRACE  */
    RIGHT_BRACE = 338,             /* RIGHT_BRACE  */
    LEFT_PAREN = 339,              /* LEFT_PAREN  */
    RIGHT_PAREN = 340,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 341,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 342,           /* RIGHT_BRACKET  */
    DOT = 343,                     /* DOT  */
    ELLIPSIS = 344,                /* ELLIPSIS  */
    QUESTION = 345,                /* QUESTION  */
    BANG = 346                     /* BANG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 249 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"

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
    dap::parser::StringNode *strExpr;
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

#line 180 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED  */
