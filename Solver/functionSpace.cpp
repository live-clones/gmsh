// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Eric Bechet
//

#include "functionSpace.h"

const SVector3 VectorLagrangeFunctionSpaceOfElement::BasisVectors[3] =
  {SVector3(1, 0, 0), SVector3(0, 1, 0), SVector3(0, 0, 1)};
const SVector3 VectorLagrangeFunctionSpace::BasisVectors[3] =
  {SVector3(1, 0, 0), SVector3(0, 1, 0), SVector3(0, 0, 1)};
