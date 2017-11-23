#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t16.geo in Python.

from gmsh import *
import math

gmshInitialize()
gmshOptionSetNumber("General.Terminal", 1)

gmshModelCreate("t16")

ov = PairVector(); ovv = PairVectorVector()

gmshModelOccAddBox(0,0,0, 1,1,1, 1)
gmshModelOccAddBox(0,0,0, 0.5,0.5,0.5, 2)
gmshModelOccBooleanDifference([(3,1)], [(3,2)], ov, ovv, 3)

x = 0; y = 0.75; z = 0; r = 0.09

holes = PairVector()
for t in range(1, 6):
    x += 0.166
    z += 0.166
    gmshModelOccAddSphere(x,y,z,r, 3 + t)
    holes.append((3, 3 + t))

gmshModelOccBooleanFragments([(3,3)], holes, ov, ovv)

gmshModelOccSynchronize()

lcar1 = .1
lcar2 = .0005
lcar3 = .055

gmshModelGetEntities(ov, 0);
gmshModelSetMeshSize(ov, lcar1);

gmshModelGetBoundary(holes, ov, False, False, True);
gmshModelSetMeshSize(ov, lcar3);

eps = 1e-3
gmshModelGetEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                  0.5+eps, 0.5+eps, 0.5+eps, ov, 0)
gmshModelSetMeshSize(ov, lcar2)

gmshModelMesh(3)

gmshExport("t16.msh")

gmshFinalize()
