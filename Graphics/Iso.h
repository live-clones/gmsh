// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ISO_H_
#define _ISO_H_

int IsoLine(double *X, double *Y, double *Z, double *Val, double V,
            double *Xp, double *Yp, double *Zp);

int IsoTriangle(double *X, double *Y, double *Z, double *Val, double V, 
                double *Xp, double *Yp, double *Zp);

int IsoSimplex(double *X, double *Y, double *Z, double *Val, double V,
               double *Xp, double *Yp, double *Zp, double n[3]);

int CutLine(double *x, double *y, double *z, double *v,
            double min, double max, 
            double *xp, double *yp, double *zp, double *vp);

int CutTriangle(double *x, double *y, double *z, double *v,
                double min, double max, 
                double *xp, double *yp, double *zp, double *vp);

#endif
