//
// Created by napbad on 9/10/24.
//

#include "DreamCommonParserListener.h"
#include "model/reserved.h"
#include "util/parse_util.h"

#define WRONG_INPUT(expected, input) \
do { \
    char buffer[200]; \
    snprintf(buffer, sizeof(buffer), "expecting %s, get %s", expected, input); \
    __throw_runtime_error(buffer); \
} while(0)

#define PARSER_ERR(msg, input) \
    char buffer [200]; \
    snprintf(buffer, sizeof(buffer), "%s: %s", msg, input);

using namespace std;

void DreamCommonParserListener::enterProgram(DreamParser::ProgramContext *ctx) {
    cout << "enter program" << endl;
    _curr_env = _global->env();
}

void DreamCommonParserListener::exitProgram(DreamParser::ProgramContext *ctx) {
    cout << "exit program" << endl;
    _curr_env = _global->env();
}

void DreamCommonParserListener::enterPackageDecl(DreamParser::PackageDeclContext *ctx) {
    cout << "==================== parsing package ====================" << endl;
    if (_global == nullptr) {
        PARSER_ERR("global package is not set, at ", ctx->getText());
    }


    const vector<antlr4::tree::ParseTree *> children = ctx->children;

    if (children.size() != 3) {
        // (PACKAGE) (name) (;)
        WRONG_INPUT(D_PACKAGE_FORMAT, ctx->getText());
    }
    if (children[0]->getText() != "package") {
        WRONG_INPUT(D_PACKAGE, ctx->getText());
    }
    if (children[2]->getText() != ";") {
        WRONG_INPUT(D_SEMICOLON, ctx->getText());
    }

    const string fullName = children[1]->getText();
    _global->add_package(fullName);

    cout << "package: " << endl;
    util::parse::printPackageTree(_global->package());
}

void DreamCommonParserListener::exitPackageDecl(DreamParser::PackageDeclContext *ctx) {
    cout << "==================== parsed package ====================" << endl;
}

void DreamCommonParserListener::enterImportStmt(DreamParser::ImportStmtContext *ctx) {
}

void DreamCommonParserListener::exitImportStmt(DreamParser::ImportStmtContext *ctx) {
}

void DreamCommonParserListener::enterPackageName(DreamParser::PackageNameContext *ctx) {
}

void DreamCommonParserListener::exitPackageName(DreamParser::PackageNameContext *ctx) {
}

void DreamCommonParserListener::enterImportName(DreamParser::ImportNameContext *ctx) {
}

void DreamCommonParserListener::exitImportName(DreamParser::ImportNameContext *ctx) {
}

void DreamCommonParserListener::enterStmt(DreamParser::StmtContext *ctx) {
    string stmt = ctx->getText();

    if (ctx->children.size() == 2) {
        antlr4::tree::ParseTree * value = ctx->children.at(0);
        const string identifier = value->getText();

        if (Dval * val = _curr_env->get(identifier); val != nullptr) {
            val->print_value();
        }
        else {
            cout << "not found: " << identifier << endl;
        }
    }
}

void DreamCommonParserListener::exitStmt(DreamParser::StmtContext *ctx) {
}

void DreamCommonParserListener::enterFunCallStmt(DreamParser::FunCallStmtContext *ctx) {
}

void DreamCommonParserListener::exitFunCallStmt(DreamParser::FunCallStmtContext *ctx) {
}

void DreamCommonParserListener::enterBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) {
}

void DreamCommonParserListener::exitBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) {
}

void DreamCommonParserListener::enterAtomExpr(DreamParser::AtomExprContext *ctx) {
}

void DreamCommonParserListener::exitAtomExpr(DreamParser::AtomExprContext *ctx) {
}

void DreamCommonParserListener::enterArgList(DreamParser::ArgListContext *ctx) {
}

void DreamCommonParserListener::exitArgList(DreamParser::ArgListContext *ctx) {
}

void DreamCommonParserListener::enterLiteral(DreamParser::LiteralContext *ctx) {
}

void DreamCommonParserListener::exitLiteral(DreamParser::LiteralContext *ctx) {
}

void DreamCommonParserListener::enterArrayInit(DreamParser::ArrayInitContext *ctx) {
}

void DreamCommonParserListener::exitArrayInit(DreamParser::ArrayInitContext *ctx) {
}

void DreamCommonParserListener::enterCastExpr(DreamParser::CastExprContext *ctx) {
}

void DreamCommonParserListener::exitCastExpr(DreamParser::CastExprContext *ctx) {
}

