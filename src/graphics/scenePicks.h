// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_PICKS_H
#define SCENE_PICKS_H

#include <vector>
#include "SPoint2.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// what a click picked: entities, mesh elements, points of 2D graphs and views
struct scenePicks {
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  void clear()
  {
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    points.clear();
    views.clear();
  }
  bool empty() const
  {
    return vertices.empty() && edges.empty() && faces.empty() &&
           regions.empty() && elements.empty() && points.empty() &&
           views.empty();
  }
};

#endif
