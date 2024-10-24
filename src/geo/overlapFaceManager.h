// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_FACE_MANAGER_H
#define OVERLAP_FACE_MANAGER_H

#include "overlapFace.h"
#include <map>

class MLine; // For overlap boundary

// Collection of overlap of a common parent face. No ownership of elements, it is a read-only view
class overlapFaceManager {
private:
  GModel* model;
  int tagParent;
  std::map<int, std::map<int, overlapFace*>> overlaps;
  std::map<int, std::map<int, partitionEdge*>> boundaries;
public:
  overlapFaceManager(GModel* model, int tagParent, int overlapSize = 1, bool createPhysicals = true);
  void create(int overlapSize = 1, bool createPhysicals = true);

  overlapFace* getOverlap(int of, int on) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    auto it2 = it->second.find(on);
    if (it2 == it->second.end()) return nullptr;
    return it2->second;
  }

  const std::map<int, overlapFace*>* getOverlapsOf(int of) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    return &it->second;
  }

  void addOverlap(overlapFace* overlap) {
    overlaps[overlap->of()][overlap->on()] = overlap;
  }


  std::map<int, std::map<int, overlapFace*>> getOverlaps() const {
    return overlaps;
  }

  std::map<int, std::map<int, partitionEdge*>> getBoundaries() const {
    return boundaries;
  }

private:
  std::vector<MLine *>
  _createBoundary(const std::set<MTriangle *> &trianglesInOverlap) const;
};

#endif
