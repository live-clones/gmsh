// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_BOUNDARY_LAYER_H
#define MESH_GFACE_BOUNDARY_LAYER_H

#include <set>
#include <vector>
#include "MVertex.h"

class GFace;
class MTriangle;
class MQuadrangle;

// Build the 2D boundary layer elements of a face from its boundary layer
// columns, filter the ones that overlap, and remesh the rest of the face
// against the boundary layer front. Returns the new elements and nodes in
// blQuads, blTris and verts; does nothing if the face has no boundary layer.
void modifyInitialMeshForBoundaryLayers(
  GFace *gf, std::vector<MQuadrangle *> &blQuads,
  std::vector<MTriangle *> &blTris,
  std::set<MVertex *, MVertexPtrLessThan> &verts, bool debug);

#endif
