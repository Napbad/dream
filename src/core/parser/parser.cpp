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
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_stmt_list = 62,                 /* stmt_list  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_include_stmt = 64,              /* include_stmt  */
  YYSYMBOL_package_stmt = 65,              /* package_stmt  */
  YYSYMBOL_block = 66,                     /* block  */
  YYSYMBOL_var_decl = 67,                  /* var_decl  */
  YYSYMBOL_var_mutable_flag = 68,          /* var_mutable_flag  */
  YYSYMBOL_assign_nullable_flag = 69,      /* assign_nullable_flag  */
  YYSYMBOL_extern_decl = 70,               /* extern_decl  */
  YYSYMBOL_function_declaration = 71,      /* function_declaration  */
  YYSYMBOL_var_decl_list = 72,             /* var_decl_list  */
  YYSYMBOL_qualified_name = 73,            /* qualified_name  */
  YYSYMBOL_type_ident = 74,                /* type_ident  */
  YYSYMBOL_binary_expression = 75,         /* binary_expression  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_unary_expression = 77,          /* unary_expression  */
  YYSYMBOL_binary_operator = 78,           /* binary_operator  */
  YYSYMBOL_unary_operator = 79,            /* unary_operator  */
  YYSYMBOL_expr_list = 80,                 /* expr_list  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_elif_stmts = 82,                /* elif_stmts  */
  YYSYMBOL_elif_statement = 83,            /* elif_statement  */
  YYSYMBOL_for_statement = 84,             /* for_statement  */
  YYSYMBOL_break_statement = 85,           /* break_statement  */
  YYSYMBOL_for_var_decl = 86,              /* for_var_decl  */
  YYSYMBOL_struct_decl = 87,               /* struct_decl  */
  YYSYMBOL_struct_field_list = 88,         /* struct_field_list  */
  YYSYMBOL_assign_expr = 89,               /* assign_expr  */
  YYSYMBOL_array_assign_stmt = 90          /* array_assign_stmt  */
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
#define YYLAST   686

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   116,   120,   128,   134,   140,   146,   152,
     158,   164,   170,   176,   182,   188,   194,   200,   206,   212,
     218,   227,   236,   245,   254,   261,   268,   277,   286,   299,
     300,   301,   305,   306,   307,   311,   321,   329,   339,   343,
     347,   356,   363,   374,   381,   391,   401,   407,   413,   422,
     428,   434,   440,   446,   452,   458,   467,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   501,
     502,   503,   504,   505,   506,   507,   511,   515,   519,   527,
     533,   539,   545,   554,   560,   570,   578,   586,   591,   599,
     603,   610,   620,   624,   632,   640
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
  "NULLABLE", "NON_NULLABLE", "LSHIFT", "RSHIFT", "URSHIFT", "$accept",
  "program", "stmt_list", "stmt", "include_stmt", "package_stmt", "block",
  "var_decl", "var_mutable_flag", "assign_nullable_flag", "extern_decl",
  "function_declaration", "var_decl_list", "qualified_name", "type_ident",
  "binary_expression", "expression", "unary_expression", "binary_operator",
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

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,    46,   201,  -126,  -126,  -126,  -126,  -126,    52,   643,
    -126,  -126,  -126,   643,  -126,   643,  -126,  -126,  -126,  -126,
     643,   643,    91,   575,    91,    61,    91,    91,  -126,  -126,
    -126,  -126,  -126,  -126,    65,    91,  -126,  -126,    25,  -126,
     246,  -126,   643,  -126,  -126,  -126,    95,  -126,    97,  -126,
      94,    27,   537,    47,   149,   537,    77,   282,   282,   107,
      11,   102,  -126,   318,    30,    91,    73,    81,  -126,     9,
     115,   643,   643,   643,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,   643,   537,  -126,
    -126,  -126,   643,  -126,  -126,   643,  -126,   -26,  -126,   105,
    -126,   643,  -126,    -1,    32,  -126,  -126,    36,   609,  -126,
     537,    50,   355,   537,   -16,   392,   537,   103,    79,    76,
     643,   428,  -126,    51,    -1,  -126,  -126,   110,   122,   465,
    -126,   112,   113,   116,  -126,  -126,   103,  -126,   537,   643,
      54,    12,    82,   643,    36,   124,   643,  -126,  -126,  -126,
     282,  -126,  -126,     5,    91,   537,   118,    36,   501,  -126,
    -126,    39,   643,   119,  -126,  -126,   537,   643,   537
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    48,    41,    46,    47,     0,    97,
      80,    79,    84,     0,     3,    86,    81,    82,    83,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
       4,    19,    20,    17,     0,     0,    15,    12,    49,    52,
       0,    53,     0,     9,    10,    11,     0,    18,     0,    14,
       0,    49,    98,     0,     0,    87,     0,     0,     0,    43,
       0,     0,     8,     0,     0,     0,     0,     0,     6,     0,
       0,     0,    86,     0,    57,    58,    59,    60,    61,     5,
      62,    63,    64,    65,    66,    67,    68,    69,    78,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    56,    16,
      13,   102,     0,    50,    23,     0,    54,    89,    95,   100,
      44,     0,     7,    38,     0,    21,    22,    34,     0,    42,
     104,     0,     0,    45,    31,     0,    88,     0,    91,    93,
       0,     0,    39,     0,    38,    32,    33,    25,     0,     0,
      51,    55,     0,     0,    55,    90,     0,    94,    99,     0,
      31,     0,     0,     0,    34,     0,     0,   101,   103,    92,
       0,    40,    36,     0,     0,    24,    26,    34,     0,    96,
      37,     0,     0,     0,   105,    35,    27,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,   117,  -126,  -126,  -126,   -48,  -106,  -126,  -125,
    -126,  -126,     1,     0,   -34,  -126,    -9,  -126,  -126,  -126,
      64,  -126,     8,   -99,  -126,  -126,  -126,  -126,  -126,  -126,
    -126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,    31,    32,    33,    34,    35,   137,
      36,    37,   133,    51,    60,    39,    40,    41,    97,    42,
      56,    43,   128,    44,    45,    46,    61,    47,   124,    48,
      49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    69,    38,   -31,    53,   142,    55,   132,   129,   107,
     108,    57,    58,   117,    63,   109,     5,   110,   143,   127,
      21,   110,    59,   110,    64,    14,    66,    67,   132,   166,
     129,   118,    14,    98,    70,    59,    70,    28,    29,    70,
      71,    70,   173,    72,   161,    72,     3,    73,   113,   102,
     134,   110,    28,    29,    38,   175,    50,    74,    75,    76,
      77,    78,   120,    55,   122,   114,   103,   105,   150,   140,
     151,    80,    81,    82,    83,    84,    85,    86,    87,   145,
      88,    68,    70,    89,    90,    91,    92,    93,   123,   115,
      70,   135,   136,   125,   105,     5,   126,   116,   159,   150,
     106,   164,   131,   162,    94,    95,    96,    28,    29,   139,
      65,    99,   169,   100,   101,   170,    70,   163,   111,   119,
     130,   148,    21,    14,   146,   153,   154,   156,   167,   157,
     171,    54,   158,   172,   177,   152,   121,   147,     0,     0,
     160,     0,     0,     0,   165,     0,     0,   168,     0,     0,
       0,    59,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,   176,    59,     0,     0,    13,   178,    14,
     104,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,    13,
       0,    14,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    74,    75,    76,    77,
      78,     0,    79,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    88,
       0,     0,    89,    90,    91,    92,    93,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,    14,    94,    95,    96,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    88,     0,     0,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,     0,   112,     0,     0,     0,     0,    94,
      95,    96,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,     0,     0,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,    94,    95,    96,   141,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    88,     0,
       0,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,    94,    95,    96,   144,    80,    81,    82,    83,
      84,    85,    86,    87,     0,    88,     0,     0,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,     0,   149,     0,     0,     0,     0,    94,
      95,    96,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    88,     0,     0,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,    94,    95,    96,   155,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    88,     0,
       0,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,   174,     0,     0,
       0,     0,    94,    95,    96,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    88,     0,     0,    89,    90,    91,
      92,    93,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      88,     0,     0,    89,    90,    91,    92,    93,     4,     5,
       6,     7,     0,     0,     0,    10,    11,    12,     0,     0,
       0,    62,     0,    13,    94,    95,    96,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     4,     5,     6,     7,    17,    18,    19,    10,
      11,    12,     0,     0,     0,     0,     0,    13,     0,     0,
       0,    15,   138,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     4,     5,     6,     7,
      17,    18,    19,    10,    11,    12,     0,     0,     0,     0,
       0,    13,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19
};

