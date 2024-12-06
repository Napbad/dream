%{
#include "node.h"
#include "src/core/parser/parser.hpp"
#include <string>
#include <cstring>
#include "src/core/utilities/file_util.h"

#define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)    (yylval.token = t)

int llcolumn = 0;

// Function to handle string literals
std::string *handle_string_literal(const char *str) {
    std::string *result = new std::string(str);
    return result;
}

// If defined, output the parse info, with line number, and the token recognized
#define PARSE_DBG

void printTokenInfo(int token, int lineNumber, const std::string& value = "") {
    #ifdef PARSE_DBG
    const char* tokenName = nullptr;
    switch (token) {
        case IF: tokenName = "IF"; break;
        case ELSE: tokenName = "ELSE"; break;
        case ELIF: tokenName = "ELIF"; break;
        case FOR: tokenName = "FOR"; break;
        case RETURN: tokenName = "RETURN"; break;
        case FUN: tokenName = "FUN"; break;
        case VAR: tokenName = "VAR"; break;
        case IMT: tokenName = "IMT"; break;
        case EXTERN: tokenName = "EXTERN"; break;
        case STRUCT: tokenName = "STRUCT"; break;
        case BREAK: tokenName = "BREAK"; break;
        case INCLUDE: tokenName = "INCLUDE"; break;
        case PACKAGE: tokenName = "PACKAGE"; break;
        case NULLABLE: tokenName = "NULLABLE"; break;
        case NON_NULLABLE: tokenName = "NON_NULLABLE"; break;
        case ASSIGN: tokenName = "ASSIGN"; break;
        case PLUS: tokenName = "PLUS"; break;
        case MINUS: tokenName = "MINUS"; break;
        case TIMES: tokenName = "TIMES"; break;
        case DIVIDE: tokenName = "DIVIDE"; break;
        case SEMICOLON: tokenName = "SEMICOLON"; break;
        case COMMA: tokenName = "COMMA"; break;
        case LPAREN: tokenName = "LPAREN"; break;
        case RPAREN: tokenName = "RPAREN"; break;
        case LBRACE: tokenName = "LBRACE"; break;
        case RBRACE: tokenName = "RBRACE"; break;
        case DOT: tokenName = "DOT"; break;
        case LT: tokenName = "LT"; break;
        case LE: tokenName = "LE"; break;
        case GT: tokenName = "GT"; break;
        case GE: tokenName = "GE"; break;
        case EQ: tokenName = "EQ"; break;
        case NE: tokenName = "NE"; break;
        case AND: tokenName = "AND"; break;
        case OR: tokenName = "OR"; break;
        case NOT: tokenName = "NOT"; break;
        case BIT_AND: tokenName = "BIT_AND"; break;
        case IDENTIFIER: tokenName = "IDENTIFIER"; break;
        case DOUBLE_TOKEN: tokenName = "DOUBLE_TOKEN"; break;
        case INT_TOKEN: tokenName = "INT_TOKEN"; break;
        case STRING_LITERAL: tokenName = "STRING_LITERAL"; break;
        case INC: tokenName = "INC"; break;         // Increment
        case DEC: tokenName = "DEC"; break;         // Decrement
        case PLUS_ASSIGN: tokenName = "PLUS_ASSIGN"; break; // Addition assignment
        case MINUS_ASSIGN: tokenName = "MINUS_ASSIGN"; break; // Subtraction assignment
        case TIMES_ASSIGN: tokenName = "TIMES_ASSIGN"; break; // Multiplication assignment
        case DIVIDE_ASSIGN: tokenName = "DIVIDE_ASSIGN"; break; // Division assignment
        case MOD: tokenName = "MOD"; break;
        case MOD_ASSIGN: tokenName = "MOD_ASSIGN"; break;
        case LSHIFT: tokenName = "LSHIFT"; break;
        case RSHIFT: tokenName = "RSHIFT"; break;
        case URSHIFT: tokenName = "URSHIFT"; break;
        case XOR: tokenName = "XOR"; break;
        case LBRACKET: tokenName = "LBRACKET"; break; // Added
        case RBRACKET: tokenName = "RBRACKET"; break; // Added
        default: tokenName = "UNKNOWN_TOKEN"; break;
    }
    std::ostringstream oss;
    oss << "<Token > at line " << lineNumber << ", column " << llcolumn << ":\t" << tokenName;
    if (!value.empty()) {
        oss << " \twith value:\t" << value;
    } else {
        oss << "  \t(Currently parsing: " << yytext << ")";
    }
    try {
        dap::util::dbg_print(std::cout, oss.str(), dap::util::FileColor::BLACK);
    } catch (const std::exception& e) {
        std::cerr << "Error in printTokenInfo: " << e.what() << std::endl;
    }
#endif

}
%}

