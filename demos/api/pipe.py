import gmsh
import math

import sys

gmsh.initialize(sys.argv)

gmsh.option.setNumber('Mesh.MeshSizeMin', 0.1)
gmsh.option.setNumber('Mesh.MeshSizeMax', 0.1)
gmsh.option.setNumber('Geometry.NumSubEdges', 300) # nicer display of curves

nturns = 3
npts = 200
r = 1.
rd = 0.1
h = 1. * nturns

for i in range(npts):
  theta = i * 2. * math.pi * nturns / npts
  gmsh.model.occ.addPoint(r * math.cos(theta), r * math.sin(theta),
                          i * h / npts, i+1)

gmsh.model.occ.addSpline(range(1, npts), 1)
gmsh.model.occ.addWire([1], 1)

gmsh.model.occ.addDisk(1,0,0, rd, rd, 1)

gmsh.model.occ.addRectangle(1+2*rd,-rd,0, 2*rd,2*rd, 2, rd/5)
gmsh.model.occ.rotate([(2, 1), (2, 2)], 0, 0, 0, 1, 0, 0, math.pi/2)

#gmsh.model.occ.addPipe([(2, 1), (2, 2)], 1, 'DiscreteTrihedron')
gmsh.model.occ.addPipe([(2, 1), (2, 2)], 1, 'Frenet')
gmsh.model.occ.remove([(2, 1), (2, 2)])

gmsh.model.occ.synchronize()

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
