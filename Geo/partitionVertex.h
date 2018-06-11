// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARTITION_VERTEX_H_
#define _PARTITION_VERTEX_H_

#include "GModel.h"
#include "discreteVertex.h"

class partitionVertex : public discreteVertex{
private:
  std::vector<unsigned int> _partitions;
  GEntity *_parentEntity;
public:
  partitionVertex(GModel *model, int num, const std::vector<unsigned int> &partitions)
    : discreteVertex(model, num), _partitions(partitions), _parentEntity(NULL) {}
  partitionVertex(GModel *model, int num)
    : discreteVertex(model, num), _partitions(), _parentEntity(NULL) {}
  virtual ~partitionVertex() {}
  virtual GeomType geomType() const { return PartitionVertex; }
  virtual void setParentEntity(GEntity* v) { _parentEntity = v; }
  virtual GEntity* getParentEntity() { return _parentEntity; }
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

struct Less_partitionVertex :
  public std::binary_function<partitionVertex*, partitionVertex*, bool> {
  bool operator()(const partitionVertex* e1, const partitionVertex* e2) const
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
