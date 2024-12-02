//
// Created by napbad on 11/18/24.
//

#ifndef DATA_STRUCT_UTIL_H
#define DATA_STRUCT_UTIL_H
#include <algorithm>
#include <vector>

namespace dap::util
{
template <typename T> std::vector<T> getSubVector(const std::vector<T> &vec, size_t start, size_t end)
{
    const auto &startIt = vec.begin() + start;
    const auto &endIt = vec.begin() + end;
    return std::vector<T>(startIt, endIt);
}

template <typename T>
bool findInVec(const std::vector<T> &vec, const T &elem)
{
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}
} // namespace ds_util

#endif // DATA_STRUCT_UTIL_H