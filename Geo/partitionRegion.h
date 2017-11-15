// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARTITION_REGION_H_
#define _PARTITION_REGION_H_

#include "GModel.h"
#include "discreteRegion.h"

class partitionRegion : public discreteRegion {
public:
  std::vector<unsigned short> _partitions;
  GRegion *_parentEntity;
public:
  partitionRegion(GModel *model, int num, std::vector<unsigned short> &partitions) : discreteRegion(model, num), _partitions(partitions), _parentEntity(NULL) {}
  partitionRegion(GModel *model, int num) : discreteRegion(model, num), _partitions(), _parentEntity(NULL) {}
  virtual ~partitionRegion() {}
  virtual GeomType geomType() const { return PartitionVolume; }
  
  virtual void setParentEntity(GRegion* r) { _parentEntity = r; }
  virtual GRegion* getParentEntity() const { return _parentEntity; }
  
  virtual void setPartition(std::vector<unsigned short> &partitions) { _partitions = partitions; }
};

struct Less_partitionRegion :
  public std::binary_function<partitionRegion*, partitionRegion*, bool> {
  bool operator()(const partitionRegion* e1, const partitionRegion* e2) const
  {
    if (e1->_partitions.size() < e2->_partitions.size()) return true; 
    if (e1->_partitions.size() > e2->_partitions.size()) return false;
    for (unsigned int i = 0; i < e1->_partitions.size(); i++){
      if (e1->_partitions[i] < e2->_partitions[i]) return true; 
      if (e1->_partitions[i] > e2->_partitions[i]) return false;      
    }
    return false;
  }
};

#endif
