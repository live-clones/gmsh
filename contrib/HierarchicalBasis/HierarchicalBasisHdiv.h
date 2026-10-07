// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Nawfel BENATIA (2025), based on Ismail Badia's contribution
// (2019).
//
// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#ifndef HIERARCHICAL_BASIS_HDIV_H
#define HIERARCHICAL_BASIS_HDIV_H

#include "HierarchicalBasis.h"

class HierarchicalBasisHdiv : public HierarchicalBasis {
protected:
  HierarchicalBasisHdiv() = default;
  // the face functions for all the orientations of the faces, from the
  // functions of one face computed by orientOneFace (divergences and values)
  void addAllOrientedFaceFunctions(
    double u, double v, double w, const std::vector<double> &faceFunctions,
    std::vector<double> &quadFaceFunctionsAllOrientations,
    std::vector<double> &triFaceFunctionsAllOrientations) override;
  void addAllOrientedFaceFunctions(
    double u, double v, double w,
    const std::vector<std::vector<double>> &faceFunctions,
    std::vector<std::vector<double>> &quadFaceFunctionsAllOrientations,
    std::vector<std::vector<double>> &triFaceFunctionsAllOrientations) override;
};

#endif
