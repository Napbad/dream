//
// Created by napbad on 9/10/24.
//

#include "parse_util.h"

#include <iostream>
#include <vector>
#include <string>

const char *D_PACKAGE_SPLIT = ".";

namespace util::parse {

std::vector<std::string>* parsePackage(const std::string& full_name) {
    if (full_name.empty()) {
        return nullptr;
    }

    const size_t split_pos = full_name.find(D_PACKAGE_SPLIT);

    // 创建一个 vector 对象，并用指定大小初始化
    std::vector<std::string>* res = new std::vector<std::string>;

    // 分割字符串并填充到 vector 中
    size_t start = 0;
    size_t end = 0;
    while ((end = full_name.find(D_PACKAGE_SPLIT, start)) != std::string::npos) {
        res->push_back(full_name.substr(start, end - start));
        start = end + 1;
    }
    // 添加最后一个子串
    res->push_back(full_name.substr(start));

    return res;
}

// Refine the parse_package_tree function to construct Package objects
Package* parsePackageTree(const std::string &full_name) {
    const vector<string> * package = parsePackage(full_name);

    if (package == nullptr || package->empty()) {
        return nullptr;
    }

    Package* pkg = new Package(package->at(package->size() - 1));
    for (int i = static_cast<int>(package->size()) - 2; i >= 0; i--) {
        Package* parent = new Package(package->at(i));
        pkg = parent;
    }

    return pkg;
}

void printPackageTree(const Package *package) {
    printPackageTree(package, 0);
}

void printPackageTree(const Package *package, int level) {
    if (package == nullptr) {
        return;
    }
    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }

    std::cout << package->name() << std::endl;

    for (const auto& child : *package->children()) {
        printPackageTree(child, level + 1);
    }
}
}
