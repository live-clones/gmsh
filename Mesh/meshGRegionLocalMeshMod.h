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

enum localMeshModAction {GMSH_DOIT, GMSH_EVALONLY};

bool edgeSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
              int iLocalEdge, const qualityMeasure4Tet &cr);

bool faceSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
              int iLocalFace, const qualityMeasure4Tet &cr);

bool smoothVertex(MTet4 *t, int iLocalVertex,
                  const qualityMeasure4Tet &cr);

bool smoothVertexOptimize(MTet4 *t, int iVertex,
                          const qualityMeasure4Tet &cr);

bool collapseVertex(std::vector<MTet4*> &newTets, MTet4 *t, 
                    int iVertex, int iTarget,
                    const qualityMeasure4Tet &cr,
                    const localMeshModAction = GMSH_DOIT,
                    double *result = 0);

bool egeSplit(std::vector<MTet4*> &newTets, MTet4 *tet,
              MVertex *newVertex, int iLocalEdge,
              const qualityMeasure4Tet &cr);

bool sliverRemoval(std::vector<MTet4*> &newTets, MTet4 *t, 
                   const qualityMeasure4Tet &cr);

#endif
