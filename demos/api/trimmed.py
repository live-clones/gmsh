import gmsh
import sys

gmsh.initialize(sys.argv)

gmsh.model.occ.addSphere(0,0,0, 1)

c=gmsh.model.occ.addCircle(0.5,0.5,0, 0.4)
w=gmsh.model.occ.addWire([c])

c2=gmsh.model.occ.addCircle(0.5,0.5,0, 0.2)
w2=gmsh.model.occ.addWire([c2])

s=gmsh.model.occ.addRectangle(0.5,0.5,0, 0.4,0.4)
gmsh.model.occ.synchronize()
b=gmsh.model.getBoundary([(2,s)])
w3=gmsh.model.occ.addWire([p[1] for p in b])

# OK
gmsh.model.occ.trimSurface(1, [w,w2])

# Doesn't work - why??
#gmsh.model.occ.trimSurface(1, [w3])

gmsh.model.occ.synchronize()

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
