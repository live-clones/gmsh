// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_PARTITION_H
#define MESH_PARTITION_H

class GModel;
class MElement;
class GFace;

int PartitionMesh(GModel *const model);
int PartitionFace(GFace *gf, int np, int *p);
int UnpartitionMesh(GModel *const model);
int ConvertOldPartitioningToNewOne(GModel *const model);

#endif
