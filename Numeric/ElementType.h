// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _ELEMENT_TYPE_H_
#define _ELEMENT_TYPE_H_

#include <string>

namespace ElementType {
  // Give parent type, order & dimension corresponding to any element MSH type.
  int getParentType(int type);
  int getOrder(int type);
  int getDimension(int type);

  // Give the number of node corresponding to a msh type 'tag'.
  int getNumVertices(int type);

  // Gives > 0 if element tag is in Serendipity Family.
  // Gives < 2 if element tag is in 'Normal' Family.
  // 1 is for element that is either Serendipity or not !
  int getSerendipity(int type);

  // Give element tag from type, order & serendip
  int getType(int parentType, int order, bool serendip = false);

  // Give first order element tag
  int getPrimaryType(int type);
  std::string nameOfParentType(int type);
} // namespace ElementType

#endif
