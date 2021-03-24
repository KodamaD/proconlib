#pragma once
#include <limits>

template <class T, T Div = 2>
constexpr T INFTY = std::numeric_limits<T>::max() / Div;