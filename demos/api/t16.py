#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t16.geo in Python.

import gmsh
import math

gmsh.initialize()
gmsh.optionSetNumber("General.Terminal", 1)

gmsh.modelAdd("t16")

ov = gmsh.PairVector(); ovv = gmsh.PairVectorVector()

gmsh.modelOccAddBox(0,0,0, 1,1,1, 1)
gmsh.modelOccAddBox(0,0,0, 0.5,0.5,0.5, 2)
gmsh.modelOccBooleanDifference([(3,1)], [(3,2)], ov, ovv, 3)

x = 0; y = 0.75; z = 0; r = 0.09

holes = gmsh.PairVector()
for t in range(1, 6):
    x += 0.166
    z += 0.166
    gmsh.modelOccAddSphere(x,y,z,r, 3 + t)
    holes.append((3, 3 + t))

gmsh.modelOccBooleanFragments([(3,3)], holes, ov, ovv)

gmsh.modelOccSynchronize()

lcar1 = .1
lcar2 = .0005
lcar3 = .055

gmsh.modelGetEntities(ov, 0);
gmsh.modelMeshSetSize(ov, lcar1);

gmsh.modelGetBoundary(holes, ov, False, False, True);
gmsh.modelMeshSetSize(ov, lcar3);

eps = 1e-3
gmsh.modelGetEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                  0.5+eps, 0.5+eps, 0.5+eps, ov, 0)
gmsh.modelMeshSetSize(ov, lcar2)

gmsh.modelMeshGenerate(3)

gmsh.write("t16.msh")

gmsh.finalize()
