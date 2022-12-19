# See the corresponding Python tutorial for detailed comments.

import gmsh

gmsh.initialize()

gmsh.model.add("t17")

gmsh.model.occ.addRectangle(-2, -2, 0, 4, 4)
gmsh.model.occ.synchronize()

path = abspath(joinpath("..","t17_bgmesh.pos"))
gmsh.merge(path)


bg_field = gmsh.model.mesh.field.add("PostView")
gmsh.model.mesh.field.setNumber(bg_field, "ViewIndex", 0)
gmsh.model.mesh.field.setAsBackgroundMesh(bg_field)

gmsh.option.setNumber("Mesh.SmoothRatio", 3)
gmsh.option.setNumber("Mesh.AnisoMax", 1000)
gmsh.option.setNumber("Mesh.Algorithm", 7)

gmsh.model.mesh.generate(2)
gmsh.write("t17.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
