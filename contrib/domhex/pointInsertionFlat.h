// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Frontal point insertion for hex-dominant meshes: a front of candidate
// points, from the boundary vertices along the local frame and size, each
// accepted when inside the domain, far enough from the boundary and from the
// points already accepted. Flat storage (arrays and integer indices) and a
// uniform spatial hash for the spacing test.

#ifndef POINT_INSERTION_FLAT_H
#define POINT_INSERTION_FLAT_H

#include "meshCombine3D.h"

class GRegion;

// Fills gr with interior points, then tetrahedralizes them with its boundary.
// If frames is given, it receives the frame and the size of each point, the
// boundary vertices included.
void fillRegionFlat(GRegion *gr, CombineFrames *frames = nullptr);

#endif
