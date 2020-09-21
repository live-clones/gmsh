#include "hxt_point_gen_numerics.h"
#include "predicates.h"
#include <math.h>

int hxtGetSys2x2(double mat[2][2], double b[2], double res[2])
// FUNCTION sys2x2 from gmsh/Numeric/Numeric.cpp
{
  double det, ud, norm;
  int i;

  norm = mat[0][0]*mat[0][0] + mat[1][1]*mat[1][1] + mat[0][1]*mat[0][1] + mat[1][0]*mat[1][0];
  det  = mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || fabs(det) / norm < 1.e-16) {
    if(norm) //Msg::Debug("Assuming 2x2 matrix is singular (det/norm == %.16g)", fabs(det) / norm);
        HXT_WARNING("Assuming 2x2 matrix is singular (det/norm == %.16g)\n", fabs(det) / norm);
    res[0] = res[1] = 0.0;
    return 0;
  }
  ud = 1. / det;

  res[0] = b[0] * mat[1][1] - mat[0][1] * b[1];
  res[1] = mat[0][0] * b[1] - mat[1][0] * b[0];

  for(i = 0; i < 2; i++)
    res[i] *= ud;

  return (1);
}

double hxtGetDet2x2(double mat[2][2])
// FUNCTION det2x2 from gmsh/Numeric/Numeric.cpp 
{
  return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

double det3x3(double mat[3][3])
{
 return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
         mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
         mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
}

double inv3x3(double mat[3][3], double inv[3][3])
{
  double det = det3x3(mat);
  if(det){
    double ud = 1. / det;
    inv[0][0] =  (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] =  (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] =  (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] =  (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] =  (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
  }
  else{
    HXT_WARNING("Singular matrix 3x3");
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        inv[i][j] = 0.;
  }
  return det;
}

HXTStatus hxtVector(const double *v0, const double *v1, double *vec)
{
  vec[0] = v1[0] - v0[0];
  vec[1] = v1[1] - v0[1];
  vec[2] = v1[2] - v0[2];

  normalize(vec);

  return HXT_STATUS_OK;

}

// from Ginzburg
double myDot(double *a, double *b)
{
  double d = 0.;
  for (int i=0; i<3; i++)
    d += a[i]*b[i];
  return d;
}

double norm(double *u)
{
  return sqrt(u[0]*u[0] + u[1]*u[1] + u[2]*u[2]);
}

HXTStatus normalize(double *u)
{
  double nu = norm(u);
  u[0] /= nu; u[1] /= nu; u[2] /= nu;
  return HXT_STATUS_OK;
}

HXTStatus myCrossprod(double *a, double *b, double *n)
{ 
  n[0] = a[1]*b[2]-a[2]*b[1];
  n[1] = a[2]*b[0]-a[0]*b[2];
  n[2] = a[0]*b[1]-a[1]*b[0];
  return HXT_STATUS_OK;
}

// from Ginzburg
HXTStatus myNormalizedCrossprod(double *a, double *b, double *n)
{ 
  n[0] = a[1]*b[2]-a[2]*b[1];
  n[1] = a[2]*b[0]-a[0]*b[2];
  n[2] = a[0]*b[1]-a[1]*b[0];
  double nn = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  n[0] /= nn; n[1] /= nn; n[2] /= nn;
  return HXT_STATUS_OK;
}



HXTStatus normal2triangle(const HXTMesh *mesh, uint64_t ct, double *n)
{
  const double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+0];
  const double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+1];
  const double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+2];

  double a[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double b[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  
  HXT_CHECK(myNormalizedCrossprod(a,b,n));
  return HXT_STATUS_OK;
}

HXTStatus normal2triangleV(double *v0, double *v1, double *v2, double *n)
{
  double a[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double b[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  
  HXT_CHECK(myNormalizedCrossprod(a,b,n));
  return HXT_STATUS_OK;
}

// Area = norm(normal)/2.;
HXTStatus normal2triangleArea(const HXTMesh *mesh, uint64_t ct, double *n)
{
  const double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+0];
  const double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+1];
  const double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+2];

  double a[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double b[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  
  HXT_CHECK(myCrossprod(a,b,n));
  return HXT_STATUS_OK;
}

HXTStatus normal2triangleAreaV(double *v0, double *v1, double *v2, double *n)
{
  double a[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double b[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  
  HXT_CHECK(myCrossprod(a,b,n));
  return HXT_STATUS_OK;
}

double hxtTriangleArea3D (double * xa, double *xb, double *xc) {
  double ba[3] = {xb[0] - xa[0] , xb[1] - xa[1] , xb[2] - xa[2] };
  double ca[3] = {xc[0] - xa[0] , xc[1] - xa[1] , xc[2] - xa[2] };
  double cross[3];
  HXT_CHECK(myCrossprod(ba, ca,cross));
  return 0.5*sqrt(cross[0]*cross[0]+cross[1]*cross[1]+cross[2]*cross[2]);
}


double hxtAngle(double *v0, double *v1)
{
  double cosTheta = myDot(v0,v1);
  double temp[3];
  myCrossprod(v0,v1,temp);
  double sinTheta = norm(temp);
  
  return atan2(sinTheta,cosTheta);
}

double hxtAngle_0_pi(double *v0, double *v1)
{
  double dot = myDot(v0,v1);
  dot = ( dot < -1.0 ? -1.0 : ( dot > 1.0 ? 1.0 : dot ) );
  double angle = acos( dot );

  return angle;
}

double hxtAngleSigned(double *v0, double *v1, double *n)
{
  double cosTheta = myDot(v0,v1);
  double temp[3];
  myCrossprod(v0,v1,temp);
  double sinTheta = myDot(temp,n);

  double angle = atan2(sinTheta,cosTheta);
  return angle;
}

double hxtAngle_0_2pi(double *v0, double *v1, double *n)
{
  double cosTheta = myDot(v0,v1);
  double temp[3];
  myCrossprod(v0,v1,temp);
  double sinTheta = myDot(temp,n);

  double angle = atan2(sinTheta,cosTheta);

  if (angle<0) angle += 2*M_PI;
  return angle;
}

double hxtAngle3Vertices(double *v0, double *v1, double *v2)
{
  double a[3];
  a[0] = v0[0] - v1[0];
  a[1] = v0[1] - v1[1];
  a[2] = v0[2] - v1[2];
  double b[3];
  b[0] = v2[0] - v1[0];
  b[1] = v2[1] - v1[1];
  b[2] = v2[2] - v1[2];

  double c[3];
  myCrossprod(a,b,c);
  double sinA = norm(c);
  double cosA = myDot(a,b);

  double angle = atan2(sinA,cosA);

  return angle;
}



// Euclidean distance of two points squared for comparison
double distance2(double *a, double *b)
{
  double p[3] = {b[0]-a[0], b[1]-a[1], b[2]-a[2]};
  return myDot(p,p);
}

// Euclidean distance of two points 
double distance(double *a, double *b)
{
  return sqrt(distance2(a,b));
}

// from gmsh Numeric.cpp 
HXTStatus hxtSignedDistancePointEdge(double *p1, double *p2, double *p,
                                  double *d,  double *t, double *closePt)
{
  double v12[3] = {p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2]};
  double v1p[3] = { p[0]-p1[0],  p[1]-p1[1],  p[2]-p1[2]};
  const double alpha = myDot(v1p,v12) / myDot(v12,v12);

  //double closePt[3] = {0.};

  if (alpha <= 0.){
    closePt[0] = p1[0];
    closePt[1] = p1[1];
    closePt[2] = p1[2];
  }
  else if (alpha >= 1.){
    closePt[0] = p2[0];
    closePt[1] = p2[1];
    closePt[2] = p2[2];
  }
  else{
    closePt[0] = p1[0] + (p2[0]-p1[0]) * alpha;
    closePt[1] = p1[1] + (p2[1]-p1[1]) * alpha;
    closePt[2] = p1[2] + (p2[2]-p1[2]) * alpha;
  }

  (*d) = distance(p,closePt);
  (*t) = alpha;

  return HXT_STATUS_OK;
}
  

// from gmsh Numeric.cpp 
HXTStatus hxtSignedDistancePointTriangle(double *p1, double *p2, double *p3,
				                                 double *p, 
				                                 double *d, int *inside, double *closePt)
				                                 //double *d, double *closePt, int *inside)
{
  double t1[3] = {p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2]};
  double t2[3] = {p3[0]-p1[0], p3[1]-p1[1], p3[2]-p1[2]};
  double t3[3] = {p3[0]-p2[0], p3[1]-p2[1], p3[2]-p2[2]};
  double n[3];
  myNormalizedCrossprod(t1,t2,n);
  const double n2t1 = myDot(t1, t1);
  const double n2t2 = myDot(t2, t2);
  const double n2t3 = myDot(t3, t3);
  double mat[3][3] = {{t1[0], t2[0], -n[0]},
                      {t1[1], t2[1], -n[1]},
                      {t1[2], t2[2], -n[2]}};
  double inv[3][3];
  double det = inv3x3(mat, inv);
  // why error ??? 
  if(det == 0.0) return(HXT_ERROR_MSG(HXT_STATUS_FAILED, "Determinant = 0"));

  double u, v;
  double pp1[3] = {p[0]-p1[0], p[1]-p1[1], p[2]-p1[2]};
  u    = (inv[0][0] * pp1[0] + inv[0][1] * pp1[1] + inv[0][2] * pp1[2]);
  v    = (inv[1][0] * pp1[0] + inv[1][1] * pp1[1] + inv[1][2] * pp1[2]);
  (*d) = (inv[2][0] * pp1[0] + inv[2][1] * pp1[1] + inv[2][2] * pp1[2]);
  double sign = ((*d) > 0) ? 1. : -1.;
  if ((*d) == 0.) sign = 1.;
  if (u >= 0. && v >= 0. && 1.-u-v >= 0.){ //P(p) inside triangle
    *inside = 1;
    closePt[0] = p1[0] + (p2[0]-p1[0])*u + (p3[0]-p1[0])*v;
    closePt[1] = p1[1] + (p2[1]-p1[1])*u + (p3[1]-p1[1])*v;
    closePt[2] = p1[2] + (p2[2]-p1[2])*u + (p3[2]-p1[2])*v;
  }
  else {
    *inside = 0;
    const double t12 = myDot(pp1, t1) / n2t1;
    const double t13 = myDot(pp1, t2) / n2t2;
    double pp2[3] = {p[0]-p2[0], p[1]-p2[1], p[2]-p2[2]};
    const double t23 = myDot(pp2, t3) / n2t3;
    (*d) = 1.e10;
    if (t12 >= 0 && t12 <= 1.){
      double temp[3] = {p1[0]+(p2[0]-p1[0])*t12,
                        p1[1]+(p2[1]-p1[1])*t12,
                        p1[2]+(p2[2]-p1[2])*t12};
      (*d) = sign * fmin(fabs((*d)),distance(p,temp));
      //d = sign * std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12));
      closePt[0] = temp[0];
      closePt[1] = temp[1];
      closePt[2] = temp[2];
      //closePt = p1 + (p2 - p1) * t12;
    }
    if (t13 >= 0 && t13 <= 1.){
      double temp[3] = {p1[0]+(p3[0]-p1[0])*t13,
                        p1[1]+(p3[1]-p1[1])*t13,
                        p1[2]+(p3[2]-p1[2])*t13};
      if (distance(p,temp)<fabs(*d)){
        closePt[0] = temp[0];
        closePt[1] = temp[1];
        closePt[2] = temp[2];
      }
      //if (p.distance(p1 + (p3 - p1) * t13) < fabs(d)) closePt = p1 + (p3 - p1) * t13;
      (*d) = sign * fmin(fabs((*d)),distance(p,temp));
      //d = sign * std::min(fabs(d), p.distance(p1 + (p3 - p1) * t13));
    }
    if (t23 >= 0 && t23 <= 1.){
      double temp[3] = {p2[0]+(p3[0]-p2[0])*t23,
                        p2[1]+(p3[1]-p2[1])*t23,
                        p2[2]+(p3[2]-p2[2])*t23};
      if (distance(p,temp)<fabs(*d)){
        closePt[0] = temp[0];
        closePt[1] = temp[1];
        closePt[2] = temp[2];
      }
      //if (p.distance(p2 + (p3 - p2) * t23) < fabs(d)) closePt = p2 + (p3 - p2) * t23;
      (*d) = sign * fmin(fabs((*d)),distance(p,temp));
      //d = sign * std::min(fabs(d), p.distance(p2 + (p3 - p2) * t23));
    }
    if (distance(p,p1) < fabs(*d)){
      closePt[0] = p1[0];
      closePt[1] = p1[1];
      closePt[2] = p1[2];
      (*d) = sign * fmin(fabs(*d), distance(p,p1));
    }
    if (distance(p,p2) < fabs(*d)){
      closePt[0] = p2[0];
      closePt[1] = p2[1];
      closePt[2] = p2[2];
      (*d) = sign * fmin(fabs(*d), distance(p,p2));
    }
    if (distance(p,p3) < fabs(*d)){
      closePt[0] = p3[0];
      closePt[1] = p3[1];
      closePt[2] = p3[2];
      (*d) = sign * fmin(fabs(*d), distance(p,p3));
    }

  }

  return HXT_STATUS_OK;
}








static inline HXTStatus triangleTangentFrame(const HXTMesh *mesh, uint64_t ct, double *t1, double *t2)
{

  uint32_t vtri[3] = {mesh->triangles.node[3*ct+0],
                      mesh->triangles.node[3*ct+1],
                      mesh->triangles.node[3*ct+2]};

  const double *v0 = mesh->vertices.coord + 4*vtri[0];
  const double *v1 = mesh->vertices.coord + 4*vtri[1];
  const double *v2 = mesh->vertices.coord + 4*vtri[2];

  t1[0] = v2[0]-v0[0];
  t1[1] = v2[1]-v0[1];
  t1[2] = v2[2]-v0[2];
  HXT_CHECK(normalize(t1));
  double tb[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};
  double n[3];
  HXT_CHECK(myNormalizedCrossprod(t1,tb,n));
  HXT_CHECK(myNormalizedCrossprod(n,t1,t2));

  return HXT_STATUS_OK;

}

static inline HXTStatus triangleLocalCoords(const HXTMesh *mesh, uint64_t ct, double *v, double *p)
{
  uint32_t vtri[3] = {mesh->triangles.node[3*ct+0],
                      mesh->triangles.node[3*ct+1],
                      mesh->triangles.node[3*ct+2]};

  double t1[3] = {0.}, t2[3]={0.};
  HXT_CHECK(triangleTangentFrame(mesh,ct,t1,t2));

  double pp[3] = {v[0] - mesh->vertices.coord[4*vtri[0]+0],   
                  v[1] - mesh->vertices.coord[4*vtri[0]+1], 
                  v[2] - mesh->vertices.coord[4*vtri[0]+2]}; 
  
  p[0] = myDot(t1,pp);
  p[1] = myDot(t2,pp);

  return HXT_STATUS_OK; 
}



// TODO change this to return all barycentric coords
HXTStatus hxtGetBarycentric(const HXTMesh *mesh, uint64_t ct, double *p, double *uv)
{
  uint32_t vtri[3] = {mesh->triangles.node[3*ct+0],
                      mesh->triangles.node[3*ct+1],
                      mesh->triangles.node[3*ct+2]};

  double vv[2];
  HXT_CHECK(triangleLocalCoords(mesh,ct,p,vv));
  double p0[2],p1[2],p2[2];
  HXT_CHECK(triangleLocalCoords(mesh,ct,mesh->vertices.coord + 4*vtri[0], p0));
  HXT_CHECK(triangleLocalCoords(mesh,ct,mesh->vertices.coord + 4*vtri[1], p1));
  HXT_CHECK(triangleLocalCoords(mesh,ct,mesh->vertices.coord + 4*vtri[2], p2));
    
  double x1 = orient2d(p0,p1,vv);
  //double x2 = orient2d(p1,p2,vv);
  double x3 = orient2d(p2,p0,vv);
  double x4 = orient2d(p0,p1,p2);

  uv[0] = x3/x4; // OF VERTEX 1 
  uv[1] = x1/x4; // OF VERTEX 2 

  return HXT_STATUS_OK; 
}

HXTStatus hxtGetBarycentricTetra(const HXTMesh *mesh, uint64_t ct, double *p, double *uv)
{
  uint32_t vtet[4] = {mesh->tetrahedra.node[4*ct+0],
                      mesh->tetrahedra.node[4*ct+1],
                      mesh->tetrahedra.node[4*ct+2],
                      mesh->tetrahedra.node[4*ct+3]};

  const double *v0 = mesh->vertices.coord + 4*vtet[0];
  const double *v1 = mesh->vertices.coord + 4*vtet[1];
  const double *v2 = mesh->vertices.coord + 4*vtet[2];
  const double *v3 = mesh->vertices.coord + 4*vtet[3];

  double x0 = orient3d(p, v1, v2, v3);
  double x1 = orient3d(p, v0, v2, v3);
  double x2 = orient3d(p, v0, v1, v3);
  //double x3 = orient3d(p, v0, v1, v2);
  double x4 = orient3d(v0, v1, v2, v3);
  double x5 = orient3d(v1, v0, v2, v3);
  double x6 = orient3d(v2, v0, v1, v3);
  //double x7 = orient3d(v3, v0, v1, v2);
  
  uv[0] = x0/x4;
  uv[1] = x1/x5;
  uv[2] = x2/x6;
  //uv[3] = x3/x7;
  uv[3] = 1.-uv[0]-uv[1]-uv[2];

  return HXT_STATUS_OK;
}

HXTStatus hxtGetTriangleCentroid(const HXTMesh *mesh, uint64_t ct, double *p)
{
  uint32_t vtri[3] = {mesh->triangles.node[3*ct+0],
                      mesh->triangles.node[3*ct+1],
                      mesh->triangles.node[3*ct+2]};

  for (uint32_t i=0; i<3; i++){
    p[i] = mesh->vertices.coord[4*vtri[0]+i]+
           mesh->vertices.coord[4*vtri[1]+i]+
           mesh->vertices.coord[4*vtri[2]+i];
    p[i]/=3.;

  }

  return HXT_STATUS_OK; 
}

// From gmsh Numeric/Numeric.cpp
HXTStatus hxtCircumCenterXY(double *p1, double *p2, double *p3, double *res)
{
  double d, a1, a2, a3;

  const double x1 = p1[0];
  const double x2 = p2[0];
  const double x3 = p3[0];
  const double y1 = p1[1];
  const double y2 = p2[1];
  const double y3 = p3[1];

  d = 2. * (double)(y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2));
  if(d == 0.0) {
    //    Msg::Warning("Colinear points in circum circle computation");
    // TODO here what??? 
    res[0] = res[1] = -99999.;
    return HXT_STATUS_FAILED;
  }

  a1 = x1 * x1 + y1 * y1;
  a2 = x2 * x2 + y2 * y2;
  a3 = x3 * x3 + y3 * y3;
  res[0] = (double)((a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d);
  res[1] = (double)((a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d);
  
  return HXT_STATUS_OK;
}

// From gmsh Numeric/Numeric.cpp
HXTStatus hxtCircumCenterXYZ(double *p1, double *p2, double *p3, double *res, double *uv)
{
  double v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3];
  myCrossprod(vx,vy,vz);
  myCrossprod(vz,vx,vy);
  normalize(vx);
  normalize(vy);
  normalize(vz);

  double p1P[2] = {0.0, 0.0};
  double p2P[2] = {myDot(v1, vx), myDot(v1, vy)};
  double p3P[2] = {myDot(v2, vx), myDot(v2, vy)};

  double resP[2];

  HXT_CHECK(hxtCircumCenterXY(p1P, p2P, p3P, resP));

  if(uv) {
    double mat[2][2] = {{p2P[0] - p1P[0], p3P[0] - p1P[0]},
                        {p2P[1] - p1P[1], p3P[1] - p1P[1]}};
    double rhs[2] = {resP[0] - p1P[0], resP[1] - p1P[1]};
    hxtGetSys2x2(mat, rhs, uv);
  }

  res[0] = p1[0] + resP[0] * vx[0] + resP[1] * vy[0];
  res[1] = p1[1] + resP[0] * vx[1] + resP[1] * vy[1];
  res[2] = p1[2] + resP[0] * vx[2] + resP[1] * vy[2];

  return HXT_STATUS_OK;
}

