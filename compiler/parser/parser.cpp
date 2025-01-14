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
    dap::util::log(msg, dap::parser::currentParsingFile, yylineno);
#endif
}

void parserLog(std::string msg) {
#ifdef D_DEBUG
    dap::util::log(msg, dap::parser::currentParsingFile, yylineno);
#endif
}

#line 108 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

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
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_BYTE = 19,                      /* BYTE  */
  YYSYMBOL_SHORT = 20,                     /* SHORT  */
  YYSYMBOL_LONG = 21,                      /* LONG  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 23,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 24,                      /* BOOL  */
  YYSYMBOL_UINT = 25,                      /* UINT  */
  YYSYMBOL_USHORT = 26,                    /* USHORT  */
  YYSYMBOL_ULONG = 27,                     /* ULONG  */
  YYSYMBOL_LLONG = 28,                     /* LLONG  */
  YYSYMBOL_ULLONG = 29,                    /* ULLONG  */
  YYSYMBOL_IDENTIFIER = 30,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 31,                   /* INTEGER  */
  YYSYMBOL_BINARY_LITERAL = 32,            /* BINARY_LITERAL  */
  YYSYMBOL_OCTAL_LITERAL = 33,             /* OCTAL_LITERAL  */
  YYSYMBOL_HEXADECIMAL_LITERAL = 34,       /* HEXADECIMAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 35,            /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 36,              /* CHAR_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 37,             /* FLOAT_LITERAL  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_MUL = 40,                       /* MUL  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_MOD = 42,                       /* MOD  */
  YYSYMBOL_BIT_AND = 43,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 44,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 45,                   /* BIT_XOR  */
  YYSYMBOL_BIT_NOT = 46,                   /* BIT_NOT  */
  YYSYMBOL_SHIFT_LEFT = 47,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 48,               /* SHIFT_RIGHT  */
  YYSYMBOL_LOGIC_SHIFT_LEFT = 49,          /* LOGIC_SHIFT_LEFT  */
  YYSYMBOL_ASSIGN = 50,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 51,                /* ADD_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 52,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 53,                /* DIV_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 54,              /* MINUS_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 55,                /* MOD_ASSIGN  */
  YYSYMBOL_BIT_AND_ASSIGN = 56,            /* BIT_AND_ASSIGN  */
  YYSYMBOL_BIT_OR_ASSIGN = 57,             /* BIT_OR_ASSIGN  */
  YYSYMBOL_BIT_XOR_ASSIGN = 58,            /* BIT_XOR_ASSIGN  */
  YYSYMBOL_SHIFT_LEFT_ASSIGN = 59,         /* SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_SHIFT_RIGHT_ASSIGN = 60,        /* SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_LOGIC_SHIFT_LEFT_ASSIGN = 61,   /* LOGIC_SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_INCREMENT = 62,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 63,                 /* DECREMENT  */
  YYSYMBOL_LESS_THAN = 64,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 65,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 66,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 67,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_EQUAL = 68,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 69,                 /* NOT_EQUAL  */
  YYSYMBOL_AND = 70,                       /* AND  */
  YYSYMBOL_OR = 71,                        /* OR  */
  YYSYMBOL_COMMA = 72,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 73,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 74,                     /* COLON  */
  YYSYMBOL_LEFT_BRACE = 75,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 76,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_PAREN = 77,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 78,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_BRACKET = 79,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 80,             /* RIGHT_BRACKET  */
  YYSYMBOL_DOT = 81,                       /* DOT  */
  YYSYMBOL_ELLIPSIS = 82,                  /* ELLIPSIS  */
  YYSYMBOL_QUESTION = 83,                  /* QUESTION  */
  YYSYMBOL_BANG = 84,                      /* BANG  */
  YYSYMBOL_LBRACK = 85,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 86,                    /* RBRACK  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_program = 88,                   /* program  */
  YYSYMBOL_variableDecl = 89,              /* variableDecl  */
  YYSYMBOL_expression = 90,                /* expression  */
  YYSYMBOL_funDecl = 91,                   /* funDecl  */
  YYSYMBOL_nullableModifier = 92,          /* nullableModifier  */
  YYSYMBOL_mutableModifier = 93,           /* mutableModifier  */
  YYSYMBOL_identifier = 94,                /* identifier  */
  YYSYMBOL_integer = 95,                   /* integer  */
  YYSYMBOL_type = 96,                      /* type  */
  YYSYMBOL_packageDecl = 97,               /* packageDecl  */
  YYSYMBOL_importStmt = 98,                /* importStmt  */
  YYSYMBOL_statement = 99,                 /* statement  */
  YYSYMBOL_statements = 100,               /* statements  */
  YYSYMBOL_expressions = 101               /* expressions  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


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
      85,    86
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    99,   104,   111,   116,   123,   135,   147,
     161,   177,   182,   188,   195,   199,   203,   210,   216,   225,
     245,   250,   256,   262,   269,   274,   279,   284,   289,   294,
     299,   304,   309,   314,   319,   324,   331,   334,   341,   344,
     350,   358,   362,   367,   374,   379,   386,   391
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
  "TYPEDEF", "IMT", "VAR", "INSTANCEOF", "RETURN", "INT", "BYTE", "SHORT",
  "LONG", "FLOAT", "DOUBLE", "BOOL", "UINT", "USHORT", "ULONG", "LLONG",
  "ULLONG", "IDENTIFIER", "INTEGER", "BINARY_LITERAL", "OCTAL_LITERAL",
  "HEXADECIMAL_LITERAL", "STRING_LITERAL", "CHAR_LITERAL", "FLOAT_LITERAL",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "BIT_AND", "BIT_OR", "BIT_XOR",
  "BIT_NOT", "SHIFT_LEFT", "SHIFT_RIGHT", "LOGIC_SHIFT_LEFT", "ASSIGN",
  "ADD_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MINUS_ASSIGN", "MOD_ASSIGN",
  "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "BIT_XOR_ASSIGN", "SHIFT_LEFT_ASSIGN",
  "SHIFT_RIGHT_ASSIGN", "LOGIC_SHIFT_LEFT_ASSIGN", "INCREMENT",
  "DECREMENT", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "AND", "OR", "COMMA",
  "SEMICOLON", "COLON", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAREN",
  "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "DOT", "ELLIPSIS",
  "QUESTION", "BANG", "LBRACK", "RBRACK", "$accept", "program",
  "variableDecl", "expression", "funDecl", "nullableModifier",
  "mutableModifier", "identifier", "integer", "type", "packageDecl",
  "importStmt", "statement", "statements", "expressions", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -22,    38,    19,   -48,    22,   -48,   -22,   -48,   -48,
      31,    24,    94,   -48,   -48,    27,   -22,   -48,   -48,   -48,
     -48,   -10,   -48,   120,    -7,   -48,   -48,     3,   -42,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -47,   -23,   -48,    18,   -48,   -48,    50,   -48,
     -30,    29,    23,     0,    -9,   -48,    15,    56,   -48,    -7,
     -21,    -9,    62,    34,   -48,    -9,    -5,   -48,   -48,   -48,
     -20,   -48,    41,   -48,    -3,    -1,   -48,   -48,   -48,   -48,
       1,   -48
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      36,     0,     0,    38,    17,     0,     1,     0,    44,    37,
       0,     0,    14,    18,    39,     0,     0,    15,    16,    19,
      43,     0,    42,     0,     6,     5,    45,     0,     0,    41,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    20,     0,    40,    46,    12,    13,     0,    21,
       0,    11,     0,     0,     0,    22,     0,     0,    44,    20,
       0,     0,     0,     0,    23,     0,    14,    44,    47,    44,
       0,     4,     0,     7,    14,    14,    44,     3,     8,     9,
      14,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,     5,   -48,    64,   -48,    17,    66,     6,
     -48,   -48,   -48,    35,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    20,    21,    22,    48,    23,    24,    25,    43,
       3,     8,    26,    12,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      16,    19,    16,   -11,    16,     1,    16,     4,     4,    17,
      18,    17,    18,    17,    18,    17,    18,    49,     5,    49,
      49,     4,    19,     7,    11,     4,    19,     4,    19,     4,
      19,     4,    19,    28,    10,    45,    46,    47,     6,    10,
      42,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     4,    67,    76,    55,    13,    60,    63,
      51,    13,    50,    29,    50,    50,    68,    27,    70,    59,
      72,    73,    61,    78,    10,    79,    44,    81,    62,    59,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     4,    66,    -2,     9,    52,    14,    58,    16,
      54,    64,    74,    10,    75,    15,    65,    71,    17,    18,
      10,    80,    46,    47,    77,    57,    56,     0,     0,     0,
       0,     0,     0,     0,     4,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       4
};

static const yytype_int8 yycheck[] =
{
       5,    31,     5,    50,     5,     3,     5,    30,    30,    14,
      15,    14,    15,    14,    15,    14,    15,    40,     1,    40,
      40,    30,    31,     4,     7,    30,    31,    30,    31,    30,
      31,    30,    31,    16,    81,    77,    83,    84,     0,    81,
      23,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    75,    75,    86,    30,    52,    54,
      43,    30,    85,    73,    85,    85,    61,    40,    62,    52,
      65,    76,    72,    76,    81,    76,    73,    76,    78,    62,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    58,     0,    73,    78,    73,    75,     5,
      50,    86,    67,    81,    69,    81,    50,    73,    14,    15,
      81,    76,    83,    84,    73,    51,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    88,    97,    30,    94,     0,     4,    98,    73,
      81,    94,   100,    30,    73,    81,     5,    14,    15,    31,
      89,    90,    91,    93,    94,    95,    99,    40,    94,    73,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    94,    96,    73,    77,    83,    84,    92,    40,
      85,    94,    78,   101,    50,    86,    95,    92,    75,    94,
      96,    72,    78,    90,    86,    50,   100,    75,    90,    75,
      96,    73,    90,    76,   100,   100,    75,    73,    76,    76,
     100,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     7,     6,     1,     1,     7,     8,     8,
       9,     0,     1,     1,     0,     1,     1,     1,     3,     1,
       1,     2,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     3,
       5,     2,     1,     1,     0,     2,     0,     3
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
#line 91 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                      {
        // Create a new program node
        program = new dap::parser::ProgramNode();
        // Log message when parsing a program node
        parserLog("Parsed program node");
    }
#line 1281 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 3: /* variableDecl: mutableModifier type identifier nullableModifier ASSIGN expression SEMICOLON  */
#line 99 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                 {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode((yyvsp[-5].typeNode), (yyvsp[-1].expr), (yyvsp[-4].ident), (yyvsp[-3].boolval), (yyvsp[-6].boolval));
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
    }
