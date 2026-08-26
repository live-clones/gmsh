import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.merge('CubeHex.geo')
#gmsh.option.setNumber('Mesh.MeshSizeFactor',.05);
gmsh.model.mesh.generate(3)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1,2,3,4,5,6')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness', .2)
gmsh.plugin.setNumber('BoundaryLayer','Size',.01)

gmsh.plugin.run('BoundaryLayer')


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
