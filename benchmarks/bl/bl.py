import gmsh
gmsh.initialize()
gmsh.model.occ.addRectangle(0,0,0, 1,1)
gmsh.model.occ.mesh.setSize ( [(0,2),(0,4),(0,3)], 3.e-2)
gmsh.model.occ.mesh.setSize ( [(0,1),(0,3)], 1.e-2)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)

gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3')
gmsh.plugin.setNumber('BoundaryLayer','Width',1.e-3)
gmsh.plugin.run('BoundaryLayer')


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