#line 1291 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 4: /* variableDecl: mutableModifier identifier nullableModifier ASSIGN expression SEMICOLON  */
#line 104 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                              {
        (yyval.stmt) = new dap::parser::VariableDeclarationNode(nullptr, (yyvsp[-1].expr), (yyvsp[-4].ident), (yyvsp[-3].boolval), (yyvsp[-5].boolval));
        // Log message when parsing a variable declaration node without explicit type
        parserLog("Parsed variable declaration node without explicit type");
    }
#line 1301 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 5: /* expression: integer  */
#line 111 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.expr) = (yyvsp[0].intExpr);
        // Log message when parsing an integer expression node
        parserLog("Parsed integer expression node");
    }
#line 1311 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 6: /* expression: identifier  */
#line 116 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        (yyval.expr) = (yyvsp[0].ident);

        parserLog("Parsed identifier expression node: [" + (yyvsp[0].ident)->getName() + "]");
    }
#line 1321 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 7: /* funDecl: FUN identifier LEFT_PAREN RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE  */
#line 123 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
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
        parserLog("Parsed function declaration node without parameters");
    }
#line 1338 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 8: /* funDecl: FUN identifier LEFT_PAREN RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE  */
#line 135 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
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
        parserLog("Parsed function declaration node without parameters");
    }
