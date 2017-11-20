#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t10.geo in Python.

from gmsh import *
import math

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("t10")

lc = .15
gmshModelGeoAddPoint(0.0,0.0,0, lc, 1)
gmshModelGeoAddPoint(1,0.0,0, lc, 2)
gmshModelGeoAddPoint(1,1,0, lc, 3)
gmshModelGeoAddPoint(0,1,0, lc, 4)
gmshModelGeoAddPoint(0.2,.5,0, lc, 5)

gmshModelGeoAddLine(1,2, 1);
gmshModelGeoAddLine(2,3, 2);
gmshModelGeoAddLine(3,4, 3);
gmshModelGeoAddLine(4,1, 4);

gmshModelGeoAddLineLoop([1,2,3,4], 5)
gmshModelGeoAddPlaneSurface([5], 6)

gmshModelFieldCreate("Attractor", 1)
gmshModelFieldSetNumbers(1, "NodesList", [5])
gmshModelFieldSetNumber(1, "NNodesByEdge", 100)
gmshModelFieldSetNumbers(1, "EdgesList", [2])

gmshModelFieldCreate("Threshold", 2);
gmshModelFieldSetNumber(2, "IField", 1);
gmshModelFieldSetNumber(2, "LcMin", lc / 30)
gmshModelFieldSetNumber(2, "LcMax", lc)
gmshModelFieldSetNumber(2, "DistMin", 0.15)
gmshModelFieldSetNumber(2, "DistMax", 0.5)

gmshModelFieldCreate("MathEval", 3)
gmshModelFieldSetString(3, "F", "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101")

gmshModelFieldCreate("Attractor", 4)
gmshModelFieldSetNumbers(4, "NodesList", [1])

gmshModelFieldCreate("MathEval", 5);
gmshModelFieldSetString(5, "F", "F4^3 + " + str(lc / 100))

gmshModelFieldCreate("Box", 6)
gmshModelFieldSetNumber(6, "VIn", lc / 15)
gmshModelFieldSetNumber(6, "VOut", lc)
gmshModelFieldSetNumber(6, "XMin", 0.3)
gmshModelFieldSetNumber(6, "XMax", 0.6)
gmshModelFieldSetNumber(6, "YMin", 0.3)
gmshModelFieldSetNumber(6, "YMax", 0.6)

gmshModelFieldCreate("Min", 7)
gmshModelFieldSetNumbers(7, "FieldsList", [2, 3, 5, 6])

gmshModelFieldSetAsBackground(7)

gmshModelGeoSynchronize()
gmshModelMesh(2)
gmshExport("t10.msh")
