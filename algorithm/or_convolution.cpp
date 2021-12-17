#pragma once
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"
#include "subset_mobius_transform.cpp"
#include "subset_zeta_transform.cpp"

template <class T> std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    subset_zeta_transform(a);
    subset_zeta_transform(b);
    for (const int i : rep(0, a.size())) a[i] *= b[i];
    subset_mobius_transform(a);
    return a;
}
