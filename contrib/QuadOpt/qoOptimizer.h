// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"
#include "qoOptions.h"

class GFace;
class GModel;

namespace QuadOpt {

  // Local cavity optimization of the mixed triangle/quad surface meshes of a
  // model: persistent half-edge, local rewrites accepted when a single energy
  // decreases, tangent-plane Winslow smoothing, work-queue scheduling.
  GMSH_API void optimizeQuads(GModel *model, const Options &options = Options());

  // The same on one face, optionally after advancing quadrangle fronts into its
  // triangles (Q-Morph, qoQMorph.cpp). False, face untouched, if it is refused.
  bool optimizeFace(GFace *gf, const Options &options = Options(),
                    bool fronts = false);

} // namespace QuadOpt
