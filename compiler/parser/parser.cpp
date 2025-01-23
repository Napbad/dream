/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"

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
    dap::util::logInfo(msg, nullptr, dap::parser::currentParsingFile, yylineno);
#endif
}

void parserLog(std::string msg) {
#ifdef D_DEBUG
    dap::util::logInfo(msg, nullptr, dap::parser::currentParsingFile, yylineno);
#endif
}

std::string tokenToString(int token) {
    switch (token) {
        case PACKAGE:
            return "PACKAGE";
        case IMPORT:
            return "IMPORT";
        case FUN:
            return "FUN";
        case VOID:
            return "VOID";
        case FOR:
            return "FOR";
        case IF:
            return "IF";
        case ELSE:
            return "ELSE";
        case MATCH:
            return "MATCH";
        case STRUCT:
            return "STRUCT";
        case TRAIT:
            return "TRAIT";
        case TYPEDEF:
            return "TYPEDEF";
        case IMT:
            return "IMT";
        case VAR:
            return "VAR";
        case INSTANCEOF:
            return "INSTANCEOF";
        case RETURN:
            return "RETURN";
        case CONST:
            return "CONST";
        case EXTERN:
            return "EXTERN";
        case INT:
            return "INT";
        case BYTE:
            return "BYTE";
        case SHORT:
            return "SHORT";
        case LONG:
            return "LONG";
        case FLOAT:
            return "FLOAT";
        case DOUBLE:
            return "DOUBLE";
        case BOOL:
            return "BOOL";
        case UINT:
            return "UINT";
        case USHORT:
            return "USHORT";
        case ULONG:
            return "ULONG";
        case LLONG:
            return "LLONG";
        case ULLONG:
            return "ULLONG";
        case IDENTIFIER:
            return "IDENTIFIER";
        case INTEGER:
            return "INTEGER";
        case BINARY_LITERAL:
            return "BINARY_LITERAL";
        case OCTAL_LITERAL:
            return "OCTAL_LITERAL";
        case HEXADECIMAL_LITERAL:
            return "HEXADECIMAL_LITERAL";
        case STRING_LITERAL:
            return "STRING_LITERAL";
        case CHAR_LITERAL:
            return "CHAR_LITERAL";
        case FLOAT_LITERAL:
            return "FLOAT_LITERAL";
        case TRUE:
            return "TRUE";
        case FALSE:
            return "FALSE";
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        case MUL:
            return "MUL";
        case DIV:
            return "DIV";
        case MOD:
            return "MOD";
        case BIT_AND:
            return "BIT_AND";
        case BIT_OR:
            return "BIT_OR";
        case BIT_XOR:
            return "BIT_XOR";
        case BIT_NOT:
            return "BIT_NOT";
        case SHIFT_LEFT:
            return "SHIFT_LEFT";
        case SHIFT_RIGHT:
            return "SHIFT_RIGHT";
        case LOGIC_SHIFT_RIGHT:
            return "LOGIC_SHIFT_RIGHT";
        case ASSIGN:
            return "ASSIGN";
        case ADD_ASSIGN:
            return "ADD_ASSIGN";
        case MUL_ASSIGN:
            return "MUL_ASSIGN";
        case DIV_ASSIGN:
            return "DIV_ASSIGN";
        case MINUS_ASSIGN:
            return "MINUS_ASSIGN";
        case MOD_ASSIGN:
            return "MOD_ASSIGN";
        case AND_ASSIGN:
            return "AND_ASSIGN";
        case OR_ASSIGN:
            return "OR_ASSIGN";
        case BIT_AND_ASSIGN:
            return "BIT_AND_ASSIGN";
        case BIT_OR_ASSIGN:
            return "BIT_OR_ASSIGN";
        case BIT_XOR_ASSIGN:
            return "BIT_XOR_ASSIGN";
        case SHIFT_LEFT_ASSIGN:
            return "SHIFT_LEFT_ASSIGN";
        case SHIFT_RIGHT_ASSIGN:
            return "SHIFT_RIGHT_ASSIGN";
        case LOGIC_SHIFT_RIGHT_ASSIGN:
            return "LOGIC_SHIFT_RIGHT_ASSIGN";
        case INCREMENT:
            return "INCREMENT";
        case DECREMENT:
            return "DECREMENT";
        case LESS_THAN:
            return "LESS_THAN";
        case GREATER_THAN:
            return "GREATER_THAN";
        case LESS_THAN_EQUAL:
            return "LESS_THAN_EQUAL";
        case GREATER_THAN_EQUAL:
            return "GREATER_THAN_EQUAL";
        case EQUAL:
            return "EQUAL";
        case NOT_EQUAL:
            return "NOT_EQUAL";
        case AND:
            return "AND";
        case OR:
            return "OR";
        case XOR:
            return "XOR";
        case COMMA:
            return "COMMA";
        case SEMICOLON:
            return "SEMICOLON";
        case COLON:
            return "COLON";
        case LEFT_BRACE:
            return "LEFT_BRACE";
        case RIGHT_BRACE:
            return "RIGHT_BRACE";
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case LEFT_BRACKET:
            return "LEFT_BRACKET";
        case RIGHT_BRACKET:
            return "RIGHT_BRACKET";
        case DOT:
            return "DOT";
        case ELLIPSIS:
            return "ELLIPSIS";
        case QUESTION:
            return "QUESTION";
        case BANG:
            return "BANG";
        default:
            return "UNKNOWN";
    }
}


