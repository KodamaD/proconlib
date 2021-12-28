#pragma once
#include <utility>
#include <vector>
#include "../math/factorize_iter.cpp"
#include "../utility/collect.cpp"

template <class T> std::vector<std::pair<T, int>> factorize(const T& x) { return collect(factorize_iter(x)); }
