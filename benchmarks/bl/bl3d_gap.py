import gmsh

# Boundary layers on a blade and on the casing above it, with a tip gap thinner
# than twice their thickness: the layers are reduced to a third of the gap
# each, with the first layer kept at its requested height.

g = 0.03 # tip gap
t = 0.02 # thickness of the layers

gmsh.initialize()
box = gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
blade = gmsh.model.occ.addBox(0.3, 0.4, 0, 0.4, 0.2, 1 - g)
gmsh.model.occ.cut([(3, box)], [(3, blade)])
gmsh.model.occ.synchronize()

# walls: the sides and the tip of the blade, and the casing (z = 1)
eps = 1e-6
walls = []
for dim, tag in gmsh.model.getEntities(2):
    xmin, ymin, zmin, xmax, ymax, zmax = gmsh.model.getBoundingBox(dim, tag)
    on_blade = (xmin > 0.3 - eps and xmax < 0.7 + eps and
                ymin > 0.4 - eps and ymax < 0.6 + eps and zmax > eps)
    on_casing = zmin > 1 - eps
    if on_blade or on_casing:
        walls.append(tag)

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.05)
gmsh.model.mesh.generate(3)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', ','.join(map(str, walls)))
gmsh.plugin.setString('BoundaryLayer', 'Volumes', '1')
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', t)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', t / 20)
gmsh.plugin.setNumber('BoundaryLayer', 'Ratio', 1.3)
gmsh.plugin.setNumber('BoundaryLayer', 'SmoothingLayers', 4)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
