// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MHexahedron.h"
#include "Numeric.h"

int MHexahedron::getVolumeSign()
{ 
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[3]->x() - _v[0]->x();
  mat[0][2] = _v[4]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[3]->y() - _v[0]->y();
  mat[1][2] = _v[4]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[3]->z() - _v[0]->z();
  mat[2][2] = _v[4]->z() - _v[0]->z();
  return sign(det3x3(mat));
}

void MHexahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQHPts(pOrder);
  *pts = getGQHPts(pOrder);
#endif
}
