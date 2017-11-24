#!/usr/bin/env python

import gmsh
import sys

gmsh.initialize(sys.argv)
gmsh.optionSetNumber("General.Terminal", 1)

# Copied from discrete.py...
gmsh.modelAdd("test");
gmsh.modelAddDiscreteEntity(2, 1)
gmsh.modelMeshSetVertices(2, 1, [1, 2, 3, 4],
                         [0., 0., 0.,
                          1., 0., 0.,
                          1., 1., 0.,
                          0., 1., 0.])
gmsh.modelMeshSetElements(2, 1, [2], [[1, 2]],
                         [[1, 2, 3,
                           1, 3, 4]])
# ... end of copy

# Create a new post-processing view
t = gmsh.viewAdd("some data")

# add 10 steps of model-based data, on the nodes of the mesh
for step in range(0, 10):
    gmsh.viewAddModelData(t, "test", "NodeData",
                         [1, 2, 3, 4], # tags of nodes
                         [[10.],[10.],[12.+step],[13.+step]], # data, per node
                         step)
    
gmsh.viewWrite(t, "data.msh")
    
gmsh.finalize()
