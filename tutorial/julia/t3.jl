# See the corresponding Python tutorial for detailed comments.

import gmsh

gmsh.initialize()

gmsh.model.add("t3")

lc = 1e-2
gmsh.model.geo.addPoint(0, 0, 0, lc, 1)
gmsh.model.geo.addPoint(.1, 0,  0, lc, 2)
gmsh.model.geo.addPoint(.1, .3, 0, lc, 3)
gmsh.model.geo.addPoint(0, .3, 0, lc, 4)
gmsh.model.geo.addLine(1, 2, 1)
gmsh.model.geo.addLine(3, 2, 2)
gmsh.model.geo.addLine(3, 4, 3)
gmsh.model.geo.addLine(4, 1, 4)
gmsh.model.geo.addCurveLoop([4, 1, -2, 3], 1)
gmsh.model.geo.addPlaneSurface([1], 1)
gmsh.model.geo.synchronize()
gmsh.model.addPhysicalGroup(0, [1, 2], 1)
gmsh.model.addPhysicalGroup(1, [1, 2], 2)
gmsh.model.addPhysicalGroup(2, [1], 6)
gmsh.model.setPhysicalName(2, 6, "My surface")

h = 0.1
angle = 90.

ov = gmsh.model.geo.extrude([(2,1)], 0, 0, h, [8,2], [0.5,1])

ov = gmsh.model.geo.revolve([(2,28)], -0.1,0,0.1, 0,1,0, -pi/2, [7])
ov = gmsh.model.geo.twist([(2,50)], 0,0.15,0.25, -2*h,0,0, 1,0,0,
                          angle*pi/180., [10], [], true)

gmsh.model.geo.synchronize()

gmsh.model.addPhysicalGroup(3, [1, 2, ov[2][2]], 101)

gmsh.model.mesh.generate(3)
gmsh.write("t3.msh")

if !("-nopopup" in ARGS)
    gmsh.fltk.run()
end

gmsh.finalize()
