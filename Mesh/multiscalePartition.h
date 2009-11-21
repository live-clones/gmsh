// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MULTI_PARTITION_H_
#define _MULTI_PARTITION_H_

#include <vector>
#include <map>
#include "linearSystemGMM.h"
#include "meshPartitionOptions.h"

class MElement;
class meshPartitionOptions;

struct partitionLevel {
  int recur;
  int region;
  std::vector<MElement *> elements;
};

class multiscalePartition{

 private:
  std::vector<partitionLevel*> levels;
  void partition(partitionLevel &level);
  int totalParts;
  meshPartitionOptions options;

 public:
  multiscalePartition(std::vector<MElement *> &elements, 
		      meshPartitionOptions &options);
  int assembleAllPartitions();
  void setNumberOfPartitions(int &nbParts);
  int getNumberOfParts(){return totalParts;}
};

#endif
