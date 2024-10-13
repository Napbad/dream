/// \file
/// \brief This file is used to handle the response of the compiler.
/// \date 9/23/24
/// \author napbad

#ifndef RESPONSE_UTIL_H
#define RESPONSE_UTIL_H

#include <string>

/// \namespace response_util
/// \brief Namespace containing utility functions related to handling compiler responses.
namespace response_util {

    /// \brief Reports an error with detailed information.
    ///
    /// This function is used to report an error message along with the file name and line number where the error occurred.
    ///
    /// \param msg The error message to be reported.
    /// \param file_name The name of the file where the error occurred.
    /// \param line The line number in the file where the error occurred.
    void report_error(const std::string &msg, const std::string &file_name, int line);

    /// \brief Reports an error message.
    ///
    /// This function is used to report an error message without detailed file and line information.
    ///
    /// \param msg The error message to be reported.
    void report_error(const std::string& msg);

} // namespace response_util

#endif // RESPONSE_UTIL_H