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

#include "node.h"
#include "compiler/parser/parser.hpp"
#include "compiler/common/define_d.h"
#include <string>
#include <cstring>
#include "compiler/utilities/file_util.h"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng); \
    std::cout << "Token: " << yytext << " size: " << std::to_string(yyleng) << std::endl;\
    for (int i = 0;i < 2147483647; ++i ) { \
        if (yytext[i]!= '\0') { yytext[i] = '\0'; } \
        else { break; }\
    }
#define TOKEN(t)    (yylval.token = t)

int llcolumn = 0;

// Function to handle string literals
std::string *handle_string_literal(const char *str) {
    std::string *result = new std::string(str);
    return result;
}

#line 96 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

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
    LITERAL = 291,                 /* LITERAL  */
    FLOAT_LITERAL = 292,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 293,          /* STRING_LITERAL  */
    CHAR_LITERAL = 294,            /* CHAR_LITERAL  */
    ASSIGN = 295,                  /* ASSIGN  */
    ADD_ASSIGN = 296,              /* ADD_ASSIGN  */
    MINUS_ASSIGN = 297,            /* MINUS_ASSIGN  */
    INCREMENT = 298,               /* INCREMENT  */
    LESS_THAN = 299,               /* LESS_THAN  */
    COMMA = 300,                   /* COMMA  */
    SEMICOLON = 301,               /* SEMICOLON  */
    COLON = 302,                   /* COLON  */
    LEFT_BRACE = 303,              /* LEFT_BRACE  */
    RIGHT_BRACE = 304,             /* RIGHT_BRACE  */
    LEFT_PAREN = 305,              /* LEFT_PAREN  */
    RIGHT_PAREN = 306,             /* RIGHT_PAREN  */
    LEFT_BRACKET = 307,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 308,           /* RIGHT_BRACKET  */
    DOT = 309,                     /* DOT  */
    ELLIPSIS = 310,                /* ELLIPSIS  */
    QUESTION = 311,                /* QUESTION  */
    BANG = 312                     /* BANG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_FLOAT = 23,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 24,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_UINT = 26,                      /* UINT  */
  YYSYMBOL_USHORT = 27,                    /* USHORT  */
  YYSYMBOL_ULONG = 28,                     /* ULONG  */
  YYSYMBOL_LLLONG = 29,                    /* LLLONG  */
  YYSYMBOL_ULLONG = 30,                    /* ULLONG  */
  YYSYMBOL_IDENTIFIER = 31,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 32,                   /* INTEGER  */
  YYSYMBOL_BINARY_LITERAL = 33,            /* BINARY_LITERAL  */
  YYSYMBOL_OCTAL_LITERAL = 34,             /* OCTAL_LITERAL  */
  YYSYMBOL_HEXADECIMAL_LITERAL = 35,       /* HEXADECIMAL_LITERAL  */
  YYSYMBOL_LITERAL = 36,                   /* LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 37,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 38,            /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 39,              /* CHAR_LITERAL  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 41,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 42,              /* MINUS_ASSIGN  */
  YYSYMBOL_INCREMENT = 43,                 /* INCREMENT  */
  YYSYMBOL_LESS_THAN = 44,                 /* LESS_THAN  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_LEFT_BRACE = 48,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 49,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_PAREN = 50,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 51,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_BRACKET = 52,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 53,             /* RIGHT_BRACKET  */
  YYSYMBOL_DOT = 54,                       /* DOT  */
  YYSYMBOL_ELLIPSIS = 55,                  /* ELLIPSIS  */
  YYSYMBOL_QUESTION = 56,                  /* QUESTION  */
  YYSYMBOL_BANG = 57,                      /* BANG  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_package_declaration = 60,       /* package_declaration  */
  YYSYMBOL_import_declarations = 61,       /* import_declarations  */
  YYSYMBOL_import_declaration = 62,        /* import_declaration  */
  YYSYMBOL_function_declarations = 63,     /* function_declarations  */
  YYSYMBOL_function_declaration = 64,      /* function_declaration  */
  YYSYMBOL_parameter_list = 65,            /* parameter_list  */
  YYSYMBOL_parameter = 66,                 /* parameter  */
  YYSYMBOL_return_type = 67,               /* return_type  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_statement_list = 70,            /* statement_list  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_variable_declaration = 72,      /* variable_declaration  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_for_loop = 74,                  /* for_loop  */
  YYSYMBOL_if_statement = 75,              /* if_statement  */
  YYSYMBOL_match_statement = 76,           /* match_statement  */
  YYSYMBOL_match_case_list = 77,           /* match_case_list  */
  YYSYMBOL_match_case = 78,                /* match_case  */
  YYSYMBOL_struct_declarations = 79,       /* struct_declarations  */
  YYSYMBOL_struct_declaration = 80,        /* struct_declaration  */
  YYSYMBOL_struct_member_list = 81,        /* struct_member_list  */
  YYSYMBOL_struct_member = 82,             /* struct_member  */
  YYSYMBOL_trait_declarations = 83,        /* trait_declarations  */
  YYSYMBOL_trait_declaration = 84,         /* trait_declaration  */
  YYSYMBOL_trait_method_list = 85,         /* trait_method_list  */
  YYSYMBOL_trait_method = 86,              /* trait_method  */
  YYSYMBOL_type_definitions = 87,          /* type_definitions  */
  YYSYMBOL_type_definition = 88            /* type_definition  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    75,    78,    84,    93,    99,   105,   114,
     120,   130,   136,   141,   147,   153,   162,   165,   171,   174,
     177,   180,   183,   186,   189,   192,   195,   198,   201,   204,
     207,   210,   216,   224,   230,   236,   239,   242,   245,   248,
     251,   260,   268,   276,   282,   291,   294,   297,   300,   303,
     306,   309,   312,   315,   321,   326,   332,   340,   355,   362,
     374,   384,   390,   396,   402,   411,   420,   426,   431,   438,
     444,   449,   455,   461,   470,   479,   485,   490,   497,   503,
     508,   514,   523,   532,   538
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
  "LONG", "CHAR", "FLOAT", "DOUBLE", "BOOL", "UINT", "USHORT", "ULONG",
  "LLLONG", "ULLONG", "IDENTIFIER", "INTEGER", "BINARY_LITERAL",
  "OCTAL_LITERAL", "HEXADECIMAL_LITERAL", "LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "CHAR_LITERAL", "ASSIGN", "ADD_ASSIGN", "MINUS_ASSIGN",
  "INCREMENT", "LESS_THAN", "COMMA", "SEMICOLON", "COLON", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "DOT", "ELLIPSIS", "QUESTION", "BANG", "$accept",
  "program", "package_declaration", "import_declarations",
  "import_declaration", "function_declarations", "function_declaration",
  "parameter_list", "parameter", "return_type", "type", "block",
  "statement_list", "statement", "variable_declaration", "expression",
  "for_loop", "if_statement", "match_statement", "match_case_list",
  "match_case", "struct_declarations", "struct_declaration",
  "struct_member_list", "struct_member", "trait_declarations",
  "trait_declaration", "trait_method_list", "trait_method",
  "type_definitions", "type_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -14,    45,    15,   -24,  -119,    -5,    38,    15,  -119,
      18,    35,    67,    38,  -119,  -119,    33,    54,    81,    67,
    -119,    22,    40,    58,   100,    81,  -119,   110,   110,    39,
      72,   -11,    70,   110,  -119,   100,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    89,    92,    76,    22,   110,   110,  -119,    94,    79,
      -3,    95,  -119,  -119,  -119,  -119,   102,  -119,  -119,   121,
     122,  -119,    26,   123,  -119,   106,   111,  -119,    42,  -119,
    -119,  -119,  -119,   108,  -119,   151,   110,   109,   112,   110,
     110,    77,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      77,   114,    42,   115,   -16,  -119,  -119,  -119,    22,  -119,
     129,    77,    77,   133,   134,    78,   -28,  -119,  -119,  -119,
      77,  -119,    77,  -119,   116,   126,    10,    19,   128,   130,
    -119,  -119,    28,  -119,    76,    77,   102,   -26,    77,    77,
    -119,   101,   160,   124,   125,  -119,   -26,   -33,   -33,    77,
     102,   102,   127,  -119,   105,  -119,  -119,   102,    77,  -119,
      43,  -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     6,     0,     1,     0,     9,     6,     3,
       0,     0,    66,     9,     5,     7,     0,     0,    75,    66,
       8,    13,     0,     0,    83,    75,    65,     0,     0,     0,
      12,     0,     0,     0,     2,    83,    74,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,    13,     0,     0,    68,     0,     0,
       0,     0,    82,    14,    15,    17,     0,    16,    11,     0,
       0,    67,    70,     0,    77,     0,     0,    84,    34,    10,
      72,    73,    69,     0,    76,    79,     0,     0,     0,     0,
       0,     0,    52,    45,    46,    47,    48,    49,    50,    51,
       0,     0,    34,     0,     0,    37,    38,    39,    13,    78,
       0,     0,     0,     0,     0,     0,     0,    32,    33,    35,
       0,    54,     0,    36,     0,     0,     0,     0,    43,    44,
      40,    56,    53,    55,     0,     0,     0,    62,     0,     0,
      81,     0,    58,     0,     0,    60,    62,    41,    42,     0,
       0,     0,     0,    61,     0,    59,    63,     0,     0,    64,
       0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   164,  -119,   162,  -119,   -53,  -119,    44,
     -21,  -118,    71,  -119,  -119,   -91,  -119,  -119,  -119,    31,
    -119,   161,  -119,   107,  -119,   156,  -119,    97,  -119,   148,
    -119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,     8,    12,    13,    29,    30,    66,
      67,    79,   101,   102,   103,   104,   105,   106,   107,   145,
     146,    18,    19,    58,    59,    24,    25,    75,    76,    34,
      35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     115,    68,    73,    55,    56,   143,    51,    52,   120,   116,
     121,   122,    61,   120,     1,   121,   122,     4,   142,     6,
     126,   127,     9,   131,   144,   120,    10,   121,   122,   132,
     123,   133,   155,   156,    69,    70,    27,    28,    57,   159,
      55,    56,   161,    11,   141,     5,    74,   147,   148,    86,
      87,   120,    88,   121,   122,   124,    89,    90,   154,    91,
     120,   136,   121,   122,    15,   110,    16,   160,   113,   114,
     137,   121,   122,    92,    93,    94,    95,    96,    17,    97,
      98,    99,    65,    21,   120,    22,   121,   122,    31,    32,
      53,    78,   100,    23,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    92,    93,
      94,    95,    96,    33,    97,    98,    99,    54,    60,   120,
      63,   121,   122,    64,   130,    72,    77,   100,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,   120,    71,   121,   122,   120,   149,   121,   122,
      78,   158,    80,    81,    83,    84,    73,    85,   108,   111,
     125,   119,   112,   117,   128,   129,   135,   134,   138,   150,
     139,   151,    14,   118,   157,    20,   152,   153,   140,    82,
      26,    36,   109,    62
};

static const yytype_uint8 yycheck[] =
{
      91,    54,     5,    14,    15,    31,    27,    28,    41,   100,
      43,    44,    33,    41,     3,    43,    44,    31,   136,     4,
     111,   112,    46,    51,    50,    41,    31,    43,    44,   120,
      46,   122,   150,   151,    55,    56,    14,    15,    49,   157,
      14,    15,   160,     5,   135,     0,    49,   138,   139,     7,
       8,    41,    10,    43,    44,   108,    14,    15,   149,    17,
      41,    51,    43,    44,    46,    86,    31,   158,    89,    90,
      51,    43,    44,    31,    32,    33,    34,    35,    11,    37,
      38,    39,     6,    50,    41,    31,    43,    44,    48,    31,
      51,    48,    50,    12,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    31,    32,
      33,    34,    35,    13,    37,    38,    39,    45,    48,    41,
      31,    43,    44,    31,    46,    46,    31,    50,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    41,    49,    43,    44,    41,    46,    43,    44,
      48,    46,    31,    31,    31,    49,     5,    46,    50,    50,
      31,    46,    50,    49,    31,    31,    40,    51,    40,     9,
      40,    47,     8,   102,    47,    13,    51,   146,   134,    72,
      19,    25,    85,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,    60,    31,     0,     4,    61,    62,    46,
      31,     5,    63,    64,    61,    46,    31,    11,    79,    80,
      63,    50,    31,    12,    83,    84,    79,    14,    15,    65,
      66,    48,    31,    13,    87,    88,    83,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    68,    68,    51,    45,    14,    15,    49,    81,    82,
      48,    68,    87,    31,    31,     6,    67,    68,    65,    68,
      68,    49,    46,     5,    49,    85,    86,    31,    48,    69,
      31,    31,    81,    31,    49,    46,     7,     8,    10,    14,
      15,    17,    31,    32,    33,    34,    35,    37,    38,    39,
      50,    70,    71,    72,    73,    74,    75,    76,    50,    85,
      68,    50,    50,    68,    68,    73,    73,    49,    70,    46,
      41,    43,    44,    46,    65,    31,    73,    73,    31,    31,
      46,    51,    73,    73,    51,    40,    51,    51,    40,    40,
      67,    73,    69,    31,    50,    77,    78,    73,    73,    46,
       9,    47,    51,    77,    73,    69,    69,    47,    46,    69,
      73,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    75,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    86,    87,    87,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     3,     0,     2,     0,     3,     2,     0,
       7,     3,     1,     0,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     0,     2,     2,     1,     1,     1,
       3,     5,     5,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,    10,     5,     7,
       5,     2,     0,     3,     4,     2,     0,     5,     4,     3,
       2,     0,     3,     3,     2,     0,     5,     4,     3,     2,
       0,     6,     2,     0,     3
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
  case 2: /* program: package_declaration import_declarations function_declarations struct_declarations trait_declarations type_definitions  */
