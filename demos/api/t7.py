# This file reimplements gmsh/tutorial/t7.geo in Python.
#
# Background mesh

import gmsh

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# Copied from t1.py...
lc = 1e-2
factory.addPoint(0, 0, 0, lc, 1)
factory.addPoint(.1, 0,  0, lc, 2)
factory.addPoint(.1, .3, 0, lc, 3)
factory.addPoint(0, .3, 0, lc, 4)
factory.addLine(1, 2, 1)
factory.addLine(3, 2, 2)
factory.addLine(3, 4, 3)
factory.addLine(4, 1, 4)
factory.addCurveLoop([4, 1, -2, 3], 1)
factory.addPlaneSurface([1], 1)
model.addPhysicalGroup(0, [1, 2], 1)
model.addPhysicalGroup(1, [1, 2], 2)
model.addPhysicalGroup(2, [1], 6)
model.setPhysicalName(2, 6, "My surface")
# ...end of copy

factory.synchronize()

# add the background mesh file as a view
gmsh.merge("bgmesh.pos")

# add the post-processing view as a new size field
bg_field = model.mesh.field.add("PostView")
model.mesh.field.setAsBackgroundMesh(bg_field)

gmsh.model.mesh.generate(2)
gmsh.write("t7.msh")

# show the mesh file
gmsh.fltk.run()

gmsh.finalize()
