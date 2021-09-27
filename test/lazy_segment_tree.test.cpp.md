---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/affine_composite_monoid.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../container/lazy_segment_tree.cpp\"\n#include <iostream>\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../utility/affine_composite_monoid.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../traits/pair_monoid.cpp\"\
    \n#include \"../traits/plus_monoid.cpp\"\n#include \"../utility/rep.cpp\"\n\n\
    using Fp = StaticModint<998244353>;\n\nstruct SumAffine {\n    using Monoid =\
    \ PairMonoid<PlusMonoid<Fp>, PlusMonoid<usize>>;\n    using Effector = AffineCompositeMonoid<Fp>;\n\
    \    static constexpr std::pair<Fp, usize> operation(const std::pair<Fp, usize>&\
    \ m, const Affine<Fp>& e) {\n        return {e.a * m.first + e.b * m.second, m.second};\n\
    \    }\n};\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<Fp,\
    \ usize>> initial(N);\n    for (const usize i : rep(0, N)) {\n        u32 a;\n\
    \        std::cin >> a;\n        initial[i] = {a, 1};\n    }\n    LazySegmentTree<SumAffine>\
    \ seg(initial);\n    while (Q--) {\n        usize t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            usize l, r;\n            std::cin >> l >>\
    \ r;\n            u32 b, c;\n            std::cin >> b >> c;\n            seg.operate(l,\
    \ r, {Fp(b), Fp(c)});\n        } else {\n            usize l, r;\n           \
    \ std::cin >> l >> r;\n            std::cout << seg.fold(l, r).first << '\\n';\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_segment_tree.test.cpp
- /verify/test/lazy_segment_tree.test.cpp.html
title: test/lazy_segment_tree.test.cpp
---
