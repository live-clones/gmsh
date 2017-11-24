# This file reimplements gmsh/tutorial/t5.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t5")

lcar1 = .1
lcar2 = .0005
lcar3 = .055

gmsh.modelGeoAddPoint(0.5,0.5,0.5, lcar2, 1)
gmsh.modelGeoAddPoint(0.5,0.5,0, lcar1, 2)
gmsh.modelGeoAddPoint(0,0.5,0.5, lcar1, 3)
gmsh.modelGeoAddPoint(0,0,0.5, lcar1, 4)
gmsh.modelGeoAddPoint(0.5,0,0.5, lcar1, 5)
gmsh.modelGeoAddPoint(0.5,0,0, lcar1, 6)
gmsh.modelGeoAddPoint(0,0.5,0, lcar1, 7)
gmsh.modelGeoAddPoint(0,1,0, lcar1, 8)
gmsh.modelGeoAddPoint(1,1,0, lcar1, 9)
gmsh.modelGeoAddPoint(0,0,1, lcar1, 10)
gmsh.modelGeoAddPoint(0,1,1, lcar1, 11)
gmsh.modelGeoAddPoint(1,1,1, lcar1, 12)
gmsh.modelGeoAddPoint(1,0,1, lcar1, 13)
gmsh.modelGeoAddPoint(1,0,0, lcar1, 14)

gmsh.modelGeoAddLine(8,9, 1);   gmsh.modelGeoAddLine(9,12, 2)
gmsh.modelGeoAddLine(12,11, 3); gmsh.modelGeoAddLine(11,8, 4)
gmsh.modelGeoAddLine(9,14, 5);  gmsh.modelGeoAddLine(14,13, 6)
gmsh.modelGeoAddLine(13,12, 7); gmsh.modelGeoAddLine(11,10, 8)
gmsh.modelGeoAddLine(10,13, 9); gmsh.modelGeoAddLine(10,4, 10)
gmsh.modelGeoAddLine(4,5, 11);  gmsh.modelGeoAddLine(5,6, 12)
gmsh.modelGeoAddLine(6,2, 13);  gmsh.modelGeoAddLine(2,1, 14)
gmsh.modelGeoAddLine(1,3, 15);  gmsh.modelGeoAddLine(3,7, 16)
gmsh.modelGeoAddLine(7,2, 17);  gmsh.modelGeoAddLine(3,4, 18)
gmsh.modelGeoAddLine(5,1, 19);  gmsh.modelGeoAddLine(7,8, 20)
gmsh.modelGeoAddLine(6,14, 21); 

gmsh.modelGeoAddLineLoop([-11,-19,-15,-18], 22)
gmsh.modelGeoAddPlaneSurface([22], 23)
gmsh.modelGeoAddLineLoop([16,17,14,15], 24)
gmsh.modelGeoAddPlaneSurface([24], 25)
gmsh.modelGeoAddLineLoop([-17,20,1,5,-21,13], 26)
gmsh.modelGeoAddPlaneSurface([26], 27)
gmsh.modelGeoAddLineLoop([-4,-1,-2,-3], 28)
gmsh.modelGeoAddPlaneSurface([28], 29)
gmsh.modelGeoAddLineLoop([-7,2,-5,-6], 30)
gmsh.modelGeoAddPlaneSurface([30], 31)
gmsh.modelGeoAddLineLoop([6,-9,10,11,12,21], 32)
gmsh.modelGeoAddPlaneSurface([32], 33)
gmsh.modelGeoAddLineLoop([7,3,8,9], 34)
gmsh.modelGeoAddPlaneSurface([34], 35)
gmsh.modelGeoAddLineLoop([-10,18,-16,-20,4,-8], 36)
gmsh.modelGeoAddPlaneSurface([36], 37)
gmsh.modelGeoAddLineLoop([-14,-13,-12,19], 38)
gmsh.modelGeoAddPlaneSurface([38], 39)

shells = gmsh.IntVector(); volumes = gmsh.IntVector()

