// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_FACE_H
#define OVERLAP_FACE_H

#include "GModel.h"
#include "partitionFace.h"
#include "partitionEdge.h"

class overlapFaceManager;

class overlapFace : public discreteFace {
private:
  std::pair<int, int> _partition; // Overlap of first as a subset of second
  partitionFace *_overlapOf,
    *_overlapOn; // must be the two partitioned entities, with the same parent.
  overlapFaceManager *_manager;

public:
  overlapFace(GModel *model, int num, partitionFace *of, partitionFace *on)
    : discreteFace(model, num), _overlapOf(of), _overlapOn(on), _manager(nullptr)
  {
    if(of->getParentEntity() != on->getParentEntity()) {
      Msg::Error("Overlap faces must have the same parent entity");
    }
    if(of->getPartitions().size() != 1 || on->getPartitions().size() != 1) {
      Msg::Error("Overlap faces must have exactly one partition");
    }
    _partition = std::make_pair(of->getPartitions()[0], on->getPartitions()[0]);
  }

  partitionFace *getOverlapOf() const { return _overlapOf; }
  partitionFace *getOverlapOn() const { return _overlapOn; }
  virtual GeomType geomType() const override { return OverlapSurface; }
  int of() const { return _partition.first; }
  int on() const { return _partition.second; }
  overlapFaceManager *getManager() const { return _manager; }
  void setManager(overlapFaceManager *manager) { _manager = manager; }


  virtual ~overlapFace() { deleteMesh(); }
  virtual void deleteMesh() override
  {
    // Do not free elements, they are owned by the partitioned entities
    this->triangles.clear();
    this->quadrangles.clear();
    this->polygons.clear();
  }
};

#endif
