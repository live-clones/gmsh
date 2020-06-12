#ifndef HXT_POINT_GEN_NUMERICS_H
#define HXT_POINT_GEN_NUMERICS_H
#include "hxt_tools.h"
#include "hxt_mesh.h"

// In Gmsh Numeric.cpp
int       hxtGetSys2x2(double mat[2][2], double b[2], double res[2]);
double    hxtGetDet2x2(double mat[2][2]);
//double    det3x3(double mat[3][3]);
//double    inv3x3(double mat[3][3], double inv[3][3]);

HXTStatus hxtVector(const double *v0, const double *v1, double *vec);
double    myDot(double *a, double *b);
double    norm(double *u);

HXTStatus normalize(double *u);
HXTStatus myCrossprod(double *a, double *b, double *n);
HXTStatus myNormalizedCrossprod(double *a, double *b, double *n);
HXTStatus normal2triangle(const HXTMesh *mesh, uint64_t ct, double *n);
HXTStatus normal2triangleV(double *v0, double *v1, double *v2, double *n);
HXTStatus normal2triangleArea(const HXTMesh *mesh, uint64_t ct, double *n);
HXTStatus normal2triangleAreaV(double *v0, double *v1, double *v2, double *n);
double    hxtTriangleArea3D (double * xa, double *xb, double *xc);


double    hxtAngle(double *v0, double *v1);
double    hxtAngle_0_pi(double *v0, double *v1);
double    hxtAngleSigned(double *v0, double *v1, double *n);
double    hxtAngle_0_2pi(double *v0, double *v1, double *n);
double    distance2(double *a, double *b);
double    distance(double *a, double *b);

HXTStatus hxtSignedDistancePointEdge(double *p1, double *p2, double *p,
                                  double *d,  double *t, double *closePt);

HXTStatus hxtSignedDistancePointTriangle(double *p1, double *p2, double *p3,
				                              double *p, 
				                              double *d, int *inside, double *closePt);

HXTStatus hxtGetBarycentric(const HXTMesh *mesh, uint64_t ct, double *p, double *uv);
HXTStatus hxtGetBarycentricTetra(const HXTMesh *mesh, uint64_t ct, double *p, double *uv);

HXTStatus hxtGetTriangleCentroid(const HXTMesh *mesh, uint64_t ct, double *p);
HXTStatus hxtCircumCenterXYZ(double *p1, double *p2, double *p3, double *res, double *uv);

#endif
