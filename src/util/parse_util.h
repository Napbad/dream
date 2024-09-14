//
// Created by napbad on 9/10/24.
//

#pragma once
#include <string>
#include <vector>
#include <tree/ParseTree.h>

#include "model/Package.h"
#include "parse/DreamCommonParserListener.h"

using namespace std;

namespace util::parse {
    std::vector<std::string> *parsePackage(const string &full_name);

    Package* parse_package_tree(const string &full_name);

    void print_package_tree(const Package *package);

    void print_package_tree(const Package *package, int level);

    void print_val(const Dval & val);

    void print_val_ln(const Dval & val);

    void print_expr_tree(const Dval* val);

    void print_expr_tree(const Dval* val, int level);

    Dval *parse_expr(antlr4::tree::ParseTree & val, const Denv *env);

    pair<int, string> find_op(const string& expr);

    Dval* calc_expr(Dval *exp, const Denv *env);

    Dval* parse_expr_tree(antlr4::tree::ParseTree &val);

    Dval* parse_array_expr(const string & type, const antlr4::tree::ParseTree & tree, const Denv * denv);
}

