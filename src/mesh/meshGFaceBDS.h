// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_BDS_H
#define MESH_GFACE_BDS_H

#include <map>
#include <list>
#include "BDS.h"

class GSurface;
class MNode;
class BDS_Mesh;
class BDS_Point;

void refineMeshBDS(
  GSurface *gf, BDS_Mesh &m, const int NIT, const bool computeNodalSizeField,
  std::map<MNode *, BDS_Point *> *recoverMapInv = 0,
  std::map<BDS_Point *, MNode *, PointLessThan> *recoverMap = 0,
  std::vector<SPoint2> *true_boundary = 0);
void modifyInitialMeshToRemoveDegeneracies(
  GSurface *gf, BDS_Mesh &m,
  std::map<BDS_Point *, MNode *, PointLessThan> *recoverMap);
void delaunayizeBDS(GSurface *gf, BDS_Mesh &m, int &nb_swap);

#endif
