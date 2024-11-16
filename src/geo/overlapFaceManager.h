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
  std::map<int, std::set<overlapFace*>> overlapsByPartition;
  std::map<int, std::set<partitionEdge*>> boundariesByPartition;
  std::map<int, partitionEdge*> fullBoundaries;
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

  const std::map<int, std::set<overlapFace*>>& getOverlapsByPartition() const {
    return overlapsByPartition;
  }
  std::map<int, std::set<overlapFace*>>& getOverlapsByPartition() {
    return overlapsByPartition;
  }

  const std::map<int, std::set<partitionEdge*>>& getBoundariesByPartition() const {
    return boundariesByPartition;
  }
  std::map<int, std::set<partitionEdge*>>& getBoundariesByPartition() {
    return boundariesByPartition;
  }

  const std::map<int, overlapFace*>* getOverlapsOf(int of) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    return &it->second;
  }

  const std::map<int, partitionEdge*>* getOverlapBoundariesOf(int of) const {
    auto it = boundaries.find(of);
    if (it == boundaries.end()) return nullptr;
    return &it->second;
  }

  void addOverlap(overlapFace* overlap) {
    overlaps[overlap->of()][overlap->on()] = overlap;
  }

  void addBoundary(partitionEdge* boundary, int i, int j) {
    boundaries[i][j] = boundary;
  }

  std::map<int, std::map<int, overlapFace*>> getOverlaps() const {
    return overlaps;
  }

  std::map<int, std::map<int, partitionEdge*>> getBoundaries() const {
    return boundaries;
  }

  std::map<int, partitionEdge*> getFullBoundaries() const {
    return fullBoundaries;
  }

  void setFullBoundary(int i, partitionEdge* bnd) {
    fullBoundaries[i] = bnd;
  }
};

#endif
