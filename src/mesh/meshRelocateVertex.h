// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_RELOCATE_VERTEX_H
#define MESH_RELOCATE_VERTEX_H

#include <vector>

class GVolume;
class GSurface;
class MElement;

void RelocateVertices(GVolume *region, int niter, double tol = 1.e-2);
void RelocateVertices(std::vector<GVolume *> &regions, int niter,
                      double tol = 1.e-2);
void RelocateVertices(GSurface *, int niter, double tol = 1.e-6);
void RelocateVerticesOfPyramids(GVolume *region, int niter, double tol = 1.e-2);
void RelocateVerticesOfPyramids(std::vector<GVolume *> &regions, int niter,
                                double tol = 1.e-2);

#endif