static const yytype_int16 yycheck[] =
{
       9,    35,     2,     4,    13,    21,    15,   113,   107,    57,
      58,    20,    21,     4,    23,     4,     4,    12,   124,    45,
      46,    12,    22,    12,    24,    20,    26,    27,   134,   154,
     129,    22,    20,    42,     9,    35,     9,    53,    54,     9,
      15,     9,   167,    18,   150,    18,     0,    22,    18,    22,
      18,    12,    53,    54,    54,    16,     4,    10,    11,    12,
      13,    14,    71,    72,    73,    65,    19,    17,    17,    19,
      19,    24,    25,    26,    27,    28,    29,    30,    31,   127,
      33,    16,     9,    36,    37,    38,    39,    40,    97,    16,
       9,    55,    56,   102,    17,     4,   105,    16,   146,    17,
      23,    19,   111,   151,    57,    58,    59,    53,    54,   118,
      49,    16,   160,    16,    20,   163,     9,   151,    16,     4,
      15,   130,    46,    20,    45,    15,     4,    15,     4,    16,
     164,    14,    16,    15,    15,   134,    72,   129,    -1,    -1,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,    -1,    -1,
      -1,   151,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    -1,   172,   164,    -1,    -1,    18,   177,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    57,    58,    59,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    57,
      58,    59,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    57,
      58,    59,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    57,    58,    59,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    38,    39,    40,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    57,    58,    59,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    41,    42,    43,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      41,    42,    43,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    18,    20,    22,    32,    41,    42,    43,
      44,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      63,    64,    65,    66,    67,    68,    70,    71,    73,    75,
      76,    77,    79,    81,    83,    84,    85,    87,    89,    90,
       4,    73,    76,    76,    62,    76,    80,    76,    76,    73,
      74,    86,    16,    76,    73,    49,    73,    73,    16,    74,
       9,    15,    18,    22,    10,    11,    12,    13,    14,    16,
      24,    25,    26,    27,    28,    29,    30,    31,    33,    36,
      37,    38,    39,    40,    57,    58,    59,    78,    76,    16,
      16,    20,    22,    19,    21,    17,    23,    66,    66,     4,
      12,    16,    16,    18,    73,    16,    16,     4,    22,     4,
      76,    80,    76,    76,    88,    76,    76,    45,    82,    83,
      15,    76,    67,    72,    18,    55,    56,    69,    23,    76,
      19,    23,    21,    67,    23,    66,    45,    82,    76,    16,
      17,    19,    72,    15,     4,    23,    15,    16,    16,    66,
      76,    67,    66,    74,    19,    76,    69,     4,    76,    66,
      66,    74,    15,    69,    16,    16,    76,    15,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    82,    82,    83,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     3,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     3,     3,     3,     6,     4,     6,     8,     9,     1,
       1,     0,     1,     1,     0,     8,     6,     7,     0,     1,
       3,     1,     3,     1,     2,     3,     1,     1,     1,     1,
       3,     4,     1,     1,     3,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     3,     3,
       5,     4,     6,     1,     2,     3,     7,     1,     2,     4,
       2,     6,     0,     3,     3,     7
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
#line 107 "./src/core/parser/parser.y"
              {
        program = new Program(new BlockStmt(*(yyvsp[0].stmtvec)));
        (yyval.node)->line = yylineno;

        printParseInfo("program", yylineno);
    }
#line 1423 "./src/core/parser/parser.cpp"
    break;

  case 3: /* stmt_list: %empty  */
#line 116 "./src/core/parser/parser.y"
                {
        (yyval.stmtvec) = new std::vector<Stmt*>();
        printParseInfo("stmt_list (empty)", yylineno);
    }
#line 1432 "./src/core/parser/parser.cpp"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 120 "./src/core/parser/parser.y"
                     {
        (yyvsp[-1].stmtvec)->push_back((yyvsp[0].stmt));
        (yyval.stmtvec) = (yyvsp[-1].stmtvec);
        printParseInfo("stmt_list", yylineno);
    }
#line 1442 "./src/core/parser/parser.cpp"
    break;

  case 5: /* stmt: expression SEMICOLON  */
#line 128 "./src/core/parser/parser.y"
                         {
        (yyval.stmt) = new ExprStmt((yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (expression SEMICOLON)", yylineno);
    }
#line 1453 "./src/core/parser/parser.cpp"
    break;

  case 6: /* stmt: var_decl SEMICOLON  */
#line 134 "./src/core/parser/parser.y"
                         {
        (yyval.stmt) = (yyvsp[-1].var_decl);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (var_decl SEMICOLON)", yylineno);
    }
#line 1464 "./src/core/parser/parser.cpp"
    break;

  case 7: /* stmt: RETURN expression SEMICOLON  */
#line 140 "./src/core/parser/parser.y"
                                  {
        (yyval.stmt) = new ReturnStmt((yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (RETURN expression SEMICOLON)", yylineno);
    }
#line 1475 "./src/core/parser/parser.cpp"
    break;

  case 8: /* stmt: RETURN SEMICOLON  */
#line 146 "./src/core/parser/parser.y"
                       {
        (yyval.stmt) = new ReturnStmt(nullptr);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (RETURN void SEMICOLON)", yylineno);
    }
#line 1486 "./src/core/parser/parser.cpp"
    break;

  case 9: /* stmt: if_statement  */
#line 152 "./src/core/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (if_statement)", yylineno);
    }
#line 1497 "./src/core/parser/parser.cpp"
    break;

  case 10: /* stmt: elif_statement  */
#line 158 "./src/core/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (elif_statement)", yylineno);
    }
#line 1508 "./src/core/parser/parser.cpp"
    break;

  case 11: /* stmt: for_statement  */
#line 164 "./src/core/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (for_statement)", yylineno);
    }
#line 1519 "./src/core/parser/parser.cpp"
    break;

  case 12: /* stmt: function_declaration  */
#line 170 "./src/core/parser/parser.y"
                           {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (function_declaration)", yylineno);
    }
#line 1530 "./src/core/parser/parser.cpp"
    break;

  case 13: /* stmt: assign_expr SEMICOLON  */
#line 176 "./src/core/parser/parser.y"
                            {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (assignment)", yylineno);
    }
#line 1541 "./src/core/parser/parser.cpp"
    break;

  case 14: /* stmt: array_assign_stmt  */
#line 182 "./src/core/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (array_assign_stmt)", yylineno);
    }
#line 1552 "./src/core/parser/parser.cpp"
    break;

  case 15: /* stmt: extern_decl  */
#line 188 "./src/core/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (extern_decl)", yylineno);
    }
