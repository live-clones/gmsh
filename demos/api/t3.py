#!/usr/bin/env python

# This files reimplements gmsh/tutorial/t3.geo in Python.

from gmsh import *
import math

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("t3")

# Copied from t1.py...
lc = 1e-2
gmshModelGeoAddPoint(0, 0, 0, lc, 1)
gmshModelGeoAddPoint(.1, 0,  0, lc, 2)
gmshModelGeoAddPoint(.1, .3, 0, lc, 3)
gmshModelGeoAddPoint(0, .3, 0, lc, 4)
gmshModelGeoAddLine(1, 2, 1)
gmshModelGeoAddLine(3, 2, 2)
gmshModelGeoAddLine(3, 4, 3)
gmshModelGeoAddLine(4, 1, 4)
gmshModelGeoAddLineLoop([4, 1, -2, 3], 1)
gmshModelGeoAddPlaneSurface([1], 1)
gmshModelAddPhysicalGroup(0, [1, 2], 1)
gmshModelAddPhysicalGroup(1, [1, 2], 2)
gmshModelAddPhysicalGroup(2, [1], 6)
gmshModelSetPhysicalName(2, 6, "My surface")
# ...end of copy

h = 0.1
angle = 90.

ov = PairVector()
  
# Extruding the mesh in addition to the geometry works as in .geo files: the
# number of elements for each layer and the (end) height of each layer are
# specified in two vectors.
gmshModelGeoExtrude([(2,1)], 0, 0, h, ov, [8,2], [0.5,1])

#/ Rotational and twisted extrusions are available as well with the built-in CAD
# kernel. The last (optional) argument for the Extrude/Revolve/Twist commands
# specified whether the extruded mesh should be recombined or not.
gmshModelGeoRevolve([(2,28)], -0.1,0,0.1, 0,1,0, -math.pi/2, ov, [7])
gmshModelGeoTwist([(2,50)], 0,0.15,0.25, -2*h,0,0, 1,0,0, angle*math.pi/180.,
                  ov, [10], [], True)

gmshModelAddPhysicalGroup(3, [1, 2, ov[1][1]], 101)

gmshModelGeoSynchronize()
gmshModelMesh(3)
gmshExport("t3.msh")
gmshFinalize()
