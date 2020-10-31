#ifndef _HXT_TRIANGLE_QUALITY_H
#define _HXT_TRIANGLE_QUALITY_H

// functions that can be used in 2D xy ONLY
void    hxtJacBoundsP2PlanarTriangle     (double *xa, double *xb, double *xc, double *xabB, double *xbcB, double *xcaB, double bounds[2]);
double  hxtAreaP1PlanarTriangle          (double *xa, double *xb, double *xc);
double  hxtQualityMetricP2PlanarTriangle (double *xa, double *xb, double *xc, double *xabB, double *xbcB, double *xcaB, void (*metric)(double *x, void *data, double *m), void *data );
double  hxtQualityMetricP1lanarTriangle  (double *xa, double *xb, double *xc, void (*metric)(double *x, void *data, double *m), void *data);

// functions that can be used in 3D
double  hxtValidityP1Triangle            (double *xa, double *xb, double *xc, double *n);
double  hxtQualityP1Triangle             (double *xa, double *xb, double *xc);
double  hxtGammaTriangleQuality          (double *xa, double *xb, double *xc);
  

double hxtRightAngledQualitySimple(double *xa, double *xb, double *xc);



#endif
