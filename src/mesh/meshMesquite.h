// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_MESQUITE_H
#define MESH_MESQUITE_H

class GRegion;
class GFace;

int mesquiteImprove(GRegion *gr);
int mesquiteImprove(GFace *gr);

#endif
