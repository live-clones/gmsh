import gmsh
import sys

# The ghost cells of a partitioned mesh follow its elements when the mesh is
# changed after partitioning: they are kept when the order of the elements is
# changed (with the partition of the elements, lines included) or when the
# elements are renumbered, and those of the elements removed are dropped
# (they used to refer to deleted elements)

gmsh.initialize(sys.argv)
errors = []

gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1)
gmsh.model.occ.synchronize()
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.3)
gmsh.model.mesh.generate(3)
gmsh.option.setNumber("Mesh.PartitionCreateGhostCells", 1)
gmsh.model.mesh.partition(3)


def ghosts():
    # the ghost cells of each partition, by the barycentre of their primary
    # nodes, with their partition and dimension
    r = []
    for p in (1, 2, 3):
        tags, parts = gmsh.model.mesh.getGhostElements(p)
        for e, q in zip(tags, parts):
            t, nodes, dim, tag = gmsh.model.mesh.getElement(e)
            n = gmsh.model.mesh.getElementProperties(t)[5]
            x = [gmsh.model.mesh.getNode(v)[0] for v in nodes[:n]]
            r.append((p, tuple(round(sum(c[i] for c in x) / n, 9)
                               for i in range(3)), int(q), dim))
    return sorted(r)


g = ghosts()
if not g:
    errors.append("no ghost cells after partitioning")

for order in (2, 1, 3):
    gmsh.model.mesh.setOrder(order)
    if ghosts() != g:
        errors.append("ghost cells changed by setOrder(%d)" % order)
gmsh.model.mesh.setOrder(1)

gmsh.model.mesh.renumberElements()
if ghosts() != g:
    errors.append("ghost cells changed by renumberElements()")

# the mesh of one partition volume removed
volumes = [e for e in gmsh.model.getEntities(3)
           if gmsh.model.getType(*e) == "Partition volume"]
gmsh.model.mesh.clear(volumes[:1])
elements = set()
for dim, tag in gmsh.model.getEntities():
    for tags in gmsh.model.mesh.getElements(dim, tag)[1]:
        elements.update(int(t) for t in tags)
left = 0
for p in (1, 2, 3):
    for e in gmsh.model.mesh.getGhostElements(p)[0]:
        left += 1
        if int(e) not in elements:
            errors.append("ghost cell %d is not an element any more" % e)
            break
if not left or left >= len(g):
    errors.append("%d ghost cells left of %d after removing the mesh of a "
                  "volume" % (left, len(g)))

gmsh.finalize()

for e in errors:
    print("Error:", e)
sys.exit(1 if errors else 0)
