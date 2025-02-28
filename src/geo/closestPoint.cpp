// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "closestPoint.h"
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include <vector>

#if defined(HAVE_ANN)
static void oversample(std::vector<SPoint3> &s, double tol)
{
  std::vector<SPoint3> t;
  for(std::size_t i = 1; i < s.size(); i++) {
    SPoint3 p0 = s[i - 1];
    SPoint3 p1 = s[i];
    double d = p0.distance(p1);
    int N = (int)(d / tol);
    t.push_back(p0);
    for(int j = 1; j < N; j++) {
      const double xi = (double)j / N;
      t.push_back(p0 + (p1 - p0) * xi);
    }
    t.push_back(p1);
  }
  s = t;
}
#endif

closestPointFinder::closestPointFinder(GEntity *ge, double e) : _tolerance(e)
{
#if defined(HAVE_ANN)
  std::vector<SPoint3> pts;
  if(ge->dim() == 1) {
    GEdge *edge = ge->cast2Edge();
    if(edge) {
      std::vector<double> ts;
      edge->discretize(_tolerance, pts, ts);
      oversample(pts, _tolerance);
    }
    else {
      Msg::Error("Unknown curve in closestPointFinder");
    }
  }
  index = new ANNidx[1];
  dist = new ANNdist[1];
  zeronodes = annAllocPts(pts.size(), 3);
  for(std::size_t k = 0; k < pts.size(); k++) {
    zeronodes[k][0] = pts[k].x();
    zeronodes[k][1] = pts[k].y();
    zeronodes[k][2] = pts[k].z();
  }
  kdtree = new ANNkd_tree(zeronodes, pts.size(), 3);
#else
  Msg::Error("Gmsh should be compiled with ANN to support closestPointFinder");
#endif
}

closestPointFinder::~closestPointFinder()
{
#if defined(HAVE_ANN)
  if(kdtree) delete kdtree;
  if(zeronodes) annDeallocPts(zeronodes);
  delete[] index;
  delete[] dist;
#endif
}

SPoint3 closestPointFinder::operator()(const SPoint3 &p)
{
#if defined(HAVE_ANN)
  double xyz[3] = {p.x(), p.y(), p.z()};
  kdtree->annkSearch(xyz, 1, index, dist);
  return SPoint3(zeronodes[index[0]][0], zeronodes[index[0]][1],
                 zeronodes[index[0]][2]);
#else
  return p;
#endif
}
