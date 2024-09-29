
// Generated from ./Dream.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "DreamListener.h"


/**
 * This class provides an empty implementation of DreamListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DreamBaseListener : public DreamListener {
public:

  virtual void enterProgram(DreamParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(DreamParser::ProgramContext * /*ctx*/) override { }

  virtual void enterPackageDecl(DreamParser::PackageDeclContext * /*ctx*/) override { }
  virtual void exitPackageDecl(DreamParser::PackageDeclContext * /*ctx*/) override { }

  virtual void enterImportStmt(DreamParser::ImportStmtContext * /*ctx*/) override { }
  virtual void exitImportStmt(DreamParser::ImportStmtContext * /*ctx*/) override { }

  virtual void enterPackageName(DreamParser::PackageNameContext * /*ctx*/) override { }
  virtual void exitPackageName(DreamParser::PackageNameContext * /*ctx*/) override { }

  virtual void enterImportName(DreamParser::ImportNameContext * /*ctx*/) override { }
  virtual void exitImportName(DreamParser::ImportNameContext * /*ctx*/) override { }

  virtual void enterFunCallStmt(DreamParser::FunCallStmtContext * /*ctx*/) override { }
  virtual void exitFunCallStmt(DreamParser::FunCallStmtContext * /*ctx*/) override { }

  virtual void enterStmt(DreamParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(DreamParser::StmtContext * /*ctx*/) override { }

  virtual void enterBinaryOpExpr(DreamParser::BinaryOpExprContext * /*ctx*/) override { }
  virtual void exitBinaryOpExpr(DreamParser::BinaryOpExprContext * /*ctx*/) override { }

  virtual void enterArgList(DreamParser::ArgListContext * /*ctx*/) override { }
  virtual void exitArgList(DreamParser::ArgListContext * /*ctx*/) override { }

  virtual void enterLiteral(DreamParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(DreamParser::LiteralContext * /*ctx*/) override { }

  virtual void enterArrayInit(DreamParser::ArrayInitContext * /*ctx*/) override { }
  virtual void exitArrayInit(DreamParser::ArrayInitContext * /*ctx*/) override { }

  virtual void enterCastExpr(DreamParser::CastExprContext * /*ctx*/) override { }
  virtual void exitCastExpr(DreamParser::CastExprContext * /*ctx*/) override { }

  virtual void enterAssign(DreamParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(DreamParser::AssignContext * /*ctx*/) override { }

  virtual void enterUnaryOpExpr(DreamParser::UnaryOpExprContext * /*ctx*/) override { }
  virtual void exitUnaryOpExpr(DreamParser::UnaryOpExprContext * /*ctx*/) override { }

  virtual void enterIfStmt(DreamParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(DreamParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterIfBlock(DreamParser::IfBlockContext * /*ctx*/) override { }
  virtual void exitIfBlock(DreamParser::IfBlockContext * /*ctx*/) override { }

  virtual void enterAtomExpr(DreamParser::AtomExprContext * /*ctx*/) override { }
  virtual void exitAtomExpr(DreamParser::AtomExprContext * /*ctx*/) override { }

  virtual void enterIfStmtBody(DreamParser::IfStmtBodyContext * /*ctx*/) override { }
  virtual void exitIfStmtBody(DreamParser::IfStmtBodyContext * /*ctx*/) override { }

  virtual void enterReturnStmt(DreamParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(DreamParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterElseIfClause(DreamParser::ElseIfClauseContext * /*ctx*/) override { }
  virtual void exitElseIfClause(DreamParser::ElseIfClauseContext * /*ctx*/) override { }

  virtual void enterElseClause(DreamParser::ElseClauseContext * /*ctx*/) override { }
  virtual void exitElseClause(DreamParser::ElseClauseContext * /*ctx*/) override { }

  virtual void enterExpr(DreamParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(DreamParser::ExprContext * /*ctx*/) override { }

  virtual void enterAssignExpr(DreamParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(DreamParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterDeclaration(DreamParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(DreamParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVarDeclaration(DreamParser::VarDeclarationContext * /*ctx*/) override { }
  virtual void exitVarDeclaration(DreamParser::VarDeclarationContext * /*ctx*/) override { }

  virtual void enterVarModifiers(DreamParser::VarModifiersContext * /*ctx*/) override { }
  virtual void exitVarModifiers(DreamParser::VarModifiersContext * /*ctx*/) override { }

  virtual void enterFunctionDeclaration(DreamParser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(DreamParser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterFunBlock(DreamParser::FunBlockContext * /*ctx*/) override { }
  virtual void exitFunBlock(DreamParser::FunBlockContext * /*ctx*/) override { }

  virtual void enterFunStmt(DreamParser::FunStmtContext * /*ctx*/) override { }
  virtual void exitFunStmt(DreamParser::FunStmtContext * /*ctx*/) override { }

  virtual void enterFunVarDeclaration(DreamParser::FunVarDeclarationContext * /*ctx*/) override { }
  virtual void exitFunVarDeclaration(DreamParser::FunVarDeclarationContext * /*ctx*/) override { }

  virtual void enterFunModifiers(DreamParser::FunModifiersContext * /*ctx*/) override { }
  virtual void exitFunModifiers(DreamParser::FunModifiersContext * /*ctx*/) override { }

  virtual void enterClassDeclaration(DreamParser::ClassDeclarationContext * /*ctx*/) override { }
  virtual void exitClassDeclaration(DreamParser::ClassDeclarationContext * /*ctx*/) override { }

  virtual void enterClassModifiers(DreamParser::ClassModifiersContext * /*ctx*/) override { }
  virtual void exitClassModifiers(DreamParser::ClassModifiersContext * /*ctx*/) override { }

  virtual void enterClassModifier(DreamParser::ClassModifierContext * /*ctx*/) override { }
  virtual void exitClassModifier(DreamParser::ClassModifierContext * /*ctx*/) override { }

  virtual void enterClassBlock(DreamParser::ClassBlockContext * /*ctx*/) override { }
  virtual void exitClassBlock(DreamParser::ClassBlockContext * /*ctx*/) override { }

  virtual void enterClassBody(DreamParser::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(DreamParser::ClassBodyContext * /*ctx*/) override { }

  virtual void enterClassVarDecl(DreamParser::ClassVarDeclContext * /*ctx*/) override { }
  virtual void exitClassVarDecl(DreamParser::ClassVarDeclContext * /*ctx*/) override { }

  virtual void enterClassFuncDecl(DreamParser::ClassFuncDeclContext * /*ctx*/) override { }
  virtual void exitClassFuncDecl(DreamParser::ClassFuncDeclContext * /*ctx*/) override { }

  virtual void enterClassMemberModifier(DreamParser::ClassMemberModifierContext * /*ctx*/) override { }
  virtual void exitClassMemberModifier(DreamParser::ClassMemberModifierContext * /*ctx*/) override { }

  virtual void enterConstructorDecl(DreamParser::ConstructorDeclContext * /*ctx*/) override { }
  virtual void exitConstructorDecl(DreamParser::ConstructorDeclContext * /*ctx*/) override { }

  virtual void enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext * /*ctx*/) override { }
  virtual void exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext * /*ctx*/) override { }

  virtual void enterThrowStmt(DreamParser::ThrowStmtContext * /*ctx*/) override { }
  virtual void exitThrowStmt(DreamParser::ThrowStmtContext * /*ctx*/) override { }

  virtual void enterSynchronizedStmt(DreamParser::SynchronizedStmtContext * /*ctx*/) override { }
  virtual void exitSynchronizedStmt(DreamParser::SynchronizedStmtContext * /*ctx*/) override { }

  virtual void enterTryCatchStmt(DreamParser::TryCatchStmtContext * /*ctx*/) override { }
  virtual void exitTryCatchStmt(DreamParser::TryCatchStmtContext * /*ctx*/) override { }

  virtual void enterCatches(DreamParser::CatchesContext * /*ctx*/) override { }
  virtual void exitCatches(DreamParser::CatchesContext * /*ctx*/) override { }

  virtual void enterCatchClause(DreamParser::CatchClauseContext * /*ctx*/) override { }
  virtual void exitCatchClause(DreamParser::CatchClauseContext * /*ctx*/) override { }

  virtual void enterCatchFormalParameter(DreamParser::CatchFormalParameterContext * /*ctx*/) override { }
  virtual void exitCatchFormalParameter(DreamParser::CatchFormalParameterContext * /*ctx*/) override { }

  virtual void enterCatchType(DreamParser::CatchTypeContext * /*ctx*/) override { }
  virtual void exitCatchType(DreamParser::CatchTypeContext * /*ctx*/) override { }

  virtual void enterFinally_(DreamParser::Finally_Context * /*ctx*/) override { }
  virtual void exitFinally_(DreamParser::Finally_Context * /*ctx*/) override { }

  virtual void enterMemberModifier(DreamParser::MemberModifierContext * /*ctx*/) override { }
  virtual void exitMemberModifier(DreamParser::MemberModifierContext * /*ctx*/) override { }

  virtual void enterVisibilityModifier(DreamParser::VisibilityModifierContext * /*ctx*/) override { }
  virtual void exitVisibilityModifier(DreamParser::VisibilityModifierContext * /*ctx*/) override { }

  virtual void enterStaticModifier(DreamParser::StaticModifierContext * /*ctx*/) override { }
  virtual void exitStaticModifier(DreamParser::StaticModifierContext * /*ctx*/) override { }

  virtual void enterInterfaceDeclaration(DreamParser::InterfaceDeclarationContext * /*ctx*/) override { }
  virtual void exitInterfaceDeclaration(DreamParser::InterfaceDeclarationContext * /*ctx*/) override { }

  virtual void enterInterfaceBlock(DreamParser::InterfaceBlockContext * /*ctx*/) override { }
  virtual void exitInterfaceBlock(DreamParser::InterfaceBlockContext * /*ctx*/) override { }

  virtual void enterInterfaceBody(DreamParser::InterfaceBodyContext * /*ctx*/) override { }
  virtual void exitInterfaceBody(DreamParser::InterfaceBodyContext * /*ctx*/) override { }

  virtual void enterInterfaceVarDecl(DreamParser::InterfaceVarDeclContext * /*ctx*/) override { }
  virtual void exitInterfaceVarDecl(DreamParser::InterfaceVarDeclContext * /*ctx*/) override { }

  virtual void enterInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext * /*ctx*/) override { }
  virtual void exitInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext * /*ctx*/) override { }

  virtual void enterAnnotationDeclaration(DreamParser::AnnotationDeclarationContext * /*ctx*/) override { }
  virtual void exitAnnotationDeclaration(DreamParser::AnnotationDeclarationContext * /*ctx*/) override { }

  virtual void enterAnnotationBlock(DreamParser::AnnotationBlockContext * /*ctx*/) override { }
  virtual void exitAnnotationBlock(DreamParser::AnnotationBlockContext * /*ctx*/) override { }

  virtual void enterAnnotation(DreamParser::AnnotationContext * /*ctx*/) override { }
  virtual void exitAnnotation(DreamParser::AnnotationContext * /*ctx*/) override { }

  virtual void enterQualifiedName(DreamParser::QualifiedNameContext * /*ctx*/) override { }
  virtual void exitQualifiedName(DreamParser::QualifiedNameContext * /*ctx*/) override { }

  virtual void enterParamList(DreamParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(DreamParser::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(DreamParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(DreamParser::ParamContext * /*ctx*/) override { }

  virtual void enterType(DreamParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(DreamParser::TypeContext * /*ctx*/) override { }

  virtual void enterSingleType(DreamParser::SingleTypeContext * /*ctx*/) override { }
  virtual void exitSingleType(DreamParser::SingleTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(DreamParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(DreamParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterReturnType(DreamParser::ReturnTypeContext * /*ctx*/) override { }
  virtual void exitReturnType(DreamParser::ReturnTypeContext * /*ctx*/) override { }

  virtual void enterForStmt(DreamParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(DreamParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterForCondition(DreamParser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(DreamParser::ForConditionContext * /*ctx*/) override { }

  virtual void enterForBlock(DreamParser::ForBlockContext * /*ctx*/) override { }
  virtual void exitForBlock(DreamParser::ForBlockContext * /*ctx*/) override { }

  virtual void enterForBody(DreamParser::ForBodyContext * /*ctx*/) override { }
  virtual void exitForBody(DreamParser::ForBodyContext * /*ctx*/) override { }

  virtual void enterForVarDecl(DreamParser::ForVarDeclContext * /*ctx*/) override { }
  virtual void exitForVarDecl(DreamParser::ForVarDeclContext * /*ctx*/) override { }

  virtual void enterFileCodeBlock(DreamParser::FileCodeBlockContext * /*ctx*/) override { }
  virtual void exitFileCodeBlock(DreamParser::FileCodeBlockContext * /*ctx*/) override { }

  virtual void enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext * /*ctx*/) override { }
  virtual void exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext * /*ctx*/) override { }

  virtual void enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext * /*ctx*/) override { }
  virtual void exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext * /*ctx*/) override { }

  virtual void enterFunCodeBlock(DreamParser::FunCodeBlockContext * /*ctx*/) override { }
  virtual void exitFunCodeBlock(DreamParser::FunCodeBlockContext * /*ctx*/) override { }

  virtual void enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext * /*ctx*/) override { }
  virtual void exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext * /*ctx*/) override { }

  virtual void enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext * /*ctx*/) override { }
  virtual void exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

