#pragma once
#include "../utility/int_alias.cpp"
#include "../bit/ceil_log2.cpp"
#include <utility>
#include <vector>

template <class F>
class AutoRealloc {
    using R = typename decltype(std::declval<F>()((usize) 0))::value_type;
    
    F func;
    mutable std::vector<R> data;

public:
    template <class G>
    explicit AutoRealloc(G&& g): func(std::forward<G>(g)), data() { }
    
    void reserve(const usize size) const {
        if (data.size() < size) data = func(((usize) 1 << ceil_log2(size)));
    }
    R operator [] (const usize i) const {
        reserve(i + 1);
        return data[i];
    }
};

template <class G>
explicit AutoRealloc(G&&) -> AutoRealloc<std::decay_t<G>>;
