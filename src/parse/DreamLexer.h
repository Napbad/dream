
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
    BOOL = 46, CHAR = 47, STRING = 48, VOID = 49, CONST = 50, AT = 51, SLASH = 52, 
    ASSIGN = 53, SEMICOLON = 54, LPAREN = 55, RPAREN = 56, LBRACE = 57, 
    RBRACE = 58, LBRACK = 59, RBRACK = 60, COMMA = 61, LINE_COMMENT = 62, 
    COMMENT = 63, WS = 64, DOT = 65, BANG = 66, QUESTION = 67, COLON = 68, 
    MOD = 69, PLUS = 70, MINUS = 71, MUL = 72, LT = 73, GT = 74, LE = 75, 
    GE = 76, EQ = 77, NEQ = 78, AND = 79, OR = 80, BIT_AND = 81, BIT_OR = 82, 
    XOR = 83, LSHIFT = 84, RSHIFT = 85, URSHIFT = 86, NOT = 87, TIBLE = 88, 
    INC = 89, DEC = 90, IDENTIFIER = 91
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

