// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_HXT_H
#define MESH_GREGION_HXT_H

#include <vector>

class GModel;
class GRegion;
class MVertex;
class MTetrahedron;
class MTriangle;

int meshGRegionHxt(std::vector<GRegion *> &regions);
void delaunayMeshIn3DHxt(std::vector<MVertex *> &points,
                         std::vector<MTetrahedron *> &tets,
                         const std::vector<MTriangle> &triangles);
void optimizeMeshHXT(GModel* pModel, double quality, bool flipOnly);
void refineTetrahedraHxt(const std::vector<double> &coord, const std::vector<double> &sizeAtNode, const std::vector<std::size_t> &tetraIn, 
                         std::vector<double> &steiner, std::vector<std::size_t> &tetraOut);
#endif