#line 294 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PACKAGE = 3,                    /* PACKAGE  */
  YYSYMBOL_IMPORT = 4,                     /* IMPORT  */
  YYSYMBOL_FUN = 5,                        /* FUN  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_MATCH = 10,                     /* MATCH  */
  YYSYMBOL_STRUCT = 11,                    /* STRUCT  */
  YYSYMBOL_TRAIT = 12,                     /* TRAIT  */
  YYSYMBOL_TYPEDEF = 13,                   /* TYPEDEF  */
  YYSYMBOL_IMT = 14,                       /* IMT  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_INSTANCEOF = 16,                /* INSTANCEOF  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_EXTERN = 19,                    /* EXTERN  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_BYTE = 21,                      /* BYTE  */
  YYSYMBOL_SHORT = 22,                     /* SHORT  */
  YYSYMBOL_LONG = 23,                      /* LONG  */
  YYSYMBOL_FLOAT = 24,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 25,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 26,                      /* BOOL  */
  YYSYMBOL_UINT = 27,                      /* UINT  */
  YYSYMBOL_USHORT = 28,                    /* USHORT  */
  YYSYMBOL_ULONG = 29,                     /* ULONG  */
  YYSYMBOL_LLONG = 30,                     /* LLONG  */
  YYSYMBOL_ULLONG = 31,                    /* ULLONG  */
  YYSYMBOL_IDENTIFIER = 32,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 33,                   /* INTEGER  */
  YYSYMBOL_BINARY_LITERAL = 34,            /* BINARY_LITERAL  */
  YYSYMBOL_OCTAL_LITERAL = 35,             /* OCTAL_LITERAL  */
  YYSYMBOL_HEXADECIMAL_LITERAL = 36,       /* HEXADECIMAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 37,            /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 38,              /* CHAR_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 39,             /* FLOAT_LITERAL  */
  YYSYMBOL_TRUE = 40,                      /* TRUE  */
  YYSYMBOL_FALSE = 41,                     /* FALSE  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MUL = 44,                       /* MUL  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_MOD = 46,                       /* MOD  */
  YYSYMBOL_BIT_AND = 47,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 48,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 49,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 50,                   /* BIT_NOT  */
  YYSYMBOL_SHIFT_LEFT = 51,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 52,               /* SHIFT_RIGHT  */
  YYSYMBOL_LOGIC_SHIFT_RIGHT = 53,         /* LOGIC_SHIFT_RIGHT  */
  YYSYMBOL_ASSIGN = 54,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 55,                /* ADD_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 56,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 57,                /* DIV_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 58,              /* MINUS_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 59,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 60,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 61,                 /* OR_ASSIGN  */
  YYSYMBOL_BIT_AND_ASSIGN = 62,            /* BIT_AND_ASSIGN  */
  YYSYMBOL_BIT_OR_ASSIGN = 63,             /* BIT_OR_ASSIGN  */
  YYSYMBOL_BIT_XOR_ASSIGN = 64,            /* BIT_XOR_ASSIGN  */
  YYSYMBOL_SHIFT_LEFT_ASSIGN = 65,         /* SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_SHIFT_RIGHT_ASSIGN = 66,        /* SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_LOGIC_SHIFT_RIGHT_ASSIGN = 67,  /* LOGIC_SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_INCREMENT = 68,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 69,                 /* DECREMENT  */
  YYSYMBOL_LESS_THAN = 70,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 71,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 72,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 73,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_EQUAL = 74,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 75,                 /* NOT_EQUAL  */
  YYSYMBOL_AND = 76,                       /* AND  */
  YYSYMBOL_OR = 77,                        /* OR  */
  YYSYMBOL_XOR = 78,                       /* XOR  */
  YYSYMBOL_COMMA = 79,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 80,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 81,                     /* COLON  */
  YYSYMBOL_LEFT_BRACE = 82,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 83,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_PAREN = 84,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 85,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_BRACKET = 86,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 87,             /* RIGHT_BRACKET  */
  YYSYMBOL_DOT = 88,                       /* DOT  */
  YYSYMBOL_ELLIPSIS = 89,                  /* ELLIPSIS  */
  YYSYMBOL_QUESTION = 90,                  /* QUESTION  */
  YYSYMBOL_BANG = 91,                      /* BANG  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_program = 93,                   /* program  */
  YYSYMBOL_variableDecl = 94,              /* variableDecl  */
  YYSYMBOL_constantDecl = 95,              /* constantDecl  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_functionDeclaration = 97,       /* functionDeclaration  */
  YYSYMBOL_functionParameters = 98,        /* functionParameters  */
  YYSYMBOL_nullableModifier = 99,          /* nullableModifier  */
  YYSYMBOL_mutableModifier = 100,          /* mutableModifier  */
  YYSYMBOL_identifier = 101,               /* identifier  */
  YYSYMBOL_integer = 102,                  /* integer  */
  YYSYMBOL_float_ = 103,                   /* float_  */
  YYSYMBOL_string_ = 104,                  /* string_  */
  YYSYMBOL_bool_ = 105,                    /* bool_  */
  YYSYMBOL_type = 106,                     /* type  */
  YYSYMBOL_packageDecl = 107,              /* packageDecl  */
  YYSYMBOL_importStmt = 108,               /* importStmt  */
  YYSYMBOL_statement = 109,                /* statement  */
  YYSYMBOL_statements = 110,               /* statements  */
  YYSYMBOL_expressions = 111,              /* expressions  */
  YYSYMBOL_structDecl = 112,               /* structDecl  */
  YYSYMBOL_structFields = 113,             /* structFields  */
  YYSYMBOL_returnStmt = 114,               /* returnStmt  */
  YYSYMBOL_functionCall = 115,             /* functionCall  */
  YYSYMBOL_binaryExpression = 116,         /* binaryExpression  */
  YYSYMBOL_binaryOperator = 117,           /* binaryOperator  */
  YYSYMBOL_unaryExpression = 118,          /* unaryExpression  */
  YYSYMBOL_unaryOperator = 119             /* unaryOperator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   280,   280,   288,   294,   300,   306,   315,   321,   330,
     336,   342,   348,   354,   359,   366,   372,   380,   393,   406,
     421,   435,   448,   461,   476,   493,   499,   506,   515,   521,
     528,   536,   541,   546,   554,   561,   571,   579,   587,   595,
     601,   609,   615,   622,   629,   637,   643,   649,   655,   661,
     667,   673,   679,   685,   691,   697,   703,   711,   714,   721,
     724,   730,   738,   744,   750,   756,   762,   768,   777,   783,
     791,   797,   803,   811,   819,   825,   833,   841,   849,   857,
     860,   863,   866,   869,   872,   875,   878,   881,   884,   887,
     890,   893,   896,   899,   902,   905,   910,   918,   921,   924,
     927,   930
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PACKAGE", "IMPORT",
  "FUN", "VOID", "FOR", "IF", "ELSE", "MATCH", "STRUCT", "TRAIT",
  "TYPEDEF", "IMT", "VAR", "INSTANCEOF", "RETURN", "CONST", "EXTERN",
  "INT", "BYTE", "SHORT", "LONG", "FLOAT", "DOUBLE", "BOOL", "UINT",
  "USHORT", "ULONG", "LLONG", "ULLONG", "IDENTIFIER", "INTEGER",
  "BINARY_LITERAL", "OCTAL_LITERAL", "HEXADECIMAL_LITERAL",
  "STRING_LITERAL", "CHAR_LITERAL", "FLOAT_LITERAL", "TRUE", "FALSE",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "BIT_AND", "BIT_OR", "BIT_XOR",
  "BIT_NOT", "SHIFT_LEFT", "SHIFT_RIGHT", "LOGIC_SHIFT_RIGHT", "ASSIGN",
  "ADD_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MINUS_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "BIT_AND_ASSIGN", "BIT_OR_ASSIGN",
  "BIT_XOR_ASSIGN", "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN",
  "LOGIC_SHIFT_RIGHT_ASSIGN", "INCREMENT", "DECREMENT", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL",
  "NOT_EQUAL", "AND", "OR", "XOR", "COMMA", "SEMICOLON", "COLON",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "DOT", "ELLIPSIS", "QUESTION", "BANG", "$accept",
  "program", "variableDecl", "constantDecl", "expression",
  "functionDeclaration", "functionParameters", "nullableModifier",
  "mutableModifier", "identifier", "integer", "float_", "string_", "bool_",
  "type", "packageDecl", "importStmt", "statement", "statements",
  "expressions", "structDecl", "structFields", "returnStmt",
  "functionCall", "binaryExpression", "binaryOperator", "unaryExpression",
  "unaryOperator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     0,    39,    58,   -80,   -52,   -80,     0,   -80,   -80,
      40,   -46,     8,   -80,   -80,   -11,     0,     0,   -80,   -80,
     249,   232,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,     5,    13,   275,   -80,   232,   -25,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   249,    17,
      -2,   -71,   302,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -27,   -20,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   249,    14,   -20,
     249,   329,   -80,   -10,   -80,   -80,   249,   -80,   -30,   -24,
     329,   -80,   -80,    47,     1,   329,   -42,   142,   -80,     2,
      -5,   329,   -80,     7,   249,   249,    53,   249,   -80,   -80,
     -80,    20,   -26,    69,   187,    30,    34,   -80,   329,   329,
     249,   329,    98,   -80,   -80,   -80,   -80,   -80,    -6,   -80,
     -80,   329,   -80,   143,   188,   -80,   -80,   -80,   -80,   233,
     -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      57,     0,     0,    59,    34,     0,     1,     0,    68,    58,
       0,     0,    31,    35,    60,     0,     0,     0,    32,    33,
       0,     0,    36,    38,    37,    39,    40,    97,    98,   101,
      99,   100,     0,     0,     0,    62,     0,    10,     9,    11,
      12,    13,    69,    65,    66,    14,    15,    16,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    41,     0,    63,    64,    80,
      81,    82,    83,    84,    79,    86,    88,    89,    87,    90,
      94,    95,    85,    91,    92,    93,    67,     0,    28,     0,
      70,    96,    61,    31,    74,    76,     0,    42,     0,     0,
      78,    29,    30,     6,    28,    71,     0,     0,    26,     0,
      31,     8,    43,     0,     0,     0,     5,     0,    77,    21,
      68,    41,     0,    31,     0,     0,     0,    44,     7,     4,
       0,    72,    31,    22,    68,    27,    23,    68,     0,    73,
      75,     3,    17,    31,    31,    24,    68,    18,    19,    31,
      20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -79,   -80,   -19,   -80,   -80,    15,   -80,    -1,
      19,   -80,   -80,   -80,   -34,   -80,   -80,   -80,   -67,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    32,    33,    34,    35,   109,   103,    36,    37,
      38,    39,    40,    41,    66,     3,     8,    42,    12,   106,
      43,   110,    44,    45,    46,    87,    47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    52,    89,    22,    18,    19,    11,     1,    -2,    18,
      19,    94,     4,    16,   108,    50,    51,    10,    97,    17,
      65,    13,    18,    19,    97,    20,    21,    96,     9,    91,
     114,   126,     4,    49,    14,    88,    10,   117,    97,     6,
       4,    22,    15,   118,   135,    23,   -41,    24,    25,    26,
      27,    28,    29,   132,   133,    30,   134,   112,   -41,    90,
      98,    10,     7,    10,    10,    99,    98,   143,   100,   -25,
     144,   105,    13,   122,   145,   107,   146,   111,   125,   149,
      98,   123,    93,    18,    19,    67,    10,   124,   104,    10,
     138,   101,   102,    68,   127,   128,   129,    92,   131,    31,
     -41,   115,    10,    16,   101,   102,   121,   130,    10,    17,
     139,   141,    18,    19,   140,    20,    21,   113,     0,   116,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       4,    22,     0,     0,     0,    23,     0,    24,    25,    26,
      27,    28,    29,     0,     0,    30,     0,     0,    16,     0,
       0,     0,     0,     0,    17,     0,     0,    18,    19,     0,
      20,    21,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     4,     4,    22,     0,     0,     0,
      23,   142,    24,    25,    26,    27,    28,    29,     0,    31,
      30,     0,     0,    16,     0,     0,     0,     0,     0,    17,
       0,     0,    18,    19,     0,    20,    21,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     4,
       4,    22,   119,     0,   120,    23,   147,    24,    25,    26,
      27,    28,    29,     0,    31,    30,     0,     0,    16,     0,
       0,     0,     0,     0,    17,     0,     0,    18,    19,     0,
      20,    21,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     4,     4,    22,   136,     0,   137,
      23,   148,    24,    25,    26,    27,    28,    29,     0,    31,
      30,     4,    22,     0,     0,     0,    23,     0,    24,    25,
      26,    27,    28,    29,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,    69,    70,    71,
      72,    73,     0,     0,    31,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      31,     0,     0,     0,    69,    70,    71,    72,    73,    82,
       0,    83,    84,    85,     0,    86,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    82,     0,    83,    84,
      85,     0,    95,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       1,    20,    36,    33,    14,    15,     7,     3,     0,    14,
      15,    82,    32,     5,    93,    16,    17,    88,    44,    11,
      21,    32,    14,    15,    44,    17,    18,    54,    80,    48,
      54,   110,    32,    44,    80,    36,    88,    79,    44,     0,
      32,    33,    88,    85,   123,    37,    32,    39,    40,    41,
      42,    43,    44,   120,    80,    47,    82,    87,    44,    84,
      86,    88,     4,    88,    88,    66,    86,   134,    87,    79,
     137,    90,    32,   107,    80,    85,    82,    96,    83,   146,
      86,    79,    84,    14,    15,    80,    88,    85,    89,    88,
     124,    90,    91,    80,    87,   114,   115,    80,   117,    91,
      86,    54,    88,     5,    90,    91,   107,    54,    88,    11,
      80,   130,    14,    15,    80,    17,    18,    98,    -1,   104,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,    -1,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    32,    33,    -1,    -1,    -1,
      37,    83,    39,    40,    41,    42,    43,    44,    -1,    91,
      47,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    14,    15,    -1,    17,    18,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      32,    33,    80,    -1,    82,    37,    83,    39,    40,    41,
      42,    43,    44,    -1,    91,    47,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,    -1,
      17,    18,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    32,    33,    80,    -1,    82,
      37,    83,    39,    40,    41,    42,    43,    44,    -1,    91,
      47,    32,    33,    -1,    -1,    -1,    37,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    42,    43,    44,
      45,    46,    -1,    -1,    91,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    42,    43,    44,    45,    46,    74,
      -1,    76,    77,    78,    -1,    80,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    74,    -1,    76,    77,
      78,    -1,    80,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    76,    77,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    93,   107,    32,   101,     0,     4,   108,    80,
      88,   101,   110,    32,    80,    88,     5,    11,    14,    15,
      17,    18,    33,    37,    39,    40,    41,    42,    43,    44,
      47,    91,    94,    95,    96,    97,   100,   101,   102,   103,
     104,   105,   109,   112,   114,   115,   116,   118,   119,    44,
     101,   101,    96,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   101,   106,    80,    80,    42,
      43,    44,    45,    46,    54,    55,    56,    57,    58,    59,
      60,    61,    74,    76,    77,    78,    80,   117,   101,   106,
      84,    96,    80,    84,    82,    80,    54,    44,    86,   101,
      96,    90,    91,    99,   101,    96,   111,    85,    94,    98,
     113,    96,    87,   102,    54,    54,    99,    79,    85,    80,
      82,   101,   106,    79,    85,    83,    94,    87,    96,    96,
      54,    96,   110,    80,    82,    94,    80,    82,   106,    80,
      80,    96,    83,   110,   110,    80,    82,    83,    83,   110,
      83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    92,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,   100,   100,   100,   101,   101,   102,   103,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   109,   109,   109,   109,   109,   109,   110,   110,
     111,   111,   111,   112,   113,   113,   114,   115,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   119,   119,   119,
     119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     6,     5,     4,     3,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     8,     8,
       9,     5,     6,     6,     7,     0,     1,     3,     0,     1,
       1,     0,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     5,     1,     2,     2,     1,     1,     2,     0,     2,
       0,     1,     3,     6,     0,     3,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: packageDecl importStmt statements  */
