import gmsh
import sys

gmsh.initialize(sys.argv)
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("test");

# add discrete surface with tag 1
gmsh.modelAddDiscreteEntity(2, 1)

# add 4 mesh vertices
gmsh.modelMeshSetVertices(2, 1,
                         [1, 2, 3, 4], # vertex tags: 1, 2, 3, and 4
                         [0., 0., 0., # coordinates of vertex 1
                          1., 0., 0., # coordinates of vertex 2
                          1., 1., 0., # ...
                          0., 1., 0.])

# add 2 triangles
gmsh.modelMeshSetElements(2, 1,
                         [2], # single type : 3-node triangle
                         [[1, 2]], # triangle tags: 1 and 2
                         [[1, 2, 3, # triangle 1: vertices 1, 2, 3
                           1, 3, 4]]) # triangle 2: vertices 1, 3, 4

# export the mesh ; use explore.py to read and examine the mesh
gmsh.write("test.msh")

gmsh.finalize()

