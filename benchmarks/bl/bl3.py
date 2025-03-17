import gmsh
gmsh.initialize()
gmsh.merge('bl3.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3')
gmsh.plugin.setString('BoundaryLayer','Vertices','30')

gmsh.plugin.setNumber('BoundaryLayer','Width',.04)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',1.5)
gmsh.plugin.setNumber('BoundaryLayer','Hwall',.0001)
gmsh.plugin.run('BoundaryLayer')
#    gmsh.plugin.setString('BoundaryLayer','Vertices','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
