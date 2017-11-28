// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARTITION_FACE_H_
#define _PARTITION_FACE_H_

#include "GModel.h"
#include "discreteFace.h"

class partitionFace : public discreteFace {
private:
  std::vector<unsigned int> _partitions;
  GFace *_parentEntity;
public:
  partitionFace(GModel *model, int num, const std::vector<unsigned int> &partitions) : discreteFace(model, num), _partitions(partitions), _parentEntity(NULL) {}
  partitionFace(GModel *model, int num) : discreteFace(model, num), _partitions(), _parentEntity(NULL) {}
  virtual ~partitionFace() {}
  virtual GeomType geomType() const { return PartitionSurface; }
  
  virtual void setParentEntity(GFace* f) { _parentEntity = f; }
  virtual GFace* getParentEntity() const { return _parentEntity; }
  
  virtual void setPartition(std::vector<unsigned int> &partitions) { _partitions = partitions; }
  virtual const std::vector<unsigned int>& getPartitions() const { return _partitions; }
  virtual unsigned int getPartition(unsigned int index) const { return _partitions[index]; }
  virtual unsigned int numPartitions() const { return _partitions.size(); }
};

struct Less_partitionFace : 
  public std::binary_function<partitionFace*, partitionFace*, bool> {
  bool operator()(const partitionFace* e1, const partitionFace* e2) const
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
