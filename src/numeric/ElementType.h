// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ELEMENT_TYPE_H
#define ELEMENT_TYPE_H

#include <string>

namespace ElementType {
  // Give parent type, order & dimension corresponding to any element MSH type.
  int getParentType(int type);
  int getOrder(int type);
  int getDimension(int type);

  // Give the number of node corresponding to any element MSH type.
  int getNumVertices(int type);

  // Gives > 0 if element MSH type is in Serendipity Family.
  // Gives < 2 if element MSH type is in 'Normal' Family.
  // 1 is for element MSH type that is either Serendipity or not !
  int getSerendipity(int type);

  // Give element MSH type from parent type, order & serendip
  int getType(int parentType, int order, bool serendip = false);

  // Give first order element tag
  int getPrimaryType(int type);
  std::string nameOfParentType(int type, bool plural = false);
} // namespace ElementType

#endif
