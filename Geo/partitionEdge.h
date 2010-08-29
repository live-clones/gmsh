// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARTITION_EDGE_H_
#define _PARTITION_EDGE_H_

#include "GModel.h"
#include "GEdge.h"
#include "discreteEdge.h"

class partitionEdge : public discreteEdge {
 public:
  std::vector<int> _partitions;
 public:
  partitionEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1, 
                std::vector<int> &partitions) 
    : discreteEdge(model, num, _v0, _v1), _partitions(partitions)
  {
    std::sort(_partitions.begin(), _partitions.end());
  }
  virtual ~partitionEdge() {}
  virtual GeomType geomType() const { return PartitionCurve; }
};

struct Less_partitionEdge : 
  public std::binary_function<partitionEdge*, partitionEdge*, bool> {
  bool operator()(const partitionEdge* e1, const partitionEdge* e2) const
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
