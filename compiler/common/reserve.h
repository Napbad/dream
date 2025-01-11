
#ifndef RESERVE_H
#define RESERVE_H

#define D_RETURN        "return"
#define D_IF            "if"
#define D_ELSE          "else"
#define D_FOR           "for"
#define D_WHILE         "while"
#define D_PACKAGE       "package"
#define D_IMPORT        "import"
#define D_BREAK         "break"
#define D_CONTINUE      "continue"
#define D_TRY           "try"
#define D_CATCH         "catch"
#define D_FINALLY       "finally"
#define D_VAR           "var"
#define D_IMT           "imt"
#define D_FUN           "fun"
#define D_CLASS         "class"
#define D_ENUM          "enum"
#define D_INTERFACE     "interface"
#define D_ANNOTATION    "annotation"
#define D_PUBLIC        "public"
#define D_PRIVATE       "private"
#define D_PROTECTED     "protected"
#define D_STATIC        "static"
#define D_NEW           "new"
#define D_OVERRIDE      "override"
#define D_SYNCHRONIZED  "synchronized"
#define D_THROW         "throw"

#define D_IMT           "imt"
#define D_VAR           "var"
#define D_FUN           "fun"

#define D_INT           "int"
#define D_BYTE          "byte"
#define D_SHORT         "short"
#define D_LONG          "long"
#define D_CHAR          "char"
#define D_FLOAT         "float"
#define D_STRING        "string"
#define D_BOOL          "bool"
#define D_UINT          "uint"
#define D_USHORT            "ushort"
#define D_ULONG             "ulong"
#define D_LLONG             "llong"
#define D_ULLONG            "ullong"
#define D_UFLOAT            "ufloat"
#define D_UDOUBLE           "udouble"

#define D_NULL_STR          "null"
#define D_NULL          "null"
#define D_TRUE          "true"
#define D_FALSE             "false"

#define D_BANG          "!"
#define D_BANG_QUESTION             "?"

#define D_NON_NULLABLE          "!"
#define D_NULLABLE          "?"

#define D_PLUS_ASSIGN           "+="
#define D_MINUS_ASSIGN          "-="
#define D_MUL_ASSIGN            "*="
#define D_DIV_ASSIGN            "/="
#define D_MOD_ASSIGN            "%="
#define D_NOT           "!"

#define D_ASSIGN            "="
#define D_ADD           "+"
#define D_SUB           "-"
#define D_MUL           "*"
#define D_DIV           "/"
#define D_MOD           "%"
#define D_LT            "<"
#define D_GT            ">"
#define D_LTE           "<="
#define D_GTE           ">="
#define D_EQ            "=="
#define D_NEQ           "!="
#define D_AND           "&&"
#define D_OR            "||"
#define D_XOR           "^"
#define D_LSHIFT            "<<"
#define D_RSHIFT            ">>"
#define D_URSHIFT           ">>>"

#define D_INC           "++"
#define D_DEC           "--"

#define D_CHAR_ASSIGN '='
#define D_CHAR_ADD '+'
#define D_CHAR_SUB '-'
#define D_CHAR_MUL '*'
#define D_CHAR_DIV '/'
#define D_CHAR_MOD '%'
#define D_CHAR_LT '<'
#define D_CHAR_GT '>'
#define D_CHAR_XOR '^'

#define D_LBRACE            "{"
#define D_RBRACE            "}"
#define D_LPAREN            "("
#define D_RPAREN            ")"
#define D_LBRACKET          "["
#define D_RBRACKET          "]"

#define D_ARR_SUFIX             "[]"
#define D_POINTER_SUFIX             "*"

#define D_SLASH             "/"

#define D_OPERATOR          "OPERATOR"

#define D_SEMICOLON             ";"

#define D_PACKAGE_FORMAT            "(PACKAGE) (name) (;)"
#define D_PACKAGE_SPLIT             "."

#define D_COMMA             ","

#define D_IDENTIFIER            "IDENTIFIER"

#define CPP_VOID            "void"

#ifdef __LP64__
inline unsigned bitWidth = 64; // 64-bit machine
#elif __ILP32__
inline unsigned bitWidth = 32; // 32-bit machine
#else
inline unsigned bitWidth = 32; // Default to 32-bit if unknown
#endif

#include <string>
#include <unordered_map>
#include <vector>

inline std::vector<std::string> ops = {
    D_NOT, D_MUL, D_DIV, D_MOD, D_ADD,    D_SUB,         D_LT,           D_GT,         D_LTE,        D_GTE,       D_EQ,
    D_NEQ, D_AND, D_OR,  D_XOR, D_ASSIGN, D_PLUS_ASSIGN, D_MINUS_ASSIGN, D_MUL_ASSIGN, D_DIV_ASSIGN, D_MOD_ASSIGN};

inline std::unordered_map<std::string, std::string> common_type_map = {
    {D_INT, "int"},
    {D_BYTE, "char"},
    {D_SHORT, "short"},
    {D_LONG, "long"},
    {D_CHAR, "char"},
    {D_FLOAT, "float"},
    {D_STRING, "std::string"},
    {D_BOOL, "bool"},
    {D_NULL, "null"},
    {D_UINT, "unsigned int"},
    {D_USHORT, "unsigned short"},
    {D_ULONG, "unsigned long"},
    {D_LLONG, "long long"},
    {D_ULLONG, "unsigned long long"},
    {D_UFLOAT, "unsigned float"},
    {D_UDOUBLE, "unsigned double"}
};
inline std::unordered_map<std::string, std::string> keywords = {{"return", "RETURN"},
                                                                {"if", "IF"},
                                                                {"else", "ELSE"},
                                                                {"for", "FOR"},
                                                                {"while", "WHILE"},
                                                                {"package", "PACKAGE"},
                                                                {"import", "IMPORT"},
                                                                {"break", "BREAK"},
                                                                {"continue", "CONTINUE"},
                                                                {"try", "TRY"},
                                                                {"catch", "CATCH"},
                                                                {"finally", "FINALLY"},
                                                                {"var", "VAR"},
                                                                {"imt", "IMT"},
                                                                {"fun", "FUN"},
                                                                {"class", "CLASS"},
                                                                {"enum", "ENUM"},
                                                                {"interface", "INTERFACE"},
                                                                {"annotation", "ANNOTATION"},
                                                                {"public", "PUBLIC"},
                                                                {"private", "PRIVATE"},
                                                                {"protected", "PROTECTED"},
                                                                {"static", "STATIC"},
                                                                {"new", "NEW"},
                                                                {"override", "OVERRIDE"},
                                                                {"native", "NATIVE"},
                                                                {"synchronized", "SYNCHRONIZED"},
                                                                {"throw", "THROW"},
                                                                {"delete", "DELETE"},
                                                                {"byte", "BYTE"},
                                                                {"short", "SHORT"},
                                                                {"int", "INT"},
                                                                {"uint", "UINT"},
                                                                {"ushort", "USHORT"},
                                                                {"long", "LONG"},
                                                                {"ulong", "ULONG"},
                                                                {"llong", "LONGLONG"},
                                                                {"ullong", "ULONGLONG"},
                                                                {"float", "FLOAT"},
                                                                {"double", "DOUBLE"},
                                                                {"bool", "BOOL"},
                                                                {"char", "CHAR"},
                                                                {"string", "STRING"},
                                                                {"void", "VOID"},
                                                                {"const", "CONST"}};

#endif