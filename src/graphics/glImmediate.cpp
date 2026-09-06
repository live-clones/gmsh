// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "glImmediate.h"
#include "drawContext.h"

void gmshColor4ubv(const void *col)
{
  if(!drawContext::pickColorActive()) glColor4ubv((const GLubyte *)col);
}
