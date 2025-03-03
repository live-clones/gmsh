import gmsh
import sys

gmsh.initialize(sys.argv)

# this example shows how alternative non-plane geometries can be used in the
# built-in kernel; here using a parametric surface

g=gmsh.model.geo.addGeometry("ParametricSurface", strings=["u", "v", "v^2"])

p1=gmsh.model.geo.addPointOnGeometry(g, 0,0,0,tag=1)
p2=gmsh.model.geo.addPointOnGeometry(g, 1,0,0,tag=2)
p3=gmsh.model.geo.addPointOnGeometry(g, 1,1,0,tag=3)
p4=gmsh.model.geo.addPointOnGeometry(g, 0,1,0,tag=4)

l1=gmsh.model.geo.addLine(p1, p2)
l2=gmsh.model.geo.addLine(p2, p3)
l3=gmsh.model.geo.addLine(p3, p4)
l4=gmsh.model.geo.addLine(p4, p1)

cl = gmsh.model.geo.addCurveLoop([l1, l2, l3, l4])
gmsh.model.geo.addPlaneSurface([cl])
gmsh.model.geo.synchronize()

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
