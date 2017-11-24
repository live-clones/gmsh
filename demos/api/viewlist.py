#!/usr/bin/env python

import gmsh
import sys

gmsh.initialize(sys.argv)
gmsh.optionSetNumber("General.Terminal", 1)

tri1 = [0., 1., 1.,
        0., 0., 1.,
        0., 0., 0.];
tri2 = [0., 1., 0.,
        0., 1., 1.,
        0., 0., 0.];

for step in range(0, 10):
    tri1.append(10.); tri1.append(10.); tri1.append(12. + step)
    tri2.append(10.); tri2.append(12. + step); tri2.append(13. + step)

t = gmsh.viewAdd("some data")

gmsh.viewAddListData(t, "ST", 2, tri1 + tri2)

gmsh.viewWrite(t, "data.pos")

gmsh.finalize()
