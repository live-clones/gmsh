// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "closestPoint.h"
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include <vector>

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

closestPointFinder::closestPointFinder(GEntity *ge, double e) : _tolerance(e)
{
  std::vector<SPoint3> &pts = _search.points();
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
  _search.build();
}

SPoint3 closestPointFinder::operator()(const SPoint3 &p)
{
  std::size_t i = _search.nearest(p);
  return i < _search.size() ? _search.point(i) : p;
}
