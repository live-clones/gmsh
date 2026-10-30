#!/usr/bin/env python3

# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Turns the frames of a Gmsh crash report on Windows (see SetCrashReport() in
# src/common/OS.cpp) into functions, files and lines:
#
#   symbolize_crash.py gmsh-crash-report.txt path/to/gmsh-5.0.dll
#
# The library must be the unstripped one of the very build that crashed: the
# dev SDK, or the dev Python wheel made from it, of the commit the report
# names. Needs llvm-addr2line (e.g. Homebrew's llvm) or the MinGW addr2line.

import os
import re
import shutil
import struct
import subprocess
import sys


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


def main():
    if len(sys.argv) != 3:
        sys.exit('Usage: symbolize_crash.py report.txt library.dll')
    report, lib = sys.argv[1], sys.argv[2]
    text = open(report, errors='replace').read()

    # the report names the build: the library must be of the same one
    m = re.search(r'Gmsh (\S+) crash report', text)
    if m:
        with open(lib, 'rb') as f:
            if m.group(1).encode() not in f.read():
                print('Warning: %s is not of the build of the report (%s): '
                      'the lines below are wrong' % (lib, m.group(1)))

    frames = re.findall(r'#\s*(\d+)\s+(\S+)\+0x([0-9a-fA-F]+)', text)
    base = image_base(lib)
    name = os.path.basename(lib).lower()
    wanted = []
    for i, module, offset in frames:
        if module.lower() == name:
            # a return address points after the call: the line of the call
            # is that of the byte before
            addr = base + int(offset, 16) - (1 if int(i) > 0 else 0)
            wanted.append((i, addr))
    if not wanted:
        sys.exit('No frame of %s in the report' % name)

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
