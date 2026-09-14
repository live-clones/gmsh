// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_QUAD_HALF_H
#define MESH_GFACE_QUAD_HALF_H

#include <map>
#include <vector>
#include "MEdge.h"

class GFace;
class GEdge;
class MVertex;
class MLine;

// For full-quad recombination: coarsen the 1D mesh of the boundary of a face
// by removing one node out of two (remembering the removed middle nodes),
// mesh and recombine on that half mesh, then subdivide the quadrangles and
// restore the original 1D mesh. The constructor performs the coarsening (and
// does nothing at all if the settings do not call for it); finish() does the
// recombination, the subdivision and the restoration.
class quadMeshRemoveHalfOfOneDMesh {
private:
  GFace *_gf;
  std::map<GEdge *, std::vector<MLine *>> _backup;
  std::map<GEdge *, std::vector<MVertex *>> _backupv;
  std::map<MEdge, MVertex *, MEdgeLessThan> _middle;
  void _subdivide();
  void _restore();

public:
  quadMeshRemoveHalfOfOneDMesh(GFace *gf, bool periodic);
  void finish();
};

#endif
