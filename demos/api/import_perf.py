import gmsh
import math

gmsh.initialize()

N = 2500

tic = gmsh.logger.getWallTime()
coords = []  # x, y, z coordinates of all the nodes
nodes = []  # tags of corresponding nodes
tris = []  # connectivities (node tags) of triangle elements

def tag(i, j):
    return (N + 1) * i + j + 1

for i in range(N + 1):
    for j in range(N + 1):
        nodes.append(tag(i, j))
        coords.extend([
            float(i) / N,
            float(j) / N, 0.05 * math.sin(10 * float(i + j) / N)
        ])
        if i > 0 and j > 0:
            tris.extend([tag(i - 1, j - 1), tag(i, j - 1), tag(i - 1, j)])
            tris.extend([tag(i, j - 1), tag(i, j), tag(i - 1, j)])
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
