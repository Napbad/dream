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
#line 1 "./src/core/parser/parser.y"

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


#line 112 "./src/core/parser/parser.cpp"

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
  YYSYMBOL_STRING_LITERAL = 3,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_INT_TOKEN = 5,                  /* INT_TOKEN  */
  YYSYMBOL_DOUBLE_TOKEN = 6,               /* DOUBLE_TOKEN  */
  YYSYMBOL_STRUCT = 7,                     /* STRUCT  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_DOT = 9,                        /* DOT  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_TIMES = 12,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 13,                    /* DIVIDE  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 22,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 23,                  /* RBRACKET  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_XOR = 33,                       /* XOR  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 35,                     /* UPLUS  */
  YYSYMBOL_PLUS_ASSIGN = 36,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 37,              /* MINUS_ASSIGN  */
  YYSYMBOL_TIMES_ASSIGN = 38,              /* TIMES_ASSIGN  */
  YYSYMBOL_DIVIDE_ASSIGN = 39,             /* DIVIDE_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 40,                /* MOD_ASSIGN  */
  YYSYMBOL_INC = 41,                       /* INC  */
  YYSYMBOL_DEC = 42,                       /* DEC  */
  YYSYMBOL_BIT_AND = 43,                   /* BIT_AND  */
  YYSYMBOL_IF = 44,                        /* IF  */
  YYSYMBOL_ELSE = 45,                      /* ELSE  */
  YYSYMBOL_ELIF = 46,                      /* ELIF  */
  YYSYMBOL_FOR = 47,                       /* FOR  */
  YYSYMBOL_RETURN = 48,                    /* RETURN  */
  YYSYMBOL_FUN = 49,                       /* FUN  */
  YYSYMBOL_EXTERN = 50,                    /* EXTERN  */
  YYSYMBOL_INCLUDE = 51,                   /* INCLUDE  */
  YYSYMBOL_PACKAGE = 52,                   /* PACKAGE  */
  YYSYMBOL_VAR = 53,                       /* VAR  */
  YYSYMBOL_IMT = 54,                       /* IMT  */
  YYSYMBOL_NULLABLE = 55,                  /* NULLABLE  */
  YYSYMBOL_NON_NULLABLE = 56,              /* NON_NULLABLE  */
  YYSYMBOL_LSHIFT = 57,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 58,                    /* RSHIFT  */
  YYSYMBOL_URSHIFT = 59,                   /* URSHIFT  */
  YYSYMBOL_TRUE = 60,                      /* TRUE  */
  YYSYMBOL_FALSE = 61,                     /* FALSE  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_stmt_list = 64,                 /* stmt_list  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_include_stmt = 66,              /* include_stmt  */
  YYSYMBOL_package_stmt = 67,              /* package_stmt  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_var_decl = 69,                  /* var_decl  */
  YYSYMBOL_var_mutable_flag = 70,          /* var_mutable_flag  */
  YYSYMBOL_assign_nullable_flag = 71,      /* assign_nullable_flag  */
  YYSYMBOL_extern_decl = 72,               /* extern_decl  */
  YYSYMBOL_function_declaration = 73,      /* function_declaration  */
  YYSYMBOL_var_decl_list = 74,             /* var_decl_list  */
  YYSYMBOL_qualified_name = 75,            /* qualified_name  */
  YYSYMBOL_type_ident = 76,                /* type_ident  */
  YYSYMBOL_binary_expression = 77,         /* binary_expression  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_bool_expression = 79,           /* bool_expression  */
  YYSYMBOL_unary_expression = 80,          /* unary_expression  */
  YYSYMBOL_binary_operator = 81,           /* binary_operator  */
  YYSYMBOL_unary_operator = 82,            /* unary_operator  */
  YYSYMBOL_expr_list = 83,                 /* expr_list  */
  YYSYMBOL_if_statement = 84,              /* if_statement  */
  YYSYMBOL_elif_stmts = 85,                /* elif_stmts  */
  YYSYMBOL_elif_statement = 86,            /* elif_statement  */
  YYSYMBOL_for_statement = 87,             /* for_statement  */
  YYSYMBOL_break_statement = 88,           /* break_statement  */
  YYSYMBOL_for_var_decl = 89,              /* for_var_decl  */
  YYSYMBOL_struct_decl = 90,               /* struct_decl  */
  YYSYMBOL_struct_field_list = 91,         /* struct_field_list  */
  YYSYMBOL_assign_expr = 92,               /* assign_expr  */
  YYSYMBOL_array_assign_stmt = 93          /* array_assign_stmt  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   721

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   117,   121,   129,   135,   141,   147,   153,
     159,   165,   171,   177,   183,   189,   195,   201,   207,   213,
     219,   228,   237,   246,   255,   262,   269,   278,   287,   300,
     301,   302,   306,   307,   308,   312,   322,   330,   340,   344,
     348,   357,   364,   375,   382,   392,   402,   408,   414,   422,
     428,   434,   440,   446,   452,   458,   464,   473,   478,   485,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   519,   520,   521,   522,   523,   524,   525,   529,
     533,   537,   545,   551,   557,   572,   578,   586,   596,   604,
     612,   617,   625,   629,   636,   646,   650,   658,   666
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING_LITERAL",
  "IDENTIFIER", "INT_TOKEN", "DOUBLE_TOKEN", "STRUCT", "BREAK", "DOT",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "MOD", "ASSIGN", "SEMICOLON",
  "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "LT", "LE", "GT", "GE", "EQ", "NE", "AND", "OR", "NOT", "XOR", "UMINUS",
  "UPLUS", "PLUS_ASSIGN", "MINUS_ASSIGN", "TIMES_ASSIGN", "DIVIDE_ASSIGN",
  "MOD_ASSIGN", "INC", "DEC", "BIT_AND", "IF", "ELSE", "ELIF", "FOR",
  "RETURN", "FUN", "EXTERN", "INCLUDE", "PACKAGE", "VAR", "IMT",
  "NULLABLE", "NON_NULLABLE", "LSHIFT", "RSHIFT", "URSHIFT", "TRUE",
  "FALSE", "$accept", "program", "stmt_list", "stmt", "include_stmt",
  "package_stmt", "block", "var_decl", "var_mutable_flag",
  "assign_nullable_flag", "extern_decl", "function_declaration",
  "var_decl_list", "qualified_name", "type_ident", "binary_expression",
  "expression", "bool_expression", "unary_expression", "binary_operator",
  "unary_operator", "expr_list", "if_statement", "elif_stmts",
  "elif_statement", "for_statement", "break_statement", "for_var_decl",
  "struct_decl", "struct_field_list", "assign_expr", "array_assign_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -141,    21,   211,  -141,  -141,  -141,  -141,  -141,    52,   297,
    -141,  -141,  -141,   297,  -141,   297,  -141,  -141,  -141,  -141,
     297,   297,    73,    28,    73,    34,    73,    73,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,    74,    73,  -141,  -141,
      40,  -141,   335,  -141,  -141,   297,  -141,  -141,  -141,    82,
    -141,    90,  -141,    87,    54,   662,   371,   152,   662,    56,
     407,   407,    99,     6,    93,  -141,   443,     7,    73,    65,
      66,  -141,     1,   106,   297,   297,   297,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
     297,   662,  -141,  -141,  -141,   297,  -141,  -141,   297,  -141,
      47,  -141,    98,  -141,   297,  -141,    -1,    33,  -141,  -141,
      39,   263,  -141,   662,    42,   480,   662,    -6,   517,   662,
      95,  -141,    55,   297,   553,  -141,    67,    -1,  -141,  -141,
     101,   113,   590,  -141,   104,   105,   107,  -141,  -141,    95,
    -141,   662,   297,    50,    15,    68,   297,    39,   116,   297,
    -141,  -141,  -141,   407,  -141,  -141,     8,    73,   662,   110,
      39,   626,  -141,  -141,    29,   297,   111,  -141,  -141,   662,
     297,   662
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    48,    41,    46,    47,     0,   100,
      83,    82,    87,     0,     3,    89,    84,    85,    86,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      57,    58,     4,    19,    20,    17,     0,     0,    15,    12,
      50,    53,     0,    49,    54,     0,     9,    10,    11,     0,
      18,     0,    14,     0,    50,   101,     0,     0,    90,     0,
       0,     0,    43,     0,     0,     8,     0,     0,     0,     0,
       0,     6,     0,     0,     0,    89,     0,    60,    61,    62,
      63,    64,     5,    65,    66,    67,    68,    69,    70,    71,
      72,    81,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    59,    16,    13,   105,     0,    51,    23,     0,    55,
      92,    98,   103,    44,     0,     7,    38,     0,    21,    22,
      34,     0,    42,   107,     0,     0,    45,    31,     0,    91,
       0,    94,    95,     0,     0,    39,     0,    38,    32,    33,
      25,     0,     0,    52,    56,     0,     0,    56,    93,     0,
      97,   102,     0,    31,     0,     0,     0,    34,     0,     0,
     104,   106,    96,     0,    40,    36,     0,     0,    24,    26,
      34,     0,    99,    37,     0,     0,     0,   108,    35,    27,
       0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   108,  -141,  -141,  -141,   -52,   -73,  -141,  -140,
    -141,  -141,   -10,     0,   -36,  -141,    -9,  -141,  -141,  -141,
    -141,    53,  -141,    -3,  -103,  -141,  -141,  -141,  -141,  -141,
    -141,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    32,    33,    34,    35,    36,    37,   140,
      38,    39,   136,    54,    63,    41,    42,    43,    44,   100,
      45,    59,    46,   131,    47,    48,    49,    64,    50,   127,
      51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    72,    40,   -31,    56,   120,    58,   132,   110,   111,
     112,    60,    61,   113,    66,   145,    73,   169,   113,     5,
     113,     3,    62,   121,    67,   116,    69,    70,    14,   132,
     176,     4,     5,     6,     7,    14,   101,    62,    10,    11,
      12,   113,    73,   135,    65,   178,    13,    28,    29,    73,
      15,   137,    28,    29,   146,    74,    53,    40,    75,   108,
      16,   143,    76,    73,   135,   123,    58,   125,   117,    17,
      18,    19,    75,   108,    73,    73,   105,     5,   148,   109,
     164,   118,   119,    68,   153,   153,   154,   167,    30,    31,
      71,   126,   130,    21,   138,   139,   128,   162,   102,   129,
     149,    21,   165,    28,    29,   134,   103,   104,    73,   114,
     122,   172,   142,   133,   173,    14,   156,   157,   166,   159,
     170,   160,    57,   161,   151,   175,   180,   155,   124,   150,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   168,     0,     0,
     171,     0,     0,     0,    62,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,   179,    62,     0,     0,
      13,   181,    14,   107,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,    31,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,    13,
       0,    14,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     4,     5,     6,     7,
       0,    30,    31,    10,    11,    12,     0,     0,     0,     0,
       0,    13,     0,     0,     0,    15,   141,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       4,     5,     6,     7,    17,    18,    19,    10,    11,    12,
       0,     0,     0,     0,     0,    13,     0,     0,     0,    15,
       0,     0,     0,    30,    31,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,    77,    78,    79,    80,    81,
       0,    82,     0,     0,     0,     0,     0,    30,    31,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,     0,     0,     0,     0,
     106,     0,    97,    98,    99,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,     0,     0,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,    14,    97,    98,
      99,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,   115,
       0,     0,     0,     0,    97,    98,    99,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
      97,    98,    99,   144,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,    97,    98,    99,
     147,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,     0,   152,
       0,     0,     0,     0,    97,    98,    99,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
      97,    98,    99,   158,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,   177,     0,     0,     0,     0,    97,    98,    99,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,     0,    97,    98,    99,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99
};

static const yytype_int16 yycheck[] =
{
       9,    37,     2,     4,    13,     4,    15,   110,    60,    61,
       4,    20,    21,    12,    23,    21,     9,   157,    12,     4,
      12,     0,    22,    22,    24,    18,    26,    27,    20,   132,
     170,     3,     4,     5,     6,    20,    45,    37,    10,    11,
      12,    12,     9,   116,    16,    16,    18,    53,    54,     9,
      22,    18,    53,    54,   127,    15,     4,    57,    18,    17,
      32,    19,    22,     9,   137,    74,    75,    76,    68,    41,
      42,    43,    18,    17,     9,     9,    22,     4,   130,    23,
     153,    16,    16,    49,    17,    17,    19,    19,    60,    61,
      16,   100,    45,    46,    55,    56,   105,   149,    16,   108,
      45,    46,   154,    53,    54,   114,    16,    20,     9,    16,
       4,   163,   121,    15,   166,    20,    15,     4,   154,    15,
       4,    16,    14,    16,   133,    15,    15,   137,    75,   132,
      -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,    -1,   154,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    -1,   175,   167,    -1,    -1,
      18,   180,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    60,    61,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     3,     4,     5,     6,
      -1,    60,    61,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    41,    42,    43,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    60,    61,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      19,    -1,    57,    58,    59,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    57,    58,
      59,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    57,    58,    59,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    57,    58,    59,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    57,    58,    59,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    64,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    18,    20,    22,    32,    41,    42,    43,
      44,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      60,    61,    65,    66,    67,    68,    69,    70,    72,    73,
      75,    77,    78,    79,    80,    82,    84,    86,    87,    88,
      90,    92,    93,     4,    75,    78,    78,    64,    78,    83,
      78,    78,    75,    76,    89,    16,    78,    75,    49,    75,
      75,    16,    76,     9,    15,    18,    22,    10,    11,    12,
      13,    14,    16,    24,    25,    26,    27,    28,    29,    30,
      31,    33,    36,    37,    38,    39,    40,    57,    58,    59,
      81,    78,    16,    16,    20,    22,    19,    21,    17,    23,
      68,    68,     4,    12,    16,    16,    18,    75,    16,    16,
       4,    22,     4,    78,    83,    78,    78,    91,    78,    78,
      45,    85,    86,    15,    78,    69,    74,    18,    55,    56,
      71,    23,    78,    19,    23,    21,    69,    23,    68,    45,
      85,    78,    16,    17,    19,    74,    15,     4,    23,    15,
      16,    16,    68,    78,    69,    68,    76,    19,    78,    71,
       4,    78,    68,    68,    76,    15,    71,    16,    16,    78,
      15,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    68,    69,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    72,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    84,    84,    84,    85,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     3,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     3,     3,     3,     6,     4,     6,     8,     9,     1,
       1,     0,     1,     1,     0,     8,     6,     7,     0,     1,
       3,     1,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     4,     1,     1,     3,     4,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     3,     5,     4,     1,     3,     2,     3,     7,
       1,     2,     4,     2,     6,     0,     3,     3,     7
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
  case 2: /* program: stmt_list  */
