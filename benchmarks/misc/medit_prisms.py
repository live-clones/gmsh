import gmsh
import os
import sys
import tempfile

# Prisms are saved in and read from Medit files (#3169); the order of the
# triangles and tetrahedra is found even when the first surfaces and volumes
# have none (it crashed)

gmsh.initialize(sys.argv)
errors = []
d = tempfile.mkdtemp()
f = os.path.join(d, "prisms.mesh")


def counts():
    out = {}
    for dim in (2, 3):
        for t, e in zip(*gmsh.model.mesh.getElements(dim)[:2]):
            out[gmsh.model.mesh.getElementProperties(t)[0]] = len(e)
    vol = sum(sum(gmsh.model.mesh.getElementQualities(e, "volume"))
              for e in gmsh.model.mesh.getElements(3)[1])
    return out, round(vol, 9)


# a recombined extrusion of a triangulated square (prisms, quadrangles on the
# sides), and a box of tetrahedra on top of it
s = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.extrude([(2, s)], 0, 0, 1, numElements=[4], recombine=True)
gmsh.model.occ.addBox(0, 0, 1, 1, 1, 1)
gmsh.model.occ.fragment([(3, 1)], [(3, 2)])
gmsh.model.occ.synchronize()
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.3)
gmsh.model.mesh.generate(3)
before = counts()
gmsh.write(f)
gmsh.clear()
gmsh.open(f)
after = counts()
if after != before or "Prism 6" not in after[0]:
    errors.append("read back %s instead of %s" % (after, before))
if after[1] != 2.0:
    errors.append("volume %g instead of 2" % after[1])

# 18-node prisms are saved as PrismsP2, with the node ordering of libMeshb
# (edges of the bottom and top triangles, vertical edges, faces), and read back
# with the same nodes, the edge nodes at the middle of their edge
gmsh.clear()
s = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.extrude([(2, s)], 0, 0, 1, numElements=[2], recombine=True)
gmsh.model.occ.synchronize()
gmsh.model.mesh.generate(3)
gmsh.model.mesh.setOrder(2)
before = counts()
gmsh.write(f)
if " PrismsP2\n" not in open(f).read():
    errors.append("no PrismsP2 section")
gmsh.clear()
gmsh.open(f)
after = counts()
if after != before or "Prism 18" not in after[0]:
    errors.append("read back %s instead of %s" % (after, before))
tags, coord, _ = gmsh.model.mesh.getNodes()
xyz = {t: coord[3 * i:3 * i + 3] for i, t in enumerate(tags)}
edges = [(0, 1), (0, 2), (0, 3), (1, 2), (1, 4), (2, 5), (3, 4), (3, 5), (4, 5)]
for t, e, n in zip(*gmsh.model.mesh.getElements(3)):
    for i in range(len(e)):
        p = [xyz[k] for k in n[18 * i:18 * i + 18]]
        for j, (a, b) in enumerate(edges):
            if max(abs(p[6 + j][k] - (p[a][k] + p[b][k]) / 2)
                   for k in range(3)) > 1e-12:
                errors.append("node %d of prism %d not on edge (%d, %d)" %
                              (6 + j, e[i], a, b))

gmsh.finalize()
os.remove(f)
os.rmdir(d)

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
