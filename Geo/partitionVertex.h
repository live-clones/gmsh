// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARTITION_VERTEX_H_
#define _PARTITION_VERTEX_H_

#include "GModel.h"
#include "discreteVertex.h"

class partitionVertex : public discreteVertex {
 public:
  std::vector<int> _partitions;
 public:
  partitionVertex(GModel *model, int num, std::vector<int> &partitions) 
    : discreteVertex(model, num), _partitions(partitions)
  {
    std::sort(_partitions.begin(), _partitions.end());
  }
  virtual ~partitionVertex() {}
  virtual GeomType geomType() const { return PartitionVertex; }
};


struct Less_partitionVertex : 
  public std::binary_function<partitionVertex*, partitionVertex*, bool> {
  bool operator()(const partitionVertex* e1, const partitionVertex* e2) const
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
