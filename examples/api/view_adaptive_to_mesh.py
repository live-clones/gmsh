import gmsh
import sys

gmsh.initialize(sys.argv)

t2 = gmsh.view.add("Second order quad")

# coordinates of 4 quad nodes
quad = [0., 1., 1., 0., # x
        -1.2, -1.2, -0.2, -0.2, # y
        0., 0., 0., 0.] # z

# 9 values to be interpolated 2nd order basis functions
quad.extend([1., 1., 1., 1., 3., 3., 3., 3., -3.])

# interpolation matrices c[i][j] and e[i][j] defining the d = 9
# basis functions, i = 0, ..., d-1:
#
# f[i](u, v, w) = sum_(j = 0, ..., d - 1) c[i][j] u^e[j][0] v^e[j][1] w^e[j][2],
#
# with u, v, w the coordinates in the reference element
gmsh.view.setInterpolationMatrices(t2, "Quadrangle", 9,
                                   [0, 0, 0.25, 0, 0, -0.25, -0.25, 0, 0.25,
                                    0, 0, 0.25, 0, 0, -0.25, 0.25, 0, -0.25,
                                    0, 0, 0.25, 0, 0, 0.25, 0.25, 0, 0.25,
                                    0, 0, 0.25, 0, 0, 0.25, -0.25, 0, -0.25,
                                    0, 0, -0.5, 0.5, 0, 0.5, 0, -0.5, 0,
                                    0, 0.5, -0.5, 0, 0.5, 0, -0.5, 0, 0,
                                    0, 0, -0.5, 0.5, 0, -0.5, 0, 0.5, 0,
                                    0, 0.5, -0.5, 0, -0.5, 0, 0.5, 0, 0,
                                    1, -1, 1, -1, 0, 0, 0, 0, 0],
                                   [0, 0, 0,
                                    2, 0, 0,
                                    2, 2, 0,
                                    0, 2, 0,
                                    1, 0, 0,
                                    2, 1, 0,
                                    1, 2, 0,
                                    0, 1, 0,
                                    1, 1, 0])

gmsh.view.addListData(t2, "SQ", 1, quad)

# adaptive visualization
gmsh.view.option.setNumber(t2, "AdaptVisualizationGrid", 1)
gmsh.view.option.setNumber(t2, "TargetError", 1e-2)
gmsh.view.option.setNumber(t2, "MaxRecursionLevel", 6)

# get adaptive visualization data
dataType, numElements, data = gmsh.view.getListData(t2, returnAdaptive=True)

# create discrete surface
surf = gmsh.model.addDiscreteEntity(2)

# create nodes and elements and add them to the surface
N = 1
for t in range(0, len(dataType)):
    if dataType[t] == 'SQ': # quad
        coord = []
        tags = []
        ele = []
        for q in range(0, numElements[t]):
            coord.extend([data[t][16*q+0], data[t][16*q+4], data[t][16*q+8]])
            coord.extend([data[t][16*q+1], data[t][16*q+5], data[t][16*q+9]])
            coord.extend([data[t][16*q+2], data[t][16*q+6], data[t][16*q+10]])
            coord.extend([data[t][16*q+3], data[t][16*q+7], data[t][16*q+11]])
            tags.extend([N, N+1, N+2, N+3])
            ele.extend([N, N+1, N+2, N+3])
            N = N+4
        gmsh.model.mesh.addNodes(2, 1, tags, coord)
        gmsh.model.mesh.addElementsByType(surf, 3, [], ele)

# remove duplicate nodes
gmsh.model.mesh.removeDuplicateNodes()

# save mesh
gmsh.write('test.msh')

# Launch the GUI to see the results:
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
