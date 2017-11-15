#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t2.geo in Python. Comments focus on the new
# API functions used, compared to the ones introduced in t1.py.

from gmsh import *
import sys

# If sys.argv is passed, Gmsh will parse the commandline in the same way as the
# standalone Gmsh code.
gmshInitialize(sys.argv);

gmshOptionSetNumber("General.Terminal", 1);

gmshModelCreate("t2");

# Copied from t1.py...
lc = 1e-2;
gmshModelGeoAddPoint(1, 0, 0, 0, lc);
gmshModelGeoAddPoint(2, .1, 0,  0, lc);
gmshModelGeoAddPoint(3, .1, .3, 0, lc);
gmshModelGeoAddPoint(4, 0,  .3, 0, lc);

gmshModelGeoAddLine(1, 1, 2);
gmshModelGeoAddLine(2, 3, 2);
gmshModelGeoAddLine(3, 3, 4);
gmshModelGeoAddLine(4, 4, 1);

gmshModelGeoAddLineLoop(1, [4, 1, -2, 3]);
gmshModelGeoAddPlaneSurface(1, [1]);
gmshModelAddPhysicalGroup(0, 1, [1, 2]);
gmshModelAddPhysicalGroup(1, 2, [1, 2]);
gmshModelAddPhysicalGroup(2, 6, [1]);
gmshModelSetPhysicalName(2, 6, "My surface");
# ...end of copy

gmshModelGeoAddPoint(5, 0, .4, 0, lc);
gmshModelGeoAddLine(5, 4, 5);

# Geometrical transformations take a vector of pairs of integers as first
# argument, which contains the list of entities, represented by (dimension, tag)
# pairs. Here we thus translate point 3 (dimension=0, tag=3), by dx=-0.05, dy=0,
# dz=0.
gmshModelGeoTranslate([(0, 3)], -0.05, 0, 0);

# The "Duplicata" functionality in .geo files is handled by
# gmshModelGeoCopy(), which takes a vector of (dim, tag) pairs as input, and
# returns another vector of (dim, tag) pairs.

ov = PairVector()
gmshModelGeoCopy([(0, 3)], ov);
gmshModelGeoTranslate(ov, 0, 0.1, 0);

gmshModelGeoAddLine(7, 3, ov[0][1]);
gmshModelGeoAddLine(8, ov[0][1], 5);
gmshModelGeoAddLineLoop(10, [5,-8,-7,3]);
gmshModelGeoAddPlaneSurface(11, [10]);

gmshModelGeoCopy([(2, 1), (2, 11)], ov);
gmshModelGeoTranslate(ov, 0.12, 0, 0);

print "New surfaces '%d' and '%d'\n", ov[0][1], ov[1][1];

gmshModelGeoAddPoint(100, 0., 0.3, 0.13, lc);
gmshModelGeoAddPoint(101, 0.08, 0.3, 0.1, lc);
gmshModelGeoAddPoint(102, 0.08, 0.4, 0.1, lc);
gmshModelGeoAddPoint(103, 0., 0.4, 0.13, lc);

gmshModelGeoAddLine(110, 4, 100);
gmshModelGeoAddLine(111, 3, 101);
gmshModelGeoAddLine(112, 6, 102);
gmshModelGeoAddLine(113, 5, 103);
gmshModelGeoAddLine(114, 103, 100);
gmshModelGeoAddLine(115, 100, 101);
gmshModelGeoAddLine(116, 101, 102);
gmshModelGeoAddLine(117, 102, 103);

gmshModelGeoAddLineLoop(118, [115, -111, 3, 110]);
gmshModelGeoAddPlaneSurface(119, [118]);
gmshModelGeoAddLineLoop(120, [111, 116, -112, -7]);
gmshModelGeoAddPlaneSurface(121, [120]);
gmshModelGeoAddLineLoop(122, [112, 117, -113, -8]);
gmshModelGeoAddPlaneSurface(123, [122]);
gmshModelGeoAddLineLoop(124, [114, -110, 5, 113]);
gmshModelGeoAddPlaneSurface(125, [124]);
gmshModelGeoAddLineLoop(126, [115, 116, 117, 114]);
gmshModelGeoAddPlaneSurface(127, [126]);

# The API to create surface loops ("shells") and volumes is similar to the
# one used to create line loops and surfaces.
gmshModelGeoAddSurfaceLoop(128, [127, 119, 121, 123, 125, 11]);
gmshModelGeoAddVolume(129, [128]);

# Extrusion works as expected, by providing a vector of (dim, tag) pairs as
# input, the translation vector, and a vector of (dim, tag) pairs as output.
ov2 = PairVector()
gmshModelGeoExtrude([ov[1]], 0, 0, 0.12, ov2);

# Mesh sizes associated to geometrical points can be set by passing a vector of
# (dim, tag) pairs for the corresponding points.

gmshModelGeoSetMeshSize([(0,103), (0,105), (0,109), (0,102), (0,28),
                         (0, 24), (0,6), (0,5)], lc * 3);

gmshModelAddPhysicalGroup(3, 1, [129,130]);
gmshModelSetPhysicalName(3, 1, "The volume");

gmshModelGeoSynchronize();

gmshModelMesh(3);

gmshExport("t2.msh");

gmshFinalize();
