// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "qoOptions.h"
#include <memory>

class GModel;

namespace QuadOpt {

  // Seams, patterns and optimization of the quad mesh produced by PACK.
  void finishPackMesh(GModel *model, const Options &options);

  // Applies the PACK-specific mesh settings for the duration of a generation
  // (uniform size, recombination) and restores the caller's settings. This is
  // the adapter to Gmsh's global context; the algorithms do not use it.
  class PackMeshScope {
    struct State;
    std::unique_ptr<State> _state;

  public:
    explicit PackMeshScope(const Options &options);
    ~PackMeshScope();
  };

} // namespace QuadOpt