#line 1355 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 9: /* funDecl: FUN identifier LEFT_PAREN expressions RIGHT_PAREN LEFT_BRACE statements RIGHT_BRACE  */
#line 147 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                          {
        if ((yyvsp[-6].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-6].ident)->name_parts->at(0),
                                                        (yyvsp[-4].exprVec),
                                                        nullptr,
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node with parameters
        parserLog("Parsed function declaration node with parameters");

    }
#line 1374 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 10: /* funDecl: FUN identifier LEFT_PAREN expressions RIGHT_PAREN type LEFT_BRACE statements RIGHT_BRACE  */
#line 161 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                               {
        if ((yyvsp[-7].ident)->name_parts->size()!= 1) {
            // Call the error function if the identifier is invalid
            yyerror("Invalid identifier");
        }

        (yyval.stmt) = new dap::parser::FunctionDeclarationNode((yyvsp[-7].ident)->name_parts->at(0),
                                                        (yyvsp[-5].exprVec),
                                                        (yyvsp[-3].typeNode),
                                                        (yyvsp[-1].stmtVec));
        // Log message when parsing a function declaration node with parameters and return type
        parserLog("Parsed function declaration node with parameters and return type");
    }
#line 1392 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 11: /* nullableModifier: %empty  */
#line 177 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.boolval) = false;
        // Log message when parsing a variable declaration node without explicit type
        parserLog("Parsed variable declaration node without explicit nullablity");
    }
