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

# create a view with some data
t = gmsh.viewAdd("some data")
gmsh.viewAddModelData(t, "test", "NodeData",
                     [1, 2, 3, 4],
                     [[1.],[10.],[20.],[1.]])

# compute the iso-curve at value 11
gmsh.pluginSetNumber("Isosurface", "Value", 11.)
gmsh.pluginRun("Isosurface")

# delete the source view
gmsh.viewRemove(t)

# check how many views the plugin created (a priori, a single one)
tags = gmsh.IntVector()
gmsh.viewGetTags(tags)
if tags.size() == 1:
    gmsh.viewWrite(tags[0], "iso.msh")

gmsh.finalize()


