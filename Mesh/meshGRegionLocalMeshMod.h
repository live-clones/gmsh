#ifndef _MESH_GREGION_LOCAL_MESH_MOD_H_
#define _MESH_GREGION_LOCAL_MESH_MOD_H_

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

#include "meshGRegionDelaunayInsertion.h"
#include "qualityMeasures.h"

// Local mesh modification operators. Those operators only apply to
// the "bulk" of the mesh and cannot be applied to boudnaries.  I'm
// working on it

enum gmshLocalMeshModAction {GMSH_DOIT, GMSH_EVALONLY};

bool gmshEdgeSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
                  int iLocalEdge, const gmshQualityMeasure4Tet &cr);

bool gmshFaceSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
                  int iLocalFace, const gmshQualityMeasure4Tet &cr);

bool gmshSmoothVertex(MTet4 *t, int iLocalVertex,
                      const gmshQualityMeasure4Tet &cr);

bool gmshSmoothVertexOptimize(MTet4 *t, int iVertex,
                              const gmshQualityMeasure4Tet &cr);

bool gmshCollapseVertex(std::vector<MTet4*> &newTets, MTet4 *t, 
                        int iVertex, int iTarget,
                        const gmshQualityMeasure4Tet &cr,
                        const gmshLocalMeshModAction = GMSH_DOIT,
                        double *result = 0);

bool gmshEdgeSplit(std::vector<MTet4*> &newTets, MTet4 *tet,
                   MVertex *newVertex, int iLocalEdge,
                   const gmshQualityMeasure4Tet &cr);

bool gmshSliverRemoval(std::vector<MTet4*> &newTets, MTet4 *t, 
                       const gmshQualityMeasure4Tet &cr);

#endif
