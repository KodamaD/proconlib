#pragma once
#include <cassert>
#include <type_traits>

template <class T, class F, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
T binary_search(T ok, T ng, const F& f) {
    using U = std::make_unsigned_t<T>;
    assert(ok != ng);
    if (ok < ng) {
        while (ok + 1 != ng) {
            const T md = ok + T((U(ng) - U(ok)) >> 1);
            (f(md) ? ok : ng) = md;
        }
    } else {
        while (ng + 1 != ok) {
            const T md = ng + T((U(ok) - U(ng)) >> 1);
            (f(md) ? ok : ng) = md;
        }
    }
    return ok;
}