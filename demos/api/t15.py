# This file reimplements gmsh/tutorial/t15.geo in Python.

# Note that t15.geo begins by calling "Include(t1.geo)" to paste the contents
# of t1.geo into t15.geo. Since the Python API has no equivalent command, we
# mark the lines adapted from t1.py.
#
# For educational purposes this code makes use of frequent geometry model
# synchronization calls.
#
# If performance is a priority, you may want to group related embed calls to
# avoid calling the expensive synchronize operation too many times.

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

# }}}

# -- begin t15.py proper --

# We change the mesh size to generate a coarser mesh
lc = lc * 4
factory.mesh.setSize([(0, 1), (0, 2), (0, 3), (0, 4)], lc)

# Define a new point and embed it in a surface
factory.addPoint(0.02, 0.02, 0., lc, 5)

# We have to synchronize before embedding entites.
# Otherwise, we get an error like "Point 5 does not exist"
#
factory.synchronize()

# embed the point (dim 0) in the surface (dim 2)
model.mesh.embed(0, [5], 2, 1)

# We can also use embed to embed a curve in the 2D mesh
factory.addPoint(0.02, 0.12, 0., lc, 6)
factory.addPoint(0.04, 0.18, 0., lc, 7)
factory.addLine(6, 7, 5)

factory.synchronize()
model.mesh.embed(1, [5], 2, 1)

# Points and curves can also be embedded in volumes
factory.extrude([(2, 1)], 0, 0, 0.1)

p = factory.addPoint(0.07, 0.15, 0.025, lc)

factory.synchronize()
model.mesh.embed(0, [p], 3, 1)

factory.addPoint(0.025, 0.15, 0.025, lc, p+1)
l = factory.addLine(7, p+1)

factory.synchronize()
model.mesh.embed(1, [l], 3, 1)

# finally, we can only embed a surface in a volume
factory.addPoint(0.02, 0.12, 0.05, lc, p+2)
factory.addPoint(0.04, 0.12, 0.05, lc, p+3)
factory.addPoint(0.04, 0.18, 0.05, lc, p+4)
factory.addPoint(0.02, 0.18, 0.05, lc, p+5)

factory.addLine(p+2, p+3, l+1)
factory.addLine(p+3, p+4, l+2)
factory.addLine(p+4, p+5, l+3)
factory.addLine(p+5, p+2, l+4)

ll = factory.addCurveLoop([l+1, l+2, l+3, l+4])
s = factory.addPlaneSurface([ll])

factory.synchronize()
model.mesh.embed(2, [s], 3, 1)

# create and show the mesh
# model.mesh.generate(3)
# gmsh.fltk.run()

gmsh.finalize()
