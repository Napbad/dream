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
    CHAR = 277,                    /* CHAR  */
    FLOAT = 278,                   /* FLOAT  */
    DOUBLE = 279,                  /* DOUBLE  */
    BOOL = 280,                    /* BOOL  */
    UINT = 281,                    /* UINT  */
    USHORT = 282,                  /* USHORT  */
    ULONG = 283,                   /* ULONG  */
    LLLONG = 284,                  /* LLLONG  */
    ULLONG = 285,                  /* ULLONG  */
    IDENTIFIER = 286,              /* IDENTIFIER  */
    INTEGER = 287,                 /* INTEGER  */
    BINARY_LITERAL = 288,          /* BINARY_LITERAL  */
    OCTAL_LITERAL = 289,           /* OCTAL_LITERAL  */
    HEXADECIMAL_LITERAL = 290,     /* HEXADECIMAL_LITERAL  */
    FLOAT_LITERAL = 291,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 292,          /* STRING_LITERAL  */
    CHAR_LITERAL = 293,            /* CHAR_LITERAL  */
    ASSIGN = 294,                  /* ASSIGN  */
    ADD_ASSIGN = 295,              /* ADD_ASSIGN  */
    MINUS_ASSIGN = 296,            /* MINUS_ASSIGN  */
    INCREMENT = 297,               /* INCREMENT  */
    LESS_THAN = 298,               /* LESS_THAN  */
    COMMA = 299,                   /* COMMA  */
    SEMICOLON = 300,               /* SEMICOLON  */
    COLON = 301,                   /* COLON  */
    LEFT_BRACE = 302,              /* LEFT_BRACE  */
    RIGHT_BRACE = 303,             /* RIGHT_BRACE  */
    LEFT_PAREN = 304,              /* LEFT_PAREN  */
    RIGHT_PAREN = 305,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 306,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 307,           /* RIGHT_BRACKET  */
    DOT = 308,                     /* DOT  */
    ELLIPSIS = 309,                /* ELLIPSIS  */
    QUESTION = 310,                /* QUESTION  */
    BANG = 311                     /* BANG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"

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

#line 142 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NAPBAD_PROJECT_DAP_DEV_MAIN_COMPILER_PARSER_PARSER_HPP_INCLUDED  */
