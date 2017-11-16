# This file reimplements gmsh/tutorial/t5.geo in Python.

from gmsh import *
import math

def hypot(a, b):
    return math.sqrt(a * a + b * b)

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("t5")

lcar1 = .1
lcar2 = .0005
lcar3 = .055

gmshModelGeoAddPoint(1, 0.5,0.5,0.5, lcar2)
gmshModelGeoAddPoint(2, 0.5,0.5,0, lcar1)
gmshModelGeoAddPoint(3, 0,0.5,0.5, lcar1)
gmshModelGeoAddPoint(4, 0,0,0.5, lcar1)
gmshModelGeoAddPoint(5, 0.5,0,0.5, lcar1)
gmshModelGeoAddPoint(6, 0.5,0,0, lcar1)
gmshModelGeoAddPoint(7, 0,0.5,0, lcar1)
gmshModelGeoAddPoint(8, 0,1,0, lcar1)
gmshModelGeoAddPoint(9, 1,1,0, lcar1)
gmshModelGeoAddPoint(10, 0,0,1, lcar1)
gmshModelGeoAddPoint(11, 0,1,1, lcar1)
gmshModelGeoAddPoint(12, 1,1,1, lcar1)
gmshModelGeoAddPoint(13, 1,0,1, lcar1)
gmshModelGeoAddPoint(14, 1,0,0, lcar1)

gmshModelGeoAddLine(1, 8,9);   gmshModelGeoAddLine(2, 9,12)
gmshModelGeoAddLine(3, 12,11); gmshModelGeoAddLine(4, 11,8)
gmshModelGeoAddLine(5, 9,14);  gmshModelGeoAddLine(6, 14,13)
gmshModelGeoAddLine(7, 13,12); gmshModelGeoAddLine(8, 11,10)
gmshModelGeoAddLine(9, 10,13); gmshModelGeoAddLine(10, 10,4)
gmshModelGeoAddLine(11, 4,5);  gmshModelGeoAddLine(12, 5,6)
gmshModelGeoAddLine(13, 6,2);  gmshModelGeoAddLine(14, 2,1)
gmshModelGeoAddLine(15, 1,3);  gmshModelGeoAddLine(16, 3,7)
gmshModelGeoAddLine(17, 7,2);  gmshModelGeoAddLine(18, 3,4)
gmshModelGeoAddLine(19, 5,1);  gmshModelGeoAddLine(20, 7,8)
gmshModelGeoAddLine(21, 6,14); 

gmshModelGeoAddLineLoop(22, [-11,-19,-15,-18])
gmshModelGeoAddPlaneSurface(23, [22])
gmshModelGeoAddLineLoop(24, [16,17,14,15])
gmshModelGeoAddPlaneSurface(25, [24])
gmshModelGeoAddLineLoop(26, [-17,20,1,5,-21,13])
gmshModelGeoAddPlaneSurface(27, [26])
gmshModelGeoAddLineLoop(28, [-4,-1,-2,-3])
gmshModelGeoAddPlaneSurface(29, [28])
gmshModelGeoAddLineLoop(30, [-7,2,-5,-6])
gmshModelGeoAddPlaneSurface(31, [30])
gmshModelGeoAddLineLoop(32, [6,-9,10,11,12,21])
gmshModelGeoAddPlaneSurface(33, [32])
gmshModelGeoAddLineLoop(34, [7,3,8,9])
gmshModelGeoAddPlaneSurface(35, [34])
gmshModelGeoAddLineLoop(36, [-10,18,-16,-20,4,-8])
gmshModelGeoAddPlaneSurface(37, [36])
gmshModelGeoAddLineLoop(38, [-14,-13,-12,19])
gmshModelGeoAddPlaneSurface(39, [38])

shells = IntVector(); volumes = IntVector()

sl = gmshModelGeoAddSurfaceLoop(-1, [35,31,29,37,33,23,39,25,27])
shells.push_back(sl[1])

