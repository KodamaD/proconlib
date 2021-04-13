#pragma once
#include <utility>
#include <type_traits>

template <class F>
struct RecLambda: private F {
    template <class G>
    explicit constexpr RecLambda(G&& g): F(std::forward<G>(g)) { }
    template <class... Args>
    constexpr decltype(auto) operator () (Args&&... args) const {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};

template <class G>
explicit RecLambda(G&&) -> RecLambda<std::decay_t<G>>;
