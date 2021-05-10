#pragma once
#include "../utility/int_alias.cpp"
#include <tuple>
#include <type_traits>
#include <utility>
#include <map>

template <class F>
class AutoMemoization {
    template <class> 
    struct GetSig;
    template <class T, class R, class S, class... Args>
    struct GetSig<R (T::*)(S, Args...) const> {
        using Ret = R;
        using Tuple = std::tuple<Args...>;
    };

    using Sig = GetSig<decltype(&F::template operator()<AutoMemoization<F>&>)>;
    using R = typename Sig::Ret;
    using Tuple = typename Sig::Tuple;

    F func;
    mutable std::map<Tuple, R> data;

    template <usize... I>
    R apply(const Tuple& args_tuple, std::index_sequence<I...>) const {
        return func(*this, std::get<I>(args_tuple)...);
    }

public:
    explicit AutoMemoization(F&& f): func(std::forward<F>(f)) { }

    template <class... Args>
    R operator () (Args&&... args) const {
        Tuple tup(std::forward<Args>(args)...);
        const auto itr = data.find(tup);
        if (itr != data.end()) return itr -> second;
        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());
        data.emplace(std::move(tup), ret);
        return ret;
    }
};

template <class F>
decltype(auto) auto_memoize(F&& f) {
    using G = std::decay_t<F>;
    return AutoMemoization<G>(std::forward<G>(f));
}