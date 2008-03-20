#ifndef _MESH_GFACE_OPTIMIZE_H_
#define _MESH_GFACE_OPTIMIZE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <vector>
#include "MElement.h"
#include "MEdge.h"
#include "meshGFaceDelaunayInsertion.h"

class GFace;
class MVertex;
typedef std::map<MVertex*, std::vector<MTriangle*> > v2t_cont;
typedef std::map<MEdge, std::pair<MTriangle*,MTriangle*>, Less_Edge> e2t_cont;
void buildVertexToTriangle(std::vector<MTriangle*> &, v2t_cont &adj);
void buildEdgeToTriangle(std::vector<MTriangle*> &, e2t_cont &adj);
void laplaceSmoothing(GFace *gf);
void edgeSwappingLawson(GFace *gf);
enum gmshSwapCriterion {SWCR_DEL, SWCR_QUAL,SWCR_NORM, SWCR_CLOSE};
enum gmshSplitCriterion {SPCR_CLOSE, SPCR_QUAL, SPCR_ALLWAYS};
int edgeSwapPass(GFace *gf, std::set<MTri3*, compareTri3Ptr> &allTris, 
                 const gmshSwapCriterion &cr,
                 const std::vector<double> &Us,
                 const std::vector<double> &Vs,
                 const std::vector<double> &vSizes,
                 const std::vector<double> &vSizesBGM);
int edgeSplitPass(double maxLC,
                  GFace *gf, std::set<MTri3*, compareTri3Ptr> &allTris,
                  const gmshSplitCriterion &cr,   
                  std::vector<double> &Us ,
                  std::vector<double> &Vs,
                  std::vector<double> &vSizes ,
                  std::vector<double> &vSizesBGM);
int edgeCollapsePass(double minLC,
                     GFace *gf, std::set<MTri3*, compareTri3Ptr> &allTris,
                     std::vector<double> &Us,
                     std::vector<double> &Vs,
                     std::vector<double> &vSizes ,
                     std::vector<double> &vSizesBGM);
void buidMeshGenerationDataStructures(GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris,
                                      std::vector<double> &vSizes,
                                      std::vector<double> &vSizesBGM,
                                      std::vector<double> &Us,
                                      std::vector<double> &Vs);
void transferDataStructure (GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris);

struct swapquad{
  int v[4];
  bool operator < (const swapquad &o) const
  {
    if (v[0] < o.v[0]) return true;
    if (v[0] > o.v[0]) return false;
    if (v[1] < o.v[1]) return true;
    if (v[1] > o.v[1]) return false;
    if (v[2] < o.v[2]) return true;
    if (v[2] > o.v[2]) return false;
    if (v[3] < o.v[3]) return true;
    return false;
  }
  swapquad(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
  {
    v[0] = v1->getNum();
    v[1] = v2->getNum();
    v[2] = v3->getNum();
    v[3] = v4->getNum();
    std::sort(v, v + 4);
  }
  swapquad(int v1, int v2, int v3, int v4)
  {
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
    v[3] = v4;
    std::sort(v, v + 4);
  }
};

#endif