#line 280 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                      {
        // Create a new program node
        program->statements = (yyvsp[0].stmtVec);
        // Log message when parsing a program node
        parserLog("Parsed program node");
    }
#line 1581 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 3: /* variableDecl: mutableModifier type identifier nullableModifier ASSIGN expression  */
#line 288 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                       {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode((yyvsp[-4].typeNode), (yyvsp[0].expr), (yyvsp[-3].ident), (yyvsp[-2].boolval), (yyvsp[-5].boolval));
        // Log message when parsing a variable declaration node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed variable declaration node");
    }
#line 1592 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 4: /* variableDecl: mutableModifier identifier nullableModifier ASSIGN expression  */
#line 294 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                    {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode(nullptr, (yyvsp[0].expr), (yyvsp[-3].ident), (yyvsp[-2].boolval), (yyvsp[-4].boolval));
        // Log message when parsing a variable declaration node without explicit type
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed variable declaration node without explicit type");
    }
#line 1603 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 5: /* variableDecl: mutableModifier type identifier nullableModifier  */
#line 300 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                       {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode((yyvsp[-2].typeNode), nullptr, (yyvsp[-1].ident), (yyvsp[0].boolval), (yyvsp[-3].boolval));
        // Log message when parsing a variable declaration node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed variable declaration node");
    }
