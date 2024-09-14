
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
    BYTE = 34, SHORT = 35, INT = 36, LONG = 37, FLOAT = 38, DOUBLE = 39, 
    BOOL = 40, CHAR = 41, STRING = 42, VOID = 43, AT = 44, ASSIGN = 45, 
    SEMICOLON = 46, LPAREN = 47, RPAREN = 48, LBRACE = 49, RBRACE = 50, 
    LBRACK = 51, RBRACK = 52, COMMA = 53, LINE_COMMENT = 54, COMMENT = 55, 
    WS = 56, DOT = 57, BANG = 58, QUESTION = 59, COLON = 60, MOD = 61, PLUS = 62, 
    MINUS = 63, MUL = 64, DIV = 65, LT = 66, GT = 67, LE = 68, GE = 69, 
    EQ = 70, NEQ = 71, AND = 72, OR = 73, BIT_AND = 74, BIT_OR = 75, XOR = 76, 
    LSHIFT = 77, RSHIFT = 78, URSHIFT = 79, NOT = 80, TIBLE = 81, INC = 82, 
    DEC = 83, IDENTIFIER = 84
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

