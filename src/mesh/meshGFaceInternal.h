// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_INTERNAL_H
#define MESH_GFACE_INTERNAL_H

#include <vector>

class GFace;
class GEdge;

// How far the 2D mesher should go past the initial triangulation.
enum class MeshExtent {
  // The whole pipeline: size field, internal nodes, boundary layer, the
  // Delaunay algorithm, then recombination.
  Full,
  // Stop after the initial mesh, i.e. the triangulation of the boundary nodes
  // alone, but still recombine it (Mesh.Algorithm = ALGO_2D_INITIAL_ONLY).
  InitialOnly,
  // Same, and do not recombine either. Used when the boundary layer code calls
  // back to remesh the face against the boundary layer front: the internal
  // nodes and the recombination both happen once, afterwards, on the mesh that
  // call produces.
  BoundaryLayerRemesh
};

// Internal entry point of the 2D mesher, shared between meshGFace.cpp and the
// boundary layer code. Not part of the public surface meshing API: use the
// meshGFace functor in meshGFace.h for that.
//
// replacementEdges: mesh the face against these curves instead of its own;
// used by the boundary layer code to remesh against the boundary layer front.
bool meshGenerator(GFace *gf, int RECUR_ITER, bool repairSelfIntersecting1dMesh,
                   MeshExtent extent, bool debug,
                   std::vector<GEdge *> *replacementEdges);

#endif
