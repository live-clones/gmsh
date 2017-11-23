#!/usr/bin/env python

from gmsh import *
import sys

gmshInitialize(sys.argv)
gmshOptionSetNumber("General.Terminal", 1)

tri1 = [0., 1., 1.,
        0., 0., 1.,
        0., 0., 0.];
tri2 = [0., 1., 0.,
        0., 1., 1.,
        0., 0., 0.];

for step in range(0, 10):
    tri1.append(10.); tri1.append(10.); tri1.append(12. + step)
    tri2.append(10.); tri2.append(12. + step); tri2.append(13. + step)

t = gmshViewCreate("some data")

gmshViewAddListData(t, "ST", 2, tri1 + tri2)

gmshViewExport(t, "data.pos")

gmshFinalize()
