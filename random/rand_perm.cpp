#pragma once
#include <numeric>
#include <vector>
#include "shuffle_vec.cpp"

template <class T> std::vector<T> rand_perm(const int n, const T& first = 0) {
    std::vector<T> p(n);
    std::iota(p.begin(), p.end(), first);
    shuffle_vec(p);
    return p;
}