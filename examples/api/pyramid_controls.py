import gmsh
import sys

# orientation of the interface quadrangles: their normal points toward the
# hexahedra, i.e. away from the tetrahedra (pushed the wrong way before the fix)
normal_toward_hexahedras = True

gmsh.initialize()

# a recombined square, extruded in a layer of hexahedra...
p = [gmsh.model.geo.addPoint(x, y, 0) for x, y in [(0, 0), (1, 0), (1, 1), (0, 1)]]
l = [gmsh.model.geo.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
s = gmsh.model.geo.addPlaneSurface([gmsh.model.geo.addCurveLoop(l)])
for c in l:
    gmsh.model.geo.mesh.setTransfiniteCurve(c, 4)
gmsh.model.geo.mesh.setTransfiniteSurface(s)
gmsh.model.geo.mesh.setRecombine(2, s)
top = gmsh.model.geo.extrude([(2, s)], 0, 0, 1, [3], recombine=True)[0]

# ...and a volume of tetrahedra on one side of the interface, whose
# quadrangles get pyramids
if normal_toward_hexahedras:
    gmsh.model.geo.extrude([(2, s)], 0, 0, -1)
else:
    gmsh.model.geo.extrude([top], 0, 0, 1)
gmsh.model.geo.synchronize()

# a negative value places the apex of each pyramid at that fraction of the
# quadrangle diagonal from its center, on the side of the tetrahedra
gmsh.option.setNumber("Mesh.OptimizePyramids", -0.3)

gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
