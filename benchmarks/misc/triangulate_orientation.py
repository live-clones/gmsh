import gmsh
import random
import sys

# gmsh.algorithm.triangulate() returns triangles oriented counterclockwise in
# the (u, v) plane (#3095)

gmsh.initialize(sys.argv)
errors = []


def check(what, coord, edges=[]):
    tri = gmsh.algorithm.triangulate(coord, edges)
    neg = 0
    for i in range(0, len(tri), 3):
        a, b, c = [(coord[2 * (n - 1)], coord[2 * (n - 1) + 1])
                   for n in tri[i:i + 3]]
        if (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]) <= 0:
            neg += 1
    if not len(tri) or neg:
        errors.append("%s: %d of %d triangles not counterclockwise" %
                      (what, neg, len(tri) // 3))


random.seed(1)
check("random points", [random.random() for i in range(2000)])
check("grid", [v for i in range(11) for j in range(11) for v in (i / 10, j / 10)])
check("constrained", [0, 0, 1, 0, 1, 1, 0, 1, 0.5, 0.2], [1, 3])

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
