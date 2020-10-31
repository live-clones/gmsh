import gmsh
import itertools

# points to connect
points = [(-1, 0, 0), (1, 1, 0), (-1, 2, 0), (1, 3, 0), (-1, 4, 0)]

# assign node numbers
nodes = [x for x in range(1, len(points)+1)]
# get a flat list of coordinates
coords = list(itertools.chain.from_iterable(points))

gmsh.initialize()
# add a dummy line to add nodes to
dummy_line = 1
gmsh.model.addDiscreteEntity(1, dummy_line)

# add nodes
gmsh.model.mesh.addNodes(1, dummy_line, nodes, coords)

# add line elements between each node
line_elt = 1
for i in range(len(nodes) - 1):
    gmsh.model.mesh.addElementsByType(
        dummy_line, line_elt, [], [nodes[i], nodes[i+1]])

gmsh.finalize()