/* Define the tokens */
%option noyywrap

%%

"include"  { printTokenInfo(INCLUDE, yylineno); llcolumn += strlen("include"); return INCLUDE; }
"package"  { printTokenInfo(PACKAGE, yylineno); llcolumn += strlen("package"); return PACKAGE; }

"if"       { printTokenInfo(IF, yylineno); llcolumn += strlen("if"); return IF; }
"else"     { printTokenInfo(ELSE, yylineno); llcolumn += strlen("else"); return ELSE; }
"elif"     { printTokenInfo(ELIF, yylineno); llcolumn += strlen("elif"); return ELIF; }
"for"      { printTokenInfo(FOR, yylineno); llcolumn += strlen("for"); return FOR; }
"return"   { printTokenInfo(RETURN, yylineno); llcolumn += strlen("return"); return RETURN; }
"fun"      { printTokenInfo(FUN, yylineno); llcolumn += strlen("fun"); return FUN; }
"var"      { printTokenInfo(VAR, yylineno); llcolumn += strlen("var"); return VAR; }
"imt"      { printTokenInfo(IMT, yylineno); llcolumn += strlen("imt"); return IMT; }
"extern"   { printTokenInfo(EXTERN, yylineno); llcolumn += strlen("extern"); return EXTERN; }
"struct"   { printTokenInfo(STRUCT, yylineno); llcolumn += strlen("struct"); return STRUCT; }
"break"    { printTokenInfo(BREAK, yylineno); llcolumn += strlen("break"); return BREAK; }
"?"        { printTokenInfo(NULLABLE, yylineno); llcolumn += strlen("?"); return NULLABLE; }
"!"        { printTokenInfo(NON_NULLABLE, yylineno); llcolumn += strlen("!"); return NON_NULLABLE; }

"="        { printTokenInfo(ASSIGN, yylineno); llcolumn += strlen("="); return ASSIGN; }
"+"        { printTokenInfo(PLUS, yylineno); llcolumn += strlen("+"); return PLUS; }
"-"        { printTokenInfo(MINUS, yylineno); llcolumn += strlen("-"); return MINUS; }
"*"        { printTokenInfo(TIMES, yylineno); llcolumn += strlen("*"); return TIMES; }
"/"        { printTokenInfo(DIVIDE, yylineno); llcolumn += strlen("/"); return DIVIDE; }
"%"        { printTokenInfo(MOD, yylineno); llcolumn += strlen("%"); return MOD; }
"++"       { printTokenInfo(INC, yylineno); llcolumn += strlen("++"); return INC; }
"--"       { printTokenInfo(DEC, yylineno); llcolumn += strlen("--"); return DEC; }
"+="       { printTokenInfo(PLUS_ASSIGN, yylineno); llcolumn += strlen("+="); return PLUS_ASSIGN; }
"-="       { printTokenInfo(MINUS_ASSIGN, yylineno); llcolumn += strlen("-="); return MINUS_ASSIGN; }
"*="       { printTokenInfo(TIMES_ASSIGN, yylineno); llcolumn += strlen("*="); return TIMES_ASSIGN; }
"/="       { printTokenInfo(DIVIDE_ASSIGN, yylineno); llcolumn += strlen("/="); return DIVIDE_ASSIGN; }
"%="       { printTokenInfo(MOD_ASSIGN, yylineno); llcolumn += strlen("%="); return MOD_ASSIGN; }
"<<"       { printTokenInfo(LSHIFT, yylineno); llcolumn += strlen("<<"); return LSHIFT; }
">>"       { printTokenInfo(RSHIFT, yylineno); llcolumn += strlen(">>"); return RSHIFT; }
">>>"      { printTokenInfo(URSHIFT, yylineno); llcolumn += strlen(">>>"); return URSHIFT; }
"^"        { printTokenInfo(XOR, yylineno); llcolumn += strlen("^"); return XOR; }

