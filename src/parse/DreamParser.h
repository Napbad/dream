
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  DreamParser : public antlr4::Parser {
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

  enum {
    RuleProgram = 0, RulePackageDecl = 1, RuleImportStmt = 2, RulePackageName = 3, 
    RuleImportName = 4, RuleFunCallStmt = 5, RuleStmt = 6, RuleBinaryOpExpr = 7, 
    RuleFunVarDeclaration = 8, RuleArgList = 9, RuleLiteral = 10, RuleArrayInit = 11, 
    RuleCastExpr = 12, RuleAssign = 13, RuleUnaryOpExpr = 14, RuleIfExpr = 15, 
    RuleIfStmt = 16, RuleIfBlock = 17, RuleAtomExpr = 18, RuleIfStmtBody = 19, 
    RuleReturnStmt = 20, RuleElseIfClause = 21, RuleElseClause = 22, RuleExpr = 23, 
    RuleAssignExpr = 24, RuleDeclaration = 25, RuleStructDeclaration = 26, 
    RuleStructMember = 27, RuleVarDeclaration = 28, RuleFunctionDeclaration = 29, 
    RuleFunBlock = 30, RuleFunStmt = 31, RuleThrowStmt = 32, RuleSynchronizedStmt = 33, 
    RuleTryCatchStmt = 34, RuleCatches = 35, RuleCatchClause = 36, RuleCatchFormalParameter = 37, 
    RuleCatchType = 38, RuleFinally_ = 39, RuleMemberModifier = 40, RuleVisibilityModifier = 41, 
    RuleStaticModifier = 42, RuleParamList = 43, RuleParam = 44, RuleType = 45, 
    RuleSingleType = 46, RuleArrayType = 47, RuleReturnType = 48, RuleForStmt = 49, 
    RuleForCondition = 50, RuleForBlock = 51, RuleForBody = 52, RuleForVarDecl = 53, 
    RuleFileCodeBlock = 54, RuleFileCodeBlockBody = 55, RuleFileCodeBlockStmt = 56, 
    RuleFunCodeBlock = 57, RuleFunCodeBlockBody = 58, RuleFunCodeBlockStmt = 59, 
    RuleDeleteStmt = 60
  };

  explicit DreamParser(antlr4::TokenStream *input);

  DreamParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DreamParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class PackageDeclContext;
  class ImportStmtContext;
  class PackageNameContext;
  class ImportNameContext;
  class FunCallStmtContext;
  class StmtContext;
  class BinaryOpExprContext;
  class FunVarDeclarationContext;
  class ArgListContext;
  class LiteralContext;
  class ArrayInitContext;
  class CastExprContext;
  class AssignContext;
  class UnaryOpExprContext;
  class IfExprContext;
  class IfStmtContext;
  class IfBlockContext;
  class AtomExprContext;
  class IfStmtBodyContext;
  class ReturnStmtContext;
  class ElseIfClauseContext;
  class ElseClauseContext;
  class ExprContext;
  class AssignExprContext;
  class DeclarationContext;
  class StructDeclarationContext;
  class StructMemberContext;
  class VarDeclarationContext;
  class FunctionDeclarationContext;
  class FunBlockContext;
  class FunStmtContext;
  class ThrowStmtContext;
  class SynchronizedStmtContext;
  class TryCatchStmtContext;
  class CatchesContext;
  class CatchClauseContext;
  class CatchFormalParameterContext;
  class CatchTypeContext;
  class Finally_Context;
  class MemberModifierContext;
  class VisibilityModifierContext;
  class StaticModifierContext;
  class ParamListContext;
  class ParamContext;
  class TypeContext;
  class SingleTypeContext;
  class ArrayTypeContext;
  class ReturnTypeContext;
  class ForStmtContext;
  class ForConditionContext;
  class ForBlockContext;
  class ForBodyContext;
  class ForVarDeclContext;
  class FileCodeBlockContext;
  class FileCodeBlockBodyContext;
  class FileCodeBlockStmtContext;
  class FunCodeBlockContext;
  class FunCodeBlockBodyContext;
  class FunCodeBlockStmtContext;
  class DeleteStmtContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    PackageDeclContext *packageDecl();
    std::vector<ImportStmtContext *> importStmt();
    ImportStmtContext* importStmt(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    std::vector<FileCodeBlockContext *> fileCodeBlock();
    FileCodeBlockContext* fileCodeBlock(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  PackageDeclContext : public antlr4::ParserRuleContext {
  public:
    PackageDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    PackageNameContext *packageName();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PackageDeclContext* packageDecl();

  class  ImportStmtContext : public antlr4::ParserRuleContext {
  public:
    ImportStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    ImportNameContext *importName();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportStmtContext* importStmt();

  class  PackageNameContext : public antlr4::ParserRuleContext {
  public:
    PackageNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PackageNameContext* packageName();

  class  ImportNameContext : public antlr4::ParserRuleContext {
  public:
    ImportNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImportNameContext* importName();

  class  FunCallStmtContext : public antlr4::ParserRuleContext {
  public:
    FunCallStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SLASH();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    ArgListContext *argList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunCallStmtContext* funCallStmt();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    FunCallStmtContext *funCallStmt();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExprContext *expr();
    IfStmtContext *ifStmt();
    ForStmtContext *forStmt();
    TryCatchStmtContext *tryCatchStmt();
    SynchronizedStmtContext *synchronizedStmt();
    DeleteStmtContext *deleteStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  BinaryOpExprContext : public antlr4::ParserRuleContext {
  public:
    BinaryOpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AtomExprContext *> atomExpr();
    AtomExprContext* atomExpr(size_t i);
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *BIT_AND();
    antlr4::tree::TerminalNode *BIT_OR();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *URSHIFT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinaryOpExprContext* binaryOpExpr();

  class  FunVarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunVarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *IMT();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunVarDeclarationContext* funVarDeclaration();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgListContext* argList();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *CHAR_LITERAL();
    antlr4::tree::TerminalNode *TRUE_LITERAL();
    antlr4::tree::TerminalNode *FALSE_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  ArrayInitContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<ArrayInitContext *> arrayInit();
    ArrayInitContext* arrayInit(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayInitContext* arrayInit();

  class  CastExprContext : public antlr4::ParserRuleContext {
  public:
    CastExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    TypeContext *type();
    antlr4::tree::TerminalNode *RPAREN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CastExprContext* castExpr();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignContext* assign();

  class  UnaryOpExprContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BANG();
    ExprContext *expr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *INC();
    antlr4::tree::TerminalNode *DEC();
    antlr4::tree::TerminalNode *TIBLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryOpExprContext* unaryOpExpr();

  class  IfExprContext : public antlr4::ParserRuleContext {
  public:
    IfExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    FunCallStmtContext *funCallStmt();
    UnaryOpExprContext *unaryOpExpr();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *URSHIFT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *BIT_AND();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *BIT_OR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    AtomExprContext *atomExpr();
    CastExprContext *castExpr();
    AssignExprContext *assignExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfExprContext* ifExpr();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    IfExprContext *ifExpr();
    IfBlockContext *ifBlock();
    std::vector<ElseIfClauseContext *> elseIfClause();
    ElseIfClauseContext* elseIfClause(size_t i);
    ElseClauseContext *elseClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStmtContext* ifStmt();

  class  IfBlockContext : public antlr4::ParserRuleContext {
  public:
    IfBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<IfStmtBodyContext *> ifStmtBody();
    IfStmtBodyContext* ifStmtBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfBlockContext* ifBlock();

  class  AtomExprContext : public antlr4::ParserRuleContext {
  public:
    AtomExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgListContext *argList();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    LiteralContext *literal();
    ArrayInitContext *arrayInit();
    CastExprContext *castExpr();
    AssignContext *assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomExprContext* atomExpr();

  class  IfStmtBodyContext : public antlr4::ParserRuleContext {
  public:
    IfStmtBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    IfStmtContext *ifStmt();
    ReturnStmtContext *returnStmt();
    ForStmtContext *forStmt();
    TryCatchStmtContext *tryCatchStmt();
    ThrowStmtContext *throwStmt();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    FunCallStmtContext *funCallStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStmtBodyContext* ifStmtBody();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStmtContext* returnStmt();

  class  ElseIfClauseContext : public antlr4::ParserRuleContext {
  public:
    ElseIfClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *IF();
    IfExprContext *ifExpr();
    IfBlockContext *ifBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseIfClauseContext* elseIfClause();

  class  ElseClauseContext : public antlr4::ParserRuleContext {
  public:
    ElseClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    IfBlockContext *ifBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ElseClauseContext* elseClause();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    FunCallStmtContext *funCallStmt();
    UnaryOpExprContext *unaryOpExpr();
    AtomExprContext *atomExpr();
    CastExprContext *castExpr();
    AssignExprContext *assignExpr();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *URSHIFT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *BIT_AND();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *BIT_OR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  AssignExprContext : public antlr4::ParserRuleContext {
  public:
    AssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    AssignContext *assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignExprContext* assignExpr();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDeclarationContext *varDeclaration();
    FunctionDeclarationContext *functionDeclaration();
    StructDeclarationContext *structDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeclarationContext* declaration();

  class  StructDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRUCT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<StructMemberContext *> structMember();
    StructMemberContext* structMember(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructDeclarationContext* structDeclaration();

  class  StructMemberContext : public antlr4::ParserRuleContext {
  public:
    StructMemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDeclarationContext *varDeclaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructMemberContext* structMember();

  class  VarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *IMT();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarDeclarationContext* varDeclaration();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    FunBlockContext *funBlock();
    ParamListContext *paramList();
    ReturnTypeContext *returnType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  FunBlockContext : public antlr4::ParserRuleContext {
  public:
    FunBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<FunStmtContext *> funStmt();
    FunStmtContext* funStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunBlockContext* funBlock();

  class  FunStmtContext : public antlr4::ParserRuleContext {
  public:
    FunStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TryCatchStmtContext *tryCatchStmt();
    antlr4::tree::TerminalNode *NATIVE();
    antlr4::tree::TerminalNode *SEMICOLON();
    IfStmtContext *ifStmt();
    ForStmtContext *forStmt();
    FunVarDeclarationContext *funVarDeclaration();
    ReturnStmtContext *returnStmt();
    ExprContext *expr();
    ThrowStmtContext *throwStmt();
    FileCodeBlockContext *fileCodeBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunStmtContext* funStmt();

  class  ThrowStmtContext : public antlr4::ParserRuleContext {
  public:
    ThrowStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THROW();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ThrowStmtContext* throwStmt();

  class  SynchronizedStmtContext : public antlr4::ParserRuleContext {
  public:
    SynchronizedStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYNCHRONIZED();
    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();
    FileCodeBlockContext *fileCodeBlock();
    FunCodeBlockContext *funCodeBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SynchronizedStmtContext* synchronizedStmt();

  class  TryCatchStmtContext : public antlr4::ParserRuleContext {
  public:
    TryCatchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRY();
    FunCodeBlockContext *funCodeBlock();
    CatchesContext *catches();
    Finally_Context *finally_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TryCatchStmtContext* tryCatchStmt();

  class  CatchesContext : public antlr4::ParserRuleContext {
  public:
    CatchesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CatchClauseContext *> catchClause();
    CatchClauseContext* catchClause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CatchesContext* catches();

  class  CatchClauseContext : public antlr4::ParserRuleContext {
  public:
    CatchClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCH();
    CatchFormalParameterContext *catchFormalParameter();
    FunCodeBlockContext *funCodeBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CatchClauseContext* catchClause();

  class  CatchFormalParameterContext : public antlr4::ParserRuleContext {
  public:
    CatchFormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatchTypeContext *catchType();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CatchFormalParameterContext* catchFormalParameter();

  class  CatchTypeContext : public antlr4::ParserRuleContext {
  public:
    CatchTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BIT_OR();
    antlr4::tree::TerminalNode* BIT_OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CatchTypeContext* catchType();

  class  Finally_Context : public antlr4::ParserRuleContext {
  public:
    Finally_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FINALLY();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Finally_Context* finally_();

  class  MemberModifierContext : public antlr4::ParserRuleContext {
  public:
    MemberModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OVERRIDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MemberModifierContext* memberModifier();

  class  VisibilityModifierContext : public antlr4::ParserRuleContext {
  public:
    VisibilityModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PROTECTED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VisibilityModifierContext* visibilityModifier();

  class  StaticModifierContext : public antlr4::ParserRuleContext {
  public:
    StaticModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StaticModifierContext* staticModifier();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamListContext* paramList();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *IMT();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamContext* param();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayTypeContext *arrayType();
    SingleTypeContext *singleType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  SingleTypeContext : public antlr4::ParserRuleContext {
  public:
    SingleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BYTE();
    antlr4::tree::TerminalNode *SHORT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LONG();
    antlr4::tree::TerminalNode *USHORT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *ULONG();
    antlr4::tree::TerminalNode *LONGLONG();
    antlr4::tree::TerminalNode *ULONGLONG();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SingleTypeContext* singleType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleTypeContext *singleType();
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ReturnTypeContext : public antlr4::ParserRuleContext {
  public:
    ReturnTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BANG();
    antlr4::tree::TerminalNode* BANG(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUESTION();
    antlr4::tree::TerminalNode* QUESTION(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *VOID();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnTypeContext* returnType();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    ForConditionContext *forCondition();
    ForBlockContext *forBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStmtContext* forStmt();

  class  ForConditionContext : public antlr4::ParserRuleContext {
  public:
    ForConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForVarDeclContext *forVarDecl();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForConditionContext* forCondition();

  class  ForBlockContext : public antlr4::ParserRuleContext {
  public:
    ForBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ForBodyContext *> forBody();
    ForBodyContext* forBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForBlockContext* forBlock();

  class  ForBodyContext : public antlr4::ParserRuleContext {
  public:
    ForBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    FunVarDeclarationContext *funVarDeclaration();
    IfStmtContext *ifStmt();
    ForStmtContext *forStmt();
    ReturnStmtContext *returnStmt();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    FunCallStmtContext *funCallStmt();
    DeleteStmtContext *deleteStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForBodyContext* forBody();

  class  ForVarDeclContext : public antlr4::ParserRuleContext {
  public:
    ForVarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForVarDeclContext* forVarDecl();

  class  FileCodeBlockContext : public antlr4::ParserRuleContext {
  public:
    FileCodeBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<FileCodeBlockBodyContext *> fileCodeBlockBody();
    FileCodeBlockBodyContext* fileCodeBlockBody(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileCodeBlockContext* fileCodeBlock();

  class  FileCodeBlockBodyContext : public antlr4::ParserRuleContext {
  public:
    FileCodeBlockBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FileCodeBlockStmtContext *fileCodeBlockStmt();
    FileCodeBlockContext *fileCodeBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileCodeBlockBodyContext* fileCodeBlockBody();

  class  FileCodeBlockStmtContext : public antlr4::ParserRuleContext {
  public:
    FileCodeBlockStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    DeclarationContext *declaration();
    IfStmtContext *ifStmt();
    ForStmtContext *forStmt();
    ReturnStmtContext *returnStmt();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    FunCallStmtContext *funCallStmt();
    ThrowStmtContext *throwStmt();
    TryCatchStmtContext *tryCatchStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileCodeBlockStmtContext* fileCodeBlockStmt();

  class  FunCodeBlockContext : public antlr4::ParserRuleContext {
  public:
    FunCodeBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    FunCodeBlockBodyContext *funCodeBlockBody();
    antlr4::tree::TerminalNode *RBRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunCodeBlockContext* funCodeBlock();

  class  FunCodeBlockBodyContext : public antlr4::ParserRuleContext {
  public:
    FunCodeBlockBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunCodeBlockStmtContext *> funCodeBlockStmt();
    FunCodeBlockStmtContext* funCodeBlockStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunCodeBlockBodyContext* funCodeBlockBody();

  class  FunCodeBlockStmtContext : public antlr4::ParserRuleContext {
  public:
    FunCodeBlockStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    IfStmtContext *ifStmt();
    ForStmtContext *forStmt();
    ReturnStmtContext *returnStmt();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    FunCallStmtContext *funCallStmt();
    ThrowStmtContext *throwStmt();
    TryCatchStmtContext *tryCatchStmt();
    DeleteStmtContext *deleteStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunCodeBlockStmtContext* funCodeBlockStmt();

  class  DeleteStmtContext : public antlr4::ParserRuleContext {
  public:
    DeleteStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DeleteStmtContext* deleteStmt();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