#line 1563 "./src/core/parser/parser.cpp"
    break;

  case 16: /* stmt: break_statement SEMICOLON  */
#line 194 "./src/core/parser/parser.y"
                                {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (break_statement)", yylineno);
    }
#line 1574 "./src/core/parser/parser.cpp"
    break;

  case 17: /* stmt: block  */
#line 200 "./src/core/parser/parser.y"
            {
        (yyval.stmt) = (yyvsp[0].block);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (block)", yylineno);
    }
#line 1585 "./src/core/parser/parser.cpp"
    break;

  case 18: /* stmt: struct_decl  */
#line 206 "./src/core/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

        printParseInfo("stmt (struct_decl)", yylineno);
    }
#line 1596 "./src/core/parser/parser.cpp"
    break;

  case 19: /* stmt: include_stmt  */
#line 212 "./src/core/parser/parser.y"
                   {
    	(yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

    	printParseInfo("stmmt (include_stmt)", yylineno);
    }
#line 1607 "./src/core/parser/parser.cpp"
    break;

  case 20: /* stmt: package_stmt  */
#line 218 "./src/core/parser/parser.y"
                   {
    	(yyval.stmt) = (yyvsp[0].stmt);
        (yyval.stmt)->line = yylineno;

    	printParseInfo("stmt (package_stmt)", yylineno);
    }
#line 1618 "./src/core/parser/parser.cpp"
    break;

  case 21: /* include_stmt: INCLUDE qualified_name SEMICOLON  */
#line 227 "./src/core/parser/parser.y"
                                     {
	(yyval.stmt) = new IncludeStmt((yyvsp[-1].ident));
        (yyval.stmt)->line = yylineno;

	printParseInfo("include_stmt", yylineno);
    }
#line 1629 "./src/core/parser/parser.cpp"
    break;

  case 22: /* package_stmt: PACKAGE qualified_name SEMICOLON  */
#line 236 "./src/core/parser/parser.y"
                                     {
	(yyval.stmt) = new PackageStmt((yyvsp[-1].ident));
        (yyval.stmt)->line = yylineno;

	printParseInfo("package_stmt", yylineno);
    }
#line 1640 "./src/core/parser/parser.cpp"
    break;

  case 23: /* block: LBRACE stmt_list RBRACE  */
#line 245 "./src/core/parser/parser.y"
                            {
        (yyval.block) = new BlockStmt(*(yyvsp[-1].stmtvec));
        (yyval.block)->line = yylineno;

        printParseInfo("block", yylineno);
    }
#line 1651 "./src/core/parser/parser.cpp"
    break;

  case 24: /* var_decl: var_mutable_flag type_ident IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 254 "./src/core/parser/parser.y"
                                                                                  {
        (yyval.var_decl) = new VarDecl((yyvsp[-4].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)})), (yyvsp[-5].boolval), (yyvsp[-2].boolval), (yyvsp[0].expr));
        delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag type_ident IDENTIFIER assign_nullable_flag ASSIGN expression)", yylineno, (yyval.var_decl)->getName());
    }
#line 1663 "./src/core/parser/parser.cpp"
    break;

  case 25: /* var_decl: var_mutable_flag type_ident IDENTIFIER assign_nullable_flag  */
#line 261 "./src/core/parser/parser.y"
                                                                  {
        (yyval.var_decl) = new VarDecl((yyvsp[-2].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-1].string)})), (yyvsp[-3].boolval), (yyvsp[0].boolval), nullptr);
        delete (yyvsp[-1].string);
        (yyval.var_decl)->line = yylineno;

        printParseInfo("var_decl (var_mutable_flag type_ident IDENTIFIER assign_nullable_flag)", yylineno);
    }
