# -*- coding: utf-8 -*-
# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

import os
import hashlib
import shutil
import sys
import re
import glob
import tempfile

wheel_text="""Wheel-Version: 1.0
Generator: gmsh_wheel
Root-Is-Purelib: true
Tag: py2-none-PLATNAME
Tag: py3-none-PLATNAME
"""

sdk_dir = sys.argv[1]
plat_name = sys.argv[2]
setup_dir = os.path.dirname(__file__)

dist_info_dir = glob.glob(os.path.join(sdk_dir, 'lib', 'gmsh*.dist-info'))[0]
dist_info_dir = dist_info_dir[len(os.path.join(sdk_dir, 'lib', '')):]
match = re.match('(.*)-(.*)\.dist-info', dist_info_dir)
name = match.group(1)
version = match.group(2)

wheel_name = "-".join([name, version ,'py2.py3', 'none', plat_name])

libversion = ".".join(version.split(".")[:2])

with tempfile.TemporaryDirectory() as wheel_dir:
    data_dir = os.path.join(wheel_dir, f'gmsh-{version}.data')

    os.makedirs(os.path.join(data_dir, 'data', 'lib'))
    os.makedirs(os.path.join(data_dir, 'scripts'))
    os.makedirs(os.path.join(wheel_dir, dist_info_dir))

    shutil.copytree(os.path.join(sdk_dir, 'share'),
                    os.path.join(data_dir, 'data', 'share'))
    shutil.copytree(os.path.join(sdk_dir, 'include'),
                    os.path.join(data_dir, 'data', 'include'))
    shutil.copy(os.path.join(sdk_dir, 'lib', 'gmsh.py'),
                wheel_dir)
    shutil.copy(os.path.join(setup_dir, 'gmsh'),
                os.path.join(wheel_dir, data_dir, 'scripts'))

    if os.path.isfile(os.path.join(sdk_dir, 'lib', f'gmsh-{libversion}.dll')):
        shutil.copy(os.path.join(sdk_dir, 'lib', f'gmsh-{libversion}.dll'),
                    os.path.join(data_dir, 'data', 'lib'))
        shutil.copy(os.path.join(sdk_dir, 'lib', 'gmsh.lib'),
                    os.path.join(data_dir, 'data', 'lib'))
        shutil.copy(os.path.join(setup_dir, "gmsh.bat"),
                    os.path.join(data_dir, 'scripts'))
    elif os.path.isfile(os.path.join(sdk_dir, 'lib', f'libgmsh.so.{libversion}')):
        shutil.copy(os.path.join(sdk_dir, 'lib', f'libgmsh.so.{libversion}'),
                    os.path.join(data_dir, 'data', 'lib'))
    elif os.path.isfile(os.path.join(sdk_dir, 'lib', f'libgmsh.{libversion}.dylib')):
        shutil.copy(os.path.join(sdk_dir, 'lib', f'libgmsh.{libversion}.dylib'),
                    os.path.join(data_dir, 'data', 'lib'))
    else :
        print('library not found')
        exit(1)

    shutil.copy(os.path.join(sdk_dir, 'lib', 'gmsh.jl'),
                os.path.join(data_dir, 'data', 'lib'))

    shutil.copy(os.path.join(sdk_dir, 'lib', dist_info_dir, 'METADATA'),
                os.path.join(wheel_dir, dist_info_dir))

    # WHEEL
    with open(os.path.join(wheel_dir, dist_info_dir, 'WHEEL'), 'w') as f:
        f.write(wheel_text.replace('PLATNAME', plat_name))

    # top_level.txt
    with open(os.path.join(wheel_dir,dist_info_dir,'top_level.txt'), 'w') as f:
        f.write("\n")

    # RECORD
    records = []
    for dirpath, dirs, files in os.walk(wheel_dir):
        for fname in files:
            fpath = os.path.join(dirpath, fname)
            with open(fpath, "rb") as f:
                content = f.read()
                checksum = hashlib.sha256(content).hexdigest()
                length = len(content)
                relpath = os.path.relpath(fpath, wheel_dir)
                records.append(f'{relpath},sha256={checksum},{length}')

    with open(os.path.join(wheel_dir, dist_info_dir, 'RECORD'), 'w') as f:
        for r in records:
            f.write(r+"\n")
        relpath = os.path.join(dist_info_dir, 'RECORD')
        f.write(f'{relpath},,\n')

    # zip
    shutil.make_archive(wheel_name, 'zip', wheel_dir)
    shutil.move(f'{wheel_name}.zip', f'{wheel_name}.whl')
    print(f'{wheel_name}.whl successfully built.')
