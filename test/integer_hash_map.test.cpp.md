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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../container/int_alias.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../container/int_alias.cpp\"\n#include \"../container/integer_hash_map.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize Q;\n    std::cin >> Q;\n    IntegerHashMap<u64,\
    \ u64> map;\n    while (Q--) {\n        char c;\n        u64 k;\n        std::cin\
    \ >> c >> k;\n        if (c == '0') {\n            u64 v;\n            std::cin\
    \ >> v;\n            map[k] = v;\n        } else {\n            std::cout << map[k]\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/integer_hash_map.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/integer_hash_map.test.cpp
layout: document
redirect_from:
- /verify/test/integer_hash_map.test.cpp
- /verify/test/integer_hash_map.test.cpp.html
title: test/integer_hash_map.test.cpp
---