#line 1675 "./src/core/parser/parser.cpp"
    break;

  case 26: /* var_decl: var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign_nullable_flag  */
#line 268 "./src/core/parser/parser.y"
                                                                                    {
    	(yyvsp[-4].ident)->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*(yyvsp[-1].string)}));
    	(yyval.var_decl) = new VarDecl((yyvsp[-4].ident), name, (yyvsp[-5].boolval), (yyvsp[0].boolval), nullptr);
    	delete (yyvsp[-1].string);
        (yyval.var_decl)->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER)", yylineno);
    }
#line 1689 "./src/core/parser/parser.cpp"
    break;

  case 27: /* var_decl: var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 277 "./src/core/parser/parser.y"
                                                                                                      {
    	(yyvsp[-6].ident)->name_parts->push_back("[]");
        QualifiedName *name = new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)}));
    	(yyval.var_decl) = new VarDecl((yyvsp[-6].ident), name, (yyvsp[-7].boolval), (yyvsp[-2].boolval), (yyvsp[0].expr));
    	delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign", yylineno);
    }
#line 1703 "./src/core/parser/parser.cpp"
    break;

  case 28: /* var_decl: var_mutable_flag type_ident LBRACKET expression RBRACKET IDENTIFIER assign_nullable_flag ASSIGN expression  */
#line 286 "./src/core/parser/parser.y"
                                                                                                                 {
    	(yyvsp[-7].ident)->name_parts->push_back("[]");
    	(yyval.var_decl) = new VarDecl((yyvsp[-7].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-3].string)})), (yyvsp[-8].boolval), (yyvsp[-3].string), (yyvsp[0].expr), (yyvsp[-5].expr));
    	(yyval.var_decl)->size = (yyvsp[-5].expr);
    	printParseInfo("var_decl (array) (var_mutable_flag type_ident LBRACKET RBRACKET IDENTIFIER assign", yylineno, *(yyvsp[-3].string));
    	std::cout << (yyval.var_decl)->getName() << std::endl;
    	delete (yyvsp[-3].string);
        (yyval.var_decl)->line = yylineno;

    }
#line 1718 "./src/core/parser/parser.cpp"
    break;

  case 29: /* var_mutable_flag: VAR  */
#line 299 "./src/core/parser/parser.y"
        { (yyval.boolval) = { true }; }
#line 1724 "./src/core/parser/parser.cpp"
    break;

  case 30: /* var_mutable_flag: IMT  */
#line 300 "./src/core/parser/parser.y"
          { (yyval.boolval) = { false }; }
#line 1730 "./src/core/parser/parser.cpp"
    break;

  case 31: /* var_mutable_flag: %empty  */
#line 301 "./src/core/parser/parser.y"
                  { (yyval.boolval) = { false }; }
#line 1736 "./src/core/parser/parser.cpp"
    break;

  case 32: /* assign_nullable_flag: NULLABLE  */
#line 305 "./src/core/parser/parser.y"
             { (yyval.boolval) = { true }; }
#line 1742 "./src/core/parser/parser.cpp"
    break;

  case 33: /* assign_nullable_flag: NON_NULLABLE  */
#line 306 "./src/core/parser/parser.y"
                   { (yyval.boolval) = { false }; }
#line 1748 "./src/core/parser/parser.cpp"
    break;

  case 34: /* assign_nullable_flag: %empty  */
#line 307 "./src/core/parser/parser.y"
                  { (yyval.boolval) = { false }; }
#line 1754 "./src/core/parser/parser.cpp"
    break;

  case 35: /* extern_decl: EXTERN FUN qualified_name LPAREN var_decl_list RPAREN type_ident SEMICOLON  */
