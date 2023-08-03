import gmsh
import sys
gmsh.initialize(sys.argv)
beg = gmsh.model.occ.addPoint(0,0,0)
end = gmsh.model.occ.addPoint(1,1,0)
mid = gmsh.model.occ.addPoint(1,0,0)
# mid is center
gmsh.model.occ.addCircleArc(beg, mid, end)
# arc goes through mid
gmsh.model.occ.addCircleArc(beg, mid, end, center=False)
gmsh.model.occ.synchronize()
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()
