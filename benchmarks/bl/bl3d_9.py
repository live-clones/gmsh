import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.merge('CubeHex2.geo')
#gmsh.option.setNumber('Mesh.MeshSizeFactor',.05);
gmsh.model.mesh.generate(3)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness', .1)
gmsh.plugin.setNumber('BoundaryLayer','Size',.001)
gmsh.plugin.setNumber('BoundaryLayer','SmoothingLayers',3)


gmsh.plugin.run('BoundaryLayer')


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
