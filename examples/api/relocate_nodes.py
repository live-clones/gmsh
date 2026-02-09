import gmsh
import sys

def add_house(A, B, C):
    p1 = gmsh.model.occ.addPoint(0, 0, 0)
    p2 = gmsh.model.occ.addPoint(A, 0, 0)
    p3 = gmsh.model.occ.addPoint(A, B, 0)
    p4 = gmsh.model.occ.addPoint(A/2, B+C, 0)
    p5 = gmsh.model.occ.addPoint(0, B, 0)
    l1 = gmsh.model.occ.addLine(p1, p2)
    l2 = gmsh.model.occ.addLine(p2, p3)
    l3 = gmsh.model.occ.addLine(p3, p4)
    l4 = gmsh.model.occ.addLine(p4, p5)
    l5 = gmsh.model.occ.addLine(p5, p1)
    cl = gmsh.model.occ.addCurveLoop([l1, l2, l3, l4, l5])

    # plane surface - inner nodes will not move as parametrization is R2
    # s = gmsh.model.occ.addPlaneSurface([cl])

    # BSpline surface - inner nodes will move
    s = gmsh.model.occ.addSurfaceFilling(cl)
    gmsh.model.occ.synchronize()

gmsh.initialize(sys.argv)

# create initial geometry
gmsh.model.add('house1')
add_house(10, 8, 5)

# mesh it and store the mesh
gmsh.model.mesh.generate(2)
m = {}
for e in gmsh.model.getEntities():
    m[e] = (gmsh.model.mesh.getNodes(e[0], e[1]),
            gmsh.model.mesh.getElements(e[0], e[1]))

# create perturbed geometry
gmsh.model.add('house2')
add_house(9.5, 8.2, 5.1)

# copy old mesh into perturbed geometry
for e in m:
    gmsh.model.mesh.addNodes(e[0], e[1], m[e][0][0], m[e][0][1], m[e][0][2])
    gmsh.model.mesh.addElements(e[0], e[1], m[e][1][0], m[e][1][1], m[e][1][2])

# relocate mesh nodes on the perturbed geometry, using the parametric
# coordinates from the initial geometry
gmsh.model.mesh.relocateNodes()

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
