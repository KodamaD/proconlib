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
    \    file = data['main file']\n    command = data['compile command']\n    out\
    \ = 'verify'\n    subprocess.call(command.split(' ') + ['-o', out, file])\n  \
    \  precision = data['precision']\n    if precision > 0:\n        subprocess.call(['oj',\
    \ 't', '-c', './' + out, '-e', str(precision)])\n    else:\n        subprocess.call(['oj',\
    \ 't', '-c', './' + out])\n    os.remove(out)\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/verify.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/verify.py
layout: document
redirect_from:
- /library/tools/verify.py
- /library/tools/verify.py.html
title: tools/verify.py
---
