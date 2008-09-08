// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_EMBEDDED_H_
#define _GMSH_EMBEDDED_H_

#include "NumericEmbedded.h"

class Context_T{
public:
  Context_T()
  {
    lc = 1.;
    hide_unselected = 0;
    geom.tolerance = 1.e-6;
    mesh.reverse_all_normals = 1;
    mesh.second_order_experimental = 0;
    pick_elements = 0;
  }
  double lc;
  int hide_unselected;
  int pick_elements;
  struct{
    double tolerance;
  } geom;
  struct{
    int reverse_all_normals;
    int second_order_experimental;
  } mesh;
  unsigned int PACK_COLOR(int,int,int,int){ return 0; }
  int UNPACK_RED(unsigned int){ return 0; }
  int UNPACK_GREEN(unsigned int){ return 0; }
  int UNPACK_BLUE(unsigned int){ return 0; }
  int UNPACK_ALPHA(unsigned int){ return 0; }
};

class smooth_normals{
 public:
  int dummy;
};

#endif
