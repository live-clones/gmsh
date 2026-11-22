import gmsh
import sys

# isInside() on a surface checks that the point is on the surface, not only
# that its projection is inside the surface (#3384)

gmsh.initialize(sys.argv)
errors = []


def check(what, point, expected):
    found = [t for _, t in gmsh.model.getEntities(2)
             if gmsh.model.isInside(2, t, point)]
    if found != expected:
        errors.append("%s: point %s is in surfaces %s instead of %s" %
                      (what, point, found, expected))


# OpenCASCADE: a box (top surface 6) and a sphere (surface 7)
gmsh.model.add("occ")
gmsh.model.occ.addBox(0, 0, 0, 2, 1, 0.5)
gmsh.model.occ.addSphere(10, 0, 0, 1)
gmsh.model.occ.synchronize()
check("OpenCASCADE", [0.1, 0.1, 0.5], [6])
check("OpenCASCADE", [0, 0.5, 0.5], [1, 6])  # on an edge of the box
check("OpenCASCADE", [3, 0.5, 0.5], [])  # in the plane of the top surface
check("OpenCASCADE", [11, 0, 0], [7])
check("OpenCASCADE", [11.1, 0, 0], [])

# built-in kernel: an extruded box (plane top surface 26)
gmsh.model.add("geo")
p = [gmsh.model.geo.addPoint(x, y, 0) for x, y in [(0, 0), (2, 0), (2, 1), (0, 1)]]
l = [gmsh.model.geo.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
s = gmsh.model.geo.addPlaneSurface([gmsh.model.geo.addCurveLoop(l)])
gmsh.model.geo.extrude([(2, s)], 0, 0, 0.5)
gmsh.model.geo.synchronize()
check("built-in", [1, 0.5, 0.5], [26])
check("built-in", [1, 0.5, 0.52], [])

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