#line 43 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                                                            {
        yyval = new Node("program", "");
        if (yyvsp[-5]) yyval->children.push_back(yyvsp[-5]);
        if (yyvsp[-4]) {
            for (auto child : *static_cast<vector<Node*>*>( yyvsp[-4])) {
                yyval->children.push_back(child);
            }
        }
        if (yyvsp[-3]) {
            for (auto child : *static_cast<vector<Node*>*>( yyvsp[-3])) {
                yyval->children.push_back(child);
            }
        }
        if (yyvsp[-2]) {
            for (auto child : *static_cast<vector<Node*>*>( yyvsp[-2])) {
                yyval->children.push_back(child);
            }
        }
        if (yyvsp[-1]) {
            for (auto child : *static_cast<vector<Node*>*>( yyvsp[-1])) {
                yyval->children.push_back(child);
            }
        }
        if (yyvsp[0]) {
            for (auto child : *static_cast<vector<Node*>*>( yyvsp[0])) {
                yyval->children.push_back(child);
            }
        }
    }
#line 1413 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 3: /* package_declaration: PACKAGE IDENTIFIER SEMICOLON  */
#line 75 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                   {
        yyval = new Node("package_declaration", yyvsp[-1]->value);
    }
#line 1421 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 4: /* package_declaration: %empty  */
#line 78 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = nullptr;
    }
