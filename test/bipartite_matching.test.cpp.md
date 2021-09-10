---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: proconlib/int_alias:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include \"../graph/dinic.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nint main() {\n    usize L, R, M;\n\
    \    std::cin >> L >> R >> M;\n    Dinic<usize> dinic;\n    const auto src = dinic.add_vertex();\n\
    \    const auto dst = dinic.add_vertex();\n    const auto left = dinic.add_vertices(L);\n\
    \    const auto right = dinic.add_vertices(R);\n    std::vector<Dinic<usize>::EdgePtr>\
    \ ptr(M);\n    for (const auto i : rep(0, L)) {\n        dinic.add_edge(src, left[i],\
    \ 1);\n    }\n    for (const auto i : rep(0, R)) {\n        dinic.add_edge(right[i],\
    \ dst, 1);\n    }\n    for (const auto i : rep(0, M)) {\n        usize a, b;\n\
    \        std::cin >> a >> b;\n        ptr[i] = dinic.add_edge(left[a], right[b],\
    \ 1);\n    }\n    std::cout << dinic.flow(src, dst) << '\\n';\n    for (const\
    \ auto i : rep(0, M)) {\n        if (ptr[i].flow() == 1) {\n            std::cout\
    \ << left.to_idx(ptr[i].src()) << ' ' << right.to_idx(ptr[i].dst()) << '\\n';\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/bipartite_matching.test.cpp
- /verify/test/bipartite_matching.test.cpp.html
title: test/bipartite_matching.test.cpp
---
