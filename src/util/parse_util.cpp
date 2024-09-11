//
// Created by napbad on 9/10/24.
//

#include "parse_util.h"
#include "./model/reserved.h"

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <tree/ParseTree.h>

#include "check.h"

namespace util::parse {
    std::vector<std::string> *parsePackage(const std::string &full_name) {
        if (full_name.empty()) {
            return nullptr;
        }

        std::vector<std::string> *res = new std::vector<std::string>;

        size_t start = 0;
        size_t end = 0;
        while ((end = full_name.find('.', start)) != std::string::npos) {
            res->push_back(full_name.substr(start, end - start));
            start = end + 1;
        }
        res->push_back(full_name.substr(start));

        return res;
    }

    // Refine the parse_package_tree function to construct Package objects
    Package *parsePackageTree(const std::string &full_name) {
        const vector<string> *package = parsePackage(full_name);

        if (package == nullptr || package->empty()) {
            return nullptr;
        }

        Package *pkg = new Package(package->at(package->size() - 1));
        for (int i = static_cast<int>(package->size()) - 2; i >= 0; i--) {
            Package *parent = new Package(package->at(i));
            pkg = parent;
        }

        return pkg;
    }

    void printPackageTree(const Package *package) {
        printPackageTree(package, 0);
    }

    void printPackageTree(const Package *package, const int level) {
        if (package == nullptr) {
            return;
        }
        for (int i = 0; i < level; i++) {
            std::cout << "  ";
        }

        std::cout << package->name() << std::endl;

        for (const auto &child: *package->children()) {
            printPackageTree(child, level + 1);
        }
    }

    Dval *parseExpr(const antlr4::tree::ParseTree & val, const Denv *env) {
        Dval *root = dval::dval_op("");

        std::stack<int> stack;
        const Dval *current = root;



        if (!stack.empty()) {
            throw std::invalid_argument("Invalid expression");
        }

        return root;
    }

    pair<int, string> findOp(const string &expr) {
        pair<int, string> res = make_pair(expr.size(), "");

        stack<int> stk;

        for (const auto &c: expr) {
            // if (stk.empty()) {
            //     if (ops_c.find(c)) {
            //
            //     }
            // }

            if (c == '(') {
                stk.push(1);
            } else if (c == ')') {
                stk.pop();
            }
        }

        for (const auto &op: ops) {
            if (auto pos = expr.find(op); pos != std::string::npos && pos < res.first) {
                res = make_pair(pos, op);
            }
        }

        return res;
    }

    Dval * calc_expr(Dval *exp, const Denv *env) {

        if (check::isVal(exp)) {
            return exp;
        }

        const builtin* builtin = exp->fun();

        return (**builtin)(env, exp->child()->at(0), exp->child()->at(1));
    }
}
