
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
    NATIVE = 26, SYNCHRONIZED = 27, THROW = 28, DELETE = 29, STRING_LITERAL = 30, 
    CHAR_LITERAL = 31, INT_LITERAL = 32, FLOAT_LITERAL = 33, TRUE_LITERAL = 34, 
    FALSE_LITERAL = 35, BYTE = 36, SHORT = 37, INT = 38, UINT = 39, USHORT = 40, 
    LONG = 41, ULONG = 42, LONGLONG = 43, ULONGLONG = 44, FLOAT = 45, DOUBLE = 46, 
    BOOL = 47, CHAR = 48, STRING = 49, VOID = 50, CONST = 51, AT = 52, SLASH = 53, 
    ASSIGN = 54, SEMICOLON = 55, LPAREN = 56, RPAREN = 57, LBRACE = 58, 
    RBRACE = 59, LBRACK = 60, RBRACK = 61, COMMA = 62, LINE_COMMENT = 63, 
    COMMENT = 64, WS = 65, DOT = 66, BANG = 67, QUESTION = 68, COLON = 69, 
    MOD = 70, PLUS = 71, MINUS = 72, MUL = 73, LT = 74, GT = 75, LE = 76, 
    GE = 77, EQ = 78, NEQ = 79, AND = 80, OR = 81, BIT_AND = 82, BIT_OR = 83, 
    XOR = 84, LSHIFT = 85, RSHIFT = 86, URSHIFT = 87, NOT = 88, TIBLE = 89, 
    INC = 90, DEC = 91, IDENTIFIER = 92
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

