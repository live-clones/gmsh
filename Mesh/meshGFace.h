// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_H_
#define _MESH_GFACE_H_

#include <vector>
#include <set>

class GFace;
class MVertex;

// Create the mesh of the face
class meshGFace {
  const bool repairSelfIntersecting1dMesh;
 public :
  meshGFace (bool r = true) : repairSelfIntersecting1dMesh(r) {}
  void operator () (GFace *);
};

// Destroy the mesh of the face
class deMeshGFace {
 public :
  void operator () (GFace *);
};

// Orient the mesh of a face to match the orientation of the
// underlying geometry. This is doubly useful: 
// 1) some surface mesh algorithms do not respect the original
//    geometrical orientation and
// 2) some volume algorithms need to change the surface mesh
//    orientation
class orientMeshGFace {
  public :
  void operator () (GFace *);
};

void fourthPoint(double *p1, double *p2, double *p3, double *p4);
void findTransfiniteCorners(GFace *gf, std::vector<MVertex*> &corners);
int MeshTransfiniteSurface(GFace *gf);
int MeshExtrudedSurface(GFace *gf, std::set<std::pair<MVertex*, MVertex*> > 
                        *constrainedEdges=0);

#endif
