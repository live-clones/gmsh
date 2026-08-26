import gmsh
gmsh.initialize()
gmsh.merge('bl_embedded_1.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','5')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1/10)

gmsh.plugin.run('BoundaryLayer')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
