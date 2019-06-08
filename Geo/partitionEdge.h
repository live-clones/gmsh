// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTITION_EDGE_H
#define PARTITION_EDGE_H

#include "GModel.h"
#include "discreteEdge.h"

class partitionEdge : public discreteEdge {
private:
  std::vector<unsigned int> _partitions;
  GEntity *_parentEntity;

public:
  partitionEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1,
                const std::vector<unsigned int> &partitions)
    : discreteEdge(model, num, _v0, _v1), _partitions(partitions),
      _parentEntity(NULL)
  {
  }
  partitionEdge(GModel *model, int num,
                const std::vector<unsigned int> &partitions)
    : discreteEdge(model, num), _partitions(partitions), _parentEntity(NULL)
  {
  }
  virtual ~partitionEdge() {}
  virtual GeomType geomType() const { return PartitionCurve; }
  virtual bool haveParametrization() { return false; }
  virtual void setParentEntity(GEntity *e) { _parentEntity = e; }
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

struct Less_partitionEdge
  : public std::binary_function<partitionEdge *, partitionEdge *, bool> {
  bool operator()(const partitionEdge *e1, const partitionEdge *e2) const
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
