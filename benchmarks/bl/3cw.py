import gmsh
gmsh.initialize()
gmsh.option.setNumber('Mesh.MeshSizeFromCurvature', 20)
gmsh.option.setNumber('Mesh.MeshSizeExtendFromBoundary', 0)
gmsh.merge('3cw.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','16')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3,4,5,6,7')

gmsh.plugin.setNumber('BoundaryLayer','Thickness',10)
gmsh.plugin.setNumber('BoundaryLayer','Size',.3)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',1.5)
gmsh.plugin.setNumber('BoundaryLayer','SmoothingLayers',5.)
gmsh.plugin.setNumber("BoundaryLayer", "HighOrder", 2)
gmsh.plugin.run('BoundaryLayer')
# gmsh.plugin.setString('BoundaryLayer','Points','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
