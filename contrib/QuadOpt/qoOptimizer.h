// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"

class GModel;

namespace QuadOpt {

  // Local cavity optimization of the mixed triangle/quad surface meshes of a
  // model: persistent half-edge, local rewrites accepted when a single energy
  // decreases, tangent-plane Winslow smoothing, work-queue scheduling.
  GMSH_API void optimizeQuads(GModel *model);

} // namespace QuadOpt
