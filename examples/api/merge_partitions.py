import gmsh
import itertools
import os
import sys

# Read the mesh of one partition of a partitioned mesh with its ghost cells,
# e.g. one per MPI rank of a parallel solver: each rank then only reads (and
# keeps in memory) its part of the mesh. The mesh is saved in one file per
# partition (`Mesh.PartitionSplitMeshFiles'), with the ghost cells of the
# partition, i.e. the elements of the other partitions, of all dimensions,
# that share a node with its elements (`Mesh.PartitionCreateGhostCells'), and
# only the entities that the partition needs (`Mesh.PartitionSplitLocalBrep').
# This checks that reading the file of partition p gives exactly the elements
# of the partition entities of p and the elements that share a node with
# them, with their nodes, entities, partitions and physical groups as in the
# whole mesh; and that merging the files of all the partitions gives the
# whole mesh back.

gmsh.initialize()

# a box with a ball inside, with physical groups of all dimensions, its mesh
# partitioned in 4
gmsh.model.add("merge_partitions")
gmsh.model.occ.addBox(0, 0, 0, 1, 1, 1, 1)
gmsh.model.occ.addSphere(0.5, 0.5, 0.5, 0.25, 2)
gmsh.model.occ.fragment([(3, 1)], [(3, 2)])
gmsh.model.occ.synchronize()
gmsh.model.addPhysicalGroup(3, [3], 10, "outer")
gmsh.model.addPhysicalGroup(3, [2], 20, "inner")
bottom = gmsh.model.getEntitiesInBoundingBox(-0.1, -0.1, -0.1, 1.1, 1.1, 0.01, 2)
gmsh.model.addPhysicalGroup(2, [t for d, t in bottom], 30, "bottom")
sphere = gmsh.model.getEntitiesInBoundingBox(0.2, 0.2, 0.2, 0.8, 0.8, 0.8, 2)
gmsh.model.addPhysicalGroup(2, [t for d, t in sphere], 40, "sphere")
edge = gmsh.model.getEntitiesInBoundingBox(-0.1, -0.1, -0.1, 1.1, 0.01, 0.01, 1)
gmsh.model.addPhysicalGroup(1, [t for d, t in edge], 50, "edge")
corner = gmsh.model.getEntitiesInBoundingBox(-0.1, -0.1, -0.1, 0.01, 0.01, 0.01, 0)
gmsh.model.addPhysicalGroup(0, [t for d, t in corner], 60, "corner")
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.1)
gmsh.model.mesh.generate(3)
gmsh.option.setNumber("Mesh.PartitionCreateGhostCells", 1)
gmsh.model.mesh.partition(4)


# the elements of the model (dim, entity, type, nodes, partitions and physical
# groups of the entity, by tag), the coordinates of its nodes and its physical
# groups
def mesh_data():
    elements = {}
    for dim, tag in gmsh.model.getEntities():
        parts = tuple(gmsh.model.getPartitions(dim, tag))
        phys = tuple(sorted(gmsh.model.getPhysicalGroupsForEntity(dim, tag)))
        types, etags, enodes = gmsh.model.mesh.getElements(dim, tag)
        for t, et, en in zip(types, etags, enodes):
            n = len(en) // len(et)
            for i, e in enumerate(et):
                nodes = tuple(int(x) for x in en[i * n:(i + 1) * n])
                elements[int(e)] = (dim, tag, int(t), nodes, parts, phys)
    tags, coord, _ = gmsh.model.mesh.getNodes()
    nodes = {int(t): tuple(coord[3 * i:3 * i + 3]) for i, t in enumerate(tags)}
    groups = {(d, t): gmsh.model.getPhysicalName(d, t)
              for d, t in gmsh.model.getPhysicalGroups()}
    return elements, nodes, groups


# the mesh of the files merged, and the warnings and errors
def read(names):
    gmsh.clear()
    gmsh.logger.start()
    for name in names:
        gmsh.merge(name)
    log = [l for l in gmsh.logger.get() if l.startswith(("Warning", "Error"))]
    gmsh.logger.stop()
    return mesh_data(), log


def expected(full, partitions, ghosts):
    elements = full[0]
    keep = {e for e, d in elements.items() if set(d[4]) & set(partitions)}
    if ghosts:
        nodes = set(itertools.chain.from_iterable(elements[e][3] for e in keep))
        keep |= {e for e, d in elements.items()
                 if e not in keep and set(d[3]) & nodes}
    return keep


ok = True


# whether the mesh read is the expected part of the full mesh, without
# warnings
def check(label, read_data, full, partitions, ghosts):
    global ok
    (elements, nodes, groups), log = read_data
    good = (set(elements) == expected(full, partitions, ghosts) and
            all(elements[e] == full[0][e] for e in elements))
    needed = set(itertools.chain.from_iterable(d[3] for d in elements.values()))
    good = (good and set(nodes) == needed and
            all(nodes[n] == full[1][n] for n in nodes))
    good = good and all(full[2].get(g) == n for g, n in groups.items())
    good = good and not log
    print("{}: {} elements, {} nodes, {} warnings: {}".format(
        label, len(elements), len(nodes), len(log), "OK" if good else "FAILED"))
    ok = ok and good


# whether the ghost cells of the partitions are the expected ones
def check_ghosts(label, full, partitions):
    global ok
    for p in partitions:
        tags, owners = gmsh.model.mesh.getGhostElements(p)
        ghosts = expected(full, [p], True) - expected(full, [p], False)
        good = set(int(t) for t in tags) == ghosts
        print("{}: ghost cells of partition {}: {}: {}".format(
            label, p, len(tags), "OK" if good else "FAILED"))
        ok = ok and good


files = []
for version, binary, local in ((4.2, 1, 1), (4.1, 0, 1), (4.2, 1, 0)):
    gmsh.option.setNumber("Mesh.MshFileVersion", version)
    gmsh.option.setNumber("Mesh.Binary", binary)
    name = "merge_partitions_{}{}.msh".format(version, "_bin" if binary else "")
    gmsh.write(name)
    files.append(name)
    gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", 1)
    gmsh.option.setNumber("Mesh.PartitionSplitLocalBrep", local)
    base = "merge_partitions_split_{}{}{}".format(
        version, "_bin" if binary else "", "_local" if local else "")
    gmsh.write(base + ".msh")
    gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", 0)
    gmsh.option.setNumber("Mesh.PartitionSplitLocalBrep", 0)
    split = ["{}_{}.msh".format(base, p) for p in range(1, 5)]
    files += split + [base + ".msh.geo"]

    full = read([name])[0]
    for p in range(1, 5):
        data = read([split[p - 1]])
        # (without the local Brep, the bounding entities of the entities of
        # the other partitions are not saved: their warnings are expected)
        if not local:
            data = (data[0], [])
        check(split[p - 1], data, full, [p], True)
        check_ghosts(split[p - 1], full, [p])
    data = read(split)
    if not local:
        data = (data[0], [])
    check(base + ": all the files", data, full, range(1, 5), False)
    check_ghosts(base + ": all the files", full, range(1, 5))

for name in set(files):
    os.remove(name)

gmsh.finalize()

if not ok:
    sys.exit(1)
