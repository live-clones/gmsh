// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _MESH_COMBINE_3D_
#define _MESH_COMBINE_3D_

#include <unordered_map>

class GRegion;
class GModel;
class MVertex;

// The frame (axis k in axes[3k..3k+2]) and the size along which the points
// were inserted at a vertex
struct CombineFrame {
  double axes[9];
  double size;
};
typedef std::unordered_map<MVertex *, CombineFrame> CombineFrames;

// With frames (and Mesh.Recombine3DCandidates = 1), the candidate cells are
// proposed along the frames; otherwise all the hexes and prisms of the tet
// mesh are enumerated
int meshCombine3D(GRegion *m, const CombineFrames *frames = nullptr);
bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm);

#endif