#line 1429 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 5: /* import_declarations: import_declaration import_declarations  */
#line 84 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                             {
        vector<Node*>* v = new vector<Node*>();
        v->push_back(yyvsp[-1]);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( yyvsp[0]);
        for (auto child : *v2) {
            v->push_back(child);
        }
        yyval = v;
    }
#line 1443 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 6: /* import_declarations: %empty  */
#line 93 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new vector<Node*>();
    }
#line 1451 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 7: /* import_declaration: IMPORT IDENTIFIER SEMICOLON  */
#line 99 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                  {
        yyval = new Node("import_declaration", yyvsp[-1]->value);
    }
#line 1459 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 8: /* function_declarations: function_declaration function_declarations  */
#line 105 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                 {
        vector<Node*>* v = new vector<Node*>();
        v->push_back(yyvsp[-1]);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( yyvsp[0]);
        for (auto child : *v2) {
            v->push_back(child);
        }
        yyval = v;
    }
#line 1473 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 9: /* function_declarations: %empty  */
#line 114 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new vector<Node*>();
    }
#line 1481 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 10: /* function_declaration: FUN IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN return_type block  */
#line 120 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                             {
        Node* funcNode = new Node("function_declaration", yyvsp[-5]->value);
        funcNode->children.push_back(yyvsp[-3]);
        funcNode->children.push_back(yyvsp[-1]);
        funcNode->children.push_back(yyvsp[0]);
        yyval = funcNode;
    }
