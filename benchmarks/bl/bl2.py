import gmsh
gmsh.initialize()
gmsh.merge('bl.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','3,4')
gmsh.plugin.setString('BoundaryLayer','Curves','1')
gmsh.plugin.setNumber('BoundaryLayer','Width',1.e-2)
gmsh.plugin.run('BoundaryLayer')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
