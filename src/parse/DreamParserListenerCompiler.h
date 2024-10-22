//
// Created by napbad on 9/23/24.
//

#ifndef DREAMPARSERLISTENERCOMPILER_H
#define DREAMPARSERLISTENERCOMPILER_H
#include "DreamBaseListener.h"
#include "compiler/gen/ClassCodeGenerator.h"
#include "compiler/gen/ClassVarGenerator.h"
#include "compiler/gen/FileStructGenerator.h"
#include "compiler/gen/FunVarGenerator.h"
#include "compiler/gen/FileVarGenerator.h"
#include "compiler/gen/FunDataRootGenerator.h"
#include "compiler/gen/FunGenerator.h"
#include "compiler/gen/StructDataCodeGenerator.h"
#include "obj/Global.h"

class ClassFunGenerator;
class FileVarGenerator;
class FunVarGenerator;

class DreamParserListenerCompiler final : public DreamBaseListener {

public:
    DreamParserListenerCompiler(const std::string & file_source, const std::string & file_name, Global * global);

    ~DreamParserListenerCompiler() override;

    string file_source();
    Hierarchy* current_hierarchy() const;


private:

    // the file that contains the translated code
    std::string _file_name;

    // identifier for every function and class, struct
    std::string _identifier;

    // the current package class_name
    std::string _package_name;

    // the file stream, to the _file_name
    std::fstream _file_stream;

    // the header file steam, to the _header_file_name
    std::fstream _header_file_stream;

    // translate global configs
    Global *_global;

    // the corresponding file path to the _file_name
    std::string _file_path;

    // the source file
    std::string _file_source;

    // the root package path
    std::string _root_path_to_include;

    // the converted file
    std::vector<std::string> _converted_file;

    // the hierarchy that is resolved currently
    Hierarchy *_current_hierarchy;

    // package's hierarchy
    Hierarchy *_package_hierarchy;

    // class code generator
    ClassCodeGenerator *_class_code_generator;

    // struct data code generator
    StructDataCodeGenerator *_input_struct_data_code_generator;
    StructDataCodeGenerator *_own_struct_data_code_generator;
    FunVarGenerator *_fun_var_generator;
    FileVarGenerator *_file_var_generator;
    FunGenerator *_fun_generator;
    ClassFunGenerator *_class_fun_generator;
    FileStructGenerator *_file_struct_generator;
    ClassVarGenerator *_class_var_generator;
    FunDataRootGenerator *_fun_data_root_generator;

    // flags
    bool _is_in_class = false;
    bool _is_in_for_loop = false;
    bool _is_in_for_condition = false;
    size_t _curr_fun_begin_pos = 0;
    bool _is_in_if_cond = false;

    void enterProgram(DreamParser::ProgramContext * /*ctx*/) override;
    void exitProgram(DreamParser::ProgramContext * /*ctx*/) override;

    void enterPackageDecl(DreamParser::PackageDeclContext * /*ctx*/) override;
    void exitPackageDecl(DreamParser::PackageDeclContext * /*ctx*/) override;

    void enterImportStmt(DreamParser::ImportStmtContext * /*ctx*/) override;
    void exitImportStmt(DreamParser::ImportStmtContext * /*ctx*/) override;

    void enterPackageName(DreamParser::PackageNameContext * /*ctx*/) override;
    void exitPackageName(DreamParser::PackageNameContext * /*ctx*/) override;

    void enterImportName(DreamParser::ImportNameContext * /*ctx*/) override;
    void exitImportName(DreamParser::ImportNameContext * /*ctx*/) override;

    void enterFunCallStmt(DreamParser::FunCallStmtContext * /*ctx*/) override;
    void exitFunCallStmt(DreamParser::FunCallStmtContext * /*ctx*/) override;

    void enterStmt(DreamParser::StmtContext * /*ctx*/) override;
    void exitStmt(DreamParser::StmtContext * /*ctx*/) override;

    void enterBinaryOpExpr(DreamParser::BinaryOpExprContext * /*ctx*/) override;
    void exitBinaryOpExpr(DreamParser::BinaryOpExprContext * /*ctx*/) override;

    void enterArgList(DreamParser::ArgListContext * /*ctx*/) override;
    void exitArgList(DreamParser::ArgListContext * /*ctx*/) override;

