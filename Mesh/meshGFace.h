// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  bool onlyInitialMesh;

public:
  meshGFace(bool r = true)
    : repairSelfIntersecting1dMesh(r), onlyInitialMesh(false)
  {
  }
  void operator()(GFace *, bool print = true);
  void setOnlyInitial() { onlyInitialMesh = true; }
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

void fourthPoint(double *p1, double *p2, double *p3, double *p4);
void findTransfiniteCorners(GFace *gf, std::vector<MVertex *> &corners);
int MeshTransfiniteSurface(GFace *gf);
int MeshExtrudedSurface(
  GFace *gf, std::set<std::pair<MVertex *, MVertex *> > *constrainedEdges = 0);
bool meshGenerator(GFace *gf, int RECUR_ITER, bool repairSelfIntersecting1dMesh,
                   bool onlyInitialMesh, bool debug = true,
                   std::vector<GEdge *> *replacement_edges = 0);
bool pointInsideParametricDomain(std::vector<SPoint2> &bnd, SPoint2 &p,
                                 SPoint2 &out, int &N);

#endif
