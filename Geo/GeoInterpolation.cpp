// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GeoStringInterface.h"
#include "Numeric.h"
#include "Context.h"

#define SQU(a)      ((a)*(a))

static Vertex InterpolateCubicSpline(Vertex *v[4], double t, double mat[4][4],
                                     int derivee, double t1, double t2)
{
  Vertex V;
  int i, j;
  double vec[4], T[4];

  V.Pos.X = V.Pos.Y = V.Pos.Z = 0.0;
  V.lc = (1 - t) * v[1]->lc + t * v[2]->lc;
  V.w = (1 - t) * v[1]->w + t * v[2]->w;

  if(derivee == 1) {
    T[3] = 0.;
    T[2] = 1.;
    T[1] = 2. * t;
    T[0] = 3. * t * t;
  }
  else if(derivee == 2) {
    T[3] = 0.;
    T[2] = 0.;
    T[1] = 2.;
    T[0] = 6. * t;
  }
  else {
    T[3] = 1.;
    T[2] = t;
    T[1] = t * t;
    T[0] = t * t * t;
  }

  for(i = 0; i < 4; i++) {
    vec[i] = 0.0;
  }

  // X
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.X;
    }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.X += T[j] * vec[j];
    vec[j] = 0.0;
  }

  // Y
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.Y;
    }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.Y += T[j] * vec[j];
    vec[j] = 0.0;
  }

  // Z
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.Z;
    }
  }
  for(j = 0; j < 4; j++) {
    V.Pos.Z += T[j] * vec[j];
    vec[j] = 0.0;
  }

  if(derivee == 1) {
    V.Pos.X /= ((t2 - t1));
    V.Pos.Y /= ((t2 - t1));
    V.Pos.Z /= ((t2 - t1));
  }
  else if(derivee == 2) {
    V.Pos.X /= ((t2 - t1)*(t2 - t1));
    V.Pos.Y /= ((t2 - t1)*(t2 - t1));
    V.Pos.Z /= ((t2 - t1)*(t2 - t1));
  }

  return V;
}

// interpolation in the parametric space !
SPoint2 InterpolateCubicSpline(Vertex *v[4], double t, double mat[4][4],
                               double t1, double t2, gmshSurface *s, int derivee)
{
  Vertex V;
  int i, j;
  double T[4] = {0., 0., 0., 0.};

  if (derivee == 0){
    T[3] = 1.;
    T[2] = t;
    T[1] = t * t;
    T[0] = t * t * t;
  }
  else if (derivee == 1){
    T[3] = 0.;
    T[2] = 1;
    T[1] = 2 * t;
    T[0] = 3 * t * t;
  }
  else if (derivee == 2){
    T[3] = 0.;
    T[2] = 0;
    T[1] = 2;
    T[0] = 6 * t;
  }

  SPoint2 coord [4], p;

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      coord[i] +=  v[j]->pntOnGeometry * mat[i][j] ;
    }
  }

  for(j = 0; j < 4; j++) {
    p += coord[j] * T[j] ;
  }
  return p;
}

// Uniform BSplines
static Vertex InterpolateUBS(Curve *Curve, double u, int derivee)
{
  bool periodic = (Curve->end == Curve->beg);
  int NbControlPoints = List_Nbr(Curve->Control_Points);
  int NbCurves = NbControlPoints + (periodic ? -1 : 1);
  int iCurve = (int)floor(u * (double)NbCurves);
  if(iCurve == NbCurves) iCurve -= 1; // u = 1
  double t1 = (double)(iCurve) / (double)(NbCurves);
  double t2 = (double)(iCurve+1) / (double)(NbCurves);
  double t = (u - t1) / (t2 - t1);
  Vertex *v[4];
  for(int i = 0; i < 4; i++) {
    int k;
    if (periodic) {
      k = (iCurve - 1 + i) % (NbControlPoints - 1);
      if (k < 0)
        k += NbControlPoints - 1;
    }
    else {
      k = std::max(0, std::min(iCurve - 2 + i, NbControlPoints -1));
    }
    List_Read(Curve->Control_Points, k , &v[i]);
  }

  if(Curve->geometry){
    SPoint2 pp = InterpolateCubicSpline(v, t, Curve->mat, t1, t2, Curve->geometry,derivee);
    SPoint3 pt = Curve->geometry->point(pp);
    Vertex V;
    V.Pos.X = pt.x();
    V.Pos.Y = pt.y();
    V.Pos.Z = pt.z();
    return V;
  }
  else
    return InterpolateCubicSpline(v, t, Curve->mat, derivee, t1, t2);
}

