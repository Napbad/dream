//
// Created by napbad on 9/23/24.
//

#include "DreamParserListenerCompiler.h"

#include "common/dream_const.h"
#include "common/reserve.h"
#include "compiler/NativeConverter.h"
#include "util/file_util.h"
#include "util/response_util.h"
#include "util/string_util.h"

using namespace std;

DreamParserListenerCompiler::DreamParserListenerCompiler(
    const std::string& file_source,
    const std::string& file_name,
    Global* global)
{
    _file_name = file_name;
    _global = global;
    _file_source = file_source;
    _current_hierarchy = _global->hierarchy();
    _package_hierarchy = nullptr; // assign later
    _root_path_to_include = "";
    _class_code_generator = nullptr; // assign later
}

DreamParserListenerCompiler::~DreamParserListenerCompiler() = default;

void DreamParserListenerCompiler::enterProgram(DreamParser::ProgramContext* ctx)
{
    _current_hierarchy = Hierarchy::file_hierarchy(_file_name.substr(0, _file_name.length() - 5));
}

void DreamParserListenerCompiler::exitProgram(DreamParser::ProgramContext* ctx)
{
    // compile the file
    for (auto& line : _converted_file)
    {
        _file_stream << line;
    }
    _file_stream.close();
    cout << flush;

    if (_package_name == MAIN_PACKAGE && _file_name == MAIN_FILE)
    {
        // add the runtime stmts:

        const string command = ("g++ -lstdc++ -std=c++17" +
            string_util::get_text_from_vector(_global->file_to_compile_list()) + " -o " + _file_path.substr(
                0, _file_path.length() - 4) + ".o \n");

        print(cout,
              "========================= Compiling ========================= \n" + command
              , file_util::FileColor::GREEN);

        if (const int result = system(
                command.c_str());
            result != 0)
        {
            print(std::cout, "Compile error", file_util::FileColor::RED);
            exit(1);
        }
        file_util::print(cout,
                         "========================= Compiling End ========================= \n",
                         file_util::FileColor::GREEN);

        system((_file_path.substr(0, _file_path.length() - 4) + ".o").c_str());
    }
}

void DreamParserListenerCompiler::enterPackageDecl(DreamParser::PackageDeclContext* ctx)
{
    // create correspond package directory and file in build directory
    const std::string path = file_util::convert_pkg_to_path(ctx->children.at(1)->getText());
    _package_name = ctx->children.at(1)->getText();

    _file_path = path + _file_name;
    _global->add_file_compile(_file_path);

    std::fstream _fstream = file_util::create_file(path + _file_name);

    _file_stream = std::move(_fstream);

    _converted_file.push_back("// package " + ctx->children.at(1)->getText() + "\n");
    _package_hierarchy = file_util::get_package_hierarchy(_package_name);

    // set up the hierarchy, merge the current hierarchy into the global hierarchy
    Hierarchy* tmp = _package_hierarchy;
    tmp = Hierarchy::merge_hierarchy(_global->hierarchy(), tmp);
    _current_hierarchy = new Hierarchy(_file_name, HierarchyType::FILE, tmp, {});
    tmp->add_child(_current_hierarchy);

    string full_hierarchy_name = _current_hierarchy->get_full_hierarchy_name();

    // find the root directory, to make the import path easier to generate
    int count = 0;
    while (tmp->parent() != _global->hierarchy())
    {
        count++;
        tmp = tmp->parent();
    }
    string import_stmt = "#include \"";
    for (int i = 0; i <= count; i++)
    {
        import_stmt.append("../");
    }

    // set up root's path
    _root_path_to_include = import_stmt;

    // include the runtime files
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "class/Object.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "gc/DataCopy.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "gc/DataPool.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "gc/DataPath.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "gc/DataSource.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + "natives/Exception.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "reserve/d_define.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/" + "reserve/Finally.h\" \n");
}

void DreamParserListenerCompiler::exitPackageDecl(DreamParser::PackageDeclContext* ctx)
{
    const std::vector<std::string> import_pack = string_util::split(ctx->children[1]->getText(), '.');
    const std::vector<std::string> pack_hierarchy = string_util::split(_package_name, '.');

    string pack_path;

    for (int i = 0; i < pack_hierarchy.size() && i < import_pack.size(); i++)
    {
        if (pack_hierarchy[i] != import_pack[i])
        {
            for (int j = 0; j < import_pack.size(); j++)
            {
                if (j < i)
                    pack_path.append("../");
                else if (j != import_pack.size() - 1)
                    pack_path.append(import_pack[j])
                             .append("/");
                else
                    pack_path.append(import_pack[j]);
            }
        }
    }
}

void DreamParserListenerCompiler::enterImportStmt(DreamParser::ImportStmtContext* ctx)
{
    string path = file_util::convert_pkg_to_path(ctx->children[1]->getText());
    if (path.ends_with("/"))
    {
        path.pop_back();
    }
    _converted_file.insert(_converted_file.begin() + 1,
                           _root_path_to_include + path + ".cpp\"\n");
}

