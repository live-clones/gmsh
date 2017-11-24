#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t2.geo in Python. Comments focus on the new
# API functions used, compared to the ones introduced in t1.py.

import gmsh
import sys

# If sys.argv is passed, Gmsh will parse the commandline in the same way as the
# standalone Gmsh code.
gmsh.initialize(sys.argv)

gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t2")

# Copied from t1.py...
lc = 1e-2
gmsh.modelGeoAddPoint(0, 0, 0, lc, 1)
gmsh.modelGeoAddPoint(.1, 0,  0, lc, 2)
gmsh.modelGeoAddPoint(.1, .3, 0, lc, 3)
gmsh.modelGeoAddPoint(0, .3, 0, lc, 4)
gmsh.modelGeoAddLine(1, 2, 1)
gmsh.modelGeoAddLine(3, 2, 2)
gmsh.modelGeoAddLine(3, 4, 3)
gmsh.modelGeoAddLine(4, 1, 4)
gmsh.modelGeoAddLineLoop([4, 1, -2, 3], 1)
gmsh.modelGeoAddPlaneSurface([1], 1)
gmsh.modelAddPhysicalGroup(0, [1, 2], 1)
gmsh.modelAddPhysicalGroup(1, [1, 2], 2)
gmsh.modelAddPhysicalGroup(2, [1], 6)
gmsh.modelSetPhysicalName(2, 6, "My surface")
# ...end of copy

gmsh.modelGeoAddPoint(0, .4, 0, lc, 5)
gmsh.modelGeoAddLine(4, 5, 5)

# Geometrical transformations take a vector of pairs of integers as first
# argument, which contains the list of entities, represented by (dimension, tag)
# pairs. Here we thus translate point 3 (dimension=0, tag=3), by dx=-0.05, dy=0,
# dz=0.
gmsh.modelGeoTranslate([(0, 3)], -0.05, 0, 0)

# The "Duplicata" functionality in .geo files is handled by
# gmsh.modelGeoCopy(), which takes a vector of (dim, tag) pairs as input, and
# returns another vector of (dim, tag) pairs.

ov = gmsh.PairVector()
gmsh.modelGeoCopy([(0, 3)], ov)
gmsh.modelGeoTranslate(ov, 0, 0.1, 0)

gmsh.modelGeoAddLine(3, ov[0][1], 7)
gmsh.modelGeoAddLine(ov[0][1], 5, 8)
gmsh.modelGeoAddLineLoop([5,-8,-7,3], 10)
gmsh.modelGeoAddPlaneSurface([10], 11)

gmsh.modelGeoCopy([(2, 1), (2, 11)], ov)
gmsh.modelGeoTranslate(ov, 0.12, 0, 0)

print "New surfaces " + str(ov[0][1]) + " and " + str(ov[1][1])

gmsh.modelGeoAddPoint(0., 0.3, 0.13, lc, 100)
gmsh.modelGeoAddPoint(0.08, 0.3, 0.1, lc, 101)
gmsh.modelGeoAddPoint(0.08, 0.4, 0.1, lc, 102)
gmsh.modelGeoAddPoint(0., 0.4, 0.13, lc, 103)

gmsh.modelGeoAddLine(4, 100, 110)
gmsh.modelGeoAddLine(3, 101, 111)
gmsh.modelGeoAddLine(6, 102, 112)
gmsh.modelGeoAddLine(5, 103, 113)
gmsh.modelGeoAddLine(103, 100, 114)
gmsh.modelGeoAddLine(100, 101, 115)
gmsh.modelGeoAddLine(101, 102, 116)
gmsh.modelGeoAddLine(102, 103, 117)

gmsh.modelGeoAddLineLoop([115, -111, 3, 110], 118)
gmsh.modelGeoAddPlaneSurface([118], 119)
gmsh.modelGeoAddLineLoop([111, 116, -112, -7], 120)
gmsh.modelGeoAddPlaneSurface([120], 121)
gmsh.modelGeoAddLineLoop([112, 117, -113, -8], 122)
gmsh.modelGeoAddPlaneSurface([122], 123)
gmsh.modelGeoAddLineLoop([114, -110, 5, 113], 124)
gmsh.modelGeoAddPlaneSurface([124], 125)
gmsh.modelGeoAddLineLoop([115, 116, 117, 114], 126)
gmsh.modelGeoAddPlaneSurface([126], 127)

# The API to create surface loops ("shells") and volumes is similar to the
# one used to create line loops and surfaces.
gmsh.modelGeoAddSurfaceLoop([127, 119, 121, 123, 125, 11], 128)
gmsh.modelGeoAddVolume([128], 129)

# Extrusion works as expected, by providing a vector of (dim, tag) pairs as
# input, the translation vector, and a vector of (dim, tag) pairs as output.
ov2 = gmsh.PairVector()
gmsh.modelGeoExtrude([ov[1]], 0, 0, 0.12, ov2)

# Mesh sizes associated to geometrical points can be set by passing a vector of
# (dim, tag) pairs for the corresponding points.

gmsh.modelGeoMeshSetSize([(0,103), (0,105), (0,109), (0,102), (0,28),
                         (0, 24), (0,6), (0,5)], lc * 3)

gmsh.modelAddPhysicalGroup(3, [129,130], 1)
gmsh.modelSetPhysicalName(3, 1, "The volume")

gmsh.modelGeoSynchronize()

gmsh.modelMeshGenerate(3)

gmsh.write("t2.msh")

gmsh.finalize()