#line 1614 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 6: /* variableDecl: mutableModifier identifier nullableModifier  */
#line 306 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                  {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode(nullptr, nullptr, (yyvsp[-1].ident), (yyvsp[0].boolval), (yyvsp[-2].boolval));
        // Log message when parsing a variable declaration node without explicit type
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed variable declaration node without explicit type");
    }
#line 1625 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 7: /* constantDecl: CONST type identifier ASSIGN expression  */
#line 315 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                            {
        (yyval.stmt) = new dap::parser::ConstantDeclarationNode((yyvsp[-3].typeNode), (yyvsp[-2].ident), (yyvsp[0].expr));
        // Log message when parsing a constant declaration node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed constant declaration node");
    }
#line 1636 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 8: /* constantDecl: CONST identifier ASSIGN expression  */
#line 321 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                         {
        (yyval.stmt) = new dap::parser::ConstantDeclarationNode(nullptr, (yyvsp[-2].ident), (yyvsp[0].expr));
        // Log message when parsing a constant declaration node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed constant declaration node");
    }
#line 1647 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 9: /* expression: integer  */
#line 330 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.expr) = (yyvsp[0].intExpr);
        // Log message when parsing an IntegerNode expression node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed IntegerNode expression node");
    }
#line 1658 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 10: /* expression: identifier  */
#line 336 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.expr) = (yyvsp[0].ident);

        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed identifier expression node: [" + (yyvsp[0].ident)->getName() + "]");
    }
