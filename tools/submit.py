#!/usr/bin/env python3
import os
import json
import subprocess

with open('config.json', 'r') as config_file:
    data = json.load(config_file)
    file = data['main file']
    with open('temporary.cpp', 'w') as temporary:
        subprocess.call(['oj-bundle', '-I', '/Users/kodamankod/Desktop/CppProcon/Library/proconlib/', '-I',  '/Users/kodamankod/Desktop/CppProcon/Library/ac-library', file], stdout=temporary)
    with open('temporary.cpp', 'r') as temporary, open('submission.cpp', 'w') as submission:
        for line in temporary:
            if '#line' not in line:
                submission.write(line)
        url = data['url']
    subprocess.call(['oj', 's', url, 'submission.cpp'])
    os.remove('temporary.cpp')
    os.remove('submission.cpp')
