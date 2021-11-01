#pragma once
#include <numeric>
#include <vector>
#include "../random/shuffle_vec.cpp"
#include "../utility/int_alias.cpp"

template <class T> std::vector<T> rand_perm(const usize n, const T& first = 0) {
    std::vector<T> p(n);
    std::iota(p.begin(), p.end(), first);
    shuffle_vec(p);
    return p;
}