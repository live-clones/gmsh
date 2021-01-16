// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Numeric.h"
#include "Context.h"

static double const fd_eps = 1.0e-8;

static void InterpolateCatmullRom(Vertex *v[4], double t, Vertex &V)
{
  V.lc = (1 - t) * v[1]->lc + t * v[2]->lc;
  V.w = (1 - t) * v[1]->w + t * v[2]->w;
  const double t2 = t * t;
  const double t3 = t * t * t;
  const double s[4] = {-.5 * t3 + t2 - .5 * t, 1.5 * t3 - 2.5 * t2 + 1,
                       -1.5 * t3 + 2 * t2 + .5 * t, 0.5 * t3 - 0.5 * t2};
  V.Pos.X = s[0] * v[0]->Pos.X + s[1] * v[1]->Pos.X + s[2] * v[2]->Pos.X +
            s[3] * v[3]->Pos.X;
  V.Pos.Y = s[0] * v[0]->Pos.Y + s[1] * v[1]->Pos.Y + s[2] * v[2]->Pos.Y +
            s[3] * v[3]->Pos.Y;
  V.Pos.Z = s[0] * v[0]->Pos.Z + s[1] * v[1]->Pos.Z + s[2] * v[2]->Pos.Z +
            s[3] * v[3]->Pos.Z;
}

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

  for(i = 0; i < 4; i++) { vec[i] = 0.0; }

  // X
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) { vec[i] += mat[i][j] * v[j]->Pos.X; }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.X += T[j] * vec[j];
    vec[j] = 0.0;
  }

  // Y
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) { vec[i] += mat[i][j] * v[j]->Pos.Y; }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.Y += T[j] * vec[j];
    vec[j] = 0.0;
  }

  // Z
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) { vec[i] += mat[i][j] * v[j]->Pos.Z; }
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
    V.Pos.X /= ((t2 - t1) * (t2 - t1));
    V.Pos.Y /= ((t2 - t1) * (t2 - t1));
    V.Pos.Z /= ((t2 - t1) * (t2 - t1));
  }

  return V;
}

// interpolation in the parametric space
SPoint2 InterpolateCubicSpline(Vertex *v[4], double t, double mat[4][4],
                               double t1, double t2, gmshSurface *s,
                               int derivee)
{
  Vertex V;
  int i, j;
  double T[4] = {0., 0., 0., 0.};

  if(derivee == 0) {
    T[3] = 1.;
    T[2] = t;
    T[1] = t * t;
    T[0] = t * t * t;
  }
  else if(derivee == 1) {
    T[3] = 0.;
    T[2] = 1;
    T[1] = 2 * t;
    T[0] = 3 * t * t;
  }
  else if(derivee == 2) {
    T[3] = 0.;
    T[2] = 0;
    T[1] = 2;
    T[0] = 6 * t;
  }

  SPoint2 coord[4], p;

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) { coord[i] += v[j]->pntOnGeometry * mat[i][j]; }
  }

  for(j = 0; j < 4; j++) { p += coord[j] * T[j]; }
  return p;
}

