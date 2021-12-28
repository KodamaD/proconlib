#pragma once
#include <cassert>
#include <vector>
#include "../traits/sum_group.cpp"
#include "../utility/rep.cpp"
#include "superset_mobius_transform.cpp"
#include "superset_zeta_transform.cpp"

template <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    superset_zeta_transform<SumGroup<T>>(a);
    superset_zeta_transform<SumGroup<T>>(b);
    for (const int i : rep(a.size())) a[i] *= b[i];
    superset_mobius_transform<SumGroup<T>>(a);
    return a;
}
