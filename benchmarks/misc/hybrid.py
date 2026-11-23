import gmsh
import sys

# A hex-dominant mesh with the options of -hybrid (Mesh.Algorithm3D = 9): a box
# with a cubic notch, with hexahedra and no inverted element, whose volume the
# elements fill: up to the gaps that the trihedra close between a quadrangular
# face that is not flat and the two triangles of the tetrahedra on its other
# side, each at most half the volume of the tetrahedron of its 4 nodes.

gmsh.initialize(sys.argv)
build = gmsh.option.getString("General.BuildOptions")
if "OpenCASCADE" not in build or "DomHex" not in build or "Hxt" not in build:
    print("Skipped: needs OpenCASCADE, DomHex and Hxt")
    gmsh.finalize()
    sys.exit(77)

gmsh.model.add("hybrid")
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1, 1)
gmsh.model.occ.addBox(0.6, 0.6, 0.6, 0.4, 0.4, 0.4, 2)
gmsh.model.occ.cut([(3, 1)], [(3, 2)])
gmsh.model.occ.synchronize()

# the options set by -hybrid
gmsh.option.setNumber("Mesh.Recombine3DAll", 1)
gmsh.option.setNumber("Mesh.Algorithm3D", 9)
gmsh.option.setNumber("Mesh.Algorithm", 9)
gmsh.option.setNumber("Mesh.RecombineAll", 1)
gmsh.option.setNumber("Mesh.MeshSizeExtendFromBoundary", 0)
gmsh.option.setNumber("Mesh.Recombine3DPrisms", 1)
gmsh.option.setNumber("Mesh.Recombine3DPyramids", 1)
gmsh.option.setNumber("Mesh.Smoothing", 3)
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.1)
gmsh.model.mesh.generate(3)

ok = True
counts = {}
volume = 0.
minSICN = 1.
for t, name in ((4, "tetrahedra"), (5, "hexahedra"), (6, "prisms"),
                (7, "pyramids")):
    tags, _ = gmsh.model.mesh.getElementsByType(t)
    counts[name] = len(tags)
    if len(tags):
        volume += sum(abs(v) for v in
                      gmsh.model.mesh.getElementQualities(tags, "volume"))
        minSICN = min(minSICN, min(
            gmsh.model.mesh.getElementQualities(tags, "minSICN")))
gaps = 0.
tags, nodes = gmsh.model.mesh.getElementsByType(140)  # trihedra
coord = {}
nt, nc, _ = gmsh.model.mesh.getNodes()
for i, t in enumerate(nt):
    coord[t] = nc[3 * i:3 * i + 3]
for i in range(len(tags)):
    p = [coord[n] for n in nodes[4 * i:4 * i + 4]]
    a, b, c = [[p[j][k] - p[0][k] for k in range(3)] for j in (1, 2, 3)]
    gaps += abs(a[0] * (b[1] * c[2] - b[2] * c[1]) -
                a[1] * (b[0] * c[2] - b[2] * c[0]) +
                a[2] * (b[0] * c[1] - b[1] * c[0])) / 12.
counts["trihedra"] = len(tags)
print(counts)
print("volume {:.12f} (gaps at most {:.6f}), smallest SICN {:.4f}".format(
    volume, gaps, minSICN))
if counts["hexahedra"] == 0:
    print("FAILED: no hexahedra")
    ok = False
if abs(volume - (1 - 0.4**3)) > gaps + 1e-9:
    print("FAILED: the elements do not fill the volume")
    ok = False
if minSICN <= 0:
    print("FAILED: inverted elements")
    ok = False

gmsh.finalize()
if not ok:
    sys.exit(1)