#line 108 "./src/core/parser/parser.y"
              {
        program = new Program(new BlockStmt(*(yyvsp[0].stmtvec)));
        (yyval.node)->line = yylineno;

        printParseInfo("program", yylineno);
    }
#line 1438 "./src/core/parser/parser.cpp"
    break;

  case 3: /* stmt_list: %empty  */
#line 117 "./src/core/parser/parser.y"
                {
        (yyval.stmtvec) = new std::vector<Stmt*>();
        printParseInfo("stmt_list (empty)", yylineno);
    }
#line 1447 "./src/core/parser/parser.cpp"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 121 "./src/core/parser/parser.y"
                     {
        (yyvsp[-1].stmtvec)->push_back((yyvsp[0].stmt));
        (yyval.stmtvec) = (yyvsp[-1].stmtvec);
        printParseInfo("stmt_list", yylineno);
    }
#line 1457 "./src/core/parser/parser.cpp"
    break;

  case 5: /* stmt: expression SEMICOLON  */
#line 129 "./src/core/parser/parser.y"
                         {
        (yyval.stmt) = new ExprStmt((yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (expression SEMICOLON)", yylineno);
    }
#line 1468 "./src/core/parser/parser.cpp"
    break;

  case 6: /* stmt: var_decl SEMICOLON  */
#line 135 "./src/core/parser/parser.y"
                         {
        (yyval.stmt) = (yyvsp[-1].var_decl);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (var_decl SEMICOLON)", yylineno);
    }
#line 1479 "./src/core/parser/parser.cpp"
    break;

  case 7: /* stmt: RETURN expression SEMICOLON  */
#line 141 "./src/core/parser/parser.y"
                                  {
        (yyval.stmt) = new ReturnStmt((yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (RETURN expression SEMICOLON)", yylineno);
    }
#line 1490 "./src/core/parser/parser.cpp"
    break;

  case 8: /* stmt: RETURN SEMICOLON  */
#line 147 "./src/core/parser/parser.y"
                       {
        (yyval.stmt) = new ReturnStmt(nullptr);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (RETURN void SEMICOLON)", yylineno);
    }
#line 1501 "./src/core/parser/parser.cpp"
    break;

  case 9: /* stmt: if_statement  */
#line 153 "./src/core/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (if_statement)", yylineno);
    }
#line 1512 "./src/core/parser/parser.cpp"
    break;

  case 10: /* stmt: elif_statement  */
#line 159 "./src/core/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (elif_statement)", yylineno);
    }
#line 1523 "./src/core/parser/parser.cpp"
    break;

  case 11: /* stmt: for_statement  */
#line 165 "./src/core/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (for_statement)", yylineno);
    }
#line 1534 "./src/core/parser/parser.cpp"
    break;

  case 12: /* stmt: function_declaration  */
#line 171 "./src/core/parser/parser.y"
                           {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (function_declaration)", yylineno);
    }
#line 1545 "./src/core/parser/parser.cpp"
    break;

  case 13: /* stmt: assign_expr SEMICOLON  */
#line 177 "./src/core/parser/parser.y"
                            {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (assignment)", yylineno);
    }
#line 1556 "./src/core/parser/parser.cpp"
    break;

  case 14: /* stmt: array_assign_stmt  */
#line 183 "./src/core/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (array_assign_stmt)", yylineno);
    }
