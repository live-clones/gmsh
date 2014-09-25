// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _MESH_GREGION_LOCAL_MESH_MOD_H_
#define _MESH_GREGION_LOCAL_MESH_MOD_H_

#include "meshGRegionDelaunayInsertion.h"
#include "qualityMeasures.h"

// Local mesh modification operators. Those operators only apply to
// the "bulk" of the mesh and cannot be applied to boudnaries.  I'm
// working on it

enum localMeshModAction {GMSH_DOIT, GMSH_EVALONLY};

bool edgeSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
              int iLocalEdge, const qmTetrahedron::Measures &cr);

bool faceSwap(std::vector<MTet4*> &newTets, MTet4 *tet, 
              int iLocalFace, const qmTetrahedron::Measures &cr);

bool smoothVertex(MTet4 *t, int iLocalVertex,
                  const qmTetrahedron::Measures &cr);

bool smoothVertexOptimize(MTet4 *t, int iVertex,
                          const qmTetrahedron::Measures &cr);

bool collapseVertex(std::vector<MTet4*> &newTets, MTet4 *t, 
                    int iVertex, int iTarget,
                    const qmTetrahedron::Measures &cr,
                    const localMeshModAction = GMSH_DOIT,
                    double *result = 0);

bool egeSplit(std::vector<MTet4*> &newTets, MTet4 *tet,
              MVertex *newVertex, int iLocalEdge,
              const qmTetrahedron::Measures &cr);

bool sliverRemoval(std::vector<MTet4*> &newTets, MTet4 *t, 
                   const qmTetrahedron::Measures &cr);

#endif