// Non Uniform BSplines
int findSpan(double u, int deg, int n, float *U)
{
  if(u >= U[n])
    return n - 1;
  if(u <= U[0])
    return deg;

  int low = deg;
  int high = n + 1;
  int mid = (low + high) / 2;

  while(u < U[mid] || u >= U[mid + 1]) {
    if(u < U[mid])
      high = mid;
    else
      low = mid;
    mid = (low + high) / 2;
  }
  return mid;
}

static void basisFuns(double u, int i, int deg, float *U, double *N)
{
  double left[1000];
  double *right = &left[deg + 1];

  double temp, saved;

  N[0] = 1.0;
  for(int j = 1; j <= deg; j++) {
    left[j] = u - U[i + 1 - j];
    right[j] = U[i + j] - u;
    saved = 0.0;
    for(int r = 0; r < j; r++) {
      temp = N[r] / (right[r + 1] + left[j - r]);
      N[r] = saved + right[r + 1] * temp;
      saved = left[j - r] * temp;
    }
    N[j] = saved;
  }
}

static Vertex InterpolateNurbs(Curve *Curve, double u, int derivee)
{
  double Nb[1000];
  int span = findSpan(u, Curve->degre, List_Nbr(Curve->Control_Points), Curve->k);
  basisFuns(u, span, Curve->degre, Curve->k, Nb);
  Vertex p;
  p.Pos.X = p.Pos.Y = p.Pos.Z = p.w = p.lc = 0.0;
  for(int i = Curve->degre; i >= 0; --i) {
    Vertex *v;
    List_Read(Curve->Control_Points, span - Curve->degre + i, &v);
    p.Pos.X += Nb[i] * v->Pos.X;
    p.Pos.Y += Nb[i] * v->Pos.Y;
    p.Pos.Z += Nb[i] * v->Pos.Z;
    p.w += Nb[i] * v->w;
    p.lc += Nb[i] * v->lc;
  }
  return p;
}

