// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#ifndef QUAD_OPTIMIZER_INTEGRATION_H
#define QUAD_OPTIMIZER_INTEGRATION_H
#include <memory>
#include <string>
class GModel;
namespace QuadOptimizer {
  void optimizeQuads(GModel *, const std::string &, bool reportQuality = true);
  void finishPackMesh(GModel *);
  // Restore the caller's settings after the complete mesh generation scope.
  class PackTargetSizeScope {
    struct State;
    std::unique_ptr<State> _state;

  public:
    PackTargetSizeScope();
    ~PackTargetSizeScope();
  };
} // namespace QuadOptimizer
#endif
