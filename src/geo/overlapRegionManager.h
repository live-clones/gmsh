// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_REGION_MANAGER_H
#define OVERLAP_REGION_MANAGER_H

#include "overlapRegion.h"
#include "partitionFace.h"
#include <map>

class MLine; // For overlap boundary

// Collection of overlap of a common parent face. No ownership of elements, it is a read-only view
class overlapRegionManager {
private:
  GModel* model;
  int tagParent;
  std::map<int, std::map<int, overlapRegion*>> overlaps;
  std::map<int, std::set<overlapRegion*>> overlapsByPartition;
  std::map<int, std::set<partitionFace*>> boundariesByPartition;
  std::map<int, std::map<int, partitionFace*>> boundaries;
  std::map<int, partitionFace*> fullBoundaries;
public:
  overlapRegionManager(GModel* model, int tagParent, int overlapSize = 1, bool createPhysicals = true);
  void create(int overlapSize = 1, bool createPhysicals = true);

  overlapRegion* getOverlap(int of, int on) const {
    auto it = overlaps.find(of);
    if (it == overlaps.end()) return nullptr;
    auto it2 = it->second.find(on);
    if (it2 == it->second.end()) return nullptr;
    return it2->second;
  }

  const std::map<int, std::set<overlapRegion*>>& getOverlapsByPartition() const {
    return overlapsByPartition;
  }
  std::map<int, std::set<overlapRegion*>>& getOverlapsByPartition() {
    return overlapsByPartition;
  }

  const std::map<int, std::set<partitionFace*>>& getBoundariesByPartition() const {
    return boundariesByPartition;
  }
  std::map<int, std::set<partitionFace*>>& getBoundariesByPartition() {
    return boundariesByPartition;
  }
  

  const std::map<int, partitionFace*>* getOverlapBoundariesOf(int of) const {
    auto it = boundaries.find(of);
    if (it == boundaries.end()) return nullptr;
    return &it->second;
  }

  void addOverlap(overlapRegion* overlap) {
    overlaps[overlap->of()][overlap->on()] = overlap;
  }

  void addBoundary(partitionFace* boundary, int i, int j) {
    boundaries[i][j] = boundary;
  }

  std::map<int, std::map<int, overlapRegion*>> getOverlaps() const {
    return overlaps;
  }

  std::map<int, std::map<int, partitionFace*>> getBoundaries() const {
    return boundaries;
  }

  std::map<int, partitionFace*> getFullBoundaries() const {
    return fullBoundaries;
  }

  void setFullBoundary(int i, partitionFace* fullBoundary) {
    fullBoundaries[i] = fullBoundary;
  }

};

#endif