# When the tag is not specified, a new one is automatically provided
sl = gmsh.modelGeoAddSurfaceLoop([35,31,29,37,33,23,39,25,27])
shells.push_back(sl)

def cheeseHole(x, y, z, r, lc, shells, volumes):
    p1 = gmsh.modelGeoAddPoint(x,  y,  z,   lc)
    p2 = gmsh.modelGeoAddPoint(x+r,y,  z,   lc)
    p3 = gmsh.modelGeoAddPoint(x,  y+r,z,   lc)
    p4 = gmsh.modelGeoAddPoint(x,  y,  z+r, lc)
    p5 = gmsh.modelGeoAddPoint(x-r,y,  z,   lc)
    p6 = gmsh.modelGeoAddPoint(x,  y-r,z,   lc)
    p7 = gmsh.modelGeoAddPoint(x,  y,  z-r, lc)

    c1 = gmsh.modelGeoAddCircleArc(p2,p1,p7)
    c2 = gmsh.modelGeoAddCircleArc(p7,p1,p5)
    c3 = gmsh.modelGeoAddCircleArc(p5,p1,p4)
    c4 = gmsh.modelGeoAddCircleArc(p4,p1,p2)
    c5 = gmsh.modelGeoAddCircleArc(p2,p1,p3)
    c6 = gmsh.modelGeoAddCircleArc(p3,p1,p5)
    c7 = gmsh.modelGeoAddCircleArc(p5,p1,p6)
    c8 = gmsh.modelGeoAddCircleArc(p6,p1,p2)
    c9 = gmsh.modelGeoAddCircleArc(p7,p1,p3)
    c10 = gmsh.modelGeoAddCircleArc(p3,p1,p4)
    c11 = gmsh.modelGeoAddCircleArc(p4,p1,p6)
    c12 = gmsh.modelGeoAddCircleArc(p6,p1,p7)
    
    l1 = gmsh.modelGeoAddLineLoop([c5,c10,c4])
    l2 = gmsh.modelGeoAddLineLoop([c9,-c5,c1])
    l3 = gmsh.modelGeoAddLineLoop([c12,-c8,-c1])
    l4 = gmsh.modelGeoAddLineLoop([c8,-c4,c11])
    l5 = gmsh.modelGeoAddLineLoop([-c10,c6,c3])
    l6 = gmsh.modelGeoAddLineLoop([-c11,-c3,c7])
    l7 = gmsh.modelGeoAddLineLoop([-c2,-c7,-c12])
    l8 = gmsh.modelGeoAddLineLoop([-c6,-c9,c2])
    
    s1 = gmsh.modelGeoAddSurfaceFilling([l1])
    s2 = gmsh.modelGeoAddSurfaceFilling([l2])
    s3 = gmsh.modelGeoAddSurfaceFilling([l3])
    s4 = gmsh.modelGeoAddSurfaceFilling([l4])
    s5 = gmsh.modelGeoAddSurfaceFilling([l5])
    s6 = gmsh.modelGeoAddSurfaceFilling([l6])
    s7 = gmsh.modelGeoAddSurfaceFilling([l7])
    s8 = gmsh.modelGeoAddSurfaceFilling([l8])
    
    sl = gmsh.modelGeoAddSurfaceLoop([s1, s2, s3, s4, s5, s6, s7, s8])
    v = gmsh.modelGeoAddVolume([sl])
    shells.append(sl)
    volumes.append(v)

x = 0; y = 0.75; z = 0; r = 0.09
for t in range(1, 6):
    x += 0.166 ;
    z += 0.166 ;
    cheeseHole(x, y, z, r, lcar3, shells, volumes);
    gmsh.modelAddPhysicalGroup(3, [volumes.back()], t);

gmsh.modelGeoAddVolume(shells, 186);
      
gmsh.modelAddPhysicalGroup(3, [186], 10);
gmsh.modelGeoSynchronize()
gmsh.modelMeshGenerate(3)
gmsh.write("t5.msh")

gmsh.finalize()