void DreamCommonParserListener::enterAssign(DreamParser::AssignContext *ctx) {
}

void DreamCommonParserListener::exitAssign(DreamParser::AssignContext *ctx) {
}

void DreamCommonParserListener::enterUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) {
}

void DreamCommonParserListener::exitUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) {
}

void DreamCommonParserListener::enterIfStmt(DreamParser::IfStmtContext *ctx) {
}

void DreamCommonParserListener::exitIfStmt(DreamParser::IfStmtContext *ctx) {
}

void DreamCommonParserListener::enterIfBlock(DreamParser::IfBlockContext *ctx) {
}

void DreamCommonParserListener::exitIfBlock(DreamParser::IfBlockContext *ctx) {
}

void DreamCommonParserListener::enterIfStmtBody(DreamParser::IfStmtBodyContext *ctx) {
}

void DreamCommonParserListener::exitIfStmtBody(DreamParser::IfStmtBodyContext *ctx) {
}

void DreamCommonParserListener::enterReturnStmt(DreamParser::ReturnStmtContext *ctx) {
}

void DreamCommonParserListener::exitReturnStmt(DreamParser::ReturnStmtContext *ctx) {
}

void DreamCommonParserListener::enterElseIfClause(DreamParser::ElseIfClauseContext *ctx) {
}

void DreamCommonParserListener::exitElseIfClause(DreamParser::ElseIfClauseContext *ctx) {
}

void DreamCommonParserListener::enterExpr(DreamParser::ExprContext *ctx) {

}

void DreamCommonParserListener::exitExpr(DreamParser::ExprContext *ctx) {
}

void DreamCommonParserListener::enterAssignExpr(DreamParser::AssignExprContext *ctx) {
}

void DreamCommonParserListener::exitAssignExpr(DreamParser::AssignExprContext *ctx) {
}

void DreamCommonParserListener::enterDeclaration(DreamParser::DeclarationContext *ctx) {
}

void DreamCommonParserListener::exitDeclaration(DreamParser::DeclarationContext *ctx) {
}

void DreamCommonParserListener::enterVarDeclaration(DreamParser::VarDeclarationContext *ctx) {
    const std::vector<antlr4::tree::ParseTree *> child = ctx->children;

    const string var_name = child[2]->getText();
    const string var_mut = child[0]->getText();
    const string var_type = child[1]->getText();
    const string var_null = child[3]->getText();
    const string var_val = child[5]->getText();
    // TODO calculate value of var_val expression

    Dval *val;



    Dval * expr = util::parse::parseExpr(var_val, _curr_env);

    if (var_type.ends_with("[]")) {
        val = new Dval();
    } else {
        val = dval::dval_gen(var_val,
                             var_type,
                             var_name,
                             var_mut == D_IMT ? IMMUTABLE : MUTABLE,
                             var_null == D_BANG ? NON_NULLABLE : NULLABLE);
    }

    _curr_env->add(var_name, val);
}

void DreamCommonParserListener::exitVarDeclaration(DreamParser::VarDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterVarModifiers(DreamParser::VarModifiersContext *ctx) {
}

void DreamCommonParserListener::exitVarModifiers(DreamParser::VarModifiersContext *ctx) {
}

void DreamCommonParserListener::enterFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) {
}

void DreamCommonParserListener::exitFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterFunBlock(DreamParser::FunBlockContext *ctx) {
}

void DreamCommonParserListener::exitFunBlock(DreamParser::FunBlockContext *ctx) {
}

void DreamCommonParserListener::enterFunStmt(DreamParser::FunStmtContext *ctx) {
}

void DreamCommonParserListener::exitFunStmt(DreamParser::FunStmtContext *ctx) {
}

void DreamCommonParserListener::enterFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) {
}

void DreamCommonParserListener::exitFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterFunModifiers(DreamParser::FunModifiersContext *ctx) {
}

void DreamCommonParserListener::exitFunModifiers(DreamParser::FunModifiersContext *ctx) {
}

void DreamCommonParserListener::enterClassDeclaration(DreamParser::ClassDeclarationContext *ctx) {
}