#line 1402 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 12: /* nullableModifier: QUESTION  */
#line 182 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.boolval) = true;
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
        (yyval.boolval) = true;
    }
#line 1413 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 13: /* nullableModifier: BANG  */
#line 188 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.boolval) = false;
        // Log message when parsing a variable declaration node
        parserLog("Parsed variable declaration node");
    }
#line 1423 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 14: /* mutableModifier: %empty  */
#line 195 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.boolval) = false;
        parserLog("Parsed variable declaration node without explicit mutability");
    }
#line 1432 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 15: /* mutableModifier: IMT  */
#line 199 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.boolval) = false;
        parserLog("Parsed variable declaration node");
    }
#line 1441 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 16: /* mutableModifier: VAR  */
#line 203 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.boolval) = true;
        parserLog("Parsed variable declaration node");
    }
#line 1450 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 17: /* identifier: IDENTIFIER  */
#line 210 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.ident) = new dap::parser::QualifiedName(*(yyvsp[0].str));
        delete (yyvsp[0].str);
        // Log message when parsing an identifier node
        parserLog("Parsed identifier node");
    }
#line 1461 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 18: /* identifier: identifier DOT IDENTIFIER  */
#line 216 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                {
        (yyvsp[-2].ident)->name_parts->push_back(*(yyvsp[0].str));
        (yyval.ident) = (yyvsp[-2].ident);
        delete (yyvsp[0].str);
        // Log message when parsing a qualified identifier node
        parserLog("Parsed qualified identifier node");
    }
#line 1473 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 19: /* integer: INTEGER  */
#line 225 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.intExpr) = new dap::parser::Integer(atol((yyvsp[0].str)->c_str()));
        // Log message when parsing an integer node
        parserLog("Parsed integer node");
    }
#line 1483 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 20: /* type: identifier  */
#line 245 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.typeNode) = new dap::parser::TypeNode((yyvsp[0].ident));
        // Log message when parsing a type node
        parserLog("Parsed type node");
    }
#line 1493 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 21: /* type: type MUL  */
#line 250 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        (yyval.typeNode) = (yyvsp[-1].typeNode);
        (yyval.typeNode)->isPointer = true;
        // Log message when parsing a pointer type node
        parserLog("Parsed pointer type node");
    }
#line 1504 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 22: /* type: type LBRACK RBRACK  */
#line 256 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                         {
        (yyval.typeNode) = (yyvsp[-2].typeNode);
        (yyval.typeNode)->isArray = true;
        // Log message when parsing an array type node without size
        parserLog("Parsed array type node without size");
    }
#line 1515 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 23: /* type: type LBRACK integer RBRACK  */
#line 262 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                 {
        (yyval.typeNode) = (yyvsp[-3].typeNode);
        (yyval.typeNode)->isArray = true;
        (yyval.typeNode)->arraySize = std::stoi((yyvsp[-1].intExpr)->getVal());
        // Log message when parsing an array type node with size
        parserLog("Parsed array type node with size");
    }
#line 1527 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 24: /* type: INT  */
#line 269 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::INT);
        // Log message when parsing an int type node
        parserLog("Parsed int type node");
    }
#line 1537 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 25: /* type: BYTE  */
#line 274 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::BYTE);
        // Log message when parsing a byte type node
        parserLog("Parsed byte type node");
    }
#line 1547 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 26: /* type: SHORT  */
#line 279 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::SHORT);
        // Log message when parsing a short type node
        parserLog("Parsed short type node");
    }
#line 1557 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 27: /* type: LONG  */
#line 284 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::LONG);
        // Log message when parsing a long type node
        parserLog("Parsed long type node");
    }
#line 1567 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 28: /* type: FLOAT  */
#line 289 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::FLOAT);
        // Log message when parsing a float type node
        parserLog("Parsed float type node");
    }
#line 1577 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 29: /* type: DOUBLE  */
#line 294 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::DOUBLE);
        // Log message when parsing a double type node
        parserLog("Parsed double type node");
    }
