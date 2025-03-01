// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _MESH_COMBINE_3D_
#define _MESH_COMBINE_3D_

class GVolume;
class GModel;

int meshCombine3D(GVolume *m);
bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm);

#endif
