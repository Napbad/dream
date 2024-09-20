//
// Created by napbad on 9/10/24.
//

#include "parse_util.h"
#include "./common/reserved.h"

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <tree/ParseTree.h>

#include "check.h"
#include "common/dval_enum.h"

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
    Package *parse_package_tree(const std::string &full_name) {
        const vector<string> *package = parsePackage(full_name);

        if (package == nullptr || package->empty()) {
            return nullptr;
        }

        Package *pkg = new Package(package->at(package->size() - 1));
        for (int i = static_cast<int>(package->size()) - 2; i >= 0; i--) {
            Package *parent = new Package(package->at(i));
            pkg = parent;
        }

        delete package;

        return pkg;
    }

    void print_package_tree(const Package *package) {
        print_package_tree(package, 0);
    }

    void print_package_tree(const Package *package, const int level) {
        if (package == nullptr) {
            return;
        }
        for (int i = 0; i < level; i++) {
            std::cout << "  ";
        }

        std::cout << package->name() << std::endl;

        for (const auto &child: *package->children()) {
            print_package_tree(child, level + 1);
        }
    }

    void print_expr_tree(const Dval *val) {
        print_expr_tree(val, 0);
    }

    void print_val(const Dval &val) {
        switch (val.type()) {
            case DVAL_INT:
                std::cout << val.int_value() << std::endl;
                break;
            case DVAL_FLOAT:
                std::cout << val.float_value() << std::endl;
                break;
            case DVAL_BOOL:
                std::cout << val.bool_value() << std::endl;
                break;
            case DVAL_STR:
                std::cout << val.string_value() << std::endl;
                break;
            case DVAL_OP:
            case DVAL_IDENT:
            case DVAL_FUN:
                std::cout << val.identifier() << std::endl;
                break;
            case DVAL_ERR:
                std::cout << val.err() << std::endl;
                break;
            default:
                std::cout << "Invalid type" << std::endl;
                break;
        }
    }

    void print_val_ln(const Dval &val) {
        print_val(val);
        cout << endl;
    }

    void print_expr_tree(const Dval *val, const int level) {
        if (val == nullptr) {
            return;
        }
        for (int i = 0; i < level; i++) {
            std::cout << "  ";
        }

        print_val(*val);

        if (val->child() == nullptr) {
            return;
        }

        for (const auto child: *val->child()) {
            print_expr_tree(child, level + 1);
        }
    }


    Dval *parse_expr(antlr4::tree::ParseTree &val, const Denv *env) {
        Dval *tree = parse_expr_tree(val);

        // print_expr_tree(tree);

        Dval *expr = calc_expr(tree, env);

        return expr;
    }

    pair<int, string> find_op(const string &expr) {
        pair<int, string> res = make_pair(expr.size(), "");

        for (const auto &op: ops) {
            if (auto pos = expr.find(op); pos != std::string::npos && pos < res.first) {
                res = make_pair(pos, op);
            }
        }

        return res;
    }

    Dval *calc_expr(Dval *exp, const Denv *env) {
        if (exp == nullptr) {
            return nullptr;
        }

        if (!exp->child()->empty()) {
            if (exp->child()->size() == 1) {
                return calc_expr(exp->child()->at(0), env);
            }
            if (exp->child()->size() == 2) {
                return (**exp->child()->at(0)->fun())(env, {calc_expr(exp->child()->at(2), env), nullptr});
            }
            if (exp->child()->size() == 3) {
                Dval * val1 = calc_expr(exp->child()->at(0), env);
                Dval * val2 = calc_expr(exp->child()->at(2), env);
                
                return (**exp->child()->at(1)->fun())(env, {val1, val2});
            }
            if (exp->child()->size() > 3) {
                return dval::dval_err("Invalid expression");
            }
        }

        if (check::str_is_char(exp->string_value(), '(') || check::str_is_char(exp->string_value(), ')')) {
            return new Dval();
        }

        if (check::is_val(exp)) {
            return exp;
        }

        if (exp->type() == DVAL_STR) {
            return dval::dval_str(exp->string_value(), "", IMMUTABLE, NON_NULLABLE);
        }

        if (exp->type() == DVAL_IDENT) {
            return new Dval(*env->get(exp->identifier()));
        }

        if (exp->type() == DVAL_FUN) {
            const builtin *builtin = exp->fun();

            return (**builtin)(env, {exp->child()->at(0), exp->child()->at(1)});
        }

        return dval::dval_err("Invalid expression");
    }

    Dval *parse_expr_tree(antlr4::tree::ParseTree &val) {
        Dval *root = new Dval();
        // has child

        // (20 + 10 * 40 - 100 / 5) + 10 * (10 + -1) % 4 + (true & a | "ab");
        string text = val.getText();
        if (!val.children.empty()) {
            if (val.children.at(0)->getText() == "(") {
                return parse_expr_tree(*val.children.at(1));
            }

            for (const auto &child_: val.children) {
                text = child_->getText();
            }

            for (const auto &child: val.children) {
                const Dval * expr_tree = parse_expr_tree(*child);
                if (expr_tree == nullptr) {
                    continue;
                }
                root->add_child(parse_expr_tree(*child));
            }
        }

        if (val.getTreeType() == antlr4::tree::ParseTreeType::TERMINAL) {
            if (check::str_is_num(val.getText())) {
                return dval::dval_gen(val.getText(), D_INT, "", IMMUTABLE, NON_NULLABLE);
            }
            if (check::str_is_float(val.getText())) {
                return dval::dval_gen(val.getText(), D_FLOAT, "", IMMUTABLE, NON_NULLABLE);
            }
            if (check::str_is_op(val.getText())) {
                return dval::dval_op(val.getText());
            }
            if (check::str_is_bool(val.getText())) {
                return dval::dval_gen(val.getText(), D_BOOL, "", IMMUTABLE, NON_NULLABLE);
            }
            if (check::str_is_str(val.getText())) {
                return dval::dval_gen(val.getText(), D_STRING, "", IMMUTABLE, NON_NULLABLE);
            }
            if (check::str_is_char(val.getText(), '(')) {
                return nullptr;
            }
            if (check::str_is_char(val.getText(), ';')) {
                return nullptr;
            }

            return dval::dval_gen(val.getText(), D_IDENTIFIER, val.getText(), IMMUTABLE, NON_NULLABLE);
        }

        return root;
    }

    Dval * parse_array_expr(const string &type, const antlr4::tree::ParseTree &tree, const Denv *denv) {
        if (tree.children.size() < 3) {
            return dval::dval_array_gen(type, "", MUTABLE, NULLABLE);
        }
        Dval * array = dval::dval_array_gen(type, "", MUTABLE, NULLABLE);
        for (int i = 1; i < tree.children.size() - 1; i++) {
            if (tree.children.at(i)->getText() == D_COMMA) {
                continue;
            }
            Dval * dval = parse_expr(*tree.children.at(i), denv);
            const Dval * expr = calc_expr(dval, denv);
            if (expr->type() == DVAL_ERR) {
                return dval::dval_err(expr->err());
            }
            if (expr->type() != dval::get_type(type.substr(0, type.find('[')))) {
                return dval::dval_err("Invalid type");
            }
            array->arr_val()->push_back(const_cast<vector<Dval *>::value_type>(expr));
        }
        return array;
    }
}
