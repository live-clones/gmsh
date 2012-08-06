// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GREGION_H_
#define _MESH_GREGION_H_

#include <vector>
#include <map>

class GModel;
class GRegion;
class GFace;
class GEdge;
class MVertex;
class MLine;
class MTriangle;

// Create the mesh of the region
class meshGRegion {
 public :
  std::vector<GRegion*> &delaunay;
  meshGRegion(std::vector<GRegion*> &d) : delaunay(d) {}
  void operator () (GRegion *);
};

class meshGRegionExtruded {
 public :
  void operator () (GRegion *);
};

// Optimize the mesh of the region using gmsh's algo
class optimizeMeshGRegionGmsh {
 public :
  void operator () (GRegion *);
};

// Optimize the mesh of the region using netgen's algo
class optimizeMeshGRegionNetgen {
 public :
  void operator () (GRegion *);
};

// destroy the mesh of the region
class deMeshGRegion {
 public :
  void operator () (GRegion *);
};

void MeshDelaunayVolume(std::vector<GRegion*> &delaunay);
int MeshTransfiniteVolume(GRegion *gr);
int SubdivideExtrudedMesh(GModel *m);
void carveHole(GRegion *gr, int num, double distance, std::vector<int> &surfaces);

typedef std::multimap<MVertex*, std::pair<MTriangle*, GFace*> > fs_cont ;
typedef std::multimap<MVertex*, std::pair<MLine*, GEdge*> > es_cont ;
GFace* findInFaceSearchStructure(MVertex *p1, MVertex *p2, MVertex *p3, 
                                 const fs_cont &search);
GEdge* findInEdgeSearchStructure(MVertex *p1, MVertex *p2, const es_cont &search);
bool buildFaceSearchStructure(GModel *model, fs_cont &search);
bool buildEdgeSearchStructure(GModel *model, es_cont &search);

// adapt the mesh of a region
class adaptMeshGRegion {
  es_cont *_es;
  fs_cont *_fs;
 public :
  void operator () (GRegion *);
};



#endif