    void enterLiteral(DreamParser::LiteralContext * /*ctx*/) override;
    void exitLiteral(DreamParser::LiteralContext * /*ctx*/) override;

    void enterArrayInit(DreamParser::ArrayInitContext * /*ctx*/) override;
    void exitArrayInit(DreamParser::ArrayInitContext * /*ctx*/) override;

    void enterCastExpr(DreamParser::CastExprContext * /*ctx*/) override;
    void exitCastExpr(DreamParser::CastExprContext * /*ctx*/) override;

    void enterAssign(DreamParser::AssignContext * /*ctx*/) override;
    void exitAssign(DreamParser::AssignContext * /*ctx*/) override;

    void enterUnaryOpExpr(DreamParser::UnaryOpExprContext * /*ctx*/) override;
    void exitUnaryOpExpr(DreamParser::UnaryOpExprContext * /*ctx*/) override;

    void enterIfStmt(DreamParser::IfStmtContext * /*ctx*/) override;
    void exitIfStmt(DreamParser::IfStmtContext * /*ctx*/) override;

    void enterElseClause(DreamParser::ElseClauseContext * /*ctx*/) override;
    void exitElseClause(DreamParser::ElseClauseContext * /*ctx*/) override;

    void enterIfBlock(DreamParser::IfBlockContext * /*ctx*/) override;
    void exitIfBlock(DreamParser::IfBlockContext * /*ctx*/) override;

    void enterAtomExpr(DreamParser::AtomExprContext * /*ctx*/) override;
    void exitAtomExpr(DreamParser::AtomExprContext * /*ctx*/) override;

    void enterIfStmtBody(DreamParser::IfStmtBodyContext * /*ctx*/) override;
    void exitIfStmtBody(DreamParser::IfStmtBodyContext * /*ctx*/) override;

    void enterReturnStmt(DreamParser::ReturnStmtContext * /*ctx*/) override;
    void exitReturnStmt(DreamParser::ReturnStmtContext * /*ctx*/) override;

    void enterElseIfClause(DreamParser::ElseIfClauseContext * /*ctx*/) override;
    void exitElseIfClause(DreamParser::ElseIfClauseContext * /*ctx*/) override;

    void enterExpr(DreamParser::ExprContext * /*ctx*/) override;
    void exitExpr(DreamParser::ExprContext * /*ctx*/) override;

    void enterAssignExpr(DreamParser::AssignExprContext * /*ctx*/) override;
    void exitAssignExpr(DreamParser::AssignExprContext * /*ctx*/) override;

    void enterDeclaration(DreamParser::DeclarationContext * /*ctx*/) override;
    void exitDeclaration(DreamParser::DeclarationContext * /*ctx*/) override;

    void enterVarDeclaration(DreamParser::VarDeclarationContext * /*ctx*/) override;
    void exitVarDeclaration(DreamParser::VarDeclarationContext * /*ctx*/) override;

    void enterVarModifiers(DreamParser::VarModifiersContext * /*ctx*/) override;
    void exitVarModifiers(DreamParser::VarModifiersContext * /*ctx*/) override;

    void enterFunctionDeclaration(DreamParser::FunctionDeclarationContext * /*ctx*/) override;
    void exitFunctionDeclaration(DreamParser::FunctionDeclarationContext * /*ctx*/) override;

    void enterFunBlock(DreamParser::FunBlockContext * /*ctx*/) override;
    void exitFunBlock(DreamParser::FunBlockContext * /*ctx*/) override;

    void enterFunStmt(DreamParser::FunStmtContext * /*ctx*/) override;
    void exitFunStmt(DreamParser::FunStmtContext * /*ctx*/) override;

    void enterFunVarDeclaration(DreamParser::FunVarDeclarationContext * /*ctx*/) override;
    void exitFunVarDeclaration(DreamParser::FunVarDeclarationContext * /*ctx*/) override;

    void enterFunModifiers(DreamParser::FunModifiersContext * /*ctx*/) override;
    void exitFunModifiers(DreamParser::FunModifiersContext * /*ctx*/) override;

    void enterClassDeclaration(DreamParser::ClassDeclarationContext * /*ctx*/) override;
    void exitClassDeclaration(DreamParser::ClassDeclarationContext * /*ctx*/) override;

