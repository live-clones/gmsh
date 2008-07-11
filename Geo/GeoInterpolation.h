// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEO_INTERPOLATION_H_
#define _GEO_INTERPOLATION_H_

#include "Geo.h"

bool iSRuledSurfaceASphere(Surface *s, SPoint3 &center, double &radius);
Vertex InterpolateCurve(Curve *Curve, double u, int derivee);
Vertex InterpolateSurface(Surface *s, double u, double v, int derivee, int u_v);
SPoint2 InterpolateCubicSpline(Vertex * v[4], double t, double mat[4][4],
                               double t1, double t2, gmshSurface *s);
#endif