Vertex InterpolateCurve(Curve *c, double u, int derivee)
{
  if(c->Num < 0) {
    Curve *C0 = FindCurve(-c->Num);
    if(!C0){
      Msg::Error("Unknown curve %d", -c->Num);
      return Vertex(0., 0., 0.);
    }
    return InterpolateCurve(C0, C0->ubeg + (C0->uend - C0->ubeg) * (1. - u), derivee);
  }

  Vertex V;

  if(derivee==1) {
    switch (c->Typ) {
      //    case MSH_SEGM_BSPLN:
      //    case MSH_SEGM_BEZIER:
      //      V = InterpolateUBS(c, u, 1);
      //      V.u = u;
      //      break;
    default :
      double eps1 = (u == 0) ? 0 : 1.e-5;
      double eps2 = (u == 1) ? 0 : 1.e-5;
      Vertex D[2];
      D[0] = InterpolateCurve(c, u - eps1, 0);
      D[1] = InterpolateCurve(c, u + eps2, 0);
      V.Pos.X = (D[1].Pos.X - D[0].Pos.X) / (eps1 + eps2);
      V.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / (eps1 + eps2);
      V.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / (eps1 + eps2);
      V.u = u;
      break;
    }
    return V;
  }

  if(derivee==2) {
    switch (c->Typ) {
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
      V = InterpolateUBS(c, u, 2);
      V.u = u;
      break;
    default :
      double eps1 = (u == 0) ? 0 : 1.e-5;
      double eps2 = (u == 1) ? 0 : 1.e-5;
      Vertex D[2];
      D[0] = InterpolateCurve(c, u - eps1, 1);
      D[1] = InterpolateCurve(c, u + eps2, 1);
      V.Pos.X = (D[1].Pos.X - D[0].Pos.X) / (eps1 + eps2);
      V.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / (eps1 + eps2);
      V.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / (eps1 + eps2);
      V.u = u;
      break;
    }
    return V;
  }

  int N, i;
  Vertex *v[5];
  double theta, t1, t2, t;
  Vertex temp1, temp2;

  switch (c->Typ) {

  case MSH_SEGM_LINE:
#if defined(HAVE_BFGS)
    //    printf("MSH_SEGM_LINE\n");
#endif
    N = List_Nbr(c->Control_Points);
    i = (int)((double)(N - 1) * u);
    while(i >= N - 1)
      i--;
    while(i < 0)
      i++;
    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);
    t = (u - t1) / (t2 - t1);
    List_Read(c->Control_Points, i, &v[1]);
    List_Read(c->Control_Points, i + 1, &v[2]);
    if(!c->geometry){
      V.Pos.X = v[1]->Pos.X + t * (v[2]->Pos.X - v[1]->Pos.X);
      V.Pos.Y = v[1]->Pos.Y + t * (v[2]->Pos.Y - v[1]->Pos.Y);
      V.Pos.Z = v[1]->Pos.Z + t * (v[2]->Pos.Z - v[1]->Pos.Z);
      V.w = (1. - t) * v[1]->w + t * v[2]->w;
      V.lc = (1. - t) * v[1]->lc + t * v[2]->lc;
    }
    else{
      SPoint2 p = v[1]->pntOnGeometry +  (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * t;
      SPoint3 pp = c->geometry->point(p);
      V.Pos.X = pp.x();
      V.Pos.Y = pp.y();
      V.Pos.Z = pp.z();
    }
    break;

  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    if(c->Typ == MSH_SEGM_CIRC_INV || c->Typ == MSH_SEGM_ELLI_INV) {
      V.u = 1. - u;
      u = V.u;
    }
    theta = c->Circle.t1 - (c->Circle.t1 - c->Circle.t2) * u;
    theta -= c->Circle.incl; // for ellipses
    V.Pos.X =
      c->Circle.f1 * cos(theta) * cos(c->Circle.incl) -
      c->Circle.f2 * sin(theta) * sin(c->Circle.incl);
    V.Pos.Y =
      c->Circle.f1 * cos(theta) * sin(c->Circle.incl) +
      c->Circle.f2 * sin(theta) * cos(c->Circle.incl);
    V.Pos.Z = 0.0;
    Projette(&V, c->Circle.invmat);
    List_Read(c->Control_Points, 1, &v[0]);
    V.Pos.X += v[0]->Pos.X;
    V.Pos.Y += v[0]->Pos.Y;
    V.Pos.Z += v[0]->Pos.Z;
    V.w = (1. - u) * c->beg->w + u * c->end->w;
    V.lc = (1. - u) * c->beg->lc + u * c->end->lc;
    break;

  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
    V = InterpolateUBS(c, u, 0);
    break;

  case MSH_SEGM_NURBS:
    V = InterpolateNurbs(c, u, 0);
    break;

  case MSH_SEGM_SPLN:
    N = List_Nbr(c->Control_Points);
    i = (int)((double)(N - 1) * u);
    if(i < 0)
      i = 0;
    if(i >= N - 1)
      i = N - 2;
    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);
    t = (u - t1) / (t2 - t1);
    List_Read(c->Control_Points, i, &v[1]);
    List_Read(c->Control_Points, i + 1, &v[2]);
    if(!i) {
      if(c->beg == c->end){
        List_Read(c->Control_Points, N - 2, &v[0]);
      }
      else{
        v[0] = &temp1;
        v[0]->Pos.X = 2. * v[1]->Pos.X - v[2]->Pos.X;
        v[0]->Pos.Y = 2. * v[1]->Pos.Y - v[2]->Pos.Y;
        v[0]->Pos.Z = 2. * v[1]->Pos.Z - v[2]->Pos.Z;
        v[0]->pntOnGeometry = v[1]->pntOnGeometry * 2. - v[2]->pntOnGeometry;
      }
    }
    else {
      List_Read(c->Control_Points, i - 1, &v[0]);
    }
    if(i == N - 2) {
      if(c->beg == c->end){
        List_Read(c->Control_Points, 1, &v[3]);
      }
      else{
        v[3] = &temp2;
        v[3]->Pos.X = 2. * v[2]->Pos.X - v[1]->Pos.X;
        v[3]->Pos.Y = 2. * v[2]->Pos.Y - v[1]->Pos.Y;
        v[3]->Pos.Z = 2. * v[2]->Pos.Z - v[1]->Pos.Z;
        v[3]->pntOnGeometry = v[2]->pntOnGeometry * 2. - v[1]->pntOnGeometry;
      }
    }
    else {
      List_Read(c->Control_Points, i + 2, &v[3]);
    }
    if(c->geometry){
      SPoint2 pp = InterpolateCubicSpline(v, t, c->mat, t1, t2,c->geometry,0);
      SPoint3 pt = c->geometry->point(pp);
      V.Pos.X = pt.x();
      V.Pos.Y = pt.y();
      V.Pos.Z = pt.z();
    }
    else
      V = InterpolateCubicSpline(v, t, c->mat, 0, t1, t2);
    break;

  case MSH_SEGM_BND_LAYER:
    Msg::Debug("Cannot interpolate boundary layer curve");
    break;

  case MSH_SEGM_DISCRETE:
    Msg::Debug("Cannot interpolate discrete curve");
    break;

  case MSH_SEGM_COMPOUND:
    Msg::Debug("Cannot interpolate compound curve");
    break;

  default:
    Msg::Error("Unknown curve type in interpolation");
    break;
  }
  V.u = u;
  return V;
}

