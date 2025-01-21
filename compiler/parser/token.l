%{
#include <string>
#include <cstring>
#include "ASTNode.h"
#include "parser/parser.hpp"
#include "common/define_d.h"
#include "common/config.h"
#include "utilities/file_util.h"
#include "utilities/log_util.h"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng); \
    std::string tokenStr(yytext, yyleng); \
    lexerLog("Token: " + tokenStr + " size: " + std::to_string(yyleng));\
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

extern void yyerror(const char *msg);
namespace dap::parser {
extern std::string currentParsingFile;
}
void lexerLog(const char *msg) {
#ifdef D_DEBUG
    dap::util::logInfo(msg, nullptr, dap::parser::currentParsingFile, yylineno);
#endif
}

void lexerLog(std::string msg) {
#ifdef D_DEBUG
    dap::util::logInfo(msg, nullptr, dap::parser::currentParsingFile, yylineno);
#endif
}


%}

/* Define the tokens */
%option noyywrap


%%
"package"               { std::string logMsg = "Parsing token: PACKAGE"; lexerLog(logMsg); return PACKAGE; }
"import"                { std::string logMsg = "Parsing token: IMPORT"; lexerLog(logMsg); return IMPORT; }
"fun"                   { std::string logMsg = "Parsing token: FUN"; lexerLog(logMsg); return FUN; }
"void"                  { std::string logMsg = "Parsing token: VOID"; lexerLog(logMsg); return VOID; }
"for"                   { std::string logMsg = "Parsing token: FOR"; lexerLog(logMsg); return FOR; }
"if"                    { std::string logMsg = "Parsing token: IF"; lexerLog(logMsg); return IF; }
"else"                  { std::string logMsg = "Parsing token: ELSE"; lexerLog(logMsg); return ELSE; }
"match"                 { std::string logMsg = "Parsing token: MATCH"; lexerLog(logMsg); return MATCH; }
"struct"                { std::string logMsg = "Parsing token: STRUCT"; lexerLog(logMsg); return STRUCT; }
"const"                 { std::string logMsg = "Parsing token: CONST"; lexerLog(logMsg); return CONST; }
"trait"                 { std::string logMsg = "Parsing token: TRAIT"; lexerLog(logMsg); return TRAIT; }
"typedef"               { std::string logMsg = "Parsing token: TYPEDEF"; lexerLog(logMsg); return TYPEDEF; }
"imt"                   { std::string logMsg = "Parsing token: IMT"; lexerLog(logMsg); return IMT; }
"var"                   { std::string logMsg = "Parsing token: VAR"; lexerLog(logMsg); return VAR; }
"instanceOf"            { std::string logMsg = "Parsing token: INSTANCEOF"; lexerLog(logMsg); return INSTANCEOF; }
"return"                { std::string logMsg = "Parsing token: RETURN"; lexerLog(logMsg); return RETURN; }
"extern"                { std::string logMsg = "Parsing token: EXTERN"; lexerLog(logMsg); return EXTERN; }

"int"                   { std::string logMsg = "Parsing token: INT"; lexerLog(logMsg); return INT; }
"byte"                  { std::string logMsg = "Parsing token: BYTE"; lexerLog(logMsg); return BYTE; }
"short"                 { std::string logMsg = "Parsing token: SHORT"; lexerLog(logMsg); return SHORT; }
"long"                  { std::string logMsg = "Parsing token: LONG"; lexerLog(logMsg); return LONG; }
"float"                 { std::string logMsg = "Parsing token: FLOAT"; lexerLog(logMsg); return FLOAT; }
"double"                { std::string logMsg = "Parsing token: DOUBLE"; lexerLog(logMsg); return DOUBLE; }
"bool"                  { std::string logMsg = "Parsing token: BOOL"; lexerLog(logMsg); return BOOL; }
"uint"                  { std::string logMsg = "Parsing token: UINT"; lexerLog(logMsg); return UINT; }
"ushort"                { std::string logMsg = "Parsing token: USHORT"; lexerLog(logMsg); return USHORT; }
"ulong"                 { std::string logMsg = "Parsing token: ULONG"; lexerLog(logMsg); return ULONG; }
"llong"                 { std::string logMsg = "Parsing token: LLONG"; lexerLog(logMsg); return LLONG; }
"ullong"                { std::string logMsg = "Parsing token: ULLONG"; lexerLog(logMsg); return ULLONG; }

"true"                  { std::string logMsg = "Parsing token: TRUE"; lexerLog(logMsg); return TRUE; }
"false"                 { std::string logMsg = "Parsing token: FALSE"; lexerLog(logMsg); return FALSE; }



