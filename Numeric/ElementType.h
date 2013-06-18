// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _ELEMENTTYPE_H_
#define _ELEMENTTYPE_H_

class ElementType
{
 public :
  // Give parent type, order & dimension
  // corresponding to any element type.
  static int ParentTypeFromTag(int tag);
  static int OrderFromTag(int tag);
  static int DimensionFromTag(int tag);

  // Gives > 0 if element type is in Serendipity Family.
  // Gives < 2 if element type is in 'Normal' Family.
  // 1 is for element that is either Serendipity or not !
  static int SerendipityFromTag(int tag);

  static int getTag(int parentTag, int order, bool serendip = false);
};

#endif
