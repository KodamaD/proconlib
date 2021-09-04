#pragma once
#include <random>
#include "../random/xorshift.cpp"

template <class T> T rand_int(const T& min, const T& max) {
    static std::default_random_engine gen(xorshift());
    return std::uniform_int_distribution<T>(min, max)(gen);
}