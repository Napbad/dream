
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "DreamParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DreamParser.
 */
class  DreamListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(DreamParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(DreamParser::ProgramContext *ctx) = 0;

  virtual void enterPackageDecl(DreamParser::PackageDeclContext *ctx) = 0;
  virtual void exitPackageDecl(DreamParser::PackageDeclContext *ctx) = 0;

  virtual void enterImportStmt(DreamParser::ImportStmtContext *ctx) = 0;
  virtual void exitImportStmt(DreamParser::ImportStmtContext *ctx) = 0;

  virtual void enterPackageName(DreamParser::PackageNameContext *ctx) = 0;
  virtual void exitPackageName(DreamParser::PackageNameContext *ctx) = 0;

  virtual void enterImportName(DreamParser::ImportNameContext *ctx) = 0;
  virtual void exitImportName(DreamParser::ImportNameContext *ctx) = 0;

  virtual void enterFunCallStmt(DreamParser::FunCallStmtContext *ctx) = 0;
  virtual void exitFunCallStmt(DreamParser::FunCallStmtContext *ctx) = 0;

  virtual void enterStmt(DreamParser::StmtContext *ctx) = 0;
  virtual void exitStmt(DreamParser::StmtContext *ctx) = 0;

  virtual void enterBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) = 0;
  virtual void exitBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) = 0;

  virtual void enterFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) = 0;
  virtual void exitFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) = 0;

  virtual void enterArgList(DreamParser::ArgListContext *ctx) = 0;
  virtual void exitArgList(DreamParser::ArgListContext *ctx) = 0;

  virtual void enterLiteral(DreamParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(DreamParser::LiteralContext *ctx) = 0;

  virtual void enterArrayInit(DreamParser::ArrayInitContext *ctx) = 0;
  virtual void exitArrayInit(DreamParser::ArrayInitContext *ctx) = 0;

  virtual void enterCastExpr(DreamParser::CastExprContext *ctx) = 0;
  virtual void exitCastExpr(DreamParser::CastExprContext *ctx) = 0;

  virtual void enterAssign(DreamParser::AssignContext *ctx) = 0;
  virtual void exitAssign(DreamParser::AssignContext *ctx) = 0;

  virtual void enterUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) = 0;
  virtual void exitUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) = 0;

  virtual void enterIfExpr(DreamParser::IfExprContext *ctx) = 0;
  virtual void exitIfExpr(DreamParser::IfExprContext *ctx) = 0;

  virtual void enterIfStmt(DreamParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(DreamParser::IfStmtContext *ctx) = 0;

  virtual void enterIfBlock(DreamParser::IfBlockContext *ctx) = 0;
  virtual void exitIfBlock(DreamParser::IfBlockContext *ctx) = 0;

  virtual void enterAtomExpr(DreamParser::AtomExprContext *ctx) = 0;
  virtual void exitAtomExpr(DreamParser::AtomExprContext *ctx) = 0;

  virtual void enterIfStmtBody(DreamParser::IfStmtBodyContext *ctx) = 0;
  virtual void exitIfStmtBody(DreamParser::IfStmtBodyContext *ctx) = 0;

  virtual void enterReturnStmt(DreamParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(DreamParser::ReturnStmtContext *ctx) = 0;

  virtual void enterElseIfClause(DreamParser::ElseIfClauseContext *ctx) = 0;
  virtual void exitElseIfClause(DreamParser::ElseIfClauseContext *ctx) = 0;

  virtual void enterElseClause(DreamParser::ElseClauseContext *ctx) = 0;
  virtual void exitElseClause(DreamParser::ElseClauseContext *ctx) = 0;

  virtual void enterExpr(DreamParser::ExprContext *ctx) = 0;
  virtual void exitExpr(DreamParser::ExprContext *ctx) = 0;

  virtual void enterAssignExpr(DreamParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(DreamParser::AssignExprContext *ctx) = 0;

  virtual void enterDeclaration(DreamParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(DreamParser::DeclarationContext *ctx) = 0;

  virtual void enterStructDeclaration(DreamParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(DreamParser::StructDeclarationContext *ctx) = 0;

  virtual void enterStructMember(DreamParser::StructMemberContext *ctx) = 0;
  virtual void exitStructMember(DreamParser::StructMemberContext *ctx) = 0;

  virtual void enterVarDeclaration(DreamParser::VarDeclarationContext *ctx) = 0;
  virtual void exitVarDeclaration(DreamParser::VarDeclarationContext *ctx) = 0;

  virtual void enterFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterFunBlock(DreamParser::FunBlockContext *ctx) = 0;
  virtual void exitFunBlock(DreamParser::FunBlockContext *ctx) = 0;

  virtual void enterFunStmt(DreamParser::FunStmtContext *ctx) = 0;
  virtual void exitFunStmt(DreamParser::FunStmtContext *ctx) = 0;

  virtual void enterThrowStmt(DreamParser::ThrowStmtContext *ctx) = 0;
  virtual void exitThrowStmt(DreamParser::ThrowStmtContext *ctx) = 0;

  virtual void enterSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) = 0;
  virtual void exitSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) = 0;

  virtual void enterTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) = 0;
  virtual void exitTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) = 0;

  virtual void enterCatches(DreamParser::CatchesContext *ctx) = 0;
  virtual void exitCatches(DreamParser::CatchesContext *ctx) = 0;

  virtual void enterCatchClause(DreamParser::CatchClauseContext *ctx) = 0;
  virtual void exitCatchClause(DreamParser::CatchClauseContext *ctx) = 0;

  virtual void enterCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) = 0;
  virtual void exitCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) = 0;

  virtual void enterCatchType(DreamParser::CatchTypeContext *ctx) = 0;
  virtual void exitCatchType(DreamParser::CatchTypeContext *ctx) = 0;

  virtual void enterFinally_(DreamParser::Finally_Context *ctx) = 0;
  virtual void exitFinally_(DreamParser::Finally_Context *ctx) = 0;

  virtual void enterMemberModifier(DreamParser::MemberModifierContext *ctx) = 0;
  virtual void exitMemberModifier(DreamParser::MemberModifierContext *ctx) = 0;

  virtual void enterVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) = 0;
  virtual void exitVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) = 0;

  virtual void enterStaticModifier(DreamParser::StaticModifierContext *ctx) = 0;
  virtual void exitStaticModifier(DreamParser::StaticModifierContext *ctx) = 0;

  virtual void enterParamList(DreamParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(DreamParser::ParamListContext *ctx) = 0;

  virtual void enterParam(DreamParser::ParamContext *ctx) = 0;
  virtual void exitParam(DreamParser::ParamContext *ctx) = 0;

  virtual void enterType(DreamParser::TypeContext *ctx) = 0;
  virtual void exitType(DreamParser::TypeContext *ctx) = 0;

  virtual void enterSingleType(DreamParser::SingleTypeContext *ctx) = 0;
  virtual void exitSingleType(DreamParser::SingleTypeContext *ctx) = 0;

  virtual void enterArrayType(DreamParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(DreamParser::ArrayTypeContext *ctx) = 0;

  virtual void enterReturnType(DreamParser::ReturnTypeContext *ctx) = 0;
  virtual void exitReturnType(DreamParser::ReturnTypeContext *ctx) = 0;

  virtual void enterForStmt(DreamParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(DreamParser::ForStmtContext *ctx) = 0;

  virtual void enterForCondition(DreamParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(DreamParser::ForConditionContext *ctx) = 0;

  virtual void enterForBlock(DreamParser::ForBlockContext *ctx) = 0;
  virtual void exitForBlock(DreamParser::ForBlockContext *ctx) = 0;

  virtual void enterForBody(DreamParser::ForBodyContext *ctx) = 0;
  virtual void exitForBody(DreamParser::ForBodyContext *ctx) = 0;

  virtual void enterForVarDecl(DreamParser::ForVarDeclContext *ctx) = 0;
  virtual void exitForVarDecl(DreamParser::ForVarDeclContext *ctx) = 0;

  virtual void enterFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) = 0;
  virtual void exitFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) = 0;

  virtual void enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) = 0;
  virtual void exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) = 0;

  virtual void enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) = 0;
  virtual void exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) = 0;

  virtual void enterFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) = 0;
  virtual void exitFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) = 0;

  virtual void enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) = 0;
  virtual void exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) = 0;

  virtual void enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) = 0;
  virtual void exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) = 0;

  virtual void enterDeleteStmt(DreamParser::DeleteStmtContext *ctx) = 0;
  virtual void exitDeleteStmt(DreamParser::DeleteStmtContext *ctx) = 0;


};

