import gmsh

# Boundary layers on both sides of a curve separating two surfaces: the curve
# ends on the boundary, where each side gets its own node sliding along it.

gmsh.initialize()
r = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
l = gmsh.model.occ.addLine(gmsh.model.occ.addPoint(0.5, 0, 0),
                           gmsh.model.occ.addPoint(0.5, 1, 0))
gmsh.model.occ.fragment([(2, r)], [(1, l)])
gmsh.model.occ.synchronize()

eps = 1e-6
surfaces = [tag for dim, tag in gmsh.model.getEntities(2)]
walls = []
for dim, tag in gmsh.model.getEntities(1):
    xmin, ymin, zmin, xmax, ymax, zmax = gmsh.model.getBoundingBox(dim, tag)
    if abs(xmin - 0.5) < eps and abs(xmax - 0.5) < eps:
        walls.append(tag)

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.05)
gmsh.model.mesh.generate(2)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', ','.join(map(str, surfaces)))
gmsh.plugin.setString('BoundaryLayer', 'Curves', ','.join(map(str, walls)))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', 0.03)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', 0.003)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