#line 1669 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 11: /* expression: float_  */
#line 342 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].floatExpr);
        // Log message when parsing a FloatNode expression node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed FloatNode expression node");
    }
#line 1680 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 12: /* expression: string_  */
#line 348 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].strExpr);
        // Log message when parsing a StringNode expression node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed StringNode expression node");
    }
#line 1691 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 13: /* expression: bool_  */
#line 354 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed Boolean expression node"); 
    }
#line 1701 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 14: /* expression: functionCall  */
#line 359 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);

        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed function call expression node: [" + dynamic_cast<dap::parser::FunctionCallExpressionNode*>((yyvsp[0].expr))
                                                        ->name->getName() + "]");
    }
#line 1713 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 15: /* expression: binaryExpression  */
#line 366 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                       {
        (yyval.expr) = (yyvsp[0].expr);

        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed binary expression node");
    }
#line 1724 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 16: /* expression: unaryExpression  */
#line 372 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);

        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed unary expression node");
    }
#line 1735 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 17: /* functionDeclaration: FUN identifier LEFT_PAREN RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE  */
#line 380 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                            {
        if ((yyvsp[-5].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-5].ident)->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node without parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node without parameters");
    }
#line 1753 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 18: /* functionDeclaration: FUN identifier LEFT_PAREN RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE  */
#line 393 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                   {
        if ((yyvsp[-6].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-6].ident)->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node without parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node without parameters");
    }
#line 1771 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 19: /* functionDeclaration: FUN identifier LEFT_PAREN functionParameters RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE  */
#line 406 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                                 {
        if ((yyvsp[-6].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-6].ident)->name_parts->at(0),
                                                        (yyvsp[-4].varDeclVec),
                                                        nullptr,
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node with parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node with parameters");

    }
#line 1791 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 20: /* functionDeclaration: FUN identifier LEFT_PAREN functionParameters RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE  */
#line 421 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                                      {
        if ((yyvsp[-7].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-7].ident)->name_parts->at(0),
                                                        (yyvsp[-5].varDeclVec),
                                                        (yyvsp[-3].typeNode),
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node with parameters and return type
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node with parameters and return type");
    }
#line 1810 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 21: /* functionDeclaration: FUN identifier LEFT_PAREN RIGHT_PAREN SEMICOLON  */
#line 435 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                      {
        if ((yyvsp[-3].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-3].ident)->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        nullptr);
        // Log message when parsing a function declaration node without parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node without parameters");
    }
#line 1828 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 22: /* functionDeclaration: FUN identifier LEFT_PAREN RIGHT_PAREN type SEMICOLON  */
#line 448 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                           {
        if ((yyvsp[-4].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }
        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-4].ident)->name_parts->at(0),
                                                        nullptr,
                                                        nullptr,
                                                        nullptr);
        // Log message when parsing a function declaration node without parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node without parameters");
    }
#line 1846 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 23: /* functionDeclaration: FUN identifier LEFT_PAREN functionParameters RIGHT_PAREN SEMICOLON  */
#line 461 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                         {
        if ((yyvsp[-4].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-4].ident)->name_parts->at(0),
                                                        (yyvsp[-2].varDeclVec),
                                                        nullptr,
                                                        nullptr);
        // Log message when parsing a function declaration node with parameters
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node with parameters");

    }
#line 1866 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 24: /* functionDeclaration: FUN identifier LEFT_PAREN functionParameters RIGHT_PAREN type SEMICOLON  */
#line 476 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                              {
        if ((yyvsp[-5].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-5].ident)->name_parts->at(0),
                                                        (yyvsp[-3].varDeclVec),
                                                        (yyvsp[-1].typeNode),
                                                        nullptr);
        // Log message when parsing a function declaration node with parameters and return type
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration node with parameters and return type");
    }
