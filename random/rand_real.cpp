#pragma once
#include <random>
#include "xorshift.cpp"

template <class T> T rand_real(const T& min, const T& max) {
    static std::default_random_engine gen(xorshift());
    return std::uniform_real_distribution<T>(min, max)(gen);
}