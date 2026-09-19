#!/usr/bin/env python3
# Builds the picking driver (pick.cpp) of the graphics tests against a Gmsh
# build directory with the GUI and the shared library (make gmsh shared):
#
#   python3 build_pick.py [build directory] [output directory]
#
# (by default ../../bin and ./out); run.py --pick then runs it from the
# output directory.

import os
import re
import shlex
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
build = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else
                        os.path.join(HERE, '..', '..', 'bin'))
out = os.path.abspath(sys.argv[2] if len(sys.argv) > 2 else
                      os.path.join(HERE, 'out'))
cache = open(os.path.join(build, 'CMakeCache.txt')).read()


def cached(name):
    m = re.search('^%s:[A-Z]+=(.*)$' % name, cache, re.M)
    return m.group(1) if m else ''


src = cached('CMAKE_HOME_DIRECTORY')
cxx = cached('CMAKE_CXX_COMPILER') or 'c++'
fltk = cached('FLTK_CONFIG_SCRIPT') or 'fltk-config'
flags = ['-std=c++17', '-O1', '-Wno-deprecated-declarations']
flags += ['-I' + os.path.join(src, d) for d in
          ('api', 'src/fltk', 'src/common', 'src/graphics', 'src/geo',
           'src/numeric', 'src/post', 'src/mesh', 'contrib/eigen')]
flags += ['-I' + os.path.join(build, 'src', 'common')]
flags += shlex.split(subprocess.run([fltk, '--use-gl', '--cxxflags'],
                                    capture_output=True, text=True).stdout)
libs = ['-L' + build, '-lgmsh', '-Wl,-rpath,' + build]
libs += shlex.split(subprocess.run([fltk, '--use-gl', '--ldflags'],
                                   capture_output=True, text=True).stdout)
os.makedirs(out, exist_ok=True)
cmd = [cxx] + flags + [os.path.join(HERE, 'pick.cpp'), '-o',
                       os.path.join(out, 'pick')] + libs
sys.exit(subprocess.run(cmd).returncode)
