// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_LOCAL_MESH_MOD_H
#define MESH_GREGION_LOCAL_MESH_MOD_H

#include "meshGRegionDelaunayInsertion.h"
#include "qualityMeasures.h"

// Local mesh modification operators. Those operators only apply to
// the "bulk" of the mesh and cannot be applied to boundaries.

enum localMeshModAction { GMSH_DOIT, GMSH_EVALONLY };

int LaplaceSmoothing(GRegion *gr);

bool edgeSwap(std::vector<MTet4 *> &newTets, MTet4 *tet, int iLocalEdge,
              const qmTetrahedron::Measures &cr,
              const std::set<MFace, MFaceLessThan> &embeddedFaces);

bool faceSwap(std::vector<MTet4 *> &newTets, MTet4 *tet, int iLocalFace,
              const qmTetrahedron::Measures &cr,
              const std::set<MFace, MFaceLessThan> &embeddedFaces);

bool smoothVertex(MTet4 *t, int iLocalVertex,
                  const qmTetrahedron::Measures &cr);

bool smoothVertexOptimize(MTet4 *t, int iVertex,
                          const qmTetrahedron::Measures &cr);

bool collapseVertex(std::vector<MTet4 *> &newTets, MTet4 *t, int iVertex,
                    int iTarget, const qmTetrahedron::Measures &cr,
                    const localMeshModAction = GMSH_DOIT,
                    double *result = nullptr);

bool edgeSplit(std::vector<MTet4 *> &newTets, MTet4 *tet, MVertex *newVertex,
               int iLocalEdge, const qmTetrahedron::Measures &cr);

#endif
