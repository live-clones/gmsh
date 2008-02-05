#ifndef _MESH_GFACEBDS_H_
#define _MESH_GFACEBDS_H_

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
class GFace;
class GModel;
class BDS_Mesh;
class BDS_Point;
class MVertex;

void computeMeshSizeFieldAccuracy (GFace *gf, BDS_Mesh &m, double &avg, double &max_e, double &min_e, int &nE, int &GS);
void computeElementShapes (GFace *gf, BDS_Mesh &m, double &worst, double &avg, double &best, int &nT, int &nbGQ);
void gmshRefineMeshBDS (GFace *gf, 
			BDS_Mesh &m, 
			const int NIT, 
			const bool computeNodalSizeField);
void gmshOptimizeMeshBDS(GFace *gf, 
			 BDS_Mesh &m, 
			 const int NIT, 
			 std::map<BDS_Point*,MVertex*> *recover_map = 0);

void gmshDelaunayizeBDS ( GFace *gf, BDS_Mesh &m, int &nb_swap );

void gmshCollapseSmallEdges (GModel &gm);

#endif
