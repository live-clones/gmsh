import gmsh

# Boundary layers on both sides of a curve embedded in a surface: at the two
# ends of the curve the layers are pinched, i.e. they taper to zero thickness
# and end with triangles.

gmsh.initialize()
r = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
l = gmsh.model.occ.addLine(gmsh.model.occ.addPoint(0.3, 0.5, 0),
                           gmsh.model.occ.addPoint(0.7, 0.5, 0))
gmsh.model.occ.synchronize()
gmsh.model.mesh.embed(1, [l], 2, r)

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.05)
gmsh.model.mesh.generate(2)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', str(r))
gmsh.plugin.setString('BoundaryLayer', 'Curves', str(l))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', 0.03)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', 0.003)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
