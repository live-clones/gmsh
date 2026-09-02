// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_OPTIMIZE_FLAT_H
#define MESH_GREGION_OPTIMIZE_FLAT_H

// Flat-array kernel of the 3D mesh optimizer, selected with
// Mesh.FlatOptimize3D. Internal to the mesher - the entry point the rest of
// Gmsh uses is optimizeMesh() in meshGRegionDelaunay.h. Returns false when
// the region cannot be handled (the caller then falls back to the MTet4
// kernel of meshGRegionOptimize.cpp).

#include "qualityMeasures.h"

class GRegion;

bool optimizeMeshFlat(GRegion *gr, const qmTetrahedron::Measures &qm);

#endif
