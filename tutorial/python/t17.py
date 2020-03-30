# This file reimplements gmsh/tutorial/t17.geo in Python.
#
# Anisotropic background mesh

import gmsh
import math
import os

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

gmsh.model.occ.addRectangle(-1, -1, 0, 2, 2)
gmsh.model.occ.synchronize()

# add a post-processing view to use as a size field
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, '..', 't17_bgmesh.pos'))

bg_field = gmsh.model.mesh.field.add("PostView")
gmsh.model.mesh.field.setAsBackgroundMesh(bg_field)

# use bamg
gmsh.option.setNumber("Mesh.SmoothRatio", 3)
gmsh.option.setNumber("Mesh.AnisoMax", 1000)
gmsh.option.setNumber("Mesh.Algorithm", 7)

gmsh.model.mesh.generate(2)
gmsh.write("t17.msh")

gmsh.fltk.run()
gmsh.finalize()
