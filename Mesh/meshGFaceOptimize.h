#ifndef _MESHGFACEOPTIMIZE_H_
#define _MESHGFACEOPTIMIZE_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
typedef std::map<MVertex*,std::vector<MTriangle*> > v2t_cont ;
typedef std::map<MEdge, std::pair<MTriangle*,MTriangle*> , Less_Edge> e2t_cont ;
void buildVertexToTriangle ( std::vector<MTriangle*> & ,  v2t_cont &adj );
void buildEdgeToTriangle ( std::vector<MTriangle*> & ,  e2t_cont &adj );
void laplaceSmoothing   (GFace *gf);
void edgeSwappingLawson (GFace *gf);
enum gmshSwapCriterion  {SWCR_DEL, SWCR_QUAL,SWCR_NORM,SWCR_CLOSE};
enum gmshSplitCriterion {SPCR_CLOSE, SPCR_QUAL,SPCR_ALLWAYS};
int edgeSwapPass (GFace *gf, std::set<MTri3*,compareTri3Ptr> &allTris, 
		  const gmshSwapCriterion &cr,		   
		  const std::vector<double> & Us ,
		  const std::vector<double> & Vs,
		  const std::vector<double> & vSizes ,
		  const std::vector<double> & vSizesBGM);


bool gmshEdgeSwap(MTri3 *t1, 
		  GFace *gf,
		  int iLocalEdge,
		  std::vector<MTri3*> &newTris,
		  const gmshSwapCriterion &cr,		   
		  const std::vector<double> & Us,
		  const std::vector<double> & Vs,
		  const std::vector<double> & vSizes,
		  const std::vector<double> & vSizesBGM);

bool gmshEdgeSplit(const double lMax,
		   MTri3 *t1, 
		   GFace *gf,
		   int iLocalEdge,
		   std::vector<MTri3*> &newTris,
		   const gmshSplitCriterion &cr,		   
		   std::vector<double> & Us,
		   std::vector<double> & Vs,
		   std::vector<double> & vSizes,
		   std::vector<double> & vSizesBGM);

int edgeSplitPass (double maxLC,
		   GFace *gf, std::set<MTri3*,compareTri3Ptr> &allTris,
		   const gmshSplitCriterion &cr,		   
		   std::vector<double> & Us ,
		   std::vector<double> & Vs,
		   std::vector<double> & vSizes ,
		   std::vector<double> & vSizesBGM);

int edgeCollapsePass (double minLC,
		      GFace *gf, std::set<MTri3*,compareTri3Ptr> &allTris,
		      std::vector<double> & Us ,
		      std::vector<double> & Vs,
		      std::vector<double> & vSizes ,
		      std::vector<double> & vSizesBGM);
#endif
