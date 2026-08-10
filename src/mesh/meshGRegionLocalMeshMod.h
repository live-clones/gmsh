// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_LOCAL_MESH_MOD_H
#define MESH_GREGION_LOCAL_MESH_MOD_H

#include "meshGRegionTet4.h"
#include "qualityMeasures.h"

// Local mesh modification operators. Those operators only apply to
// the "bulk" of the mesh and cannot be applied to boundaries.

enum localMeshModAction { GMSH_DOIT, GMSH_EVALONLY };

// the possible retriangulations of the ring of an edge, for edge swaps
typedef struct {
  int nbr_triangles; // number of different triangles
  int (*triangles)[3]; // triangles array
  int nbr_trianguls; // number of different triangulations
  int nbr_triangles_2; // number of triangles / triangulation
  int (*trianguls)[5]; // retriangulations array
} SwapPattern;

void BuildSwapPattern3(SwapPattern *sc);
void BuildSwapPattern4(SwapPattern *sc);
void BuildSwapPattern5(SwapPattern *sc);
void BuildSwapPattern6(SwapPattern *sc);
void BuildSwapPattern7(SwapPattern *sc);

bool edgeSwap(std::vector<MTet4 *> &newTets, MTet4 *tet, int iLocalEdge,
              const qmTetrahedron::Measures &cr,
              const std::set<MFace, MFaceLessThan> &embeddedFaces);

bool faceSwap(std::vector<MTet4 *> &newTets, MTet4 *tet, int iLocalFace,
              const qmTetrahedron::Measures &cr,
              const std::set<MFace, MFaceLessThan> &embeddedFaces);

bool smoothVertex(MTet4 *t, int iLocalVertex,
                  const qmTetrahedron::Measures &cr);

bool collapseVertex(std::vector<MTet4 *> &newTets, MTet4 *t, int iVertex,
                    int iTarget, const qmTetrahedron::Measures &cr,
                    const localMeshModAction = GMSH_DOIT,
                    double *result = nullptr);

#endif
