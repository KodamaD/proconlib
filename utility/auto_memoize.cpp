#pragma once
#include "../utility/int_alias.cpp"
#include <tuple>
#include <type_traits>
#include <utility>
#include <map>

template <class F>
class AutoMemoize {
    template <class> 
    struct GetSig;
    template <class T, class R, class S, class... Args>
    struct GetSig<R (T::*)(S, Args...) const> {
        using Ret = R;
        using Tuple = std::tuple<Args...>;
    };

    using Sig = GetSig<decltype(&F::template operator()<AutoMemoize<F>&>)>;
    using R = typename Sig::Ret;
    using Tuple = typename Sig::Tuple;

    F func;
    mutable std::map<Tuple, R> data;

    template <usize... I>
    R apply(const Tuple& args_tuple, std::index_sequence<I...>) const {
        return func(*this, std::get<I>(args_tuple)...);
    }

public:
    template <class G>
    explicit AutoMemoize(G&& g): func(std::forward<G>(g)) { }

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

template <class G>
explicit AutoMemoize(G&&) -> AutoMemoize<std::decay_t<G>>;
