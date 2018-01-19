// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

class GModel;
class MElement;


int PartitionMesh(GModel *const model);
int UnpartitionMesh(GModel *const model);
int ConvertOldPartitioningToNewOne(GModel *const model);

#ifndef SWIG

#if __cplusplus >= 201103L
#include <unordered_map>
#define hashmap std::unordered_map
#else
#include <map>
#define hashmap std::map
#endif

int PartitionUsingThisSplit(GModel *const model, unsigned int npart,
                            hashmap<MElement*, unsigned int> &elmToPartition);

#undef hashmap

#endif

#endif
