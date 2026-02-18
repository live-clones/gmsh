import gmsh
gmsh.initialize()
gmsh.merge('bl2.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','3,4')
gmsh.plugin.setString('BoundaryLayer','Curves','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1.e-2)
gmsh.plugin.setNumber('BoundaryLayer','Size',1.e-3)
gmsh.plugin.run('BoundaryLayer')
#gmsh.plugin.run('BoundaryLayer')
#gmsh.plugin.run('BoundaryLayer')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
