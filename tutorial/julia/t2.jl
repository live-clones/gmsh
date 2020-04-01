# See the corresponding Python tutorial for detailed comments.

import gmsh

model = gmsh.model
factory = model.geo

gmsh.initialize(ARGS)

gmsh.option.setNumber("General.Terminal", 1)

model.add("t2")

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

factory.addPoint(0, .4, 0, lc, 5)
factory.addLine(4, 5, 5)

factory.translate([(0, 5)], -0.02, 0, 0)
factory.rotate([(0, 5)], 0,0.3,0, 0,0,1, -pi/4)

ov = factory.copy([(0, 3)])
factory.translate(ov, 0, 0.05, 0)

factory.addLine(3, ov[1][2], 7)
factory.addLine(ov[1][2], 5, 8)
factory.addCurveLoop([5,-8,-7,3], 10)
factory.addPlaneSurface([10], 11)

ov = factory.copy([(2, 1), (2, 11)])
factory.translate(ov, 0.12, 0, 0)

println("New surfaces ", ov[1][2], " and ", ov[2][2])

factory.addPoint(0., 0.3, 0.12, lc, 100)
factory.addPoint(0.1, 0.3, 0.12, lc, 101)
factory.addPoint(0.1, 0.35, 0.12, lc, 102)

factory.synchronize()
xyz = model.getValue(0, 5, [])
factory.addPoint(xyz[1], xyz[2], 0.12, lc, 103)

factory.addLine(4, 100, 110)
factory.addLine(3, 101, 111)
factory.addLine(6, 102, 112)
factory.addLine(5, 103, 113)
factory.addLine(103, 100, 114)
factory.addLine(100, 101, 115)
factory.addLine(101, 102, 116)
factory.addLine(102, 103, 117)

factory.addCurveLoop([115, -111, 3, 110], 118)
factory.addPlaneSurface([118], 119)
factory.addCurveLoop([111, 116, -112, -7], 120)
factory.addPlaneSurface([120], 121)
factory.addCurveLoop([112, 117, -113, -8], 122)
factory.addPlaneSurface([122], 123)
factory.addCurveLoop([114, -110, 5, 113], 124)
factory.addPlaneSurface([124], 125)
factory.addCurveLoop([115, 116, 117, 114], 126)
factory.addPlaneSurface([126], 127)

factory.addSurfaceLoop([127, 119, 121, 123, 125, 11], 128)
factory.addVolume([128], 129)

ov2 = factory.extrude([ov[2]], 0, 0, 0.12)

factory.mesh.setSize([(0,103), (0,105), (0,109), (0,102), (0,28),
                      (0, 24), (0,6), (0,5)], lc * 3)

model.addPhysicalGroup(3, [129,130], 1)
model.setPhysicalName(3, 1, "The volume")

factory.synchronize()

model.mesh.generate(3)

gmsh.write("t2.msh")

gmsh.finalize()
