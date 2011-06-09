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
