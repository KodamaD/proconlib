#!/usr/bin/env python3
import os
import json
import subprocess

with open('config.json', 'r') as config_file:
    data = json.load(config_file)
    file = data['main file']
    command = data['compile command']
    out = 'verify'
    subprocess.call(command.split(' ') + ['-o', out, file])
    precision = data['precision']
    if precision > 0:
        subprocess.call(['oj', 't', '-c', './' + out, '-e', str(precision)])
    else:
        subprocess.call(['oj', 't', '-c', './' + out])
    os.remove(out)
