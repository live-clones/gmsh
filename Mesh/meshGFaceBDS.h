// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_BDS_H_
#define _MESH_GFACE_BDS_H_

#include <map>
#include <list>

class GFace;
class GModel;
class BDS_Mesh;
class BDS_Point;
class MVertex;
class BDS_Mesh;

void computeMeshSizeFieldAccuracy(GFace *gf, BDS_Mesh &m, double &avg, 
                                  double &max_e, double &min_e, int &nE, int &GS);
void refineMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT, 
                   const bool computeNodalSizeField,
                   std::map<MVertex*, BDS_Point*> *recoverMapInv=0);
void optimizeMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT, 
                         std::map<BDS_Point*, MVertex*> *recoverMap=0);
void delaunayizeBDS(GFace *gf, BDS_Mesh &m, int &nb_swap);
void collapseSmallEdges(GModel &gm);
BDS_Mesh *gmsh2BDS(std::list<GFace*> &l);
double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2);
void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q);

#endif