// Transfinite interpolation on a quadrangle :
// f(u,v) = (1-u)c4(v) + u c2(v) + (1-v)c1(u) + v c3(u)
//          - [ (1-u)(1-v)s1 + u(1-v)s2 + uv s3 + (1-u)v s4 ]

#define TRAN_QUA(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
   (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)

static Vertex TransfiniteQua(Vertex c1, Vertex c2, Vertex c3, Vertex c4,
                             Vertex s1, Vertex s2, Vertex s3, Vertex s4,
                             double u, double v)
{
  Vertex V;

  V.lc = TRAN_QUA(c1.lc, c2.lc, c3.lc, c4.lc,
                  s1.lc, s2.lc, s3.lc, s4.lc, u, v);
  V.w = TRAN_QUA(c1.w, c2.w, c3.w, c4.w, s1.w, s2.w, s3.w, s4.w, u, v);
  V.Pos.X = TRAN_QUA(c1.Pos.X, c2.Pos.X, c3.Pos.X, c4.Pos.X,
                     s1.Pos.X, s2.Pos.X, s3.Pos.X, s4.Pos.X, u, v);
  V.Pos.Y = TRAN_QUA(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y, c4.Pos.Y,
                     s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, s4.Pos.Y, u, v);
  V.Pos.Z = TRAN_QUA(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z, c4.Pos.Z,
                     s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, s4.Pos.Z, u, v);
  return (V);
}

// Transfinite interpolation on a triangle :
//
//            s3(1,1)
//              +
//            / |
//      c3  /   |
//        /     |  c2
//      /       |
//    /   c1    |
//   +----------+
//  s1(0,0)     s2(1,0)

#if 0

// Old-style: TRAN_QUA with s1=s4=c4
//
// f(u,v) = u c2 (v) + (1-v) c1(u) + v c3(u) - u(1-v) s2 - uv s3
//
// u = v = 0     -----> x = c1(0) = s1 --> OK
// u = 1 ; v = 0 -----> x = c2(0) + c1(1) - s2 =  s2 --> OK
// u = 1 ; v = 1 -----> x = c2(1) + c3(1) - s3 =  s3 --> OK
// v = 0 --> u s2 + c1(u) - u s2 --> x = c1(u) --> OK
// u = 1 --> c2(v) + (1-v) s2 + v s3 -(1-v) s2  - v s3 --> x = c2(v) --> OK
// u = 0 --> (1-v) s1 + v s1 = s1 !!! not terrible (singular)

#define TRAN_TRI(c1,c2,c3,s1,s2,s3,u,v) u*c2+(1.-v)*c1+v*c3-(u*(1.-v)*s2+u*v*s3);

static Vertex TransfiniteTri(Vertex c1, Vertex c2, Vertex c3,
                             Vertex s1, Vertex s2, Vertex s3, double u, double v)
{
  Vertex V;
  V.lc = TRAN_TRI(c1.lc, c2.lc, c3.lc, s1.lc, s2.lc, s3.lc, u, v);
  V.w = TRAN_TRI(c1.w, c2.w, c3.w, s1.w, s2.w, s3.w, u, v);
  V.Pos.X = TRAN_TRI(c1.Pos.X, c2.Pos.X, c3.Pos.X,
                     s1.Pos.X, s2.Pos.X, s3.Pos.X, u, v);
  V.Pos.Y = TRAN_TRI(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y,
                     s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, u, v);
  V.Pos.Z = TRAN_TRI(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z,
                     s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, u, v);
  return V;
}

