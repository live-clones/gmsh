import gmsh
gmsh.initialize()
gmsh.model.occ.addRectangle(0,0,0, 1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)
gmsh.plugin.run('BoundaryLayer')

gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
