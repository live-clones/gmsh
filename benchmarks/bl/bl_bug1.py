import gmsh
gmsh.initialize()
gmsh.merge('bl_bug1.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1,2')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3,4')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1.e-1)
gmsh.plugin.setNumber('BoundaryLayer','Size',1.e-1)
gmsh.plugin.setNumber('BoundaryLayer','SmoothingLayers',12.)
gmsh.plugin.run('BoundaryLayer')

#gmsh.plugin.run('BoundaryLayer')
#gmsh.plugin.run('BoundaryLayer')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