#endif

// New-style:
//
// f(u,v) = (1-u) (c1(u-v) + c3(1-v)     - s1) +
//          (u-v) (c2(v)   + c1(u)       - s2) +
//            v   (c3(1-u) + c2(1-u+v)   - s3)
//
// u = v = 0 --> f(0,0) = s1 + s1 - s1     = s1
// u = v = 1 --> f(1,1) = s3 + s3 - s3     = s3
// u = 1 ; v = 0 --> f(1,1) = s2 + s2 - s2 = s2
// v = 0 --> (1-u)c1(u) + u c1(u) = c1(u) --> COOL

#define TRAN_TRIB(c1,c1b,c2,c2b,c3,c3b,s1,s2,s3,u,v)\
      (1.-u)*(c1+c3b-s1)+(u-v)*(c2+c1b-s2)+v*(c3+c2b-s3);

static Vertex TransfiniteTriB(Vertex c1, Vertex c1b, Vertex c2,
			      Vertex c2b, Vertex c3, Vertex c3b,
			      Vertex s1, Vertex s2, Vertex s3,
			      double u, double v)
{
  Vertex V;
  V.lc = TRAN_TRIB(c1.lc,c1b.lc, c2.lc,c2b.lc, c3.lc, c3b.lc, s1.lc, s2.lc, s3.lc, u, v);
  V.w = TRAN_TRIB(c1.w, c1b.w, c2.w,c2b.w, c3.w,c3b.w, s1.w, s2.w, s3.w, u, v);
  V.Pos.X = TRAN_TRIB(c1.Pos.X, c1b.Pos.X,c2.Pos.X, c2b.Pos.X,c3.Pos.X,c3b.Pos.X,
                     s1.Pos.X, s2.Pos.X, s3.Pos.X, u, v);
  V.Pos.Y = TRAN_TRIB(c1.Pos.Y, c1b.Pos.Y,c2.Pos.Y, c2b.Pos.Y,c3.Pos.Y,c3b.Pos.Y,
                     s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, u, v);
  V.Pos.Z = TRAN_TRIB(c1.Pos.Z, c1b.Pos.Z,c2.Pos.Z, c2b.Pos.Z,c3.Pos.Z,c3b.Pos.Z,
                     s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, u, v);
  return V;
}

static void TransfiniteSph(Vertex S, Vertex center, Vertex *T)
{
  double r = sqrt(SQU(S.Pos.X - center.Pos.X) + SQU(S.Pos.Y - center.Pos.Y)
                  + SQU(S.Pos.Z - center.Pos.Z));

  double s = sqrt(SQU(T->Pos.X - center.Pos.X) + SQU(T->Pos.Y - center.Pos.Y)
                  + SQU(T->Pos.Z - center.Pos.Z));

  double dirx = (T->Pos.X - center.Pos.X) / s;
  double diry = (T->Pos.Y - center.Pos.Y) / s;
  double dirz = (T->Pos.Z - center.Pos.Z) / s;

  T->Pos.X = center.Pos.X + r * dirx;
  T->Pos.Y = center.Pos.Y + r * diry;
  T->Pos.Z = center.Pos.Z + r * dirz;
}

bool iSRuledSurfaceASphere(Surface *s, SPoint3 &center, double &radius)
{
  if(s->Typ != MSH_SURF_REGL && s->Typ != MSH_SURF_TRIC) return false;

  bool isSphere = true;
  Vertex *O = 0;
  Curve *C[4] = {0, 0, 0, 0};
  for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++)
    List_Read(s->Generatrices, i, &C[i]);

  if(List_Nbr(s->InSphereCenter)) {
    // it's on a sphere: get the center
    List_Read(s->InSphereCenter, 0, &O);
  }
  else{
    // try to be intelligent (hum)
    for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++) {
      if(C[i]->Typ != MSH_SEGM_CIRC && C[i]->Typ != MSH_SEGM_CIRC_INV){
        isSphere = false;
      }
      else if(isSphere){
        if(!i){
          List_Read(C[i]->Control_Points, 1, &O);
          ((double *)center)[0] = O->Pos.X;
          ((double *)center)[1] = O->Pos.Y;
          ((double *)center)[2] = O->Pos.Z;
        }
        else{
          Vertex *tmp;
          List_Read(C[i]->Control_Points, 1, &tmp);
          if(compareVertex(&O, &tmp))
            isSphere = false;
        }
      }
    }
  }
  if (isSphere && C[0]){
    Vertex *p = C[0]->beg;
    radius = sqrt ((p->Pos.X - center.x())+
                   (p->Pos.Y - center.y())+
                   (p->Pos.Z - center.z()));
  }

  return isSphere;
}