    void enterClassModifiers(DreamParser::ClassModifiersContext * /*ctx*/) override;
    void exitClassModifiers(DreamParser::ClassModifiersContext * /*ctx*/) override;

    void enterClassModifier(DreamParser::ClassModifierContext * /*ctx*/) override;
    void exitClassModifier(DreamParser::ClassModifierContext * /*ctx*/) override;

    void enterClassBlock(DreamParser::ClassBlockContext * /*ctx*/) override;
    void exitClassBlock(DreamParser::ClassBlockContext * /*ctx*/) override;

    void enterClassBody(DreamParser::ClassBodyContext * /*ctx*/) override;
    void exitClassBody(DreamParser::ClassBodyContext * /*ctx*/) override;

    void enterClassVarDecl(DreamParser::ClassVarDeclContext * /*ctx*/) override;
    void exitClassVarDecl(DreamParser::ClassVarDeclContext * /*ctx*/) override;

    void enterClassFuncDecl(DreamParser::ClassFuncDeclContext * /*ctx*/) override;
    void exitClassFuncDecl(DreamParser::ClassFuncDeclContext * /*ctx*/) override;

    void enterClassMemberModifier(DreamParser::ClassMemberModifierContext * /*ctx*/) override;
    void exitClassMemberModifier(DreamParser::ClassMemberModifierContext * /*ctx*/) override;

    void enterConstructorDecl(DreamParser::ConstructorDeclContext * /*ctx*/) override;
    void exitConstructorDecl(DreamParser::ConstructorDeclContext * /*ctx*/) override;

