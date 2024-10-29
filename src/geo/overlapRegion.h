// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OVERLAP_REGION_H
#define OVERLAP_REGION_H

#include "GModel.h"
#include "partitionFace.h"
#include "partitionRegion.h"
#include "MTetrahedron.h"

class overlapRegionManager;

class overlapRegion : public discreteRegion {
private:
  std::pair<int, int> _partition; // Overlap of first as a subset of second
  partitionRegion *_overlapOf,
    *_overlapOn; // must be the two partitioned entities, with the same parent.
  overlapRegionManager *_manager;

public:
  overlapRegion(GModel *model, int num, partitionRegion *of, partitionRegion *on)
    : discreteRegion(model, num), _overlapOf(of), _overlapOn(on), _manager(nullptr)
  {
    if(of->getParentEntity() != on->getParentEntity()) {
      Msg::Error("Overlap regions must have the same parent entity");
    }
    if(of->getPartitions().size() != 1 || on->getPartitions().size() != 1) {
      Msg::Error("Overlap regions must have exactly one partition");
    }
    _partition = std::make_pair(of->getPartitions()[0], on->getPartitions()[0]);
  }

  partitionRegion *getOverlapOf() const { return _overlapOf; }
  partitionRegion *getOverlapOn() const { return _overlapOn; }
  virtual GeomType geomType() const override { return OverlapVolume; }
  int of() const { return _partition.first; }
  int on() const { return _partition.second; }
  overlapRegionManager *getManager() const { return _manager; }
  void setManager(overlapRegionManager *manager) { _manager = manager; }

  // All entites which must be exported for this to have all needed nodes
  std::set<GEntity *> getCoveredEntities() const
  {
    std::set<GEntity *> entities;
    entities.insert(_overlapOn);
    for(MTetrahedron *t : this->tetrahedra) {
      for(unsigned n = 0; n < 4; n++) {
        MVertex *v = t->getVertex(n);
        entities.insert(v->onWhat());
      }
    }
    return entities;
  }

  virtual ~overlapRegion() { deleteMesh(); }
  virtual void deleteMesh() override
  {
    // Do not free elements, they are owned by the partitioned entities
    this->tetrahedra.clear();
  }
};

#endif
