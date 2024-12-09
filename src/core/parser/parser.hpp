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

#ifndef YY_YY_SRC_CORE_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_SRC_CORE_PARSER_PARSER_HPP_INCLUDED
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
    STRING_LITERAL = 258,          /* STRING_LITERAL  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    INT_TOKEN = 260,               /* INT_TOKEN  */
    DOUBLE_TOKEN = 261,            /* DOUBLE_TOKEN  */
    STRUCT = 262,                  /* STRUCT  */
    BREAK = 263,                   /* BREAK  */
    DOT = 264,                     /* DOT  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    TIMES = 267,                   /* TIMES  */
    DIVIDE = 268,                  /* DIVIDE  */
    MOD = 269,                     /* MOD  */
    ASSIGN = 270,                  /* ASSIGN  */
    SEMICOLON = 271,               /* SEMICOLON  */
    COMMA = 272,                   /* COMMA  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    LBRACKET = 277,                /* LBRACKET  */
    RBRACKET = 278,                /* RBRACKET  */
    LT = 279,                      /* LT  */
    LE = 280,                      /* LE  */
    GT = 281,                      /* GT  */
    GE = 282,                      /* GE  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    NOT = 287,                     /* NOT  */
    XOR = 288,                     /* XOR  */
    UMINUS = 289,                  /* UMINUS  */
    UPLUS = 290,                   /* UPLUS  */
    PLUS_ASSIGN = 291,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 292,            /* MINUS_ASSIGN  */
    TIMES_ASSIGN = 293,            /* TIMES_ASSIGN  */
    DIVIDE_ASSIGN = 294,           /* DIVIDE_ASSIGN  */
    MOD_ASSIGN = 295,              /* MOD_ASSIGN  */
    INC = 296,                     /* INC  */
    DEC = 297,                     /* DEC  */
    BIT_AND = 298,                 /* BIT_AND  */
    IF = 299,                      /* IF  */
    ELSE = 300,                    /* ELSE  */
    ELIF = 301,                    /* ELIF  */
    FOR = 302,                     /* FOR  */
    RETURN = 303,                  /* RETURN  */
    FUN = 304,                     /* FUN  */
    EXTERN = 305,                  /* EXTERN  */
    INCLUDE = 306,                 /* INCLUDE  */
    PACKAGE = 307,                 /* PACKAGE  */
    VAR = 308,                     /* VAR  */
    IMT = 309,                     /* IMT  */
    NULLABLE = 310,                /* NULLABLE  */
    NON_NULLABLE = 311,            /* NON_NULLABLE  */
    LSHIFT = 312,                  /* LSHIFT  */
    RSHIFT = 313,                  /* RSHIFT  */
    URSHIFT = 314                  /* URSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "./src/core/parser/parser.y"

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

#line 141 "./src/core/parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_CORE_PARSER_PARSER_HPP_INCLUDED  */