static Vertex InterpolateBezier(Curve *Curve, double u, int derivee)
{
  int NbControls = List_Nbr(Curve->Control_Points);
  if(NbControls - derivee <= 0) return Vertex(0, 0, 0);

  List_T *controls = List_Create(NbControls, 1, sizeof(Coord));

  if(Curve->geometry) {
    for(int i = 0; i < NbControls; ++i) {
      Vertex *v;
      List_Read(Curve->Control_Points, i, &v);
      Coord c = {v->pntOnGeometry.x(), v->pntOnGeometry.y(), 0};
      List_Add(controls, &c);
    }
  }
  else {
    for(int i = 0; i < NbControls; ++i) {
      Vertex *v;
      List_Read(Curve->Control_Points, i, &v);
      List_Add(controls, &v->Pos);
    }
  }

  // Compute derivative:
  while(derivee > 0) {
    NbControls--;
    derivee--;
    for(int i = 0; i < NbControls; ++i) {
      Coord c1;
      Coord c2;
      List_Read(controls, i, &c1);
      List_Read(controls, i + 1, &c2);
      c2.X -= c1.X;
      c2.Y -= c1.Y;
      c2.Z -= c1.Z;
      List_Write(controls, i, &c2);
    }
  }

  // De Casteljau's algorithm:
  while(NbControls > 1) {
    NbControls--;
    for(int i = 0; i < NbControls; ++i) {
      Coord c1;
      Coord c2;
      List_Read(controls, i, &c1);
      List_Read(controls, i + 1, &c2);
      c2.X = (1 - u) * c1.X + u * c2.X;
      c2.Y = (1 - u) * c1.Y + u * c2.Y;
      c2.Z = (1 - u) * c1.Z + u * c2.Z;
      List_Write(controls, i, &c2);
    }
  }

  Coord c;
  List_Read(controls, 0, &c);
  List_Delete(controls);

  if(Curve->geometry) {
    SPoint2 pp(c.X, c.Y);
    SPoint3 pt = Curve->geometry->point(pp);
    Vertex V;
    V.Pos.X = pt.x();
    V.Pos.Y = pt.y();
    V.Pos.Z = pt.z();
    return V;
  }
  else {
    Vertex V;
    V.Pos.X = c.X;
    V.Pos.Y = c.Y;
    V.Pos.Z = c.Z;
    return V;
  }
}

