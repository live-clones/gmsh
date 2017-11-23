# This file reimplements gmsh/tutorial/t5.geo in Python.

from gmsh import *
import math

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("t5")

lcar1 = .1
lcar2 = .0005
lcar3 = .055

gmshModelGeoAddPoint(0.5,0.5,0.5, lcar2, 1)
gmshModelGeoAddPoint(0.5,0.5,0, lcar1, 2)
gmshModelGeoAddPoint(0,0.5,0.5, lcar1, 3)
gmshModelGeoAddPoint(0,0,0.5, lcar1, 4)
gmshModelGeoAddPoint(0.5,0,0.5, lcar1, 5)
gmshModelGeoAddPoint(0.5,0,0, lcar1, 6)
gmshModelGeoAddPoint(0,0.5,0, lcar1, 7)
gmshModelGeoAddPoint(0,1,0, lcar1, 8)
gmshModelGeoAddPoint(1,1,0, lcar1, 9)
gmshModelGeoAddPoint(0,0,1, lcar1, 10)
gmshModelGeoAddPoint(0,1,1, lcar1, 11)
gmshModelGeoAddPoint(1,1,1, lcar1, 12)
gmshModelGeoAddPoint(1,0,1, lcar1, 13)
gmshModelGeoAddPoint(1,0,0, lcar1, 14)

gmshModelGeoAddLine(8,9, 1);   gmshModelGeoAddLine(9,12, 2)
gmshModelGeoAddLine(12,11, 3); gmshModelGeoAddLine(11,8, 4)
gmshModelGeoAddLine(9,14, 5);  gmshModelGeoAddLine(14,13, 6)
gmshModelGeoAddLine(13,12, 7); gmshModelGeoAddLine(11,10, 8)
gmshModelGeoAddLine(10,13, 9); gmshModelGeoAddLine(10,4, 10)
gmshModelGeoAddLine(4,5, 11);  gmshModelGeoAddLine(5,6, 12)
gmshModelGeoAddLine(6,2, 13);  gmshModelGeoAddLine(2,1, 14)
gmshModelGeoAddLine(1,3, 15);  gmshModelGeoAddLine(3,7, 16)
gmshModelGeoAddLine(7,2, 17);  gmshModelGeoAddLine(3,4, 18)
gmshModelGeoAddLine(5,1, 19);  gmshModelGeoAddLine(7,8, 20)
gmshModelGeoAddLine(6,14, 21); 

gmshModelGeoAddLineLoop([-11,-19,-15,-18], 22)
gmshModelGeoAddPlaneSurface([22], 23)
gmshModelGeoAddLineLoop([16,17,14,15], 24)
gmshModelGeoAddPlaneSurface([24], 25)
gmshModelGeoAddLineLoop([-17,20,1,5,-21,13], 26)
gmshModelGeoAddPlaneSurface([26], 27)
gmshModelGeoAddLineLoop([-4,-1,-2,-3], 28)
gmshModelGeoAddPlaneSurface([28], 29)
gmshModelGeoAddLineLoop([-7,2,-5,-6], 30)
gmshModelGeoAddPlaneSurface([30], 31)
gmshModelGeoAddLineLoop([6,-9,10,11,12,21], 32)
gmshModelGeoAddPlaneSurface([32], 33)
gmshModelGeoAddLineLoop([7,3,8,9], 34)
gmshModelGeoAddPlaneSurface([34], 35)
gmshModelGeoAddLineLoop([-10,18,-16,-20,4,-8], 36)
gmshModelGeoAddPlaneSurface([36], 37)
gmshModelGeoAddLineLoop([-14,-13,-12,19], 38)
gmshModelGeoAddPlaneSurface([38], 39)

shells = IntVector(); volumes = IntVector()

# When the tag is not specified, a new one is automatically provided
sl = gmshModelGeoAddSurfaceLoop([35,31,29,37,33,23,39,25,27])
shells.push_back(sl)

def cheeseHole(x, y, z, r, lc, shells, volumes):
    p1 = gmshModelGeoAddPoint(x,  y,  z,   lc)
    p2 = gmshModelGeoAddPoint(x+r,y,  z,   lc)
    p3 = gmshModelGeoAddPoint(x,  y+r,z,   lc)
    p4 = gmshModelGeoAddPoint(x,  y,  z+r, lc)
    p5 = gmshModelGeoAddPoint(x-r,y,  z,   lc)
    p6 = gmshModelGeoAddPoint(x,  y-r,z,   lc)
    p7 = gmshModelGeoAddPoint(x,  y,  z-r, lc)

    c1 = gmshModelGeoAddCircleArc(p2,p1,p7)
    c2 = gmshModelGeoAddCircleArc(p7,p1,p5)
    c3 = gmshModelGeoAddCircleArc(p5,p1,p4)
    c4 = gmshModelGeoAddCircleArc(p4,p1,p2)
    c5 = gmshModelGeoAddCircleArc(p2,p1,p3)
    c6 = gmshModelGeoAddCircleArc(p3,p1,p5)
    c7 = gmshModelGeoAddCircleArc(p5,p1,p6)
    c8 = gmshModelGeoAddCircleArc(p6,p1,p2)
    c9 = gmshModelGeoAddCircleArc(p7,p1,p3)
    c10 = gmshModelGeoAddCircleArc(p3,p1,p4)
    c11 = gmshModelGeoAddCircleArc(p4,p1,p6)
    c12 = gmshModelGeoAddCircleArc(p6,p1,p7)
    
    l1 = gmshModelGeoAddLineLoop([c5,c10,c4])
    l2 = gmshModelGeoAddLineLoop([c9,-c5,c1])
    l3 = gmshModelGeoAddLineLoop([c12,-c8,-c1])
    l4 = gmshModelGeoAddLineLoop([c8,-c4,c11])
    l5 = gmshModelGeoAddLineLoop([-c10,c6,c3])
    l6 = gmshModelGeoAddLineLoop([-c11,-c3,c7])
    l7 = gmshModelGeoAddLineLoop([-c2,-c7,-c12])
    l8 = gmshModelGeoAddLineLoop([-c6,-c9,c2])
    
    s1 = gmshModelGeoAddSurfaceFilling([l1])
    s2 = gmshModelGeoAddSurfaceFilling([l2])
    s3 = gmshModelGeoAddSurfaceFilling([l3])
    s4 = gmshModelGeoAddSurfaceFilling([l4])
    s5 = gmshModelGeoAddSurfaceFilling([l5])
    s6 = gmshModelGeoAddSurfaceFilling([l6])
    s7 = gmshModelGeoAddSurfaceFilling([l7])
    s8 = gmshModelGeoAddSurfaceFilling([l8])
    
    sl = gmshModelGeoAddSurfaceLoop([s1, s2, s3, s4, s5, s6, s7, s8])
    v = gmshModelGeoAddVolume([sl])
    shells.append(sl)
    volumes.append(v)

x = 0; y = 0.75; z = 0; r = 0.09
for t in range(1, 6):
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    gmshModelAddPhysicalGroup(3, [volumes.back()], t);

gmshModelGeoAddVolume(shells, 186);
      
gmshModelAddPhysicalGroup(3, [186], 10);
gmshModelGeoSynchronize()
gmshModelMesh(3)
gmshExport("t5.msh")

gmshFinalize()