#line 1493 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 11: /* parameter_list: parameter COMMA parameter_list  */
#line 130 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                     {
        Node* paramListNode = new Node("parameter_list", "");
        paramListNode->children.push_back(yyvsp[-2]);
        paramListNode->children.push_back(yyvsp[0]);
        yyval = paramListNode;
    }
#line 1504 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 12: /* parameter_list: parameter  */
#line 136 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                {
        Node* paramListNode = new Node("parameter_list", "");
        paramListNode->children.push_back(yyvsp[0]);
        yyval = paramListNode;
    }
#line 1514 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 13: /* parameter_list: %empty  */
#line 141 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new Node("parameter_list", "");
    }
#line 1522 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 14: /* parameter: IMT type IDENTIFIER  */
#line 147 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* paramNode = new Node("parameter", yyvsp[0]->value);
        paramNode->children.push_back(new Node("modifier", "imt"));
        paramNode->children.push_back(yyvsp[-1]);
        yyval = paramNode;
    }
#line 1533 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 15: /* parameter: VAR type IDENTIFIER  */
#line 153 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* paramNode = new Node("parameter", yyvsp[0]->value);
        paramNode->children.push_back(new Node("modifier", "var"));
        paramNode->children.push_back(yyvsp[-1]);
        yyval = paramNode;
    }
