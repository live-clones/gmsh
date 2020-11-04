// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_GEOMETRY
#define MESH_QUAD_GEOMETRY

#include <vector>

class GFace;

/*******************************/
/* Hand-made pattern remeshing */
/*******************************/

int optimizeQuadGeometry(GFace* gf);

#endif
