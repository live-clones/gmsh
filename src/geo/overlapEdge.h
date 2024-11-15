// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_EDGE_H
#define OVERLAP_EDGE_H

#include "GModel.h"
#include "partitionEdge.h"
#include "MLine.h"

class overlapEdgeManager;

class overlapEdge : public discreteEdge {
private:
  std::pair<int, int> _partition; // Overlap of first as a subset of second
  partitionEdge *_overlapOf,
    *_overlapOn; // must be the two partitioned entities, with the same parent.
  overlapEdgeManager *_manager;

public:
  overlapEdge(GModel *model, int num, partitionEdge *of, partitionEdge *on)
    : discreteEdge(model, num), _overlapOf(of), _overlapOn(on), _manager(nullptr)
  {
    if(of->getParentEntity() != on->getParentEntity()) {
      Msg::Error("Overlap edges must have the same parent entity");
    }
    if(of->getPartitions().size() != 1 || on->getPartitions().size() != 1) {
      Msg::Error("Overlap edges must have exactly one partition");
    }
    _partition = std::make_pair(of->getPartitions()[0], on->getPartitions()[0]);
  }

  partitionEdge *getOverlapOf() const { return _overlapOf; }
  partitionEdge *getOverlapOn() const { return _overlapOn; }
  virtual GeomType geomType() const override { return OverlapCurve; }
  int of() const { return _partition.first; }
  int on() const { return _partition.second; }
  overlapEdgeManager *getManager() const { return _manager; }
  void setManager(overlapEdgeManager *manager) { _manager = manager; }

  virtual ~overlapEdge() { deleteMesh(); }
  virtual void deleteMesh() override
  {
    // Do not free elements, they are owned by the partitioned entities
    this->lines.clear();
  }
};

#endif
