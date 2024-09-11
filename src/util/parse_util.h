//
// Created by napbad on 9/10/24.
//

#pragma once
#include <string>
#include <vector>

#include "model/Package.h"

using namespace std;

namespace util::parse {
    std::vector<std::string> *parsePackage(const string &full_name);

    Package* parsePackageTree(const string &full_name);

    void printPackageTree(const Package *package);

    void printPackageTree(const Package *package, int level);

    Dval *parseExpr(const antlr4::tree::ParseTree & val, const Denv *env);

    pair<int, string> findOp(const string& expr);

    Dval* calc_expr(Dval *exp, const Denv *env);
}

