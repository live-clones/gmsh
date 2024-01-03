// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTITION_EDGE_H
#define PARTITION_EDGE_H

#include "GModel.h"
#include "discreteEdge.h"

class partitionEdge : public discreteEdge {
private:
  std::vector<int> _partitions;
  GEntity *_parentEntity;

public:
  partitionEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1,
                const std::vector<int> &partitions)
    : discreteEdge(model, num, _v0, _v1), _partitions(partitions),
      _parentEntity(nullptr)
  {
  }
  partitionEdge(GModel *model, int num, const std::vector<int> &partitions)
    : discreteEdge(model, num), _partitions(partitions), _parentEntity(nullptr)
  {
  }
  partitionEdge(GModel *model, const std::vector<int> &partitions)
    : discreteEdge(model), _partitions(partitions), _parentEntity(nullptr)
  {
  }
  virtual ~partitionEdge() {}
  virtual GeomType geomType() const { return PartitionCurve; }
  virtual bool haveParametrization() { return false; }
  virtual void setParentEntity(GEntity *e) { _parentEntity = e; }
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

struct partitionEdgePtrLessThan
{
  bool operator()(const partitionEdge *e1, const partitionEdge *e2) const
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
