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

// The candidate cells are proposed along the frames
int meshCombine3D(GRegion *m, const CombineFrames *frames = nullptr);
bool MakeHybridHexTetMeshConformalThroughTriHedron(GModel *gm);
// The trihedra of the unmatched quadrangular faces of a region made
// positive (Mesh.Recombine3DPositiveTrihedra), the faces where the two
// tetrahedra on them form a pyramid left as they are if skipPyramids
void MakeTrihedraPositive(GRegion *gr, bool skipPyramids = false);
// The pairs of tetrahedra forming a pyramid on an unmatched quadrangular face
// replaced by it (Mesh.Recombine3DPyramids)
void MakeFreePyramids(GRegion *gr);

#endif