// Uniform BSplines
static Vertex InterpolateUBS(Curve *Curve, double u, int derivee)
{
#if 1 // bypass regression in Gmsh 4 for bsplines on geometry (see #685)
  if(Curve->geometry) {
    bool periodic = (Curve->end == Curve->beg);
    int NbControlPoints = List_Nbr(Curve->Control_Points);
    int NbCurves = NbControlPoints + (periodic ? -1 : 1);
    int iCurve = (int)floor(u * (double)NbCurves);
    if(iCurve == NbCurves) iCurve -= 1; // u = 1
    double t1 = (double)(iCurve) / (double)(NbCurves);
    double t2 = (double)(iCurve + 1) / (double)(NbCurves);
    double t = (u - t1) / (t2 - t1);
    Vertex *v[4];
    for(int i = 0; i < 4; i++) {
      int k;
      if(periodic) {
        k = (iCurve - 1 + i) % (NbControlPoints - 1);
        if(k < 0) k += NbControlPoints - 1;
      }
      else {
        k = std::max(0, std::min(iCurve - 2 + i, NbControlPoints - 1));
      }
      List_Read(Curve->Control_Points, k, &v[i]);
    }
    SPoint2 pp = InterpolateCubicSpline(v, t, Curve->mat, t1, t2,
                                        Curve->geometry, derivee);
    SPoint3 pt = Curve->geometry->point(pp);
    Vertex V;
    V.Pos.X = pt.x();
    V.Pos.Y = pt.y();
    V.Pos.Z = pt.z();
    return V;
  }
#endif

  // Mat for 2 control points (=> linear)
  static double mat2[4][4] = {
    {0, 0, 0, 0}, {0, 0, 0, 0}, {-1, 1, 0, 0}, {1, 0, 0, 0}};
  // Mat for 3 control points (=> quadratic, Bézier)
  static double mat3[4][4] = {
    {0, 0, 0, 0}, {1, -2, 1, 0}, {-2, 2, 0, 0}, {1, 0, 0, 0}};
  // Mat for 4 control points (=> cubic, Bézier)
  static double mat4[4][4] = {{-1, 3, -3, 1}, // t^3
                              {3, -6, 3, 0}, // t^2
                              {-3, 3, 0, 0}, // t^1
                              {1, 0, 0, 0}}; // t^0
  // n0  n1  n2  n3
  // Mat for 5 control points (left extremity, other obtained by symmetry)
  static double mat5[4][4] = {
    {-1, 7. / 4, -1, 1. / 4}, {3, -4.5, 1.5, 0}, {-3, 3, 0, 0}, {1, 0, 0, 0}};
  // Mat for 6 control points (left extremity + middle, right obtained by
  // symmetry)
  static double mat6_1[4][4] = {{-1, 7. / 4, -11. / 12, 2. / 12},
                                {3, -4.5, 1.5, 0},
                                {-3, 3, 0, 0},
                                {1, 0, 0, 0}};
  static double mat6_2[4][4] = {{-1. / 4, 7. / 12, -7. / 12, 1. / 4},
                                {3. / 4, -5. / 4, 1. / 2, 0},
                                {-3. / 4, 1. / 4, 1. / 2, 0},
                                {1. / 4, 7. / 12, 1. / 6, 0}};
  // Mat for 7+ control points
  static double matext_1[4][4] = {{-1, 7. / 4, -11. / 12, 1. / 6},
                                  {3, -4.5, 1.5, 0},
                                  {-3, 3, 0, 0},
                                  {1, 0, 0, 0}};
  static double mat7_2[4][4] = {{-1. / 4, 7. / 12, -1. / 2, 1. / 6},
                                {3. / 4, -5. / 4, 1. / 2, 0},
                                {-3. / 4, 1. / 4, 1. / 2, 0},
                                {1. / 4, 7. / 12, 1. / 6, 0}};
  static double matext_2[4][4] = {{-1. / 4, 7. / 12, -.5, 1. / 6},
                                  {3. / 4, -5. / 4, .5, 0},
                                  {-3. / 4, 1. / 4, .5, 0},
                                  {1. / 4, 7. / 12, 1. / 6, 0}};

  bool periodic = (Curve->end == Curve->beg);

  int NbControlPoints = List_Nbr(Curve->Control_Points);
  int NbCurves = NbControlPoints + (periodic ? -1 : -3);

  NbCurves = std::max(NbCurves, 1);

  int iCurve = static_cast<int>(std::floor(u * static_cast<double>(NbCurves)));
  if(iCurve == NbCurves) iCurve -= 1; // u = 1

  double t1 = static_cast<double>(iCurve) / static_cast<double>(NbCurves);
  double t2 = static_cast<double>(iCurve + 1) / static_cast<double>(NbCurves);
  double t = (u - t1) / (t2 - t1);

  Vertex *v[4];
  for(int i = 0; i < 4; i++) {
    int k;
    if(periodic) {
      k = (iCurve - 1 + i) % (NbControlPoints - 1);
      if(k < 0) k += NbControlPoints - 1;
    }
    else {
      k = std::min(iCurve + i, NbControlPoints - 1);
    }

    if(k >= 0 && k < NbControlPoints) {
      List_Read(Curve->Control_Points, k, &v[i]);
    }
    else {
      Msg::Warning("Wrong control point index in bspline");
      Vertex V;
      return V;
    }
  }

  double(*matrix)[4][4] = &Curve->mat;
  if(!periodic) {
    // Inverse if right extremity
    if((NbControlPoints > 6 && iCurve >= NbCurves - 2) ||
       (NbControlPoints > 4 && iCurve == NbCurves - 1)) {
      Vertex *v_tmp = v[0];
      v[0] = v[3];
      v[3] = v_tmp;
      v_tmp = v[1];
      v[1] = v[2];
      v[2] = v_tmp;
      t = 1 - t;
      double t_tmp = t1;
      t1 = t2;
      t2 = t_tmp;
      iCurve = NbCurves - 1 - iCurve;
    }
    if(iCurve == 0) {
      switch(NbControlPoints) {
      case 2: matrix = &mat2; break;
      case 3: matrix = &mat3; break;
      case 4: matrix = &mat4; break;
      case 5: matrix = &mat5; break;
      case 6: matrix = &mat6_1; break;
      default: matrix = &matext_1; break;
      }
    }
    else if(iCurve == 1) {
      switch(NbControlPoints) {
      case 6: matrix = &mat6_2; break;
      case 7: matrix = &mat7_2; break;
      default: matrix = &matext_2; break;
      }
    }
  }

#if 0 // bypass regression in Gmsh 4 for bsplines on geometry (see #685)
  if(Curve->geometry) {
    SPoint2 pp =
      InterpolateCubicSpline(v, t, *matrix, t1, t2, Curve->geometry, derivee);
    SPoint3 pt = Curve->geometry->point(pp);
    Vertex V;
    V.Pos.X = pt.x();
    V.Pos.Y = pt.y();
    V.Pos.Z = pt.z();
    return V;
  }
#endif
  return InterpolateCubicSpline(v, t, *matrix, derivee, t1, t2);
}

