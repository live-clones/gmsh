#!/bin/sh

GMSH_BUNDLE="`echo "$0" | sed -e 's/\/Contents\/MacOS\/Gmsh//'`"
GMSH_RESOURCES="$GMSH_BUNDLE/Contents/Resources"
exec $GMSH_RESOURCES/bin/gmsh
