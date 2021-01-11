import gmsh
import math

gmsh.initialize()

N = 2500

tic = gmsh.logger.getWallTime()
try:
    import numpy
    # x, y, z coordinates of all the nodes
    coords = numpy.empty((N + 1) * (N + 1) * 3)
    # tags of corresponding nodes
    nodes = numpy.empty((N + 1) * (N + 1))
    # connectivities (node tags) of triangle elements
    tris = numpy.empty(N * N * 2 * 3)
except:
    coords = [0] * (N + 1) * (N + 1) * 3
    nodes = [0] * (N + 1) * (N + 1)
    tris = [0] * N * N * 2 * 3

def tag(i, j):
    return (N + 1) * i + j + 1

k = 0
l = 0
for i in range(N + 1):
    for j in range(N + 1):
        nodes[k] = tag(i, j)
        coords[3 * k] = float(i) / N
        coords[3 * k + 1] = float(j) / N
        coords[3 * k + 2] = 0.05 * math.sin(10 * float(i + j) / N)
        k = k + 1
        if i > 0 and j > 0:
            tris[6 * l] = tag(i - 1, j - 1)
            tris[6 * l + 1] = tag(i, j - 1)
            tris[6 * l + 2] = tag(i - 1, j)
            tris[6 * l + 3] = tag(i, j - 1)
            tris[6 * l + 4] = tag(i, j)
            tris[6 * l + 5] = tag(i - 1, j)
            l = l + 1

toc = gmsh.logger.getWallTime()
print("==> created nodes and connectivities in {} seconds".format(toc - tic))

tic = gmsh.logger.getWallTime()
surf = gmsh.model.addDiscreteEntity(2)
toc = gmsh.logger.getWallTime()
print("==> created surface in {} seconds".format(toc - tic))

tic = gmsh.logger.getWallTime()
gmsh.model.mesh.addNodes(2, 1, nodes, coords)
toc = gmsh.logger.getWallTime()
print("==> imported nodes in {} seconds".format(toc - tic))

tic = gmsh.logger.getWallTime()
gmsh.model.mesh.addElementsByType(1, 2, [], tris)
toc = gmsh.logger.getWallTime()
print("==> imported elements in {} seconds".format(toc - tic))

tic = gmsh.logger.getWallTime()
gmsh.option.setNumber("Mesh.Binary", 1)
gmsh.write("import_perf.msh")
toc = gmsh.logger.getWallTime()
print("==> wrote to disk in {} seconds".format(toc - tic))

tic = gmsh.logger.getWallTime()
gmsh.merge("import_perf.msh")
toc = gmsh.logger.getWallTime()
print("==> read from disk in {} seconds".format(toc - tic))

#gmsh.fltk.run()

gmsh.finalize()
