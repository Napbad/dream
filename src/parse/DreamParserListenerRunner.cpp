//
// Created by napbad on 9/10/24.
//

#include "DreamParserListenerRunner.h"

#include <random>

#include "common/enum.h"
#include "common/reserved.h"
#include "gc/gc.h"
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

void DreamParserListenerRunner::enterProgram(DreamParser::ProgramContext *ctx) {
    cout << "enter program" << endl;
    _curr_env = _global->env();
}

void DreamParserListenerRunner::exitProgram(DreamParser::ProgramContext *ctx) {
    cout << "exit program" << endl;
    _curr_env = _global->env();
}

void DreamParserListenerRunner::enterPackageDecl(DreamParser::PackageDeclContext *ctx) {
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
    util::parse::print_package_tree(_global->package());
}

void DreamParserListenerRunner::exitPackageDecl(DreamParser::PackageDeclContext *ctx) {
    cout << "==================== parsed package ====================" << endl;
}

void DreamParserListenerRunner::enterImportStmt(DreamParser::ImportStmtContext *ctx) {
}

void DreamParserListenerRunner::exitImportStmt(DreamParser::ImportStmtContext *ctx) {
}

void DreamParserListenerRunner::enterPackageName(DreamParser::PackageNameContext *ctx) {
}

void DreamParserListenerRunner::exitPackageName(DreamParser::PackageNameContext *ctx) {
}

void DreamParserListenerRunner::enterImportName(DreamParser::ImportNameContext *ctx) {
}

void DreamParserListenerRunner::exitImportName(DreamParser::ImportNameContext *ctx) {
}

void DreamParserListenerRunner::enterStmt(DreamParser::StmtContext *ctx) {
    if (ctx->children.size() == 2) {
        antlr4::tree::ParseTree *value = ctx->children.at(0);
        const string identifier = value->getText();

        if (Dval *val = _curr_env->get(identifier); val != nullptr) {
            val->print_value();
        }
    }
}

void DreamParserListenerRunner::exitStmt(DreamParser::StmtContext *ctx) {
}

void DreamParserListenerRunner::enterFunCallStmt(DreamParser::FunCallStmtContext *ctx) {
}

void DreamParserListenerRunner::exitFunCallStmt(DreamParser::FunCallStmtContext *ctx) {
}

void DreamParserListenerRunner::enterBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) {
}

void DreamParserListenerRunner::exitBinaryOpExpr(DreamParser::BinaryOpExprContext *ctx) {
}

void DreamParserListenerRunner::enterAtomExpr(DreamParser::AtomExprContext *ctx) {
}

void DreamParserListenerRunner::exitAtomExpr(DreamParser::AtomExprContext *ctx) {
}

void DreamParserListenerRunner::enterArgList(DreamParser::ArgListContext *ctx) {
}

void DreamParserListenerRunner::exitArgList(DreamParser::ArgListContext *ctx) {
}

void DreamParserListenerRunner::enterLiteral(DreamParser::LiteralContext *ctx) {
}

void DreamParserListenerRunner::exitLiteral(DreamParser::LiteralContext *ctx) {
}

void DreamParserListenerRunner::enterArrayInit(DreamParser::ArrayInitContext *ctx) {
}

void DreamParserListenerRunner::exitArrayInit(DreamParser::ArrayInitContext *ctx) {
}

void DreamParserListenerRunner::enterCastExpr(DreamParser::CastExprContext *ctx) {
}

void DreamParserListenerRunner::exitCastExpr(DreamParser::CastExprContext *ctx) {
}

void DreamParserListenerRunner::enterAssign(DreamParser::AssignContext *ctx) {
    if (ctx->children.size() == 3) {
        cout << "==================== parsing assign ====================" << endl;

        const string ident = ctx->children.at(0)->getText();

        if (const string expr = ctx->children.at(1)->getText(); expr == D_ASSIGN) {
            Dval *val = _curr_env->get(ident);
            if (val == nullptr) {
                cout << "not found: " << ident << endl;
                return;
            }
            if (val->is_mutable()) {
                Dval *tree = util::parse::parse_expr_tree(*ctx->children.at(2));
                const Dval *res = util::parse::calc_expr(tree, _curr_env);
                val->set_value(res->get_string_value());
            } else {
                cout << "not mutable: " << ident << endl;
                return;
            }
            val->print_value();
        } else {
            WRONG_INPUT(":=", expr);
        }
    }
}

