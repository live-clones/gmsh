/* $Id: Iso.h,v 1.3 2000-11-26 15:43:46 geuzaine Exp $ */
#ifndef _ISO_H_
#define _ISO_H_

void IsoSimplex (double *X, double *Y, double *Z, double *Val,
                 double V, double Vmin, double Vmax,
                 double *Offset, double Raise[3][5], int shade);

void CutTriangle1D (double *X, double *Y, double *Z, double *Val,
                    double V, double Vmin, double Vmax,
                    double *Xp, double *Yp, double *Zp, int *nb);

void CutTriangle2D (double *X, double *Y, double *Z, double *Val,
                    double V1, double V2, double Vmin, double Vmax,
                    double *Xp, double *Yp, double *Zp, int *nb,
                    double *value);

void CutLine0D (double *X, double *Y, double *Z, double *Val,
                double V, double Vmin, double Vmax,
                double *Xp, double *Yp, double *Zp, int *nb);

void CutLine1D (double *X, double *Y, double *Z, double *Val,
                double V1, double V2, double Vmin, double Vmax,
                double *Xp, double *Yp, double *Zp, int *nb,
                double *value);

#endif
