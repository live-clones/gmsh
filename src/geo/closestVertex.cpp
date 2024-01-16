// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "closestVertex.h"
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include <vector>

closestVertexFinder::closestVertexFinder(GEntity *ge, bool closure) : nbVtcs(0)
{
#if defined(HAVE_ANN)
  std::set<MVertex *> vtcs;
  ge->addVerticesInSet(vtcs, closure);
  nbVtcs = vtcs.size();
  if(nbVtcs) {
    vertex = new MVertex *[nbVtcs];
    index = new ANNidx[1];
    dist = new ANNdist[1];
    vCoord = annAllocPts(nbVtcs, 3);
    int k = 0;
    auto vIter = vtcs.begin();
    for(; vIter != vtcs.end(); ++vIter, ++k) {
      MVertex *mv = *vIter;
      vCoord[k][0] = mv->x();
      vCoord[k][1] = mv->y();
      vCoord[k][2] = mv->z();
      vertex[k] = mv;
    }
    kdtree = new ANNkd_tree(vCoord, nbVtcs, 3);
  }
#else
  Msg::Warning(
    "Gmsh must be compiled with ANN support for finding closest nodes");
#endif
}

closestVertexFinder::~closestVertexFinder()
{
#if defined(HAVE_ANN)
  if(nbVtcs) {
    delete kdtree;
    annDeallocPts(vCoord);
    delete[] vertex;
    delete[] index;
    delete[] dist;
  }
#endif
}

MVertex *closestVertexFinder::operator()(const SPoint3 &p)
{
#if defined(HAVE_ANN)
  if(nbVtcs == 0) return nullptr;
  double xyz[3] = {p.x(), p.y(), p.z()};
  kdtree->annkSearch(xyz, 1, index, dist);
  return vertex[index[0]];
#else
  return nullptr;
#endif
}

MVertex *closestVertexFinder::operator()(const SPoint3 &p,
                                         const std::vector<double> &tfo)
{
#if defined(HAVE_ANN)
  if(nbVtcs == 0) return nullptr;
  double ori[4] = {p.x(), p.y(), p.z(), 1};
  double xyz[4] = {0, 0, 0, 0};
  if(tfo.size() == 16) {
    int idx = 0;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) xyz[i] += tfo[idx++] * ori[j];
  }
  else
    std::memcpy(xyz, ori, 3 * sizeof(double));
  kdtree->annkSearch(xyz, 1, index, dist);
  return vertex[index[0]];
#else
  return nullptr;
#endif
}
