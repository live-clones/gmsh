// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_RELOCATE_VERTEX_H
#define MESH_RELOCATE_VERTEX_H

#include <vector>

class GRegion;
class GFace;
class MElement;

// nthreads: Mesh.MaxNumThreads3D, else General.NumThreads, if 0;
// skipGoodVertices: the vertices whose elements are all good (tets of gamma
// 0.5, other elements of SICN 0.9) are not moved
void RelocateVertices(GRegion *region, int niter, double tol = 1.e-2,
                      int nthreads = 0, bool skipGoodVertices = false);
void RelocateVertices(std::vector<GRegion *> &regions, int niter,
                      double tol = 1.e-2);
void RelocateVertices(GFace *, int niter, double tol = 1.e-6);
void RelocateVerticesOfPyramids(GRegion *region, int niter, double tol = 1.e-2);
void RelocateVerticesOfPyramids(std::vector<GRegion *> &regions, int niter,
                                double tol = 1.e-2);

#endif
