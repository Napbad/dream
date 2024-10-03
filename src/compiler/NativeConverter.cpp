//
// Created by napbadsen on 24-10-2.
//

#include "NativeConverter.h"

#include "common/dream_const.h"
#include "util/file_util.h"
#include "util/string_util.h"


std::vector<std::string> NativeConverter::get_native_class_code(const std::string& class_name)
{
    for (std::vector<std::string> files = file_util::get_all_files_in_dir(native_file_path);
            const auto& file : files)
    {
        if (file.ends_with(class_name + CONVERT_DESTINATION_FILE_TYPE))
        {
            std::vector<std::string> res_vec = file_util::get_file_content(file);
            return res_vec;
        }
    }

    response_util::report_error(
        "Could not find native class! \n"
        "   class name -> " + class_name + " \n ", class_name, 0);

    return {};
}
