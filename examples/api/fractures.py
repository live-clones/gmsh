import gmsh
import random
import math
import sys

# shows how to identify parts after boolean fragments

gmsh.initialize()
gmsh.model.occ.addRectangle(-0.6,-0.6, 0, 2.2, 2.2, tag=1)
N = 20
for i in range(2, N+2):
  h = 0.05+random.random()*0.5;
  w = 0.01+random.random()*0.1;
  x = random.random();
  y = random.random();
  alpha = random.random() * 2 * math.pi;
  gmsh.model.occ.addRectangle(x, y, 0, w, h, tag=i)
  gmsh.model.occ.rotate([(2, i)], x, y, 0, 0,0,1, alpha)

rin = [(2, i) for i in range(1, N+2)]
rout, rinout = gmsh.model.occ.fragment(rin, [])

gmsh.model.occ.synchronize()

for r in zip(rin, rinout):
    if(r[0][1] != 1):
        print("fracture " + str(r[0][1]) + " -> surfaces " + str(r[1]))
        gmsh.model.addPhysicalGroup(2, [r[1][i][1] for i in range(len(r[1]))],
                                    name='fracture'+str(r[0][1]))

gmsh.option.setNumber('Mesh.MeshSizeMin', 0.05)
gmsh.option.setNumber('Mesh.MeshSizeMax', 0.05)
gmsh.model.mesh.generate()

if "-nopopup" not in sys.argv:
    gmsh.fltk.run()
