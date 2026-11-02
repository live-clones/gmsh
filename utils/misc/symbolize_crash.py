#!/usr/bin/env python3

# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Turns the frames of a Gmsh crash report on Windows (see SetCrashReport() in
# src/common/OS.cpp) into functions, files and lines:
#
#   symbolize_crash.py gmsh-crash-report.txt [library]
#
# The library must be the unstripped one of the very build that crashed. The
# Windows dev builds keep it on the server (see upload_debug_library.sh), from
# where it is downloaded when none is given; it can also be given as a file,
# gzipped or not. Needs llvm-addr2line (e.g. Homebrew's llvm) or the MinGW
# addr2line.

import gzip
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import urllib.request


def image_base(path):
    # the address the library is linked at, from its PE header
    with open(path, 'rb') as f:
        head = f.read(4096)
    pe = struct.unpack_from('<I', head, 0x3c)[0]
    opt = pe + 24
    if struct.unpack_from('<H', head, opt)[0] == 0x20b:  # PE32+
        return struct.unpack_from('<Q', head, opt + 24)[0]
    return struct.unpack_from('<I', head, opt + 28)[0]


def find_tool():
    for t in ['llvm-addr2line', '/opt/homebrew/opt/llvm/bin/llvm-addr2line',
              '/usr/local/opt/llvm/bin/llvm-addr2line',
              'x86_64-w64-mingw32-addr2line']:
        if shutil.which(t):
            return t
    sys.exit('Need llvm-addr2line or x86_64-w64-mingw32-addr2line')


URL = 'https://gmsh.info/bin/Windows/debug/gmsh-%s-Windows64.dll.gz'


def main():
    if len(sys.argv) not in [2, 3]:
        sys.exit('Usage: symbolize_crash.py report.txt [library]')
    text = open(sys.argv[1], errors='replace').read()
    # the report names the build: the library must be of the same one
    m = re.search(r'Gmsh (\S+) crash report', text)
    version = m.group(1) if m else None

    tmp = tempfile.TemporaryDirectory()
    if len(sys.argv) == 3:
        lib = sys.argv[2]
    elif version:
        lib = os.path.join(tmp.name, os.path.basename(URL % version))
        print('Downloading %s' % (URL % version))
        try:
            urllib.request.urlretrieve(URL % version, lib)
        except Exception as e:
            sys.exit('Could not download the library of %s (%s): only the two '
                     'most recent dev builds are kept' % (version, e))
    else:
        sys.exit('No Gmsh version in the report: give the library')
    if lib.endswith('.gz'):
        out = os.path.join(tmp.name, 'gmsh.dll')
        with gzip.open(lib, 'rb') as f, open(out, 'wb') as g:
            shutil.copyfileobj(f, g)
        lib = out

    if version:
        with open(lib, 'rb') as f:
            if version.encode() not in f.read():
                print('Warning: the library is not of the build of the report '
                      '(%s): the lines below are wrong' % version)

    frames = re.findall(r'#\s*(\d+)\s+(\S+)\+0x([0-9a-fA-F]+)', text)
    base = image_base(lib)
    wanted = []
    for i, module, offset in frames:
        # the frames of the Gmsh library (gmsh-5.0.dll), or of the executable
        # given in its place
        if (re.match(r'gmsh-[\d.]+\.dll$', module, re.I) or
            module.lower() == os.path.basename(sys.argv[-1]).lower()):
            # a return address points after the call: the line of the call
            # is that of the byte before
            addr = base + int(offset, 16) - (1 if int(i) > 0 else 0)
            wanted.append((i, addr))
    if not wanted:
        sys.exit('No frame of the Gmsh library in the report')

    out = subprocess.run([find_tool(), '-e', lib, '-f', '-C', '-i', '-a'] +
                         ['0x%x' % a for _, a in wanted],
                         capture_output=True, text=True).stdout.splitlines()
    # for each address: its line, then a function and a location per frame
    # (more than one where functions were inlined)
    results, current = {}, None
    for line in out:
        if re.match(r'^0x[0-9a-fA-F]+$', line):
            current = int(line, 16)
            results[current] = []
        elif current is not None:
            results[current].append(line)
    for i, addr in wanted:
        r = results.get(addr, [])
        pairs = [(r[k], r[k + 1]) for k in range(0, len(r) - 1, 2)]
        for k, (func, loc) in enumerate(pairs):
            loc = re.sub(r'^.*/src/', 'src/', loc)
            print('#%-3s %s\n       %s' % (i if k == 0 else '', func, loc))


if __name__ == '__main__':
    main()
