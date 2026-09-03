import gmsh
l = 8.e-2
gmsh.initialize()
gmsh.model.occ.addBox(0,0,0, 1,1,1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)

gmsh.plugin.setString('BoundaryLayer','Surfaces','1,2,3,5,6')
gmsh.plugin.setString('BoundaryLayer','Volumes','1')
gmsh.plugin.setNumber('BoundaryLayer','Thickness',1/40.)
gmsh.plugin.setNumber('BoundaryLayer','Size',1/400.)

gmsh.plugin.run('BoundaryLayer')

gmsh.option.setNumber('Geometry.SurfaceLabels',1);
gmsh.option.setNumber('Geometry.PointLabels',1);
gmsh.option.setNumber('Geometry.CurveLabels',1);


#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
