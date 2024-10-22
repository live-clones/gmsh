// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_EDGE_MANAGER_H
#define OVERLAP_EDGE_MANAGER_H

#include "overlapEdge.h"
#include <map>

// Collection of overlap of a common parent edge. No ownership of elements, it is a read-only view
class overlapEdgeManager {
private:
  GModel* model;
  int tagParent;
  std::map<int, std::map<int, overlapEdge*>> overlaps;
public:
  overlapEdgeManager(GModel* model, int tagParent, int overlapSize = 1, bool createPhysicals = true);
  void create(int overlapSize = 1, bool createPhysicals = true);

  overlapEdge* getOverlap(int of, int on) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    auto it2 = it->second.find(on);
    if (it2 == it->second.end()) return nullptr;
    return it2->second;
  }

  const std::map<int, overlapEdge*>* getOverlapsOf(int of) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    return &it->second;
  }

  void addOverlap(overlapEdge* overlap) {
    overlaps[overlap->of()][overlap->on()] = overlap;
  }

  std::map<int, std::map<int, overlapEdge*>> getOverlaps() const {
    return overlaps;
  }

};

#endif
