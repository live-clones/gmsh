// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GREGION_LOCAL_MESH_MOD_H_
#define _MESH_GREGION_LOCAL_MESH_MOD_H_

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
