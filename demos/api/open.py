#!/usr/bin/env python

from gmsh import *
import sys

if len(sys.argv) < 2:
    print "Usage: " + sys.argv[0] + " file.geo [options]"
    exit(0)

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)
gmshOpen(sys.argv[1])
gmshModelMesh(3)
gmshExport("test.msh")
gmshFinalize()

