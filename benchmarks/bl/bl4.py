import gmsh
gmsh.initialize()
gmsh.merge('bl4.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3,4,5,6,7,8')
gmsh.plugin.setString('BoundaryLayer','Points','56,58')

gmsh.plugin.setNumber('BoundaryLayer','Thickness',.2)
gmsh.plugin.setNumber('BoundaryLayer','Size',.001)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',1.5)
gmsh.plugin.run('BoundaryLayer')
# gmsh.plugin.setString('BoundaryLayer','Points','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