def cheeseHole(x, y, z, r, lc, shells, volumes):
    # When the tag (first argument) is negative, the next available tag for the
    # corresponding entity is appended to the value returned by the function
    p1 = gmshModelGeoAddPoint(-1, x,  y,  z,   lc)[1]
    p2 = gmshModelGeoAddPoint(-1, x+r,y,  z,   lc)[1]
    p3 = gmshModelGeoAddPoint(-1, x,  y+r,z,   lc)[1]
    p4 = gmshModelGeoAddPoint(-1, x,  y,  z+r, lc)[1]
    p5 = gmshModelGeoAddPoint(-1, x-r,y,  z,   lc)[1]
    p6 = gmshModelGeoAddPoint(-1, x,  y-r,z,   lc)[1]
    p7 = gmshModelGeoAddPoint(-1, x,  y,  z-r, lc)[1]

    c1 = gmshModelGeoAddCircleArc(-1, p2,p1,p7)[1]
    c2 = gmshModelGeoAddCircleArc(-1, p7,p1,p5)[1]
    c3 = gmshModelGeoAddCircleArc(-1, p5,p1,p4)[1]
    c4 = gmshModelGeoAddCircleArc(-1, p4,p1,p2)[1]
    c5 = gmshModelGeoAddCircleArc(-1, p2,p1,p3)[1]
    c6 = gmshModelGeoAddCircleArc(-1, p3,p1,p5)[1]
    c7 = gmshModelGeoAddCircleArc(-1, p5,p1,p6)[1]
    c8 = gmshModelGeoAddCircleArc(-1, p6,p1,p2)[1]
    c9 = gmshModelGeoAddCircleArc(-1, p7,p1,p3)[1]
    c10 = gmshModelGeoAddCircleArc(-1, p3,p1,p4)[1]
    c11 = gmshModelGeoAddCircleArc(-1, p4,p1,p6)[1]
    c12 = gmshModelGeoAddCircleArc(-1, p6,p1,p7)[1]
    
    l1 = gmshModelGeoAddLineLoop(-1, [c5,c10,c4])[1]
    l2 = gmshModelGeoAddLineLoop(-1, [c9,-c5,c1])[1]
    l3 = gmshModelGeoAddLineLoop(-1, [c12,-c8,-c1])[1]
    l4 = gmshModelGeoAddLineLoop(-1, [c8,-c4,c11])[1]
    l5 = gmshModelGeoAddLineLoop(-1, [-c10,c6,c3])[1]
    l6 = gmshModelGeoAddLineLoop(-1, [-c11,-c3,c7])[1]
    l7 = gmshModelGeoAddLineLoop(-1, [-c2,-c7,-c12])[1]
    l8 = gmshModelGeoAddLineLoop(-1, [-c6,-c9,c2])[1]
    
    s1 = gmshModelGeoAddSurfaceFilling(-1, [l1])[1]
    s2 = gmshModelGeoAddSurfaceFilling(-1, [l2])[1]
    s3 = gmshModelGeoAddSurfaceFilling(-1, [l3])[1]
    s4 = gmshModelGeoAddSurfaceFilling(-1, [l4])[1]
    s5 = gmshModelGeoAddSurfaceFilling(-1, [l5])[1]
    s6 = gmshModelGeoAddSurfaceFilling(-1, [l6])[1]
    s7 = gmshModelGeoAddSurfaceFilling(-1, [l7])[1]
    s8 = gmshModelGeoAddSurfaceFilling(-1, [l8])[1]
    
    sl = gmshModelGeoAddSurfaceLoop(-1, [s1, s2, s3, s4, s5, s6, s7, s8])[1]
    v = gmshModelGeoAddVolume(-1, [sl])[1]
    shells.append(sl)
    volumes.append(v)

x = 0; y = 0.75; z = 0; r = 0.09
for t in range(1,5):
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    gmshModelAddPhysicalGroup(3, t, [volumes.back()]);

gmshModelGeoAddVolume(186, shells);
      
gmshModelAddPhysicalGroup(3, 10, [186]);
gmshModelGeoSynchronize()
gmshModelMesh(3)
gmshExport("t5.msh")

gmshFinalize()
