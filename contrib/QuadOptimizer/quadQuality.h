// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#pragma once

#include "GmshGlobal.h"

#include <array>
#include <cstddef>
#include <string>
#include <vector>

class MElement;

namespace QuadOptimizer {

  enum class SurfaceElementKind { Triangle, Quadrangle };

  struct ElementQuality {
    SurfaceElementKind kind = SurfaceElementKind::Triangle;
    double warpingDegrees = 0.;
    double edgeRatio = 0.;
    double minimumAngleDegrees = 0.;
    double maximumAngleDegrees = 0.;
    double skewingDegrees = 0.;
    bool passesAbsoluteSpecifications = false;
  };

  struct SpecificationObjective {
    std::size_t absoluteViolationCount = 0;
    std::size_t preferredViolationCount = 0;
    double absolutePenalty = 0.;
    double preferredPenalty = 0.;
    double shapePenalty = 0.;
  };

  GMSH_API ElementQuality evaluateElementQuality(
    SurfaceElementKind kind,
    const std::vector<std::array<double, 3> > &vertices);

  GMSH_API ElementQuality evaluateElementQuality(const MElement *element);

  GMSH_API SpecificationObjective specificationObjective(
    const ElementQuality &quality);

  GMSH_API SpecificationObjective specificationObjective(
    const std::vector<MElement *> &elements);

  GMSH_API SpecificationObjective &operator+=(
    SpecificationObjective &left, const SpecificationObjective &right);

  GMSH_API bool improvesSpecificationObjective(
    const SpecificationObjective &candidate,
    const SpecificationObjective &reference,
    double relativeTolerance = 1.e-12);

  // Write the seven requested scalar element views plus a final absolute-pass
  // view. Only linear triangle and quadrangle corner vertices are used.
  GMSH_API bool writeQualityPos(const std::vector<MElement *> &elements,
                                const std::string &filename);

  GMSH_API bool writeFaceQualityPos(int faceTag,
                                    const std::string &filename);

  GMSH_API bool writeModelQualityPos(const std::string &filename);

} // namespace QuadOptimizer
