%{
#include <stdio.h>
#define MAX_LENGTH 100
%}

digit [0-9]

%%

{digit}+ {
    printf("Matched digit sequence: %s\n", yytext);
    // More processing about digit sequence can be done here, such as converting to numeric type, etc.
}

[a-zA-Z]+ {
    printf("Matched alphabet sequence: %s\n", yytext);
}

"//".*  {
    // Ignore C-style single-line comments
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    // Ignore C-style multi-line comments
}

%%

int main() {
    yylex();
    return 0;
}