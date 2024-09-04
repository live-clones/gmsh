// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTITION_VERTEX_H
#define PARTITION_VERTEX_H

#include "GModel.h"
#include "discreteVertex.h"

class partitionVertex : public discreteVertex {
private:
  std::vector<int> _partitions;
  GEntity *_parentEntity;

public:
  partitionVertex(GModel *model, int num, const std::vector<int> &partitions)
    : discreteVertex(model, num), _partitions(partitions),
      _parentEntity(nullptr)
  {
  }
  partitionVertex(GModel *model, int num)
    : discreteVertex(model, num), _partitions(), _parentEntity(nullptr)
  {
  }
  partitionVertex(GModel *model, const std::vector<int> &partitions)
    : discreteVertex(model), _partitions(partitions), _parentEntity(nullptr)
  {
  }
  virtual ~partitionVertex() {}
  virtual GeomType geomType() const { return PartitionPoint; }
  virtual void setParentEntity(GEntity *v) { _parentEntity = v; }
  virtual GEntity *getParentEntity() { return _parentEntity; }
  virtual void setPartitions(std::vector<int> &partitions)
  {
    _partitions = partitions;
  }
  virtual const std::vector<int> &getPartitions() const { return _partitions; }
  virtual int getPartition(std::size_t index) const
  {
    return _partitions[index];
  }
  virtual std::size_t numPartitions() const { return _partitions.size(); }
};

struct partitionVertexPtrLessThan
{
  bool operator()(const partitionVertex *e1, const partitionVertex *e2) const
  {
    if(e1->numPartitions() < e2->numPartitions()) return true;
    if(e1->numPartitions() > e2->numPartitions()) return false;
    for(std::size_t i = 0; i < e1->numPartitions(); i++) {
      if(e1->getPartition(i) < e2->getPartition(i)) return true;
      if(e1->getPartition(i) > e2->getPartition(i)) return false;
    }
    return false;
  }
};

#endif
