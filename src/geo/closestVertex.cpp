// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "closestVertex.h"
#include "GEntity.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"

closestVertexFinder::closestVertexFinder(GEntity *ge, bool closure)
{
  std::set<MVertex *> vtcs;
  ge->addVerticesInSet(vtcs, closure);
  _vertices.assign(vtcs.begin(), vtcs.end());
  for(auto v : _vertices) _search.points().push_back(v->point());
  _search.build();
}

MVertex *closestVertexFinder::operator()(const SPoint3 &p)
{
  std::size_t i = _search.nearest(p);
  return i < _vertices.size() ? _vertices[i] : nullptr;
}

MVertex *closestVertexFinder::operator()(const SPoint3 &p,
                                         const std::vector<double> &tfo)
{
  if(tfo.size() != 16) return (*this)(p);
  double ori[4] = {p.x(), p.y(), p.z(), 1};
  double xyz[3] = {0, 0, 0};
  int idx = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 4; j++) xyz[i] += tfo[idx++] * ori[j];
  return (*this)(SPoint3(xyz));
}
