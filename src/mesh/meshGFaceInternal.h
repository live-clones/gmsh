// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_INTERNAL_H
#define MESH_GFACE_INTERNAL_H

#include <vector>

class GFace;
class GEdge;

// Internal entry point of the 2D mesher, shared between meshGFace.cpp and the
// boundary layer code. Not part of the public surface meshing API: use the
// meshGFace functor in meshGFace.h for that.
//
// onlyInitialMesh: 0 = mesh fully, 1 = stop after the initial mesh,
// 99 = called back from the boundary layer code, which means "mesh fully but
// do not recombine" (the recombination happens once, on the final mesh).
// FIXME: this wants to be an enum.
//
// replacementEdges: mesh the face against these curves instead of its own;
// used by the boundary layer code to remesh against the boundary layer front.
bool meshGenerator(GFace *gf, int RECUR_ITER, bool repairSelfIntersecting1dMesh,
                   int onlyInitialMesh, bool debug,
                   std::vector<GEdge *> *replacementEdges);

#endif
