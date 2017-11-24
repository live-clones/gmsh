# This file reimplements gmsh/tutorial/t6.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t6")

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

# Delete surface 1 and left boundary (line 4)
gmsh.modelGeoRemove([[2,1], [1,4]])

# Replace left boundary with 3 new lines
p1 = gmsh.modelGeoAddPoint(-0.05, 0.05, 0, lc)
p2 = gmsh.modelGeoAddPoint(-0.05, 0.1, 0, lc)
l1 = gmsh.modelGeoAddLine(1, p1)
l2 = gmsh.modelGeoAddLine(p1, p2)
l3 = gmsh.modelGeoAddLine(p2, 4)

# Recreate surface
gmsh.modelGeoAddLineLoop([2, -1, l1, l2, l3, -3], 2)
gmsh.modelGeoAddPlaneSurface([-2], 1)

# Put 20 points with a refinement toward the extremities on curve 2
gmsh.modelGeoMeshSetTransfiniteLine(2, 20, "Bump", 0.05)

# Put 20 points total on combination of curves l1, l2 and l3 (beware that the
# points p1 and p2 are shared by the curves, so we do not create 6 + 6 + 10 = 22
# points, but 20!)
gmsh.modelGeoMeshSetTransfiniteLine(l1, 6)
gmsh.modelGeoMeshSetTransfiniteLine(l2, 6)
gmsh.modelGeoMeshSetTransfiniteLine(l3, 10)

# Put 30 points following a geometric progression on curve 1 (reversed) and on
# curve 3
gmsh.modelGeoMeshSetTransfiniteLine(1, 30, "Progression", -1.2)
gmsh.modelGeoMeshSetTransfiniteLine(3, 30, "Progression", 1.2)

# Define the Surface as transfinite, by specifying the four corners of the
# transfinite interpolation
gmsh.modelGeoMeshSetTransfiniteSurface(1, "Left", [1,2,3,4])

# Recombine the triangles into quads
gmsh.modelGeoMeshSetRecombine(2, 1)

# Apply an elliptic smoother to the grid
gmsh.optionSetNumber("Mesh.Smoothing", 100)
gmsh.modelAddPhysicalGroup(2, [1], 1)

# When the surface has only 3 or 4 control points, the transfinite constraint
# can be applied automatically (without specifying the corners explictly).
gmsh.modelGeoAddPoint(0.2, 0.2, 0, 1.0, 7)
gmsh.modelGeoAddPoint(0.2, 0.1, 0, 1.0, 8)
gmsh.modelGeoAddPoint(0, 0.3, 0, 1.0, 9)
gmsh.modelGeoAddPoint(0.25, 0.2, 0, 1.0, 10)
gmsh.modelGeoAddPoint(0.3, 0.1, 0, 1.0, 11)
gmsh.modelGeoAddLine(8, 11, 10)
gmsh.modelGeoAddLine(11, 10, 11)
gmsh.modelGeoAddLine(10, 7, 12)
gmsh.modelGeoAddLine(7, 8, 13)
gmsh.modelGeoAddLineLoop([13, 10, 11, 12], 14)
gmsh.modelGeoAddPlaneSurface([14], 15)
for i in range(10,14):
    gmsh.modelGeoMeshSetTransfiniteLine(i, 10)
gmsh.modelGeoMeshSetTransfiniteSurface(15)
gmsh.modelAddPhysicalGroup(2, [15], 2)

gmsh.modelMeshGenerate(2)
gmsh.write("t6.msh")
gmsh.finalize()
