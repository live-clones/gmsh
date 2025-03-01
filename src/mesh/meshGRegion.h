// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_H
#define MESH_GREGION_H

#include <list>
#include <vector>
#include <map>
#include "MFace.h"

class GModel;
class GVolume;
class GSurface;
class GCurve;
class MNode;
class MLine;
class MTriangle;

// Create the mesh of the region
class meshGRegion {
public:
  std::vector<GVolume *> &delaunay;
  meshGRegion(std::vector<GVolume *> &d) : delaunay(d) {}
  void operator()(GVolume *);
};

class meshGRegionExtruded {
public:
  void operator()(GVolume *);
};


// Optimize the mesh of the region using gmsh's algo
class untangleMeshGRegion {
public:
  void operator()(GVolume *, bool always = false);
};

// Optimize the mesh of the region using gmsh's algo
class optimizeMeshGRegion {
public:
  void operator()(GVolume *, bool always = false);
};

// Optimize the mesh of the region using netgen's algo
class optimizeMeshGRegionNetgen {
public:
  void operator()(GVolume *, bool always = false);
};

// destroy the mesh of the region
class deMeshGRegion {
public:
  void operator()(GVolume *);
};

void MeshDelaunayVolume(std::vector<GVolume *> &delaunay);
bool CreateAnEmptyVolumeMesh(GVolume *gr);
int MeshTransfiniteVolume(GVolume *gr);
int SubdivideExtrudedMesh(GModel *m);
void carveHole(GVolume *gr, int num, double distance,
               std::vector<int> &surfaces);

typedef std::map<MFace, GSurface *, MFaceLessThan> fs_cont;
typedef std::multimap<MNode *, std::pair<MLine *, GCurve *> > es_cont;
GSurface *findInFaceSearchStructure(MNode *p1, MNode *p2, MNode *p3,
                                 const fs_cont &search);
GSurface *findInFaceSearchStructure(const MFace &f, const fs_cont &search);
GCurve *findInEdgeSearchStructure(MNode *p1, MNode *p2,
                                 const es_cont &search);
bool buildFaceSearchStructure(GModel *model, fs_cont &search,
                              bool onlyTriangles = false);
bool buildEdgeSearchStructure(GModel *model, es_cont &search);

// hybrid mesh recovery structure
class splitQuadRecovery {
private:
  std::map<MFace, MNode *, MFaceLessThan> _quad;
  std::map<MFace, GSurface *, MFaceLessThan> _tri;

public:
  splitQuadRecovery() {}
  void add(const MFace &f, MNode *v, GSurface *gf);
  std::map<MFace, GSurface *, MFaceLessThan> &getTri() { return _tri; }
  std::map<MFace, MNode *, MFaceLessThan> &getQuad() { return _quad; }
  int buildPyramids(GModel *gm);
};

// adapt the mesh of a region
class adaptMeshGRegion {
public:
  void operator()(GVolume *);
};

#endif
