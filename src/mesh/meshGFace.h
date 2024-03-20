// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_H
#define MESH_GFACE_H

#include <vector>
#include <set>
#include <list>
#include "SPoint2.h"
#include "SVector3.h"
#include "MElementOctree.h"

class GEdge;
class GFace;
class MVertex;

// Create the mesh of the face
class meshGFace {
  const bool repairSelfIntersecting1dMesh;

public:
  meshGFace(bool r = true) : repairSelfIntersecting1dMesh(r) {}
  void operator()(GFace *, bool print = true);
};

// Destroy the mesh of the face
class deMeshGFace {
public:
  deMeshGFace() {}
  void operator()(GFace *);
};

// Orient the mesh of a face to match the orientation of the underlying
// geometry. This is necessary for 3 different reasons:
// 1) some surface mesh algorithms do not respect the original geometrical
//    orientation
// 2) some volume algorithms need to change the surface mesh orientation
// 3) users can choose to reverse the natural orientation
class orientMeshGFace {
public:
  void operator()(GFace *);
};

void findTransfiniteCorners(GFace *gf, std::vector<MVertex *> &corners);
int MeshTransfiniteSurface(GFace *gf);
int MeshExtrudedSurface(
  GFace *gf,
  std::set<std::pair<MVertex *, MVertex *> > *constrainedEdges = nullptr);
bool pointInsideParametricDomain(std::vector<SPoint2> &bnd, SPoint2 &p,
                                 SPoint2 &out, int &N);

/**
 * @brief Automatically set transfinite constraints on curves and faces
 *        in the candidate_faces if possible. Curves on opposide sides
 *        of rectangular faces are constrained to reiceive the same number
 *        of points.
 *
 * @param candidate_faces The faces which are candidate for transfinite
 * @param cornerAngle Threshold on the angle (viewed from face) at corners
 * @param setRecombine If true, quads will be built instead of triangles when
 * meshing
 * @param maxDiffRel Reject transfinite constraints if the relative difference
 * on the initial number of lines (from sizing constraints) on opposite sides is
 * larger than the maxDiffRel
 * @param ignoreEmbedded If true, ignore embedded edges and vertices in faces
 *
 * @return true if success
 */
bool MeshSetTransfiniteFacesAutomatic(std::set<GFace *> &candidate_faces,
                                      double cornerAngle = 2.35,
                                      bool setRecombine = true,
                                      double maxDiffRel = 1.,
                                      bool ignoreEmbedded = false);

#endif