void DreamCommonParserListener::exitClassDeclaration(DreamParser::ClassDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterClassModifiers(DreamParser::ClassModifiersContext *ctx) {
}

void DreamCommonParserListener::exitClassModifiers(DreamParser::ClassModifiersContext *ctx) {
}

void DreamCommonParserListener::enterClassModifier(DreamParser::ClassModifierContext *ctx) {
}

void DreamCommonParserListener::exitClassModifier(DreamParser::ClassModifierContext *ctx) {
}

void DreamCommonParserListener::enterClassBlock(DreamParser::ClassBlockContext *ctx) {
}

void DreamCommonParserListener::exitClassBlock(DreamParser::ClassBlockContext *ctx) {
}

void DreamCommonParserListener::enterClassBody(DreamParser::ClassBodyContext *ctx) {
}

void DreamCommonParserListener::exitClassBody(DreamParser::ClassBodyContext *ctx) {
}

void DreamCommonParserListener::enterClassVarDecl(DreamParser::ClassVarDeclContext *ctx) {
}

void DreamCommonParserListener::exitClassVarDecl(DreamParser::ClassVarDeclContext *ctx) {
}

void DreamCommonParserListener::enterClassFuncDecl(DreamParser::ClassFuncDeclContext *ctx) {
}

void DreamCommonParserListener::exitClassFuncDecl(DreamParser::ClassFuncDeclContext *ctx) {
}

void DreamCommonParserListener::enterClassMemberModifier(DreamParser::ClassMemberModifierContext *ctx) {
}

void DreamCommonParserListener::exitClassMemberModifier(DreamParser::ClassMemberModifierContext *ctx) {
}

void DreamCommonParserListener::enterConstructorDecl(DreamParser::ConstructorDeclContext *ctx) {
}

void DreamCommonParserListener::exitConstructorDecl(DreamParser::ConstructorDeclContext *ctx) {
}

void DreamCommonParserListener::enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext *ctx) {
}

void DreamCommonParserListener::exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext *ctx) {
}

void DreamCommonParserListener::enterThrowStmt(DreamParser::ThrowStmtContext *ctx) {
}

void DreamCommonParserListener::exitThrowStmt(DreamParser::ThrowStmtContext *ctx) {
}

void DreamCommonParserListener::enterSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) {
}

void DreamCommonParserListener::exitSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) {
}

void DreamCommonParserListener::enterTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) {
}

void DreamCommonParserListener::exitTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) {
}

void DreamCommonParserListener::enterCatches(DreamParser::CatchesContext *ctx) {
}

void DreamCommonParserListener::exitCatches(DreamParser::CatchesContext *ctx) {
}

void DreamCommonParserListener::enterCatchClause(DreamParser::CatchClauseContext *ctx) {
}

void DreamCommonParserListener::exitCatchClause(DreamParser::CatchClauseContext *ctx) {
}

void DreamCommonParserListener::enterCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) {
}

void DreamCommonParserListener::exitCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) {
}

void DreamCommonParserListener::enterCatchType(DreamParser::CatchTypeContext *ctx) {
}

void DreamCommonParserListener::exitCatchType(DreamParser::CatchTypeContext *ctx) {
}

void DreamCommonParserListener::enterFinally_(DreamParser::Finally_Context *ctx) {
}

void DreamCommonParserListener::exitFinally_(DreamParser::Finally_Context *ctx) {
}

void DreamCommonParserListener::enterMemberModifier(DreamParser::MemberModifierContext *ctx) {
}

void DreamCommonParserListener::exitMemberModifier(DreamParser::MemberModifierContext *ctx) {
}

void DreamCommonParserListener::enterVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) {
}

void DreamCommonParserListener::exitVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) {
}

void DreamCommonParserListener::enterStaticModifier(DreamParser::StaticModifierContext *ctx) {
}

void DreamCommonParserListener::exitStaticModifier(DreamParser::StaticModifierContext *ctx) {
}

void DreamCommonParserListener::enterInterfaceDeclaration(DreamParser::InterfaceDeclarationContext *ctx) {
}

void DreamCommonParserListener::exitInterfaceDeclaration(DreamParser::InterfaceDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterInterfaceBlock(DreamParser::InterfaceBlockContext *ctx) {
}

void DreamCommonParserListener::exitInterfaceBlock(DreamParser::InterfaceBlockContext *ctx) {
}

void DreamCommonParserListener::enterInterfaceBody(DreamParser::InterfaceBodyContext *ctx) {
}

void DreamCommonParserListener::exitInterfaceBody(DreamParser::InterfaceBodyContext *ctx) {
}

void DreamCommonParserListener::enterInterfaceVarDecl(DreamParser::InterfaceVarDeclContext *ctx) {
}

void DreamCommonParserListener::exitInterfaceVarDecl(DreamParser::InterfaceVarDeclContext *ctx) {
}

void DreamCommonParserListener::enterInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext *ctx) {
}