#line 311 "./src/core/parser/parser.y"
                                                                               {
        (yyval.stmt) = new ProtoDecl((yyvsp[-1].ident), (yyvsp[-5].ident), *(yyvsp[-3].varvec));
        delete (yyvsp[-3].varvec);
        (yyval.stmt)->line = yylineno;

        printParseInfo("extern_decl", yylineno);
    }
#line 1766 "./src/core/parser/parser.cpp"
    break;

  case 36: /* function_declaration: FUN qualified_name LPAREN var_decl_list RPAREN block  */
#line 321 "./src/core/parser/parser.y"
                                                         {

        (yyval.stmt) = new FuncDecl(new QualifiedName(), (yyvsp[-4].ident), *(yyvsp[-2].varvec), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;

        delete (yyvsp[-2].varvec);
        printParseInfo("function_declaration (without return type)", yylineno);
    }
#line 1779 "./src/core/parser/parser.cpp"
    break;

  case 37: /* function_declaration: FUN qualified_name LPAREN var_decl_list RPAREN type_ident block  */
#line 329 "./src/core/parser/parser.y"
                                                                       {
        (yyval.stmt) = new FuncDecl((yyvsp[-1].ident), (yyvsp[-5].ident), *(yyvsp[-3].varvec), (yyvsp[0].block));
        delete (yyvsp[-3].varvec);
        (yyval.stmt)->line = yylineno;

        printParseInfo("function_declaration (with return type)", yylineno);
    }
#line 1791 "./src/core/parser/parser.cpp"
    break;

  case 38: /* var_decl_list: %empty  */
#line 339 "./src/core/parser/parser.y"
                     {
    	(yyval.varvec) = new std::vector<VarDecl*>();
    	printParseInfo("var_decl_list (empty list)", yylineno);
    }
#line 1800 "./src/core/parser/parser.cpp"
    break;

  case 39: /* var_decl_list: var_decl  */
#line 343 "./src/core/parser/parser.y"
               {
        (yyval.varvec) = new std::vector<VarDecl*>{(yyvsp[0].var_decl)};
        printParseInfo("var_decl_list (single var_decl)", yylineno);
    }
#line 1809 "./src/core/parser/parser.cpp"
    break;

  case 40: /* var_decl_list: var_decl_list COMMA var_decl  */
#line 347 "./src/core/parser/parser.y"
                                   {
        (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl));
        std::cout << "Added " << (yyvsp[0].var_decl)->name->getName() << " to var_decl_list" << std::endl;
        (yyval.varvec) = (yyvsp[-2].varvec);
        printParseInfo("var_decl_list (multiple var_decl)", yylineno);
    }
#line 1820 "./src/core/parser/parser.cpp"
    break;

  case 41: /* qualified_name: IDENTIFIER  */
#line 356 "./src/core/parser/parser.y"
               {
        (yyval.ident) = new QualifiedName({*(yyvsp[0].string)});
        delete (yyvsp[0].string); // Clean up the string
        (yyval.ident)->line = yylineno;

        printParseInfo("qualified_name (single IDENTIFIER)", yylineno);
    }
#line 1832 "./src/core/parser/parser.cpp"
    break;

  case 42: /* qualified_name: qualified_name DOT IDENTIFIER  */
#line 363 "./src/core/parser/parser.y"
                                    {
        (yyval.ident) = (yyvsp[-2].ident);
        (yyval.ident)->name_parts->push_back(*(yyvsp[0].string));
        delete (yyvsp[0].string); // Clean up the string
        (yyval.ident)->line = yylineno;

        printParseInfo("qualified_name (nested)", yylineno);
    }
#line 1845 "./src/core/parser/parser.cpp"
    break;

  case 43: /* type_ident: qualified_name  */
#line 374 "./src/core/parser/parser.y"
                   {
        (yyval.ident) = (yyvsp[0].ident);
        (yyval.ident)->line = yylineno;

        printParseInfo("type_ident", yylineno);

    }
#line 1857 "./src/core/parser/parser.cpp"
    break;

  case 44: /* type_ident: type_ident TIMES  */
#line 381 "./src/core/parser/parser.y"
                       {
        (yyval.ident) = (yyvsp[-1].ident);
        (yyval.ident)->line = yylineno;
        (yyval.ident)->name_parts->push_back("*");

        printParseInfo("type_ident (pointer)", yylineno);
    }
#line 1869 "./src/core/parser/parser.cpp"
    break;

  case 45: /* binary_expression: expression binary_operator expression  */
#line 391 "./src/core/parser/parser.y"
                                         {
        (yyval.expr) = new BinaryExpr((yyvsp[-1].token), (yyvsp[-2].expr), (yyvsp[0].expr));
        (yyval.expr)->line = yylineno;

        printParseInfo("binary_expression", yylineno);
    }
#line 1880 "./src/core/parser/parser.cpp"
    break;

  case 46: /* expression: INT_TOKEN  */
#line 401 "./src/core/parser/parser.y"
              {
        (yyval.expr) = new IntegerExpr(atol((yyvsp[0].string)->c_str()));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (INT_TOKEN)", yylineno);
    }
#line 1891 "./src/core/parser/parser.cpp"
    break;

  case 47: /* expression: DOUBLE_TOKEN  */
#line 407 "./src/core/parser/parser.y"
                   {
        (yyval.expr) = new DoubleExpr(atof((yyvsp[0].string)->c_str()));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (DOUBLE_TOKEN)", yylineno);
    }
#line 1902 "./src/core/parser/parser.cpp"
    break;

  case 48: /* expression: STRING_LITERAL  */
#line 413 "./src/core/parser/parser.y"
                     {
        printParseInfo("expression (STRING_LITERAL)", yylineno, *(yyvsp[0].string));
        std::string str;
        str = (yyvsp[0].string)->substr(1, (yyvsp[0].string)->length() - 2);
        (yyval.expr) = new StringExpr(str);
        delete (yyvsp[0].string); // Clean up the string
        (yyval.expr)->line = yylineno;

    }
