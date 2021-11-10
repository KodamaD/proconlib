#pragma once
#include <vector>
#include <cassert>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "superset_zeta_transform.cpp"
#include "superset_mobius_transform.cpp"

template <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size());
    superset_zeta_transform(a);
    superset_zeta_transform(b);
    for (const usize i : rep(0, a.size())) a[i] *= b[i];
    superset_mobius_transform(a);
    return a;
}
