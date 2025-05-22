import gmsh
gmsh.initialize()
gmsh.merge('bl5.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','13,14,15,16,17,19,18')
gmsh.plugin.setString('BoundaryLayer','Vertices','16,18,19')

gmsh.plugin.setNumber('BoundaryLayer','Width',.25)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',1.1)
gmsh.plugin.setNumber('BoundaryLayer','Hwall',.01)
gmsh.plugin.run('BoundaryLayer')
#    gmsh.plugin.setString('BoundaryLayer','Vertices','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
