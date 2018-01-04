// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

class GModel;

int PartitionMesh(GModel *const model);
int UnpartitionMesh(GModel *const model);
int ConvertOldPartitioningToNewOne(GModel *const model);

#endif
