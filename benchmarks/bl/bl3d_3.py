import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.merge('bl3d_3.brep')
gmsh.option.setNumber('Mesh.MeshSizeFactor',.1);
gmsh.model.mesh.generate(3)


gmsh.plugin.setString('BoundaryLayer','Surfaces','7,8,9,10')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1/20.)
gmsh.plugin.setNumber('BoundaryLayer','Size',1.e-5)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',2.)
gmsh.plugin.setNumber('BoundaryLayer','SmoothingLayers',2.)

gmsh.plugin.run('BoundaryLayer')

gmsh.option.setNumber('Geometry.SurfaceLabels',1)
gmsh.option.setNumber('Geometry.PointLabels',1)
gmsh.option.setNumber('Geometry.CurveLabels',1)


gmsh.write("wtf.msh")

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
