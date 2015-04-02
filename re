#!/usr/bin/env python
"""Remmina session quick starter.

Find first remmina connection which name include all script arguments.
"""

__author__ = 'Oleg Selivanov <oleg.a.selivanov@gmail.com>'

import ConfigParser
import subprocess
import sys
from glob import glob
from os import path

matched = lambda name: all(map(
    lambda s: s.lower() in name.lower(), sys.argv[1:]))

if __name__ == '__main__':
    for filename in glob(path.expanduser('~/.remmina/*.remmina')):
        config = ConfigParser.ConfigParser()
        config.read(filename)
        name = config.get('remmina', 'name')
        if matched(name):
            subprocess.call(' '.join(['remmina', '-c', filename]), shell=True)
            sys.exit(0)
