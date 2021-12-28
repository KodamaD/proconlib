#pragma once
#include "factorize_iter.cpp"

template <class T> constexpr T totient(T x) {
    T ret = x;
    for (const auto& p : factorize_iter(x)) {
        ret /= p.first;
        ret *= p.first - 1;
    }
    return ret;
}