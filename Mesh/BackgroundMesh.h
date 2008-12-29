// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BACKGROUND_MESH_H_
#define _BACKGROUND_MESH_H_

class GEntity;
double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y, double Z);
bool Extend1dMeshIn2dSurfaces();
bool Extend2dMeshIn3dVolumes();

#endif
