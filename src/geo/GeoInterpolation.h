// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEO_INTERPOLATION_H
#define GEO_INTERPOLATION_H

#include "SPoint2.h"

class Surface;
class Curve;
class Vertex;
class gmshSurface;

Vertex InterpolateCurve(Curve *Curve, double u, int derivee);
Vertex InterpolateSurface(Surface *s, double u, double v, int derivee, int u_v);
SPoint2 InterpolateCubicSpline(Vertex *v[4], double t, double mat[4][4],
                               double t1, double t2, gmshSurface *s);
#endif
