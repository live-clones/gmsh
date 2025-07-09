import gmsh
gmsh.initialize()
gmsh.merge('bl2.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','3,4')
gmsh.plugin.setString('BoundaryLayer','Curves','1')
gmsh.plugin.setNumber('BoundaryLayer','Width',8.e-3)
gmsh.plugin.run('BoundaryLayer')
#gmsh.plugin.run('BoundaryLayer')
#gmsh.plugin.run('BoundaryLayer')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