#line 1567 "./src/core/parser/parser.cpp"
    break;

  case 15: /* stmt: extern_decl  */
#line 189 "./src/core/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (extern_decl)", yylineno);
    }
#line 1578 "./src/core/parser/parser.cpp"
    break;

  case 16: /* stmt: break_statement SEMICOLON  */
#line 195 "./src/core/parser/parser.y"
                                {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (break_statement)", yylineno);
    }
#line 1589 "./src/core/parser/parser.cpp"
    break;

  case 17: /* stmt: block  */
#line 201 "./src/core/parser/parser.y"
            {
        (yyval.stmt) = (yyvsp[0].block);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (block)", yylineno);
    }
#line 1600 "./src/core/parser/parser.cpp"
    break;

  case 18: /* stmt: struct_decl  */
#line 207 "./src/core/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (struct_decl)", yylineno);
    }
#line 1611 "./src/core/parser/parser.cpp"
    break;

  case 19: /* stmt: include_stmt  */
#line 213 "./src/core/parser/parser.y"
                   {
    	(yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

    	printParseInfo("stmmt (include_stmt)", yylineno);
    }
#line 1622 "./src/core/parser/parser.cpp"
    break;

  case 20: /* stmt: package_stmt  */
#line 219 "./src/core/parser/parser.y"
                   {
    	(yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

    	printParseInfo("stmt (package_stmt)", yylineno);
    }
#line 1633 "./src/core/parser/parser.cpp"
    break;

  case 21: /* include_stmt: INCLUDE qualified_name SEMICOLON  */
#line 228 "./src/core/parser/parser.y"
                                     {
	(yyval.stmt) = new IncludeStmt((yyvsp[-1].ident));
        (yyval.stmt)->line = yylineno;

	printParseInfo("include_stmt", yylineno);
    }
#line 1644 "./src/core/parser/parser.cpp"
    break;

  case 22: /* package_stmt: PACKAGE qualified_name SEMICOLON  */
#line 237 "./src/core/parser/parser.y"
                                     {
	(yyval.stmt) = new PackageStmt((yyvsp[-1].ident));
        (yyval.stmt)->line = yylineno;

	printParseInfo("package_stmt", yylineno);
    }
#line 1655 "./src/core/parser/parser.cpp"
    break;

  case 23: /* block: LBRACE stmt_list RBRACE  */
#line 246 "./src/core/parser/parser.y"
                            {
        (yyval.block) = new BlockStmt(*(yyvsp[-1].stmtvec));
        (yyval.block)->line = yylineno;

        printParseInfo("block", yylineno);
    }
#line 1666 "./src/core/parser/parser.cpp"
    break;

  case 24: /* var_decl: var_mutable_flag type_ident IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 255 "./src/core/parser/parser.y"
                                                                                  {
        (yyval.var_decl) = new VarDecl((yyvsp[-4].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)})), (yyvsp[-5].boolval), (yyvsp[-2].boolval), (yyvsp[0].expr));
        delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag type_ident IDENTIFIER assign_nullable_flag ASSIGN expression)", yylineno, (yyval.var_decl)->getName());
    }
#line 1678 "./src/core/parser/parser.cpp"
    break;

  case 25: /* var_decl: var_mutable_flag type_ident IDENTIFIER assign_nullable_flag  */
#line 262 "./src/core/parser/parser.y"
                                                                  {
        (yyval.var_decl) = new VarDecl((yyvsp[-2].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-1].string)})), (yyvsp[-3].boolval), (yyvsp[0].boolval), nullptr);
        delete (yyvsp[-1].string);
        (yyval.var_decl)->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag type_ident IDENTIFIER assign_nullable_flag)", yylineno);
    }