void DreamParserListenerCompiler::exitImportStmt(DreamParser::ImportStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterPackageName(DreamParser::PackageNameContext* ctx)
{
}

void DreamParserListenerCompiler::exitPackageName(DreamParser::PackageNameContext* ctx)
{
}

void DreamParserListenerCompiler::enterImportName(DreamParser::ImportNameContext* ctx)
{
}

void DreamParserListenerCompiler::exitImportName(DreamParser::ImportNameContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunCallStmt(DreamParser::FunCallStmtContext* ctx)
{
    string fun_call;
    if (ctx->children.at(0)->getText().starts_with(D_SLASH))
    {
        if (ctx->children.at(1)->getText() == "println")
        {
            // file_util::insert_front_of_file(&_file_stream, _file_path, "#include <iostream> \n");
            vector<string>::iterator it = _converted_file.begin();
            ++it;
            _converted_file.insert(it, "#include <iostream> \n");

            fun_call.append("std::cout ");

            for (int i = 3; i < ctx->children.size() - 1; i++)
            {
                if (ctx->children.at(i)->getText() != ",")
                {
                    fun_call.append(" << ")
                            .append(ctx->children.at(i)->getText());
                }
            }

            fun_call.append(" << std::endl;");
        }

        string_util::replace_all(fun_call, ".", "->");

        if (_class_code_generator)
            _class_code_generator->current_converting()->push_back(fun_call + "\n");
        else
            _converted_file.push_back(fun_call + "\n");
        return;
    }


    std::string stmt = string_util::convert_parser_tree_to_string(ctx);
    string_util::replace_all(stmt, ".", "->");
    if (_class_code_generator)
    {
        _class_code_generator->current_converting()->push_back(stmt);
        _class_code_generator->current_converting()->emplace_back(";\n");
    }
    else
        _converted_file.push_back(stmt + ";\n");
}

void DreamParserListenerCompiler::exitFunCallStmt(DreamParser::FunCallStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterStmt(DreamParser::StmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitStmt(DreamParser::StmtContext* ctx)
{
    _converted_file.emplace_back("; \n ");
}

void DreamParserListenerCompiler::enterBinaryOpExpr(DreamParser::BinaryOpExprContext* ctx)
{
}

void DreamParserListenerCompiler::exitBinaryOpExpr(DreamParser::BinaryOpExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterArgList(DreamParser::ArgListContext* ctx)
{
}

void DreamParserListenerCompiler::exitArgList(DreamParser::ArgListContext* ctx)
{
}

void DreamParserListenerCompiler::enterLiteral(DreamParser::LiteralContext* ctx)
{
}

void DreamParserListenerCompiler::exitLiteral(DreamParser::LiteralContext* ctx)
{
}

void DreamParserListenerCompiler::enterArrayInit(DreamParser::ArrayInitContext* ctx)
{
}

void DreamParserListenerCompiler::exitArrayInit(DreamParser::ArrayInitContext* ctx)
{
}

void DreamParserListenerCompiler::enterCastExpr(DreamParser::CastExprContext* ctx)
{
}

void DreamParserListenerCompiler::exitCastExpr(DreamParser::CastExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterAssign(DreamParser::AssignContext* ctx)
{
}

void DreamParserListenerCompiler::exitAssign(DreamParser::AssignContext* ctx)
{
}

void DreamParserListenerCompiler::enterUnaryOpExpr(DreamParser::UnaryOpExprContext* ctx)
{
}

void DreamParserListenerCompiler::exitUnaryOpExpr(DreamParser::UnaryOpExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterIfStmt(DreamParser::IfStmtContext* ctx)
{
    string if_stmt = "if";

    if_stmt.append("(")
           .append(ctx->children.at(1)->getText())
           .append(")");
    _converted_file.push_back(if_stmt + "\n");
}

void DreamParserListenerCompiler::exitIfStmt(DreamParser::IfStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterIfBlock(DreamParser::IfBlockContext* ctx)
{
    _converted_file.emplace_back("{\n");
}

void DreamParserListenerCompiler::exitIfBlock(DreamParser::IfBlockContext* ctx)
{
    _converted_file.emplace_back("}\n");
}

void DreamParserListenerCompiler::enterElseClause(DreamParser::ElseClauseContext* ctx)
{
    _converted_file.emplace_back("else");
}

void DreamParserListenerCompiler::exitElseClause(DreamParser::ElseClauseContext* ctx)
{
}

void DreamParserListenerCompiler::enterAtomExpr(DreamParser::AtomExprContext* ctx)
{
}

void DreamParserListenerCompiler::exitAtomExpr(DreamParser::AtomExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterIfStmtBody(DreamParser::IfStmtBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitIfStmtBody(DreamParser::IfStmtBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterReturnStmt(DreamParser::ReturnStmtContext* ctx)
{
    _converted_file.emplace_back("return ")
                   .append(ctx->children.at(1)->getText())
                   .append(";\n");
}

void DreamParserListenerCompiler::exitReturnStmt(DreamParser::ReturnStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterElseIfClause(DreamParser::ElseIfClauseContext* ctx)
{
    _converted_file.emplace_back("else if");

    _converted_file.emplace_back("(")
                   .append(ctx->children.at(2)->getText())
                   .append(")");
}

void DreamParserListenerCompiler::exitElseIfClause(DreamParser::ElseIfClauseContext* ctx)
{
}

void DreamParserListenerCompiler::enterExpr(DreamParser::ExprContext* ctx)
{
}

void DreamParserListenerCompiler::exitExpr(DreamParser::ExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterAssignExpr(DreamParser::AssignExprContext* ctx)
{
    if (_is_in_for_condition)
    {
        return;
    }

    // common type declare and assign (int ...)
    if (string_util::str_is_common_type(ctx->children.at(0)->getText()))
    {
        _converted_file.push_back(string_util::convert_parser_tree_to_string(ctx));
        return;
    }

    // custom type declare and assign
    string assign_stmt;

    string tmp = string_util::convert_parser_tree_to_string(ctx);

    if (ctx->children.at(1)->getText() != D_COMMA && ctx->children.at(1)->getText() != D_ASSIGN)
    {
        int assign_index = -1;
        for (int i = 0; i < ctx->children.size(); i++)
            if (ctx->children.at(i)->getText() == D_ASSIGN)
                assign_index = i;

        if (assign_index == -1)
        {
            response_util::report_error("Assign error: \n" + string_util::convert_parser_tree_to_string(ctx) +
                                        "\nExpect \" = \", but not found", _file_path,
                                        static_cast<int>(ctx->getStart()->getLine()));
            return;
        }

        assign_stmt.append(ctx->children.at(0)->getText() + " ");

        // custom type declaration must be assigned to an object which is a pointer
        if (!ctx->children.at(assign_index + 1)->getText().starts_with(D_NEW))
        {
            response_util::report_error("Assign error: \n" + string_util::convert_parser_tree_to_string(ctx) +
                                        "\nExpect \" new \" TYPE, but not found", _file_path,
                                        static_cast<int>(ctx->getStart()->getLine()));
            return;
        }

        for (int i = 1; i < assign_index; i++)
        {
            assign_stmt.append("*" + ctx->children.at(i)->getText());
            if (i == assign_index - 1)
            {
                assign_stmt.append(" = ");
            }
            else
            {
                assign_stmt.append(", ");
            }
        }
        assign_stmt.append(string_util::convert_parser_tree_to_string(ctx->children.at(assign_index + 1)));
        _converted_file.push_back(assign_stmt + ";\n");

        return;
    }

    // common assign without declare
    assign_stmt.append(string_util::convert_parser_tree_to_string(ctx));

    _converted_file.push_back(assign_stmt + ";\n");
}

void DreamParserListenerCompiler::exitAssignExpr(DreamParser::AssignExprContext* ctx)
{
}

void DreamParserListenerCompiler::enterDeclaration(DreamParser::DeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::exitDeclaration(DreamParser::DeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterVarDeclaration(DreamParser::VarDeclarationContext* ctx)
{
    if (ctx->children.size() == 7)
    {
        const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

        const string var_name = child[2]->getText();
        const string var_mut = child[0]->getText();
        const string var_null = child[3]->getText();
        const string var_val = child[5]->getText();
        string var_type = child[1]->getText();

        if (var_type == D_STRING || var_type == D_STRING_ARR)
        {
            _converted_file.emplace_back("#include <string> \n");
        }

        if (var_mut == D_IMT)
        {
            _converted_file.push_back("const "
                + string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");
        }
        else if (var_mut == D_VAR)
        {
            _converted_file.push_back(string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");
        }

        if (var_null == D_NON_NULLABLE)
        {
            if (var_val == D_NULL)
            {
                cerr << "Cannot assign null to non-nullable variable" << endl;
            }

            if (string_util::str_is_only_ident(var_val))
            {
                if (_global->is_var_nullable(_package_name + _file_name + var_val))
                {
                    response_util::report_error(
                        "Cannot assign null to non-nullable variable ( " +
                        var_name + " ) \n because <" +
                        var_val +
                        "> might be null \n ",
                        _file_source,
                        static_cast<int>(ctx->getStart()->getLine()));
                }
            }

            return;
        }

        _global->add_var_nullable(_package_name + _file_name + var_name, true);
    }
    else if (ctx->children.size() == 5)
    {
        const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

        const string var_name = child[2]->getText();
        const string var_val = child[3]->getText();
        string var_type = child[0]->getText();

        if (var_type == D_STRING || var_type == D_STRING_ARR)
        {
            _converted_file.emplace_back("#include <string>\n");
        }

        _converted_file.push_back("const "
            + string_util::convert_type_to_cpp(var_type) + " "
            + var_name + " = " + var_val + ";\n");
    }
    else if (ctx->children.size() == 6)
    {
        if (ctx->children.at(0)->getText() == D_VAR || ctx->children.at(0)->getText() == D_IMT)
        {
            const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

            const string var_name = child[2]->getText();
            const string var_mut = child[0]->getText();
            const string var_val = child[4]->getText();
            string var_type = child[1]->getText();

            if (var_type == D_STRING || var_type == D_STRING_ARR)
            {
                _converted_file.emplace_back("#include <string> \n");
            }

            if (var_mut == D_IMT)
            {
                _converted_file.push_back("const "
                    + string_util::convert_type_to_cpp(var_type) + " "
                    + var_name + " = " + var_val + ";\n");
            }
            else if (var_mut == D_VAR)
            {
                _converted_file.push_back(string_util::convert_type_to_cpp(var_type) + " "
                    + var_name + " = " + var_val + ";\n");
            }

            if (var_val == D_NULL)
            {
                response_util::report_error(
                    "Cannot assign null to non-nullable variable",
                    _file_source,
                    static_cast<int>(ctx->getStart()->getLine()));
                return;
            }

            if (string_util::str_is_only_ident(var_val))
            {
                if (_global->is_var_nullable(_package_name + _file_name + var_val))
                {
                    response_util::report_error(
                        "Cannot assign null to non-nullable variable ( " +
                        var_name + " ) \n because <" +
                        var_val +
                        "> might be null \n ",
                        _file_source,
                        static_cast<int>(ctx->getStart()->getLine()));
                }
            }

            _global->add_var_nullable(_package_name + _file_name + var_name, true);
        }
        else
        {
            const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

            const string var_name = child[1]->getText();
            const string var_null = child[2]->getText();
            const string var_val = child[4]->getText();
            string var_type = child[0]->getText();

            if (var_type == D_STRING || var_type == D_STRING_ARR)
            {
                _converted_file.insert(_converted_file.begin() + 1, "#include <string>\n");
            }
            _converted_file.push_back("const "
                + string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");

            if (var_null == D_NON_NULLABLE)
            {
                if (var_val == D_NULL)
                {
                    cerr << "Cannot assign null to non-nullable variable" << endl;
                }

                if (string_util::str_is_only_ident(var_val))
                {
                    if (_global->is_var_nullable(_package_name + _file_name + var_val))
                    {
                        response_util::report_error(
                            "Cannot assign null to non-nullable variable ( " +
                            var_name + " ) \n because <" +
                            var_val +
                            "> might be null \n ",
                            _file_source,
                            static_cast<int>(ctx->getStart()->getLine()));
                    }
                }

                return;
            }

            _global->add_var_nullable(_package_name + _file_name + var_name, true);
        }
    }
}

void DreamParserListenerCompiler::exitVarDeclaration(DreamParser::VarDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterVarModifiers(DreamParser::VarModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::exitVarModifiers(DreamParser::VarModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunctionDeclaration(DreamParser::FunctionDeclarationContext* ctx)
{
    // get ctx children and compose them
    const vector<antlr4::tree::ParseTree*> trees = ctx->children;

    const string func_name = trees[1]->getText();
    string fun_decl;

    int param_list_begin = 0;
    for (auto i = 0; i < trees.size(); i++)
    {
        if (trees.at(i)->getText() == D_FUN)
            continue;
        // find the param list
        if (trees.at(i)->getText() == D_LPAREN)
            param_list_begin = i + 1;

        if (trees.at(i)->getText().starts_with(D_LBRACE))
        {
            // only one return type
            vector<antlr4::tree::ParseTree*> return_tree = trees.at(i - 1)->children;
            if (return_tree.size() == 1)
            {
                fun_decl.append(return_tree.at(0)->getText())
                        .append(" ")
                        .append(func_name)
                        .append("(");
            }
            else if (return_tree.empty())
            {
                fun_decl.append("void ")
                        .append(func_name)
                        .append("(");
            }
        }
    }

    antlr4::tree::ParseTree* params = trees.at(param_list_begin);
    if (params->getText() == D_RPAREN)
    {
        fun_decl.append(")");
        _converted_file.push_back(fun_decl + "\n");
        return;
    }

    for (const vector<antlr4::tree::ParseTree*> single_params = params->children;
         const auto single_param : single_params)
    {
        if (single_param->getText() == D_COMMA)
        {
            fun_decl.append(", ");
        }
        // format like < int a >, default it is non-nullable and immutable
        if (single_param->children.size() == 2)
        {
            string param_decl = single_param->getText();
            fun_decl.append("const ");
            fun_decl.append(string_util::convert_parser_tree_to_string(single_param));

            continue;
        }
        // format like < int a ! > or < imt int a>, default it is non-nullable and immutable
        if (single_param->children.size() == 3)
        {
            if (single_param->children.at(0)->getText() == D_IMT ||
                single_param->children.at(0)->getText() == D_VAR)
            {
                fun_decl.append(single_param->children.at(0)->getText() == D_IMT ? "const " : "")
                        .append(string_util::convert_parser_tree_to_string(single_param->children.at(1)))
                        .append(single_param->children.at(2)->getText());

                continue;
            }

            if (single_param->children.at(2)->getText() == D_NON_NULLABLE ||
                single_param->children.at(2)->getText() == D_NULLABLE)
            {
                // fun_decl.append(string_util::convert_parser_tree_to_string(single_param->children.at(1)))
                //         .append(single_param->children.at(1)->getText());

                string type = single_param->children.at(1)->getText();

                fun_decl.append("const ")
                        .append(string_util::convert_type_to_cpp(type))
                        .append(" ")
                        .append(single_param->children.at(2)->getText());

                if (single_param->children.at(2)->getText() == D_NULLABLE)
                {
                    _global->add_var_nullable(
                        _package_name + _file_name + func_name + single_param->children.at(1)->getText(), true);
                }
                continue;
            }

            response_util::report_error("Invalid parameter declaration ", _file_source,
                                        static_cast<int>(ctx->getStart()->getLine()));

            continue;
        }

        // format like < imt int a ! > or < var int a? >
        if (single_param->children.size() == 4)
        {
            if (single_param->children.at(0)->getText() == D_IMT ||
                single_param->children.at(0)->getText() == D_VAR)
            {
                fun_decl.append(single_param->children.at(0)->getText() == D_IMT ? "const " : "")
                        .append(single_param->children.at(1)->getText())
                        .append(" ")
                        .append(single_param->children.at(2)->getText());
            }
            if (single_param->children.at(3)->getText() == D_NON_NULLABLE ||
                single_param->children.at(3)->getText() == D_NULLABLE)
            {
                if (single_param->children.at(3)->getText() == D_NULLABLE)
                {
                    _global->add_var_nullable(
                        _package_name + _file_name + func_name + single_param->children.at(1)->getText(), true);
                }

                continue;
            }

            response_util::report_error("Invalid parameter declaration ", _file_source,
                                        static_cast<int>(ctx->getStart()->getLine()));
        }
    }

    fun_decl.append(")");

    _converted_file.push_back(fun_decl + "\n");
}

void DreamParserListenerCompiler::exitFunctionDeclaration(DreamParser::FunctionDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunBlock(DreamParser::FunBlockContext* ctx)
{
    if (!_class_code_generator)
        _converted_file.emplace_back(("{ \n"));
    else
        _class_code_generator->current_converting()->emplace_back("{\n");
}

void DreamParserListenerCompiler::exitFunBlock(DreamParser::FunBlockContext* ctx)
{
    if (!_class_code_generator)
        _converted_file.emplace_back(("} \n"));
    else
        _class_code_generator->current_converting()->emplace_back("}\n");
}

void DreamParserListenerCompiler::enterFunStmt(DreamParser::FunStmtContext* ctx)
{
    // read lines

    // convert to cpp
}

void DreamParserListenerCompiler::exitFunStmt(DreamParser::FunStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunVarDeclaration(DreamParser::FunVarDeclarationContext* ctx)
{
    if (ctx->children.size() == 7)
    {
        const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

        const string var_name = child[2]->getText();
        const string var_mut = child[0]->getText();
        const string var_null = child[3]->getText();
        const string var_val = child[5]->getText();
        string var_type = child[1]->getText();

        if (var_type == D_STRING || var_type == D_STRING_ARR)
        {
            _converted_file.emplace_back("#include <string> \n");
        }

        if (var_mut == D_IMT)
        {
            _converted_file.push_back("const "
                + string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");
        }
        else if (var_mut == D_VAR)
        {
            _converted_file.push_back(string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");
        }

        if (var_null == D_NON_NULLABLE)
        {
            if (var_val == D_NULL)
            {
                cerr << "Cannot assign null to non-nullable variable" << endl;
            }

            if (string_util::str_is_only_ident(var_val))
            {
                if (_global->is_var_nullable(_package_name + _file_name + var_val))
                {
                    response_util::report_error(
                        "Cannot assign null to non-nullable variable ( " +
                        var_name + " ) \n because <" +
                        var_val +
                        "> might be null \n ",
                        _file_source,
                        static_cast<int>(ctx->getStart()->getLine()));
                }
            }
        }
        else
        {
            _global->add_var_nullable(_package_name + _file_name + var_name, true);
        }
    }
    else if (ctx->children.size() == 5)
    {
        const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

        const string var_name = child[2]->getText();
        const string var_val = child[3]->getText();
        string var_type = child[0]->getText();

        if (var_type == D_STRING || var_type == D_STRING_ARR)
        {
            _converted_file.emplace_back("#include <string>\n");
        }

        _converted_file.push_back("const "
            + string_util::convert_type_to_cpp(var_type) + " "
            + var_name + " = " + var_val + ";\n");
    }
    else if (ctx->children.size() == 6)
    {
        if (ctx->children.at(0)->getText() == D_VAR || ctx->children.at(0)->getText() == D_IMT)
        {
            const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

            const string var_name = child[2]->getText();
            const string var_mut = child[0]->getText();
            const string var_val = child[4]->getText();
            string var_type = child[1]->getText();

            if (var_type == D_STRING || var_type == D_STRING_ARR)
            {
                _converted_file.emplace_back("#include <string> \n");
            }

            if (var_mut == D_IMT)
            {
                _converted_file.push_back("const "
                    + string_util::convert_type_to_cpp(var_type) + " "
                    + var_name + " = " + var_val + ";\n");
            }
            else if (var_mut == D_VAR)
            {
                _converted_file.push_back(string_util::convert_type_to_cpp(var_type) + " "
                    + var_name + " = " + var_val + ";\n");
            }

            if (var_val == D_NULL)
            {
                response_util::report_error(
                    "Cannot assign null to non-nullable variable",
                    _file_source,
                    static_cast<int>(ctx->getStart()->getLine()));
                return;
            }

            if (string_util::str_is_only_ident(var_val))
            {
                if (_global->is_var_nullable(_package_name + _file_name + var_val))
                {
                    response_util::report_error(
                        "Cannot assign null to non-nullable variable ( " +
                        var_name + " ) \n because <" +
                        var_val +
                        "> might be null \n ",
                        _file_source,
                        static_cast<int>(ctx->getStart()->getLine()));
                }
            }
        }
        else
        {
            const std::vector<antlr4::tree::ParseTree*> child = ctx->children;

            const string var_name = child[1]->getText();
            const string var_null = child[2]->getText();
            const string var_val = child[4]->getText();
            string var_type = child[0]->getText();

            if (var_type == D_STRING || var_type == D_STRING_ARR)
            {
                _converted_file.insert(_converted_file.begin() + 1, "#include <string>\n");
            }
            _converted_file.push_back("const "
                + string_util::convert_type_to_cpp(var_type) + " "
                + var_name + " = " + var_val + ";\n");

            if (var_null == D_NON_NULLABLE)
            {
                if (var_val == D_NULL)
                {
                    cerr << "Cannot assign null to non-nullable variable" << endl;
                }

                if (string_util::str_is_only_ident(var_val))
                {
                    if (_global->is_var_nullable(_package_name + _file_name + var_val))
                    {
                        response_util::report_error(
                            "Cannot assign null to non-nullable variable ( " +
                            var_name + " ) \n because <" +
                            var_val +
                            "> might be null \n ",
                            _file_source,
                            static_cast<int>(ctx->getStart()->getLine()));
                    }
                }

                return;
            }
            else
            {
                _global->add_var_nullable(_package_name + _file_name + var_name, true);
            }
        }
    }
}

void DreamParserListenerCompiler::exitFunVarDeclaration(DreamParser::FunVarDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunModifiers(DreamParser::FunModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::exitFunModifiers(DreamParser::FunModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassDeclaration(DreamParser::ClassDeclarationContext* ctx)
{
    // add the class class_name to the file
    if (ctx->children.at(0)->getText() == D_NATIVE_ANNOTATION)
    {
        vector<string> content = NativeConverter::get_native_class_code(ctx->children.at(2)->getText());

        for (auto& line : content)
        {
            _converted_file.push_back(line);
            _converted_file.emplace_back("\n");
        }


        return;
    }

    const vector<antlr4::tree::ParseTree*> trees = ctx->children;
    for (int i = 0; i < trees.size(); i++)
        if (trees.at(i)->getText() == D_CLASS)
            _class_code_generator = new ClassCodeGenerator(trees.at(i + 1)->getText());

    if (!_class_code_generator)
    {
        response_util::report_error("Class Declaration Error", _file_source,
                                    static_cast<int>(ctx->getStart()->getLine()));
        exit(1);
    }
}

void DreamParserListenerCompiler::exitClassDeclaration(DreamParser::ClassDeclarationContext* ctx)
{
    if (_class_code_generator)
    {
        _class_code_generator->current_converting()->emplace_back("}; \"");
        _converted_file.push_back(_class_code_generator->generate_code());

        delete _class_code_generator;
        _class_code_generator = nullptr;
    }
}

void DreamParserListenerCompiler::enterClassModifiers(DreamParser::ClassModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassModifiers(DreamParser::ClassModifiersContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassModifier(DreamParser::ClassModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassModifier(DreamParser::ClassModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassBlock(DreamParser::ClassBlockContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassBlock(DreamParser::ClassBlockContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassBody(DreamParser::ClassBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassBody(DreamParser::ClassBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassVarDecl(DreamParser::ClassVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassVarDecl(DreamParser::ClassVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassFuncDecl(DreamParser::ClassFuncDeclContext* ctx)
{
    // get ctx children and compose them
    const vector<antlr4::tree::ParseTree*> trees = ctx->children;

    string fun_decl;
    string func_name;

    string fun_type;

    int param_list_begin = 0;
    for (auto i = 0; i < trees.size(); i++)
    {
        // check out the reserves for function
        if (trees.at(i)->getText() == D_FUN)
        {
            func_name = trees[i + 1]->getText();
            continue;
        }
        if (trees.at(i)->getText() == D_PUBLIC
            || trees.at(i)->getText() == D_PRIVATE
            || trees.at(i)->getText() == D_PROTECTED)
        {
            _class_code_generator->set_current_visibility(getClassMemberVisibility(trees.at(i)->getText()));
            continue;
        }

        // find the param list
        if (trees.at(i)->getText() == D_LPAREN)
            param_list_begin = i + 1;

        if (trees.at(i)->getText().starts_with(D_LBRACE))
        {
            // only one return type

            if (antlr4::tree::ParseTree* return_tree = trees.at(i - 1);
                return_tree->getText().starts_with(D_RPAREN))
            {
                fun_decl.append(CPP_VOID)
                        .append(" ")
                        .append(func_name)
                        .append("(");
            }
            else if (return_tree->children.size() == 1)
            {
                fun_decl.append(return_tree->children.at(0)->getText())
                        .append(" ")
                        .append(func_name)
                        .append("(");
            }
            else // multiple return types
            {
            }
        }
    }

    antlr4::tree::ParseTree* params = trees.at(param_list_begin);
    if (params->getText() == D_RPAREN)
    {
        fun_decl.append(")");
        _class_code_generator->current_converting()->push_back(fun_decl + "\n");
        return;
    }

    for (const vector<antlr4::tree::ParseTree*> single_params = params->children;
         const auto single_param : single_params)
    {
        if (single_param->getText() == D_COMMA)
        {
            fun_decl.append(", ");
        }
        // format like < int a >, default it is non-nullable and immutable
        if (single_param->children.size() == 2)
        {
            string param_decl = single_param->getText();
            fun_decl.append("const ");
            fun_decl.append(string_util::convert_parser_tree_to_string(single_param));

            continue;
        }
        // format like < int a ! > or < imt int a>, default it is non-nullable and immutable
        if (single_param->children.size() == 3)
        {
            string val_type = single_param->children.at(1)->getText();
            if (single_param->children.at(0)->getText() == D_IMT ||
                single_param->children.at(0)->getText() == D_VAR)
            {
                fun_decl.append(single_param->children.at(0)->getText() == D_IMT ? "const " : "")
                        .append(string_util::convert_type_to_cpp(val_type))
                        .append(" ")
                        .append(single_param->children.at(2)->getText());

                continue;
            }

            if (single_param->children.at(2)->getText() == D_NON_NULLABLE ||
                single_param->children.at(2)->getText() == D_NULLABLE)
            {
                fun_decl.append(string_util::convert_parser_tree_to_string(single_param->children.at(1)))
                        .append(string_util::convert_type_to_cpp(val_type));

                if (single_param->children.at(2)->getText() == D_NULLABLE)
                {
                    _global->add_var_nullable(
                        _package_name + _file_name + func_name + single_param->children.at(1)->getText(), true);
                }
                continue;
            }

            response_util::report_error("Invalid parameter declaration ", _file_source,
                                        static_cast<int>(ctx->getStart()->getLine()));

            continue;
        }

        // format like < imt int a ! > or < var int a? >
        if (single_param->children.size() == 4)
        {
            string val_type = single_param->children.at(1)->getText();
            if (!(single_param->children.at(0)->getText() == D_IMT ||
                single_param->children.at(0)->getText() == D_VAR))
            {
                response_util::report_error("Invalid parameter declaration ", _file_source,
                                            static_cast<int>(ctx->getStart()->getLine()));
            }

            fun_decl.append(single_param->children.at(0)->getText() == D_IMT ? "const " : "")
                    .append(string_util::convert_type_to_cpp(val_type))
                    .append(" ")
                    .append(single_param->children.at(2)->getText());
            if (single_param->children.at(3)->getText() == D_NON_NULLABLE ||
                single_param->children.at(3)->getText() == D_NULLABLE)
            {
                if (single_param->children.at(3)->getText() == D_NULLABLE)
                {
                    _global->add_var_nullable(
                        _package_name + _file_name + _class_code_generator->class_name() + func_name + single_param->
                        children.at(1)->getText(), true);
                }
                continue;
            }
            response_util::report_error("Invalid parameter declaration ", _file_source,
                                        static_cast<int>(ctx->getStart()->getLine()));
        }
    }

    fun_decl.append(")");

    _class_code_generator->current_converting()->push_back(fun_decl + "\n");
}

void DreamParserListenerCompiler::exitClassFuncDecl(DreamParser::ClassFuncDeclContext* ctx)
{
    _class_code_generator->add_current();
}

void DreamParserListenerCompiler::enterClassMemberModifier(DreamParser::ClassMemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassMemberModifier(DreamParser::ClassMemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterConstructorDecl(DreamParser::ConstructorDeclContext* ctx)
{
}

void DreamParserListenerCompiler::exitConstructorDecl(DreamParser::ConstructorDeclContext* ctx)
{
}

void DreamParserListenerCompiler::enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext* ctx)
{
    _converted_file.emplace_back("{");
}

void DreamParserListenerCompiler::exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext* ctx)
{
    _converted_file.emplace_back("}");
}

void DreamParserListenerCompiler::enterThrowStmt(DreamParser::ThrowStmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitThrowStmt(DreamParser::ThrowStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterSynchronizedStmt(DreamParser::SynchronizedStmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitSynchronizedStmt(DreamParser::SynchronizedStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterTryCatchStmt(DreamParser::TryCatchStmtContext* ctx)
{
    _converted_file.emplace_back("try ");
}

void DreamParserListenerCompiler::exitTryCatchStmt(DreamParser::TryCatchStmtContext* ctx)
{
    _converted_file.emplace_back("\n");
}

void DreamParserListenerCompiler::enterCatches(DreamParser::CatchesContext* ctx)
{
}

void DreamParserListenerCompiler::exitCatches(DreamParser::CatchesContext* ctx)
{
}

void DreamParserListenerCompiler::enterCatchClause(DreamParser::CatchClauseContext* ctx)
{
    _converted_file.emplace_back("catch ");
}

void DreamParserListenerCompiler::exitCatchClause(DreamParser::CatchClauseContext* ctx)
{
}

void DreamParserListenerCompiler::enterCatchFormalParameter(DreamParser::CatchFormalParameterContext* ctx)
{
    _converted_file.emplace_back("(");

    _converted_file.push_back(string_util::convert_parser_tree_to_string(ctx));
}

void DreamParserListenerCompiler::exitCatchFormalParameter(DreamParser::CatchFormalParameterContext* ctx)
{
    _converted_file.emplace_back(")");
}

void DreamParserListenerCompiler::enterCatchType(DreamParser::CatchTypeContext* ctx)
{
}

void DreamParserListenerCompiler::exitCatchType(DreamParser::CatchTypeContext* ctx)
{
}

void DreamParserListenerCompiler::enterFinally_(DreamParser::Finally_Context* ctx)
{
    _converted_file.emplace_back("Finally([]() { \n");
}

void DreamParserListenerCompiler::exitFinally_(DreamParser::Finally_Context* ctx)
{
    _converted_file.emplace_back("});\n");
}

void DreamParserListenerCompiler::enterMemberModifier(DreamParser::MemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitMemberModifier(DreamParser::MemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterVisibilityModifier(DreamParser::VisibilityModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitVisibilityModifier(DreamParser::VisibilityModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterStaticModifier(DreamParser::StaticModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitStaticModifier(DreamParser::StaticModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterInterfaceDeclaration(DreamParser::InterfaceDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::exitInterfaceDeclaration(DreamParser::InterfaceDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterInterfaceBlock(DreamParser::InterfaceBlockContext* ctx)
{
}

void DreamParserListenerCompiler::exitInterfaceBlock(DreamParser::InterfaceBlockContext* ctx)
{
}

void DreamParserListenerCompiler::enterInterfaceBody(DreamParser::InterfaceBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitInterfaceBody(DreamParser::InterfaceBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterInterfaceVarDecl(DreamParser::InterfaceVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::exitInterfaceVarDecl(DreamParser::InterfaceVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::enterInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext* ctx)
{
}

void DreamParserListenerCompiler::exitInterfaceFuncDecl(DreamParser::InterfaceFuncDeclContext* ctx)
{
}

void DreamParserListenerCompiler::enterAnnotationDeclaration(DreamParser::AnnotationDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::exitAnnotationDeclaration(DreamParser::AnnotationDeclarationContext* ctx)
{
}

void DreamParserListenerCompiler::enterAnnotationBlock(DreamParser::AnnotationBlockContext* ctx)
{
}

void DreamParserListenerCompiler::exitAnnotationBlock(DreamParser::AnnotationBlockContext* ctx)
{
}

void DreamParserListenerCompiler::enterAnnotation(DreamParser::AnnotationContext* ctx)
{
}

void DreamParserListenerCompiler::exitAnnotation(DreamParser::AnnotationContext* ctx)
{
}

void DreamParserListenerCompiler::enterQualifiedName(DreamParser::QualifiedNameContext* ctx)
{
}

void DreamParserListenerCompiler::exitQualifiedName(DreamParser::QualifiedNameContext* ctx)
{
}

void DreamParserListenerCompiler::enterParamList(DreamParser::ParamListContext* ctx)
{
}

void DreamParserListenerCompiler::exitParamList(DreamParser::ParamListContext* ctx)
{
}

void DreamParserListenerCompiler::enterParam(DreamParser::ParamContext* ctx)
{
}

void DreamParserListenerCompiler::exitParam(DreamParser::ParamContext* ctx)
{
}

void DreamParserListenerCompiler::enterType(DreamParser::TypeContext* ctx)
{
}

void DreamParserListenerCompiler::exitType(DreamParser::TypeContext* ctx)
{
}

void DreamParserListenerCompiler::enterSingleType(DreamParser::SingleTypeContext* ctx)
{
}

void DreamParserListenerCompiler::exitSingleType(DreamParser::SingleTypeContext* ctx)
{
}

void DreamParserListenerCompiler::enterArrayType(DreamParser::ArrayTypeContext* ctx)
{
}

void DreamParserListenerCompiler::exitArrayType(DreamParser::ArrayTypeContext* ctx)
{
}

void DreamParserListenerCompiler::enterReturnType(DreamParser::ReturnTypeContext* ctx)
{
}

void DreamParserListenerCompiler::exitReturnType(DreamParser::ReturnTypeContext* ctx)
{
}

void DreamParserListenerCompiler::enterForStmt(DreamParser::ForStmtContext* ctx)
{
    _is_in_for_loop = true;
    _converted_file.emplace_back("for");
}

void DreamParserListenerCompiler::exitForStmt(DreamParser::ForStmtContext* ctx)
{
    _is_in_for_loop = false;
}

void DreamParserListenerCompiler::enterForCondition(DreamParser::ForConditionContext* ctx)
{
    _is_in_for_condition = true;
    _converted_file.emplace_back("(");
    _converted_file.push_back(string_util::convert_parser_tree_to_string(ctx));
}

void DreamParserListenerCompiler::exitForCondition(DreamParser::ForConditionContext* ctx)
{
    _converted_file.emplace_back(")");
    _is_in_for_condition = false;
}

void DreamParserListenerCompiler::enterForBlock(DreamParser::ForBlockContext* ctx)
{
    _converted_file.emplace_back("{ \n");
}

void DreamParserListenerCompiler::exitForBlock(DreamParser::ForBlockContext* ctx)
{
    _converted_file.emplace_back("} \n");
}

void DreamParserListenerCompiler::enterForBody(DreamParser::ForBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitForBody(DreamParser::ForBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterForVarDecl(DreamParser::ForVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::exitForVarDecl(DreamParser::ForVarDeclContext* ctx)
{
}

void DreamParserListenerCompiler::enterFileCodeBlock(DreamParser::FileCodeBlockContext* ctx)
{
}

void DreamParserListenerCompiler::exitFileCodeBlock(DreamParser::FileCodeBlockContext* ctx)
{
}

void DreamParserListenerCompiler::enterFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitFileCodeBlockBody(DreamParser::FileCodeBlockBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitFileCodeBlockStmt(DreamParser::FileCodeBlockStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunCodeBlock(DreamParser::FunCodeBlockContext* ctx)
{
    _converted_file.emplace_back("{ \n");
}

void DreamParserListenerCompiler::exitFunCodeBlock(DreamParser::FunCodeBlockContext* ctx)
{
    _converted_file.emplace_back("} \n");
}

void DreamParserListenerCompiler::enterFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext* ctx)
{
}

void DreamParserListenerCompiler::exitFunCodeBlockBody(DreamParser::FunCodeBlockBodyContext* ctx)
{
}

void DreamParserListenerCompiler::enterFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitFunCodeBlockStmt(DreamParser::FunCodeBlockStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterEveryRule(antlr4::ParserRuleContext* ctx)
{
}

void DreamParserListenerCompiler::exitEveryRule(antlr4::ParserRuleContext* ctx)
{
}

void DreamParserListenerCompiler::visitTerminal(antlr4::tree::TerminalNode* /*node*/)
{
}

void DreamParserListenerCompiler::visitErrorNode(antlr4::tree::ErrorNode* /*node*/)
{
}
