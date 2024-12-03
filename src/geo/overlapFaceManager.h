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

  std::map<int, std::map<int, overlapFace*>> getOverlaps() const {
    return overlaps;
  }

  std::map<int, std::map<int, partitionEdge*>> getBoundaries() const {
    return boundaries;
  }


};

#endif
