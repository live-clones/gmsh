import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.merge('bl3d_5.brep')
gmsh.option.setNumber('Mesh.MeshSizeFactor',.05);
gmsh.model.mesh.generate(3)


gmsh.plugin.setString('BoundaryLayer','Surfaces','7,8,9,10,23,12,13,11')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1/160.)
gmsh.plugin.setNumber('BoundaryLayer','Size',1/1600.)

gmsh.plugin.run('BoundaryLayer')

gmsh.option.setNumber('Geometry.SurfaceLabels',1);
gmsh.option.setNumber('Geometry.PointLabels',1);
gmsh.option.setNumber('Geometry.CurveLabels',1);


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
