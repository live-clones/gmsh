# Triangulations in the discrete CAD modeler, and the topology built from their
# triangles: an STL file, split where the normals of its triangles turn by more
# than 40 degrees, and two cubes sharing a face, given by their nodes and
# triangles, whose curves are along the sharp edges and along the edges of the
# common face (shared by three surfaces), and whose volumes are the two cells
# of space they bound

import gmsh
import math
import os
import sys

gmsh.initialize(sys.argv)
gmsh.model.add("discrete_import")

path = os.path.dirname(os.path.abspath(__file__))
stl = gmsh.model.discrete.importShapes(
    os.path.join(path, os.pardir, os.pardir, 'tutorials', 't13_data.stl'),
    40 * math.pi / 180)

# the nodes (i, j, k) of the cubes [0, 1]^3 and [1, 2] x [0, 1]^2, shifted
# away from the STL
coord = []
for i in range(3):
    for j in range(2):
        for k in range(2):
            coord += [100 + 30 * i, 30 * j, 30 * k]
node = lambda i, j, k: 4 * i + 2 * j + k
# the squares of the faces, 2 triangles each
triangles = []
def square(a, b, c, d):
    triangles.extend([a, b, c, a, c, d])
for i in range(2):
    square(node(i, 0, 0), node(i + 1, 0, 0), node(i + 1, 0, 1), node(i, 0, 1))
    square(node(i, 1, 0), node(i, 1, 1), node(i + 1, 1, 1), node(i + 1, 1, 0))
    square(node(i, 0, 0), node(i, 1, 0), node(i + 1, 1, 0), node(i + 1, 0, 0))
    square(node(i, 0, 1), node(i + 1, 0, 1), node(i + 1, 1, 1), node(i, 1, 1))
for i in range(3):
    square(node(i, 0, 0), node(i, 0, 1), node(i, 1, 1), node(i, 1, 0))
cubes = gmsh.model.discrete.addTriangulation(coord, triangles,
                                             40 * math.pi / 180)
print("STL:", stl, "cubes:", cubes)

gmsh.model.discrete.synchronize()
for dim in range(4):
    print("dimension {}: {} entities".format(dim,
                                             len(gmsh.model.getEntities(dim))))

gmsh.option.setNumber("Mesh.MeshSizeMax", 3)
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
