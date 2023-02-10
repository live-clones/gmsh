# ------------------------------------------------------------------------------
#
#  Gmsh Julia tutorial 17
#
#  Anisotropic background mesh
#
# ------------------------------------------------------------------------------

# As seen in `t7.jl', mesh sizes can be specified very accurately by providing a
# background mesh, i.e., a post-processing view that contains the target mesh
# sizes.

# Here, the background mesh is represented as a metric tensor field defined on a
# square. One should use bamg as 2d mesh generator to enable anisotropic meshes
# in 2D.

import gmsh

gmsh.initialize()

gmsh.model.add("t17")

# Create a square
gmsh.model.occ.addRectangle(-2, -2, 0, 4, 4)
gmsh.model.occ.synchronize()

# Merge a post-processing view containing the target anisotropic mesh sizes
gmsh.merge(abspath(joinpath(@__DIR__, "..","t17_bgmesh.pos")))

# Apply the view as the current background mesh
bg_field = gmsh.model.mesh.field.add("PostView")
gmsh.model.mesh.field.setNumber(bg_field, "ViewIndex", 0)
gmsh.model.mesh.field.setAsBackgroundMesh(bg_field)

# Use bamg
gmsh.option.setNumber("Mesh.SmoothRatio", 3)
gmsh.option.setNumber("Mesh.AnisoMax", 1000)
gmsh.option.setNumber("Mesh.Algorithm", 7)

gmsh.model.mesh.generate(2)
gmsh.write("t17.msh")

# Launch the GUI to see the results:
if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
