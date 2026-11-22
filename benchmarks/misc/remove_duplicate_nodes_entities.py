import gmsh
import sys

# Removing the duplicate nodes of some entities replaces them in the elements
# of all the entities, e.g. in the tets of the volumes on both sides of the
# surfaces whose nodes are merged (#3462)

gmsh.initialize(sys.argv)

# two boxes sharing a face, not fused: their surfaces 2 and 7 are at x = 1
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.addBox(1, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.model.mesh.setPeriodic(2, [2], [7],
                            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1])
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.5)
gmsh.model.mesh.generate(3)

surfaces = [(2, 2), (2, 7)]
curves = gmsh.model.getBoundary(surfaces, oriented=False)
points = gmsh.model.getBoundary(surfaces, oriented=False, recursive=True)
for dimTags in [surfaces, curves, points]:
    gmsh.model.mesh.removeDuplicateNodes(dimTags)

errors = []
if len(gmsh.model.mesh.getDuplicateNodes()):
    errors.append("duplicate nodes left")
tags, coord, _ = gmsh.model.mesh.getNodes()
nodes = set(tags)
for dim in range(4):
    for nodeTags in gmsh.model.mesh.getElements(dim)[2]:
        unknown = [n for n in nodeTags if n not in nodes]
        if unknown:
            errors.append("elements of dimension %d use %d unknown nodes" %
                          (dim, len(unknown)))

# the tets on both sides of x = 1 use the same nodes there
x = dict(zip(tags, coord[0::3]))
used = []
for v in [1, 2]:
    s = set()
    for nodeTags in gmsh.model.mesh.getElements(3, v)[2]:
        s.update(n for n in nodeTags if abs(x[n] - 1) < 1e-12)
    used.append(s)
if not used[0] or used[0] != used[1]:
    errors.append("volumes 1 and 2 do not share their nodes at x = 1")

gmsh.finalize()

if errors:
    print("\n".join(errors))
    sys.exit(1)
print("OK")