#line 1916 "./src/core/parser/parser.cpp"
    break;

  case 49: /* expression: qualified_name  */
#line 422 "./src/core/parser/parser.y"
                     {
        (yyval.expr) = new VarExpr((yyvsp[0].ident));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (qualified_name)", yylineno, (yyvsp[0].ident)->getName());
    }
#line 1927 "./src/core/parser/parser.cpp"
    break;

  case 50: /* expression: LPAREN expression RPAREN  */
#line 428 "./src/core/parser/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (parenthesized)", yylineno);
    }
#line 1938 "./src/core/parser/parser.cpp"
    break;

  case 51: /* expression: qualified_name LPAREN expr_list RPAREN  */
#line 434 "./src/core/parser/parser.y"
                                             {
        (yyval.expr) = new CallExpr((yyvsp[-3].ident), *(yyvsp[-1].exprvec));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (function call)", yylineno);
    }
#line 1949 "./src/core/parser/parser.cpp"
    break;

  case 52: /* expression: binary_expression  */
#line 440 "./src/core/parser/parser.y"
                        {
	(yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (binary_expression)", yylineno);
    }
#line 1960 "./src/core/parser/parser.cpp"
    break;

  case 53: /* expression: unary_expression  */
#line 446 "./src/core/parser/parser.y"
                       {
        (yyval.expr) = (yyvsp[0].expr);
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (unary_expression)", yylineno);
    }
#line 1971 "./src/core/parser/parser.cpp"
    break;

  case 54: /* expression: LBRACKET expr_list RBRACKET  */
#line 452 "./src/core/parser/parser.y"
                                  {
        (yyval.expr) = new ListExpr((yyvsp[-1].exprvec));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (list)", yylineno);
    }
#line 1982 "./src/core/parser/parser.cpp"
    break;

  case 55: /* expression: qualified_name LBRACKET expression RBRACKET  */
#line 458 "./src/core/parser/parser.y"
                                                  {
        (yyval.expr) = new ArrayExpr((yyvsp[-1].expr), (yyvsp[-3].ident));
        (yyval.expr)->line = yylineno;

        printParseInfo("expression (array access)", yylineno);
    }
#line 1993 "./src/core/parser/parser.cpp"
    break;

  case 56: /* unary_expression: unary_operator expression  */
#line 467 "./src/core/parser/parser.y"
                              {
        (yyval.expr) = new UnaryExpr((yyvsp[-1].token), (yyvsp[0].expr));
        (yyval.expr)->line = yylineno;

        printParseInfo("unary_expression", yylineno);
    }
#line 2004 "./src/core/parser/parser.cpp"
    break;

  case 57: /* binary_operator: PLUS  */
#line 476 "./src/core/parser/parser.y"
         { (yyval.token) = PLUS; }
#line 2010 "./src/core/parser/parser.cpp"
    break;

  case 58: /* binary_operator: MINUS  */
#line 477 "./src/core/parser/parser.y"
            { (yyval.token) = MINUS; }
#line 2016 "./src/core/parser/parser.cpp"
    break;

  case 59: /* binary_operator: TIMES  */
#line 478 "./src/core/parser/parser.y"
            { (yyval.token) = TIMES; }
#line 2022 "./src/core/parser/parser.cpp"
    break;

  case 60: /* binary_operator: DIVIDE  */
#line 479 "./src/core/parser/parser.y"
             { (yyval.token) = DIVIDE; }
#line 2028 "./src/core/parser/parser.cpp"
    break;

  case 61: /* binary_operator: MOD  */
#line 480 "./src/core/parser/parser.y"
          { (yyval.token) = MOD; }
#line 2034 "./src/core/parser/parser.cpp"
    break;

  case 62: /* binary_operator: LT  */
#line 481 "./src/core/parser/parser.y"
         { (yyval.token) = LT; }
#line 2040 "./src/core/parser/parser.cpp"
    break;

  case 63: /* binary_operator: LE  */
#line 482 "./src/core/parser/parser.y"
         { (yyval.token) = LE; }
#line 2046 "./src/core/parser/parser.cpp"
    break;

  case 64: /* binary_operator: GT  */
#line 483 "./src/core/parser/parser.y"
         { (yyval.token) = GT; }
#line 2052 "./src/core/parser/parser.cpp"
    break;

  case 65: /* binary_operator: GE  */
#line 484 "./src/core/parser/parser.y"
         { (yyval.token) = GE; }
#line 2058 "./src/core/parser/parser.cpp"
    break;

  case 66: /* binary_operator: EQ  */
#line 485 "./src/core/parser/parser.y"
         { (yyval.token) = EQ; }
#line 2064 "./src/core/parser/parser.cpp"
    break;

  case 67: /* binary_operator: NE  */
#line 486 "./src/core/parser/parser.y"
         { (yyval.token) = NE; }
#line 2070 "./src/core/parser/parser.cpp"
    break;

  case 68: /* binary_operator: AND  */
#line 487 "./src/core/parser/parser.y"
          { (yyval.token) = AND; }
#line 2076 "./src/core/parser/parser.cpp"
    break;

  case 69: /* binary_operator: OR  */
#line 488 "./src/core/parser/parser.y"
         { (yyval.token) = OR; }
#line 2082 "./src/core/parser/parser.cpp"
    break;

  case 70: /* binary_operator: PLUS_ASSIGN  */
#line 489 "./src/core/parser/parser.y"
                  { (yyval.token) = PLUS_ASSIGN; }
#line 2088 "./src/core/parser/parser.cpp"
    break;

  case 71: /* binary_operator: MINUS_ASSIGN  */
#line 490 "./src/core/parser/parser.y"
                   { (yyval.token) = MINUS_ASSIGN; }
#line 2094 "./src/core/parser/parser.cpp"
    break;

  case 72: /* binary_operator: TIMES_ASSIGN  */
#line 491 "./src/core/parser/parser.y"
                   { (yyval.token) = TIMES_ASSIGN; }
#line 2100 "./src/core/parser/parser.cpp"
    break;

  case 73: /* binary_operator: DIVIDE_ASSIGN  */
#line 492 "./src/core/parser/parser.y"
                    { (yyval.token) = DIVIDE_ASSIGN; }
#line 2106 "./src/core/parser/parser.cpp"
    break;

  case 74: /* binary_operator: MOD_ASSIGN  */
#line 493 "./src/core/parser/parser.y"
                 { (yyval.token) = MOD_ASSIGN; }
#line 2112 "./src/core/parser/parser.cpp"
    break;

  case 75: /* binary_operator: LSHIFT  */
#line 494 "./src/core/parser/parser.y"
             { (yyval.token) = LSHIFT; }
#line 2118 "./src/core/parser/parser.cpp"
    break;

  case 76: /* binary_operator: RSHIFT  */
#line 495 "./src/core/parser/parser.y"
             { (yyval.token) = RSHIFT; }
#line 2124 "./src/core/parser/parser.cpp"
    break;

  case 77: /* binary_operator: URSHIFT  */
#line 496 "./src/core/parser/parser.y"
              { (yyval.token) = URSHIFT; }
#line 2130 "./src/core/parser/parser.cpp"
    break;

  case 78: /* binary_operator: XOR  */
#line 497 "./src/core/parser/parser.y"
          { (yyval.token) = XOR; }
#line 2136 "./src/core/parser/parser.cpp"
    break;

  case 79: /* unary_operator: MINUS  */
#line 501 "./src/core/parser/parser.y"
          { (yyval.token) = MINUS; }
#line 2142 "./src/core/parser/parser.cpp"
    break;

  case 80: /* unary_operator: PLUS  */
#line 502 "./src/core/parser/parser.y"
           { (yyval.token) = PLUS; }
#line 2148 "./src/core/parser/parser.cpp"
    break;

  case 81: /* unary_operator: NOT  */
#line 503 "./src/core/parser/parser.y"
          { (yyval.token) = NOT; }
#line 2154 "./src/core/parser/parser.cpp"
    break;

  case 82: /* unary_operator: INC  */
#line 504 "./src/core/parser/parser.y"
          { (yyval.token) = INC; }
#line 2160 "./src/core/parser/parser.cpp"
    break;

  case 83: /* unary_operator: DEC  */
#line 505 "./src/core/parser/parser.y"
          { (yyval.token) = DEC; }
#line 2166 "./src/core/parser/parser.cpp"
    break;

  case 84: /* unary_operator: TIMES  */
#line 506 "./src/core/parser/parser.y"
            { (yyval.token) = TIMES; }
#line 2172 "./src/core/parser/parser.cpp"
    break;

  case 85: /* unary_operator: BIT_AND  */
#line 507 "./src/core/parser/parser.y"
              { (yyval.token) = BIT_AND; }
#line 2178 "./src/core/parser/parser.cpp"
    break;

  case 86: /* expr_list: %empty  */
#line 511 "./src/core/parser/parser.y"
                {
        (yyval.exprvec) = new std::vector<Expr*>();
        printParseInfo("expr_list (empty)", yylineno);
    }
#line 2187 "./src/core/parser/parser.cpp"
    break;

  case 87: /* expr_list: expression  */
#line 515 "./src/core/parser/parser.y"
                {
        (yyval.exprvec) = new std::vector<Expr*>{(yyvsp[0].expr)};
        printParseInfo("expr_list (singleexpression)", yylineno);
    }
#line 2196 "./src/core/parser/parser.cpp"
    break;

  case 88: /* expr_list: expr_list COMMA expression  */
#line 519 "./src/core/parser/parser.y"
                                {
        (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr));
        (yyval.exprvec) = (yyvsp[-2].exprvec);
        printParseInfo("expr_list (multipleexpressions)", yylineno);
    }