void DreamCommonParserListener::exitInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext *ctx) {
}

void DreamCommonParserListener::enterAnnotationDeclaration(DreamParser::AnnotationDeclarationContext *ctx) {
}

void DreamCommonParserListener::exitAnnotationDeclaration(DreamParser::AnnotationDeclarationContext *ctx) {
}

void DreamCommonParserListener::enterAnnotationBlock(DreamParser::AnnotationBlockContext *ctx) {
}

void DreamCommonParserListener::exitAnnotationBlock(DreamParser::AnnotationBlockContext *ctx) {
}

void DreamCommonParserListener::enterAnnotation(DreamParser::AnnotationContext *ctx) {
}

void DreamCommonParserListener::exitAnnotation(DreamParser::AnnotationContext *ctx) {
}

void DreamCommonParserListener::enterQualifiedName(DreamParser::QualifiedNameContext *ctx) {
}

void DreamCommonParserListener::exitQualifiedName(DreamParser::QualifiedNameContext *ctx) {
}

void DreamCommonParserListener::enterParamList(DreamParser::ParamListContext *ctx) {
}

void DreamCommonParserListener::exitParamList(DreamParser::ParamListContext *ctx) {
}

void DreamCommonParserListener::enterParam(DreamParser::ParamContext *ctx) {
}

void DreamCommonParserListener::exitParam(DreamParser::ParamContext *ctx) {
}

void DreamCommonParserListener::enterType(DreamParser::TypeContext *ctx) {
}

void DreamCommonParserListener::exitType(DreamParser::TypeContext *ctx) {
}

void DreamCommonParserListener::enterSingleType(DreamParser::SingleTypeContext *ctx) {
}

void DreamCommonParserListener::exitSingleType(DreamParser::SingleTypeContext *ctx) {
}

void DreamCommonParserListener::enterArrayType(DreamParser::ArrayTypeContext *ctx) {
}

void DreamCommonParserListener::exitArrayType(DreamParser::ArrayTypeContext *ctx) {
}

void DreamCommonParserListener::enterReturnType(DreamParser::ReturnTypeContext *ctx) {
}

void DreamCommonParserListener::exitReturnType(DreamParser::ReturnTypeContext *ctx) {
}

void DreamCommonParserListener::enterForStmt(DreamParser::ForStmtContext *ctx) {
}

void DreamCommonParserListener::exitForStmt(DreamParser::ForStmtContext *ctx) {
}

void DreamCommonParserListener::enterForCondition(DreamParser::ForConditionContext *ctx) {
}

void DreamCommonParserListener::exitForCondition(DreamParser::ForConditionContext *ctx) {
}

void DreamCommonParserListener::enterForBlock(DreamParser::ForBlockContext *ctx) {
}

void DreamCommonParserListener::exitForBlock(DreamParser::ForBlockContext *ctx) {
}

void DreamCommonParserListener::enterForBody(DreamParser::ForBodyContext *ctx) {
}

void DreamCommonParserListener::exitForBody(DreamParser::ForBodyContext *ctx) {
}

void DreamCommonParserListener::enterForVarDecl(DreamParser::ForVarDeclContext *ctx) {
}

void DreamCommonParserListener::exitForVarDecl(DreamParser::ForVarDeclContext *ctx) {
}

void DreamCommonParserListener::enterFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) {
    std::cout << "FileCodeBlock" << std::endl;
    Denv *block = new Denv();
    block->set_parent(_curr_env);
    _curr_env->add_child(block);
    _curr_env = block;
}

void DreamCommonParserListener::exitFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) {
    _curr_env = _curr_env->parent();
}

void DreamCommonParserListener::enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) {
}

void DreamCommonParserListener::exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) {
}

void DreamCommonParserListener::enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) {
}

void DreamCommonParserListener::exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) {
}

void DreamCommonParserListener::enterFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) {
}

void DreamCommonParserListener::exitFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) {
}

void DreamCommonParserListener::enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) {
}

void DreamCommonParserListener::exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) {
}

void DreamCommonParserListener::enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) {
}

void DreamCommonParserListener::exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) {
}


void DreamCommonParserListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
}

void DreamCommonParserListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
}

void DreamCommonParserListener::visitTerminal(antlr4::tree::TerminalNode * /*node*/) {
}

void DreamCommonParserListener::visitErrorNode(antlr4::tree::ErrorNode * /*node*/) {
}
