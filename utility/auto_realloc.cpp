#pragma once
#include <utility>
#include <vector>
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"

template <class F> class AutoReallocation {
    using R = typename decltype(std::declval<F>()((usize)0))::value_type;

    F func;
    mutable std::vector<R> data;

  public:
    explicit AutoReallocation(F&& f) : func(std::move(f)), data() {}

    void reserve(const usize size) const {
        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));
    }
    R operator[](const usize i) const {
        reserve(i + 1);
        return data[i];
    }
};

template <class F> decltype(auto) auto_realloc(F&& f) { return AutoReallocation<F>(std::move(f)); }