void DreamParserListenerRunner::exitAssign(DreamParser::AssignContext *ctx) {
}

void DreamParserListenerRunner::enterUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) {
}

void DreamParserListenerRunner::exitUnaryOpExpr(DreamParser::UnaryOpExprContext *ctx) {
}

void DreamParserListenerRunner::enterIfStmt(DreamParser::IfStmtContext *ctx) {
}

void DreamParserListenerRunner::exitIfStmt(DreamParser::IfStmtContext *ctx) {
}

void DreamParserListenerRunner::enterIfBlock(DreamParser::IfBlockContext *ctx) {
}

void DreamParserListenerRunner::exitIfBlock(DreamParser::IfBlockContext *ctx) {
}

void DreamParserListenerRunner::enterIfStmtBody(DreamParser::IfStmtBodyContext *ctx) {
}

void DreamParserListenerRunner::exitIfStmtBody(DreamParser::IfStmtBodyContext *ctx) {
}

void DreamParserListenerRunner::enterReturnStmt(DreamParser::ReturnStmtContext *ctx) {
}

void DreamParserListenerRunner::exitReturnStmt(DreamParser::ReturnStmtContext *ctx) {
}

void DreamParserListenerRunner::enterElseIfClause(DreamParser::ElseIfClauseContext *ctx) {
}

void DreamParserListenerRunner::exitElseIfClause(DreamParser::ElseIfClauseContext *ctx) {
}

void DreamParserListenerRunner::enterExpr(DreamParser::ExprContext *ctx) {
}

void DreamParserListenerRunner::exitExpr(DreamParser::ExprContext *ctx) {
}

void DreamParserListenerRunner::enterAssignExpr(DreamParser::AssignExprContext *ctx) {
}

void DreamParserListenerRunner::exitAssignExpr(DreamParser::AssignExprContext *ctx) {
}

void DreamParserListenerRunner::enterDeclaration(DreamParser::DeclarationContext *ctx) {
}

