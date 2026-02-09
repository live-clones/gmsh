# ------------------------------------------------------------------------------
#
#  Gmsh Julia tutorial 16
#
#  Constructive Solid Geometry, OpenCASCADE geometry kernel
#
# ------------------------------------------------------------------------------

# Instead of constructing a model in a bottom-up fashion with Gmsh's built-in
# geometry kernel, starting with version 3 Gmsh allows you to directly use
# alternative geometry kernels. Here we will use the OpenCASCADE kernel.

import gmsh

gmsh.initialize()

gmsh.model.add("t16")

# Let's build the same model as in `t5.jl', but using constructive solid
# geometry.

# We can log all messages for further processing with:
gmsh.logger.start()

# We first create two cubes:
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1, 1)
gmsh.model.occ.addBox(0, 0, 0, 0.5, 0.5, 0.5, 2)

# We apply a boolean difference to create the "cube minus one eighth" shape:
gmsh.model.occ.cut([(3, 1)], [(3, 2)], 3)

# Boolean operations with OpenCASCADE always create new entities. By default the
# extra arguments `removeObject' and `removeTool' in `cut()' are set to `True',
# which will delete the original entities.

# We then create the five spheres:
x = 0; y = 0.75; z = 0; r = 0.09
holes = []
for t in 1:5
    global x, z
    x += 0.166
    z += 0.166
    gmsh.model.occ.addSphere(x, y, z, r, 3 + t)
    t = (3, 3 + t)
    push!(holes, t)
end

# If we had wanted five empty holes we would have used `cut()' again. Here we
# want five spherical inclusions, whose mesh should be conformal with the mesh
# of the cube: we thus use `fragment()', which intersects all volumes in a
# conformal manner (without creating duplicate interfaces):
ov, ovv = gmsh.model.occ.fragment([(3, 3)], holes)

# ov contains all the generated entities of the same dimension as the input
# entities:
println("fragment produced volumes:")
for e in ov
    println(e)
end

# ovv contains the parent-child relationships for all the input entities:
println("before/after fragment relations:")
for e in zip([(3, 3); holes], ovv)
    println("parent ", e[1], " -> child ", e[2])
end

gmsh.model.occ.synchronize()

# When the boolean operation leads to simple modifications of entities, and if
# one deletes the original entities, Gmsh tries to assign the same tag to the
# new entities. (This behavior is governed by the
# `Geometry.OCCBooleanPreserveNumbering' option.)

# Here the `Physical Volume' definitions can thus be made for the 5 spheres
# directly, as the five spheres (volumes 4, 5, 6, 7 and 8), which will be
# deleted by the fragment operations, will be recreated identically (albeit with
# new surfaces) with the same tags:
for i in 1:5
    gmsh.model.addPhysicalGroup(3, [3 + i], i)
end

# The tag of the cube will change though, so we need to access it
# programmatically:
gmsh.model.addPhysicalGroup(3, [ov[1][2]], 10)

# Creating entities using constructive solid geometry is very powerful, but can
# lead to practical issues for e.g. setting mesh sizes at points, or identifying
# boundaries.

# To identify points or other bounding entities you can take advantage of the
# `getEntities()', `getBoundary()', `getClosestEntities()' and
# `getEntitiesInBoundingBox()' functions:

# Define a physical surface for the top and right-most surfaces, by finding
# amongst the surfaces making up the boundary of the model, the two closest to
# point (1, 1, 0.5):
bnd = gmsh.model.getBoundary(gmsh.model.getEntities(3))
closest = gmsh.model.occ.getClosestEntities(1, 1, 0.5, bnd, 2)[1]
gmsh.model.addPhysicalGroup(2, [closest[1][2], closest[2][2]], 100,
                            "Top & right surfaces")

# Assign a mesh size to all the points:
lcar1 = .1
lcar2 = .0005
lcar3 = .055
ov = gmsh.model.getEntities(0);
gmsh.model.mesh.setSize(ov, lcar1);

# Override this constraint on the points of the five spheres:
ov = gmsh.model.getBoundary(holes, false, false, true);
gmsh.model.mesh.setSize(ov, lcar3);

# Select the corner point by searching for it geometrically using a bounding box
# (`getClosestEntities()' could have been used as well):
eps = 1e-3
ov = gmsh.model.getEntitiesInBoundingBox(0.5 - eps, 0.5 - eps, 0.5 - eps,
                                         0.5 + eps, 0.5 + eps, 0.5 + eps, 0)
gmsh.model.mesh.setSize(ov, lcar2)

gmsh.model.mesh.generate(3)

gmsh.write("t16.msh")

# Additional examples created with the OpenCASCADE geometry kernel are available
# in `t18.jl', `t19.jl' and `t20.jl', as well as in the `examples/api'
# directory.

# Inspect the log:
log = gmsh.logger.get()
println("Logger has recorded ", length(log), " lines")
gmsh.logger.stop()

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
