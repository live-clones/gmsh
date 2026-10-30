#!/bin/bash

# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Keeps the unstripped Gmsh library of a Windows dev build on the server, as
# gmsh.info/bin/Windows/debug/gmsh-VERSION-Windows64.dll.gz. The SDK and the
# Python wheel ship the stripped library, which has the same code at the same
# offsets, so the crash reports it prints (see SetCrashReport() in
# src/common/OS.cpp) are read against this one with symbolize_crash.py. Like the
# dev wheels, only the two most recent are kept.
#
# Run from the build directory, after "make package".

set -e

lib=$(ls gmsh-*.dll)
version=$(sed -n 's/^#define GMSH_VERSION *"\(.*\)"/\1/p' src/common/GmshVersion.h)
name=gmsh-${version}-Windows64.dll.gz
gzip -9 -c "${lib}" > "${name}"

ssh_opt="-o StrictHostKeyChecking=no -i /home/geuzaine/.ssh/id_rsa"
dir=.wwwgmsh/bin/Windows/debug
/usr/bin/ssh ${ssh_opt} geuzaine@gmsh.info "mkdir -p ${dir}"
/usr/bin/scp ${ssh_opt} "${name}" geuzaine@gmsh.info:${dir}/
/usr/bin/ssh ${ssh_opt} geuzaine@gmsh.info \
  "cd ${dir} && ls -t gmsh-*-Windows64.dll.gz | tail -n +3 | xargs rm -f"