#line 1690 "./src/core/parser/parser.cpp"
    break;

  case 26: /* var_decl: var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign_nullable_flag  */
#line 269 "./src/core/parser/parser.y"
                                                                                    {
    	(yyvsp[-4].ident)->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*(yyvsp[-1].string)}));
    	(yyval.var_decl) = new VarDecl((yyvsp[-4].ident), name, (yyvsp[-5].boolval), (yyvsp[0].boolval), nullptr);
    	delete (yyvsp[-1].string);
        (yyval.var_decl)->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER)", yylineno);
    }
#line 1704 "./src/core/parser/parser.cpp"
    break;

  case 27: /* var_decl: var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 278 "./src/core/parser/parser.y"
                                                                                                      {
    	(yyvsp[-6].ident)->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)}));
    	(yyval.var_decl) = new VarDecl((yyvsp[-6].ident), name, (yyvsp[-7].boolval), (yyvsp[-2].boolval), (yyvsp[0].expr));
    	delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign", yylineno);
    }
#line 1718 "./src/core/parser/parser.cpp"
    break;

  case 28: /* var_decl: var_mutable_flag type_ident LBRACKET expression RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 287 "./src/core/parser/parser.y"
                                                                                                                 {
    	(yyvsp[-7].ident)->name_parts->push_back("[]");
    	(yyval.var_decl) = new VarDecl((yyvsp[-7].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)})), (yyvsp[-8].boolval), (yyvsp[-3].string), (yyvsp[0].expr), (yyvsp[-5].expr));
    	(yyval.var_decl)->size = (yyvsp[-5].expr);
    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign", yylineno, *(yyvsp[-3].string));
    	std::cout << (yyval.var_decl)->getName() << std::endl;
    	delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

    }
#line 1733 "./src/core/parser/parser.cpp"
    break;

  case 29: /* var_mutable_flag: VAR  */
#line 300 "./src/core/parser/parser.y"
        { (yyval.boolval) = { true }; }
#line 1739 "./src/core/parser/parser.cpp"
    break;

  case 30: /* var_mutable_flag: IMT  */
#line 301 "./src/core/parser/parser.y"
          { (yyval.boolval) = { false }; }
