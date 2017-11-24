# This file reimplements gmsh/tutorial/t4.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t4")

cm = 1e-02
e1 = 4.5 * cm; e2 = 6 * cm / 2; e3 =  5 * cm / 2
h1 = 5 * cm; h2 = 10 * cm; h3 = 5 * cm; h4 = 2 * cm; h5 = 4.5 * cm
R1 = 1 * cm; R2 = 1.5 * cm; r = 1 * cm
Lc1 = 0.01
Lc2 = 0.003

def hypot(a, b):
    return math.sqrt(a * a + b * b)

ccos = (-h5*R1 + e2 * hypot(h5, hypot(e2, R1))) / (h5*h5 + e2*e2)
ssin = math.sqrt(1 - ccos*ccos)

gmsh.modelGeoAddPoint(-e1-e2, 0    , 0, Lc1, 1)
gmsh.modelGeoAddPoint(-e1-e2, h1   , 0, Lc1, 2)
gmsh.modelGeoAddPoint(-e3-r , h1   , 0, Lc2, 3)
gmsh.modelGeoAddPoint(-e3-r , h1+r , 0, Lc2, 4)
gmsh.modelGeoAddPoint(-e3   , h1+r , 0, Lc2, 5)
gmsh.modelGeoAddPoint(-e3   , h1+h2, 0, Lc1, 6)
gmsh.modelGeoAddPoint( e3   , h1+h2, 0, Lc1, 7)
gmsh.modelGeoAddPoint( e3   , h1+r , 0, Lc2, 8)
gmsh.modelGeoAddPoint( e3+r , h1+r , 0, Lc2, 9)
gmsh.modelGeoAddPoint( e3+r , h1   , 0, Lc2, 10)
gmsh.modelGeoAddPoint( e1+e2, h1   , 0, Lc1, 11)
gmsh.modelGeoAddPoint( e1+e2, 0    , 0, Lc1, 12)
gmsh.modelGeoAddPoint( e2   , 0    , 0, Lc1, 13)

gmsh.modelGeoAddPoint( R1 / ssin, h5+R1*ccos, 0, Lc2, 14)
gmsh.modelGeoAddPoint( 0        , h5        , 0, Lc2, 15)
gmsh.modelGeoAddPoint(-R1 / ssin, h5+R1*ccos, 0, Lc2, 16)
gmsh.modelGeoAddPoint(-e2       , 0.0       , 0, Lc1, 17)

gmsh.modelGeoAddPoint(-R2 , h1+h3   , 0, Lc2, 18)
gmsh.modelGeoAddPoint(-R2 , h1+h3+h4, 0, Lc2, 19)
gmsh.modelGeoAddPoint( 0  , h1+h3+h4, 0, Lc2, 20)
gmsh.modelGeoAddPoint( R2 , h1+h3+h4, 0, Lc2, 21)
gmsh.modelGeoAddPoint( R2 , h1+h3   , 0, Lc2, 22)
gmsh.modelGeoAddPoint( 0  , h1+h3   , 0, Lc2, 23)
                                                
gmsh.modelGeoAddPoint( 0, h1+h3+h4+R2, 0, Lc2, 24)
gmsh.modelGeoAddPoint( 0, h1+h3-R2,    0, Lc2, 25)

gmsh.modelGeoAddLine(1 , 17, 1)
gmsh.modelGeoAddLine(17, 16, 2)

gmsh.modelGeoAddCircleArc(14,15,16, 3)
gmsh.modelGeoAddLine(14,13, 4)
gmsh.modelGeoAddLine(13,12, 5)
gmsh.modelGeoAddLine(12,11, 6)
gmsh.modelGeoAddLine(11,10, 7)
gmsh.modelGeoAddCircleArc(8,9,10, 8)
gmsh.modelGeoAddLine(8,7, 9)
gmsh.modelGeoAddLine(7,6, 10)
gmsh.modelGeoAddLine(6,5, 11)
gmsh.modelGeoAddCircleArc(3,4,5, 12)
gmsh.modelGeoAddLine(3,2, 13)
gmsh.modelGeoAddLine(2,1, 14)
gmsh.modelGeoAddLine(18,19, 15)
gmsh.modelGeoAddCircleArc(21,20,24, 16)
gmsh.modelGeoAddCircleArc(24,20,19, 17)
gmsh.modelGeoAddCircleArc(18,23,25, 18)
gmsh.modelGeoAddCircleArc(25,23,22, 19)
gmsh.modelGeoAddLine(21,22, 20)

gmsh.modelGeoAddLineLoop([17,-15,18,19,-20,16], 21)
gmsh.modelGeoAddPlaneSurface([21], 22)
gmsh.modelGeoAddLineLoop([11,-12,13,14,1,2,-3,4,5,6,7,-8,9,10], 23)

# A surface with one hole is specified using 2 line loops:
gmsh.modelGeoAddPlaneSurface([23,21], 24)

# FIXME: this will be implemented through the gmshView API
#  View "comments" {
#    T2(10, -10, 0){ StrCat("Created on ", Today, " with Gmsh") };
#    T3(0, 0.11, 0, TextAttributes("Align", "Center", "Font", "Helvetica")){ "Hole" };
#    T3(0, 0.09, 0, TextAttributes("Align", "Center")){ "file://image.png@0.01x0" };
#    T3(-0.01, 0.09, 0, 0){ "file://image.png@0.01x0,0,0,1,0,1,0" };
#    T3(0, 0.12, 0, TextAttributes("Align", "Center")){ "file://image.png@0.01x0#" };
#    T2(350, -7, 0){ "file://image.png@20x0" };
# };

gmsh.modelGeoSynchronize()

gmsh.modelMeshGenerate(2)

gmsh.write("t4.msh")

gmsh.finalize()
