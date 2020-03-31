# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 7
#
#  Background mesh
#
# ------------------------------------------------------------------------------

import gmsh
import os

# Mesh sizes can be specified very accurately by providing a background mesh,
# i.e., a post-processing view that contains the target characteristic lengths.

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# Create a simple rectangular geometry
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

factory.synchronize()

# Merge a post-processing view containing the target mesh sizes
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, '..', 't7_bgmesh.pos'))

# Add the post-processing view as a new size field
bg_field = model.mesh.field.add("PostView")

# Apply the view as the current background mesh
model.mesh.field.setAsBackgroundMesh(bg_field)

gmsh.model.mesh.generate(2)
gmsh.write("t7.msh")

# Show the mesh
# gmsh.fltk.run()

gmsh.finalize()
