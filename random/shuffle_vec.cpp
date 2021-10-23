#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include "../random/xorshift.cpp"

template <class T> void shuffle_vec(std::vector<T>& v) {
    static std::default_random_engine gen(xorshift());
    std::shuffle(v.begin(), v.end(), gen);
}