#line 1587 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 30: /* type: BOOL  */
#line 299 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::BOOL);
        // Log message when parsing a bool type node
        parserLog("Parsed bool type node");
    }
#line 1597 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 31: /* type: UINT  */
#line 304 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::UINT);
        // Log message when parsing a uint type node
        parserLog("Parsed uint type node");
    }
#line 1607 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 32: /* type: USHORT  */
#line 309 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::USHORT);
        // Log message when parsing a ushort type node
        parserLog("Parsed ushort type node");
    }
#line 1617 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 33: /* type: ULONG  */
#line 314 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::ULONG);
        // Log message when parsing a ulong type node
        parserLog("Parsed ulong type node");
    }
#line 1627 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 34: /* type: LLONG  */
#line 319 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::LLONG);
        // Log message when parsing a lllong type node
        parserLog("Parsed lllong type node");
    }
#line 1637 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 35: /* type: ULLONG  */
#line 324 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        (yyval.typeNode) = new dap::parser::TypeNode(BasicType::ULLONG);
        // Log message when parsing a ullong type node
        parserLog("Parsed ullong type node");
    }
#line 1647 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 36: /* packageDecl: %empty  */
#line 331 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {

    }
#line 1655 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 37: /* packageDecl: PACKAGE identifier SEMICOLON  */
#line 334 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                 {
        program->packageName = (yyvsp[-1].ident);
        // Log message when parsing a package declaration node
        parserLog("Parsed package declaration node: package [" + (yyvsp[-1].ident)->getName() + "]");
    }
#line 1665 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 38: /* importStmt: %empty  */
#line 341 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {

    }
#line 1673 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 39: /* importStmt: IMPORT identifier SEMICOLON  */
#line 344 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                  {
        auto info = new dap::parser::ProgramNode::importedPackageInfo((yyvsp[-1].ident), false);
        program->importedPackages.push_back(info);
        // Log message when parsing an import statement node
        parserLog("Parsed import statement node: import [" + (yyvsp[-1].ident)->getName() + "]");
    }
#line 1684 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 40: /* importStmt: IMPORT identifier DOT MUL SEMICOLON  */
#line 350 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                          {
        auto info = new dap::parser::ProgramNode::importedPackageInfo((yyvsp[-3].ident), true);
        program->importedPackages.push_back(info);
        // Log message when parsing an import wildcard statement node
        parserLog("Parsed import wildcard statement node: import [" + (yyvsp[-3].ident)->getName() + "] [all]");
    }
#line 1695 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 41: /* statement: expression SEMICOLON  */
#line 358 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                         {
        // Log message when parsing an expression statement node
        parserLog("Parsed expression statement node");
    }
#line 1704 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 42: /* statement: funDecl  */
#line 362 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
              {
        (yyval.stmt) = (yyvsp[0].stmt);
        // Log message when parsing a function declaration statement node
        parserLog("Parsed function declaration statement node: [" + (dynamic_cast<dap::parser::FunctionDeclarationNode*>((yyvsp[0].stmt)))->name + "]");
    }
#line 1714 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 43: /* statement: variableDecl  */
#line 367 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
        // Log message when parsing a variable declaration statement node
        parserLog("Parsed variable declaration statement node: [" + (dynamic_cast<dap::parser::VariableDeclarationNode*>((yyvsp[0].stmt)))->variableName->getName() + "]");
    }
#line 1724 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 44: /* statements: %empty  */
#line 374 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.stmtVec) = new std::vector<dap::parser::Statement*>();
        // Log message when starting to parse a list of statements
        parserLog("Started parsing statements list");
    }
#line 1734 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 45: /* statements: statements statement  */
#line 379 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                           {
        (yyval.stmtVec)->push_back((yyvsp[0].stmt));
        // Log message when adding a statement to the statements list
        parserLog("Added statement to statements list");
    }
#line 1744 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 46: /* expressions: %empty  */
#line 386 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        (yyval.exprVec) = new std::vector<dap::parser::Expression*>();
        // Log message when starting to parse a list of expressions
        parserLog("Started parsing expressions list");
    }
#line 1754 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 47: /* expressions: expressions COMMA expression  */
#line 391 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                   {
        (yyval.exprVec)->push_back((yyvsp[0].expr));
        // Log message when adding an expression to the expressions list
        parserLog("Added expression to expressions list");
    }
#line 1764 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;


#line 1768 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

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

#line 396 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
