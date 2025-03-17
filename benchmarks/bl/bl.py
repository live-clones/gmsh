import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.model.occ.addRectangle(0,0,0, 1,1)
gmsh.model.occ.mesh.setSize ( [(0,2),(0,4),(0,1)], l)
gmsh.model.occ.mesh.setSize ( [(0,3)], l/10)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)

gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3,4')
gmsh.plugin.setNumber('BoundaryLayer','Width',l/10)

gmsh.plugin.run('BoundaryLayer')



#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