#line 2206 "./src/core/parser/parser.cpp"
    break;

  case 89: /* if_statement: IF expression block  */
#line 527 "./src/core/parser/parser.y"
                        {
        (yyval.stmt) = new IfStmt((yyvsp[-1].expr), (yyvsp[0].block), nullptr);
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (no else)", yylineno);
    }
#line 2217 "./src/core/parser/parser.cpp"
    break;

  case 90: /* if_statement: IF expression block ELSE block  */
#line 533 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new IfStmt((yyvsp[-3].expr), (yyvsp[-2].block), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (with else)", yylineno);
    }
#line 2228 "./src/core/parser/parser.cpp"
    break;

  case 91: /* if_statement: IF expression block elif_stmts  */
#line 539 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new IfStmt((yyvsp[-2].expr), (yyvsp[-1].block), nullptr, dynamic_cast<IfStmt*>((yyvsp[0].stmt)));
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (with elif_stmts)", yylineno);
    }
#line 2239 "./src/core/parser/parser.cpp"
    break;

  case 92: /* if_statement: IF expression block elif_stmts ELSE block  */
#line 545 "./src/core/parser/parser.y"
                                                {
        (yyval.stmt) = new IfStmt((yyvsp[-4].expr), (yyvsp[-3].block), (yyvsp[0].block), dynamic_cast<IfStmt*>((yyvsp[-2].stmt)));
        (yyval.stmt)->line = yylineno;

        printParseInfo("if_statement (with elif_stmts)", yylineno);
    }
