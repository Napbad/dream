//
// Created by napbad on 9/23/24.
//

#include "DreamParserListenerCompiler.h"

#include "common/dream_const.h"
#include "common/reserve.h"
#include "compiler/NativeConverter.h"
#include "compiler/gen/ClassFunGenerator.h"
#include "compiler/gen/FunDataRootGenerator.h"
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
    _own_struct_data_code_generator = nullptr;
    _input_struct_data_code_generator = nullptr;
    _fun_var_generator = nullptr;
    _file_var_generator = nullptr;
    _fun_generator = nullptr;
    _class_fun_generator = nullptr;
    _file_struct_generator = new FileStructGenerator(file_name);
    _class_var_generator = nullptr;
    _fun_data_root_generator = new FunDataRootGenerator();
}

DreamParserListenerCompiler::~DreamParserListenerCompiler() = default;

string DreamParserListenerCompiler::file_source()
{
    return _file_source;
}

Hierarchy* DreamParserListenerCompiler::current_hierarchy() const
{
    return _current_hierarchy;
}

void DreamParserListenerCompiler::enterProgram(DreamParser::ProgramContext* ctx)
{
    _current_hierarchy = Hierarchy::file_hierarchy(_file_name.substr(0, _file_name.length() - 5));
}

void DreamParserListenerCompiler::exitProgram(DreamParser::ProgramContext* ctx)
{
    // compile the file
    if (_package_name == MAIN_PACKAGE && _file_name == MAIN_FILE)
    {
        // add the runtime stmts:
        _converted_file.insert(_converted_file.end() - 2, "GLOBAL_DATA_ROOT->destroy();");
    }
    _header_file_stream << "#pragma once \n";

    for (auto& line : _converted_file)
    {
        _file_stream << line;

        if (line.starts_with("#include ") && !line.starts_with(
            "#include \"" + _file_name.substr(0, _file_name.length() - 4) + ".h\""))
            _header_file_stream << line;
    }
    _file_stream.close();

    _header_file_stream << _file_struct_generator->generate_code();
    _header_file_stream.close();

    cout << flush;


    if (_package_name == MAIN_PACKAGE && _file_name == MAIN_FILE)
    {
        // compile
        const string command = "g++ -lstdc++ -std=c++17" +
            string_util::get_text_from_vector(_global->file_to_compile_list()) + " -o " + _file_path.substr(
                0, _file_path.length() - 4) + ".o \n";

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
        print(cout,
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
    _header_file_stream = file_util::create_file(path + _file_name.substr(0, _file_name.length() - 4) + ".h");

    _file_stream = std::move(_fstream);

    _converted_file.push_back("// package " + ctx->children.at(1)->getText() + "\n");
    _package_hierarchy = file_util::get_package_hierarchy(_package_name);

    // set up the hierarchy, merge the current hierarchy into the global hierarchy
    Hierarchy* tmp = _package_hierarchy;
    tmp = Hierarchy::merge_hierarchy(_global->hierarchy(), tmp);
    _current_hierarchy = new Hierarchy(_file_name.substr(0, _file_name.size() - 4), HierarchyType::FILE, tmp, {});
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
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/class/Object.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/gc/DataCopy.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/gc/FunDataRoot.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/gc/DataPath.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/gc/DataNode.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/gc/DataRoot.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + "/natives/exception/Exception.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/reserve/d_define.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1, import_stmt + RUNTIME_DIR + "/reserve/Finally.h\" \n");
    _converted_file.insert(_converted_file.begin() + 1,
                           import_stmt + RUNTIME_DIR + "/" + "global/global_runtime_depen.h\" \n");

    _converted_file.insert(_converted_file.begin() + 1, "#include <string> \n");
    _converted_file.insert(_converted_file.begin() + 1, "#include <cstdint> \n");
    _converted_file.insert(_converted_file.begin() + 1,
                           "#include \"" + _file_name.substr(0, _file_name.size() - 4) + ".h\" \n");
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
                           _root_path_to_include + path + ".h\"\n");
}

