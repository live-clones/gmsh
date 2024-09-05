// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
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
PolyMesh *GFaceInitialMeshAlpha(int faceTag, int recover,
                                std::vector<double> *additional,
                                std::vector<size_t> &IND);
void GFaceDelaunayRefinement(int faceTag);
int GFace2PolyMesh(int faceTag, PolyMesh **pm);
int PolyMesh2GFace(PolyMesh *pm, int faceTag);
int meshTriangulate2d (const std::vector<double> &coord,
		       std::vector<std::size_t> &tri,
		       const std::vector<size_t> *edges_to_recover = 0);
int triangulateEntity(const int tag);
// apply Delaunay refinement using old algorithms
// FIXME -- not working yet
int recover_edge(PolyMesh *pm, PolyMesh::Vertex *v_start,
                        PolyMesh::Vertex *v_end);

void GFaceDelaunayRefinementOldMesher(int faceTag);

#endif
