import gmsh
gmsh.initialize()
gmsh.merge('bl3.geo')
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(2)


gmsh.plugin.setString('BoundaryLayer','Surfaces','1')
gmsh.plugin.setString('BoundaryLayer','Curves','2,3')
gmsh.plugin.setString('BoundaryLayer','Vertices','30')

width = .02

for i in range(1) :
    gmsh.plugin.setNumber('BoundaryLayer','Width',width)
    gmsh.plugin.run('BoundaryLayer')
#    gmsh.plugin.setString('BoundaryLayer','Vertices','')

#gmsh.model.mesh.optimize('UntangleTris')

gmsh.fltk.run()
