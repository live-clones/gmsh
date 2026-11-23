import gmsh
import sys

# Plugin(NonConformalRefinement) and Plugin(DualMesh) on a box meshed with
# hexahedra (extruded) and tetrahedra: the refined mesh and the dual mesh fill
# the same volume and have the same boundary area as the mesh they come from;
# the dual mesh has one polyhedron for each node of each volume.

gmsh.initialize(sys.argv)


def node_coordinates():
    tags, coord, _ = gmsh.model.mesh.getNodes()
    return {t: coord[3 * i:3 * i + 3] for i, t in enumerate(tags)}


def triangle_area(a, b, c):
    u = [b[k] - a[k] for k in range(3)]
    v = [c[k] - a[k] for k in range(3)]
    n = [u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2],
         u[0] * v[1] - u[1] * v[0]]
    return 0.5 * (n[0]**2 + n[1]**2 + n[2]**2)**0.5


def tet_volume(a, b, c, d):
    u, v, w = [[p[k] - a[k] for k in range(3)] for p in (b, c, d)]
    return abs(u[0] * (v[1] * w[2] - v[2] * w[1]) -
               u[1] * (v[0] * w[2] - v[2] * w[0]) +
               u[2] * (v[0] * w[1] - v[1] * w[0])) / 6.


# the volume of the elements and the area of the boundary elements, the
# polytopes through their simplices, and the number of polyhedra
def measure():
    x = node_coordinates()
    volume, area = 0., 0.
    for t in (4, 5, 6, 7):
        tags, _ = gmsh.model.mesh.getElementsByType(t)
        if len(tags):
            volume += sum(abs(v) for v in
                          gmsh.model.mesh.getElementQualities(tags, "volume"))
    for t in (2, 3):
        _, nodes = gmsh.model.mesh.getElementsByType(t)
        n = 3 if t == 2 else 4
        for i in range(0, len(nodes), n):
            p = [x[v] for v in nodes[i:i + n]]
            area += triangle_area(p[0], p[1], p[2])
            if n == 4:
                area += triangle_area(p[0], p[2], p[3])
    polyhedra = 0
    for t, n in ((34, 3), (35, 4)):
        tags, _, nodes, _ = gmsh.model.mesh.getPolytopeSimplices(t)
        if t == 35:
            polyhedra = len(tags)
        for i in range(0, len(nodes), n):
            p = [x[v] for v in nodes[i:i + n]]
            if n == 3:
                area += triangle_area(p[0], p[1], p[2])
            else:
                volume += tet_volume(p[0], p[1], p[2], p[3])
    return volume, area, polyhedra


def make_mesh():
    gmsh.clear()
    gmsh.model.add("box")
    # a box of hexahedra, extruded from a square of quadrangles, next to a box
    # of tetrahedra
    p = [gmsh.model.geo.addPoint(x, y, 0) for x, y in ((0, 0), (1, 0),
                                                       (1, 1), (0, 1))]
    c = [gmsh.model.geo.addLine(p[i], p[(i + 1) % 4]) for i in range(4)]
    s = gmsh.model.geo.addPlaneSurface([gmsh.model.geo.addCurveLoop(c)])
    gmsh.model.geo.mesh.setTransfiniteSurface(s)
    for l in c:
        gmsh.model.geo.mesh.setTransfiniteCurve(l, 5)
    gmsh.model.geo.mesh.setRecombine(2, s)
    top = gmsh.model.geo.extrude([(2, s)], 0, 0, 1, [4], recombine=True)
    gmsh.model.geo.extrude([top[0]], 0, 0, 1)
    gmsh.model.geo.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", 0.3)
    gmsh.model.mesh.generate(3)


ok = True


def check(what, good):
    global ok
    print("{}: {}".format(what, "OK" if good else "FAILED"))
    ok = ok and good


make_mesh()
volume, area, _ = measure()
print("mesh: volume {:.12f}, area {:.12f}".format(volume, area))
check("the mesh fills the boxes", abs(volume - 2) < 1e-9)

# refined in a band around the plane z = 1
gmsh.model.mesh.field.add("MathEval", 1)
gmsh.model.mesh.field.setString(1, "F", "0.05 + Abs(z - 1)")
gmsh.plugin.setNumber("NonConformalRefinement", "SizeField", 1)
gmsh.plugin.setNumber("NonConformalRefinement", "MaxLevel", 3)
n0 = len(gmsh.model.mesh.getNodes()[0])
gmsh.plugin.run("NonConformalRefinement")
v, a, _ = measure()
n1 = len(gmsh.model.mesh.getNodes()[0])
print("refined: {} -> {} nodes, volume {:.12f}, area {:.12f}".format(
    n0, n1, v, a))
check("the refinement adds nodes", n1 > n0)
check("the refined mesh fills the same volume", abs(v - volume) < 1e-9)
check("the refined mesh has the same boundary area", abs(a - area) < 1e-9)

# the dual of the original mesh (the nodes of each volume, those on the face
# between the two boxes counting twice)
make_mesh()
n0 = 0
for dim, tag in gmsh.model.getEntities(3):
    _, _, nodes = gmsh.model.mesh.getElements(dim, tag)
    n0 += len(set(n for block in nodes for n in block))
gmsh.plugin.run("DualMesh")
v, a, polyhedra = measure()
print("dual: {} polyhedra for {} nodes, volume {:.12f}, area {:.12f}".format(
    polyhedra, n0, v, a))
check("the dual has one polyhedron per node of each volume", polyhedra == n0)
check("the dual fills the same volume", abs(v - volume) < 1e-9)
check("the dual has the same boundary area", abs(a - area) < 1e-9)

gmsh.finalize()
if not ok:
    sys.exit(1)
