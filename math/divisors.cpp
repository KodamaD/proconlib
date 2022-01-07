#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <class T> std::vector<T> divisors(const T& x) {
    std::vector<T> small, big;
    for (T i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            small.push_back(i);
            if (i * i != x) big.push_back(x / i);
        }
    }
    small.reserve(small.size() + big.size());
    std::copy(big.rbegin(), big.rend(), std::back_inserter(small));
    return small;
}
