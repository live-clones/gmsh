// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_TRIANGULATION_H
#define MESH_TRIANGULATION_H

#include "meshPolyMesh.h"
// returns a PolyMesh i.e. a half edge data structure that
// is actually the triangulation face boundary
// if recover = 1 --> edges are recovered and
// the triangulation is colored : triangles belonging
// to the model face are colored faceTag, other have negative colors.
PolyMesh *GFaceInitialMesh(int faceTag, int recover = 0,
                           std::vector<double> *additional = nullptr);
// apply Delaunay refinement using old algorithms
// FIXME -- not working yet
void GFaceDelaunayRefinementOldMesher(int faceTag);
void GFaceDelaunayRefinement(int faceTag);
int GFace2PolyMesh(int faceTag, PolyMesh **pm);
int PolyMesh2GFace(PolyMesh *pm, int faceTag);
int PolyMeshDelaunayize (int faceTag);

#endif
