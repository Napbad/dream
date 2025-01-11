%{
#include "node.h"
#include "src/core/parser/parser.hpp"
#include "src/core/common/define_d.h"
#include <string>
#include <cstring>
#include "src/core/utilities/file_util.h"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng); \
    std::cout << "Token: " << yytext << " size: " << std::to_string(yyleng) << std::endl;\
    for (int i = 0;i < 2147483647; ++i ) { \
        if (yytext[i] != '\0') { yytext[i] = '\0'; } \
        else { break; }\
    }
#define TOKEN(t)    (yylval.token = t)

int llcolumn = 0;

// Function to handle string literals
std::string *handle_string_literal(const char *str) {
    std::string *result = new std::string(str);
    return result;
}


namespace dap::parser {

}
%}

/* Define the tokens */
%option noyywrap

LETTER [a-zA-Z_]
DIGIT [0-9]
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
UNDERSCORE [_]
FLOAT {DIGIT}({DIGIT}|{UNDERSCORE})*[eE][+-]?{DIGIT}+

INTEGER {DIGIT}({DIGIT}|{UNDERSCORE})*{DIGIT}

BINARY 0[bB]{DIGIT}[01]({UNDERSCORE}[01])*[01]

OCTAL 0[0-7]({DIGIT}|{UNDERSCORE})*[0-7]

HEXADECIMAL 0[xX][0-9a-fA-F]([0-9a-fA-F]|{UNDERSCORE})*[0-9a-fA-F]

%%
"package"         { return PACKAGE; }
"import"          { return IMPORT; }
"fun"             { return FUN; }
"void"            { return VOID; }
"for"             { return FOR; }
"if"              { return IF; }
"else"            { return ELSE; }
"match"           { return MATCH; }
"struct"          { return STRUCT; }
"trait"           { return TRAIT; }
"typedef"         { return TYPEDEF; }
"imt"             { return IMT; }
"var"             { return VAR; }
"instanceOf"      { return INSTANCEOF; }
"return"          { return RETURN; }

"int"             { return INT; }
"byte"            { return BYTE; }
"short"           { return SHORT; }
"long"            { return LONG; }
"float"           { return FLOAT; }
"double"          { return DOUBLE; }
"bool"            { return BOOL; }
"uint"            { return UINT; }
"ushort"          { return USHORT; }
"ulong"          { return ULONG; }
"llong"           { return LLLONG; }
"ullong"          { return ULLONG; }



{IDENTIFIER}      { yylval.string = strdup(yytext); return IDENTIFIER; }

{INTEGER}         { yylval.integer = strtol(yytext, NULL, 10); return INTEGER; }

{BINARY}          { yylval.integer = strtol(yytext+2, NULL, 2); return BINARY_LITERAL; }

{OCTAL}           { yylval.integer = strtol(yytext, NULL, 8); return OCTAL_LITERAL; }

{HEXADECIMAL}     { yylval.integer = strtol(yytext+2, NULL, 16); return HEXADECIMAL_LITERAL; }

{FLOAT}           { yylval.float_val = atof(yytext); return FLOAT; }

\"([^\\\n]|(\\.))*?\" { yylval.string = strdup(yytext); return STRING_LITERAL; }

\'([^\\\n]|(\\.))*?\' { yylval.char_val = yytext[1]; return CHAR_LITERAL; }

"="               { return ASSIGN; }
"+="              { return ADD_ASSIGN; }
"-="              { return MINUS_ASSIGN; }
"++"              { return INCREMENT; }
"<"               { return LESS_THAN; }

","               { return COMMA; }
";"               { return SEMICOLON; }
":"               { return COLON; }
"{"               { return LEFT_BRACE; }
"}"               { return RIGHT_BRACE; }
"("               { return LEFT_PAREN; }
")"               { return RIGHT_PAREN; }
"["               { return LEFT_BRACKET; }
"]"               { return RIGHT_BRACKET; }
"."               { return DOT; }
"..."             { return ELLIPSIS; }
"?"               { return QUESTION; }
"!"               { return BANG; }


[ \t\n]           { /* 忽略空白字符 */ }

.                 { yyerror("未识别的字符"); }

%%