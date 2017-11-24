#!/usr/bin/env python

# This files reimplements gmsh/tutorial/t3.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t3")

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

h = 0.1
angle = 90.

ov = gmsh.PairVector()
  
# Extruding the mesh in addition to the geometry works as in .geo files: the
# number of elements for each layer and the (end) height of each layer are
# specified in two vectors.
gmsh.modelGeoExtrude([(2,1)], 0, 0, h, ov, [8,2], [0.5,1])

#/ Rotational and twisted extrusions are available as well with the built-in CAD
# kernel. The last (optional) argument for the Extrude/Revolve/Twist commands
# specified whether the extruded mesh should be recombined or not.
gmsh.modelGeoRevolve([(2,28)], -0.1,0,0.1, 0,1,0, -math.pi/2, ov, [7])
gmsh.modelGeoTwist([(2,50)], 0,0.15,0.25, -2*h,0,0, 1,0,0, angle*math.pi/180.,
                  ov, [10], [], True)

gmsh.modelAddPhysicalGroup(3, [1, 2, ov[1][1]], 101)

gmsh.modelGeoSynchronize()
gmsh.modelMeshGenerate(3)
gmsh.write("t3.msh")
gmsh.finalize()
