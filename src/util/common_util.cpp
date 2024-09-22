//
// Created by napbad on 9/20/24.
//

#include "common_util.h"

using namespace std;

std::vector<std::string> common_util::split(const std::string &str, const std::string &delim) {
    auto pos = str.find(delim);
    string _str = str;
    vector<string> result;

    while (pos != string::npos) {
        result.push_back(_str.substr(0, pos));
        _str = _str.substr(pos + 1);
        pos = _str.find(delim);
    }

    result.push_back(_str);

    return result;
}
