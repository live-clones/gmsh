# This file reimplements gmsh/tutorial/t7.geo in Python.
# It extends t1.py to use a background mesh.

import gmsh

model = gmsh.model
factory = model.geo

# adapted t1.py section {{{

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

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

model.geo.synchronize()
# }}}

# -- begin t7.py --

# add the background mesh file as a view
gmsh.merge("bgmesh.pos")

# pass the just-added view number to specify the background mesh
gmsh.model.mesh.field.setAsBackgroundMesh(0)
gmsh.model.mesh.generate(2)

# show the mesh file
# gmsh.fltk.run()

gmsh.finalize()
