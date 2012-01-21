// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise

#ifndef _MULTI_PARTITION_H_
#define _MULTI_PARTITION_H_

#include <vector>
#include <map>
#include "linearSystemGMM.h"
#include "meshPartitionOptions.h"
#include "meshPartition.h"

class MElement;
struct meshPartitionOptions;

struct partitionLevel {
  int recur;
  int region;
  std::vector<MElement *> elements;
};

typedef enum {LAPLACIAN= 0, MULTILEVEL=1} typeOfPartition;

class multiscalePartition{

 private:
  std::vector<partitionLevel*> levels;
  void partition(partitionLevel &level, int nbParts,  typeOfPartition method);
  int totalParts;
  bool onlyMultilevel;
  meshPartitionOptions options;

 public:
  multiscalePartition(std::vector<MElement *> &elements, int nbParts, 
		      typeOfPartition method, int allowPartition);
  int assembleAllPartitions(std::vector<MElement*> & elements);
  void setNumberOfPartitions(int &nbParts);
  int getNumberOfParts(){return totalParts;}
};

#endif
