// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTITION_REGION_H
#define PARTITION_REGION_H

#include "GModel.h"
#include "discreteRegion.h"

class partitionRegion : public discreteRegion {
private:
  std::vector<unsigned int> _partitions;
  GEntity *_parentEntity;

public:
  partitionRegion(GModel *model, int num,
                  const std::vector<unsigned int> &partitions)
    : discreteRegion(model, num), _partitions(partitions), _parentEntity(NULL)
  {
  }
  partitionRegion(GModel *model, int num)
    : discreteRegion(model, num), _partitions(), _parentEntity(NULL)
  {
  }
  virtual ~partitionRegion() {}
  virtual GeomType geomType() const { return PartitionVolume; }
  virtual void setParentEntity(GEntity *r) { _parentEntity = r; }
  virtual GEntity *getParentEntity() { return _parentEntity; }
  virtual void setPartitions(std::vector<unsigned int> &partitions)
  {
    _partitions = partitions;
  }
  virtual const std::vector<unsigned int> &getPartitions() const
  {
    return _partitions;
  }
  virtual unsigned int getPartition(unsigned int index) const
  {
    return _partitions[index];
  }
  virtual unsigned int numPartitions() const { return _partitions.size(); }
};

struct Less_partitionRegion
  : public std::binary_function<partitionRegion *, partitionRegion *, bool> {
  bool operator()(const partitionRegion *e1, const partitionRegion *e2) const
  {
    if(e1->numPartitions() < e2->numPartitions()) return true;
    if(e1->numPartitions() > e2->numPartitions()) return false;
    for(unsigned int i = 0; i < e1->numPartitions(); i++) {
      if(e1->getPartition(i) < e2->getPartition(i)) return true;
      if(e1->getPartition(i) > e2->getPartition(i)) return false;
    }
    return false;
  }
};

#endif
