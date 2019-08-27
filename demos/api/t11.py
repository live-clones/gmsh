# This file reimplements gmsh/tutorial/t11.geo in Python.
#
# Unstructured quadrangular meshes

import gmsh

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

p1 = factory.addPoint(-1.25, -.5, 0)
p2 = factory.addPoint(1.25, -.5, 0)
p3 = factory.addPoint(1.25, 1.25, 0)
p4 = factory.addPoint(-1.25, 1.25, 0)

l1 = factory.addLine(p1, p2)
l2 = factory.addLine(p2, p3)
l3 = factory.addLine(p3, p4)
l4 = factory.addLine(p4, p1)

cl = factory.addCurveLoop([l1, l2, l3, l4])
pl = factory.addPlaneSurface([cl])

factory.synchronize()

# field options
field = model.mesh.field

# add an analytical size field with tag 1
field.add("MathEval", 1)
field.setString(1, "F", "0.01*(1.0+30.*(y-x*x)*(y-x*x) + (1-x)*(1-x))")
field.setAsBackgroundMesh(1)

# to generate quadrangles instead of triangles for the plane surface, add the
# recombine constraint before meshing
model.mesh.setRecombine(2, pl)
model.mesh.generate(2)

# we can handle several surfaces with a loop
# for s in surfaces:
#     model.mesh.setRecombine(2, s)
# model.mesh.generate(2)

# Or, you could force recombination after meshing for the entire mesh:
# model.mesh.generate(2)
# model.mesh.recombine()

# Or, you could set the option "Mesh.RecombineAll"
# gmsh.option.setNumber("Mesh.RecombineAll", 1)
# model.mesh.generate(2)

# You can set other meshing options depending on your quadrilateral requirements

# Better 2D planar quadrilateral meshes with the Frontal-Delaunay for quads
# algorithm
# gmsh.option.setNumber("Mesh.Algorithm", 8)
# model.mesh.generate(2)

# Force a full-quad mesh with either option
# gmsh.option.setNumber("Mesh.SubdivisionAlgorithm", 1)
# gmsh.option.setNumber("Mesh.RecombinationAlgorithm", 2) # or 3

# model.mesh.generate(2)

gmsh.fltk.run()

gmsh.finalize()
