%{
#include <string>
#include <unistd.h>
#include <cstring>
#include "src/core/parser.hpp"


#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)

int llcolumn = 0;

// Function to handle string literals
std::string *handle_string_literal(const char *str) {
    std::string *result = new std::string(str);
    return result;
}

%}
%option noyywrap

%%
"return"   { return RETURN; }
"fun"      { return FUN; }
"var"      { return VAR; }

[a-zA-Z_][a-zA-Z0-9_]*  { SAVE_TOKEN; return IDENTIFIER; }
[0-9]+                  { SAVE_TOKEN; return INT_TOKEN; }
\"([^\\\"]|\\.)*\"      { SAVE_TOKEN; return STRING_LITERAL; }

";"        { return SEMICOLON; }
","        { return COMMA; }
"("        { return LPAREN; }
")"        { return RPAREN; }
"{"        { return LBRACE; }
"}"        { return RBRACE; }
"="        { return ASSIGN; }
%%