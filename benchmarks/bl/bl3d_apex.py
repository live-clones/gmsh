import gmsh

# Boundary layer on one of the four sides of a pyramid: at the apex two curves
# leave the wall, so that no node can slide along a single one of them. The
# layers are pinched there, i.e. they taper to zero thickness.

gmsh.initialize()
g = gmsh.model.geo
p = [g.addPoint(0, 0, 0), g.addPoint(1, 0, 0), g.addPoint(1, 1, 0),
     g.addPoint(0, 1, 0), g.addPoint(0.5, 0.5, 1)]
base = [g.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
up = [g.addLine(p[i], p[4]) for i in range(4)]
s = [g.addPlaneSurface([g.addCurveLoop(base)])]
for i in range(4):
    s.append(g.addPlaneSurface(
        [g.addCurveLoop([base[i], up[(i + 1) % 4], -up[i]])]))
v = g.addVolume([g.addSurfaceLoop(s)])
g.synchronize()

gmsh.option.setNumber('Mesh.MeshSizeMax', 0.1)
gmsh.model.mesh.generate(3)

gmsh.plugin.setString('BoundaryLayer', 'Surfaces', str(s[1]))
gmsh.plugin.setString('BoundaryLayer', 'Volumes', str(v))
gmsh.plugin.setNumber('BoundaryLayer', 'Thickness', 0.03)
gmsh.plugin.setNumber('BoundaryLayer', 'Size', 0.003)
gmsh.plugin.run('BoundaryLayer')

gmsh.fltk.run()