#line 1885 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 25: /* functionParameters: %empty  */
#line 493 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.varDeclVec) = new std::vector<dap::parser::VariableDeclarationNode*>();
        // Log message when parsing a variable declaration node without explicit type

        parserLog("Parsed variable declaration node without explicit type");
    }
#line 1896 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 26: /* functionParameters: variableDecl  */
#line 499 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                    {
        (yyval.varDeclVec) = new std::vector<dap::parser::VariableDeclarationNode*>();
        (yyval.varDeclVec)->push_back(dynamic_cast<dap::parser::VariableDeclarationNode*>((yyvsp[0].stmt)));
        // Log message when parsing a variable declaration node

        parserLog("Parsed variable declaration node");
    }
#line 1908 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 27: /* functionParameters: functionParameters COMMA variableDecl  */
#line 506 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                             {
        (yyval.varDeclVec) = (yyvsp[-2].varDeclVec);
        (yyvsp[-2].varDeclVec)->push_back(dynamic_cast<dap::parser::VariableDeclarationNode*>((yyvsp[0].stmt)));
        // Log message when parsing a variable declaration node

        parserLog("Parsed variable declaration node");
    }
#line 1920 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 28: /* nullableModifier: %empty  */
#line 515 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.boolval) = false;
        // Log message when parsing a variable declaration node without explicit type

        parserLog("Parsed variable declaration node without explicit nullablity");
    }
#line 1931 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 29: /* nullableModifier: QUESTION  */
#line 521 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.boolval) = true;
        // Log message when parsing a variable declaration node

        parserLog("Parsed variable declaration node");
        (yyval.boolval) = true;
    }
#line 1943 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 30: /* nullableModifier: BANG  */
#line 528 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.boolval) = false;
        // Log message when parsing a variable declaration node

        parserLog("Parsed variable declaration node");
    }
#line 1954 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 31: /* mutableModifier: %empty  */
#line 536 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.boolval) = false;

        parserLog("Parsed variable declaration node without explicit mutability");
    }
#line 1964 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 32: /* mutableModifier: IMT  */
#line 541 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.boolval) = false;

        parserLog("Parsed variable declaration node");
    }
#line 1974 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 33: /* mutableModifier: VAR  */
#line 546 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.boolval) = true;

        parserLog("Parsed variable declaration node");
    }
#line 1984 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 34: /* identifier: IDENTIFIER  */
#line 554 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.ident) = new dap::parser::QualifiedNameNode(*(yyvsp[0].str));
        delete (yyvsp[0].str);
        // Log message when parsing an identifier node
        (yyval.ident)->lineNum = yylineno;
        parserLog("Parsed identifier node");
    }
#line 1996 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 35: /* identifier: identifier DOT IDENTIFIER  */
#line 561 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                {
        (yyvsp[-2].ident)->name_parts->push_back(*(yyvsp[0].str));
        (yyval.ident) = (yyvsp[-2].ident);
        delete (yyvsp[0].str);
        // Log message when parsing a qualified identifier node
        (yyval.ident)->lineNum = yylineno;
        parserLog("Parsed qualified identifier node");
    }
#line 2009 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 36: /* integer: INTEGER  */
#line 571 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.intExpr) = new dap::parser::IntegerNode(atol((yyvsp[0].str)->c_str()));
        // Log message when parsing an IntegerNode node
        (yyval.intExpr)->lineNum = yylineno;
        parserLog("Parsed IntegerNode node: integer[" + (yyval.intExpr)->getVal() + "]");
    }
#line 2020 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 37: /* float_: FLOAT_LITERAL  */
#line 579 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        (yyval.floatExpr) = new dap::parser::FloatNode(atof((yyvsp[0].str)->c_str()));
        // Log message when parsing a float node
        (yyval.floatExpr)->lineNum = yylineno;
        parserLog("Parsed float node");
    }
#line 2031 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 38: /* string_: STRING_LITERAL  */
#line 587 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        (yyval.strExpr) = new dap::parser::StringNode(*(yyvsp[0].str));
        // Log message when parsing a string node
        (yyval.strExpr)->lineNum = yylineno;
        parserLog("Parsed string node");
    }
#line 2042 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 39: /* bool_: TRUE  */
#line 595 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
         {
        (yyval.expr) = new dap::parser::BoolNode(true);
        // Log message when parsing a boolean node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed boolean node: [ TRUE ]");
    }
#line 2053 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 40: /* bool_: FALSE  */
#line 601 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.expr) = new dap::parser::BoolNode(false);
        // Log message when parsing a boolean node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed boolean node: [ FALSE ]");
    }
#line 2064 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 41: /* type: identifier  */
#line 609 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.typeNode) = new dap::parser::TypeNode((yyvsp[0].ident));
        // Log message when parsing a type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed type node");
    }
#line 2075 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 42: /* type: type MUL  */
#line 615 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.typeNode) = (yyvsp[-1].typeNode);
        (yyval.typeNode)->isPointer = true;
        // Log message when parsing a pointer type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed pointer type node");
    }
#line 2087 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 43: /* type: type LEFT_BRACKET RIGHT_BRACKET  */
#line 622 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                      {
        (yyval.typeNode) = (yyvsp[-2].typeNode);
        (yyval.typeNode)->isArray = true;
        // Log message when parsing an array type node without size
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed array type node without size");
    }
#line 2099 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 44: /* type: type LEFT_BRACKET integer RIGHT_BRACKET  */
#line 629 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                              {
        (yyval.typeNode) = (yyvsp[-3].typeNode);
        (yyval.typeNode)->isArray = true;
        (yyval.typeNode)->arraySize = std::stoi((yyvsp[-1].intExpr)->getVal());
        // Log message when parsing an array type node with size
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed array type node with size");
    }
#line 2112 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 45: /* type: INT  */
#line 637 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::INT);
        // Log message when parsing an int type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed int type node");
    }
