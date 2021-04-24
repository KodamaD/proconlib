#pragma once
#include "../utility/int_alias.cpp"
#include <vector>
#include <type_traits>
#include <utility>

template <class T, usize N, std::enable_if_t<(N != 0)>* = nullptr>
struct MultiVecImpl {
    using type = std::vector<typename MultiVecImpl<T, N - 1>::type>;
};

template <class T>
struct MultiVecImpl<T, 1> {
    using type = std::vector<T>;
};

template <class T, usize N>
using MultiVec = typename MultiVecImpl<T, N>::type;

template <class T, class U>
std::vector<U> make_vec(T&& size, U&& value) {
    return std::vector<U>(std::forward<T>(size), std::forward<U>(value));
}

template <class T, class... Args>
decltype(auto) make_vec(T&& size, Args&&... args) {
    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size), make_vec(std::forward<Args>(args)...));
}
