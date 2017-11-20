#!/usr/bin/env python

# This file reimplements gmsh/tutorial/t1.geo in Python. 

# For all the elementary explanations about the general philosphy of entities in
# Gmsh, see the comments in the .geo file. Comments here focus on the specifics
# of the Python API.

# The API is entirely defined in the gmsh module
from gmsh import *

# Before using any functions in the Python API, Gmsh must be initialized.
gmshInitialize()

# By default Gmsh will not print out any messages: in order to output messages
# on the terminal, just set the standard Gmsh option "General.Terminal" (same
# format and meaning as in .geo files) using gmshOptionSetNumber():
gmshOptionSetNumber("General.Terminal", 1)

# This creates a new model, named "t1". If gmshModelCreate() is not called, a
# new default (unnamed) model will be created on the fly, if necessary.
gmshModelCreate("t1")

# The Python API provides direct access to the internal CAD kernels. The
# built-in CAD kernel was used in t1.geo: the corresponding API functions have
# the "gmshModeGeo" prefix. To create geometrical points with the built-in CAD
# kernel, one thus uses gmshModelGeoAddPoint():
#
# - the first 3 arguments are the point coordinates (x, y, z)
#
# - the next (optional) argument is the target mesh size close to the point
#
# - the last (optional) argument is the point tag
lc = 1e-2
gmshModelGeoAddPoint(0, 0, 0, lc, 1)
gmshModelGeoAddPoint(.1, 0,  0, lc, 2)
gmshModelGeoAddPoint(.1, .3, 0, lc, 3)
gmshModelGeoAddPoint(0, .3, 0, lc, 4)

# The API to create lines with the built-in kernel follows the same
# conventions: the first 2 arguments are point tags, the last (optional one)
# is the line tag.
gmshModelGeoAddLine(1, 2, 1)
gmshModelGeoAddLine(3, 2, 2)
gmshModelGeoAddLine(3, 4, 3)
gmshModelGeoAddLine(4, 1, 4)

# The philosophy to construct line loops and surfaces is similar: the first
# argument is now a vector of integers.
gmshModelGeoAddLineLoop([4, 1, -2, 3], 1)
gmshModelGeoAddPlaneSurface([1], 1)

# Physical groups are defined by providing the dimension of the group (0 for
# physical points, 1 for physical lines, 2 for physical surfaces and 3 for
# phsyical volumes) followed by a vector of entity tags. The last (optional)
# argument is the tag of the new group to create.
gmshModelAddPhysicalGroup(0, [1, 2], 1)
gmshModelAddPhysicalGroup(1, [1, 2], 2)
gmshModelAddPhysicalGroup(2, [1], 6)

# Physical names are also defined by providing the dimension and tag of the
# entity.
gmshModelSetPhysicalName(2, 6, "My surface")

# Before it can be meshed, the internal CAD representation must be synchronized
# with the Gmsh model, which will create the relevant Gmsh data structures. This
# is achieved by the gmshModelGeoSynchronize() API call for the built-in CAD
# kernel. Synchronizations can be called at any time, but they involve a non
# trivial amount of processing; so while you could synchronize the internal CAD
# data after every CAD command, it is usually better to minimize the number of
# synchronization points.
gmshModelGeoSynchronize()

# We can then generate a 2D mesh...
gmshModelMesh(2)

# ... and save it to disk
gmshExport("t1.msh")

# This should be called at the end:
gmshFinalize()