void DreamParserListenerCompiler::exitImportStmt(DreamParser::ImportStmtContext* ctx)
{
    // begin the real file
    // fill the file metadata
    // _converted_file.emplace_back("// file meta data:\n");
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
    if (ctx->getText().starts_with("super("))
        if (_class_fun_generator != nullptr)
        {
            _class_fun_generator->set_has_super();
        }

    if (_is_in_if_cond) return;
    vector<string> real_args;
    if (ctx->argList() != nullptr)
    {
        for (vector<antlr4::tree::ParseTree*> args = ctx->argList()->children;
            const auto arg : args)
        {
            bool arg_converted = false;
            for (size_t pos = _curr_fun_begin_pos; pos < _converted_file.size(); pos++)
                if (string_util::find_expect_str(_converted_file.at(pos), DATA_NODE_PREFIX + arg->getText()))
                {
                    real_args.push_back(DATA_NODE_PREFIX + arg->getText());
                    arg_converted = true;
                }

            if (!arg_converted)
                real_args.push_back(arg->getText());
        }
    }

    if (ctx->children.at(0)->getText().starts_with(D_SLASH))
    {
        string fun_call;
        if (ctx->children.at(1)->getText() == "println")
        {
            // file_util::insert_front_of_file(&_file_stream, _file_path, "#include <iostream> \n");
            auto it = _converted_file.begin();
            ++it;
            _converted_file.insert(it, "#include <iostream> \n");

            fun_call.append("std::cout ");

            for (const auto & real_arg : real_args)
            {
                if (real_arg != ",")
                {
                    fun_call.append(" << ")
                            .append(real_arg);
                }
            }

            fun_call.append(" << std::endl");
        }

        string_util::replace_all_without_str(fun_call, ".", "->");

        if (_class_fun_generator)
            _class_fun_generator->add_stmt(fun_call + ";\n");
        else
            _converted_file.push_back(fun_call + ";\n");
        return;
    }


    std::string fun_call;

    for (const auto& i : ctx->children)
    {
        if (i->getText() == "(")
            break;
        fun_call.append(i->getText());
    }

    fun_call.append("(");
    for (const auto& real_arg : real_args)
    {
        if (real_arg != ",")
            fun_call.append(real_arg);
        else
            fun_call.append(", ");
    }
    fun_call.append(")");
    string_util::replace_all_without_str(fun_call, ".", "->");

    if (_class_fun_generator)
        _class_fun_generator->add_stmt(fun_call + ";\n");
    else
        _converted_file.push_back(fun_call + ";\n");
}

void DreamParserListenerCompiler::exitFunCallStmt(DreamParser::FunCallStmtContext* ctx)
{
}

