# See the corresponding Python tutorial for detailed comments.

import gmsh

gmsh.initialize()

lc = 1e-2

gmsh.model.geo.addPoint(0, 0, 0, lc, 1)
gmsh.model.geo.addPoint(.1, 0, 0, lc, 2)
gmsh.model.geo.addPoint(.1, .3, 0, lc, 3)
gmsh.model.geo.addPoint(0, .3, 0, lc, 4)
gmsh.model.geo.addLine(1, 2, 1)
gmsh.model.geo.addLine(3, 2, 2)
gmsh.model.geo.addLine(3, 4, 3)
gmsh.model.geo.addLine(4, 1, 4)
gmsh.model.geo.addCurveLoop([4, 1, -2, 3], 1)
gmsh.model.geo.addPlaneSurface([1], 1)

lc = lc * 4

gmsh.model.geo.mesh.setSize([(0, 1), (0, 2), (0, 3), (0, 4)], lc)

gmsh.model.geo.addPoint(0.02, 0.02, 0., lc, 5)

gmsh.model.geo.synchronize()

gmsh.model.mesh.embed(0, [5], 2, 1)

gmsh.model.geo.addPoint(0.02, 0.12, 0., lc, 6)
gmsh.model.geo.addPoint(0.04, 0.18, 0., lc, 7)
gmsh.model.geo.addLine(6, 7, 5)

gmsh.model.geo.synchronize()
gmsh.model.mesh.embed(1, [5], 2, 1)

gmsh.model.geo.extrude([(2, 1)], 0, 0, 0.1)

p = gmsh.model.geo.addPoint(0.07, 0.15, 0.025, lc)

gmsh.model.geo.synchronize()
gmsh.model.mesh.embed(0, [p], 3, 1)

gmsh.model.geo.addPoint(0.025, 0.15, 0.025, lc, p + 1)
l = gmsh.model.geo.addLine(7, p + 1)

gmsh.model.geo.synchronize()
gmsh.model.mesh.embed(1, [l], 3, 1)

gmsh.model.geo.addPoint(0.02, 0.12, 0.05, lc, p + 2)
gmsh.model.geo.addPoint(0.04, 0.12, 0.05, lc, p + 3)
gmsh.model.geo.addPoint(0.04, 0.18, 0.05, lc, p + 4)
gmsh.model.geo.addPoint(0.02, 0.18, 0.05, lc, p + 5)

gmsh.model.geo.addLine(p + 2, p + 3, l + 1)
gmsh.model.geo.addLine(p + 3, p + 4, l + 2)
gmsh.model.geo.addLine(p + 4, p + 5, l + 3)
gmsh.model.geo.addLine(p + 5, p + 2, l + 4)

ll = gmsh.model.geo.addCurveLoop([l + 1, l + 2, l + 3, l + 4])
s = gmsh.model.geo.addPlaneSurface([ll])

gmsh.model.geo.synchronize()
gmsh.model.mesh.embed(2, [s], 3, 1)

gmsh.model.mesh.generate(3)

gmsh.write("t15.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
