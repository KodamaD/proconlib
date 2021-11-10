#pragma once
#include <algorithm>
#include <random>
#include <vector>
#include "xorshift.cpp"

template <class C> void shuffle_vec(C& v) {
    static std::default_random_engine gen(xorshift());
    std::shuffle(v.begin(), v.end(), gen);
}