# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 21
#
#  Mesh partitioning
#
# ------------------------------------------------------------------------------

import gmsh
import sys

# Gmsh can partition meshes using different algorithms, e.g. the graph
# partitioner Metis or the `SimplePartition' plugin. For all the partitioning
# algorithms, the relationship between mesh elements and mesh partitions is
# encoded through the creation of new (discrete) elementary entities, called
# "partition entities".
#
# Partition entities behave exactly like other discrete elementary entities; the
# only difference is that they keep track of both a mesh partition index and
# their parent elementary entity.
#
# The major advantage of this approach is that it allows to maintain a full
# boundary representation of the partition entities, which Gmsh creates
# automatically if `Mesh.PartitionCreateTopology' is set.

gmsh.initialize()

# Let us start by creating a simple geometry with two adjacent squares sharing
# an edge:

gmsh.model.add("t21")
gmsh.model.occ.addRectangle(0, 0, 0, 1, 1, 1)
gmsh.model.occ.addRectangle(1, 0, 0, 1, 1, 2)
gmsh.model.occ.fragment([(2, 1)], [(2, 2)])
gmsh.model.occ.synchronize()
gmsh.model.mesh.setSize(gmsh.model.getEntities(0), 0.05)

# We create one physical group for each square, and we mesh the resulting
# geometry:
gmsh.model.addPhysicalGroup(2, [1], 100)
gmsh.model.setPhysicalName(2, 100, "Left")
gmsh.model.addPhysicalGroup(2, [2], 200)
gmsh.model.setPhysicalName(2, 200, "Right")
gmsh.model.mesh.generate(2)

# We now define several constants to fine-tune how the mesh will be partitioned
partitioner = 0  # 0 for Metis, 1 for SimplePartition
N = 3  # Number of partitions
topology = 1  # Create partition topology (BRep)?
ghosts = 0  # Create ghost cells?
physicals = 0  # Create new physical groups?
write = 1  # Write file to disk?
split = 1  # Write one file per partition?

# Should we create the boundary representation of the partition entities?
gmsh.option.setNumber("Mesh.PartitionCreateTopology", topology)

# Should we create ghost cells?
gmsh.option.setNumber("Mesh.PartitionCreateGhostCells", ghosts)

# Should we automatically create new physical groups on the partition entities?
gmsh.option.setNumber("Mesh.PartitionCreatePhysicals", physicals)

# Should we keep backward compatibility with pre-Gmsh 4, e.g. to save the mesh
# in MSH2 format?
gmsh.option.setNumber("Mesh.PartitionOldStyleMsh2", 0)

# Should we save one mesh file per partition?
gmsh.option.setNumber("Mesh.PartitionSplitMeshFiles", split)

if partitioner == 0:
    # Use Metis to create N partitions
    gmsh.model.mesh.partition(N)
    # Several options can be set to control Metis: `Mesh.MetisAlgorithm' (1:
    # Recursive, 2: K-way), `Mesh.MetisObjective' (1: min. edge-cut, 2:
    # min. communication volume), `Mesh.PartitionTriWeight' (weight of
    # triangles), `Mesh.PartitionQuadWeight' (weight of quads), ...
else:
    # Use the `SimplePartition' plugin to create chessboard-like partitions
    gmsh.plugin.setNumber("SimplePartition", "NumSlicesX", N)
    gmsh.plugin.setNumber("SimplePartition", "NumSlicesY", 1)
    gmsh.plugin.setNumber("SimplePartition", "NumSlicesZ", 1)
    gmsh.plugin.run("SimplePartition")

# Save mesh file (or files, if `Mesh.PartitionSplitMeshFiles' is set):
if write:
    gmsh.write("t21.msh")

# Iterate over partitioned entities and print some info (see the first extended
# tutorial `x1.py' for additional information):
entities = gmsh.model.getEntities()
for e in entities:
    partitions = gmsh.model.getPartitions(e[0], e[1])
    if len(partitions):
        print("Entity " + str(e) + " of type " +
              gmsh.model.getType(e[0], e[1]))
        print(" - Partition(s): " + str(partitions))
        print(" - Parent: " + str(gmsh.model.getParent(e[0], e[1])))
        print(" - Boundary: " + str(gmsh.model.getBoundary([e])))

# Launch the GUI to see the results:
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