void DreamParserListenerRunner::exitDeclaration(DreamParser::DeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterVarDeclaration(DreamParser::VarDeclarationContext *ctx) {
    const std::vector<antlr4::tree::ParseTree *> child = ctx->children;

    const string var_name = child[2]->getText();
    const string var_mut = child[0]->getText();
    const string var_type = child[1]->getText();
    const string var_null = child[3]->getText();
    const string var_val = child[5]->getText();

    Dval *val;
    if (var_type.ends_with("[]")) {
        val = util::parse::parse_array_expr(var_type, *child[5]->children.at(0)->children.at(0), _curr_env);
    } else {
        val = util::parse::parse_expr(*child[5], _curr_env);
    }
    val->set_identifier(var_name);
    val->set_val_nullable(var_null == D_NULLABLE);
    val->set_val_mutable(var_mut == D_VAR);

    _curr_env->add(var_name, val);
}

void DreamParserListenerRunner::exitVarDeclaration(DreamParser::VarDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterVarModifiers(DreamParser::VarModifiersContext *ctx) {
}

void DreamParserListenerRunner::exitVarModifiers(DreamParser::VarModifiersContext *ctx) {
}

void DreamParserListenerRunner::enterFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) {
    Dval *fun_val = dval::dval_fun("");
    _global->ds()->add_data(fun_val);
    fun_val->set_env(_curr_env);

    const vector<antlr4::tree::ParseTree *> children = ctx->children;

    for (auto i = 0; i < children.size(); i++) {
        if (const auto child = children.at(i); child->getText() == D_FUN) {
            const string fun_name = children.at(i + 1)->getText();
            Denv *env = new Denv(fun_name);
            env->set_parent(_curr_env);
            _curr_env->add_child(env);
            _curr_env = env;

            for (auto j = i + 3; j < children.size(); j++) {
                if (children.at(j)->getText() == D_RPAREN) {
                    break;
                }
                if (children.at(j)->getText() == D_COMMA) {
                    continue;
                }
            }
        }
    }
}

void DreamParserListenerRunner::exitFunctionDeclaration(DreamParser::FunctionDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterFunBlock(DreamParser::FunBlockContext *ctx) {
}

void DreamParserListenerRunner::exitFunBlock(DreamParser::FunBlockContext *ctx) {
}

void DreamParserListenerRunner::enterFunStmt(DreamParser::FunStmtContext *ctx) {
}

void DreamParserListenerRunner::exitFunStmt(DreamParser::FunStmtContext *ctx) {
}

void DreamParserListenerRunner::enterFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) {
}

void DreamParserListenerRunner::exitFunVarDeclaration(DreamParser::FunVarDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterFunModifiers(DreamParser::FunModifiersContext *ctx) {
}

void DreamParserListenerRunner::exitFunModifiers(DreamParser::FunModifiersContext *ctx) {
}

void DreamParserListenerRunner::enterClassDeclaration(DreamParser::ClassDeclarationContext *ctx) {
}

void DreamParserListenerRunner::exitClassDeclaration(DreamParser::ClassDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterClassModifiers(DreamParser::ClassModifiersContext *ctx) {
}

void DreamParserListenerRunner::exitClassModifiers(DreamParser::ClassModifiersContext *ctx) {
}

void DreamParserListenerRunner::enterClassModifier(DreamParser::ClassModifierContext *ctx) {
}

void DreamParserListenerRunner::exitClassModifier(DreamParser::ClassModifierContext *ctx) {
}

void DreamParserListenerRunner::enterClassBlock(DreamParser::ClassBlockContext *ctx) {
}

void DreamParserListenerRunner::exitClassBlock(DreamParser::ClassBlockContext *ctx) {
}

void DreamParserListenerRunner::enterClassBody(DreamParser::ClassBodyContext *ctx) {
}

void DreamParserListenerRunner::exitClassBody(DreamParser::ClassBodyContext *ctx) {
}

void DreamParserListenerRunner::enterClassVarDecl(DreamParser::ClassVarDeclContext *ctx) {
}

void DreamParserListenerRunner::exitClassVarDecl(DreamParser::ClassVarDeclContext *ctx) {
}

void DreamParserListenerRunner::enterClassFuncDecl(DreamParser::ClassFuncDeclContext *ctx) {
}

void DreamParserListenerRunner::exitClassFuncDecl(DreamParser::ClassFuncDeclContext *ctx) {
}

void DreamParserListenerRunner::enterClassMemberModifier(DreamParser::ClassMemberModifierContext *ctx) {
}

void DreamParserListenerRunner::exitClassMemberModifier(DreamParser::ClassMemberModifierContext *ctx) {
}

void DreamParserListenerRunner::enterConstructorDecl(DreamParser::ConstructorDeclContext *ctx) {
}

void DreamParserListenerRunner::exitConstructorDecl(DreamParser::ConstructorDeclContext *ctx) {
}

void DreamParserListenerRunner::enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext *ctx) {
}

void DreamParserListenerRunner::exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext *ctx) {
}

void DreamParserListenerRunner::enterThrowStmt(DreamParser::ThrowStmtContext *ctx) {
}

void DreamParserListenerRunner::exitThrowStmt(DreamParser::ThrowStmtContext *ctx) {
}

void DreamParserListenerRunner::enterSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) {
}

void DreamParserListenerRunner::exitSynchronizedStmt(DreamParser::SynchronizedStmtContext *ctx) {
}

void DreamParserListenerRunner::enterTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) {
}

void DreamParserListenerRunner::exitTryCatchStmt(DreamParser::TryCatchStmtContext *ctx) {
}

void DreamParserListenerRunner::enterCatches(DreamParser::CatchesContext *ctx) {
}

void DreamParserListenerRunner::exitCatches(DreamParser::CatchesContext *ctx) {
}

void DreamParserListenerRunner::enterCatchClause(DreamParser::CatchClauseContext *ctx) {
}

void DreamParserListenerRunner::exitCatchClause(DreamParser::CatchClauseContext *ctx) {
}

void DreamParserListenerRunner::enterCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) {
}

void DreamParserListenerRunner::exitCatchFormalParameter(DreamParser::CatchFormalParameterContext *ctx) {
}

void DreamParserListenerRunner::enterCatchType(DreamParser::CatchTypeContext *ctx) {
}

void DreamParserListenerRunner::exitCatchType(DreamParser::CatchTypeContext *ctx) {
}

void DreamParserListenerRunner::enterFinally_(DreamParser::Finally_Context *ctx) {
}

void DreamParserListenerRunner::exitFinally_(DreamParser::Finally_Context *ctx) {
}

void DreamParserListenerRunner::enterMemberModifier(DreamParser::MemberModifierContext *ctx) {
}

void DreamParserListenerRunner::exitMemberModifier(DreamParser::MemberModifierContext *ctx) {
}

