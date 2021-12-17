#pragma once
#include <vector>
#include <cassert>
#include "../utility/rep.cpp"

template <class T> void subset_mobius_transform(std::vector<T>& f) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = n; i >>= 1;) {
        for (const int j : rep(0, n)) {
            if (j & i) f[j] -= f[j & ~i];
        }
    }
}
