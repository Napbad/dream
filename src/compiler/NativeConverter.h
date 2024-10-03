//
// Created by napbadsen on 24-10-2.
//

#ifndef NATIVECONVERTER_H
#define NATIVECONVERTER_H

#include <string>
#include <vector>

// this file is used to generate the native code from native folder

const std::string native_file_path = "../build/native";


class NativeConverter {
public:
    static std::vector<std::string> get_native_class_code(const std::string& class_name);
};


#endif //NATIVECONVERTER_H
