#pragma once
#include <algorithm>
#include <vector>
#include "int_alias.cpp"

template <class T> usize compress(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    return vec.size();
}

template <class T> usize lowb(const std::vector<T>& vec, const T& val) {
    return std::distance(vec.cbegin(), std::lower_bound(vec.cbegin(), vec.cend(), val));
}

template <class T> usize upb(const std::vector<T>& vec, const T& val) {
    return std::distance(vec.cbegin(), std::upper_bound(vec.cbegin(), vec.cend(), val));
}