void DreamParserListenerCompiler::enterStmt(DreamParser::StmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitStmt(DreamParser::StmtContext* ctx)
{
    _converted_file.emplace_back("\n ");
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
    _is_in_if_cond = true;
    string if_stmt = "if";

    string cond = ctx->children.at(1)->getText();
    string_util::replace_all_without_str(cond, ".", "->");

    if_stmt.append("(")
           .append(cond)
           .append(")");
    _converted_file.push_back(if_stmt + "\n");
}

void DreamParserListenerCompiler::exitIfStmt(DreamParser::IfStmtContext* ctx)
{
    _is_in_if_cond = false;
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
        // _converted_file.push_back(assign_stmt + ";\n");


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
    if (global_flag_is_debug)
    {
        dbg_print(std::cout, "VarDeclaration: " + string_util::convert_parser_tree_to_string(ctx) + "\n",
                  file_util::FileColor::WHITE);
    }
    _file_var_generator = new FileVarGenerator(this);
    _file_var_generator->init(ctx);

    _converted_file.push_back(_file_var_generator->generate_code());

    _file_struct_generator->add_var_decl(_file_var_generator->generate_decl());

    if (_file_var_generator->is_nullable())
        _global->add_var_nullable(_current_hierarchy->get_full_hierarchy_name() +
                                  _file_var_generator->name(), true);
}

void DreamParserListenerCompiler::exitVarDeclaration(DreamParser::VarDeclarationContext* ctx)
{
    delete _file_var_generator;
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
    _current_hierarchy = new Hierarchy(func_name, HierarchyType::FILE_FUN, _current_hierarchy, {});
    string hierarchy_name = _current_hierarchy->get_full_hierarchy_name();
    string_util::replace_all(hierarchy_name, ".", "_");

    _fun_generator = new FunGenerator();
    _fun_generator->init(ctx);
    const string fun_decl = _fun_generator->generate_code();

    string full_hierarchy_name = _current_hierarchy->get_full_hierarchy_name();

    _converted_file.push_back(fun_decl + "\n");
    _file_struct_generator->add_fun_decl(fun_decl + ";\n");

    _fun_data_root_generator->set_name(_fun_generator->name());
}

void DreamParserListenerCompiler::exitFunctionDeclaration(DreamParser::FunctionDeclarationContext* ctx)
{
    string hierarchy_name = _current_hierarchy->get_full_hierarchy_name();
    string_util::replace_all(hierarchy_name, ".", "_");

    _curr_fun_begin_pos = _converted_file.size();
    _current_hierarchy = _current_hierarchy->parent();
}

void DreamParserListenerCompiler::enterFunBlock(DreamParser::FunBlockContext* ctx)
{
    if (!_class_fun_generator)
    {
        _converted_file.emplace_back("{ \n");
        _converted_file.push_back(_fun_data_root_generator->generate_code());
        vector<FUN_PARAM_TYPE> params = _fun_generator->params();

        return;
    }
    _class_fun_generator->add_stmt(_fun_data_root_generator->generate_code());
}

void DreamParserListenerCompiler::exitFunBlock(DreamParser::FunBlockContext* ctx)
{
    // if is the main function, then start the relative work of GC
    if (_package_name == MAIN_PACKAGE && _file_name == MAIN_FILE)
    {
    }
    if (!_class_fun_generator)
        _converted_file.emplace_back("\n } \n");


    delete _fun_generator;
    _fun_generator = nullptr;
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
    _fun_var_generator = new FunVarGenerator(this);
    _fun_var_generator->init(ctx);

    if (_fun_var_generator->is_nullable())
        _global->add_var_nullable(_current_hierarchy->get_full_hierarchy_name() +
                                  _fun_var_generator->name(), true);
}

void DreamParserListenerCompiler::exitFunVarDeclaration(DreamParser::FunVarDeclarationContext* ctx)
{
    if (!_class_code_generator)
        _converted_file.push_back(_fun_var_generator->generate_code());
    else
        _class_fun_generator->add_stmt(_fun_var_generator->generate_code());
    delete _fun_var_generator;
    _fun_var_generator = nullptr;
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
        for (vector<string> content = NativeConverter::get_native_class_code(ctx->children.at(2)->getText());
             auto& line : content)
        {
            _converted_file.push_back(line);
            _converted_file.emplace_back("\n");
        }

        return;
    }

    const vector<antlr4::tree::ParseTree*> trees = ctx->children;
    std::string class_name;
    for (int i = 0; i < trees.size(); i++)
        if (trees.at(i)->getText() == D_CLASS)
        {
            for (int j = i + 1; j < trees.size(); j++)
                if (!trees.at(j)->getText().starts_with("{"))
                    class_name.append(trees.at(j)->getText())
                              .append(" ");
            _class_code_generator = new ClassCodeGenerator(class_name);
        }


    if (!_class_code_generator)
    {
        response_util::report_error("Class Declaration Error", _file_source,
                                    static_cast<int>(ctx->getStart()->getLine()));
        exit(1);
    }
    // add a class definition to file
    _file_struct_generator->add_new_class_code_generator(_class_code_generator->class_name());
}

