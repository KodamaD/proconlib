#pragma once
#include <vector>
#include <cassert>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class T> void superset_zeta_transform(std::vector<T>& f) {
    const usize n = f.size();
    assert((n & (n - 1)) == 0);
    for (usize i = 1; i < n; i <<= 1) {
        for (const usize j : rep(0, n)) {
            if (j & i) f[j & ~i] += f[j];
        }
    }
}
