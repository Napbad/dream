//
// Created by napbad on 9/18/24.
//

#include "string_util.h"

using namespace std;

vector<string> string_util::split(const string &str, const char delimiter) {
    auto pos = str.find(delimiter);
    string _str = str;
    vector<string> result;

    while (pos != string::npos) {
        result.push_back(_str.substr(0, pos));
        _str = _str.substr(pos + 1);
        pos = _str.find(delimiter);
    }

    result.push_back(_str);

    return result;
}
