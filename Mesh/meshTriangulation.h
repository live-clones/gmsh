// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_TRIANGULATION_H
#define MESH_TRIANGULATION_H

#include "meshPolyMesh.h"

// returns a PolyMesh i.e. a half edge data structure that
// is actually the triangulation face boundary
// if recover = 1 --> edges are recovered and
// the triangulation is colored : triangles belonging
// to the model face are colored faceTag, other have negative colors.
PolyMesh *GFaceInitialMesh(int faceTag, int recover = 0);
// apply Delaunay refinement using old algorithms
// FIXME -- not working yet
void GFaceDelaunayRefinementOldMesher(int faceTag);
void GFaceDelaunayRefinement(int faceTag);
int GFace2PolyMesh(int faceTag, PolyMesh **pm);
// int PolyMesh2GFace (const PolyMesh *pm, size_t faceTag);

#endif
