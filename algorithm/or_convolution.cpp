#pragma once
#include <vector>
#include <cassert>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../algorithm/subset_zeta_transform.cpp"
#include "../algorithm/subset_mobius_transform.cpp"

template <class T> std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    subset_zeta_transform(a);
    subset_zeta_transform(b);
    for (const usize i : rep(0, a.size())) a[i] *= b[i];
    subset_mobius_transform(a);
    return a;
}
