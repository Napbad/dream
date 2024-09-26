
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DreamLexer : public antlr4::Lexer {
public:
  enum {
    RETURN = 1, IF = 2, ELSE = 3, FOR = 4, WHILE = 5, PACKAGE = 6, IMPORT = 7, 
    BREAK = 8, CONTINUE = 9, TRY = 10, CATCH = 11, FINALLY = 12, VAR = 13, 
    IMT = 14, FUN = 15, CLASS = 16, ENUM = 17, INTERFACE = 18, ANNOTATION = 19, 
    PUBLIC = 20, PRIVATE = 21, PROTECTED = 22, STATIC = 23, NEW = 24, OVERRIDE = 25, 
    NATIVE = 26, SYNCHRONIZED = 27, THROW = 28, STRING_LITERAL = 29, CHAR_LITERAL = 30, 
    INT_LITERAL = 31, FLOAT_LITERAL = 32, TRUE_LITERAL = 33, FALSE_LITERAL = 34, 
    BYTE = 35, SHORT = 36, INT = 37, UINT = 38, USHORT = 39, LONG = 40, 
    ULONG = 41, LONGLONG = 42, ULONGLONG = 43, FLOAT = 44, DOUBLE = 45, 
    BOOL = 46, CHAR = 47, STRING = 48, VOID = 49, AT = 50, ASSIGN = 51, 
    SEMICOLON = 52, LPAREN = 53, RPAREN = 54, LBRACE = 55, RBRACE = 56, 
    LBRACK = 57, RBRACK = 58, COMMA = 59, LINE_COMMENT = 60, COMMENT = 61, 
    WS = 62, DOT = 63, BANG = 64, QUESTION = 65, COLON = 66, MOD = 67, PLUS = 68, 
    MINUS = 69, MUL = 70, DIV = 71, LT = 72, GT = 73, LE = 74, GE = 75, 
    EQ = 76, NEQ = 77, AND = 78, OR = 79, BIT_AND = 80, BIT_OR = 81, XOR = 82, 
    LSHIFT = 83, RSHIFT = 84, URSHIFT = 85, NOT = 86, TIBLE = 87, INC = 88, 
    DEC = 89, IDENTIFIER = 90
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

