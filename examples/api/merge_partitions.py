import gmsh
import itertools
import os
import sys

# Read some partitions of a partitioned mesh, with their ghost cells, with
# `gmsh.model.mesh.merge()', e.g. one per MPI rank of a parallel solver: each
# rank then only reads (and keeps in memory) its part of the mesh. The ghost
# cells of a partition are the elements of the other partitions, of all
# dimensions, that share a node with its elements; they are created by the
# partitioner with the `Mesh.PartitionCreateGhostCells' option. This checks
# that reading partitions P with their ghost cells gives exactly the elements
# of the partition entities of P and the elements that share a node with them,
# with their nodes, entities, partitions and physical groups as in a full
# read; and that the file of a partition saved on its own
# (`Mesh.PartitionSplitMeshFiles') holds the same.

gmsh.initialize()

# a box with a ball inside, with physical groups of all dimensions, its mesh
# partitioned in 4 and saved in partitioned MSH files
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
files = []
for version, binary in ((4.2, 1), (4.1, 0)):
    name = "merge_partitions_{}{}.msh".format(version, "_bin" if binary else "")
    gmsh.option.setNumber("Mesh.MshFileVersion", version)
    gmsh.option.setNumber("Mesh.Binary", binary)
    gmsh.write(name)
    files.append(name)


# the elements of the model (dim, entity, type, nodes, partitions and physical
# groups of the entity, by tag) and the coordinates of its nodes
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
    return elements, nodes


def read(name, partitions=[], ghosts=False):
    gmsh.clear()
    gmsh.model.mesh.merge(name, partitions, ghosts)
    return mesh_data()


def expected(full, partitions, ghosts):
    elements = full[0]
    keep = {e for e, d in elements.items() if set(d[4]) & set(partitions)}
    if ghosts:
        nodes = set(itertools.chain.from_iterable(elements[e][3] for e in keep))
        keep |= {e for e, d in elements.items()
                 if e not in keep and set(d[3]) & nodes}
    return keep


ok = True


# whether the mesh read is the expected part of the full mesh
def check(label, data, full, partitions, ghosts):
    global ok
    elements, nodes = data
    good = (set(elements) == expected(full, partitions, ghosts) and
            all(elements[e] == full[0][e] for e in elements))
    needed = set(itertools.chain.from_iterable(d[3] for d in elements.values()))
    good = (good and set(nodes) == needed and
            all(nodes[n] == full[1][n] for n in nodes))
    print("{}: {} elements, {} nodes: {}".format(label, len(elements),
                                                 len(nodes),
                                                 "OK" if good else "FAILED"))
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


for name in files:
    full = read(name)
    check_ghosts(name, full, range(1, 5))
    cases = [([p], g) for p in range(1, 5) for g in (False, True)]
    cases += [([1, 3], True)]
    for partitions, ghosts in cases:
        check("{}: partitions {}, ghosts {}".format(name, partitions, ghosts),
              read(name, partitions, ghosts), full, partitions, ghosts)

# the files of the partitions saved on their own: each with its ghost cells
full = read(files[0])
gmsh.option.setNumber("Mesh.MshFileVersion", 4.2)
gmsh.option.setNumber("Mesh.Binary", 1)
gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", 1)
gmsh.write("merge_partitions_split.msh")
gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", 0)
split = ["merge_partitions_split_{}.msh".format(p) for p in range(1, 5)]
for p in range(1, 5):
    check(split[p - 1], read(split[p - 1]), full, [p], True)
    check_ghosts(split[p - 1], full, [p])
    check("{}: partition {}, ghosts True".format(split[p - 1], p),
          read(split[p - 1], [p], True), full, [p], True)
gmsh.clear()
for name in split:
    gmsh.model.mesh.merge(name)
check("all the files of the partitions", mesh_data(), full, range(1, 5), False)
check_ghosts("all the files of the partitions", full, range(1, 5))

# without ghost cells in the file, the partitions are read with them as the
# whole mesh, with a warning
gmsh.clear()
gmsh.model.mesh.merge(files[0])
gmsh.option.setNumber("Mesh.PartitionCreateGhostCells", 0)
gmsh.model.mesh.partition(4)
gmsh.write("merge_partitions_no_ghosts.msh")
full = read("merge_partitions_no_ghosts.msh")
check("no ghost cells in the file: partition 1, ghosts True",
      read("merge_partitions_no_ghosts.msh", [1], True), full, range(1, 5),
      False)

for name in files + split + ["merge_partitions_split.msh.geo",
                             "merge_partitions_no_ghosts.msh"]:
    os.remove(name)

gmsh.finalize()

if not ok:
    sys.exit(1)
