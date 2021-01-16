// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_H
#define MESH_GREGION_H

#include <list>
#include <vector>
#include <map>
#include "MFace.h"

class GModel;
class GRegion;
class GFace;
class GEdge;
class MVertex;
class MLine;
class MTriangle;

// Create the mesh of the region
class meshGRegion {
public:
  std::vector<GRegion *> &delaunay;
  meshGRegion(std::vector<GRegion *> &d) : delaunay(d) {}
  void operator()(GRegion *);
};

class meshGRegionExtruded {
public:
  void operator()(GRegion *);
};

// Optimize the mesh of the region using gmsh's algo
class optimizeMeshGRegion {
public:
  void operator()(GRegion *, bool always = false);
};

// Optimize the mesh of the region using netgen's algo
class optimizeMeshGRegionNetgen {
public:
  void operator()(GRegion *, bool always = false);
};

// destroy the mesh of the region
class deMeshGRegion {
public:
  void operator()(GRegion *);
};

void MeshDelaunayVolume(std::vector<GRegion *> &delaunay);
bool CreateAnEmptyVolumeMesh(GRegion *gr);
int MeshTransfiniteVolume(GRegion *gr);
int SubdivideExtrudedMesh(GModel *m);
void carveHole(GRegion *gr, int num, double distance,
               std::vector<int> &surfaces);

typedef std::map<MFace, GFace *, MFaceLessThan> fs_cont;
typedef std::multimap<MVertex *, std::pair<MLine *, GEdge *> > es_cont;
GFace *findInFaceSearchStructure(MVertex *p1, MVertex *p2, MVertex *p3,
                                 const fs_cont &search);
GFace *findInFaceSearchStructure(const MFace &f, const fs_cont &search);
GEdge *findInEdgeSearchStructure(MVertex *p1, MVertex *p2,
                                 const es_cont &search);
bool buildFaceSearchStructure(GModel *model, fs_cont &search,
                              bool onlyTriangles = false);
bool buildEdgeSearchStructure(GModel *model, es_cont &search);

// hybrid mesh recovery structure
class splitQuadRecovery {
private:
  std::map<MFace, MVertex *, MFaceLessThan> _quad;
  std::map<MFace, GFace *, MFaceLessThan> _tri;

public:
  splitQuadRecovery() {}
  void add(const MFace &f, MVertex *v, GFace *gf);
  std::map<MFace, GFace *, MFaceLessThan> &getTri() { return _tri; }
  std::map<MFace, MVertex *, MFaceLessThan> &getQuad() { return _quad; }
  int buildPyramids(GModel *gm);
};

// adapt the mesh of a region
class adaptMeshGRegion {
public:
  void operator()(GRegion *);
};

#endif
