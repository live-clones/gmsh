import gmsh

# Boundary layers on both sides of a gap thinner than twice their thickness: a
# channel of height 0.3 with a step that leaves a gap g to the bottom wall. The
# layers are reduced to a third of the gap each, with the first layer kept at
# its requested height.

g = 0.03 # gap
t = 0.02 # thickness of the layers

gmsh.initialize()
pts = [(0, 0), (1, 0), (1, 0.3), (0.7, 0.3), (0.7, g), (0.3, g), (0.3, 0.3),
       (0, 0.3)]
p = [gmsh.model.occ.addPoint(x, y, 0) for x, y in pts]
l = [gmsh.model.occ.addLine(p[i], p[(i + 1) % 8]) for i in range(8)]
gmsh.model.occ.addPlaneSurface([gmsh.model.occ.addCurveLoop(l)])
gmsh.model.occ.synchronize()
gmsh.model.mesh.setSize(gmsh.model.getEntities(0), 0.02)
gmsh.model.mesh.generate(2)

# walls: the bottom and the three sides of the step
walls = [l[0], l[3], l[4], l[5]]
gmsh.plugin.setString('BoundaryLayer', 'Surfaces', '1')
gmsh.plugin.setString('BoundaryLayer', 'Curves', ','.join(map(str, walls)))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', t)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', t / 20)
gmsh.plugin.setNumber('BoundaryLayer', 'Ratio', 1.3)
gmsh.plugin.setNumber('BoundaryLayer', 'SmoothingLayers', 6)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
