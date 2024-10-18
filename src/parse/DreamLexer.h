
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DreamLexer : public antlr4::Lexer {
public:
  enum {
    STRING_LITERAL = 1, RETURN = 2, IF = 3, ELSE = 4, FOR = 5, WHILE = 6, 
    PACKAGE = 7, IMPORT = 8, BREAK = 9, CONTINUE = 10, TRY = 11, CATCH = 12, 
    FINALLY = 13, VAR = 14, IMT = 15, FUN = 16, CLASS = 17, ENUM = 18, INTERFACE = 19, 
    ANNOTATION = 20, PUBLIC = 21, PRIVATE = 22, PROTECTED = 23, STATIC = 24, 
    NEW = 25, OVERRIDE = 26, NATIVE = 27, SYNCHRONIZED = 28, THROW = 29, 
    DELETE = 30, BYTE = 31, SHORT = 32, INT = 33, UINT = 34, USHORT = 35, 
    LONG = 36, ULONG = 37, LONGLONG = 38, ULONGLONG = 39, FLOAT = 40, DOUBLE = 41, 
    BOOL = 42, CHAR = 43, STRING = 44, VOID = 45, CONST = 46, CHAR_LITERAL = 47, 
    INT_LITERAL = 48, FLOAT_LITERAL = 49, TRUE_LITERAL = 50, FALSE_LITERAL = 51, 
    AT = 52, SLASH = 53, ASSIGN = 54, SEMICOLON = 55, LPAREN = 56, RPAREN = 57, 
    LBRACE = 58, RBRACE = 59, LBRACK = 60, RBRACK = 61, COMMA = 62, LINE_COMMENT = 63, 
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