#line 1544 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 16: /* return_type: type  */
#line 162 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = yyvsp[0];
    }
#line 1552 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 17: /* return_type: VOID  */
#line 165 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("return_type", "void");
    }
#line 1560 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 18: /* type: INT  */
#line 171 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
          {
        yyval = new Node("type", "int");
    }
#line 1568 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 19: /* type: BYTE  */
#line 174 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("type", "byte");
    }
#line 1576 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 20: /* type: SHORT  */
#line 177 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        yyval = new Node("type", "short");
    }
#line 1584 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 21: /* type: LONG  */
#line 180 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("type", "long");
    }
#line 1592 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 22: /* type: CHAR  */
#line 183 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("type", "char");
    }
#line 1600 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 23: /* type: FLOAT  */
#line 186 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        yyval = new Node("type", "float");
    }
#line 1608 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 24: /* type: DOUBLE  */
#line 189 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        yyval = new Node("type", "double");
    }
#line 1616 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 25: /* type: BOOL  */
#line 192 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("type", "bool");
    }
#line 1624 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 26: /* type: UINT  */
#line 195 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
           {
        yyval = new Node("type", "uint");
    }
#line 1632 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 27: /* type: USHORT  */
#line 198 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        yyval = new Node("type", "ushort");
    }
#line 1640 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 28: /* type: ULONG  */
#line 201 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
            {
        yyval = new Node("type", "ulong");
    }
#line 1648 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 29: /* type: LLLONG  */
#line 204 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        yyval = new Node("type", "lllong");
    }
#line 1656 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 30: /* type: ULLONG  */
#line 207 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
             {
        yyval = new Node("type", "ullong");
    }
#line 1664 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 31: /* type: IDENTIFIER  */
#line 210 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        yyval = new Node("type", yyvsp[0]->value);
    }
#line 1672 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 32: /* block: LEFT_BRACE statement_list RIGHT_BRACE  */
#line 216 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                            {
        Node* blockNode = new Node("block", "");
        blockNode->children.push_back(yyvsp[-1]);
        yyval = blockNode;
    }
#line 1682 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 33: /* statement_list: statement statement_list  */
#line 224 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                               {
        Node* stmtListNode = new Node("statement_list", "");
        stmtListNode->children.push_back(yyvsp[-1]);
        stmtListNode->children.push_back(yyvsp[0]);
        yyval = stmtListNode;
    }
#line 1693 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 34: /* statement_list: %empty  */
#line 230 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new Node("statement_list", "");
    }
#line 1701 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 35: /* statement: variable_declaration SEMICOLON  */
#line 236 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                     {
        yyval = yyvsp[-1];
    }
#line 1709 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 36: /* statement: expression SEMICOLON  */
#line 239 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                           {
        yyval = yyvsp[-1];
    }
#line 1717 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 37: /* statement: for_loop  */
#line 242 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
               {
        yyval = yyvsp[0];
    }
#line 1725 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 38: /* statement: if_statement  */
#line 245 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        yyval = yyvsp[0];
    }
#line 1733 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 39: /* statement: match_statement  */
#line 248 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                      {
        yyval = yyvsp[0];
    }
#line 1741 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 40: /* statement: RETURN expression SEMICOLON  */
#line 251 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                  {
        Node* returnStmtNode = new Node("return_statement", "");
        returnStmtNode->children.push_back(new Node("keyword", "return"));
        returnStmtNode->children.push_back(yyvsp[-1]);
        yyval = returnStmtNode;
    }
#line 1752 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 41: /* variable_declaration: IMT type IDENTIFIER ASSIGN expression  */
#line 260 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                            {
        Node* varDeclNode = new Node("variable_declaration", yyvsp[-2]->value);
        varDeclNode->children.push_back(new Node("modifier", "imt"));
        varDeclNode->children.push_back(yyvsp[-3]);
        varDeclNode->children.push_back(new Node("operator", "="));
        varDeclNode->children.push_back(yyvsp[0]);
        yyval = varDeclNode;
    }
