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
  code: "#!/usr/bin/env python3\nimport sys\nimport os\nimport json\nimport subprocess\n\
    \nargs = sys.argv\n\nif len(args) <= 2:\n    print('Fatal error: directory name\
    \ or problem url is not specified')\n    sys.exit()\n\nproblem_url = args[1]\n\
    dir_name = args[2]\nprecision = 0\ninteractive = False\nmulti_testcase = False\n\
    \nidx = 3\nwhile idx < len(args):\n    if args[idx] == '-e':\n        precision\
    \ = int(args[idx + 1])\n        idx += 2\n    elif args[idx] == '-i':\n      \
    \  interactive = True\n        idx += 1\n    elif args[idx] == '-m':\n       \
    \ multi_testcase = True\n        idx += 1\n    else:\n        print('Fatal error:\
    \ unrecognized argument')\n        sys.exit()\n\ndir = './' + dir_name\nos.mkdir(dir)\n\
    os.chdir(dir)\n\ndata = dict()\ndata['url'] = problem_url\ndata['precision'] =\
    \ precision\ndata['main file'] = 'main.cpp'\ndata['compile command'] = 'g++ -std=gnu++17\
    \ -O2 -Wall -Wextra'\n\nwith open('config.json', 'w') as config_file:\n    json.dump(data,\
    \ config_file, indent=4)\n\nsubprocess.call([\"oj\", \"d\", data['url']])\n\n\
    tab = '    '\nfunc = dir_name + '_main()'\n\nwith open(data['main file'], 'w')\
    \ as main_file:\n    with open(\"../template.cpp\", 'r') as template:\n      \
    \  for line in template:\n            line = line.replace('dir_name_main()', func)\n\
    \            if line == tab + func + ';\\n':\n                if precision > 0:\n\
    \                    main_file.write(tab + 'std::cout << std::fixed << std::setprecision('\
    \ + str(precision + 5) + ');\\n')\n                if interactive:\n         \
    \           main_file.write(tab + 'std::cout << std::unitbuf;\\n')\n         \
    \       if multi_testcase:\n                    main_file.write(tab + 'usize cases;\\\
    n')\n                    main_file.write(tab + 'std::cin >> cases;\\n')\n    \
    \                main_file.write(tab + 'while (cases--) {\\n')\n             \
    \       main_file.write(tab + line)\n                    main_file.write(tab +\
    \ '}\\n')\n                else:\n                    main_file.write(line)\n\
    \            else:\n                main_file.write(line)\n\nsubprocess.call(['code',\
    \ '-a', 'main.cpp'])\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/new.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/new.py
layout: document
redirect_from:
- /library/tools/new.py
- /library/tools/new.py.html
title: tools/new.py
---
