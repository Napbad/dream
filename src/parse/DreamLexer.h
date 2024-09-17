
// Generated from Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DreamLexer : public antlr4::Lexer {
public:
  enum {
    RETURN = 1, IF = 2, ELSE = 3, FOR = 4, WHILE = 5, PACKAGE = 6, IMPORT = 7, 
    BREAK = 8, CONTINUE = 9, TRY = 10, CATCH = 11, FINALLY = 12, VAR = 13, 
    IMT = 14, FUN = 15, CLASS = 16, ENUM = 17, INTERFACE = 18, ANNOTATION = 19, 
    PUBLIC = 20, PRIVATE = 21, PROTECTED = 22, STATIC = 23, NEW = 24, OVERRIDE = 25, 
    SYNCHRONIZED = 26, THROW = 27, STRING_LITERAL = 28, CHAR_LITERAL = 29, 
    INT_LITERAL = 30, FLOAT_LITERAL = 31, TRUE_LITERAL = 32, FALSE_LITERAL = 33, 
    BYTE = 34, SHORT = 35, INT = 36, UINT = 37, USHORT = 38, LONG = 39, 
    ULONG = 40, LONGLONG = 41, ULONGLONG = 42, FLOAT = 43, DOUBLE = 44, 
    BOOL = 45, CHAR = 46, STRING = 47, VOID = 48, AT = 49, ASSIGN = 50, 
    SEMICOLON = 51, LPAREN = 52, RPAREN = 53, LBRACE = 54, RBRACE = 55, 
    LBRACK = 56, RBRACK = 57, COMMA = 58, LINE_COMMENT = 59, COMMENT = 60, 
    WS = 61, DOT = 62, BANG = 63, QUESTION = 64, COLON = 65, MOD = 66, PLUS = 67, 
    MINUS = 68, MUL = 69, DIV = 70, LT = 71, GT = 72, LE = 73, GE = 74, 
    EQ = 75, NEQ = 76, AND = 77, OR = 78, BIT_AND = 79, BIT_OR = 80, XOR = 81, 
    LSHIFT = 82, RSHIFT = 83, URSHIFT = 84, NOT = 85, TIBLE = 86, INC = 87, 
    DEC = 88, IDENTIFIER = 89
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

