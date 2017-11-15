// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _PARTITION_FACE_H_
#define _PARTITION_FACE_H_

#include "GModel.h"
#include "discreteFace.h"

class partitionFace : public discreteFace {
public:
  std::vector<unsigned short> _partitions;
  GFace *_parentEntity;
public:
  partitionFace(GModel *model, int num, std::vector<unsigned short> &partitions) : discreteFace(model, num), _partitions(partitions), _parentEntity(NULL) {}
  partitionFace(GModel *model, int num) : discreteFace(model, num), _partitions(), _parentEntity(NULL) {}
  virtual ~partitionFace() {}
  virtual GeomType geomType() const { return PartitionSurface; }
  
  virtual void setParentEntity(GFace* f) { _parentEntity = f; }
  virtual GFace* getParentEntity() const { return _parentEntity; }
  
  virtual void setPartition(std::vector<unsigned short> &partitions) { _partitions = partitions; }
};

struct Less_partitionFace : 
  public std::binary_function<partitionFace*, partitionFace*, bool> {
  bool operator()(const partitionFace* e1, const partitionFace* e2) const
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
