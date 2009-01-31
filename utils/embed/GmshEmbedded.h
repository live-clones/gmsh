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
    pickElements = 0;
    hideUnselected = 0;
    geom.tolerance = 1.e-6;
    mesh.reverseAllNormals = 1;
    mesh.secondOrderExperimental = 0;
  }
  double lc;
  int pickElements;
  int hideUnselected;
  struct{
    double tolerance;
  } geom;
  struct{
    int reverseAllNormals;
    int secondOrderExperimental;
  } mesh;
  unsigned int packColor(int,int,int,int){ return 0; }
  int unpackRed(unsigned int){ return 0; }
  int unpackGreen(unsigned int){ return 0; }
  int unpackBlue(unsigned int){ return 0; }
  int unpackAlpha(unsigned int){ return 0; }
};

class smooth_normals{
 public:
  int dummy;
};

#endif