void DreamParserListenerRunner::enterVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) {
}

void DreamParserListenerRunner::exitVisibilityModifier(DreamParser::VisibilityModifierContext *ctx) {
}

void DreamParserListenerRunner::enterStaticModifier(DreamParser::StaticModifierContext *ctx) {
}

void DreamParserListenerRunner::exitStaticModifier(DreamParser::StaticModifierContext *ctx) {
}

void DreamParserListenerRunner::enterInterfaceDeclaration(DreamParser::InterfaceDeclarationContext *ctx) {
}

void DreamParserListenerRunner::exitInterfaceDeclaration(DreamParser::InterfaceDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterInterfaceBlock(DreamParser::InterfaceBlockContext *ctx) {
}

void DreamParserListenerRunner::exitInterfaceBlock(DreamParser::InterfaceBlockContext *ctx) {
}

void DreamParserListenerRunner::enterInterfaceBody(DreamParser::InterfaceBodyContext *ctx) {
}

void DreamParserListenerRunner::exitInterfaceBody(DreamParser::InterfaceBodyContext *ctx) {
}

void DreamParserListenerRunner::enterInterfaceVarDecl(DreamParser::InterfaceVarDeclContext *ctx) {
}

void DreamParserListenerRunner::exitInterfaceVarDecl(DreamParser::InterfaceVarDeclContext *ctx) {
}

void DreamParserListenerRunner::enterInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext *ctx) {
}

void DreamParserListenerRunner::exitInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext *ctx) {
}

void DreamParserListenerRunner::enterAnnotationDeclaration(DreamParser::AnnotationDeclarationContext *ctx) {
}

void DreamParserListenerRunner::exitAnnotationDeclaration(DreamParser::AnnotationDeclarationContext *ctx) {
}

void DreamParserListenerRunner::enterAnnotationBlock(DreamParser::AnnotationBlockContext *ctx) {
}

void DreamParserListenerRunner::exitAnnotationBlock(DreamParser::AnnotationBlockContext *ctx) {
}

void DreamParserListenerRunner::enterAnnotation(DreamParser::AnnotationContext *ctx) {
}

void DreamParserListenerRunner::exitAnnotation(DreamParser::AnnotationContext *ctx) {
}

void DreamParserListenerRunner::enterQualifiedName(DreamParser::QualifiedNameContext *ctx) {
}

void DreamParserListenerRunner::exitQualifiedName(DreamParser::QualifiedNameContext *ctx) {
}

void DreamParserListenerRunner::enterParamList(DreamParser::ParamListContext *ctx) {
    Denv *_param_curr_env = new Denv();
    _param_curr_env->set_parent(_curr_env);
    _curr_env->add_child(_param_curr_env);
    _curr_env = _param_curr_env;
}

void DreamParserListenerRunner::exitParamList(DreamParser::ParamListContext *ctx) {
    const Denv *denv = _curr_env->parent();
    denv->remove_child(_curr_env);
}

void DreamParserListenerRunner::enterParam(DreamParser::ParamContext *ctx) {
    const vector<antlr4::tree::ParseTree *> trees = ctx->children;
    if (trees.size() == 2) {
        // immutable, non-null
        Dval *val = dval::dval_gen("", trees[0]->getText(), trees[1]->getText(), IMMUTABLE, NON_NULLABLE);
        _curr_env->add(trees[1]->getText(), val);
        return;
    }
    if (trees.size() == 3) {
        if (trees[0]->getText() == D_IMT || trees[0]->getText() == D_VAR) {
            // mutable, non-null
            Dval *val = dval::dval_gen("",
                                       trees[1]->getText(),
                                       trees[2]->getText(),
                                       trees[0]->getText() == D_IMT ? MUTABLE : IMMUTABLE,
                                       NON_NULLABLE);
            _curr_env->add(trees[2]->getText(), val);
        } else if (trees[2]->getText() == D_NULLABLE || trees[2]->getText() == D_NON_NULLABLE) {
            Dval *val = dval::dval_gen("",
                                       trees[0]->getText(),
                                       trees[1]->getText(),
                                       IMMUTABLE,
                                       trees[2]->getText() == D_NULLABLE ? NULLABLE : NON_NULLABLE);
            _curr_env->add(trees[1]->getText(), val);
        } else {
            throw std::invalid_argument("Invalid param");
        }
    }

    if (trees.size() == 4) {
        if ((trees[0]->getText() == D_IMT || trees[0]->getText() == D_VAR) &&
            (trees[3]->getText() == D_NULLABLE || trees[3]->getText() == D_NON_NULLABLE)) {
            Dval *dval = dval::dval_gen("",
                                        trees[1]->getText(),
                                        trees[2]->getText(),
                                        trees[0]->getText() == D_IMT ? MUTABLE : IMMUTABLE,
                                        trees[3]->getText() == D_NULLABLE ? NULLABLE : NON_NULLABLE);
            _curr_env->add(trees[2]->getText(), dval);
        } else {
            throw std::invalid_argument("Invalid param");
        }
    }
}

