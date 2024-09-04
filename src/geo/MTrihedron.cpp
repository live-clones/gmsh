// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MTrihedron.h"

int MTrihedron::numCommonNodesInDualGraph(const MElement *const other) const
{
  switch(other->getType()) {
  case TYPE_PNT: return 1;
  case TYPE_LIN: return 2;
  case TYPE_QUA: return 4;
  case TYPE_HEX: return 4;
  case TYPE_TRIH: return 2;
  default: return 3;
  }
}