void DreamParserListenerCompiler::exitClassDeclaration(DreamParser::ClassDeclarationContext* ctx)
{
    if (_class_code_generator)
    {
        // push all method implementations to source file
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
    _class_var_generator = new ClassVarGenerator();

    _class_var_generator->init(ctx);
}

void DreamParserListenerCompiler::exitClassVarDecl(DreamParser::ClassVarDeclContext* ctx)
{
    if (_class_var_generator)
        // add class member to header file, class definition
        _file_struct_generator->get_newest_class_struct_generator().add_to_current(
            _class_var_generator->visibility(),
            _class_var_generator->generate_code());
    _file_struct_generator->get_newest_class_struct_generator().add_current();

    delete _class_var_generator;

    _class_var_generator = nullptr;
}

void DreamParserListenerCompiler::enterClassFuncDecl(DreamParser::ClassFuncDeclContext* ctx)
{
    // get ctx children and compose them
    const vector<antlr4::tree::ParseTree*> trees = ctx->children;

    // generate the class function generator
    _class_fun_generator = new ClassFunGenerator();
    _class_fun_generator->init(ctx, _class_code_generator->class_name());
    const string fun_decl = _class_fun_generator->generate_code();

    // add declaration to the class struct
    _file_struct_generator->get_newest_class_struct_generator().add_to_current(
        _class_fun_generator->visibility(),
        _class_fun_generator->generate_decl_code() + ";\n");
    _file_struct_generator->get_newest_class_struct_generator().add_current();
    _fun_data_root_generator->set_name(_class_fun_generator->name());
}

void DreamParserListenerCompiler::exitClassFuncDecl(DreamParser::ClassFuncDeclContext* ctx)
{
    // add implementation to the class source code
    _class_code_generator->add_to_current(_class_fun_generator->generate_code());
    _class_code_generator->add_current();
    delete _class_fun_generator;
    _class_fun_generator = nullptr;
}

void DreamParserListenerCompiler::enterClassMemberModifier(DreamParser::ClassMemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::exitClassMemberModifier(DreamParser::ClassMemberModifierContext* ctx)
{
}

void DreamParserListenerCompiler::enterConstructorDecl(DreamParser::ConstructorDeclContext* ctx)
{
    _class_fun_generator = new ClassFunGenerator();
    _class_fun_generator->set_is_constructor();
    _class_fun_generator->init(ctx, _class_code_generator->class_name());
    const string fun_decl = _class_fun_generator->generate_code();

    // add declaration to the class struct
    _file_struct_generator->get_newest_class_struct_generator().add_to_current(
        _class_fun_generator->visibility(),
        _class_fun_generator->generate_decl_code() + ";\n");
    _file_struct_generator->get_newest_class_struct_generator().add_current();
    _fun_data_root_generator->set_name(_class_fun_generator->name());
}

void DreamParserListenerCompiler::exitConstructorDecl(DreamParser::ConstructorDeclContext* ctx)
{
    // add implementation to the class source code
    _class_code_generator->add_to_current(_class_fun_generator->generate_code());
    _class_code_generator->add_current();
    delete _class_fun_generator;
    _class_fun_generator = nullptr;
}

void DreamParserListenerCompiler::enterClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext* ctx)
{
    //_converted_file.emplace_back("{");
}

void DreamParserListenerCompiler::exitClassFunStmtBlock(DreamParser::ClassFunStmtBlockContext* ctx)
{
    //_converted_file.emplace_back("}");
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
    const auto hierarchy = new Hierarchy(FOR_STMT + string_util::gen_unique_name(),
                                         HierarchyType::FOR_STMT, _current_hierarchy, {});
    _current_hierarchy = hierarchy;
}

void DreamParserListenerCompiler::exitForStmt(DreamParser::ForStmtContext* ctx)
{
    _is_in_for_loop = false;
    _current_hierarchy = _current_hierarchy->parent();
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

void DreamParserListenerCompiler::enterDeleteStmt(DreamParser::DeleteStmtContext* ctx)
{
}

void DreamParserListenerCompiler::exitDeleteStmt(DreamParser::DeleteStmtContext* ctx)
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
