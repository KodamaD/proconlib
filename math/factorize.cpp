#pragma once
#include <cassert>
#include <utility>
#include <vector>

template <class T> std::vector<std::pair<T, int>> factorize(T x) {
    assert(x > 0);
    std::vector<std::pair<T, int>> ret;
    for (T p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e += 1;
            }
            ret.emplace_back(p, e);
        }
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}
