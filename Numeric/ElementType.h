// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _ELEMENTTYPE_H_
#define _ELEMENTTYPE_H_

namespace ElementType
{
  // Give parent type, order & dimension
  // corresponding to any element type.
  int ParentTypeFromTag(int tag);
  int OrderFromTag(int tag);
  int DimensionFromTag(int tag);

  // Gives > 0 if element tag is in Serendipity Family.
  // Gives < 2 if element tag is in 'Normal' Family.
  // 1 is for element that is either Serendipity or not !
  int SerendipityFromTag(int tag);

  // Give element tag from type, order & serendip
  int getTag(int parentTag, int order, bool serendip = false);

  // Give first order element tag
  int getPrimaryTag(int tag);
}

#endif
