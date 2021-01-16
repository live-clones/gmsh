// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_PARTITION_H
#define MESH_PARTITION_H

class GModel;
class MElement;
class GFace;

int PartitionMesh(GModel *model);
int UnpartitionMesh(GModel *model);

int PartitionUsingThisSplit(
  GModel *model, std::size_t npart,
  std::vector<std::pair<MElement *, int> > &elmToPartition);
int ConvertOldPartitioningToNewOne(GModel *model);

int PartitionFaceMinEdgeLength(GFace *gf, int np, double tol = 1.02);

#endif
