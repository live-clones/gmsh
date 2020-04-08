# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 5
#
#  Characteristic lengths, holes in volumes
#
# ------------------------------------------------------------------------------

import gmsh
import math

model = gmsh.model
factory = model.geo

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

model.add("t5")

lcar1 = .1
lcar2 = .0005
lcar3 = .055

# If we wanted to change these mesh sizes globally (without changing the above
# definitions), we could give a global scaling factor for all characteristic
# lengths with e.g.
#
# gmsh.option.setNumber("Mesh.CharacteristicLengthFactor", 0.1);
#
# Since we pass `argc' and `argv' to `gmsh.initialize()', we can also give the
# option on the command line with the `-clscale' switch. For example, with:
#
# > ./t5.exe -clscale 1
#
# this tutorial produces a mesh of approximately 3000 nodes and 14,000
# tetrahedra. With
#
# > ./t5.exe -clscale 0.2
#
# the mesh counts approximately 231,000 nodes and 1,360,000 tetrahedra. You can
# check mesh statistics in the graphical user interface (gmsh.fltk.run()) with
# the `Tools->Statistics' menu.
#
# See `t10.py' for more information about mesh sizes.


# We proceed by defining some elementary entities describing a truncated cube:

factory.addPoint(0.5,0.5,0.5, lcar2, 1)
factory.addPoint(0.5,0.5,0, lcar1, 2)
factory.addPoint(0,0.5,0.5, lcar1, 3)
factory.addPoint(0,0,0.5, lcar1, 4)
factory.addPoint(0.5,0,0.5, lcar1, 5)
factory.addPoint(0.5,0,0, lcar1, 6)
factory.addPoint(0,0.5,0, lcar1, 7)
factory.addPoint(0,1,0, lcar1, 8)
factory.addPoint(1,1,0, lcar1, 9)
factory.addPoint(0,0,1, lcar1, 10)
factory.addPoint(0,1,1, lcar1, 11)
factory.addPoint(1,1,1, lcar1, 12)
factory.addPoint(1,0,1, lcar1, 13)
factory.addPoint(1,0,0, lcar1, 14)

factory.addLine(8,9, 1);   factory.addLine(9,12, 2)
factory.addLine(12,11, 3); factory.addLine(11,8, 4)
factory.addLine(9,14, 5);  factory.addLine(14,13, 6)
factory.addLine(13,12, 7); factory.addLine(11,10, 8)
factory.addLine(10,13, 9); factory.addLine(10,4, 10)
factory.addLine(4,5, 11);  factory.addLine(5,6, 12)
factory.addLine(6,2, 13);  factory.addLine(2,1, 14)
factory.addLine(1,3, 15);  factory.addLine(3,7, 16)
factory.addLine(7,2, 17);  factory.addLine(3,4, 18)
factory.addLine(5,1, 19);  factory.addLine(7,8, 20)
factory.addLine(6,14, 21)

factory.addCurveLoop([-11,-19,-15,-18], 22)
factory.addPlaneSurface([22], 23)
factory.addCurveLoop([16,17,14,15], 24)
factory.addPlaneSurface([24], 25)
factory.addCurveLoop([-17,20,1,5,-21,13], 26)
factory.addPlaneSurface([26], 27)
factory.addCurveLoop([-4,-1,-2,-3], 28)
factory.addPlaneSurface([28], 29)
factory.addCurveLoop([-7,2,-5,-6], 30)
factory.addPlaneSurface([30], 31)
factory.addCurveLoop([6,-9,10,11,12,21], 32)
factory.addPlaneSurface([32], 33)
factory.addCurveLoop([7,3,8,9], 34)
factory.addPlaneSurface([34], 35)
factory.addCurveLoop([-10,18,-16,-20,4,-8], 36)
factory.addPlaneSurface([36], 37)
factory.addCurveLoop([-14,-13,-12,19], 38)
factory.addPlaneSurface([38], 39)

shells = []

sl = factory.addSurfaceLoop([35,31,29,37,33,23,39,25,27])
shells.append(sl)

