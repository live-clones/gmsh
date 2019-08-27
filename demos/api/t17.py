# This file reimplements gmsh/tutorial/t17.geo in Python.
#
# Anisotropic background mesh

import gmsh
import math

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

factory.addPoint(-1, -1, 0)
factory.addPoint(1, -1, 0)
factory.addPoint(1, 1, 0)
factory.addPoint(-1, 1, 0)

factory.addLine(1, 2, 1)
factory.addLine(2, 3, 2)
factory.addLine(3, 4, 3)
factory.addLine(4, 1, 4)
factory.addCurveLoop([1, 2, 3, 4], 1)
factory.addPlaneSurface([1], 1)

factory.synchronize()

# add a post-processing view to use as a size field
gmsh.merge("t17.pos")

bg_field = model.mesh.field.fromView(0)
model.mesh.field.setAsBackgroundMesh(bg_field)

# use bamg
gmsh.option.setNumber("Mesh.SmoothRatio", 3)
gmsh.option.setNumber("Mesh.AnisoMax", 1000)
gmsh.option.setNumber("Mesh.Algorithm", 7)

gmsh.model.mesh.generate(2)
gmsh.write("t17.msh")

gmsh.fltk.run()
gmsh.finalize()
