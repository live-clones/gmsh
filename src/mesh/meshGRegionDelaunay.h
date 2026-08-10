// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_DELAUNAY_H
#define MESH_GREGION_DELAUNAY_H

// The 3D Delaunay mesher: tetrahedralize a set of points, fill a region with
// tetrahedra, and optimize the tetrahedra of a region. The data structures
// and the kernels themselves are internal (meshGRegionTet4.h and the
// meshGRegion{Refine,Optimize}.cpp sources).

#include <cstdint>
#include <vector>
#include "qualityMeasures.h"

class GRegion;
class MVertex;
class MTetrahedron;
class splitQuadRecovery;

// circumcenter of a tetrahedron, and its distance to the vertices
double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
                       double circumcenter[3], double *xi, double *eta,
                       double *zeta);

// tetrahedralize the vertices given in v
void delaunayMeshIn3D(std::vector<MVertex *> &v,
                      std::vector<MTetrahedron *> &result,
                      bool removeBox = false,
                      std::vector<std::int64_t> *neighbors = nullptr);

// mesh the interior of a region whose boundary is already meshed
void insertVerticesInRegion(GRegion *gr, int maxIter,
                            double worstTetRadiusTarget, bool _classify = true,
                            splitQuadRecovery *sqr = nullptr);

// improve the tetrahedra of a region by local mesh modifications
void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm);

#endif
