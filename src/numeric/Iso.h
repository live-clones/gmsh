// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ISO_H
#define ISO_H

double InterpolateIso(double *X, double *Y, double *Z, double *Val, double V,
                      int I1, int I2, double *XI, double *YI, double *ZI);

int IsoLine(double *X, double *Y, double *Z, double *Val, double V, double *Xp,
            double *Yp, double *Zp);

int IsoTriangle(double *X, double *Y, double *Z, double *Val, double V,
                double *Xp, double *Yp, double *Zp);

int IsoSimplex(double *X, double *Y, double *Z, double *Val, double V,
               double *Xp, double *Yp, double *Zp, double n[3]);

// Order the corners of a convex polygon that lies in the plane of normal n
// around their centroid, so that it can be drawn as a fan, wound
// counter-clockwise as seen from the side n points to. Vp may be null
void OrderPolygonInPlane(int nb, const double n[3], double *Xp, double *Yp,
                         double *Zp, double *Vp);

// Cut a tetrahedron by the plane where the linear function D vanishes, with n
// the normal of that plane. Returns the number of corners of the polygon of the
// cut - a triangle or a quadrangle, ordered so that it can be drawn as a fan
// and wound counter-clockwise as seen from the side n points to - with the
// coordinates and the values interpolated along the edges the plane crosses.
// Val may be null, and Vp is then left alone
int CutSimplexByPlane(double *X, double *Y, double *Z, double *Val, double *D,
                      const double n[3], double *Xp, double *Yp, double *Zp,
                      double *Vp);

int CutLine(double *x, double *y, double *z, double *v, double min, double max,
            double *xp, double *yp, double *zp, double *vp);

int CutTriangle(double *x, double *y, double *z, double *v, double min,
                double max, double *xp, double *yp, double *zp, double *vp);

#endif
