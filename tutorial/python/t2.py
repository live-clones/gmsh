# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 2
#
#  Geometrical transformations, extruded geometries, elementary entities
#  (volumes), physical groups (volumes)
#
# ------------------------------------------------------------------------------

import gmsh
import sys
import math

# We start by giving some nice shortcuts for some namespaces
model = gmsh.model
factory = model.geo

# If sys.argv is passed to gmsh.initialize(), Gmsh will parse the command line
# in the same way as the standalone Gmsh app:
gmsh.initialize(sys.argv)

gmsh.option.setNumber("General.Terminal", 1)

model.add("t2")

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
model.addPhysicalGroup(0, [1, 2, 4], 5)
ps = model.addPhysicalGroup(2, [1])
model.setPhysicalName(2, ps, "My surface")

# We can then add new points and curves in the same way as we did in `t1.py':
factory.addPoint(0, .4, 0, lc, 5)
factory.addLine(4, 5, 5)

# But Gmsh also provides tools to transform (translate, rotate, etc.)
# elementary entities or copies of elementary entities.  Geometrical
# transformations take a vector of pairs of integers as first argument, which
# contains the list of entities, represented by (dimension, tag) pairs.  For
# example, the point 5 (dimension=0, tag=5) can be moved by 0.02 to the left
# (dx=-0.02, dy=0, dz=0) with
factory.translate([(0, 5)], -0.02, 0, 0)

# And it can be further rotated by -Pi/4 around (0, 0.3, 0) (with the rotation
# along the z axis) with:
factory.rotate([(0, 5)], 0,0.3,0, 0,0,1, -math.pi/4)

# Note that there are no units in Gmsh: coordinates are just numbers - it's
# up to the user to associate a meaning to them.

# Point 3 can be duplicated and translated by 0.05 along the y axis by using the
# copy() function, which takes a vector of (dim, tag) pairs as input, and
# returns another vector of (dim, tag) pairs:
ov = factory.copy([(0, 3)])
factory.translate(ov, 0, 0.05, 0)

# The new point tag is available in ov[0][1], and can be used to create new
# lines:
factory.addLine(3, ov[0][1], 7)
factory.addLine(ov[0][1], 5, 8)
factory.addCurveLoop([5,-8,-7,3], 10)
factory.addPlaneSurface([10], 11)

# In the same way, we can translate copies of the two surfaces 1 and 11 to the
# right with the following command:
ov = factory.copy([(2, 1), (2, 11)])
factory.translate(ov, 0.12, 0, 0)

print "New surfaces " + str(ov[0][1]) + " and " + str(ov[1][1])

# Volumes are the fourth type of elementary entities in Gmsh. In the same way
# one defines curve loops to build surfaces, one has to define surface loops
# (i.e. `shells') to build volumes. The following volume does not have holes and
# thus consists of a single surface loop:
factory.addPoint(0., 0.3, 0.12, lc, 100)
factory.addPoint(0.1, 0.3, 0.12, lc, 101)
factory.addPoint(0.1, 0.35, 0.12, lc, 102)

# We would like to retrieve the coordinates of point 5 to create point 103, so
# we synchronize the model, and use `getValue()'
factory.synchronize()
xyz = model.getValue(0, 5, [])
factory.addPoint(xyz[0], xyz[1], 0.12, lc, 103)

factory.addLine(4, 100, 110)
factory.addLine(3, 101, 111)
factory.addLine(6, 102, 112)
factory.addLine(5, 103, 113)
factory.addLine(103, 100, 114)
factory.addLine(100, 101, 115)
factory.addLine(101, 102, 116)
factory.addLine(102, 103, 117)

factory.addCurveLoop([115, -111, 3, 110], 118)
factory.addPlaneSurface([118], 119)
factory.addCurveLoop([111, 116, -112, -7], 120)
factory.addPlaneSurface([120], 121)
factory.addCurveLoop([112, 117, -113, -8], 122)
factory.addPlaneSurface([122], 123)
factory.addCurveLoop([114, -110, 5, 113], 124)
factory.addPlaneSurface([124], 125)
factory.addCurveLoop([115, 116, 117, 114], 126)
factory.addPlaneSurface([126], 127)

factory.addSurfaceLoop([127, 119, 121, 123, 125, 11], 128)
factory.addVolume([128], 129)

# When a volume can be extruded from a surface, it is usually easier to use the
# `extrude()' function directly instead of creating all the points, curves and
# surfaces by hand. For example, the following command extrudes the surface 11
# along the z axis and automatically creates a new volume (as well as all the
# needed points, curves and surfaces). As expected, the function takes a vector
# of (dim, tag) pairs as input as well as the translation vector, and returns a
# vector of (dim, tag) pairs as output:
ov2 = factory.extrude([ov[1]], 0, 0, 0.12)

# Mesh sizes associated to geometrical points can be set by passing a vector of
# (dim, tag) pairs for the corresponding points:
factory.mesh.setSize([(0,103), (0,105), (0,109), (0,102), (0,28),
                      (0, 24), (0,6), (0,5)], lc * 3)

# We finally group volumes 129 and 130 in a single physical group with tag `1'
# and name "The volume":
model.addPhysicalGroup(3, [129,130], 1)
model.setPhysicalName(3, 1, "The volume")

# We finish by synchronizing the data from the built-in geometry kernel with the
# Gmsh model, and by generating and saving the mesh:
factory.synchronize()
model.mesh.generate(3)
gmsh.write("t2.msh")

# Note that, if the transformation tools are handy to create complex geometries,
# it is also sometimes useful to generate the `flat' geometry, with an explicit
# representation of all the elementary entities.
#
# With the built-in geometry kernel, this can be achieved by saving the model in
# the `Gmsh Unrolled GEO' format:
#
# gmsh.write("t2.geo_unrolled");
#
# With the OpenCASCADE geometry kernel, unrolling the geometry can be achieved
# by exporting in the `OpenCASCADE BRep' format:
#
# gmsh.write("t2.brep");
#
# (OpenCASCADE geometries can also be exported as STEP files.)

# It is important to note that Gmsh never translates geometry data into a common
# representation: all the operations on a geometrical entity are performed
# natively with the associated geometry kernel. Consequently, one cannot export
# a geometry constructed with the built-in kernel as an OpenCASCADE BRep file;
# or export an OpenCASCADE model as an Unrolled GEO file.

gmsh.finalize()
