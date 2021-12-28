#pragma once
#include <cassert>
#include <vector>
#include "../traits/sum_group.cpp"
#include "../utility/rep.cpp"
#include "subset_mobius_transform.cpp"
#include "subset_zeta_transform.cpp"

template <class T> std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    subset_zeta_transform<SumGroup<T>>(a);
    subset_zeta_transform<SumGroup<T>>(b);
    for (const int i : rep(a.size())) a[i] *= b[i];
    subset_mobius_transform<SumGroup<T>>(a);
    return a;
}
