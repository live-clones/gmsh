#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t10.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t10")

lc = .15
gmsh.modelGeoAddPoint(0.0,0.0,0, lc, 1)
gmsh.modelGeoAddPoint(1,0.0,0, lc, 2)
gmsh.modelGeoAddPoint(1,1,0, lc, 3)
gmsh.modelGeoAddPoint(0,1,0, lc, 4)
gmsh.modelGeoAddPoint(0.2,.5,0, lc, 5)

gmsh.modelGeoAddLine(1,2, 1);
gmsh.modelGeoAddLine(2,3, 2);
gmsh.modelGeoAddLine(3,4, 3);
gmsh.modelGeoAddLine(4,1, 4);

gmsh.modelGeoAddLineLoop([1,2,3,4], 5)
gmsh.modelGeoAddPlaneSurface([5], 6)

gmsh.modelMeshFieldAdd("Attractor", 1)
gmsh.modelMeshFieldSetNumbers(1, "NodesList", [5])
gmsh.modelMeshFieldSetNumber(1, "NNodesByEdge", 100)
gmsh.modelMeshFieldSetNumbers(1, "EdgesList", [2])

gmsh.modelMeshFieldAdd("Threshold", 2);
gmsh.modelMeshFieldSetNumber(2, "IField", 1);
gmsh.modelMeshFieldSetNumber(2, "LcMin", lc / 30)
gmsh.modelMeshFieldSetNumber(2, "LcMax", lc)
gmsh.modelMeshFieldSetNumber(2, "DistMin", 0.15)
gmsh.modelMeshFieldSetNumber(2, "DistMax", 0.5)

gmsh.modelMeshFieldAdd("MathEval", 3)
gmsh.modelMeshFieldSetString(3, "F", "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101")

gmsh.modelMeshFieldAdd("Attractor", 4)
gmsh.modelMeshFieldSetNumbers(4, "NodesList", [1])

gmsh.modelMeshFieldAdd("MathEval", 5);
gmsh.modelMeshFieldSetString(5, "F", "F4^3 + " + str(lc / 100))

gmsh.modelMeshFieldAdd("Box", 6)
gmsh.modelMeshFieldSetNumber(6, "VIn", lc / 15)
gmsh.modelMeshFieldSetNumber(6, "VOut", lc)
gmsh.modelMeshFieldSetNumber(6, "XMin", 0.3)
gmsh.modelMeshFieldSetNumber(6, "XMax", 0.6)
gmsh.modelMeshFieldSetNumber(6, "YMin", 0.3)
gmsh.modelMeshFieldSetNumber(6, "YMax", 0.6)

gmsh.modelMeshFieldAdd("Min", 7)
gmsh.modelMeshFieldSetNumbers(7, "FieldsList", [2, 3, 5, 6])

gmsh.modelMeshFieldSetAsBackground(7)

gmsh.modelGeoSynchronize()
gmsh.modelMeshGenerate(2)
gmsh.write("t10.msh")
gmsh.finalize()

