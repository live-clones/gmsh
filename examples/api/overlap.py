import gmsh
import sys

# This example demonstrates overlapping domain decomposition. On top of a
# partitioned mesh, `createOverlaps' grows each partition by a given number of
# element layers, borrowed from its neighbours. This is what overlapping Schwarz
# methods (ORAS, PCASM, PCHPDDM...) need, as opposed to the non-overlapping
# partitions created by `partition'.
#
# The overlap layers are exposed as new model entities of type "Overlap
# surface"/"Overlap volume". They do not own their elements: they point at the
# elements of the partitioned entity they cover.

# Optionally write the mesh to disk (nothing is written by default). Both use
# Mesh.SaveAll, without which the elements of the overlap boundaries are dropped
# on export: they do not belong to any physical group.
write_unpartitioned_file = False  # overlap.msh, before the mesh is partitioned
write_one_file_per_partition = False  # overlap_1.msh, overlap_2.msh, with overlaps
write_binary = False  # write the files above in binary instead of ASCII

# Partition with Metis instead of the explicit split below
partition_using_metis = False

gmsh.initialize()

if write_binary:
    gmsh.option.setNumber("Mesh.Binary", 1)

Lx, Ly = 1.0, 0.5
Nx1 = Nx2 = 20
Ny = 10

# create two surfaces sharing a vertical interface (i.e. two "materials"), and
# mesh them with structured quadrangles
gmsh.model.add("overlap")
geo = gmsh.model.geo
for x, y in [(0, 0), (Lx / 2, 0), (Lx, 0), (Lx, Ly), (Lx / 2, Ly), (0, Ly)]:
    geo.addPoint(x, y, 0)
for a, b in [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 1), (2, 5)]:
    geo.addLine(a, b)
geo.addCurveLoop([1, 7, 5, 6], 10)
geo.addPlaneSurface([10], 20)  # left
geo.addCurveLoop([2, 3, 4, -7], 11)
geo.addPlaneSurface([11], 21)  # right
for curve, n in [(1, Nx1), (5, Nx1), (2, Nx2), (4, Nx2), (6, Ny), (7, Ny),
                 (3, Ny)]:
    geo.mesh.setTransfiniteCurve(curve, n + 1)
geo.mesh.setTransfiniteSurface(20, "Left", [1, 2, 5, 6])
geo.mesh.setTransfiniteSurface(21, "Left", [2, 3, 4, 5])
geo.mesh.setRecombine(2, 20)
geo.mesh.setRecombine(2, 21)
geo.synchronize()
gmsh.model.addPhysicalGroup(2, [20], 1, "Vol_Left")
gmsh.model.addPhysicalGroup(2, [21], 2, "Vol_Right")
gmsh.model.mesh.generate(2)

if write_unpartitioned_file:
    gmsh.option.setNumber("Mesh.SaveAll", 1)
    gmsh.write("overlap.msh")

# Partition the mesh explicitly rather than with Metis, so that the split is
# reproducible and so that it exercises the interesting case: each partition
# straddles the material interface, i.e. owns elements on *both* surfaces. (A
# split aligned with the interface would give one partition entity per
# partition, and would not exercise facets lying on both a material interface
# and a partition boundary.) Partition 1 takes all of the left surface plus the
# upper half of the first column of the right surface; partition 2 is its
# mirror image.
xi = Lx / 2  # material interface
dxLeft, dxRight = (Lx / 2) / Nx1, (Lx / 2) / Nx2
ymid = Ly / 2


def whichPartition(bx, by):
    if xi - dxLeft < bx < xi and by < ymid:
        return 2  # partition 2 reaches left, across the interface
    if xi < bx < xi + dxRight and by > ymid:
        return 1  # partition 1 reaches right, across the interface
    return 1 if bx < xi else 2


if partition_using_metis:
    gmsh.model.mesh.partition(2)
else:
    # every element of every dimension must be assigned a (1-based, nonzero)
    # partition, not just the elements of the highest dimension
    elementTags = []
    partitions = []
    for dim, tag in gmsh.model.getEntities():
        elementTypes, tags, _ = gmsh.model.mesh.getElements(dim, tag)
        for elementType, tagsOfType in zip(elementTypes, tags):
            bary = gmsh.model.mesh.getBarycenters(elementType, tag, False,
                                                  True)
            elementTags += [int(t) for t in tagsOfType]
            partitions += [
                whichPartition(bary[3 * i], bary[3 * i + 1])
                for i in range(len(tagsOfType))
            ]
    gmsh.model.mesh.partition(2, elementTags, partitions)

# grow one layer of overlap around each partition
gmsh.model.mesh.createOverlaps(1)

if write_one_file_per_partition:
    # each file holds the entities of one partition, plus the elements and
    # nodes borrowed from its neighbours through the overlap
    gmsh.option.setNumber("Mesh.SaveAll", 1)
    gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", 1)
    gmsh.write("overlap.msh")

# iterate over the overlap-related entities and print some info. Note that the
# queries take the tag of the *parent* entity, i.e. the entity the partitioned
# entity is a subset of.
dim = gmsh.model.getDimension()
parents = [t for _, t in gmsh.model.getEntities(dim)
           if gmsh.model.getType(dim, t) not in ("Partition surface",
                                                 "Overlap surface")]
boundaryParents = [t for _, t in gmsh.model.getEntities(dim - 1)
                   if gmsh.model.getType(dim - 1, t) != "Partition curve"]

for part in range(1, gmsh.model.getNumberOfPartitions() + 1):
    print("Partition " + str(part))
    for tag in parents:
        entities, overlaps = gmsh.model.mesh.getPartitionEntities(dim, tag,
                                                                  part)
        if len(entities) or len(overlaps):
            print(" - Parent " + str((dim, tag)))
            print("   - Own: " + str([int(t) for t in entities]))
            print("   - Overlap: " + str([int(t) for t in overlaps]))
        # the (dim-1) entities bounding the overlap of this partition
        boundary = gmsh.model.mesh.getOverlapBoundary(dim, tag, part)
        if len(boundary):
            print("   - Boundary of overlap: " + str([int(t) for t in boundary]))
    for tag in boundaryParents:
        # the part of an outer boundary that is covered by the overlap
        _, overlaps = gmsh.model.mesh.getPartitionEntities(dim - 1, tag, part)
        if len(overlaps):
            print(" - Overlap of boundary " + str((dim - 1, tag)) + ": " +
                  str([int(t) for t in overlaps]))
        # the part of an interface between two parent entities that is covered
        interface = gmsh.model.mesh.getOverlapInterfaceBoundary(dim - 1, tag,
                                                               part)
        if len(interface):
            print(" - Overlap of interface " + str((dim - 1, tag)) + ": " +
                  str([int(t) for t in interface]))

# in the GUI, use Tools -> Visibility with the list mode set to "Mesh
# partitions" to show the entities of a single partition: the overlap layers of
# that partition are shown together with the entities it owns
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
