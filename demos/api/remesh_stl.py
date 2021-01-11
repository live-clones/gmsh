import gmsh
import math
import os
import sys

gmsh.initialize()

gmsh.option.setNumber("Mesh.Algorithm", 6)
gmsh.option.setNumber("Mesh.MeshSizeMin", 0.75)
gmsh.option.setNumber("Mesh.MeshSizeMax", 0.75)

# load STL file
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, "object.stl"))

# split input surface mesh based on an angle threshold of 40 degrees between
# triangles, and generate new discrete surfaces suitable for reparametrization
gmsh.model.mesh.classifySurfaces(40 * math.pi / 180., True, True)

# create a geometry (through reparametrization) for all discrete curves and
# discrete surfaces
gmsh.model.mesh.createGeometry()

# add a volume
s = gmsh.model.getEntities(2)
l = gmsh.model.geo.addSurfaceLoop([s[i][1] for i in range(len(s))])
gmsh.model.geo.addVolume([l])

gmsh.model.geo.synchronize()
gmsh.model.mesh.generate(3)

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
