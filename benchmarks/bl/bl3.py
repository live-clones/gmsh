import gmsh
gmsh.initialize()
gmsh.merge('bl3.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','1,2,3')
gmsh.plugin.setString('BoundaryLayer','Points','30')

gmsh.plugin.setNumber('BoundaryLayer','Thickness',.04)
gmsh.plugin.setNumber('BoundaryLayer','Size',.0001)
gmsh.plugin.setNumber('BoundaryLayer','Ratio',1.5)
gmsh.plugin.run('BoundaryLayer')
# gmsh.plugin.setString('BoundaryLayer','Points','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
