#ifndef _ISO_H_
#define _ISO_H_

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

void InterpolateIso(double *X, double *Y, double *Z, 
		    double *Val, double V, int I1, int I2, 
		    double *XI, double *YI ,double *ZI);
  
#endif