[a-zA-Z_]([a-zA-Z_]|[0-9])*     { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: IDENTIFIER, value: " + std::string(yytext); lexerLog(logMsg); return IDENTIFIER; }

[0-9]+(_[0-9]+)*                { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: INTEGER, value: " + std::string(yytext); lexerLog(logMsg); return INTEGER; }

0[bB][01]([01]|(_[01]))*[01]    { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: BINARY_LITERAL, value: " + std::string(yytext); lexerLog(logMsg); return BINARY_LITERAL; }

[0-9]+\.[0-9]+                  { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: FLOAT_LITERAL, value: " + std::string(yytext); lexerLog(logMsg); return FLOAT_LITERAL; }

0[xX][0-9a-fA-F]([0-9a-fA-F]|(_[0-9a-fA-F]))*[0-9a-fA-F] { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: HEXADECIMAL_LITERAL, value: " + std::string(yytext); lexerLog(logMsg); return HEXADECIMAL_LITERAL; }

\"([^\\\"]|\\.)*\"              { yylval.str = new std::string(yytext); std::string logMsg = "Parsing token: STRING_LITERAL, value: " + std::string(yytext); lexerLog(logMsg); return STRING_LITERAL; }

\'([^\\\n]|(\\.))*?\'           { yylval.charVal = yytext[1]; std::string logMsg = "Parsing token: CHAR_LITERAL, value: " + std::string(1, yytext[1]); lexerLog(logMsg); return CHAR_LITERAL; }


"+"                     { std::string logMsg = "Parsing token: PLUS"; lexerLog(logMsg); return PLUS; }
"-"                     { std::string logMsg = "Parsing token: MINUS"; lexerLog(logMsg); return MINUS; }
"*"                     { std::string logMsg = "Parsing token: MUL"; lexerLog(logMsg); return MUL; }
"/"                     { std::string logMsg = "Parsing token: DIV"; lexerLog(logMsg); return DIV; }
"%"                     { std::string logMsg = "Parsing token: MOD"; lexerLog(logMsg); return MOD; }
"&"                     { std::string logMsg = "Parsing token: BIT_AND"; lexerLog(logMsg); return BIT_AND; }
"|"                     { std::string logMsg = "Parsing token: BIT_OR"; lexerLog(logMsg); return BIT_OR; }
"^"                     { std::string logMsg = "Parsing token: BIT_XOR"; lexerLog(logMsg); return BIT_XOR; }
"~"                     { std::string logMsg = "Parsing token: BIT_NOT"; lexerLog(logMsg); return BIT_NOT; }
"<<"                    { std::string logMsg = "Parsing token: SHIFT_LEFT"; lexerLog(logMsg); return SHIFT_LEFT; }
">>"                    { std::string logMsg = "Parsing token: SHIFT_RIGHT"; lexerLog(logMsg); return SHIFT_RIGHT; }
">>>"                   { std::string logMsg = "Parsing token: LOGIC_SHIFT_RIGHT"; lexerLog(logMsg); return LOGIC_SHIFT_RIGHT; }
"="                     { std::string logMsg = "Parsing token: ASSIGN"; lexerLog(logMsg); return ASSIGN; }

"+="                    { std::string logMsg = "Parsing token: ADD_ASSIGN"; lexerLog(logMsg); return ADD_ASSIGN; }
"*="                    { std::string logMsg = "Parsing token: MUL_ASSIGN"; lexerLog(logMsg); return MUL_ASSIGN; }
"/="                    { std::string logMsg = "Parsing token: DIV_ASSIGN"; lexerLog(logMsg); return DIV_ASSIGN; }
"-="                    { std::string logMsg = "Parsing token: MINUS_ASSIGN"; lexerLog(logMsg); return MINUS_ASSIGN; }
"%="                    { std::string logMsg = "Parsing token: MOD_ASSIGN"; lexerLog(logMsg); return MOD_ASSIGN; }

"&&="                   { std::string logMsg = "Parsing token: AND_ASSIGN"; lexerLog(logMsg); return AND_ASSIGN; }
"||="                   { std::string logMsg = "Parsing token: OR_ASSIGN"; lexerLog(logMsg); return OR_ASSIGN; }

"&="                    { std::string logMsg = "Parsing token: BIT_AND_ASSIGN"; lexerLog(logMsg); return BIT_AND_ASSIGN; }
"|="                    { std::string logMsg = "Parsing token: BIT_OR_ASSIGN"; lexerLog(logMsg); return BIT_OR_ASSIGN; }
"^="                    { std::string logMsg = "Parsing token: BIT_XOR_ASSIGN"; lexerLog(logMsg); return BIT_XOR_ASSIGN; }
"<<="                   { std::string logMsg = "Parsing token: SHIFT_LEFT_ASSIGN"; lexerLog(logMsg); return SHIFT_LEFT_ASSIGN; }
">>="                   { std::string logMsg = "Parsing token: SHIFT_RIGHT_ASSIGN"; lexerLog(logMsg); return SHIFT_RIGHT_ASSIGN; }
">>>="                  { std::string logMsg = "Parsing token: LOGIC_SHIFT_RIGHT_ASSIGN"; lexerLog(logMsg); return LOGIC_SHIFT_RIGHT_ASSIGN; }

"++"                    { std::string logMsg = "Parsing token: INCREMENT"; lexerLog(logMsg); return INCREMENT; }
"--"                    { std::string logMsg = "Parsing token: DECREMENT"; lexerLog(logMsg); return DECREMENT; }
"<"                     { std::string logMsg = "Parsing token: LESS_THAN"; lexerLog(logMsg); return LESS_THAN; }
">"                     { std::string logMsg = "Parsing token: GREATER_THAN"; lexerLog(logMsg); return GREATER_THAN; }

"<="                    { std::string logMsg = "Parsing token: LESS_THAN_EQUAL"; lexerLog(logMsg); return LESS_THAN_EQUAL; }
">="                    { std::string logMsg = "Parsing token: GREATER_THAN_EQUAL"; lexerLog(logMsg); return GREATER_THAN_EQUAL; }
"=="                    { std::string logMsg = "Parsing token: EQUAL"; lexerLog(logMsg); return EQUAL; }
"!="                    { std::string logMsg = "Parsing token: NOT_EQUAL"; lexerLog(logMsg); return NOT_EQUAL; }

"&&"                    { std::string logMsg = "Parsing token: AND"; lexerLog(logMsg); return AND; }
"||"                    { std::string logMsg = "Parsing token: OR"; lexerLog(logMsg); return OR; }


","                     { std::string logMsg = "Parsing token: COMMA"; lexerLog(logMsg); return COMMA; }
";"                     { std::string logMsg = "Parsing token: SEMICOLON"; lexerLog(logMsg); return SEMICOLON; }
":"                     { std::string logMsg = "Parsing token: COLON"; lexerLog(logMsg); return COLON; }
"{"                     { std::string logMsg = "Parsing token: LEFT_BRACE"; lexerLog(logMsg); return LEFT_BRACE; }
"}"                     { std::string logMsg = "Parsing token: RIGHT_BRACE"; lexerLog(logMsg); return RIGHT_BRACE; }
"("                     { std::string logMsg = "Parsing token: LEFT_PAREN"; lexerLog(logMsg); return LEFT_PAREN; }
")"                     { std::string logMsg = "Parsing token: RIGHT_PAREN"; lexerLog(logMsg); return RIGHT_PAREN; }
"["                     { std::string logMsg = "Parsing token: LEFT_BRACKET"; lexerLog(logMsg); return LEFT_BRACKET; }
"]"                     { std::string logMsg = "Parsing token: RIGHT_BRACKET"; lexerLog(logMsg); return RIGHT_BRACKET; }
"."                     { std::string logMsg = "Parsing token: DOT"; lexerLog(logMsg); return DOT; }
"..."                   { std::string logMsg = "Parsing token: ELLIPSIS"; lexerLog(logMsg); return ELLIPSIS; }
"?"                     { std::string logMsg = "Parsing token: QUESTION"; lexerLog(logMsg); return QUESTION; }
"!"                     { std::string logMsg = "Parsing token: BANG"; lexerLog(logMsg); return BANG; }



"//"[^\n]*              { std::string logMsg = "Parsing comment: " + std::string(yytext); lexerLog(logMsg); llcolumn += yyleng; }

"/*"                    {
                            std::string logMsg = "Parsing multiline comment start";
                            lexerLog(logMsg);
                            int comment_level = 1;
                            while (comment_level > 0) {
                                int c = yyinput();
                                if (c == EOF) {
                                    std::string errMsg = "Error: Unexpected EOF in comment";
                                    lexerLog(errMsg);
                                    return 0;
                                }
                                if (c == '*' && yyinput() == '/') {
                                    comment_level--;
                                    std::string nestedMsg = "End of a nested comment";
                                    lexerLog(nestedMsg);
                                } else if (c == '/' && yyinput() == '*') {
                                    comment_level++;
                                    std::string nestedMsg = "Start of a nested comment";
                                    lexerLog(nestedMsg);
                                }
                                if (c == '\n') {
                                    ++yylineno;
                                    llcolumn = 0;
                                } else {
                                    llcolumn++;
                                }
                            }
                            std::string endMsg = "Parsing multiline comment end";
                            lexerLog(endMsg);
                        }

[ \t]                   { llcolumn += yyleng; } // Update column for whitespace
\n                      { std::string logMsg = "New line encountered"; lexerLog(logMsg); ++yylineno; llcolumn = 0; } // Increment line number and reset column on newline

.                       { std::string errMsg = "unknown token"; lexerLog(errMsg); yyerror("unknown token"); }

%%