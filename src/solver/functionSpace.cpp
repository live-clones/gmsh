// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Eric Bechet
//

#include "functionSpace.h"

const SVector3 VectorLagrangeFunctionSpaceOfElement::BasisVectors[3] = {
  SVector3(1, 0, 0), SVector3(0, 1, 0), SVector3(0, 0, 1)};
const SVector3 VectorLagrangeFunctionSpace::BasisVectors[3] = {
  SVector3(1, 0, 0), SVector3(0, 1, 0), SVector3(0, 0, 1)};
