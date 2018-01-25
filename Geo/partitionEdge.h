// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARTITION_EDGE_H_
#define _PARTITION_EDGE_H_

#include "GModel.h"
#include "discreteEdge.h"

class partitionEdge : public discreteEdge {
private:
  std::vector<unsigned int> _partitions;
  GEdge *_parentEntity;
public:
  partitionEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1,
                const std::vector<unsigned int> &partitions)
    : discreteEdge(model, num, _v0, _v1), _partitions(partitions),
      _parentEntity(NULL) {}
  partitionEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
    : discreteEdge(model, num, _v0, _v1), _partitions(), _parentEntity(NULL) {}
  virtual ~partitionEdge() {}
  virtual GeomType geomType() const { return PartitionCurve; }
  virtual void setParentEntity(GEdge* e) { _parentEntity = e; }
  virtual GEdge* getParentEntity() const { return _parentEntity; }
  virtual void setPartitions(std::vector<unsigned int> &partitions)
  {
    _partitions = partitions;
  }
  virtual const std::vector<unsigned int>& getPartitions() const
  {
    return _partitions;
  }
  virtual unsigned int getPartition(unsigned int index) const
  {
    return _partitions[index];
  }
  virtual unsigned int numPartitions() const { return _partitions.size(); }
};

struct Less_partitionEdge :
  public std::binary_function<partitionEdge*, partitionEdge*, bool> {
  bool operator()(const partitionEdge* e1, const partitionEdge* e2) const
  {
    if (e1->numPartitions() < e2->numPartitions()) return true;
    if (e1->numPartitions() > e2->numPartitions()) return false;
    for (unsigned int i = 0; i < e1->numPartitions(); i++){
      if (e1->getPartition(i) < e2->getPartition(i)) return true;
      if (e1->getPartition(i) > e2->getPartition(i)) return false;
    }
    return false;
  }
};

#endif
