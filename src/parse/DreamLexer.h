
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DreamLexer : public antlr4::Lexer {
public:
  enum {
    STRING_LITERAL = 1, RETURN = 2, IF = 3, ELSE = 4, FOR = 5, WHILE = 6, 
    PACKAGE = 7, IMPORT = 8, BREAK = 9, CONTINUE = 10, TRY = 11, CATCH = 12, 
    FINALLY = 13, VAR = 14, IMT = 15, FUN = 16, ENUM = 17, STRUCT = 18, 
    PUBLIC = 19, PRIVATE = 20, PROTECTED = 21, STATIC = 22, NEW = 23, OVERRIDE = 24, 
    NATIVE = 25, SYNCHRONIZED = 26, THROW = 27, DELETE = 28, BYTE = 29, 
    SHORT = 30, INT = 31, UINT = 32, USHORT = 33, LONG = 34, ULONG = 35, 
    LONGLONG = 36, ULONGLONG = 37, FLOAT = 38, DOUBLE = 39, BOOL = 40, CHAR = 41, 
    STRING = 42, VOID = 43, CONST = 44, CHAR_LITERAL = 45, INT_LITERAL = 46, 
    FLOAT_LITERAL = 47, TRUE_LITERAL = 48, FALSE_LITERAL = 49, AT = 50, 
    SLASH = 51, ASSIGN = 52, SEMICOLON = 53, LPAREN = 54, RPAREN = 55, LBRACE = 56, 
    RBRACE = 57, LBRACK = 58, RBRACK = 59, COMMA = 60, LINE_COMMENT = 61, 
    COMMENT = 62, WS = 63, DOT = 64, BANG = 65, QUESTION = 66, COLON = 67, 
    MOD = 68, PLUS = 69, MINUS = 70, MUL = 71, LT = 72, GT = 73, LE = 74, 
    GE = 75, EQ = 76, NEQ = 77, AND = 78, OR = 79, BIT_AND = 80, BIT_OR = 81, 
    XOR = 82, LSHIFT = 83, RSHIFT = 84, URSHIFT = 85, NOT = 86, TIBLE = 87, 
    INC = 88, DEC = 89, IDENTIFIER = 90
  };

  explicit DreamLexer(antlr4::CharStream *input);

  ~DreamLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