#line 2123 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 46: /* type: BYTE  */
#line 643 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::BYTE);
        // Log message when parsing a byte type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed byte type node");
    }
#line 2134 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 47: /* type: SHORT  */
#line 649 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::SHORT);
        // Log message when parsing a short type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed short type node");
    }
#line 2145 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 48: /* type: LONG  */
#line 655 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::LONG);
        // Log message when parsing a long type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed long type node");
    }
#line 2156 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 49: /* type: FLOAT  */
#line 661 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::FLOAT);
        // Log message when parsing a float type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed float type node");
    }
#line 2167 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 50: /* type: DOUBLE  */
#line 667 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::DOUBLE);
        // Log message when parsing a double type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed double type node");
    }
#line 2178 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 51: /* type: BOOL  */
#line 673 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::BOOL);
        // Log message when parsing a bool type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed bool type node");
    }
#line 2189 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 52: /* type: UINT  */
#line 679 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::UINT);
        // Log message when parsing a uint type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed uint type node");
    }
#line 2200 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 53: /* type: USHORT  */
#line 685 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::USHORT);
        // Log message when parsing a ushort type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed ushort type node");
    }
#line 2211 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 54: /* type: ULONG  */
#line 691 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::ULONG);
        // Log message when parsing a ulong type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed ulong type node");
    }
#line 2222 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 55: /* type: LLONG  */
#line 697 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::LLONG);
        // Log message when parsing a lllong type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed lllong type node");
    }
#line 2233 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 56: /* type: ULLONG  */
#line 703 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::ULLONG);
        // Log message when parsing a ullong type node
        (yyval.typeNode)->lineNum = yylineno;
        parserLog("Parsed ullong type node");
    }
#line 2244 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 57: /* packageDecl: %empty  */
#line 711 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {

    }
#line 2252 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 58: /* packageDecl: PACKAGE identifier SEMICOLON  */
#line 714 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                 {
        program->packageName = (yyvsp[-1].ident);
        // Log message when parsing a package declaration node
        parserLog("Parsed package declaration node: package [" + (yyvsp[-1].ident)->getName() + "]");
    }
#line 2262 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 59: /* importStmt: %empty  */
#line 721 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {

    }
#line 2270 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 60: /* importStmt: IMPORT identifier SEMICOLON  */
#line 724 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                  {
        auto info = new dap::parser::ProgramNode::importedPackageInfo((yyvsp[-1].ident), false);
        program->importedPackages->push_back(info);
        // Log message when parsing an import statement node
        parserLog("Parsed import statement node: import [" + (yyvsp[-1].ident)->getName() + "]");
    }
#line 2281 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 61: /* importStmt: IMPORT identifier DOT MUL SEMICOLON  */
#line 730 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                          {
        auto info = new dap::parser::ProgramNode::importedPackageInfo((yyvsp[-3].ident), true);
        program->importedPackages->push_back(info);
        // Log message when parsing an import wildcard statement node
        parserLog("Parsed import wildcard statement node: import [" + (yyvsp[-3].ident)->getName() + "] [all]");
    }
#line 2292 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 62: /* statement: functionDeclaration  */
#line 738 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
        // Log message when parsing a function declaration statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function declaration statement node: [" + (dynamic_cast<dap::parser::FunctionDeclarationNode*>((yyvsp[0].stmt)))->name + "]");
    }
#line 2303 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 63: /* statement: variableDecl SEMICOLON  */
#line 744 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[-1].stmt);
        // Log message when parsing a variable declaration statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed variable declaration statement node: [" + (dynamic_cast<dap::parser::VariableDeclarationNode*>((yyvsp[-1].stmt)))->variableName->getName() + "]");
    }
#line 2314 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 64: /* statement: constantDecl SEMICOLON  */
#line 750 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                             { 
        (yyval.stmt) = (yyvsp[-1].stmt);
        // Log message when parsing a constant declaration statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed constant declaration statement node: [" + (dynamic_cast<dap::parser::ConstantDeclarationNode*>((yyvsp[-1].stmt)))->name->getName() + "]");
    }
#line 2325 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 65: /* statement: structDecl  */
#line 756 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.stmt) = (yyvsp[0].stmt);
        // Log message when parsing a struct declaration statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed struct declaration statement node: [" + (dynamic_cast<dap::parser::StructDeclarationNode*>((yyvsp[0].stmt)))->name->getName() + "]");
    }
#line 2336 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 66: /* statement: returnStmt  */
#line 762 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.stmt) = (yyvsp[0].stmt);
        // Log message when parsing a return statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed return statement node");
    }
#line 2347 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 67: /* statement: expression SEMICOLON  */
#line 768 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                           {
        (yyval.stmt) = new dap::parser::Statement();
        (yyval.stmt)->value = (yyvsp[-1].expr);
        // Log message when parsing a function call statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed function call statement node");
    }
#line 2359 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 68: /* statements: %empty  */
#line 777 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.stmtVec) = new std::vector<dap::parser::Statement*>();
        // Log message when starting to parse a list of statements

        parserLog("Started parsing statements list");
    }
#line 2370 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 69: /* statements: statements statement  */
#line 783 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                           {
        (yyval.stmtVec)->push_back((yyvsp[0].stmt));
        // Log message when adding a statement to the statements list

        parserLog("Added statement to statements list");
    }
#line 2381 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 70: /* expressions: %empty  */
#line 791 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.exprVec) = new std::vector<dap::parser::Expression*>();
        // Log message when starting to parse a list of expressions

        parserLog("Started parsing expressions list");
    }
