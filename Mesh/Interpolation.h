#ifndef _INTERPOLATION_H_
#define _INTERPOLATION_H_

Vertex InterpolateCurve (Curve * Curve, double u, int derivee);

Vertex InterpolateSurface (Surface * s, double u, double v, 
			   int derivee, int u_v);

Vertex TransfiniteQua (Vertex c1, Vertex c2, Vertex c3, Vertex c4,
		       Vertex s1, Vertex s2, Vertex s3, Vertex s4,
		       double u, double v);

Vertex TransfiniteTri (Vertex c1, Vertex c2, Vertex c3,
		       Vertex s1, Vertex s2, Vertex s3,
		       double u, double v);

Vertex TransfiniteHex 
  (Vertex f1, Vertex f2, Vertex f3, Vertex f4, Vertex f5, Vertex f6,
   Vertex c1, Vertex c2, Vertex c3, Vertex c4, Vertex c5, Vertex c6,
   Vertex c7, Vertex c8, Vertex c9, Vertex c10, Vertex c11, Vertex c12,
   Vertex s1, Vertex s2, Vertex s3, Vertex s4,
   Vertex s5, Vertex s6, Vertex s7, Vertex s8,
   double u, double v, double w);

void TransfiniteSph (Vertex S, Vertex center, Vertex * T);

void Normal2Surface (Surface * s, double u, double v, double n[3]);

Vertex InterpolateCubicSpline (Vertex * v[4], double t, double mat[4][4],
			       int derivee, double t1, double t2);
Vertex InterpolateUBS (Curve * Curve, double u, int derivee);
  
Vertex InterpolateNurbs (Curve * Curve, double u, int derivee);

Vertex InterpolateNurbsSurface (Surface * s, double u, double v);

#endif


