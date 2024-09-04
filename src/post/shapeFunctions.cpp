// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "shapeFunctions.h"
#include "Context.h"

double element::getTolerance() const
{
  return CTX::instance()->mesh.toleranceReferenceElement;
}
