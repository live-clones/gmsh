# ------------------------------------------------------------------------------
#
#  Gmsh Julia tutorial 20
#
#  STEP import and manipulation, geometry partitioning
#
# ------------------------------------------------------------------------------

# The OpenCASCADE CAD kernel allows to import STEP files and to modify them. In
# this tutorial we will load a STEP geometry and partition it into slices.

import gmsh

gmsh.initialize()

gmsh.model.add("t20")

# Load a STEP file (using `importShapes' instead of `merge' allows to directly
# retrieve the tags of the highest dimensional imported entities):
path = abspath(joinpath(@__DIR__, "..", "t20_data.step"))
v = gmsh.model.occ.importShapes(path)

# If we had specified
#
# gmsh.option.setString('Geometry.OCCTargetUnit', 'M')
#
# before merging the STEP file, OpenCASCADE would have converted the units to
# meters (instead of the default, which is millimeters).

# Get the bounding box of the volume:
xmin, ymin, zmin, xmax, ymax, zmax = gmsh.model.occ.getBoundingBox(
    v[1][1], v[1][2])

# We want to slice the model into N slices, and either keep the volume slices
# or just the surfaces obtained by the cutting:

N = 5 # Number of slices
dir = "X" # Direction: "X", "Y" or "Z"
surf = false # Keep only surfaces?

dx = (xmax - xmin)
dy = (ymax - ymin)
dz = (zmax - zmin)
L = (dir == "X") ? dz : dx
H = (dir == "Y") ? dz : dy

# Create the first cutting plane:
s = []
push!(s,(2, gmsh.model.occ.addRectangle(xmin, ymin, zmin, L, H)))
if dir == "X"
    gmsh.model.occ.rotate([s[1]], xmin, ymin, zmin, 0, 1, 0, -pi/2)
elseif dir == "Y"
    gmsh.model.occ.rotate([s[1]], xmin, ymin, zmin, 1, 0, 0, pi/2)
end
tx = (dir == "X") ? dx / N : 0
ty = (dir == "Y") ? dy / N : 0
tz = (dir == "Z") ? dz / N : 0
gmsh.model.occ.translate([s[1]], tx, ty, tz)

# Create the other cutting planes:
for i in 1:N-1
    append!(s,(gmsh.model.occ.copy([s[1]])))
    gmsh.model.occ.translate([s[length(s)]], i * tx, i * ty, i * tz)
end

# Fragment (i.e. intersect) the volume with all the cutting planes:
gmsh.model.occ.fragment(v, s)

# Now remove all the surfaces (and their bounding entities) that are not on the
# boundary of a volume, i.e. the parts of the cutting planes that "stick out" of
# the volume:
gmsh.model.occ.remove(gmsh.model.occ.getEntities(2), true)

gmsh.model.occ.synchronize()

if surf
    # If we want to only keep the surfaces, retrieve the surfaces in bounding
    # boxes around the cutting planes...
    eps = 1e-4
    s = []
    for i in 1:N
        xx = (dir == "X") ? xmin : xmax;
        yy = (dir == "Y") ? ymin : ymax;
        zz = (dir == "Z") ? zmin : zmax;
        append!(s, (gmsh.model.getEntitiesInBoundingBox(
            xmin - eps + i * tx, ymin - eps + i * ty, zmin - eps + i * tz,
            xx + eps + i * tx, yy + eps + i * ty, zz + eps + i * tz, 2)))
    end

    # ...and remove all the other entities (here directly in the model, as we
    # won't modify any OpenCASCADE entities later on):
    dels = gmsh.model.getEntities(2)
    for e in s
        deleteat!(dels, findall(x -> x == e, dels))
    end
    gmsh.model.removeEntities(gmsh.model.getEntities(3))
    gmsh.model.removeEntities(dels)
    gmsh.model.removeEntities(gmsh.model.getEntities(1))
    gmsh.model.removeEntities(gmsh.model.getEntities(0))
end

# Finally, let's specify a global mesh size and mesh the partitioned model:
gmsh.option.setNumber("Mesh.MeshSizeMin", 3)
gmsh.option.setNumber("Mesh.MeshSizeMax", 3)
gmsh.model.mesh.generate(3)
gmsh.write("t20.msh")

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
