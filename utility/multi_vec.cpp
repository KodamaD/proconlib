#pragma once
#include <type_traits>
#include <utility>
#include <vector>

namespace proconlib {

template <class T, int N, std::enable_if_t<(N != 0)>* = nullptr> struct MultiVecImpl {
    using type = std::vector<typename MultiVecImpl<T, N - 1>::type>;
};

template <class T> struct MultiVecImpl<T, 1> { using type = std::vector<T>; };

}  // namespace proconlib

template <class T, int N> using MultiVec = typename proconlib::MultiVecImpl<T, N>::type;

template <class T, class U> decltype(auto) make_vec(T&& size, U&& value) {
    using V = std::decay_t<U>;
    return std::vector<V>(std::forward<T>(size), std::forward<V>(value));
}

template <class T, class... Args> decltype(auto) make_vec(T&& size, Args&&... args) {
    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size),
                                                                        make_vec(std::forward<Args>(args)...));
}
