#pragma once
#include "../utility/int_alias.cpp"
#include <array>
#include <type_traits>

template <class T, usize N, usize... Seq>
struct MultiArrayImpl {
  using type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;
};

template <class T, usize N>
struct MultiArrayImpl<T, N> {
  using type = std::array<T, N>;
};

template <class T, usize N, usize... Seq>
using MultiArray = typename MultiArrayImpl<T, N, Seq...>::type; 