// Non Uniform BSplines
int findSpan(double u, int deg, int n, float *U)
{
  if(u >= U[n]) return n - 1;
  if(u <= U[0]) return deg;

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
  int span =
    findSpan(u, Curve->degre, List_Nbr(Curve->Control_Points), Curve->k);
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

Vertex InterpolateCurve(Curve *c, double u, int const derivee)
{
  if(c->Num < 0) {
    Curve *C0 = FindCurve(-c->Num);
    if(!C0) {
      Msg::Error("Unknown curve %d", -c->Num);
      return Vertex(0., 0., 0.);
    }
    return InterpolateCurve(C0, C0->ubeg + (C0->uend - C0->ubeg) * (1.0 - u),
                            derivee);
  }

  const double eps = (c->Typ == MSH_SEGM_LINE) ? 1e-5 : fd_eps;

  Vertex V;

  if(derivee == 1) {
    switch(c->Typ) {
      /*
    case MSH_SEGM_BSPLN:
      V = InterpolateUBS(c, u, 1);
      V.u = u;
      break;
      */
    case MSH_SEGM_BEZIER:
      V = InterpolateBezier(c, u, 1);
      V.u = u;
      break;
    default:
      const double eps1 = (u < eps) ? 0.0 : eps;
      const double eps2 = (u > 1 - eps) ? 0.0 : eps;
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

  if(derivee == 2) {
    switch(c->Typ) {
      /*
    case MSH_SEGM_BSPLN:
      V = InterpolateUBS(c, u, 2);
      V.u = u;
      break;
      */
    case MSH_SEGM_BEZIER:
      V = InterpolateBezier(c, u, 2);
      V.u = u;
      break;
    default:
      double const eps1 = (u < eps) ? 0.0 : eps;
      double const eps2 = (u > 1 - eps) ? 0.0 : eps;
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

  Vertex *v[5];
  double theta, t1, t2, t;
  Vertex temp1, temp2;

  switch(c->Typ) {
  case MSH_SEGM_LINE: {
    int N = List_Nbr(c->Control_Points);

    if(N < 2) {
      Msg::Error("Line with less than 2 control points");
      V.Pos.X = V.Pos.Y = V.Pos.Z = 0;
    }
    else {
      int i = static_cast<int>(static_cast<double>(N - 1) * u);
      // clamp
      if(i >= N - 1) i = N - 2;
      if(i < 0) i = 0;

      t1 = static_cast<double>(i) / static_cast<double>(N - 1);
      t2 = static_cast<double>(i + 1) / static_cast<double>(N - 1);
      t = (u - t1) / (t2 - t1);

      List_Read(c->Control_Points, i, &v[1]);
      List_Read(c->Control_Points, i + 1, &v[2]);

      if(!c->geometry) {
        V.Pos.X = v[1]->Pos.X + t * (v[2]->Pos.X - v[1]->Pos.X);
        V.Pos.Y = v[1]->Pos.Y + t * (v[2]->Pos.Y - v[1]->Pos.Y);
        V.Pos.Z = v[1]->Pos.Z + t * (v[2]->Pos.Z - v[1]->Pos.Z);
        V.w = (1. - t) * v[1]->w + t * v[2]->w;
        V.lc = (1. - t) * v[1]->lc + t * v[2]->lc;
      }
      else {
        SPoint2 p =
          v[1]->pntOnGeometry + (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * t;
        SPoint3 pp = c->geometry->point(p);
        V.Pos.X = pp.x();
        V.Pos.Y = pp.y();
        V.Pos.Z = pp.z();
      }
    }
    break;
  }

  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: {
    int N = List_Nbr(c->Control_Points);
    if(N < 2) {
      Msg::Error("Circle or ellipse with less than 2 control points");
      V.Pos.X = V.Pos.Y = V.Pos.Z = 0;
    }
    else {
      if(c->Typ == MSH_SEGM_CIRC_INV || c->Typ == MSH_SEGM_ELLI_INV) {
        V.u = 1. - u;
        u = V.u;
      }
      theta = c->Circle.t1 - (c->Circle.t1 - c->Circle.t2) * u;
      theta -= c->Circle.incl; // for ellipses

      V.Pos.X = c->Circle.f1 * std::cos(theta) * std::cos(c->Circle.incl) -
                c->Circle.f2 * std::sin(theta) * std::sin(c->Circle.incl);
      V.Pos.Y = c->Circle.f1 * std::cos(theta) * std::sin(c->Circle.incl) +
                c->Circle.f2 * std::sin(theta) * std::cos(c->Circle.incl);
      V.Pos.Z = 0.0;

      Projette(&V, c->Circle.invmat);
      List_Read(c->Control_Points, 1, &v[0]);

      V.Pos.X += v[0]->Pos.X;
      V.Pos.Y += v[0]->Pos.Y;
      V.Pos.Z += v[0]->Pos.Z;

      V.w = (1. - u) * c->beg->w + u * c->end->w;
      V.lc = (1. - u) * c->beg->lc + u * c->end->lc;
    }
    break;
  }

  case MSH_SEGM_BSPLN: V = InterpolateUBS(c, u, 0); break;

  case MSH_SEGM_BEZIER: V = InterpolateBezier(c, u, 0); break;

  case MSH_SEGM_NURBS: V = InterpolateNurbs(c, u, 0); break;

  case MSH_SEGM_SPLN: {
    int N = List_Nbr(c->Control_Points);
    if(N < 2) {
      Msg::Error("Spline with less than 2 control points");
      V.Pos.X = V.Pos.Y = V.Pos.Z = 0;
    }
    else {
      int i = static_cast<double>(N - 1) * u;

      // clamp
      if(i < 0) i = 0;
      if(i >= N - 1) i = N - 2;

      t1 = static_cast<double>(i) / static_cast<double>(N - 1);
      t2 = static_cast<double>(i + 1) / static_cast<double>(N - 1);
      t = (u - t1) / (t2 - t1);

      List_Read(c->Control_Points, i, &v[1]);
      List_Read(c->Control_Points, i + 1, &v[2]);
      if(!i) {
        if(c->beg == c->end) { List_Read(c->Control_Points, N - 2, &v[0]); }
        else {
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
        if(c->beg == c->end) { List_Read(c->Control_Points, 1, &v[3]); }
        else {
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
      if(c->geometry) {
        SPoint2 pp =
          InterpolateCubicSpline(v, t, c->mat, t1, t2, c->geometry, 0);
        SPoint3 pt = c->geometry->point(pp);
        V.Pos.X = pt.x();
        V.Pos.Y = pt.y();
        V.Pos.Z = pt.z();
      }
      else {
        InterpolateCatmullRom(v, t, V);
        // V = InterpolateCubicSpline(v, t, c->mat, 0, t1, t2);
      }
    }
    break;
  }

  case MSH_SEGM_BND_LAYER:
    Msg::Debug("Cannot interpolate boundary layer curve");
    break;

  case MSH_SEGM_DISCRETE:
    Msg::Debug("Cannot interpolate discrete curve");
    break;

  default: Msg::Error("Unknown curve type %d in interpolation", c->Typ); break;
  }
  V.u = u;
  return V;
}

// Transfinite interpolation on a quadrangle :
// f(u,v) = (1-u)c4(v) + u c2(v) + (1-v)c1(u) + v c3(u)
//          - [ (1-u)(1-v)s1 + u(1-v)s2 + uv s3 + (1-u)v s4 ]

template <class T>
T TRAN_QUA(T const c1, T const c2, T const c3, T const c4, T const s1,
           T const s2, T const s3, T const s4, T const u, T const v)
{
  return (1.0 - u) * c4 + u * c2 + (1.0 - v) * c1 + v * c3 -
         ((1.0 - u) * (1.0 - v) * s1 + u * (1.0 - v) * s2 + u * v * s3 +
          (1.0 - u) * v * s4);
}

static Vertex TransfiniteQua(Vertex c1, Vertex c2, Vertex c3, Vertex c4,
                             Vertex s1, Vertex s2, Vertex s3, Vertex s4,
                             double u, double v)
{
  Vertex V;

  V.lc = TRAN_QUA(c1.lc, c2.lc, c3.lc, c4.lc, s1.lc, s2.lc, s3.lc, s4.lc, u, v);
  V.w = TRAN_QUA(c1.w, c2.w, c3.w, c4.w, s1.w, s2.w, s3.w, s4.w, u, v);
  V.Pos.X = TRAN_QUA(c1.Pos.X, c2.Pos.X, c3.Pos.X, c4.Pos.X, s1.Pos.X, s2.Pos.X,
                     s3.Pos.X, s4.Pos.X, u, v);
  V.Pos.Y = TRAN_QUA(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y, c4.Pos.Y, s1.Pos.Y, s2.Pos.Y,
                     s3.Pos.Y, s4.Pos.Y, u, v);
  V.Pos.Z = TRAN_QUA(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z, c4.Pos.Z, s1.Pos.Z, s2.Pos.Z,
                     s3.Pos.Z, s4.Pos.Z, u, v);
  return V;
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

template <class T>
T TRAN_TRI(T const c1, T const c2, T const c3, T const s1, T const s2,
           T const s3, T const u, T const v)
{
  return u * c2 + (1.0 - v) * c1 + v * c3 - (u * (1.0 - v) * s2 + u * v * s3);
}

static Vertex TransfiniteTri(Vertex c1, Vertex c2, Vertex c3, const Vertex &s1,
                             Vertex s2, Vertex s3, double u, double v)
{
  Vertex V;
  V.lc = TRAN_TRI(c1.lc, c2.lc, c3.lc, s1.lc, s2.lc, s3.lc, u, v);
  V.w = TRAN_TRI(c1.w, c2.w, c3.w, s1.w, s2.w, s3.w, u, v);
  V.Pos.X =
    TRAN_TRI(c1.Pos.X, c2.Pos.X, c3.Pos.X, s1.Pos.X, s2.Pos.X, s3.Pos.X, u, v);
  V.Pos.Y =
    TRAN_TRI(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y, s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, u, v);
  V.Pos.Z =
    TRAN_TRI(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z, s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, u, v);
  return V;
}

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

// FIXME: but what happens when v > u ? You interpolate the curves outside
// ubeg/uend... Argh.

template <class T>
T TRAN_TRIB(T const c1, T const c1b, T const c2, T const c2b, T const c3,
            T const c3b, T const s1, T const s2, T const s3, T const u,
            T const v)
{
  return (1.0 - u) * (c1 + c3b - s1) + (u - v) * (c2 + c1b - s2) +
         v * (c3 + c2b - s3);
}

static Vertex TransfiniteTriB(Vertex c1, Vertex c1b, Vertex c2, Vertex c2b,
                              Vertex c3, Vertex c3b, Vertex s1, Vertex s2,
                              Vertex s3, double u, double v)
{
  Vertex V;
  V.lc = TRAN_TRIB(c1.lc, c1b.lc, c2.lc, c2b.lc, c3.lc, c3b.lc, s1.lc, s2.lc,
                   s3.lc, u, v);
  V.w =
    TRAN_TRIB(c1.w, c1b.w, c2.w, c2b.w, c3.w, c3b.w, s1.w, s2.w, s3.w, u, v);
  V.Pos.X = TRAN_TRIB(c1.Pos.X, c1b.Pos.X, c2.Pos.X, c2b.Pos.X, c3.Pos.X,
                      c3b.Pos.X, s1.Pos.X, s2.Pos.X, s3.Pos.X, u, v);
  V.Pos.Y = TRAN_TRIB(c1.Pos.Y, c1b.Pos.Y, c2.Pos.Y, c2b.Pos.Y, c3.Pos.Y,
                      c3b.Pos.Y, s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, u, v);
  V.Pos.Z = TRAN_TRIB(c1.Pos.Z, c1b.Pos.Z, c2.Pos.Z, c2b.Pos.Z, c3.Pos.Z,
                      c3b.Pos.Z, s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, u, v);
  return V;
}

static void TransfiniteSph(Vertex S, Vertex center, Vertex *T)
{
  double r = std::sqrt(std::pow(S.Pos.X - center.Pos.X, 2) +
                       std::pow(S.Pos.Y - center.Pos.Y, 2) +
                       std::pow(S.Pos.Z - center.Pos.Z, 2));
  double s = std::sqrt(std::pow(T->Pos.X - center.Pos.X, 2) +
                       std::pow(T->Pos.Y - center.Pos.Y, 2) +
                       std::pow(T->Pos.Z - center.Pos.Z, 2));

  double const dirx = (T->Pos.X - center.Pos.X) / s;
  double const diry = (T->Pos.Y - center.Pos.Y) / s;
  double const dirz = (T->Pos.Z - center.Pos.Z) / s;

  T->Pos.X = center.Pos.X + r * dirx;
  T->Pos.Y = center.Pos.Y + r * diry;
  T->Pos.Z = center.Pos.Z + r * dirz;
}

static Vertex InterpolateRuledSurface(Surface *s, double u, double v)
{
  Curve *C[4] = {nullptr, nullptr, nullptr, nullptr};

  if(!List_Nbr(s->Generatrices)) {
    Msg::Error("No curves on boundary of ruled surface");
    return Vertex(0., 0., 0.);
  }

  for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++) {
    List_Read(s->Generatrices, i, &C[i]);
    if(C[i]->Typ == MSH_SEGM_BND_LAYER || C[i]->Typ == MSH_SEGM_DISCRETE) {
      Msg::Error(
        "Cannot interpolate ruled surface with discrete bounding curves");
      return Vertex(0., 0., 0.);
    }
    if(!C[i]->beg || !C[i]->end) {
      Msg::Error("Cannot interpolate ruled surface if bounding curves don't "
                 "have end points");
      return Vertex(0., 0., 0.);
    }
  }

  Vertex *O = nullptr;
  bool isSphere = true;

  // Ugly hack: "fix" transfinite interpolation if we have a sphere
  // patch
  if(s->InSphereCenter) {
    // it's on a sphere: get the center
    O = s->InSphereCenter;
  }
  else {
    // try to be intelligent (hum)
    for(int i = 0; i < std::min(List_Nbr(s->Generatrices), 4); i++) {
      if(C[i]->Typ != MSH_SEGM_CIRC && C[i]->Typ != MSH_SEGM_CIRC_INV) {
        isSphere = false;
      }
      else if(isSphere) {
        if(!i) { List_Read(C[i]->Control_Points, 1, &O); }
        else {
          Vertex *tmp;
          List_Read(C[i]->Control_Points, 1, &tmp);
          if(CompareVertex(&O, &tmp)) isSphere = false;
        }
      }
    }
    if(isSphere) {
      double n[3] = {C[0]->Circle.invmat[0][2], C[0]->Circle.invmat[1][2],
                     C[0]->Circle.invmat[2][2]};
      bool isPlane = true;
      for(int i = 1; i < std::min(List_Nbr(s->Generatrices), 4); i++)
        isPlane &= (n[0] == C[i]->Circle.invmat[0][2] &&
                    n[1] == C[i]->Circle.invmat[1][2] &&
                    n[2] == C[i]->Circle.invmat[2][2]);
      if(isPlane) isSphere = false;
    }
  }

  Vertex *S[4], V[4], VB[3], T;
  if(s->Typ == MSH_SURF_REGL && List_Nbr(s->Generatrices) >= 4) {
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    S[3] = C[3]->beg;
    V[0] =
      InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] =
      InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(
      C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    V[3] = InterpolateCurve(
      C[3], C[3]->ubeg + (C[3]->uend - C[3]->ubeg) * (1. - v), 0);
    T =
      TransfiniteQua(V[0], V[1], V[2], V[3], *S[0], *S[1], *S[2], *S[3], u, v);
    if(isSphere) TransfiniteSph(*S[0], *O, &T);
  }
  else if(List_Nbr(s->Generatrices) >= 3) {
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    if(CTX::instance()->geom.oldRuledSurface) {
      V[0] =
        InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
      V[1] =
        InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
      V[2] = InterpolateCurve(
        C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
      T = TransfiniteTri(V[0], V[1], V[2], *S[0], *S[1], *S[2], u, v);
    }
    else {
      V[0] = InterpolateCurve(
        C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * (u - v), 0);
      V[1] =
        InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
      V[2] = InterpolateCurve(
        C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
      VB[0] =
        InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
      VB[1] = InterpolateCurve(
        C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * (1 - u + v), 0);
      VB[2] = InterpolateCurve(
        C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - v), 0);
      T = TransfiniteTriB(V[0], VB[0], V[1], VB[1], V[2], VB[2], *S[0], *S[1],
                          *S[2], u, v);
    }
    if(isSphere) { TransfiniteSph(*S[0], *O, &T); }
  }

  return T;
}

static Vertex InterpolateExtrudedSurface(Surface *s, double u, double v)
{
  Curve *c = FindCurve(s->Extrude->geo.Source);

  // find position of c in the list of generatrices
  int num = -1;
  for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
    if(c == *(Curve **)List_Pointer(s->Generatrices, i)) {
      num = i;
      break;
    }
  }

  Vertex T;

  if(num < 0) {
    Msg::Error("Unknown curve in extruded surface");
    return T;
  }

  switch(num) {
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
    Vertex D[4];
    if(u_v == 1) {
      if(u - fd_eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u + fd_eps, v, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u - fd_eps, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    else {
      if(v - fd_eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v + fd_eps, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - fd_eps, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    return Vertex((D[1].Pos.X - D[0].Pos.X) / fd_eps,
                  (D[1].Pos.Y - D[0].Pos.Y) / fd_eps,
                  (D[1].Pos.Z - D[0].Pos.Z) / fd_eps);
  }
  else if(derivee == 2) {
    Vertex D[2];
    if(u_v == 1) { // dudu
      if(u - fd_eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 1);
        D[1] = InterpolateSurface(s, u + fd_eps, v, 1, 1);
      }
      else {
        D[0] = InterpolateSurface(s, u - fd_eps, v, 1, 1);
        D[1] = InterpolateSurface(s, u, v, 1, 1);
      }
    }
    else if(u_v == 2) { // dvdv
      if(v - fd_eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 2);
        D[1] = InterpolateSurface(s, u, v + fd_eps, 1, 2);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - fd_eps, 1, 2);
        D[1] = InterpolateSurface(s, u, v, 1, 2);
      }
    }
    else { // dudv
      if(v - fd_eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 1, 1);
        D[1] = InterpolateSurface(s, u, v + fd_eps, 1, 1);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - fd_eps, 1, 1);
        D[1] = InterpolateSurface(s, u, v, 1, 1);
      }
    }
    return Vertex((D[1].Pos.X - D[0].Pos.X) / fd_eps,
                  (D[1].Pos.Y - D[0].Pos.Y) / fd_eps,
                  (D[1].Pos.Z - D[0].Pos.Z) / fd_eps);
  }

  if(s->geometry) {
    SPoint3 p = s->geometry->point(u, v);
    return Vertex(p.x(), p.y(), p.z());
  }

  // Warning: we use the exact extrusion formula so we can create exact surfaces
  // of revolution. This WILL fail if the surface is transformed after the
  // extrusion: in that case set the exactExtrusion option to 0 to use the
  // normal code path
  if(CTX::instance()->geom.exactExtrusion && s->Extrude &&
     s->Extrude->geo.Mode == EXTRUDED_ENTITY && s->Typ != MSH_SURF_PLAN)
    return InterpolateExtrudedSurface(s, u, v);

  switch(s->Typ) {
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC: return InterpolateRuledSurface(s, u, v);
  case MSH_SURF_PLAN:
    Msg::Error("Should not interpolate plane surface here");
    return Vertex(0., 0., 0.);
  case MSH_SURF_BND_LAYER:
    Msg::Debug("Cannot interpolate boundary layer surface");
    return Vertex(0., 0., 0.);
  case MSH_SURF_DISCRETE:
    Msg::Debug("Cannot interpolate discrete surface");
    return Vertex(0., 0., 0.);
  default:
    Msg::Error("Unknown surface type in interpolation");
    return Vertex(0., 0., 0.);
  }
}