void DreamParserListenerRunner::exitParam(DreamParser::ParamContext *ctx) {
}

void DreamParserListenerRunner::enterType(DreamParser::TypeContext *ctx) {
}

void DreamParserListenerRunner::exitType(DreamParser::TypeContext *ctx) {
}

void DreamParserListenerRunner::enterSingleType(DreamParser::SingleTypeContext *ctx) {
}

void DreamParserListenerRunner::exitSingleType(DreamParser::SingleTypeContext *ctx) {
}

void DreamParserListenerRunner::enterArrayType(DreamParser::ArrayTypeContext *ctx) {
}

void DreamParserListenerRunner::exitArrayType(DreamParser::ArrayTypeContext *ctx) {
}

void DreamParserListenerRunner::enterReturnType(DreamParser::ReturnTypeContext *ctx) {
}

void DreamParserListenerRunner::exitReturnType(DreamParser::ReturnTypeContext *ctx) {
}

void DreamParserListenerRunner::enterForStmt(DreamParser::ForStmtContext *ctx) {
}

void DreamParserListenerRunner::exitForStmt(DreamParser::ForStmtContext *ctx) {
}

void DreamParserListenerRunner::enterForCondition(DreamParser::ForConditionContext *ctx) {
}

void DreamParserListenerRunner::exitForCondition(DreamParser::ForConditionContext *ctx) {
}

void DreamParserListenerRunner::enterForBlock(DreamParser::ForBlockContext *ctx) {
}

void DreamParserListenerRunner::exitForBlock(DreamParser::ForBlockContext *ctx) {
}

void DreamParserListenerRunner::enterForBody(DreamParser::ForBodyContext *ctx) {
}

void DreamParserListenerRunner::exitForBody(DreamParser::ForBodyContext *ctx) {
}

void DreamParserListenerRunner::enterForVarDecl(DreamParser::ForVarDeclContext *ctx) {
}

void DreamParserListenerRunner::exitForVarDecl(DreamParser::ForVarDeclContext *ctx) {
}

void DreamParserListenerRunner::enterFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) {
    cout << "FileCodeBlock enter" << endl;
    Denv *block = new Denv();
    block->set_parent(_curr_env);
    _curr_env->add_child(block);
    _curr_env = block;
}

void DreamParserListenerRunner::exitFileCodeBlock(DreamParser::FileCodeBlockContext *ctx) {
    cout << "FileCodeBlock exit" << endl;
    _curr_env = _curr_env->parent();
}

void DreamParserListenerRunner::enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) {
}

void DreamParserListenerRunner::exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext *ctx) {
}

void DreamParserListenerRunner::enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) {
    if (ctx->children.size() == 2) {
        antlr4::tree::ParseTree *value = ctx->children.at(0);
        const string identifier = value->getText();

        if (Dval *val = _curr_env->get(identifier); val != nullptr) {
            val->print_value();
        }
    }
}

void DreamParserListenerRunner::exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext *ctx) {
}

void DreamParserListenerRunner::enterFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) {
}

void DreamParserListenerRunner::exitFunCodeBlock(DreamParser::FunCodeBlockContext *ctx) {
}

void DreamParserListenerRunner::enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) {
}

void DreamParserListenerRunner::exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext *ctx) {
}

void DreamParserListenerRunner::enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) {
}

void DreamParserListenerRunner::exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext *ctx) {
}


void DreamParserListenerRunner::enterEveryRule(antlr4::ParserRuleContext *ctx) {
}

void DreamParserListenerRunner::exitEveryRule(antlr4::ParserRuleContext *ctx) {
}

void DreamParserListenerRunner::visitTerminal(antlr4::tree::TerminalNode * /*node*/) {
}

void DreamParserListenerRunner::visitErrorNode(antlr4::tree::ErrorNode * /*node*/) {
}
