// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "qoOptions.h"

class GModel;

namespace QuadOpt {

  // Seams, patterns and optimization of the quad mesh produced by PACK.
  void finishPackMesh(GModel *model, const Options &options);

} // namespace QuadOpt
