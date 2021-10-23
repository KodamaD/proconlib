#pragma once
#include "../random/rand_real.cpp"

template <class T> bool rand_bool(const T& prob) { return rand_real<T>(0, 1) < prob; }