#line 1745 "./src/core/parser/parser.cpp"
    break;

  case 31: /* var_mutable_flag: %empty  */
#line 302 "./src/core/parser/parser.y"
                  { (yyval.boolval) = { false }; }
#line 1751 "./src/core/parser/parser.cpp"
    break;

  case 32: /* assign_nullable_flag: NULLABLE  */
#line 306 "./src/core/parser/parser.y"
             { (yyval.boolval) = { true }; }
#line 1757 "./src/core/parser/parser.cpp"
    break;

  case 33: /* assign_nullable_flag: NON_NULLABLE  */
#line 307 "./src/core/parser/parser.y"
                   { (yyval.boolval) = { false }; }
#line 1763 "./src/core/parser/parser.cpp"
    break;

  case 34: /* assign_nullable_flag: %empty  */
#line 308 "./src/core/parser/parser.y"
                  { (yyval.boolval) = { false }; }
#line 1769 "./src/core/parser/parser.cpp"
    break;

  case 35: /* extern_decl: EXTERN FUN qualified_name LPAREN var_decl_list RPAREN type_ident SEMICOLON  */
#line 312 "./src/core/parser/parser.y"
                                                                               {
        (yyval.stmt) = new ProtoDecl((yyvsp[-1].ident), (yyvsp[-5].ident), *(yyvsp[-3].varvec));
        delete (yyvsp[-3].varvec);
        (yyval.stmt)->line = yylineno;

        printParseInfo("extern_decl", yylineno);
    }
#line 1781 "./src/core/parser/parser.cpp"
    break;

  case 36: /* function_declaration: FUN qualified_name LPAREN var_decl_list RPAREN block  */
#line 322 "./src/core/parser/parser.y"
                                                         {

        (yyval.stmt) = new FuncDecl(new QualifiedName(), (yyvsp[-4].ident), *(yyvsp[-2].varvec), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;

        delete (yyvsp[-2].varvec);
        printParseInfo("function_declaration (without return type)", yylineno);
    }
#line 1794 "./src/core/parser/parser.cpp"
    break;

  case 37: /* function_declaration: FUN qualified_name LPAREN var_decl_list RPAREN type_ident block  */
#line 330 "./src/core/parser/parser.y"
                                                                       {
        (yyval.stmt) = new FuncDecl((yyvsp[-1].ident), (yyvsp[-5].ident), *(yyvsp[-3].varvec), (yyvsp[0].block));
        delete (yyvsp[-3].varvec);
        (yyval.stmt)->line = yylineno;

        printParseInfo("function_declaration (with return type)", yylineno);
    }
#line 1806 "./src/core/parser/parser.cpp"
    break;

  case 38: /* var_decl_list: %empty  */
#line 340 "./src/core/parser/parser.y"
                     {
    	(yyval.varvec) = new std::vector<VarDecl*>();
    	printParseInfo("var_decl_list (empty list)", yylineno);
    }
#line 1815 "./src/core/parser/parser.cpp"
    break;

  case 39: /* var_decl_list: var_decl  */
#line 344 "./src/core/parser/parser.y"
               {
        (yyval.varvec) = new std::vector<VarDecl*>{(yyvsp[0].var_decl)};
        printParseInfo("var_decl_list (single var_decl)", yylineno);
    }
#line 1824 "./src/core/parser/parser.cpp"
    break;

  case 40: /* var_decl_list: var_decl_list COMMA var_decl  */
#line 348 "./src/core/parser/parser.y"
                                   {
        (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl));
        std::cout << "Added " << (yyvsp[0].var_decl)->name->getName() << " to var_decl_list" << std::endl;
        (yyval.varvec) = (yyvsp[-2].varvec);
        printParseInfo("var_decl_list (multiple var_decl)", yylineno);
    }
#line 1835 "./src/core/parser/parser.cpp"
    break;

  case 41: /* qualified_name: IDENTIFIER  */
#line 357 "./src/core/parser/parser.y"
               {
        (yyval.ident) = new QualifiedName({*(yyvsp[0].string)});
        delete (yyvsp[0].string); // Clean up the string
        (yyval.ident)->line = yylineno;

        printParseInfo("qualified_name (single IDENTIFIER)", yylineno);
    }
#line 1847 "./src/core/parser/parser.cpp"
    break;

  case 42: /* qualified_name: qualified_name DOT IDENTIFIER  */
#line 364 "./src/core/parser/parser.y"
                                    {
        (yyval.ident) = (yyvsp[-2].ident);
        (yyval.ident)->name_parts->push_back(*(yyvsp[0].string));
        delete (yyvsp[0].string); // Clean up the string
        (yyval.ident)->line = yylineno;

        printParseInfo("qualified_name (nested)", yylineno);
    }
#line 1860 "./src/core/parser/parser.cpp"
    break;

  case 43: /* type_ident: qualified_name  */
#line 375 "./src/core/parser/parser.y"
                   {
        (yyval.ident) = (yyvsp[0].ident);
        (yyval.ident)->line = yylineno;

        printParseInfo("type_ident", yylineno);

    }
#line 1872 "./src/core/parser/parser.cpp"
    break;

  case 44: /* type_ident: type_ident TIMES  */
#line 382 "./src/core/parser/parser.y"
                       {
        (yyval.ident) = (yyvsp[-1].ident);
        (yyval.ident)->line = yylineno;
        (yyval.ident)->name_parts->push_back("*");

        printParseInfo("type_ident (pointer)", yylineno);
    }
#line 1884 "./src/core/parser/parser.cpp"
    break;

  case 45: /* binary_expression: expression binary_operator expression  */
