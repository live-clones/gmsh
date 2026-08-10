// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_OPTIMIZE_FLAT_H
#define MESH_GREGION_OPTIMIZE_FLAT_H

#include "qualityMeasures.h"

class GRegion;

// Flat-array port of optimizeMesh(): same edge swaps and same node
// relocations, but on index-based arrays instead of the MTet4/MTetrahedron
// object graph. Only the tets of the region are optimized; any other element
// is left untouched, and nodes are then not relocated, as they may belong to
// one. Returns false when the region cannot be handled, in which case the
// caller must fall back to the object-based optimizer.
bool optimizeMeshFlat(GRegion *gr, const qmTetrahedron::Measures &qm);

#endif
