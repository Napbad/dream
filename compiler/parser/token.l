%{
#include "ASTNode.h"
#include "parser/parser.hpp"
#include <string>
#include <cstring>
#include "utilities/file_util.h"

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

extern void yyerror(const char *msg);

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
"package"               { return PACKAGE; }
"import"                { return IMPORT; }
"fun"                   { return FUN; }
"void"                  { return VOID; }
"for"                   { return FOR; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"match"                 { return MATCH; }
"struct"                { return STRUCT; }
"const"                 { return CONST; }
"trait"                 { return TRAIT; }
"typedef"               { return TYPEDEF; }
"imt"                   { return IMT; }
"var"                   { return VAR; }
"instanceOf"            { return INSTANCEOF; }
"return"                { return RETURN; }

"int"                   { return INT; }
"byte"                  { return BYTE; }
"short"                 { return SHORT; }
"long"                  { return LONG; }
"float"                 { return FLOAT; }
"double"                { return DOUBLE; }
"bool"                  { return BOOL; }
"uint"                  { return UINT; }
"ushort"                { return USHORT; }
"ulong"                 { return ULONG; }
"llong"                 { return LLONG; }
"ullong"                { return ULLONG; }



[a-zA-Z_]([a-zA-Z_]|[0-9])*     { yylval.str = new std::string(yytext); return IDENTIFIER; }

[0-9]+(_[0-9]+)*                { yylval.str = new std::string(yytext); return INTEGER; }

0[bB][01]([01]|(_[01]))*[01]    { yylval.str = new std::string(yytext); return BINARY_LITERAL; }

0[0-7]([0-7]|(_[0-7]))*[0-7]    { yylval.str = new std::string(yytext); return OCTAL_LITERAL; }

0[xX][0-9a-fA-F]([0-9a-fA-F]|(_[0-9a-fA-F]))*[0-9a-fA-F] { yylval.str = new std::string(yytext); return HEXADECIMAL_LITERAL; }

[0-9]+(_[0-9]+)*[eE][+-]?[0-9]+ { yylval.str = new std::string(yytext); return FLOAT; }

\"([^\\\n]|(\\.))*?\"           { yylval.str = new std::string(yytext); return STRING_LITERAL; }

\'([^\\\n]|(\\.))*?\'           { yylval.charVal = yytext[1]; return CHAR_LITERAL; }


"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"%"                     { return MOD; }
"&"                     { return BIT_AND; }
"|"                     { return BIT_OR; }
"^"                     { return BIT_XOR; }
"~"                     { return BIT_NOT; }
"<<"                    { return SHIFT_LEFT; }
">>"                    { return SHIFT_RIGHT; }
"<<<"                   { return LOGIC_SHIFT_LEFT; }
"="                     { return ASSIGN; }

"+="                    { return ADD_ASSIGN; }
"*="                    { return MUL_ASSIGN; }
"/="                    { return DIV_ASSIGN; }
"-="                    { return MINUS_ASSIGN; }
"%="                    { return MOD_ASSIGN; }

"&="                    { return BIT_AND_ASSIGN; }
"|="                    { return BIT_OR_ASSIGN; }
"^="                    { return BIT_XOR_ASSIGN; }
"<<="                   { return SHIFT_LEFT_ASSIGN; }
">>="                   { return SHIFT_RIGHT_ASSIGN; }
">>>="                  { return LOGIC_SHIFT_LEFT_ASSIGN; }

"++"                    { return INCREMENT; }
"--"                    { return DECREMENT; }
"<"                     { return LESS_THAN; }
">"                     { return GREATER_THAN; }

"<="                    { return LESS_THAN_EQUAL; }
">="                    { return GREATER_THAN_EQUAL; }
"=="                    { return EQUAL; }
"!="                    { return NOT_EQUAL; }

"&&"                    { return AND; }
"||"                    { return OR; }


","                     { return COMMA; }
";"                     { return SEMICOLON; }
":"                     { return COLON; }
"{"                     { return LEFT_BRACE; }
"}"                     { return RIGHT_BRACE; }
"("                     { return LEFT_PAREN; }
")"                     { return RIGHT_PAREN; }
"["                     { return LEFT_BRACKET; }
"]"                     { return RIGHT_BRACKET; }
"."                     { return DOT; }
"..."                   { return ELLIPSIS; }
"?"                     { return QUESTION; }
"!"                     { return BANG; }



"//"[^\n]*              { llcolumn += yyleng; }

"/*"                    {
                            int comment_level = 1;
                            while (comment_level > 0) {
                                int c = yyinput();
                                if (c == EOF) {
                                    return 0;
                                }
                                if (c == '*' && yyinput() == '/') {
                                    comment_level--;
                                } else if (c == '/' && yyinput() == '*') {
                                    comment_level++;
                                }
                                if (c == '\n') {
                                    ++yylineno;
                                    llcolumn = 0;
                                } else {
                                    llcolumn++;
                                }
                            }
                        }

[ \t]                   { llcolumn += yyleng; } // Update column for whitespace
\n                      { ++yylineno; llcolumn = 0; } // Increment line number and reset column on newline

.                       { yyerror("unknown token"); }

%%