#line 392 "./src/core/parser/parser.y"
                                         {
        (yyval.expr) = new BinaryExpr((yyvsp[-1].token), (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr)->line = yylineno;

        printParseInfo("binary_expression", yylineno);
    }
#line 1895 "./src/core/parser/parser.cpp"
    break;

  case 46: /* expression: INT_TOKEN  */
#line 402 "./src/core/parser/parser.y"
              {
        (yyval.expr) = new IntegerExpr(atol((yyvsp[0].string)->c_str()));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (INT_TOKEN)", yylineno);
    }
#line 1906 "./src/core/parser/parser.cpp"
    break;

  case 47: /* expression: DOUBLE_TOKEN  */
#line 408 "./src/core/parser/parser.y"
                   {
        (yyval.expr) = new DoubleExpr(atof((yyvsp[0].string)->c_str()));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (DOUBLE_TOKEN)", yylineno);
    }
#line 1917 "./src/core/parser/parser.cpp"
    break;

  case 48: /* expression: STRING_LITERAL  */
#line 414 "./src/core/parser/parser.y"
                     {
        printParseInfo("expression (STRING_LITERAL)", yylineno, *(yyvsp[0].string));
        std::string str;
        str = (yyvsp[0].string)->substr(1, (yyvsp[0].string)->length() - 2);
        (yyval.expr) = new StringExpr(str);
        delete (yyvsp[0].string); // Clean up the string
        (yyval.expr)->line = yylineno;
    }
#line 1930 "./src/core/parser/parser.cpp"
    break;

  case 49: /* expression: bool_expression  */
#line 422 "./src/core/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->line = yylineno;
        
        printParseInfo("expression (bool_expression)", yylineno);
    }
#line 1941 "./src/core/parser/parser.cpp"
    break;

  case 50: /* expression: qualified_name  */
#line 428 "./src/core/parser/parser.y"
                     {
        (yyval.expr) = new VarExpr((yyvsp[0].ident));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (qualified_name)", yylineno, (yyvsp[0].ident)->getName());
    }
#line 1952 "./src/core/parser/parser.cpp"
    break;

  case 51: /* expression: LPAREN expression RPAREN  */
#line 434 "./src/core/parser/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (parenthesized)", yylineno);
    }
#line 1963 "./src/core/parser/parser.cpp"
    break;

  case 52: /* expression: qualified_name LPAREN expr_list RPAREN  */
#line 440 "./src/core/parser/parser.y"
                                             {
        (yyval.expr) = new CallExpr((yyvsp[-3].ident), *(yyvsp[-1].exprvec));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (function call)", yylineno);
    }
#line 1974 "./src/core/parser/parser.cpp"
    break;

  case 53: /* expression: binary_expression  */
