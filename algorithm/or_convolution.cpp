#pragma once
#include <cassert>
#include <vector>
#include "../utility/rep.cpp"
#include "subset_mobius_transform.cpp"
#include "subset_zeta_transform.cpp"

template <class R>
std::vector<typename R::Type> or_convolution(std::vector<typename R::Type> a, std::vector<typename R::Type> b) {
    assert(a.size() == b.size());
    subset_zeta_transform<typename R::Sum>(a);
    subset_zeta_transform<typename R::Sum>(b);
    for (const int i : rep(a.size())) a[i] = R::Product::operation(a[i], b[i]);
    subset_mobius_transform<typename R::Sum>(a);
    return a;
}