#line 1765 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 42: /* variable_declaration: VAR type IDENTIFIER ASSIGN expression  */
#line 268 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                            {
        Node* varDeclNode = new Node("variable_declaration", yyvsp[-2]->value);
        varDeclNode->children.push_back(new Node("modifier", "var"));
        varDeclNode->children.push_back(yyvsp[-3]);
        varDeclNode->children.push_back(new Node("operator", "="));
        varDeclNode->children.push_back(yyvsp[0]);
        yyval = varDeclNode;
    }
#line 1778 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 43: /* variable_declaration: IMT type IDENTIFIER  */
#line 276 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* varDeclNode = new Node("variable_declaration", yyvsp[0]->value);
        varDeclNode->children.push_back(new Node("modifier", "imt"));
        varDeclNode->children.push_back(yyvsp[-1]);
        yyval = varDeclNode;
    }
#line 1789 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 44: /* variable_declaration: VAR type IDENTIFIER  */
#line 282 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* varDeclNode = new Node("variable_declaration", yyvsp[0]->value);
        varDeclNode->children.push_back(new Node("modifier", "var"));
        varDeclNode->children.push_back(yyvsp[-1]);
        yyval = varDeclNode;
    }
#line 1800 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 45: /* expression: INTEGER  */
#line 291 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
              {
        yyval = new Node("expression", to_string(yyvsp[0]->integer));
    }
#line 1808 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 46: /* expression: BINARY_LITERAL  */
#line 294 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                     {
        yyval = new Node("expression", to_string(yyvsp[0]->integer));
    }
#line 1816 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 47: /* expression: OCTAL_LITERAL  */
#line 297 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                    {
        yyval = new Node("expression", to_string(yyvsp[0]->integer));
    }
#line 1824 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 48: /* expression: HEXADECIMAL_LITERAL  */
#line 300 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        yyval = new Node("expression", to_string(yyvsp[0]->integer));
    }
#line 1832 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 49: /* expression: FLOAT_LITERAL  */
#line 303 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                    {
        yyval = new Node("expression", to_string(yyvsp[0]->float_val));
    }
#line 1840 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 50: /* expression: STRING_LITERAL  */
#line 306 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                     {
        yyval = new Node("expression", yyvsp[0]->string->c_str());
    }
#line 1848 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 51: /* expression: CHAR_LITERAL  */
#line 309 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                   {
        yyval = new Node("expression", string(1, yyvsp[0]->char_val));
    }
#line 1856 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 52: /* expression: IDENTIFIER  */
#line 312 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                 {
        yyval = new Node("expression", yyvsp[0]->value);
    }
#line 1864 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 53: /* expression: expression ADD_ASSIGN expression  */
#line 315 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                       {
        Node* expNode = new Node("expression", "+=");
        expNode->children.push_back(yyvsp[-2]);
        expNode->children.push_back(yyvsp[0]);
        yyval = expNode;
    }
#line 1875 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 54: /* expression: expression INCREMENT  */
#line 321 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                           {
        Node* expNode = new Node("expression", "++");
        expNode->children.push_back(yyvsp[-1]);
        yyval = expNode;
    }
#line 1885 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 55: /* expression: expression LESS_THAN expression  */
#line 326 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                      {
        Node* expNode = new Node("expression", "<");
        expNode->children.push_back(yyvsp[-2]);
        expNode->children.push_back(yyvsp[0]);
        yyval = expNode;
    }
#line 1896 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 56: /* expression: LEFT_PAREN expression RIGHT_PAREN  */
#line 332 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                        {
        Node* expNode = new Node("expression", "");
        expNode->children.push_back(yyvsp[-1]);
        yyval = expNode;
    }
#line 1906 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 57: /* for_loop: FOR type IDENTIFIER ASSIGN expression SEMICOLON expression SEMICOLON expression block  */
#line 340 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                                            {
        Node* forLoopNode = new Node("for_loop", "");
        forLoopNode->children.push_back(new Node("keyword", "for"));
        forLoopNode->children.push_back(yyvsp[-8]);
        forLoopNode->children.push_back(yyvsp[-7]);
        forLoopNode->children.push_back(new Node("operator", "="));
        forLoopNode->children.push_back(yyvsp[-5]);
        forLoopNode->children.push_back(yyvsp[-3]);
        forLoopNode->children.push_back(yyvsp[-1]);
        forLoopNode->children.push_back(yyvsp[0]);
        yyval = forLoopNode;
    }
