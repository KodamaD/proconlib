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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/reversed_monoid.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../container/queue_aggregation.cpp\"\n#include <iostream>\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../utility/int_alias.cpp\"\n#include\
    \ \"../traits/affine_composite_monoid.cpp\"\n\nusing Fp = Modint998244353;\n\n\
    int main() {\n    std::ios_base::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    usize Q;\n    std::cin >> Q;\n    QueueAggregation<AffineCompositeMonoid<Fp>>\
    \ que;\n    while (Q--) {\n        usize t;\n        std::cin >> t;\n        if\
    \ (t == 0) {\n            u32 a, b;\n            std::cin >> a >> b;\n       \
    \     que.push(Affine<Fp>(Fp(a), Fp(b)));\n        } else if (t == 1) {\n    \
    \        que.pop();\n        } else {\n            u32 x;\n            std::cin\
    \ >> x;\n            std::cout << que.fold().eval(Fp(x)) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/queue_aggregation.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/queue_aggregation.test.cpp
layout: document
redirect_from:
- /verify/test/queue_aggregation.test.cpp
- /verify/test/queue_aggregation.test.cpp.html
title: test/queue_aggregation.test.cpp
---