#line 2392 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 71: /* expressions: expression  */
#line 797 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.exprVec) = new std::vector<dap::parser::Expression*>();
        (yyval.exprVec)->push_back((yyvsp[0].expr));

        parserLog("Started parsing expressions list");
    }
#line 2403 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 72: /* expressions: expressions COMMA expression  */
#line 803 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                   {
        (yyval.exprVec)->push_back((yyvsp[0].expr));
        // Log message when adding an expression to the expressions list

        parserLog("Added expression to expressions list");
    }
#line 2414 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 73: /* structDecl: STRUCT identifier LEFT_BRACE structFields RIGHT_BRACE SEMICOLON  */
#line 811 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                    {
        (yyval.stmt) = new dap::parser::StructDeclarationNode((yyvsp[-4].ident), (yyvsp[-2].varDeclVec));
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed struct declaration node: [" + (yyvsp[-4].ident)->getName() + "]");
    }
#line 2424 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 74: /* structFields: %empty  */
#line 819 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.varDeclVec) = new std::vector<dap::parser::VariableDeclarationNode*>();
        // Log message when starting to parse a list of struct fields

        parserLog("Started parsing struct fields list");
    }
#line 2435 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 75: /* structFields: structFields variableDecl SEMICOLON  */
#line 825 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                          {
        (yyval.varDeclVec)->push_back(dynamic_cast<dap::parser::VariableDeclarationNode*>((yyvsp[-1].stmt)));
        // Log message when adding a struct field to the struct fields list

        parserLog("Added struct field to struct fields list");
    }
#line 2446 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 76: /* returnStmt: RETURN expression SEMICOLON  */
#line 833 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                {
        (yyval.stmt) = new dap::parser::ReturnStatementNode((yyvsp[-1].expr));
        // Log message when parsing a return statement node
        (yyval.stmt)->lineNum = yylineno;
        parserLog("Parsed return statement node");
    }
#line 2457 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 77: /* functionCall: identifier LEFT_PAREN expressions RIGHT_PAREN  */
#line 841 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                  {
        (yyval.expr) = new dap::parser::FunctionCallExpressionNode((yyvsp[-3].ident), (yyvsp[-1].exprVec));
        // Log message when parsing a function call statement node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed function call experssion node: [" + (yyvsp[-3].ident)->getName() + "]");
    }
#line 2468 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 78: /* binaryExpression: expression binaryOperator expression  */
#line 849 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                         {
        (yyval.expr) = new dap::parser::BinaryExpressionNode((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr));
        // Log message when parsing a binary expression node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed binary expression node: [" + tokenToString((yyvsp[-1].token)) + "]");
    }
#line 2479 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 79: /* binaryOperator: ASSIGN  */
#line 857 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.token) = ASSIGN;
    }
#line 2487 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 80: /* binaryOperator: PLUS  */
#line 860 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.token) = PLUS;
    }
#line 2495 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 81: /* binaryOperator: MINUS  */
#line 863 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.token) = MINUS;
    }
#line 2503 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 82: /* binaryOperator: MUL  */
#line 866 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = MUL;
    }
#line 2511 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 83: /* binaryOperator: DIV  */
#line 869 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = DIV;
    }
#line 2519 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 84: /* binaryOperator: MOD  */
#line 872 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = MOD;
    }
#line 2527 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 85: /* binaryOperator: EQUAL  */
#line 875 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.token) = EQUAL;
    }
#line 2535 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 86: /* binaryOperator: ADD_ASSIGN  */
#line 878 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.token) = ADD_ASSIGN;
    }
#line 2543 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 87: /* binaryOperator: MINUS_ASSIGN  */
#line 881 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        (yyval.token) = MINUS_ASSIGN;
    }
#line 2551 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 88: /* binaryOperator: MUL_ASSIGN  */
#line 884 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.token) = MUL_ASSIGN;
    }
#line 2559 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 89: /* binaryOperator: DIV_ASSIGN  */
#line 887 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.token) = DIV_ASSIGN;
    }
#line 2567 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 90: /* binaryOperator: MOD_ASSIGN  */
#line 890 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.token) = MOD_ASSIGN;
    }
#line 2575 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 91: /* binaryOperator: AND  */
#line 893 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = AND;
    }
#line 2583 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 92: /* binaryOperator: OR  */
#line 896 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
         {
        (yyval.token) = OR;
    }
#line 2591 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 93: /* binaryOperator: XOR  */
#line 899 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = XOR;
    }
#line 2599 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 94: /* binaryOperator: AND_ASSIGN  */
#line 902 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.token) = AND_ASSIGN;
    }
#line 2607 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 95: /* binaryOperator: OR_ASSIGN  */
#line 905 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.token) = OR_ASSIGN;
    }
#line 2615 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 96: /* unaryExpression: unaryOperator expression  */
#line 910 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                             {
        (yyval.expr) = new dap::parser::UnaryExpressionNode((yyvsp[-1].token), (yyvsp[0].expr));
        // Log message when parsing a unary expression node
        (yyval.expr)->lineNum = yylineno;
        parserLog("Parsed unary expression node: [" + tokenToString((yyvsp[-1].token)) + "]");
    }
#line 2626 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 97: /* unaryOperator: PLUS  */
#line 918 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
         {
        (yyval.token) = PLUS;
    }
#line 2634 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 98: /* unaryOperator: MINUS  */
#line 921 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.token) = MINUS;
    }
#line 2642 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 99: /* unaryOperator: BIT_AND  */
#line 924 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
              {
        (yyval.token) = BIT_AND;
    }
#line 2650 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 100: /* unaryOperator: BANG  */
#line 927 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.token) = BANG;
    }
#line 2658 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 101: /* unaryOperator: MUL  */
#line 930 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.token) = MUL;
    }
#line 2666 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;


#line 2670 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 933 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"