#line 1923 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 58: /* if_statement: IF LEFT_PAREN expression RIGHT_PAREN block  */
#line 355 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                 {
        Node* ifStmtNode = new Node("if_statement", "");
        ifStmtNode->children.push_back(new Node("keyword", "if"));
        ifStmtNode->children.push_back(yyvsp[-2]);
        ifStmtNode->children.push_back(yyvsp[0]);
        yyval = ifStmtNode;
    }
#line 1935 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 59: /* if_statement: IF LEFT_PAREN expression RIGHT_PAREN block ELSE block  */
#line 362 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                            {
        Node* ifStmtNode = new Node("if_statement", "");
        ifStmtNode->children.push_back(new Node("keyword", "if"));
        ifStmtNode->children.push_back(yyvsp[-4]);
        ifStmtNode->children.push_back(yyvsp[-2]);
        ifStmtNode->children.push_back(new Node("keyword", "else"));
        ifStmtNode->children.push_back(yyvsp[0]);
        yyval = ifStmtNode;
    }
#line 1949 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 60: /* match_statement: MATCH LEFT_PAREN expression RIGHT_PAREN match_case_list  */
#line 374 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                              {
        Node* matchStmtNode = new Node("match_statement", "");
        matchStmtNode->children.push_back(new Node("keyword", "match"));
        matchStmtNode->children.push_back(yyvsp[-2]);
        matchStmtNode->children.push_back(yyvsp[0]);
        yyval = matchStmtNode;
    }
#line 1961 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 61: /* match_case_list: match_case match_case_list  */
#line 384 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                 {
        Node* matchCaseListNode = new Node("match_case_list", "");
        matchCaseListNode->children.push_back(yyvsp[-1]);
        matchCaseListNode->children.push_back(yyvsp[0]);
        yyval = matchCaseListNode;
    }
#line 1972 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 62: /* match_case_list: %empty  */
#line 390 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new Node("match_case_list", "");
    }
#line 1980 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 63: /* match_case: IDENTIFIER COLON block  */
#line 396 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                             {
        Node* matchCaseNode = new Node("match_case", yyvsp[-2]->value);
        matchCaseNode->children.push_back(new Node("colon", ":"));
        matchCaseNode->children.push_back(yyvsp[0]);
        yyval = matchCaseNode;
    }
#line 1991 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 64: /* match_case: LEFT_PAREN RIGHT_PAREN COLON block  */
#line 402 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                         {
        Node* matchCaseNode = new Node("match_case", "default");
        matchCaseNode->children.push_back(new Node("colon", ":"));
        matchCaseNode->children.push_back(yyvsp[0]);
        yyval = matchCaseNode;
    }
#line 2002 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 65: /* struct_declarations: struct_declaration struct_declarations  */
#line 411 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                             {
        vector<Node*>* v = new vector<Node*>();
        v->push_back(yyvsp[-1]);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( yyvsp[0]);
        for (auto child : *v2) {
            v->push_back(child);
        }
        yyval = v;
    }
#line 2016 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 66: /* struct_declarations: %empty  */
#line 420 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new vector<Node*>();
    }
#line 2024 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 67: /* struct_declaration: STRUCT IDENTIFIER LEFT_BRACE struct_member_list RIGHT_BRACE  */
#line 426 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                  {
        Node* structDeclNode = new Node("struct_declaration", yyvsp[-3]->value);
        structDeclNode->children.push_back(yyvsp[-1]);
        yyval = structDeclNode;
    }
#line 2034 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 68: /* struct_declaration: STRUCT IDENTIFIER LEFT_BRACE RIGHT_BRACE  */
#line 431 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                               {
        Node* structDeclNode = new Node("struct_declaration", yyvsp[-2]->value);
        yyval = structDeclNode;
    }
#line 2043 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 69: /* struct_member_list: struct_member SEMICOLON struct_member_list  */
#line 438 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                 {
        Node* structMemberListNode = new Node("struct_member_list", "");
        structMemberListNode->children.push_back(yyvsp[-2]);
        structMemberListNode->children.push_back(yyvsp[0]);
        yyval = structMemberListNode;
    }
#line 2054 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 70: /* struct_member_list: struct_member SEMICOLON  */
#line 444 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                              {
        Node* structMemberListNode = new Node("struct_member_list", "");
        structMemberListNode->children.push_back(yyvsp[-1]);
        yyval = structMemberListNode;
    }
#line 2064 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 71: /* struct_member_list: %empty  */
#line 449 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new Node("struct_member_list", "");
    }
