#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../utility/int_alias.cpp"

template <class T> std::vector<std::pair<T, int>> factorize(T x) {
    assert(x > 0);
    std::vector<std::pair<T, int>> ret;
    for (T i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ret.emplace_back(i, 0);
            while (x % i == 0) {
                ret.back().second++;
                x /= i;
            }
        }
    }
    if (x > 1) {
        ret.emplace_back(x, 1);
    }
    return ret;
}