#line 2250 "./src/core/parser/parser.cpp"
    break;

  case 93: /* elif_stmts: elif_statement  */
#line 554 "./src/core/parser/parser.y"
                   {
        (yyvsp[0].stmt)->line = yylineno;
        (yyval.stmt) = (yyvsp[0].stmt);

        printParseInfo("elif_stmts (empty)", yylineno);
    }
#line 2261 "./src/core/parser/parser.cpp"
    break;

  case 94: /* elif_stmts: elif_statement elif_stmts  */
#line 560 "./src/core/parser/parser.y"
                                {
        auto res = dynamic_cast<IfStmt*>((yyvsp[-1].stmt));
        res->elseIf = dynamic_cast<IfStmt*>((yyvsp[0].stmt));
        res->line = yylineno;
        (yyval.stmt) = res;
        printParseInfo("elif_stmts (with elif_statement)", yylineno);
    }
#line 2273 "./src/core/parser/parser.cpp"
    break;

  case 95: /* elif_statement: ELIF expression block  */
#line 570 "./src/core/parser/parser.y"
                          {
        (yyval.stmt) = new IfStmt((yyvsp[-1].expr), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;
        printParseInfo("elif_statement", yylineno);
    }
#line 2283 "./src/core/parser/parser.cpp"
    break;

  case 96: /* for_statement: FOR for_var_decl SEMICOLON expression SEMICOLON expression block  */
#line 578 "./src/core/parser/parser.y"
                                                                     {
        (yyval.stmt) = new ForStmt((yyvsp[-5].var_decl), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[0].block));
        (yyval.stmt)->line = yylineno;
        printParseInfo("for_statement", yylineno);
    }
#line 2293 "./src/core/parser/parser.cpp"
    break;

  case 97: /* break_statement: BREAK  */
#line 586 "./src/core/parser/parser.y"
          {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new BreakStmt();
        printParseInfo("break_statement", yylineno);
    }
#line 2303 "./src/core/parser/parser.cpp"
    break;

  case 98: /* break_statement: BREAK expression  */
#line 591 "./src/core/parser/parser.y"
                       {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new BreakStmt((yyvsp[0].expr));
        printParseInfo("break_statement", yylineno);
    }
#line 2313 "./src/core/parser/parser.cpp"
    break;

  case 99: /* for_var_decl: type_ident IDENTIFIER ASSIGN expression  */
#line 599 "./src/core/parser/parser.y"
                                            {
        (yyval.var_decl) = new VarDecl((yyvsp[-3].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[-2].string)})), true, true, (yyvsp[0].expr));
        printParseInfo("for_var_decl (type_ident qualified_name IDENTIFIER ASSIGN expression)", yylineno);
    }
#line 2322 "./src/core/parser/parser.cpp"
    break;

  case 100: /* for_var_decl: type_ident IDENTIFIER  */
#line 603 "./src/core/parser/parser.y"
                            {
        (yyval.var_decl) = new VarDecl((yyvsp[-1].ident), new QualifiedName(new std::vector<std::string>({*(yyvsp[0].string)})), true, true, nullptr);
        printParseInfo("for_var_decl (type_ident qualified_name IDENTIFIER)", yylineno);
    }
#line 2331 "./src/core/parser/parser.cpp"
    break;

  case 101: /* struct_decl: STRUCT IDENTIFIER LBRACE struct_field_list RBRACE SEMICOLON  */
#line 610 "./src/core/parser/parser.y"
                                                                {
        (yyval.stmt)->line = yylineno;
        (yyval.stmt) = new StructDecl(new QualifiedName({*(yyvsp[-4].string)}), *(yyvsp[-2].varvec));
        delete (yyvsp[-4].string);
        delete (yyvsp[-2].varvec);
        printParseInfo("struct_decl", yylineno);
    }
#line 2343 "./src/core/parser/parser.cpp"
    break;

  case 102: /* struct_field_list: %empty  */
#line 620 "./src/core/parser/parser.y"
                {
        (yyval.varvec) = new std::vector<VarDecl*>();
        printParseInfo("struct_field_list (empty)", yylineno);
    }
#line 2352 "./src/core/parser/parser.cpp"
    break;

  case 103: /* struct_field_list: struct_field_list var_decl SEMICOLON  */
#line 624 "./src/core/parser/parser.y"
                                           {
        (yyvsp[-2].varvec)->push_back((yyvsp[-1].var_decl));
        (yyval.varvec) = (yyvsp[-2].varvec);
        printParseInfo("struct_field_list (with var_decl)", yylineno);
    }
#line 2362 "./src/core/parser/parser.cpp"
    break;

  case 104: /* assign_expr: qualified_name ASSIGN expression  */
#line 632 "./src/core/parser/parser.y"
                                     {
        (yyval.stmt) = new AssignExpr((yyvsp[-2].ident), (yyvsp[0].expr));
        (yyval.stmt)->line = yylineno;
        printParseInfo("assignment", yylineno);
    }
#line 2372 "./src/core/parser/parser.cpp"
    break;

  case 105: /* array_assign_stmt: qualified_name LBRACKET expression RBRACKET ASSIGN expression SEMICOLON  */
#line 640 "./src/core/parser/parser.y"
                                                                            {
        (yyval.stmt) = new ArrayAssignExpr((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-1].expr));
        (yyval.stmt)->line = yylineno;
        printParseInfo("array_assign_expr", yylineno);
    }
#line 2382 "./src/core/parser/parser.cpp"
    break;


#line 2386 "./src/core/parser/parser.cpp"

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

#line 647 "./src/core/parser/parser.y"