#line 446 "./src/core/parser/parser.y"
                        {
	(yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (binary_expression)", yylineno);
    }
#line 1985 "./src/core/parser/parser.cpp"
    break;

  case 54: /* expression: unary_expression  */
#line 452 "./src/core/parser/parser.y"
                       {
        (yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (unary_expression)", yylineno);
    }
#line 1996 "./src/core/parser/parser.cpp"
    break;

  case 55: /* expression: LBRACKET expr_list RBRACKET  */
#line 458 "./src/core/parser/parser.y"
                                  {
        (yyval.expr) = new ListExpr((yyvsp[-1].exprvec));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (list)", yylineno);
    }
#line 2007 "./src/core/parser/parser.cpp"
    break;

  case 56: /* expression: qualified_name LBRACKET expression RBRACKET  */
#line 464 "./src/core/parser/parser.y"
                                                  {
        (yyval.expr) = new ArrayExpr((yyvsp[-1].expr), (yyvsp[-3].ident));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (array access)", yylineno);
    }
#line 2018 "./src/core/parser/parser.cpp"
    break;

  case 57: /* bool_expression: TRUE  */
#line 473 "./src/core/parser/parser.y"
         {
        printParseInfo("expression (TRUE)", yylineno);
        (yyval.expr) = new BoolExpr(true);
        (yyval.expr)->line = yylineno;
    }
#line 2028 "./src/core/parser/parser.cpp"
    break;

  case 58: /* bool_expression: FALSE  */
#line 478 "./src/core/parser/parser.y"
            {
        printParseInfo("expression (FALSE)", yylineno);
        (yyval.expr) = new BoolExpr(false);
        (yyval.expr)->line = yylineno;
    }
#line 2038 "./src/core/parser/parser.cpp"
    break;

  case 59: /* unary_expression: unary_operator expression  */
#line 485 "./src/core/parser/parser.y"
                              {
        (yyval.expr) = new UnaryExpr((yyvsp[-1].token), (yyvsp[0].expr));
        (yyval.expr)->line = yylineno;

        printParseInfo("unary_expression", yylineno);
    }
#line 2049 "./src/core/parser/parser.cpp"
    break;

  case 60: /* binary_operator: PLUS  */
#line 494 "./src/core/parser/parser.y"
         { (yyval.token) = PLUS; }
#line 2055 "./src/core/parser/parser.cpp"
    break;

  case 61: /* binary_operator: MINUS  */
#line 495 "./src/core/parser/parser.y"
            { (yyval.token) = MINUS; }
#line 2061 "./src/core/parser/parser.cpp"
    break;

  case 62: /* binary_operator: TIMES  */
#line 496 "./src/core/parser/parser.y"
            { (yyval.token) = TIMES; }
#line 2067 "./src/core/parser/parser.cpp"
    break;

  case 63: /* binary_operator: DIVIDE  */
#line 497 "./src/core/parser/parser.y"
             { (yyval.token) = DIVIDE; }
#line 2073 "./src/core/parser/parser.cpp"
    break;

  case 64: /* binary_operator: MOD  */
#line 498 "./src/core/parser/parser.y"
          { (yyval.token) = MOD; }
#line 2079 "./src/core/parser/parser.cpp"
    break;

  case 65: /* binary_operator: LT  */
#line 499 "./src/core/parser/parser.y"
         { (yyval.token) = LT; }
#line 2085 "./src/core/parser/parser.cpp"
    break;

  case 66: /* binary_operator: LE  */
#line 500 "./src/core/parser/parser.y"
         { (yyval.token) = LE; }
#line 2091 "./src/core/parser/parser.cpp"
    break;

  case 67: /* binary_operator: GT  */
#line 501 "./src/core/parser/parser.y"
         { (yyval.token) = GT; }
#line 2097 "./src/core/parser/parser.cpp"
    break;

  case 68: /* binary_operator: GE  */
#line 502 "./src/core/parser/parser.y"
         { (yyval.token) = GE; }
#line 2103 "./src/core/parser/parser.cpp"
    break;

  case 69: /* binary_operator: EQ  */
#line 503 "./src/core/parser/parser.y"
         { (yyval.token) = EQ; }
#line 2109 "./src/core/parser/parser.cpp"
    break;

  case 70: /* binary_operator: NE  */
#line 504 "./src/core/parser/parser.y"
         { (yyval.token) = NE; }
#line 2115 "./src/core/parser/parser.cpp"
    break;

  case 71: /* binary_operator: AND  */
#line 505 "./src/core/parser/parser.y"
          { (yyval.token) = AND; }
#line 2121 "./src/core/parser/parser.cpp"
    break;

  case 72: /* binary_operator: OR  */
#line 506 "./src/core/parser/parser.y"
         { (yyval.token) = OR; }
#line 2127 "./src/core/parser/parser.cpp"
    break;

  case 73: /* binary_operator: PLUS_ASSIGN  */
#line 507 "./src/core/parser/parser.y"
                  { (yyval.token) = PLUS_ASSIGN; }
#line 2133 "./src/core/parser/parser.cpp"
    break;

  case 74: /* binary_operator: MINUS_ASSIGN  */
#line 508 "./src/core/parser/parser.y"
                   { (yyval.token) = MINUS_ASSIGN; }
#line 2139 "./src/core/parser/parser.cpp"
    break;

  case 75: /* binary_operator: TIMES_ASSIGN  */
#line 509 "./src/core/parser/parser.y"
                   { (yyval.token) = TIMES_ASSIGN; }
#line 2145 "./src/core/parser/parser.cpp"
    break;

  case 76: /* binary_operator: DIVIDE_ASSIGN  */
#line 510 "./src/core/parser/parser.y"
                    { (yyval.token) = DIVIDE_ASSIGN; }
#line 2151 "./src/core/parser/parser.cpp"
    break;

  case 77: /* binary_operator: MOD_ASSIGN  */
#line 511 "./src/core/parser/parser.y"
                 { (yyval.token) = MOD_ASSIGN; }
#line 2157 "./src/core/parser/parser.cpp"
    break;

  case 78: /* binary_operator: LSHIFT  */
#line 512 "./src/core/parser/parser.y"
             { (yyval.token) = LSHIFT; }
#line 2163 "./src/core/parser/parser.cpp"
    break;

  case 79: /* binary_operator: RSHIFT  */
#line 513 "./src/core/parser/parser.y"
             { (yyval.token) = RSHIFT; }
#line 2169 "./src/core/parser/parser.cpp"
    break;

  case 80: /* binary_operator: URSHIFT  */
#line 514 "./src/core/parser/parser.y"
              { (yyval.token) = URSHIFT; }
#line 2175 "./src/core/parser/parser.cpp"
    break;

  case 81: /* binary_operator: XOR  */
#line 515 "./src/core/parser/parser.y"
          { (yyval.token) = XOR; }
#line 2181 "./src/core/parser/parser.cpp"
    break;

  case 82: /* unary_operator: MINUS  */
#line 519 "./src/core/parser/parser.y"
          { (yyval.token) = MINUS; }
#line 2187 "./src/core/parser/parser.cpp"
    break;

  case 83: /* unary_operator: PLUS  */
#line 520 "./src/core/parser/parser.y"
           { (yyval.token) = PLUS; }
#line 2193 "./src/core/parser/parser.cpp"
    break;

  case 84: /* unary_operator: NOT  */
#line 521 "./src/core/parser/parser.y"
          { (yyval.token) = NOT; }
#line 2199 "./src/core/parser/parser.cpp"
    break;

  case 85: /* unary_operator: INC  */
#line 522 "./src/core/parser/parser.y"
          { (yyval.token) = INC; }
#line 2205 "./src/core/parser/parser.cpp"
    break;

  case 86: /* unary_operator: DEC  */
#line 523 "./src/core/parser/parser.y"
          { (yyval.token) = DEC; }
#line 2211 "./src/core/parser/parser.cpp"
    break;

  case 87: /* unary_operator: TIMES  */
#line 524 "./src/core/parser/parser.y"
            { (yyval.token) = TIMES; }
#line 2217 "./src/core/parser/parser.cpp"
    break;

  case 88: /* unary_operator: BIT_AND  */
#line 525 "./src/core/parser/parser.y"
              { (yyval.token) = BIT_AND; }
#line 2223 "./src/core/parser/parser.cpp"
    break;

  case 89: /* expr_list: %empty  */
#line 529 "./src/core/parser/parser.y"
                {
        (yyval.exprvec) = new std::vector<Expr*>();
        printParseInfo("expr_list (empty)", yylineno);
    }
#line 2232 "./src/core/parser/parser.cpp"
    break;

  case 90: /* expr_list: expression  */
#line 533 "./src/core/parser/parser.y"
                {
        (yyval.exprvec) = new std::vector<Expr*>{(yyvsp[0].expr)};
        printParseInfo("expr_list (singleexpression)", yylineno);
    }
#line 2241 "./src/core/parser/parser.cpp"
    break;

  case 91: /* expr_list: expr_list COMMA expression  */
#line 537 "./src/core/parser/parser.y"
                                {
        (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr));
        (yyval.exprvec) = (yyvsp[-2].exprvec);
        printParseInfo("expr_list (multipleexpressions)", yylineno);
    }
#line 2251 "./src/core/parser/parser.cpp"
    break;

  case 92: /* if_statement: IF expression block  */
#line 545 "./src/core/parser/parser.y"
                        {
        (yyval.stmt) = new IfStmt((yyvsp[-1].expr), (yyvsp[0].block), nullptr);
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (no else)", yylineno);
    }
#line 2262 "./src/core/parser/parser.cpp"
    break;

  case 93: /* if_statement: IF expression block ELSE block  */
#line 551 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new IfStmt((yyvsp[-3].expr), (yyvsp[-2].block), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (with else)", yylineno);
    }
