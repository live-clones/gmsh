import gmsh

# Boundary layers on both sides of a surface separating two volumes: the
# surface ends on the boundary, where each side gets its own nodes sliding
# along it.

gmsh.initialize()
b = gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
r = gmsh.model.occ.addRectangle(-0.5, -0.5, 0.5, 2, 2)
gmsh.model.occ.fragment([(3, b)], [(2, r)])
gmsh.model.occ.synchronize()

# remove the parts of the rectangle outside the box
outside = [(dim, tag) for dim, tag in gmsh.model.getEntities(2)
           if not len(gmsh.model.getAdjacencies(dim, tag)[0])]
gmsh.model.removeEntities(outside, recursive=True)

volumes = [tag for dim, tag in gmsh.model.getEntities(3)]
walls = [tag for dim, tag in gmsh.model.getEntities(2)
         if len(gmsh.model.getAdjacencies(dim, tag)[0]) == 2]

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.1)
gmsh.model.mesh.generate(3)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', ','.join(map(str, walls)))
gmsh.plugin.setString('BoundaryLayer', 'Volumes', ','.join(map(str, volumes)))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', 0.05)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', 0.005)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
