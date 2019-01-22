// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _MESH_RELOCATE_VERTEX_H_
#define _MESH_RELOCATE_VERTEX_H_

#include <vector>

class GRegion;
class GFace;
class MElement;

void RelocateVertices(GRegion *region, int niter, double tol = 1.e-2);
void RelocateVertices(std::vector<GRegion *> &regions, int niter,
                      double tol = 1.e-2);
void RelocateVertices(GFace *, int niter, double tol = 1.e-6);

#endif
