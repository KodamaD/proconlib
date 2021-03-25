---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nimport os\nimport json\nimport subprocess\n\nwith\
    \ open('config.json', 'r') as config_file:\n    data = json.load(config_file)\n\
    \    file = data['main file']\n    with open('temporary.cpp', 'w') as temporary:\n\
    \        subprocess.call(['oj-bundle', '-I', '/Users/kodamankod/Desktop/CppProcon/Library/proconlib/',\
    \ '-I',  '/Users/kodamankod/Desktop/CppProcon/Library/ac-library', file], stdout=temporary)\n\
    \    with open('temporary.cpp', 'r') as temporary, open('submission.cpp', 'w')\
    \ as submission:\n        for line in temporary:\n            if '#line' not in\
    \ line:\n                submission.write(line)\n        url = data['url']\n \
    \   subprocess.call(['oj', 's', url, 'submission.cpp'])\n    os.remove('temporary.cpp')\n\
    \    os.remove('submission.cpp')\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/submit.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/submit.py
layout: document
redirect_from:
- /library/tools/submit.py
- /library/tools/submit.py.html
title: tools/submit.py
---
