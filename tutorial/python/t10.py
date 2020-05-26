# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 10
#
#  Mesh size fields
#
# ------------------------------------------------------------------------------

# In addition to specifying target mesh sizes at the points of the geometry (see
# `t1.py') or using a background mesh (see `t7.py'), you can use general mesh
# size "Fields".

import gmsh
import math

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

gmsh.model.add("t10")

# Let's create a simple rectangular geometry:
lc = .15
gmsh.model.geo.addPoint(0.0, 0.0, 0, lc, 1)
gmsh.model.geo.addPoint(1, 0.0, 0, lc, 2)
gmsh.model.geo.addPoint(1, 1, 0, lc, 3)
gmsh.model.geo.addPoint(0, 1, 0, lc, 4)
gmsh.model.geo.addPoint(0.2, .5, 0, lc, 5)

gmsh.model.geo.addLine(1, 2, 1)
gmsh.model.geo.addLine(2, 3, 2)
gmsh.model.geo.addLine(3, 4, 3)
gmsh.model.geo.addLine(4, 1, 4)

gmsh.model.geo.addCurveLoop([1, 2, 3, 4], 5)
gmsh.model.geo.addPlaneSurface([5], 6)

gmsh.model.geo.synchronize()

# Say we would like to obtain mesh elements with size lc/30 near curve 2 and
# point 5, and size lc elsewhere. To achieve this, we can use two fields:
# "Distance", and "Threshold". We first define a Distance field (`Field[1]') on
# points 5 and on curve 2. This field returns the distance to point 5 and to
# (100 equidistant points on) curve 2.
gmsh.model.mesh.field.add("Distance", 1)
gmsh.model.mesh.field.setNumbers(1, "NodesList", [5])
gmsh.model.mesh.field.setNumber(1, "NNodesByEdge", 100)
gmsh.model.mesh.field.setNumbers(1, "EdgesList", [2])

# We then define a `Threshold' field, which uses the return value of the
# `Distance' field 1 in order to define a simple change in element size
# depending on the computed distances
#
# LcMax -                         /------------------
#                               /
#                             /
#                           /
# LcMin -o----------------/
#        |                |       |
#      Point           DistMin DistMax
gmsh.model.mesh.field.add("Threshold", 2)
gmsh.model.mesh.field.setNumber(2, "IField", 1)
gmsh.model.mesh.field.setNumber(2, "LcMin", lc / 30)
gmsh.model.mesh.field.setNumber(2, "LcMax", lc)
gmsh.model.mesh.field.setNumber(2, "DistMin", 0.15)
gmsh.model.mesh.field.setNumber(2, "DistMax", 0.5)

# Say we want to modulate the mesh element sizes using a mathematical function
# of the spatial coordinates. We can do this with the MathEval field:
gmsh.model.mesh.field.add("MathEval", 3)
gmsh.model.mesh.field.setString(3, "F",
                                "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101")

# We could also combine MathEval with values coming from other fields. For
# example, let's define a `Distance' field around point 1
gmsh.model.mesh.field.add("Distance", 4)
gmsh.model.mesh.field.setNumbers(4, "NodesList", [1])

# We can then create a `MathEval' field with a function that depends on the
# return value of the `Distance' field 4, i.e., depending on the distance to
# point 1 (here using a cubic law, with minimum element size = lc / 100)
gmsh.model.mesh.field.add("MathEval", 5)
gmsh.model.mesh.field.setString(5, "F", "F4^3 + " + str(lc / 100))

# We could also use a `Box' field to impose a step change in element sizes
# inside a box
gmsh.model.mesh.field.add("Box", 6)
gmsh.model.mesh.field.setNumber(6, "VIn", lc / 15)
gmsh.model.mesh.field.setNumber(6, "VOut", lc)
gmsh.model.mesh.field.setNumber(6, "XMin", 0.3)
gmsh.model.mesh.field.setNumber(6, "XMax", 0.6)
gmsh.model.mesh.field.setNumber(6, "YMin", 0.3)
gmsh.model.mesh.field.setNumber(6, "YMax", 0.6)

# Many other types of fields are available: see the reference manual for a
# complete list. You can also create fields directly in the graphical user
# interface by selecting `Define->Fields' in the `Mesh' module.

# Finally, let's use the minimum of all the fields as the background mesh field:
gmsh.model.mesh.field.add("Min", 7)
gmsh.model.mesh.field.setNumbers(7, "FieldsList", [2, 3, 5, 6])

gmsh.model.mesh.field.setAsBackgroundMesh(7)

# To determine the size of mesh elements, Gmsh locally computes the minimum of
#
# 1) the size of the model bounding box;
# 2) if `Mesh.CharacteristicLengthFromPoints' is set, the mesh size specified
#    at geometrical points;
# 3) if `Mesh.CharacteristicLengthFromCurvature' is set, the mesh size based
#    on the curvature and `Mesh.MinimumElementsPerTwoPi';
# 4) the background mesh field;
# 5) any per-entity mesh size constraint.
#
# This value is then constrained in the interval
# [`Mesh.CharacteristicLengthMin', `Mesh.CharacteristicLengthMax'] and
# multiplied by `Mesh.CharacteristicLengthFactor'.  In addition, boundary
# mesh sizes (on curves or surfaces) are interpolated inside the enclosed
# entity (surface or volume, respectively) if the option
# `Mesh.CharacteristicLengthExtendFromBoundary' is set (which is the case by
# default).
#
# When the element size is fully specified by a background mesh (as it is in
# this example), it is thus often desirable to set

gmsh.option.setNumber("Mesh.CharacteristicLengthExtendFromBoundary", 0)
gmsh.option.setNumber("Mesh.CharacteristicLengthFromPoints", 0)
gmsh.option.setNumber("Mesh.CharacteristicLengthFromCurvature", 0)

# This will prevent over-refinement due to small mesh sizes on the boundary.

gmsh.model.mesh.generate(2)
gmsh.write("t10.msh")

# gmsh.fltk.run()

gmsh.finalize()