    void enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext * /*ctx*/) override;
    void exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext * /*ctx*/) override;

    void enterThrowStmt(DreamParser::ThrowStmtContext * /*ctx*/) override;
    void exitThrowStmt(DreamParser::ThrowStmtContext * /*ctx*/) override;

    void enterSynchronizedStmt(DreamParser::SynchronizedStmtContext * /*ctx*/) override;
    void exitSynchronizedStmt(DreamParser::SynchronizedStmtContext * /*ctx*/) override;

    void enterTryCatchStmt(DreamParser::TryCatchStmtContext * /*ctx*/) override;
    void exitTryCatchStmt(DreamParser::TryCatchStmtContext * /*ctx*/) override;

    void enterCatches(DreamParser::CatchesContext * /*ctx*/) override;
    void exitCatches(DreamParser::CatchesContext * /*ctx*/) override;

    void enterCatchClause(DreamParser::CatchClauseContext * /*ctx*/) override;
    void exitCatchClause(DreamParser::CatchClauseContext * /*ctx*/) override;

    void enterCatchFormalParameter(DreamParser::CatchFormalParameterContext * /*ctx*/) override;
    void exitCatchFormalParameter(DreamParser::CatchFormalParameterContext * /*ctx*/) override;

    void enterCatchType(DreamParser::CatchTypeContext * /*ctx*/) override;
    void exitCatchType(DreamParser::CatchTypeContext * /*ctx*/) override;

    void enterFinally_(DreamParser::Finally_Context * /*ctx*/) override;
    void exitFinally_(DreamParser::Finally_Context * /*ctx*/) override;

    void enterMemberModifier(DreamParser::MemberModifierContext * /*ctx*/) override;
    void exitMemberModifier(DreamParser::MemberModifierContext * /*ctx*/) override;

    void enterVisibilityModifier(DreamParser::VisibilityModifierContext * /*ctx*/) override;
    void exitVisibilityModifier(DreamParser::VisibilityModifierContext * /*ctx*/) override;

    void enterStaticModifier(DreamParser::StaticModifierContext * /*ctx*/) override;
    void exitStaticModifier(DreamParser::StaticModifierContext * /*ctx*/) override;

    void enterInterfaceDeclaration(DreamParser::InterfaceDeclarationContext * /*ctx*/) override;
    void exitInterfaceDeclaration(DreamParser::InterfaceDeclarationContext * /*ctx*/) override;

    void enterInterfaceBlock(DreamParser::InterfaceBlockContext * /*ctx*/) override;
    void exitInterfaceBlock(DreamParser::InterfaceBlockContext * /*ctx*/) override;

    void enterInterfaceBody(DreamParser::InterfaceBodyContext * /*ctx*/) override;
    void exitInterfaceBody(DreamParser::InterfaceBodyContext * /*ctx*/) override;

    void enterInterfaceVarDecl(DreamParser::InterfaceVarDeclContext * /*ctx*/) override;
    void exitInterfaceVarDecl(DreamParser::InterfaceVarDeclContext * /*ctx*/) override;

    void enterInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext * /*ctx*/) override;
    void exitInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext * /*ctx*/) override;

    void enterAnnotationDeclaration(DreamParser::AnnotationDeclarationContext * /*ctx*/) override;
    void exitAnnotationDeclaration(DreamParser::AnnotationDeclarationContext * /*ctx*/) override;

    void enterAnnotationBlock(DreamParser::AnnotationBlockContext * /*ctx*/) override;
    void exitAnnotationBlock(DreamParser::AnnotationBlockContext * /*ctx*/) override;

    void enterAnnotation(DreamParser::AnnotationContext * /*ctx*/) override;
    void exitAnnotation(DreamParser::AnnotationContext * /*ctx*/) override;

    void enterQualifiedName(DreamParser::QualifiedNameContext * /*ctx*/) override;
    void exitQualifiedName(DreamParser::QualifiedNameContext * /*ctx*/) override;

    void enterParamList(DreamParser::ParamListContext * /*ctx*/) override;
    void exitParamList(DreamParser::ParamListContext * /*ctx*/) override;

    void enterParam(DreamParser::ParamContext * /*ctx*/) override;
    void exitParam(DreamParser::ParamContext * /*ctx*/) override;

    void enterType(DreamParser::TypeContext * /*ctx*/) override;
    void exitType(DreamParser::TypeContext * /*ctx*/) override;

    void enterSingleType(DreamParser::SingleTypeContext * /*ctx*/) override;
    void exitSingleType(DreamParser::SingleTypeContext * /*ctx*/) override;

    void enterArrayType(DreamParser::ArrayTypeContext * /*ctx*/) override;
    void exitArrayType(DreamParser::ArrayTypeContext * /*ctx*/) override;

    void enterReturnType(DreamParser::ReturnTypeContext * /*ctx*/) override;
    void exitReturnType(DreamParser::ReturnTypeContext * /*ctx*/) override;

    void enterForStmt(DreamParser::ForStmtContext * /*ctx*/) override;
    void exitForStmt(DreamParser::ForStmtContext * /*ctx*/) override;

    void enterForCondition(DreamParser::ForConditionContext * /*ctx*/) override;
    void exitForCondition(DreamParser::ForConditionContext * /*ctx*/) override;

    void enterForBlock(DreamParser::ForBlockContext * /*ctx*/) override;
    void exitForBlock(DreamParser::ForBlockContext * /*ctx*/) override;

    void enterForBody(DreamParser::ForBodyContext * /*ctx*/) override;
    void exitForBody(DreamParser::ForBodyContext * /*ctx*/) override;

    void enterForVarDecl(DreamParser::ForVarDeclContext * /*ctx*/) override;
    void exitForVarDecl(DreamParser::ForVarDeclContext * /*ctx*/) override;

    void enterFileCodeBlock(DreamParser::FileCodeBlockContext * /*ctx*/) override;
    void exitFileCodeBlock(DreamParser::FileCodeBlockContext * /*ctx*/) override;

    void enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext * /*ctx*/) override;
    void exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext * /*ctx*/) override;

    void enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext * /*ctx*/) override;
    void exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext * /*ctx*/) override;

    void enterFunCodeBlock(DreamParser::FunCodeBlockContext * /*ctx*/) override;
    void exitFunCodeBlock(DreamParser::FunCodeBlockContext * /*ctx*/) override;

    void enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext * /*ctx*/) override;
    void exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext * /*ctx*/) override;

    void enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext * /*ctx*/) override;
    void exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext * /*ctx*/) override;

    void enterDeleteStmt(DreamParser::DeleteStmtContext* ctx) override;
    void exitDeleteStmt(DreamParser::DeleteStmtContext* ctx) override;

    void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
    void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override;
    void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override;
    void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override;
};



#endif //DREAMPARSERLISTENERCOMPILER_H
