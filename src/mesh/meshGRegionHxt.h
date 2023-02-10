// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle

//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_HXT_H
#define MESH_GREGION_HXT_H

#include <vector>
#include "hxt_mesh.h"
#include <map>

class GRegion;
class MVertex;
class MTetrahedron;

int meshGRegionHxt(std::vector<GRegion *> &regions);
void delaunayMeshIn3DHxt(std::vector<MVertex *> &points,
                         std::vector<MTetrahedron *> &tets);
void Gmsh2HxtAlpha(std::vector<GRegion *> &regions, HXTMesh *m,
                   std::map<MVertex *, uint32_t> &v2c,
                   std::vector<MVertex *> &c2v);
void Hxt2GmshAlpha(std::vector<GRegion *> &regions, HXTMesh *m,
                          std::map<MVertex *, uint32_t> &v2c,
                          std::vector<MVertex *> &c2v);

#endif
