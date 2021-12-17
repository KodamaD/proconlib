#pragma once
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"

template <class T> void superset_zeta_transform(std::vector<T>& f) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (const int j : rep(0, n)) {
            if (j & i) f[j & ~i] += f[j];
        }
    }
}
