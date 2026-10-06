// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include <memory>

class GModel;

namespace QuadOpt {

  // Seams, patterns and optimization of the quad mesh produced by PACK.
  void finishPackMesh(GModel *model);

  // Applies the PACK-specific mesh settings for the duration of a generation
  // (uniform-size bounds, recombination) and restores the caller's settings.
  class PackMeshScope {
    struct State;
    std::unique_ptr<State> _state;

  public:
    PackMeshScope();
    ~PackMeshScope();
  };

} // namespace QuadOpt
