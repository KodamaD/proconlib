#pragma once
#include "rem_euclid.cpp"

template <class T> constexpr T div_floor(const T& x, const T& y) { return (x - rem_euclid(x, y)) / y; }
