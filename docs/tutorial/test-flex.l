%{
#include <stdio.h>
#define MAX_LENGTH 100
%}

digit [0-9]
identifier [a-zA-Z][a-zA-Z]*
whitespace [ \t\n\r\f\v]

keyword "if"|"else"|"while"|"for"|"return"|"int"|"float"|"char"|"void"

%option noyywrap
%%

{digit}+ {
    // Match IntegerNode sequences
    printf("Matched digit sequence: %s\n", yytext);
    // More processing about digit sequence can be done here, such as converting to numeric type, etc.
}

{digit}+"."{digit}+ {
    // Match floating point number sequences
    printf("Matched float number: %s\n", yytext);
}

0[xX]{digit}[a-fA-F0-9]* {
    // Match hexadecimal number sequences
    printf("Matched hexadecimal number: %s\n", yytext);
}

{keyword} {
    // Match keywords
    printf("Matched keyword: %s\n", yytext);
}

{identifier} {
// Match identifiers and keywords
    printf("Matched identifier: %s\n", yytext);
}

[+\-*/=<>!&|] {
// Match operators
    printf("Matched operator: %s\n", yytext);
}

\"([^\\\n]|(\\.))*\" {
// Match string constants
    printf("Matched string: %s\n", yytext);
}

"//".*  {
// Ignore single-line comments
    // Ignore C-style single-line comments
}

"/*"([^*]|\*+[^*/])*\*+"/" {
// Ignore multi-line comments
    // Ignore C-style multi-line comments
}

{whitespace} {
// Ignore whitespace characters
    // Ignore whitespace characters
}

. {
// Match unknown characters
    printf("Unknown character: %s\n", yytext);
}

%%

// Main function, entry point of the program
int main() {
    yylex();
    return 0;
}