#!/usr/bin/env python3
import sys
import os
import json
import subprocess

args = sys.argv

if len(args) <= 2:
    print('Fatal error: directory name or problem url is not specified')
    sys.exit()

problem_url = args[1]
dir_name = args[2]
precision = 0
interactive = False
multi_testcase = False

idx = 3
while idx < len(args):
    if args[idx] == '-e':
        precision = int(args[idx + 1])
        idx += 2
    elif args[idx] == '-i':
        interactive = True
        idx += 1
    elif args[idx] == '-m':
        multi_testcase = True
        idx += 1
    else:
        print('Fatal error: unrecognized argument')
        sys.exit()

dir = './' + dir_name
os.mkdir(dir)
os.chdir(dir)

data = dict()
data['url'] = problem_url
data['precision'] = precision
data['main file'] = 'main.cpp'
data['compile command'] = 'g++ -std=gnu++17 -O2 -Wall -Wextra'

with open('config.json', 'w') as config_file:
    json.dump(data, config_file, indent=4)

subprocess.call(["oj", "d", data['url']])

tab = '    '
func = dir_name + '_main()'

with open(data['main file'], 'w') as main_file:
    with open("../template.cpp", 'r') as template:
        for line in template:
            line = line.replace('dir_name_main()', func)
            if line == tab + func + ';\n':
                if precision > 0:
                    main_file.write(tab + 'std::cout << std::fixed << std::setprecision(' + str(precision + 5) + ');\n')
                if interactive:
                    main_file.write(tab + 'std::cout << std::unitbuf;\n')
                if multi_testcase:
                    main_file.write(tab + 'usize cases;\n')
                    main_file.write(tab + 'std::cin >> cases;\n')
                    main_file.write(tab + 'while (cases--) {\n')
                    main_file.write(tab + line)
                    main_file.write(tab + '}\n')
                else:
                    main_file.write(line)
            else:
                main_file.write(line)

subprocess.call(['code', '-a', 'main.cpp'])
