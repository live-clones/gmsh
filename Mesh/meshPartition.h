// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

#if __cplusplus >= 201103L
#include <unordered_map>
#define hashmap std::unordered_map
#else
#define hashmap std::map
#endif

class GModel;

int PartitionMesh(GModel *const model);
int UnpartitionMesh(GModel *const model);
int ConvertOldPartitioningToNewOne(GModel *const model);
int PartitionUsingThisSplit(GModel *const model, unsigned int npart, hashmap<MElement*, unsigned int> &elmToPartition);

#endif