#line 2273 "./src/core/parser/parser.cpp"
    break;

  case 94: /* if_statement: IF expression block elif_stmts  */
#line 557 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new IfStmt((yyvsp[-2].expr), (yyvsp[-1].block), nullptr, dynamic_cast<IfStmt*>((yyvsp[0].stmt)));
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (with elif_stmts)", yylineno);
    }
#line 2284 "./src/core/parser/parser.cpp"
    break;

  case 95: /* elif_stmts: elif_statement  */
#line 572 "./src/core/parser/parser.y"
                   {
        (yyvsp[0].stmt)->line = yylineno;
        (yyval.stmt) = (yyvsp[0].stmt);

        printParseInfo("elif_stmts (empty)", yylineno);
    }
#line 2295 "./src/core/parser/parser.cpp"
    break;

  case 96: /* elif_stmts: elif_statement ELSE block  */
#line 578 "./src/core/parser/parser.y"
                                {
        auto res = dynamic_cast<IfStmt*>((yyvsp[-2].stmt));
        res->line = yylineno;
        res->else_body = (yyvsp[0].block);
        (yyval.stmt) = res;

        printParseInfo("elif_stmts (empty)", yylineno);
    }
#line 2308 "./src/core/parser/parser.cpp"
    break;

  case 97: /* elif_stmts: elif_statement elif_stmts  */
#line 586 "./src/core/parser/parser.y"
                                {
        auto res = dynamic_cast<IfStmt*>((yyvsp[-1].stmt));
        res->elseIf = dynamic_cast<IfStmt*>((yyvsp[0].stmt));
        res->line = yylineno;
        (yyval.stmt) = res;
        printParseInfo("elif_stmts (with elif_statement)", yylineno);
    }
#line 2320 "./src/core/parser/parser.cpp"
    break;

  case 98: /* elif_statement: ELIF expression block  */
#line 596 "./src/core/parser/parser.y"
                          {
        (yyval.stmt) = new IfStmt((yyvsp[-1].expr), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;
        printParseInfo("elif_statement", yylineno);
    }
#line 2330 "./src/core/parser/parser.cpp"
    break;

  case 99: /* for_statement: FOR for_var_decl SEMICOLON expression SEMICOLON expression block  */
#line 604 "./src/core/parser/parser.y"
                                                                     {
        (yyval.stmt) = new ForStmt((yyvsp[-5].var_decl), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;
        printParseInfo("for_statement", yylineno);
    }
#line 2340 "./src/core/parser/parser.cpp"
    break;

  case 100: /* break_statement: BREAK  */
#line 612 "./src/core/parser/parser.y"
          {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new BreakStmt();
        printParseInfo("break_statement", yylineno);
    }
#line 2350 "./src/core/parser/parser.cpp"
    break;

  case 101: /* break_statement: BREAK expression  */
#line 617 "./src/core/parser/parser.y"
                       {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new BreakStmt((yyvsp[0].expr));
        printParseInfo("break_statement", yylineno);
    }
#line 2360 "./src/core/parser/parser.cpp"
    break;

  case 102: /* for_var_decl: type_ident IDENTIFIER ASSIGN expression  */
#line 625 "./src/core/parser/parser.y"
                                            {
        (yyval.var_decl) = new VarDecl((yyvsp[-3].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-2].string)})), true, true, (yyvsp[0].expr));
        printParseInfo("for_var_decl (type_ident qualified_name IDENTIFIER ASSIGN expression)", yylineno);
    }
#line 2369 "./src/core/parser/parser.cpp"
    break;

  case 103: /* for_var_decl: type_ident IDENTIFIER  */
#line 629 "./src/core/parser/parser.y"
                            {
        (yyval.var_decl) = new VarDecl((yyvsp[-1].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[0].string)})), true, true, nullptr);
        printParseInfo("for_var_decl (type_ident qualified_name IDENTIFIER)", yylineno);
    }
#line 2378 "./src/core/parser/parser.cpp"
    break;

  case 104: /* struct_decl: STRUCT IDENTIFIER LBRACE struct_field_list RBRACE SEMICOLON  */
#line 636 "./src/core/parser/parser.y"
                                                                {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new StructDecl(new QualifiedName({*(yyvsp[-4].string)}), *(yyvsp[-2].varvec));
        delete (yyvsp[-4].string);
        delete (yyvsp[-2].varvec);
        printParseInfo("struct_decl", yylineno);
    }
#line 2390 "./src/core/parser/parser.cpp"
    break;

  case 105: /* struct_field_list: %empty  */
#line 646 "./src/core/parser/parser.y"
                {
        (yyval.varvec) = new std::vector<VarDecl*>();
        printParseInfo("struct_field_list (empty)", yylineno);
    }
#line 2399 "./src/core/parser/parser.cpp"
    break;

  case 106: /* struct_field_list: struct_field_list var_decl SEMICOLON  */
#line 650 "./src/core/parser/parser.y"
                                           {
        (yyvsp[-2].varvec)->push_back((yyvsp[-1].var_decl));
        (yyval.varvec) = (yyvsp[-2].varvec);
        printParseInfo("struct_field_list (with var_decl)", yylineno);
    }
#line 2409 "./src/core/parser/parser.cpp"
    break;

  case 107: /* assign_expr: qualified_name ASSIGN expression  */
#line 658 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new AssignExpr((yyvsp[-2].ident), (yyvsp[0].expr));
        (yyval.stmt)->line = yylineno;
        printParseInfo("assignment", yylineno);
    }
#line 2419 "./src/core/parser/parser.cpp"
    break;

  case 108: /* array_assign_stmt: qualified_name LBRACKET expression RBRACKET ASSIGN expression SEMICOLON  */
#line 666 "./src/core/parser/parser.y"
                                                                            {
        (yyval.stmt) = new ArrayAssignExpr((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;
        printParseInfo("array_assign_expr", yylineno);

    }
#line 2430 "./src/core/parser/parser.cpp"
    break;


#line 2434 "./src/core/parser/parser.cpp"

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

#line 674 "./src/core/parser/parser.y"
