#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <class T> int lowb(const std::vector<T>& vec, const T& val) {
    return std::distance(vec.cbegin(), std::lower_bound(vec.cbegin(), vec.cend(), val));
}