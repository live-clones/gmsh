# ------------------------------------------------------------------------------
#
#  Gmsh Julia tutorial 2
#
#  Transformations, extruded geometries, volumes
#
# ------------------------------------------------------------------------------

import gmsh

# If ARGS is passed to gmsh.initialize(), Gmsh will parse the command line in
# the same way as the standalone Gmsh app:
gmsh.initialize(append!(["gmsh"], ARGS))

gmsh.model.add("t2")

# Copied from `t1.jl'...
lc = 1e-2
gmsh.model.geo.addPoint(0, 0, 0, lc, 1)
gmsh.model.geo.addPoint(.1, 0,  0, lc, 2)
gmsh.model.geo.addPoint(.1, .3, 0, lc, 3)
gmsh.model.geo.addPoint(0, .3, 0, lc, 4)
gmsh.model.geo.addLine(1, 2, 1)
gmsh.model.geo.addLine(3, 2, 2)
gmsh.model.geo.addLine(3, 4, 3)
gmsh.model.geo.addLine(4, 1, 4)
gmsh.model.geo.addCurveLoop([4, 1, -2, 3], 1)
gmsh.model.geo.addPlaneSurface([1], 1)
gmsh.model.geo.synchronize()
gmsh.model.addPhysicalGroup(1, [1, 2, 4], 5)
gmsh.model.addPhysicalGroup(2, [1], -1, "My surface")

# We can then add new points and curves in the same way as we did in `t1.jl':
gmsh.model.geo.addPoint(0, .4, 0, lc, 5)
gmsh.model.geo.addLine(4, 5, 5)

# But Gmsh also provides tools to transform (translate, rotate, etc.)
# elementary entities or copies of elementary entities.  Geometrical
# transformations take a vector of pairs of integers as first argument, which
# contains the list of entities, represented by (dimension, tag) pairs.  For
# example, the point 5 (dimension=0, tag=5) can be moved by 0.02 to the left
# (dx=-0.02, dy=0, dz=0) with
gmsh.model.geo.translate([(0, 5)], -0.02, 0, 0)

# And it can be further rotated by -Pi/4 around (0, 0.3, 0) (with the rotation
# along the z axis) with:
gmsh.model.geo.rotate([(0, 5)], 0, 0.3, 0, 0, 0, 1, -pi / 4)

# Note that there are no units in Gmsh: coordinates are just numbers - it's
# up to the user to associate a meaning to them.

# Point 3 can be duplicated and translated by 0.05 along the y axis by using the
# copy() function, which takes a vector of (dim, tag) pairs as input, and
# returns another vector of (dim, tag) pairs:
ov = gmsh.model.geo.copy([(0, 3)])
gmsh.model.geo.translate(ov, 0, 0.05, 0)

# The new point tag is available in ov[1][2], and can be used to create new
# lines:
gmsh.model.geo.addLine(3, ov[1][2], 7)
gmsh.model.geo.addLine(ov[1][2], 5, 8)
gmsh.model.geo.addCurveLoop([5, -8, -7, 3], 10)
gmsh.model.geo.addPlaneSurface([10], 11)

# In the same way, we can translate copies of the two surfaces 1 and 11 to the
# right with the following command:
ov = gmsh.model.geo.copy([(2, 1), (2, 11)])
gmsh.model.geo.translate(ov, 0.12, 0, 0)

println("New surfaces ", ov[1][2], " and ", ov[2][2])

# Volumes are the fourth type of elementary entities in Gmsh. In the same way
# one defines curve loops to build surfaces, one has to define surface loops
# (i.e. `shells') to build volumes. The following volume does not have holes and
# thus consists of a single surface loop:
gmsh.model.geo.addPoint(0., 0.3, 0.12, lc, 100)
gmsh.model.geo.addPoint(0.1, 0.3, 0.12, lc, 101)
gmsh.model.geo.addPoint(0.1, 0.35, 0.12, lc, 102)

# We would like to retrieve the coordinates of point 5 to create point 103, so
# we synchronize the model, and use `getValue()'
gmsh.model.geo.synchronize()
xyz = gmsh.model.getValue(0, 5, [])
gmsh.model.geo.addPoint(xyz[1], xyz[2], 0.12, lc, 103)

gmsh.model.geo.addLine(4, 100, 110)
gmsh.model.geo.addLine(3, 101, 111)
gmsh.model.geo.addLine(6, 102, 112)
gmsh.model.geo.addLine(5, 103, 113)
gmsh.model.geo.addLine(103, 100, 114)
gmsh.model.geo.addLine(100, 101, 115)
gmsh.model.geo.addLine(101, 102, 116)
gmsh.model.geo.addLine(102, 103, 117)

gmsh.model.geo.addCurveLoop([115, -111, 3, 110], 118)
gmsh.model.geo.addPlaneSurface([118], 119)
gmsh.model.geo.addCurveLoop([111, 116, -112, -7], 120)
gmsh.model.geo.addPlaneSurface([120], 121)
gmsh.model.geo.addCurveLoop([112, 117, -113, -8], 122)
gmsh.model.geo.addPlaneSurface([122], 123)
gmsh.model.geo.addCurveLoop([114, -110, 5, 113], 124)
gmsh.model.geo.addPlaneSurface([124], 125)
gmsh.model.geo.addCurveLoop([115, 116, 117, 114], 126)
gmsh.model.geo.addPlaneSurface([126], 127)

gmsh.model.geo.addSurfaceLoop([127, 119, 121, 123, 125, 11], 128)
gmsh.model.geo.addVolume([128], 129)

# When a volume can be extruded from a surface, it is usually easier to use the
# `extrude()' function directly instead of creating all the points, curves and
# surfaces by hand. For example, the following command extrudes the surface 11
# along the z axis and automatically creates a new volume (as well as all the
# needed points, curves and surfaces). As expected, the function takes a vector
# of (dim, tag) pairs as input as well as the translation vector, and returns a
# vector of (dim, tag) pairs as output:
ov2 = gmsh.model.geo.extrude([ov[2]], 0, 0, 0.12)

# Mesh sizes associated to geometrical points can be set by passing a vector of
# (dim, tag) pairs for the corresponding points:
gmsh.model.geo.mesh.setSize([(0, 103), (0, 105), (0, 109), (0, 102), (0, 28),
                             (0, 24), (0, 6), (0, 5)], lc * 3)

# We finish by synchronizing the data from the built-in CAD kernel with the Gmsh
# model:
gmsh.model.geo.synchronize()

# We group volumes 129 and 130 in a single physical group with tag `1' and name
# "The volume":
gmsh.model.addPhysicalGroup(3, [129, 130], 1, "The volume")

# We finally generate and save the mesh:
gmsh.model.mesh.generate(3)
gmsh.write("t2.msh")

# Note that, if the transformation tools are handy to create complex geometries,
# it is also sometimes useful to generate the `flat' geometry, with an explicit
# representation of all the elementary entities.
#
# This can be achieved by saving the model in the `Gmsh Unrolled GEO' format:
#
# gmsh.write("t2.geo_unrolled");

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
