// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_REGION_MANAGER_H
#define OVERLAP_REGION_MANAGER_H

#include "overlapRegion.h"
#include "partitionFace.h"
#include <map>
#include <unordered_set>
#include <unordered_map>

class MLine; // For overlap boundary

// Collection of overlap of a common parent face. No ownership of elements, it is a read-only view
class overlapRegionManager {
private:
  GModel* model;
  int tagParent;
  std::map<int, std::set<overlapRegion*>> overlapsByPartition;
  std::map<int, std::set<partitionFace*>> boundariesByPartition;
public:
  overlapRegionManager(GModel* model, int tagParent, int overlapSize = 1, bool createPhysicals = true);
  void create(int overlapSize = 1, bool createPhysicals = true);

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
  

  private:
    static void findElementsForBoundaryOverlap(
      partitionFace *pf,
      const std::map<partitionFace *, std::unordered_set<MFace, MFaceHash>>&
        faceToOverlaps,
      std::map<partitionFace *, std::set<MTriangle *>>& faceToOverlapElements,
      GModel* model);
};

#endif
