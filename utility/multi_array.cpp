#pragma once
#include <array>
#include <type_traits>

namespace proconlib {

template <class T, int N, int... Seq> struct MultiArrayImpl {
    using type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;
};

template <class T, int N> struct MultiArrayImpl<T, N> { using type = std::array<T, N>; };

}  // namespace proconlib

template <class T, int N, int... Seq> using MultiArray = typename proconlib::MultiArrayImpl<T, N, Seq...>::type;