";"        { printTokenInfo(SEMICOLON, yylineno); llcolumn += strlen(";"); return SEMICOLON; }
","        { printTokenInfo(COMMA, yylineno); llcolumn += strlen(","); return COMMA; }
"("        { printTokenInfo(LPAREN, yylineno); llcolumn += strlen("("); return LPAREN; }
")"        { printTokenInfo(RPAREN, yylineno); llcolumn += strlen(")"); return RPAREN; }
"{"        { printTokenInfo(LBRACE, yylineno); llcolumn += strlen("{"); return LBRACE; }
"}"        { printTokenInfo(RBRACE, yylineno); llcolumn += strlen("}"); return RBRACE; }

"["        { printTokenInfo(LBRACKET, yylineno); llcolumn += strlen("["); return LBRACKET; } // Added
"]"        { printTokenInfo(RBRACKET, yylineno); llcolumn += strlen("]"); return RBRACKET; } // Added

"."        { printTokenInfo(DOT, yylineno); llcolumn += strlen("."); return DOT; }

"<"        { printTokenInfo(LT, yylineno); llcolumn += strlen("<"); return LT; }
"<="       { printTokenInfo(LE, yylineno); llcolumn += strlen("<="); return LE; }
">"        { printTokenInfo(GT, yylineno); llcolumn += strlen(">"); return GT; }
">="       { printTokenInfo(GE, yylineno); llcolumn += strlen(">="); return GE; }
"=="       { printTokenInfo(EQ, yylineno); llcolumn += strlen("=="); return EQ; }
"!="       { printTokenInfo(NE, yylineno); llcolumn += strlen("!="); return NE; }
"&&"       { printTokenInfo(AND, yylineno); llcolumn += strlen("&&"); return AND; }
"||"       { printTokenInfo(OR, yylineno); llcolumn += strlen("||"); return OR; }
"~"        { printTokenInfo(NOT, yylineno); llcolumn += strlen("~"); return NOT; }

"&"        { printTokenInfo(BIT_AND, yylineno); llcolumn += strlen("&"); return BIT_AND; }

[a-zA-Z_][a-zA-Z0-9_]*  { SAVE_TOKEN; printTokenInfo(IDENTIFIER, yylineno, *yylval.string); llcolumn += yyleng; return IDENTIFIER; }
[0-9]+\.[0-9]+          { SAVE_TOKEN; printTokenInfo(DOUBLE_TOKEN, yylineno, *yylval.string); llcolumn += yyleng; return DOUBLE_TOKEN; }
[0-9]+                  { SAVE_TOKEN; printTokenInfo(INT_TOKEN, yylineno, *yylval.string); llcolumn += yyleng; return INT_TOKEN; }
\"([^\\\"]|\\.)*\"      { SAVE_TOKEN; printTokenInfo(STRING_LITERAL, yylineno, *yylval.string); llcolumn += yyleng; return STRING_LITERAL; }

"//"[^\n]*  { llcolumn += yyleng; }

"/*" {
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

[ \t]    { llcolumn += yyleng; } // Update column for whitespace
\n       { ++yylineno; llcolumn = 0; } // Increment line number and reset column on newline
.        { llcolumn += yyleng; printTokenInfo(-1, yylineno, std::string(yytext, yyleng)); }

%%
