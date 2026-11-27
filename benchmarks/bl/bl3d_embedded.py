import gmsh

# Boundary layers on both sides of a surface embedded in a volume: along the
# rim of the surface the layers are pinched, i.e. they taper to zero thickness
# and end with pyramids and tetrahedra.

gmsh.initialize()
b = gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
r = gmsh.model.occ.addRectangle(0.3, 0.3, 0.5, 0.4, 0.4)
gmsh.model.occ.synchronize()
gmsh.model.mesh.embed(2, [r], 3, b)

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.08)
gmsh.model.mesh.generate(3)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', str(r))
gmsh.plugin.setString('BoundaryLayer', 'Volumes', str(b))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', 1 / 40.)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', 1 / 400.)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
