# See the corresponding Python tutorial for detailed comments.

import gmsh

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

model.add("t3")

lc = 1e-2
factory.addPoint(0, 0, 0, lc, 1)
factory.addPoint(.1, 0,  0, lc, 2)
factory.addPoint(.1, .3, 0, lc, 3)
factory.addPoint(0, .3, 0, lc, 4)
factory.addLine(1, 2, 1)
factory.addLine(3, 2, 2)
factory.addLine(3, 4, 3)
factory.addLine(4, 1, 4)
factory.addCurveLoop([4, 1, -2, 3], 1)
factory.addPlaneSurface([1], 1)
model.addPhysicalGroup(0, [1, 2], 1)
model.addPhysicalGroup(1, [1, 2], 2)
model.addPhysicalGroup(2, [1], 6)
model.setPhysicalName(2, 6, "My surface")

h = 0.1
angle = 90.

ov = factory.extrude([(2,1)], 0, 0, h, [8,2], [0.5,1])

ov = factory.revolve([(2,28)], -0.1,0,0.1, 0,1,0, -pi/2, [7])
ov = factory.twist([(2,50)], 0,0.15,0.25, -2*h,0,0, 1,0,0, angle*pi/180.,
                   [10], [], true)

model.addPhysicalGroup(3, [1, 2, ov[2][2]], 101)

factory.synchronize()
model.mesh.generate(3)
gmsh.write("t3.msh")
gmsh.finalize()
