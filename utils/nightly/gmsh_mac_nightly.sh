#!/bin/sh

# this is supposed to be called by launchd:
#  * copy org.geuz.gmsh.nightly.plist to ~/Library/LauchAgents/
#  * launchctl load ~/Library/LaunchAgents/org.geuz.gmsh.nightly.plist

cd ${HOME}/src/gmsh/utils/nightly && /usr/local/bin/ctest -S gmsh_mac_nightly.ctest -VV > ${HOME}/src/gmsh/nightly.log 2>&1