def cheeseHole(x, y, z, r, lc, shells):
    # This function will create a spherical hole in a volume. We don't specify
    # tags manually, and let the functions return them automatically:

    p1 = factory.addPoint(x,  y,  z,   lc)
    p2 = factory.addPoint(x+r,y,  z,   lc)
    p3 = factory.addPoint(x,  y+r,z,   lc)
    p4 = factory.addPoint(x,  y,  z+r, lc)
    p5 = factory.addPoint(x-r,y,  z,   lc)
    p6 = factory.addPoint(x,  y-r,z,   lc)
    p7 = factory.addPoint(x,  y,  z-r, lc)

    c1 = factory.addCircleArc(p2,p1,p7)
    c2 = factory.addCircleArc(p7,p1,p5)
    c3 = factory.addCircleArc(p5,p1,p4)
    c4 = factory.addCircleArc(p4,p1,p2)
    c5 = factory.addCircleArc(p2,p1,p3)
    c6 = factory.addCircleArc(p3,p1,p5)
    c7 = factory.addCircleArc(p5,p1,p6)
    c8 = factory.addCircleArc(p6,p1,p2)
    c9 = factory.addCircleArc(p7,p1,p3)
    c10 = factory.addCircleArc(p3,p1,p4)
    c11 = factory.addCircleArc(p4,p1,p6)
    c12 = factory.addCircleArc(p6,p1,p7)

    l1 = factory.addCurveLoop([c5,c10,c4])
    l2 = factory.addCurveLoop([c9,-c5,c1])
    l3 = factory.addCurveLoop([c12,-c8,-c1])
    l4 = factory.addCurveLoop([c8,-c4,c11])
    l5 = factory.addCurveLoop([-c10,c6,c3])
    l6 = factory.addCurveLoop([-c11,-c3,c7])
    l7 = factory.addCurveLoop([-c2,-c7,-c12])
    l8 = factory.addCurveLoop([-c6,-c9,c2])

    # We need non-plane surfaces to define the spherical holes. Here we use the
    # `gmsh.model.geo.addSurfaceFilling()' function, which can be used for
    # surfaces with 3 or 4 curves on their boundary. With the he built-in
    # kernel, if the curves are circle arcs, ruled surfaces are created;
    # otherwise transfinite interpolation is used.
    #
    # With the OpenCASCADE kernel, `gmsh.model.occ.addSurfaceFilling()' uses a
    # much more general generic surface filling algorithm, creating a BSpline
    # surface passing through an arbitrary number of boundary curves. The
    # `gmsh.model.geo.addThruSections()' allows to create ruled surfaces (see
    # `t19.py').

    s1 = factory.addSurfaceFilling([l1])
    s2 = factory.addSurfaceFilling([l2])
    s3 = factory.addSurfaceFilling([l3])
    s4 = factory.addSurfaceFilling([l4])
    s5 = factory.addSurfaceFilling([l5])
    s6 = factory.addSurfaceFilling([l6])
    s7 = factory.addSurfaceFilling([l7])
    s8 = factory.addSurfaceFilling([l8])

    sl = factory.addSurfaceLoop([s1, s2, s3, s4, s5, s6, s7, s8])
    v = factory.addVolume([sl])
    shells.append(sl)
    return v

# We create five holes in the cube:
x = 0; y = 0.75; z = 0; r = 0.09
for t in range(1, 6):
    x += 0.166
    z += 0.166
    v = cheeseHole(x, y, z, r, lcar3, shells)
    model.addPhysicalGroup(3, [v], t)

# The volume of the cube, without the 5 holes, is defined by 6 surface loops:
# the first surface loop defines the exterior surface; the surface loops other
# than the first one define holes:
factory.addVolume(shells, 186)

# Note that using solid modelling with the OpenCASCADE geometry kernel, the same
# geometry could be built quite differently: see `t16.py'.

# We finally define a physical volume for the elements discretizing the cube,
# without the holes (for which physical groups were already defined in the
# `cheeseHole()' function):
model.addPhysicalGroup(3, [186], 10)

factory.synchronize()

# We could make only part of the model visible to only mesh this subset:
# ent = gmsh.model.getEntities()
# gmsh.model.setVisibility(ent, False)
# gmsh.model.setVisibility([(3, 5(], True, True)
# gmsh.option.setNumber("Mesh.MeshOnlyVisible", 1)

# Meshing algorithms can changed globally using options:
gmsh.option.setNumber("Mesh.Algorithm", 6) # 2D algorithm set to Frontal-Delaunay
gmsh.option.setNumber("Mesh.Algorithm3D", 1) # 3D algorithm set to Delaunay

# They can also be set for individual surfaces, e.g. for using `MeshAdapt' on
# surface 1:
gmsh.model.mesh.setAlgorithm(2, 33, 1)

# To generate a curvilinear mesh and optimize it to produce provably valid
# curved elements (see A. Johnen, J.-F. Remacle and C. Geuzaine. Geometric
# validity of curvilinear finite elements. Journal of Computational Physics
# 233, pp. 359-372, 2013; and T. Toulorge, C. Geuzaine, J.-F. Remacle,
# J. Lambrechts. Robust untangling of curvilinear meshes. Journal of
# Computational Physics 254, pp. 8-26, 2013), you can uncomment the following
# lines:
#
# gmsh.option.setNumber("Mesh.ElementOrder", 2)
# gmsh.option.setNumber("Mesh.HighOrderOptimize", 2)

model.mesh.generate(3)
gmsh.write("t5.msh")

# gmsh.fltk.run()

gmsh.finalize()
