# Polygons and polyhedra in Gmsh: a triangular mesh of a disk is agglomerated
# into polygons, whose sub-triangulation is the original triangles, and a
# hexagonal prism is built by hand as a polyhedron

import gmsh
import sys
import math

gmsh.initialize(sys.argv)

gmsh.model.add("disk")
gmsh.model.occ.addDisk(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.1)
gmsh.model.mesh.generate(2)

# The triangles are grouped by the cell of a coarse grid holding their
# barycenter; each group becomes a polygon if its boundary is a single loop
nodeTags, coord, _ = gmsh.model.mesh.getNodes()
xyz = {nodeTags[i]: coord[3 * i:3 * i + 3] for i in range(len(nodeTags))}
triTags, triNodes = gmsh.model.mesh.getElementsByType(2)
h = 0.3
groups = {}
for i in range(len(triTags)):
    n = triNodes[3 * i:3 * i + 3]
    bx = sum(xyz[k][0] for k in n) / 3
    by = sum(xyz[k][1] for k in n) / 3
    groups.setdefault((math.floor(bx / h), math.floor(by / h)), []).append(n)

def boundary(triangles):
    # the boundary of a set of consistently oriented triangles, as an ordered
    # loop of nodes, or None if it is not a single loop
    count = {}
    for n in triangles:
        for a, b in ((n[0], n[1]), (n[1], n[2]), (n[2], n[0])):
            count[(a, b)] = count.get((a, b), 0) + 1
    nxt = {}
    for (a, b), c in count.items():
        if c == 1 and (b, a) not in count:
            if a in nxt: return None
            nxt[a] = b
    if not nxt: return None
    loop = [next(iter(nxt))]
    while True:
        b = nxt.get(loop[-1])
        if b is None: return None
        if b == loop[0]: break
        loop.append(b)
    return loop if len(loop) == len(nxt) else None

gmsh.model.add("polygons")
s = gmsh.model.addDiscreteEntity(2)
gmsh.model.mesh.addNodes(2, s, nodeTags, coord)
polyNodes, polyNumNodes, simplices, numSimplices = [], [], [], []
leftover = []
for triangles in groups.values():
    loop = boundary(triangles)
    if loop is None:
        leftover += [k for n in triangles for k in n]
        continue
    polyNodes += loop
    polyNumNodes.append(len(loop))
    simplices += [k for n in triangles for k in n]
    numSimplices.append(len(triangles))
gmsh.model.mesh.addPolygons(s, [], polyNodes, polyNumNodes)
tags, _, _ = gmsh.model.mesh.getPolygons(s)
# the original triangles are the sub-triangulation of the polygons, so that
# the interior nodes of each group stay part of the mesh
gmsh.model.mesh.setPolytopeSimplices(tags, numSimplices, simplices)
# groups that could not be turned into polygons stay triangles
if leftover:
    gmsh.model.mesh.addElementsByType(s, 2, [], leftover)
print("Agglomerated", len(triTags), "triangles into", len(tags), "polygons")
gmsh.write("polygons.msh")

# A hexagonal prism, given by the nodes of its 8 faces
gmsh.model.add("prism")
r = gmsh.model.addDiscreteEntity(3)
pts, tags = [], []
for k in range(2):
    for i in range(6):
        pts += [math.cos(i * math.pi / 3), math.sin(i * math.pi / 3), k]
        tags.append(6 * k + i + 1)
gmsh.model.mesh.addNodes(3, r, tags, pts)
bottom = [6, 5, 4, 3, 2, 1]
top = [7, 8, 9, 10, 11, 12]
sides = [[i + 1, (i + 1) % 6 + 1, (i + 1) % 6 + 7, i + 7] for i in range(6)]
faces = bottom + top + [k for f in sides for k in f]
gmsh.model.mesh.addPolyhedra(r, [], [8], [6, 6] + [4] * 6, faces)
# without a given sub-tetrahedralization, Gmsh computes one when needed (here
# for the volume), and saves it only if asked for
gmsh.plugin.setNumber("MeshVolume", "Dimension", 3)
gmsh.plugin.run("MeshVolume")
gmsh.model.mesh.createPolytopeSimplices()
gmsh.write("prism.msh")

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