#line 2072 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 72: /* struct_member: IMT type IDENTIFIER  */
#line 455 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* structMemberNode = new Node("struct_member", yyvsp[0]->value);
        structMemberNode->children.push_back(new Node("modifier", "imt"));
        structMemberNode->children.push_back(yyvsp[-1]);
        yyval = structMemberNode;
    }
#line 2083 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 73: /* struct_member: VAR type IDENTIFIER  */
#line 461 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                          {
        Node* structMemberNode = new Node("struct_member", yyvsp[0]->value);
        structMemberNode->children.push_back(new Node("modifier", "var"));
        structMemberNode->children.push_back(yyvsp[-1]);
        yyval = structMemberNode;
    }
#line 2094 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 74: /* trait_declarations: trait_declaration trait_declarations  */
#line 470 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                           {
        vector<Node*>* v = new vector<Node*>();
        v->push_back(yyvsp[-1]);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( yyvsp[0]);
        for (auto child : *v2) {
            v->push_back(child);
        }
        yyval = v;
    }
#line 2108 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 75: /* trait_declarations: %empty  */
#line 479 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new vector<Node*>();
    }
#line 2116 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 76: /* trait_declaration: TRAIT IDENTIFIER LEFT_BRACE trait_method_list RIGHT_BRACE  */
#line 485 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                {
        Node* traitDeclNode = new Node("trait_declaration", yyvsp[-3]->value);
        traitDeclNode->children.push_back(yyvsp[-1]);
        yyval = traitDeclNode;
    }
#line 2126 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 77: /* trait_declaration: TRAIT IDENTIFIER LEFT_BRACE RIGHT_BRACE  */
#line 490 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                              {
        Node* traitDeclNode = new Node("trait_declaration", yyvsp[-2]->value);
        yyval = traitDeclNode;
    }
#line 2135 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 78: /* trait_method_list: trait_method SEMICOLON trait_method_list  */
#line 497 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                               {
        Node* traitMethodListNode = new Node("trait_method_list", "");
        traitMethodListNode->children.push_back(yyvsp[-2]);
        traitMethodListNode->children.push_back(yyvsp[0]);
        yyval = traitMethodListNode;
    }
#line 2146 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 79: /* trait_method_list: trait_method SEMICOLON  */
#line 503 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                             {
        Node* traitMethodListNode = new Node("trait_method_list", "");
        traitMethodListNode->children.push_back(yyvsp[-1]);
        yyval = traitMethodListNode;
    }
#line 2156 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 80: /* trait_method_list: %empty  */
#line 508 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new Node("trait_method_list", "");
    }
#line 2164 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 81: /* trait_method: FUN IDENTIFIER LEFT_PAREN parameter_list RIGHT_PAREN return_type  */
#line 514 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                                                       {
        Node* traitMethodNode = new Node("trait_method", yyvsp[-4]->value);
        traitMethodNode->children.push_back(yyvsp[-2]);
        traitMethodNode->children.push_back(yyvsp[0]);
        yyval = traitMethodNode;
    }
#line 2175 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 82: /* type_definitions: type_definition type_definitions  */
#line 523 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                                       {
        vector<Node*>* v = new vector<Node*>();
        v->push_back(yyvsp[-1]);
        vector<Node*>* v2 = static_cast<vector<Node*>*>( yyvsp[0]);
        for (auto child : *v2) {
            v->push_back(child);
        }
        yyval = v;
    }
#line 2189 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 83: /* type_definitions: %empty  */
#line 532 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                  {
        yyval = new vector<Node*>();
    }
#line 2197 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;

  case 84: /* type_definition: TYPEDEF type IDENTIFIER  */
#line 538 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"
                              {
        Node* typeDefNode = new Node("type_definition", yyvsp[0]->value);
        typeDefNode->children.push_back(new Node("keyword", "typedef"));
        typeDefNode->children.push_back(yyvsp[-1]);
        yyval = typeDefNode;
    }
#line 2208 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"
    break;


#line 2212 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.cpp"

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

#line 545 "/home/napbad/Project/dap-dev-main/compiler/parser/parser.y"


namespace dap::parser {
Node* parseProgram() {
    // 这里yyparse是由yacc生成的函数，用于启动语法分析
    if (yyparse() == 0) {
        // 假设语法分析成功，返回语法树的根节点
        // 这里根据实际情况从全局变量获取根节点
        // 例如，如果根节点存储在某个全局变量root中
        // return root;
        // 这里简单返回nullptr，实际应正确设置根节点
        return nullptr;
    } else {
        return nullptr;
    }
}
}