static Vertex InterpolateRuledSurface(Surface *s, double u, double v)
{
  Curve *C[4] = {0, 0, 0, 0};

  for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++)
    List_Read(s->Generatrices, i, &C[i]);

  Vertex *O = 0;
  bool isSphere = true;

  // Ugly hack: "fix" transfinite interpolation if we have a sphere
  // patch
  if(List_Nbr(s->InSphereCenter)) {
    // it's on a sphere: get the center
    List_Read(s->InSphereCenter, 0, &O);
  }
  else{
    // try to be intelligent (hum)
    for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++) {
      if(C[i]->Typ != MSH_SEGM_CIRC && C[i]->Typ != MSH_SEGM_CIRC_INV){
        isSphere = false;
      }
      else if(isSphere){
        if(!i){
          List_Read(C[i]->Control_Points, 1, &O);
        }
        else{
          Vertex *tmp;
          List_Read(C[i]->Control_Points, 1, &tmp);
          if(compareVertex(&O, &tmp))
            isSphere = false;
        }
      }
    }
    if(isSphere){
      double n[3] = {C[0]->Circle.invmat[0][2],
                     C[0]->Circle.invmat[1][2],
                     C[0]->Circle.invmat[2][2]};
      bool isPlane = true;
      for(int i = 1; i < std::min(List_Nbr(s->Generatrices), 4); i++)
        isPlane &= (n[0] == C[i]->Circle.invmat[0][2] &&
                    n[1] == C[i]->Circle.invmat[1][2] &&
                    n[2] == C[i]->Circle.invmat[2][2]);
      if(isPlane)
        isSphere = false;
    }
  }

  Vertex *S[4], V[4],VB[3], T;
  if(s->Typ == MSH_SURF_REGL && List_Nbr(s->Generatrices) >= 4){
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    S[3] = C[3]->beg;
    V[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    V[3] = InterpolateCurve(C[3], C[3]->ubeg + (C[3]->uend - C[3]->ubeg) * (1. - v), 0);
    /*
#if defined(HAVE_BFGS)
    printf("----- u %f v %f %g %g\n", u, v,C[1]->ubeg,C[1]->uend);
    printf("S[0] %f %f %f\n", S[0]->Pos.X, S[0]->Pos.Y,S[0]->Pos.Z);
    printf("S[1] %f %f %f\n", S[1]->Pos.X, S[1]->Pos.Y,S[1]->Pos.Z);
    printf("S[2] %f %f %f\n", S[2]->Pos.X, S[2]->Pos.Y,S[2]->Pos.Z);
    printf("S[3] %f %f %f\n", S[3]->Pos.X, S[3]->Pos.Y,S[3]->Pos.Z);
    printf("V[0] %f %f %f\n", V[0].Pos.X, V[0].Pos.Y,V[0].Pos.Z);
    printf("V[1] %f %f %f\n", V[1].Pos.X, V[1].Pos.Y,V[1].Pos.Z);
    printf("V[2] %f %f %f\n", V[2].Pos.X, V[2].Pos.Y,V[2].Pos.Z);
    printf("V[3] %f %f %f\n", V[3].Pos.X, V[3].Pos.Y,V[3].Pos.Z);
#endif
    */
    T = TransfiniteQua(V[0], V[1], V[2], V[3], *S[0], *S[1], *S[2], *S[3], u, v);
    if(isSphere) TransfiniteSph(*S[0], *O, &T);
  }
  else if(List_Nbr(s->Generatrices) >= 3){
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    /*
    V[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    T = TransfiniteTri(V[0], V[1], V[2], *S[0], *S[1], *S[2], u, v);
    */
    V[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * (u-v), 0);
    V[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    VB[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    VB[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * (1-u+v), 0);
    VB[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - v), 0);
    T = TransfiniteTriB(V[0],VB[0], V[1],VB[1], V[2],VB[2], *S[0], *S[1], *S[2], u, v);

    if(isSphere) {
      TransfiniteSph(*S[0], *O, &T);
    }
  }

  return T;
}

static Vertex InterpolateExtrudedSurface(Surface *s, double u, double v)
{
  Curve *c = FindCurve(s->Extrude->geo.Source);

  // find position of c in the list of generatrices
  int num = -1;
  for(int i = 0; i < List_Nbr(s->Generatrices); i++){
    if(c == *(Curve**)List_Pointer(s->Generatrices, i)){
      num = i;
      break;
    }
  }

  Vertex T;

  if(num < 0){
    Msg::Error("Unknown curve in extruded surface");
    return T;
  }

  switch(num){
  case 0:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * u, 0);
    s->Extrude->Extrude(v, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  case 1:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * v, 0);
    s->Extrude->Extrude(1. - u, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  case 2:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * (1. - u), 0);
    s->Extrude->Extrude(1. - v, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  default:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * (1. - v), 0);
    s->Extrude->Extrude(u, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  }
}

Vertex InterpolateSurface(Surface *s, double u, double v, int derivee, int u_v)
{
  if(derivee == 1) {
    double eps = 1.e-8;
    Vertex D[4];
    if(u_v == 1) {
      if(u - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u + eps, v, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u - eps, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    else {
      if(v - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v + eps, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - eps, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    return Vertex((D[1].Pos.X - D[0].Pos.X) / eps,
                  (D[1].Pos.Y - D[0].Pos.Y) / eps,
                  (D[1].Pos.Z - D[0].Pos.Z) / eps);
  }
  else if (derivee == 2) {
    double eps = 1.e-6;
    Vertex D[2];
    if(u_v == 1) { // dudu
      if(u - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 1);
        D[1] = InterpolateSurface(s, u + eps, v, 1, 1);
      }
      else {
        D[0] = InterpolateSurface(s, u - eps, v, 1, 1);
        D[1] = InterpolateSurface(s, u, v, 1, 1);
      }
    }
    else if(u_v == 2) { // dvdv
      if(v - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 2);
        D[1] = InterpolateSurface(s, u, v + eps, 1, 2);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - eps, 1, 2);
        D[1] = InterpolateSurface(s, u, v, 1, 2);
      }
    }
    else { // dudv
      if(v - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 1);
        D[1] = InterpolateSurface(s, u, v + eps, 1, 1);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - eps, 1, 1);
        D[1] = InterpolateSurface(s, u, v, 1, 1);
      }
    }
    return Vertex((D[1].Pos.X - D[0].Pos.X) / eps,
                  (D[1].Pos.Y - D[0].Pos.Y) / eps,
                  (D[1].Pos.Z - D[0].Pos.Z) / eps);
  }

  if(s->geometry){
    SPoint3 p = s->geometry->point(u, v);
    return Vertex(p.x(), p.y(), p.z());
  }

  // Warning: we use the exact extrusion formula so we can create
  // exact surfaces of revolution. This WILL fail if the surface is
  // transformed after the extrusion: in that case set the
  // exactExtrusion option to 0 to use the normal code path
  if(CTX::instance()->geom.exactExtrusion && s->Extrude &&
     s->Extrude->geo.Mode == EXTRUDED_ENTITY && s->Typ != MSH_SURF_PLAN)
    return InterpolateExtrudedSurface(s, u, v);

  switch (s->Typ) {
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC:
    return InterpolateRuledSurface(s, u, v);
  case MSH_SURF_PLAN:
    Msg::Error("Should never interpolate plane surface in InterpolateSurface()");
    return Vertex(0., 0., 0.);
  case MSH_SURF_BND_LAYER:
    Msg::Error("Cannot interpolate boundary layer surface");
    return Vertex(0., 0., 0.);
  case MSH_SURF_DISCRETE:
    Msg::Error("Cannot interpolate discrete surface");
    return Vertex(0., 0., 0.);
  default:
    Msg::Error("Unknown surface type in interpolation");
    return Vertex(0., 0., 0.);
  }
}
