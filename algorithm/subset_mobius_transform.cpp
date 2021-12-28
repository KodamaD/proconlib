#pragma once
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"

template <class G> void subset_mobius_transform(std::vector<typename G::Type>& f) {
    const int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = n; i >>= 1;)
        for (const int j : rep(n))
            if (j & i) f[j] = G::operation(G::inverse(f[j & ~i]), f[j]);
}
