---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/binary_search.cpp\"\n#include <type_traits>\n#include\
    \ <cassert>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 5 \"utility/binary_search.cpp\"\n\ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\nT binary_search(T ok, T ng, const F& f) {\n    using U = std::make_unsigned_t<T>;\n\
    \    assert(ok != ng);\n    if (ok < ng) {\n        while (ok + 1 != ng) {\n \
    \           const T md = ok + T((U(ng) - U(ok)) >> 1);\n            (f(md) ? ok\
    \ : ng) = md;\n        }\n    } else {\n        while (ng + 1 != ok) {\n     \
    \       const T md = ng + T((U(ok) - U(ng)) >> 1);\n            (f(md) ? ok :\
    \ ng) = md;\n        }\n    }\n    return ok;\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <cassert>\n#include \"../utility/int_alias.cpp\"\
    \n\ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\n\
    T binary_search(T ok, T ng, const F& f) {\n    using U = std::make_unsigned_t<T>;\n\
    \    assert(ok != ng);\n    if (ok < ng) {\n        while (ok + 1 != ng) {\n \
    \           const T md = ok + T((U(ng) - U(ok)) >> 1);\n            (f(md) ? ok\
    \ : ng) = md;\n        }\n    } else {\n        while (ng + 1 != ok) {\n     \
    \       const T md = ng + T((U(ok) - U(ng)) >> 1);\n            (f(md) ? ok :\
    \ ng) = md;\n        }\n    }\n    return ok;\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/binary_search.cpp
  requiredBy: []
  timestamp: '2021-09-19 12:46:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/binary_search.cpp
layout: document
redirect_from:
- /library/utility/binary_search.cpp
- /library/utility/binary_search.cpp.html
title: utility/binary_search.cpp
---
