#pragma once
#include <algorithm>
#include <vector>

template <class T> int dedup(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    return vec.size();
}