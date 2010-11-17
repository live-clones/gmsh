#include "meshPartitionOptions.h"
#include "meshPartition.h"
#include "GModel.h"
#include <map>


meshPartitionOptions::meshPartitionOptions()
{
  setDefaults();
}

  //--Default values

void meshPartitionOptions::setDefaults()
{
  partitioner = 2;
  num_partitions=1;
  ncon = 0;
  renumber = 0;
  global_method = 1;
  architecture = 1;
  ndims_tot = 2;
  mesh_dims[0] = 4;
  mesh_dims[1] = 1;
  mesh_dims[2] = 1;
  goal = 0;
  local_method = 1;
  rqi_flag = 1;
  vmax = 250;
  ndims = 1;
  eigtol = 1.E-3;
  seed = 7654321L;
  refine_partition = false;
  internal_vertices = false;
  refine_map = true;
  terminal_propogation = false;
  algorithm = 1;
  edge_matching = 3;
  refine_algorithm = 3;
  createPartitionBoundaries = true;
  createGhostCells = true;
  partitionByExtrusion =false;
  triWeight = 1;
  quaWeight = 1;
  tetWeight = 1;
  priWeight = 1;
  pyrWeight = 1;
  hexWeight = 1; 
}

void meshPartitionOptions::partition(GModel *model)
{
  PartitionMesh(model, *this);
}
   
void meshPartitionOptions::setAlgorithm(int algo)
{
  algorithm=algo;
}


#include "Bindings.h"
void meshPartitionOptions::registerBindings(binding *b){
  classBinding *cb = b->addClass<meshPartitionOptions>("meshPartitionOptions");
  cb->setDescription("Defines the options for mesh partitioning (CHACO/METIS)");
  methodBinding *cm;
  cm = cb->setConstructor<meshPartitionOptions>();
  cm->setDescription("Build an object that contains all the options needed to perform a partitioning, when creating object default options are applied");
  cm->setArgNames(NULL);
  cm = cb->addMethod("partition", &meshPartitionOptions::partition);
  cm->setDescription("Partition with the specified option the GModel given as argument");
  cm->setArgNames("GModel", NULL);
  cm = cb->addMethod("setNumOfPartitions", &meshPartitionOptions::setNumOfPartitions);
  cm->setDescription("Define the number of partitions desired");
  cm->setArgNames("numPart", NULL);
  cm = cb->addMethod("getNumConstraints", &meshPartitionOptions::getNumConstraints);
  cm->setDescription("Get the number of different weights on the elements");
  cm->setArgNames(NULL);
  cm = cb->addMethod("setAlgorithm", &meshPartitionOptions::setAlgorithm);
  cm->setDescription("Set the partitionning algorithm");
  cm->setArgNames("algo", NULL);
}
