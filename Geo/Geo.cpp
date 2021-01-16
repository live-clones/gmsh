// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <string.h>
#include "GmshMessage.h"
#include "GmshConfig.h"
#include "Numeric.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Context.h"
#include "MVertexRTree.h"
#include "fullMatrix.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

static List_T *ListOfTransformedPoints = nullptr;

int CompareVertex(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;
  return abs(q->Num) - abs(w->Num);
}

static int ComparePosition(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;

  if(!q || !w) {
    Msg::Error("Cannot compare position of null points");
    return 99;
  }

  // Warning: tolerance (before 1.61, it was set to 1.e-10 *
  // CTX::instance()->lc)
  double eps = CTX::instance()->geom.tolerance * CTX::instance()->lc;

  if(q->Pos.X - w->Pos.X > eps) return 1;
  if(q->Pos.X - w->Pos.X < -eps) return -1;
  if(q->Pos.Y - w->Pos.Y > eps) return 1;
  if(q->Pos.Y - w->Pos.Y < -eps) return -1;
  if(q->Pos.Z - w->Pos.Z > eps) return 1;
  if(q->Pos.Z - w->Pos.Z < -eps) return -1;
  return 0;
}

int CompareSurfaceLoop(const void *a, const void *b)
{
  SurfaceLoop *q = *(SurfaceLoop **)a;
  SurfaceLoop *w = *(SurfaceLoop **)b;
  return q->Num - w->Num;
}

int CompareEdgeLoop(const void *a, const void *b)
{
  EdgeLoop *q = *(EdgeLoop **)a;
  EdgeLoop *w = *(EdgeLoop **)b;
  return q->Num - w->Num;
}

int CompareCurve(const void *a, const void *b)
{
  Curve *q = *(Curve **)a;
  Curve *w = *(Curve **)b;
  return q->Num - w->Num;
}

int CompareSurface(const void *a, const void *b)
{
  Surface *q = *(Surface **)a;
  Surface *w = *(Surface **)b;
  return q->Num - w->Num;
}

int CompareVolume(const void *a, const void *b)
{
  Volume *q = *(Volume **)a;
  Volume *w = *(Volume **)b;
  return q->Num - w->Num;
}

int ComparePhysicalGroup(const void *a, const void *b)
{
  PhysicalGroup *q = *(PhysicalGroup **)a;
  PhysicalGroup *w = *(PhysicalGroup **)b;
  int cmp = q->Typ - w->Typ;
  if(cmp)
    return cmp;
  else
    return q->Num - w->Num;
}

Vertex *CreateVertex(int Num, double X, double Y, double Z, double lc, double u)
{
  Vertex *pV = new Vertex(X, Y, Z, lc);
  pV->w = 1.0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    0, std::max(GModel::current()->getGEOInternals()->getMaxTag(0), Num));
  pV->u = u;
  pV->geometry = nullptr;
  return pV;
}

Vertex *CreateVertex(int Num, double u, double v, gmshSurface *surf, double lc)
{
  SPoint3 p = surf->point(u, v);
  Vertex *pV = new Vertex(p.x(), p.y(), p.z(), lc);
  pV->w = 1.0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    0, std::max(GModel::current()->getGEOInternals()->getMaxTag(0), Num));
  pV->u = u;
  pV->geometry = surf;
  pV->pntOnGeometry = SPoint2(u, v);
  surf->vertex_defined_on_surface = true;
  return pV;
}

void FreeVertex(void *a, void *b)
{
  Vertex *v = *(Vertex **)a;
  if(v) {
    delete v;
    v = nullptr;
  }
}

PhysicalGroup *CreatePhysicalGroup(int Num, int typ, List_T *intlist)
{
  PhysicalGroup *p = new PhysicalGroup;
  p->Entities = List_Create(List_Nbr(intlist), 1, sizeof(int));
  p->Num = Num;
  GModel::current()->getGEOInternals()->setMaxPhysicalTag(
    std::max(GModel::current()->getGEOInternals()->getMaxPhysicalTag(), Num));
  p->Typ = typ;
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(p->Entities, &j);
  }
  return p;
}

void FreePhysicalGroup(void *a, void *b)
{
  PhysicalGroup *p = *(PhysicalGroup **)a;
  if(p) {
    List_Delete(p->Entities);
    delete p;
    p = nullptr;
  }
}

EdgeLoop *CreateEdgeLoop(int Num, List_T *intlist)
{
  EdgeLoop *l = new EdgeLoop;
  l->Curves = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    -1, std::max(GModel::current()->getGEOInternals()->getMaxTag(-1), Num));
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Curves, &j);
  }
  return l;
}

void FreeEdgeLoop(void *a, void *b)
{
  EdgeLoop *l = *(EdgeLoop **)a;
  if(l) {
    List_Delete(l->Curves);
    delete l;
    l = nullptr;
  }
}

SurfaceLoop *CreateSurfaceLoop(int Num, List_T *intlist)
{
  SurfaceLoop *l = new SurfaceLoop;
  l->Surfaces = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    -2, std::max(GModel::current()->getGEOInternals()->getMaxTag(-2), Num));
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Surfaces, &j);
  }
  return l;
}

void FreeSurfaceLoop(void *a, void *b)
{
  SurfaceLoop *l = *(SurfaceLoop **)a;
  if(l) {
    List_Delete(l->Surfaces);
    delete l;
    l = nullptr;
  }
}

static void direction(Vertex *v1, Vertex *v2, double d[3])
{
  d[0] = v2->Pos.X - v1->Pos.X;
  d[1] = v2->Pos.Y - v1->Pos.Y;
  d[2] = v2->Pos.Z - v1->Pos.Z;
}

bool EndCurve(Curve *c)
{
  bool ok = true;

  // if all control points of a curve are on the same geometry, then the curve
  // is also on the geometry
  int NN = List_Nbr(c->Control_Points);
  if(NN) {
    Vertex *pV;
    List_Read(c->Control_Points, 0, &pV);
    c->geometry = pV->geometry;
    for(int i = 1; i < NN; i++) {
      List_Read(c->Control_Points, i, &pV);
      if(c->geometry != pV->geometry) {
        c->geometry = nullptr;
        break;
      }
    }
  }
  c->degenerated = false;

  if((c->Typ == MSH_SEGM_CIRC || c->Typ == MSH_SEGM_CIRC_INV ||
      c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV) &&
     (NN == 3 || NN == 4)) {
    // v[0] = first point
    // v[1] = center
    // v[2] = last point
    // v[3] = major axis point
    Vertex *v[4];
    if(List_Nbr(c->Control_Points) == 4)
      List_Read(c->Control_Points, 2, &v[3]);
    else
      v[3] = nullptr;
    if(c->Typ == MSH_SEGM_CIRC_INV || c->Typ == MSH_SEGM_ELLI_INV) {
      List_Read(c->Control_Points, 0, &v[2]);
      List_Read(c->Control_Points, 1, &v[1]);
      if(!v[3])
        List_Read(c->Control_Points, 2, &v[0]);
      else
        List_Read(c->Control_Points, 3, &v[0]);
    }
    else {
      List_Read(c->Control_Points, 0, &v[0]);
      List_Read(c->Control_Points, 1, &v[1]);
      if(!v[3])
        List_Read(c->Control_Points, 2, &v[2]);
      else
        List_Read(c->Control_Points, 3, &v[2]);
    }
    double dir12[3], dir32[3], dir42[3] = {0., 0., 0.};
    direction(v[1], v[0], dir12);
    direction(v[1], v[2], dir32);
    if(v[3]) direction(v[1], v[3], dir42);
    // v0 = vector center->first pt
    // v2 = vector center->last pt
    // v3 = vector center->major axis pt
    Vertex v0, v2, v3;
    v0.Pos.X = dir12[0];
    v0.Pos.Y = dir12[1];
    v0.Pos.Z = dir12[2];
    v2.Pos.X = dir32[0];
    v2.Pos.Y = dir32[1];
    v2.Pos.Z = dir32[2];
    if(v[3]) {
      v3.Pos.X = dir42[0];
      v3.Pos.Y = dir42[1];
      v3.Pos.Z = dir42[2];
    }
    norme(dir12);
    norme(dir32);
    double n[3];
    prodve(dir12, dir32, n);
    bool isValid = true;
    if(norm3(n) < 1.e-15) { isValid = false; }
    else {
      norme(n);
      if((fabs(n[0]) < 1.e-5 && fabs(n[1]) < 1.e-5 && fabs(n[2]) < 1.e-5)) {
        isValid = false;
      }
    }
    // use provided plane if unable to compute it from input points...
    if(!isValid) {
      n[0] = c->Circle.n[0];
      n[1] = c->Circle.n[1];
      n[2] = c->Circle.n[2];
      norme(n);
    }
    double m[3];
    prodve(n, dir12, m);
    norme(m);
    double mat[3][3];
    mat[2][0] = c->Circle.invmat[0][2] = n[0];
    mat[2][1] = c->Circle.invmat[1][2] = n[1];
    mat[2][2] = c->Circle.invmat[2][2] = n[2];
    mat[1][0] = c->Circle.invmat[0][1] = m[0];
    mat[1][1] = c->Circle.invmat[1][1] = m[1];
    mat[1][2] = c->Circle.invmat[2][1] = m[2];
    mat[0][0] = c->Circle.invmat[0][0] = dir12[0];
    mat[0][1] = c->Circle.invmat[1][0] = dir12[1];
    mat[0][2] = c->Circle.invmat[2][0] = dir12[2];
    // assume circle in z=0 plane
    if(CTX::instance()->geom.oldCircle) {
      if(n[0] == 0.0 && n[1] == 0.0) {
        mat[2][0] = c->Circle.invmat[0][2] = 0;
        mat[2][1] = c->Circle.invmat[1][2] = 0;
        mat[2][2] = c->Circle.invmat[2][2] = 1;
        mat[1][0] = c->Circle.invmat[0][1] = 0;
        mat[1][1] = c->Circle.invmat[1][1] = 1;
        mat[1][2] = c->Circle.invmat[2][1] = 0;
        mat[0][0] = c->Circle.invmat[0][0] = 1;
        mat[0][1] = c->Circle.invmat[1][0] = 0;
        mat[0][2] = c->Circle.invmat[2][0] = 0;
      }
    }
    Projette(&v0, mat);
    Projette(&v2, mat);
    if(v[3]) Projette(&v3, mat);
    double R = sqrt(v0.Pos.X * v0.Pos.X + v0.Pos.Y * v0.Pos.Y);
    double R2 = sqrt(v2.Pos.X * v2.Pos.X + v2.Pos.Y * v2.Pos.Y);
    if(!R || !R2) {
      // check radius
      Msg::Error("Zero radius in circle or ellipse with tag %d", c->Num);
      ok = false;
    }
    else if(!v[3] && fabs((R - R2) / (R + R2)) > 0.1) {
      // check cocircular pts (allow 10% error)
      Msg::Error("Control points of circle with tag %d are not cocircular: "
                 "R1=%g, R2=%g, n=[%g,%g,%g]",
                 c->Num, R, R2, n[0], n[1], n[2]);
      ok = false;
    }
    // A1 = angle first pt
    // A3 = angle last pt
    // A4 = angle major axis
    double A3, A1, A4;
    double f1, f2;
    if(v[3]) {
      A4 = myatan2(v3.Pos.Y, v3.Pos.X);
      A4 = angle_02pi(A4);
      double x1 = v0.Pos.X * cos(A4) + v0.Pos.Y * sin(A4);
      double y1 = -v0.Pos.X * sin(A4) + v0.Pos.Y * cos(A4);
      double x3 = v2.Pos.X * cos(A4) + v2.Pos.Y * sin(A4);
      double y3 = -v2.Pos.X * sin(A4) + v2.Pos.Y * cos(A4);
      double sys[2][2], rhs[2], sol[2];
      sys[0][0] = x1 * x1;
      sys[0][1] = y1 * y1;
      sys[1][0] = x3 * x3;
      sys[1][1] = y3 * y3;
      rhs[0] = 1;
      rhs[1] = 1;
      sys2x2(sys, rhs, sol);
      if(sol[0] <= 0 || sol[1] <= 0) {
        Msg::Error("Ellipse with tag %d is wrong", c->Num);
        ok = false;
        A1 = A3 = 0.;
        f1 = f2 = R;
      }
      else {
        f1 = sqrt(1. / sol[0]);
        f2 = sqrt(1. / sol[1]);
        // myasin() permet de contourner les problemes de precision
        // sur y1/f2 ou y3/f2, qui peuvent legerement etre hors de
        // [-1,1]
        if(x1 < 0)
          A1 = -myasin(y1 / f2) + A4 + M_PI;
        else
          A1 = myasin(y1 / f2) + A4;
        if(x3 < 0)
          A3 = -myasin(y3 / f2) + A4 + M_PI;
        else
          A3 = myasin(y3 / f2) + A4;
      }
    }
    else {
      A1 = myatan2(v0.Pos.Y, v0.Pos.X);
      A3 = myatan2(v2.Pos.Y, v2.Pos.X);
      A4 = 0.;
      f1 = f2 = R;
    }
    A1 = angle_02pi(A1);
    A3 = angle_02pi(A3);
    if(A1 >= A3) A3 += 2 * M_PI;
    c->Circle.t1 = A1;
    c->Circle.t2 = A3;
    c->Circle.incl = A4;
    c->Circle.f1 = f1;
    c->Circle.f2 = f2;
    if(!CTX::instance()->expertMode && c->Num > 0 && A3 - A1 > 1.01 * M_PI) {
      Msg::Error("Circle or ellipse arc %d greater than Pi (angle=%g)", c->Num,
                 A3 - A1);
      Msg::Error(
        "(If you understand what this implies, you can disable this error");
      Msg::Error(
        "message by selecting `Enable expert mode' in the option dialog.");
      Msg::Error("Otherwise, please subdivide the arc in smaller pieces.)");
      ok = false;
    }
  }

  return ok;
}

void EndSurface(Surface *s)
{
  // if all generatrices of a surface are on the same geometry, then
  // the surface is also on the geometry
  if(List_Nbr(s->Generatrices)) {
    Curve *c;
    int NN = List_Nbr(s->Generatrices);
    List_Read(s->Generatrices, 0, &c);
    s->geometry = c->geometry;
    for(int i = 1; i < NN; i++) {
      List_Read(s->Generatrices, i, &c);
      if(c->geometry != s->geometry) {
        s->geometry = nullptr;
        break;
      }
    }
  }
}

Curve *CreateCurve(int Num, int Typ, int Order, List_T *Liste, List_T *Knots,
                   int p1, int p2, double u1, double u2, bool &ok)
{
  ok = true;
  double matcr[4][4] = {{-0.5, 1.5, -1.5, 0.5},
                        {1.0, -2.5, 2.0, -0.5},
                        {-0.5, 0.0, 0.5, 0.0},
                        {0.0, 1.0, 0.0, 0.0}};
  double matbs[4][4] = {
    {-1, 3, -3, 1}, {3, -6, 3, 0}, {-3, 0, 3, 0}, {1, 4, 1, 0}};
  double matbez[4][4] = {
    {-1, 3, -3, 1}, {3, -6, 3, 0}, {-3, 3, 0, 0}, {1, 0, 0, 0}};

  Curve *pC = new Curve;
  pC->Extrude = nullptr;
  pC->Typ = Typ;
  pC->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    1, std::max(GModel::current()->getGEOInternals()->getMaxTag(1), Num));
  pC->Method = MESH_UNSTRUCTURED;
  pC->degre = Order;
  pC->Circle.n[0] = 0.0;
  pC->Circle.n[1] = 0.0;
  pC->Circle.n[2] = 1.0;
  pC->geometry = nullptr;
  pC->nbPointsTransfinite = 0;
  pC->typeTransfinite = 0;
  pC->coeffTransfinite = 0.;
  pC->ReverseMesh = 0;
  pC->beg = nullptr;
  pC->end = nullptr;
  pC->Control_Points = nullptr;
  pC->degenerated = false;

  if(Typ == MSH_SEGM_SPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) pC->mat[i][j] = matcr[i][j];
  }
  else if(Typ == MSH_SEGM_BSPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) pC->mat[i][j] = matbs[i][j] / 6.0;
  }
  else if(Typ == MSH_SEGM_BEZIER) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) pC->mat[i][j] = matbez[i][j];
  }

  pC->ubeg = u1;
  pC->uend = u2;

  if(Knots && List_Nbr(Knots)) {
    pC->k = new float[List_Nbr(Knots)];
    double kmin = .0, kmax = 1.;
    List_Read(Knots, 0, &kmin);
    List_Read(Knots, List_Nbr(Knots) - 1, &kmax);
    pC->ubeg = kmin;
    pC->uend = kmax;
    for(int i = 0; i < List_Nbr(Knots); i++) {
      double d;
      List_Read(Knots, i, &d);
      pC->k[i] = (float)d;
    }
  }
  else
    pC->k = nullptr;

  if(List_Nbr(Liste)) {
    pC->Control_Points = List_Create(List_Nbr(Liste), 1, sizeof(Vertex *));
    for(int j = 0; j < List_Nbr(Liste); j++) {
      int iPnt;
      List_Read(Liste, j, &iPnt);
      Vertex *v;
      if((v = FindPoint(iPnt)))
        List_Add(pC->Control_Points, &v);
      else {
        Msg::Error("Unknown control point %d in GEO curve %d", iPnt, pC->Num);
        ok = false;
      }
    }
    if(p1 < 0) {
      if(List_Nbr(pC->Control_Points)) {
        List_Read(pC->Control_Points, 0, &pC->beg);
        List_Read(pC->Control_Points, List_Nbr(pC->Control_Points) - 1,
                  &pC->end);
      }
    }
    else {
      Vertex *v;
      if((v = FindPoint(p1))) {
        Msg::Info("Curve %d first control point %d ", pC->Num, v->Num);
        pC->beg = v;
      }
      else {
        Msg::Error("Unknown control point %d in GEO curve %d", p1, pC->Num);
        ok = false;
      }
      if((v = FindPoint(p2))) {
        Msg::Info("Curve %d first control point %d ", pC->Num, v->Num);
        pC->end = v;
      }
      else {
        Msg::Error("Unknown control point %d in GEO curve %d", p2, pC->Num);
        ok = false;
      }
    }
    if(!EndCurve(pC)) ok = false;
  }

  return pC;
}

void FreeCurve(void *a, void *b)
{
  Curve *pC = *(Curve **)a;
  if(pC) {
    if(pC->k) delete[] pC->k;
    List_Delete(pC->Control_Points);
    if(pC->Extrude) delete pC->Extrude;
    delete pC;
    pC = nullptr;
  }
}

Surface *CreateSurface(int Num, int Typ)
{
  Surface *pS = new Surface;
  pS->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    2, std::max(GModel::current()->getGEOInternals()->getMaxTag(2), Num));
  pS->geometry = nullptr;
  pS->InSphereCenter = nullptr;
  pS->Typ = Typ;
  pS->Method = MESH_UNSTRUCTURED;
  pS->Recombine = 0;
  pS->RecombineAngle = 45;
  pS->Recombine_Dir = -1;
  pS->TransfiniteSmoothing = -1;
  pS->TrsfPoints = List_Create(4, 4, sizeof(Vertex *));
  pS->Generatrices = nullptr;
  pS->GeneratricesByTag = nullptr;
  pS->Extrude = nullptr;
  pS->geometry = nullptr;
  pS->ReverseMesh = 0;
  pS->MeshAlgorithm = 0;
  pS->MeshSizeFromBoundary = -1;
  return (pS);
}

void FreeSurface(void *a, void *b)
{
  Surface *pS = *(Surface **)a;
  if(pS) {
    List_Delete(pS->TrsfPoints);
    List_Delete(pS->Generatrices);
    List_Delete(pS->GeneratricesByTag);
    if(pS->Extrude) delete pS->Extrude;
    delete pS;
    pS = nullptr;
  }
}

Volume *CreateVolume(int Num, int Typ)
{
  Volume *pV = new Volume;
  pV->Recombine3D = 0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->setMaxTag(
    3, std::max(GModel::current()->getGEOInternals()->getMaxTag(3), Num));
  pV->Typ = Typ;
  pV->Method = MESH_UNSTRUCTURED;
  pV->QuadTri = NO_QUADTRI;
  pV->TrsfPoints = List_Create(6, 6, sizeof(Vertex *));
  pV->Surfaces = List_Create(1, 2, sizeof(Surface *));
  pV->SurfacesOrientations = List_Create(1, 2, sizeof(int));
  pV->SurfacesByTag = List_Create(1, 2, sizeof(int));
  pV->Extrude = nullptr;
  return pV;
}

void FreeVolume(void *a, void *b)
{
  Volume *pV = *(Volume **)a;
  if(pV) {
    List_Delete(pV->TrsfPoints);
    List_Delete(pV->Surfaces);
    List_Delete(pV->SurfacesOrientations);
    List_Delete(pV->SurfacesByTag);
    if(pV->Extrude) delete pV->Extrude;
    delete pV;
    pV = nullptr;
  }
}

static int Compare2Lists(List_T *List1, List_T *List2,
                         int (*fcmp)(const void *a, const void *b))
{
  int i, found;

  if(!List_Nbr(List1) && !List_Nbr(List2)) return 0;

  if(!List_Nbr(List1) || !List_Nbr(List2) ||
     (List_Nbr(List1) != List_Nbr(List2)))
    return List_Nbr(List1) - List_Nbr(List2);

  List_T *List1Prime = List_Create(List_Nbr(List1), 1, List1->size);
  List_T *List2Prime = List_Create(List_Nbr(List2), 1, List2->size);
  List_Copy(List1, List1Prime);
  List_Copy(List2, List2Prime);
  List_Sort(List1Prime, fcmp);
  List_Sort(List2Prime, fcmp);

  for(i = 0; i < List_Nbr(List1Prime); i++) {
    found = fcmp(List_Pointer(List1Prime, i), List_Pointer(List2Prime, i));
    if(found != 0) {
      List_Delete(List1Prime);
      List_Delete(List2Prime);
      return found;
    }
  }
  List_Delete(List1Prime);
  List_Delete(List2Prime);
  return 0;
}

static Vertex *FindPoint(int inum, Tree_T *t)
{
  Vertex C, *pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(t, &pc)) { return pc; }
  return nullptr;
}

Vertex *FindPoint(int inum)
{
  return FindPoint(inum, GModel::current()->getGEOInternals()->Points);
}

static Curve *FindCurve(int inum, Tree_T *t)
{
  Curve C, *pc;
  pc = &C;
  pc->Num = inum;
  if(Tree_Query(t, &pc)) { return pc; }
  return nullptr;
}

Curve *FindCurve(int inum)
{
  return FindCurve(inum, GModel::current()->getGEOInternals()->Curves);
}

static Surface *FindSurface(int inum, Tree_T *t)
{
  Surface S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(t, &ps)) { return ps; }
  return nullptr;
}

Surface *FindSurface(int inum)
{
  return FindSurface(inum, GModel::current()->getGEOInternals()->Surfaces);
}

Volume *FindVolume(int inum)
{
  Volume V, *pv;
  pv = &V;
  pv->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->Volumes, &pv)) {
    return pv;
  }
  return nullptr;
}

EdgeLoop *FindEdgeLoop(int inum)
{
  EdgeLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->EdgeLoops, &ps)) {
    return ps;
  }
  return nullptr;
}

SurfaceLoop *FindSurfaceLoop(int inum)
{
  SurfaceLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->SurfaceLoops, &ps)) {
    return ps;
  }
  return nullptr;
}

PhysicalGroup *FindPhysicalGroup(int num, int type)
{
  PhysicalGroup P, *pp, **ppp;
  pp = &P;
  pp->Num = num;
  pp->Typ = type;
  if((ppp = (PhysicalGroup **)List_PQuery(
        GModel::current()->getGEOInternals()->PhysicalGroups, &pp,
        ComparePhysicalGroup))) {
    return *ppp;
  }
  return nullptr;
}

static void CopyVertex(Vertex *v, Vertex *vv)
{
  vv->lc = v->lc;
  vv->u = v->u;
  vv->Pos.X = v->Pos.X;
  vv->Pos.Y = v->Pos.Y;
  vv->Pos.Z = v->Pos.Z;
}

Vertex *DuplicateVertex(Vertex *v)
{
  if(!v) return nullptr;
  Vertex *pv = CreateVertex(NEWPOINT(), 0, 0, 0, 0, 0);
  CopyVertex(v, pv);
  Tree_Insert(GModel::current()->getGEOInternals()->Points, &pv);
  return pv;
}

static int CompareAbsCurve(const void *a, const void *b)
{
  Curve *q = *(Curve **)a;
  Curve *w = *(Curve **)b;
  return abs(q->Num) - abs(w->Num);
}

static void CopyCurve(Curve *c, Curve *cc)
{
  cc->Typ = c->Typ;
  if(CTX::instance()->geom.copyMeshingMethod) {
    cc->Method = c->Method;
    cc->nbPointsTransfinite = c->nbPointsTransfinite;
    cc->typeTransfinite = c->typeTransfinite;
    cc->coeffTransfinite = c->coeffTransfinite;
    cc->ReverseMesh = c->ReverseMesh;
  }
  cc->l = c->l;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) cc->mat[i][j] = c->mat[i][j];
  cc->beg = c->beg;
  cc->end = c->end;
  cc->ubeg = c->ubeg;
  cc->uend = c->uend;
  cc->Control_Points =
    List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex *));
  List_Copy(c->Control_Points, cc->Control_Points);
  EndCurve(cc);
}

Curve *DuplicateCurve(Curve *c)
{
  bool ok = true;
  Curve *pc =
    CreateCurve(NEWLINE(), 0, 1, nullptr, nullptr, -1, -1, 0., 1., ok);
  CopyCurve(c, pc);
  Tree_Insert(GModel::current()->getGEOInternals()->Curves, &pc);
  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    Vertex *v;
    List_Read(pc->Control_Points, i, &v);
    Vertex *newv = DuplicateVertex(v);
    List_Write(pc->Control_Points, i, &newv);
  }
  pc->beg = DuplicateVertex(c->beg);
  pc->end = DuplicateVertex(c->end);
  CreateReversedCurve(pc);
  return pc;
}

static void CopySurface(Surface *s, Surface *ss)
{
  ss->Typ = s->Typ;
  if(CTX::instance()->geom.copyMeshingMethod) {
    ss->Method = s->Method;
    ss->Recombine = s->Recombine;
    ss->RecombineAngle = s->RecombineAngle;
    ss->ReverseMesh = s->ReverseMesh;
    ss->MeshAlgorithm = s->MeshAlgorithm;
    ss->MeshSizeFromBoundary = s->MeshSizeFromBoundary;
    if(List_Nbr(s->TrsfPoints))
      Msg::Warning(
        "Only automatic transfinite surface specifications can be copied");
  }
  ss->Generatrices =
    List_Create(List_Nbr(s->Generatrices) + 1, 1, sizeof(Curve *));
  ss->GeneratricesByTag =
    List_Create(List_Nbr(s->GeneratricesByTag) + 1, 1, sizeof(int));
  // after copy (and subsequent transformation), the sphere center does not make
  // sense anymore
  ss->InSphereCenter = nullptr;
  List_Copy(s->Generatrices, ss->Generatrices);
  List_Copy(s->GeneratricesByTag, ss->GeneratricesByTag);
  EndSurface(ss);
}

Surface *DuplicateSurface(Surface *s)
{
  Surface *ps = CreateSurface(NEWSURFACE(), 0);
  CopySurface(s, ps);
  Tree_Insert(GModel::current()->getGEOInternals()->Surfaces, &ps);
  for(int i = 0; i < List_Nbr(ps->Generatrices); i++) {
    Curve *c;
    List_Read(ps->Generatrices, i, &c);
    Curve *newc = DuplicateCurve(c);
    List_Write(ps->Generatrices, i, &newc);
  }
  return ps;
}

static void CopyVolume(Volume *v, Volume *vv)
{
  vv->Typ = v->Typ;
  if(CTX::instance()->geom.copyMeshingMethod) {
    vv->Method = v->Method;
    vv->QuadTri = v->QuadTri;
    vv->Recombine3D = v->Recombine3D;
    if(List_Nbr(v->TrsfPoints))
      Msg::Warning(
        "Only automatic transfinite volume specifications can be copied");
  }
  List_Copy(v->Surfaces, vv->Surfaces);
  List_Copy(v->SurfacesOrientations, vv->SurfacesOrientations);
  List_Copy(v->SurfacesByTag, vv->SurfacesByTag);
}

Volume *DuplicateVolume(Volume *v)
{
  Volume *pv = CreateVolume(NEWVOLUME(), 0);
  CopyVolume(v, pv);
  Tree_Insert(GModel::current()->getGEOInternals()->Volumes, &pv);
  for(int i = 0; i < List_Nbr(pv->Surfaces); i++) {
    Surface *s;
    List_Read(pv->Surfaces, i, &s);
    Surface *news = DuplicateSurface(s);
    List_Write(pv->Surfaces, i, &news);
  }
  return pv;
}

void DeletePoint(int ip, bool recursive)
{
  Vertex *v = FindPoint(ip);
  if(!v) return;
  List_T *Curves = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(Curves); i++) {
    Curve *c;
    List_Read(Curves, i, &c);
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      if(!CompareVertex(List_Pointer(c->Control_Points, j), &v)) {
        List_Delete(Curves);
        // cannot delete: it's a control point of a curve
        return;
      }
    }
  }
  List_Delete(Curves);

  int tmax = GModel::current()->getGEOInternals()->getMaxTag(0);
  if(v->Num == tmax)
    GModel::current()->getGEOInternals()->setMaxTag(0, tmax - 1);
  Tree_Suppress(GModel::current()->getGEOInternals()->Points, &v);
  Tree_Add(GModel::current()->getGEOInternals()->DelPoints, &v);
}

void DeleteCurve(int ip, bool recursive)
{
  Curve *c = FindCurve(ip);
  if(!c) return;
  List_T *Surfs = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      if(!CompareAbsCurve(List_Pointer(s->Generatrices, j), &c)) {
        List_Delete(Surfs);
        // cannot delete: it's on the boundary of a surface
        return;
      }
    }
  }
  List_Delete(Surfs);

  int tmax = GModel::current()->getGEOInternals()->getMaxTag(1);
  if(c->Num == tmax)
    GModel::current()->getGEOInternals()->setMaxTag(1, tmax - 1);
  Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c);
  Tree_Add(GModel::current()->getGEOInternals()->DelCurves, &c);

  if(recursive) {
    std::set<int> vv;
    for(int k = 0; k < List_Nbr(c->Control_Points); k++) {
      Vertex *v;
      List_Read(c->Control_Points, k, &v);
      vv.insert(v->Num);
    }
    if(c->beg) vv.insert(c->beg->Num);
    if(c->end) vv.insert(c->end->Num);
    for(auto it = vv.begin(); it != vv.end(); it++) DeletePoint(*it);
  }
}

void DeleteSurface(int is, bool recursive)
{
  Surface *s = FindSurface(is);
  if(!s) return;
  List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(Vols); i++) {
    Volume *v;
    List_Read(Vols, i, &v);
    for(int j = 0; j < List_Nbr(v->Surfaces); j++) {
      if(!CompareSurface(List_Pointer(v->Surfaces, j), &s)) {
        List_Delete(Vols);
        // cannot delete: it's on the boundary of a volume
        return;
      }
    }
  }
  List_Delete(Vols);

  int tmax = GModel::current()->getGEOInternals()->getMaxTag(2);
  if(s->Num == tmax)
    GModel::current()->getGEOInternals()->setMaxTag(2, tmax - 1);
  Tree_Suppress(GModel::current()->getGEOInternals()->Surfaces, &s);
  Tree_Add(GModel::current()->getGEOInternals()->DelSurfaces, &s);

  if(recursive) {
    std::set<int> cc, vv;
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      Curve *c;
      List_Read(s->Generatrices, j, &c);
      cc.insert(c->Num);
      for(int k = 0; k < List_Nbr(c->Control_Points); k++) {
        Vertex *v;
        List_Read(c->Control_Points, k, &v);
        vv.insert(v->Num);
      }
      if(c->beg) vv.insert(c->beg->Num);
      if(c->end) vv.insert(c->end->Num);
    }
    for(auto it = cc.begin(); it != cc.end(); it++) {
      DeleteCurve(*it);
      DeleteCurve(-*it);
    }
    for(auto it = vv.begin(); it != vv.end(); it++) DeletePoint(*it);
  }
}

void DeleteVolume(int iv, bool recursive)
{
  Volume *v = FindVolume(iv);
  if(!v) return;

  int tmax = GModel::current()->getGEOInternals()->getMaxTag(3);
  if(v->Num == tmax)
    GModel::current()->getGEOInternals()->setMaxTag(3, tmax - 1);
  Tree_Suppress(GModel::current()->getGEOInternals()->Volumes, &v);
  Tree_Add(GModel::current()->getGEOInternals()->DelVolumes, &v);

  if(recursive) {
    std::set<int> ss, cc, vv;
    for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
      Surface *s;
      List_Read(v->Surfaces, i, &s);
      ss.insert(s->Num);
      for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
        Curve *c;
        List_Read(s->Generatrices, j, &c);
        cc.insert(c->Num);
        for(int k = 0; k < List_Nbr(c->Control_Points); k++) {
          Vertex *v;
          List_Read(c->Control_Points, k, &v);
          vv.insert(v->Num);
        }
        if(c->beg) vv.insert(c->beg->Num);
        if(c->end) vv.insert(c->end->Num);
      }
    }
    for(auto it = ss.begin(); it != ss.end(); it++) DeleteSurface(*it);
    for(auto it = cc.begin(); it != cc.end(); it++) {
      DeleteCurve(*it);
      DeleteCurve(-*it);
    }
    for(auto it = vv.begin(); it != vv.end(); it++) DeletePoint(*it);
  }
}

void DeletePhysicalPoint(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
  if(p) {
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  ComparePhysicalGroup);
    List_Add(GModel::current()->getGEOInternals()->DelPhysicalGroups, &p);
  }
  GModel::current()->removePhysicalGroup(0, num);
}

void DeletePhysicalLine(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
  if(p) {
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  ComparePhysicalGroup);
    List_Add(GModel::current()->getGEOInternals()->DelPhysicalGroups, &p);
  }
  GModel::current()->removePhysicalGroup(1, num);
}

void DeletePhysicalSurface(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
  if(p) {
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  ComparePhysicalGroup);
    List_Add(GModel::current()->getGEOInternals()->DelPhysicalGroups, &p);
  }
  GModel::current()->removePhysicalGroup(2, num);
}

void DeletePhysicalVolume(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
  if(p) {
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  ComparePhysicalGroup);
    List_Add(GModel::current()->getGEOInternals()->DelPhysicalGroups, &p);
  }
  GModel::current()->removePhysicalGroup(3, num);
}

Curve *CreateReversedCurve(Curve *c)
{
  bool ok = true;
  Curve *newc =
    CreateCurve(-c->Num, c->Typ, 1, nullptr, nullptr, -1, -1, 0., 1., ok);

  if(List_Nbr(c->Control_Points)) {
    newc->Control_Points =
      List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex *));
    if(c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV) {
      Vertex *e1, *e2, *e3, *e4;
      List_Read(c->Control_Points, 0, &e1);
      List_Read(c->Control_Points, 1, &e2);
      List_Read(c->Control_Points, 2, &e3);
      List_Read(c->Control_Points, 3, &e4);
      List_Add(newc->Control_Points, &e4);
      List_Add(newc->Control_Points, &e2);
      List_Add(newc->Control_Points, &e3);
      List_Add(newc->Control_Points, &e1);
    }
    else
      List_Invert(c->Control_Points, newc->Control_Points);
  }

  if(c->Typ == MSH_SEGM_NURBS && c->k) {
    newc->k = new float[c->degre + List_Nbr(c->Control_Points) + 1];
    for(int i = 0; i < c->degre + List_Nbr(c->Control_Points) + 1; i++)
      newc->k[c->degre + List_Nbr(c->Control_Points) - i] = c->k[i];
  }

  if(c->Typ == MSH_SEGM_CIRC) newc->Typ = MSH_SEGM_CIRC_INV;
  if(c->Typ == MSH_SEGM_CIRC_INV) newc->Typ = MSH_SEGM_CIRC;
  if(c->Typ == MSH_SEGM_ELLI) newc->Typ = MSH_SEGM_ELLI_INV;
  if(c->Typ == MSH_SEGM_ELLI_INV) newc->Typ = MSH_SEGM_ELLI;

  newc->beg = c->end;
  newc->end = c->beg;
  newc->Method = c->Method;
  newc->nbPointsTransfinite = c->nbPointsTransfinite;
  newc->typeTransfinite = -c->typeTransfinite;
  newc->coeffTransfinite = c->coeffTransfinite;
  newc->degre = c->degre;
  newc->ubeg = 1. - c->uend;
  newc->uend = 1. - c->ubeg;

  if(c->Extrude) {
    newc->Extrude = new ExtrudeParams;
    newc->Extrude->geo = c->Extrude->geo;
  }

  EndCurve(newc);

  Curve **pc;
  if((pc = (Curve **)Tree_PQuery(GModel::current()->getGEOInternals()->Curves,
                                 &newc))) {
    FreeCurve(&newc, nullptr);
    return *pc;
  }
  else {
    Tree_Add(GModel::current()->getGEOInternals()->Curves, &newc);
    return newc;
  }
}

int RecognizeLineLoop(List_T *liste, int *loop)
{
  int res = 0;
  *loop = 0;
  List_T *temp = Tree2List(GModel::current()->getGEOInternals()->EdgeLoops);
  for(int i = 0; i < List_Nbr(temp); i++) {
    EdgeLoop *pe;
    List_Read(temp, i, &pe);
    if(!Compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

int RecognizeSurfaceLoop(List_T *liste, int *loop)
{
  int res = 0;
  *loop = 0;
  List_T *temp = Tree2List(GModel::current()->getGEOInternals()->SurfaceLoops);
  for(int i = 0; i < List_Nbr(temp); i++) {
    EdgeLoop *pe;
    List_Read(temp, i, &pe);
    if(!Compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

void SetTranslationMatrix(double matrix[4][4], double T[3])
{
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) { matrix[i][j] = (i == j) ? 1.0 : 0.0; }
  }
  for(int i = 0; i < 3; i++) matrix[i][3] = T[i];
}

void SetSymmetryMatrix(double matrix[4][4], double A, double B, double C,
                       double D)
{
  double p = (A * A + B * B + C * C);
  if(!p) p = 1e-12;
  double F = -2.0 / p;
  matrix[0][0] = 1. + A * A * F;
  matrix[0][1] = A * B * F;
  matrix[0][2] = A * C * F;
  matrix[0][3] = A * D * F;
  matrix[1][0] = A * B * F;
  matrix[1][1] = 1. + B * B * F;
  matrix[1][2] = B * C * F;
  matrix[1][3] = B * D * F;
  matrix[2][0] = A * C * F;
  matrix[2][1] = B * C * F;
  matrix[2][2] = 1. + C * C * F;
  matrix[2][3] = C * D * F;
  matrix[3][0] = B * C * F;
  matrix[3][1] = 0.0;
  matrix[3][2] = 0.0;
  matrix[3][3] = 1.0;
}

void SetDilatationMatrix(double matrix[4][4], double T[3], double A, double B,
                         double C)
{
  matrix[0][0] = A;
  matrix[0][1] = 0.0;
  matrix[0][2] = 0.0;
  matrix[0][3] = T[0] * (1.0 - A);
  matrix[1][0] = 0.0;
  matrix[1][1] = B;
  matrix[1][2] = 0.0;
  matrix[1][3] = T[1] * (1.0 - B);
  matrix[2][0] = 0.0;
  matrix[2][1] = 0.0;
  matrix[2][2] = C;
  matrix[2][3] = T[2] * (1.0 - C);
  matrix[3][0] = 0.0;
  matrix[3][1] = 0.0;
  matrix[3][2] = 0.0;
  matrix[3][3] = 1.0;
}

static void GramSchmidt(double v1[3], double v2[3], double v3[3])
{
  double tmp[3];
  norme(v1);
  prodve(v3, v1, tmp);
  norme(tmp);
  v2[0] = tmp[0];
  v2[1] = tmp[1];
  v2[2] = tmp[2];
  prodve(v1, v2, v3);
  norme(v3);
}

void SetRotationMatrix(double matrix[4][4], double Axe[3], double alpha)
{
  double t1[3], t2[3];
  if(Axe[0] != 0.0) {
    t1[0] = 0.0;
    t1[1] = 1.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 0.0;
    t2[2] = 1.0;
  }
  else if(Axe[1] != 0.0) {
    t1[0] = 1.0;
    t1[1] = 0.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 0.0;
    t2[2] = 1.0;
  }
  else {
    t1[0] = 1.0;
    t1[1] = 0.0;
    t1[2] = 0.0;
    t2[0] = 0.0;
    t2[1] = 1.0;
    t2[2] = 0.0;
  }
  GramSchmidt(Axe, t1, t2);
  double rot[3][3], plan[3][3], invplan[3][3];
  plan[0][0] = Axe[0];
  plan[0][1] = Axe[1];
  plan[0][2] = Axe[2];
  plan[1][0] = t1[0];
  plan[1][1] = t1[1];
  plan[1][2] = t1[2];
  plan[2][0] = t2[0];
  plan[2][1] = t2[1];
  plan[2][2] = t2[2];
  rot[2][2] = cos(alpha);
  rot[2][1] = sin(alpha);
  rot[2][0] = 0.;
  rot[1][2] = -sin(alpha);
  rot[1][1] = cos(alpha);
  rot[1][0] = 0.;
  rot[0][2] = 0.;
  rot[0][1] = 0.;
  rot[0][0] = 1.;
  int i, j, k;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) invplan[i][j] = plan[j][i];
  double interm[3][3];
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      interm[i][j] = 0.0;
      for(k = 0; k < 3; k++) interm[i][j] += invplan[i][k] * rot[k][j];
    }
  for(i = 0; i < 4; i++)
    for(j = 0; j < 4; j++) matrix[i][j] = 0.0;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      for(k = 0; k < 3; k++) matrix[i][j] += interm[i][k] * plan[k][j];
    }
  matrix[3][3] = 1.0;
}

static void vecmat4x4(double mat[4][4], double vec[4], double res[4])
{
  for(int i = 0; i < 4; i++) {
    res[i] = 0.0;
    for(int j = 0; j < 4; j++) { res[i] += mat[i][j] * vec[j]; }
  }
}

static void ApplyTransformationToPointAlways(double matrix[4][4], Vertex *v)
{
  double pos[4], vec[4];
  vec[0] = v->Pos.X;
  vec[1] = v->Pos.Y;
  vec[2] = v->Pos.Z;
  vec[3] = v->w;
  vecmat4x4(matrix, vec, pos);
  v->Pos.X = pos[0];
  v->Pos.Y = pos[1];
  v->Pos.Z = pos[2];
  v->w = pos[3];
}

static void ApplyTransformationToPoint(double matrix[4][4], Vertex *v)
{
  if(!ListOfTransformedPoints)
    ListOfTransformedPoints = List_Create(50, 50, sizeof(int));

  if(!List_Search(ListOfTransformedPoints, &v->Num, fcmp_absint)) {
    List_Add(ListOfTransformedPoints, &v->Num);
  }
  else
    return;
  ApplyTransformationToPointAlways(matrix, v);
}

static void ApplyTransformationToCurve(double matrix[4][4], Curve *c)
{
  if(!c->beg || !c->end) {
    Msg::Error("Cannot transform curve with no begin/end points");
    return;
  }

  ApplyTransformationToPoint(matrix, c->beg);
  ApplyTransformationToPoint(matrix, c->end);

  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    Vertex *v;
    List_Read(c->Control_Points, i, &v);
    ApplyTransformationToPoint(matrix, v);
  }
  EndCurve(c);
}

static void ApplyTransformationToSurface(double matrix[4][4], Surface *s)
{
  for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    Curve *cc = FindCurve(abs(c->Num));
    ApplyTransformationToCurve(matrix, cc);
  }
  EndSurface(s);
}

static void ApplyTransformationToVolume(double matrix[4][4], Volume *v)
{
  for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    ApplyTransformationToSurface(matrix, s);
  }
}

static bool ApplicationOnShapes(double matrix[4][4], List_T *shapes)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  Volume *vol;
  bool ok = true;

  List_Reset(ListOfTransformedPoints);

  for(int i = 0; i < List_Nbr(shapes); i++) {
    Shape O;
    List_Read(shapes, i, &O);
    switch(O.Type) {
    case MSH_POINT:
      v = FindPoint(O.Num);
      if(v)
        ApplyTransformationToPoint(matrix, v);
      else {
        Msg::Error("Unknown GEO point with tag %d", O.Num);
        ok = false;
      }
      break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_CIRC_INV:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV:
    case MSH_SEGM_NURBS:
      c = FindCurve(O.Num);
      if(c)
        ApplyTransformationToCurve(matrix, c);
      else {
        Msg::Error("Unknown GEO curve with tag %d", O.Num);
        ok = false;
      }
      break;
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
      s = FindSurface(O.Num);
      if(s)
        ApplyTransformationToSurface(matrix, s);
      else {
        Msg::Error("Unknown GEO surface with tag %d", O.Num);
        ok = false;
      }
      break;
    case MSH_VOLUME:
      vol = FindVolume(O.Num);
      if(vol)
        ApplyTransformationToVolume(matrix, vol);
      else {
        Msg::Error("Unknown GEO volume with tag %d", O.Num);
        ok = false;
      }
      break;
    default:
      Msg::Error("Impossible to transform entity %d (of type %d)", O.Num,
                 O.Type);
      ok = false;
      break;
    }
  }

  // recompute curve parameters if control points have been transformed.
  // Warning: in theory we should always redo these checks; but in practice this
  // is so slow for big models that we need to provide a way to bypass it (which
  // is OK if the guy who builds the geometry knowns what he's doing). Instead
  // of adding one more option, let's just bypass all the checks if
  // auto_coherence==0.
  if(CTX::instance()->geom.autoCoherence) {
    List_T *All = Tree2List(GModel::current()->getGEOInternals()->Curves);
    for(int i = 0; i < List_Nbr(All); i++) {
      Curve *c;
      List_Read(All, i, &c);
      for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
        Vertex *pv = *(Vertex **)List_Pointer(c->Control_Points, j);
        if(List_Search(ListOfTransformedPoints, &pv->Num, fcmp_absint)) {
          EndCurve(c);
          break;
        }
      }
    }
    List_Delete(All);
  }

  List_Reset(ListOfTransformedPoints);

  return ok;
}

bool TranslateShapes(double X, double Y, double Z, List_T *shapes)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetTranslationMatrix(matrix, T);
  bool ok = ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence) ReplaceAllDuplicates();

  return ok;
}

bool DilatShapes(double X, double Y, double Z, double A, double B, double C,
                 List_T *shapes)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetDilatationMatrix(matrix, T, A, B, C);
  bool ok = ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence) ReplaceAllDuplicates();

  return ok;
}

bool RotateShapes(double Ax, double Ay, double Az, double Px, double Py,
                  double Pz, double alpha, List_T *shapes)
{
  double A[3], T[3], matrix[4][4];

  T[0] = -Px;
  T[1] = -Py;
  T[2] = -Pz;
  SetTranslationMatrix(matrix, T);
  bool ok = ApplicationOnShapes(matrix, shapes);

  A[0] = Ax;
  A[1] = Ay;
  A[2] = Az;
  SetRotationMatrix(matrix, A, alpha);
  ok &= ApplicationOnShapes(matrix, shapes);

  T[0] = Px;
  T[1] = Py;
  T[2] = Pz;
  SetTranslationMatrix(matrix, T);
  ok &= ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence) ReplaceAllDuplicates();

  return ok;
}

bool SymmetryShapes(double A, double B, double C, double D, List_T *shapes)
{
  double matrix[4][4];

  SetSymmetryMatrix(matrix, A, B, C, D);
  bool ok = ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence) ReplaceAllDuplicates();

  return ok;
}

class ShapeLessThan {
public:
  bool operator()(Shape *v1, Shape *v2) const
  {
    if(std::abs(v1->Num) < std::abs(v2->Num)) return true;
    return false;
  }
};

static int CompareTwoPoints(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;

  if(q->Typ != w->Typ) return q->Typ - w->Typ;

  if(q->boundaryLayerIndex != w->boundaryLayerIndex)
    return q->boundaryLayerIndex - w->boundaryLayerIndex;

  return ComparePosition(a, b);
}

static int CompareTwoCurves(const void *a, const void *b)
{
  Curve *c1 = *(Curve **)a;
  Curve *c2 = *(Curve **)b;
  int comp;

  // if two curves are discrete, assume that they are different if their tags
  // are different
  if(c1->Typ == MSH_SEGM_DISCRETE && c2->Typ == MSH_SEGM_DISCRETE) {
    return c1->Num - c2->Num;
  }

  if(c1->Typ != c2->Typ) {
    if((c1->Typ == MSH_SEGM_CIRC && c2->Typ == MSH_SEGM_CIRC_INV) ||
       (c1->Typ == MSH_SEGM_CIRC_INV && c2->Typ == MSH_SEGM_CIRC) ||
       (c1->Typ == MSH_SEGM_ELLI && c2->Typ == MSH_SEGM_ELLI_INV) ||
       (c1->Typ == MSH_SEGM_ELLI_INV && c2->Typ == MSH_SEGM_ELLI)) {
      // this is still ok
    }
    else
      return c1->Typ - c2->Typ;
  }

  if(List_Nbr(c1->Control_Points) != List_Nbr(c2->Control_Points))
    return List_Nbr(c1->Control_Points) - List_Nbr(c2->Control_Points);

  if(!List_Nbr(c1->Control_Points)) {
    if(!c1->beg || !c2->beg) return 1;
    comp = CompareVertex(&c1->beg, &c2->beg);
    if(comp) return comp;
    if(!c1->end || !c2->end) return 1;
    comp = CompareVertex(&c1->end, &c2->end);
    if(comp) return comp;
  }
  else {
    for(int i = 0; i < List_Nbr(c1->Control_Points); i++) {
      Vertex *v1, *v2;
      List_Read(c1->Control_Points, i, &v1);
      List_Read(c2->Control_Points, i, &v2);
      comp = CompareVertex(&v1, &v2);
      if(comp) return comp;
    }
  }

  // compare boundary layer curves using their source extrusion entity, which is
  // assumed to be unique; this allows to have 2 distinct boundary layer curves
  // with the same beg/end points
  if(c1->Typ == MSH_SEGM_BND_LAYER && c1->Extrude &&
     c2->Typ == MSH_SEGM_BND_LAYER && c2->Extrude) {
    int comp =
      std::abs(c1->Extrude->geo.Source) - std::abs(c2->Extrude->geo.Source);
    if(comp) return comp;
  }

  return 0;
}

static int CompareTwoSurfaces(const void *a, const void *b)
{
  Surface *s1 = *(Surface **)a;
  Surface *s2 = *(Surface **)b;

  // if two surface are discrete, assume that they are different if their tags
  // are different
  if(s1->Typ == MSH_SURF_DISCRETE && s2->Typ == MSH_SURF_DISCRETE) {
    return s1->Num - s2->Num;
  }

  // checking types is the "right thing" to do (see e.g. CompareTwoCurves)
  // but it would break backward compatibility (see e.g. tutorial/t2.geo),
  // so let's just do it for boundary layer surfaces for now:
  if(s1->Typ == MSH_SURF_BND_LAYER || s2->Typ == MSH_SURF_BND_LAYER) {
    if(s1->Typ != s2->Typ) return s1->Typ - s2->Typ;
  }

  // if both surfaces have no generatrices, stay on the safe side and
  // assume they are different
  if(!List_Nbr(s1->Generatrices) && !List_Nbr(s2->Generatrices)) return 1;

  return Compare2Lists(s1->Generatrices, s2->Generatrices, CompareAbsCurve);
}

static void MaxNumPoint(void *a, void *b)
{
  Vertex *v = *(Vertex **)a;
  GModel::current()->getGEOInternals()->setMaxTag(
    0, std::max(GModel::current()->getGEOInternals()->getMaxTag(0), v->Num));
}

static void MaxNumCurve(void *a, void *b)
{
  Curve *c = *(Curve **)a;
  GModel::current()->getGEOInternals()->setMaxTag(
    1, std::max(GModel::current()->getGEOInternals()->getMaxTag(1), c->Num));
}

static void MaxNumSurface(void *a, void *b)
{
  Surface *s = *(Surface **)a;
  GModel::current()->getGEOInternals()->setMaxTag(
    2, std::max(GModel::current()->getGEOInternals()->getMaxTag(2), s->Num));
}

static void ReplaceDuplicatePointsNew(double tol = -1.)
{
  Msg::Info("New Coherence...");
  if(tol < 0) tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;

  // create rtree
  MVertexRTree pos(tol);
  std::map<MVertex *, Vertex *> v2V;
  std::vector<MVertex *> used, unused;
  List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Points);
  for(int i = 0; i < List_Nbr(tmp); i++) {
    Vertex *V;
    List_Read(tmp, i, &V);
    MVertex *v = new MVertex(V->Pos.X, V->Pos.Y, V->Pos.Z);
    if(!pos.insert(v))
      used.push_back(v);
    else
      unused.push_back(v);
    v2V[v] = V;
  }
  List_Delete(tmp);

  // replace points in curves
  tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(tmp); i++) {
    Curve *c;
    List_Read(tmp, i, &c);
    // replace begin/end points
    c->beg = v2V[pos.find(c->beg->Pos.X, c->beg->Pos.Y, c->beg->Pos.Z)];
    c->end = v2V[pos.find(c->end->Pos.X, c->end->Pos.Y, c->end->Pos.Z)];

    // replace control points
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      Vertex *V;
      List_Read(c->Control_Points, j, &V);
      List_Write(c->Control_Points, j,
                 &v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]);
    }
    // replace extrusion sources
    if(c->Extrude && c->Extrude->geo.Mode == EXTRUDED_ENTITY) {
      Vertex *V = FindPoint(std::abs(c->Extrude->geo.Source));
      if(V)
        c->Extrude->geo.Source =
          v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]->Num;
    }
  }
  List_Delete(tmp);

  // replace points in surfaces
  tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(tmp); i++) {
    Surface *s;
    List_Read(tmp, i, &s);
    // replace transfinite corners
    for(int j = 0; j < List_Nbr(s->TrsfPoints); j++) {
      Vertex *V;
      List_Read(s->TrsfPoints, j, &V);
      List_Write(s->TrsfPoints, j,
                 &v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]);
    }
  }
  List_Delete(tmp);

  // replace points in volumes
  tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(tmp); i++) {
    Volume *vol;
    List_Read(tmp, i, &vol);
    // replace transfinite corners
    for(int j = 0; j < List_Nbr(vol->TrsfPoints); j++) {
      Vertex *V;
      List_Read(vol->TrsfPoints, j, &V);
      List_Write(vol->TrsfPoints, j,
                 &v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]);
    }
  }
  List_Delete(tmp);

  // replace points in physical groups
  for(int i = 0;
      i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++) {
    PhysicalGroup *p;
    List_Read(GModel::current()->getGEOInternals()->PhysicalGroups, i, &p);
    if(p->Typ == MSH_PHYSICAL_POINT) {
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        int num;
        List_Read(p->Entities, j, &num);
        Vertex *V = FindPoint(std::abs(num));
        if(V)
          List_Write(p->Entities, j,
                     &(v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]->Num));
      }
    }
  }

  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Points);
  for(std::size_t i = 0; i < unused.size(); i++) {
    Vertex *V = v2V[unused[i]];
    Tree_Suppress(GModel::current()->getGEOInternals()->Points, &V);
    Tree_Add(GModel::current()->getGEOInternals()->DelPoints, &V);
    delete unused[i];
  }
  for(std::size_t i = 0; i < used.size(); i++) { delete used[i]; }
  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Points);
  Msg::Info("Done new Coherence (removed %d additional points)", start - end);
}

static void ReplaceDuplicatePoints(std::map<int, int> *v_report = nullptr)
{
  // This routine is logically wrong: the CompareTwoPoints() function used in
  // the avl tree is not an appropriate comparison function. Fixing the routine
  // is easy (we need to a multi-dimensional tree), but it would break backward
  // compatibility with old .geo files (the point ids after "Coherence" would
  // change, as which point gets removed is implementation-dependent).
  //
  // Instead, we still use this routine, but call the new one if an error is
  // detected.

  Vertex *v, *v2, **pv, **pv2;
  Curve *c;
  Surface *s;
  Volume *vol;
  Tree_T *points2delete = Tree_Create(sizeof(Vertex *), CompareVertex);
  Tree_T *allNonDuplicatedPoints =
    Tree_Create(sizeof(Vertex *), CompareTwoPoints);

  // Create unique points
  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Points);

  List_T *All = Tree2List(GModel::current()->getGEOInternals()->Points);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &v);
    if(!Tree_Search(allNonDuplicatedPoints, &v)) {
      Tree_Insert(allNonDuplicatedPoints, &v);
    }
    else {
      Tree_Suppress(GModel::current()->getGEOInternals()->Points, &v);
      Tree_Insert(points2delete, &v);
      if(v_report) { // keep track of changes
        auto m_it = v_report->find(v->Num);
        if(m_it != v_report->end()) {
          Vertex **v_rep = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v);
          if(v_rep) m_it->second = (*v_rep)->Num;
        }
      }
    }
  }
  List_Delete(All);

  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Points);
  if(start == end) {
    Tree_Delete(points2delete);
    Tree_Delete(allNonDuplicatedPoints);
    return;
  }

  Msg::Debug("Removed %d duplicate points", start - end);

  if(CTX::instance()->geom.oldNewreg) {
    GModel::current()->getGEOInternals()->setMaxTag(0, 0);
    Tree_Action(GModel::current()->getGEOInternals()->Points, MaxNumPoint);
  }

  bool success = true;

  // Replace old points in curves
  All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    // replace begin/end points
    if(c->beg && !Tree_Query(allNonDuplicatedPoints, &c->beg)) {
      Msg::Debug("Could not replace point %d in old Coherence", c->beg->Num);
      Tree_Insert(GModel::current()->getGEOInternals()->Points, &c->beg);
      Tree_Suppress(points2delete, &c->beg);
      success = false;
    }
    if(c->end && !Tree_Query(allNonDuplicatedPoints, &c->end)) {
      Msg::Debug("Could not replace point %d in old Coherence", c->end->Num);
      Tree_Insert(GModel::current()->getGEOInternals()->Points, &c->end);
      Tree_Suppress(points2delete, &c->end);
      success = false;
    }
    // replace control points
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      pv = (Vertex **)List_Pointer(c->Control_Points, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))) {
        Msg::Debug("Could not replace point %d in old Coherence", (*pv)->Num);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, pv);
        Tree_Suppress(points2delete, pv);
        success = false;
      }
      else
        List_Write(c->Control_Points, j, pv2);
    }
    // replace extrusion sources
    if(c->Extrude && c->Extrude->geo.Mode == EXTRUDED_ENTITY) {
      v2 = FindPoint(std::abs(c->Extrude->geo.Source), points2delete);
      if(v2) {
        if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v2))) {
          Msg::Debug("Could not replace point %d in old Coherence", v2->Num);
          Tree_Insert(GModel::current()->getGEOInternals()->Points, &v2);
          Tree_Suppress(points2delete, &v2);
          success = false;
        }
        else
          c->Extrude->geo.Source = (*pv2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old points in surfaces
  All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    // replace transfinite corners
    for(int j = 0; j < List_Nbr(s->TrsfPoints); j++) {
      pv = (Vertex **)List_Pointer(s->TrsfPoints, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))) {
        Msg::Debug("Could not replace point %d in old Coherence", (*pv)->Num);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, pv);
        Tree_Suppress(points2delete, pv);
        success = false;
      }
      else
        List_Write(s->TrsfPoints, j, pv2);
    }
  }
  List_Delete(All);

  // Replace old points in volumes
  All = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &vol);
    // replace transfinite corners
    for(int j = 0; j < List_Nbr(vol->TrsfPoints); j++) {
      pv = (Vertex **)List_Pointer(vol->TrsfPoints, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))) {
        Msg::Debug("Could not replace point %d in old Coherence", (*pv)->Num);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, pv);
        Tree_Suppress(points2delete, pv);
        success = false;
      }
      else
        List_Write(vol->TrsfPoints, j, pv2);
    }
  }
  List_Delete(All);

  // Replace old points in physical groups
  for(int i = 0;
      i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++) {
    PhysicalGroup *p = *(PhysicalGroup **)List_Pointer(
      GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_POINT) {
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        int num;
        List_Read(p->Entities, j, &num);
        v2 = FindPoint(std::abs(num), points2delete);
        if(v2) {
          if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v2))) {
            Msg::Debug("Could not replace point %d in old Coherence", v2->Num);
            Tree_Insert(GModel::current()->getGEOInternals()->Points, &v2);
            Tree_Suppress(points2delete, &v2);
            success = false;
          }
          else
            List_Write(p->Entities, j, &(*pv2)->Num);
        }
      }
    }
  }

  List_T *tmp = Tree2List(points2delete);
  for(int i = 0; i < List_Nbr(tmp); i++)
    Tree_Add(GModel::current()->getGEOInternals()->DelPoints,
             List_Pointer(tmp, i));
  List_Delete(tmp);
  Tree_Delete(points2delete);
  Tree_Delete(allNonDuplicatedPoints);

  if(!success) ReplaceDuplicatePointsNew();
}

static void ReplaceDuplicateCurves(std::map<int, int> *c_report = nullptr)
{
  Curve *c, *c2, **pc, **pc2;
  Surface *s;
  Tree_T *curves2delete = Tree_Create(sizeof(Curve *), CompareCurve);
  Tree_T *allNonDuplicatedCurves =
    Tree_Create(sizeof(Curve *), CompareTwoCurves);

  // Create unique curves
  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Curves);

  List_T *All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    if(c->Num > 0) {
      if(!Tree_Search(allNonDuplicatedCurves, &c)) {
        Tree_Insert(allNonDuplicatedCurves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg::Error("Unknown GEO curve with tag %d", -c->Num);
          List_Delete(All);
          List_T *tmp = Tree2List(curves2delete);
          for(int i = 0; i < List_Nbr(tmp); i++)
            Tree_Add(GModel::current()->getGEOInternals()->DelCurves,
                     List_Pointer(tmp, i));
          List_Delete(tmp);
          Tree_Delete(curves2delete);
          Tree_Delete(allNonDuplicatedCurves);
          return;
        }
        Tree_Insert(allNonDuplicatedCurves, &c2);
      }
      else {
        Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg::Error("Unknown GEO curve with tag %d", -c->Num);
          break;
        }
        Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c2);
        Tree_Insert(curves2delete, &c);
        Tree_Insert(curves2delete, &c2);

        if(c_report) { // keep track of changes
          auto m_it = c_report->find(c->Num);
          if(m_it != c_report->end()) {
            Curve **c_rep = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c);
            if(c_rep) m_it->second = (*c_rep)->Num;
          }
          m_it = c_report->find(c2->Num);
          if(m_it != c_report->end()) {
            Curve **c_rep_neg =
              (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2);
            if(c_rep_neg) m_it->second = (*c_rep_neg)->Num;
          }
        }
      }
    }
  }
  List_Delete(All);

  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Curves);

  if(start == end) {
    List_T *tmp = Tree2List(curves2delete);
    for(int i = 0; i < List_Nbr(tmp); i++)
      Tree_Add(GModel::current()->getGEOInternals()->DelCurves,
               List_Pointer(tmp, i));
    List_Delete(tmp);
    Tree_Delete(curves2delete);
    Tree_Delete(allNonDuplicatedCurves);
    return;
  }

  Msg::Debug("Removed %d duplicate curves", start - end);

  if(CTX::instance()->geom.oldNewreg) {
    GModel::current()->getGEOInternals()->setMaxTag(1, 0);
    Tree_Action(GModel::current()->getGEOInternals()->Curves, MaxNumCurve);
  }

  // Replace old curves in curves
  All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    // replace extrusion sources
    if(c->Extrude && c->Extrude->geo.Mode == COPIED_ENTITY) {
      c2 = FindCurve(std::abs(c->Extrude->geo.Source), curves2delete);
      if(c2) {
        if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
          Msg::Error("Could not replace GEO curve with tag %d in Coherence",
                     c2->Num);
        else
          c->Extrude->geo.Source = (*pc2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old curves in surfaces
  All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    // replace bounding curves
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      pc = (Curve **)List_Pointer(s->Generatrices, j);
      if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, pc)))
        Msg::Error("Could not replace GEO curve with tag %d in Coherence",
                   (*pc)->Num);
      else {
        List_Write(s->Generatrices, j, pc2);
        // arghhh: check CompareTwoCurves!
        EndCurve(*pc2);
      }
    }
    // replace extrusion sources
    if(s->Extrude && s->Extrude->geo.Mode == EXTRUDED_ENTITY) {
      c2 = FindCurve(std::abs(s->Extrude->geo.Source), curves2delete);
      if(c2) {
        if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
          Msg::Error("Could not replace GEO curve with tag %d in Coherence",
                     c2->Num);
        else
          s->Extrude->geo.Source = (*pc2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old curves in physical groups
  for(int i = 0;
      i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++) {
    PhysicalGroup *p = *(PhysicalGroup **)List_Pointer(
      GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_LINE) {
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        int num;
        List_Read(p->Entities, j, &num);
        c2 = FindCurve(std::abs(num), curves2delete);
        if(c2) {
          if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
            Msg::Error("Could not replace GEO curve with tag %d in Coherence",
                       c2->Num);
          else
            List_Write(p->Entities, j, &(*pc2)->Num);
        }
      }
    }
  }

  List_T *tmp = Tree2List(curves2delete);
  for(int i = 0; i < List_Nbr(tmp); i++)
    Tree_Add(GModel::current()->getGEOInternals()->DelCurves,
             List_Pointer(tmp, i));
  List_Delete(tmp);
  Tree_Delete(curves2delete);
  Tree_Delete(allNonDuplicatedCurves);
}

/*
  1) Find duplicate points and replace in curves
  2) Find duplicate curves and replace in surfaces
  3) Find duplicate surfaces and replace in volumes

--> some curves are degenerate (zero length)
--> some surfaces are degenerate (zero surface)
--> some volumes are degenerate (zero volume)

*/

static void RemoveDegenerateCurves()
{
  { // remove degenerate curves from surface generatrices
    List_T *All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
    for(int i = 0; i < List_Nbr(All); i++) {
      Surface *s;
      List_Read(All, i, &s);
      List_T *ll = s->Generatrices;
      s->Generatrices = List_Create(4, 1, sizeof(Curve *));
      // List_Delete(s->GeneratricesByTag);
      // s->GeneratricesByTag = List_Create(4, 1, sizeof(int));
      for(int j = 0; j < List_Nbr(ll); j++) {
        Curve *c;
        List_Read(ll, j, &c);
        if(!c->degenerate()) {
          List_Add(s->Generatrices, &c);
          // List_Add(s->GeneratricesByTag, &c->Num);
        }
      }
      if(List_Nbr(ll) != List_Nbr(s->Generatrices))
        Msg::Info("Coherence: surface %d goes from %d to %d boundary edges",
                  s->Num, List_Nbr(ll), List_Nbr(s->Generatrices));
      List_Delete(ll);
    }
  }

  { // actually remove the curves
    List_T *All = Tree2List(GModel::current()->getGEOInternals()->Curves);
    for(int i = 0; i < List_Nbr(All); i++) {
      Curve *c;
      List_Read(All, i, &c);
      if(c->degenerate()) {
        DeleteCurve(c->Num);
        DeleteCurve(-c->Num);
      }
    }
  }
}

static void RemoveDegenerateVolumes()
{
  List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int k = 0; k < List_Nbr(Vols); k++) {
    Volume *v;
    List_Read(Vols, k, &v);
    std::set<int> unique;
    int N = List_Nbr(v->Surfaces);
    for(int j = 0; j < N; j++) {
      Surface *s;
      List_Read(v->Surfaces, j, &s);
      auto it = unique.find(-s->Num);
      if(it == unique.end())
        unique.insert(s->Num);
      else
        unique.erase(it);
    }
    if(N - unique.size())
      Msg::Info("Coherence: removing %d seams on volume %d", N - unique.size(),
                v->Num);

    List_T *ll = v->Surfaces;
    List_T *ll2 = v->SurfacesOrientations;
    v->Surfaces = List_Create(1, 2, sizeof(Surface *));
    v->SurfacesOrientations = List_Create(1, 2, sizeof(int));
    for(int j = 0; j < List_Nbr(ll); j++) {
      Surface *s;
      List_Read(ll, j, &s);
      if(unique.find(s->Num) != unique.end()) {
        List_Add(v->Surfaces, &s);
        List_Add(v->SurfacesOrientations, List_Pointer(ll2, j));
      }
    }
    List_Delete(ll);
    List_Delete(ll2);
    if(List_Nbr(v->Surfaces) == 0) {
      Msg::Info("Coherence: volume %d is removed (degenerated)", v->Num);
      DeleteVolume(v->Num);
    }
  }
}

static void RemoveDegenerateSurfaces()
{
  List_T *All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);

  for(int i = 0; i < List_Nbr(All); i++) {
    Surface *s;
    std::set<int> unique;
    List_Read(All, i, &s);
    int N = List_Nbr(s->Generatrices);
    for(int j = 0; j < N; j++) {
      Curve *c;
      List_Read(s->Generatrices, j, &c);
      auto it = unique.find(-c->Num);
      if(it == unique.end())
        unique.insert(c->Num);
      else
        unique.erase(it);
    }

    if(N - unique.size())
      Msg::Info("Coherence: removing %d seams on surface %d", N - unique.size(),
                s->Num);

    List_T *ll = s->Generatrices;
    s->Generatrices = List_Create(4, 1, sizeof(Curve *));
    // List_Delete(s->GeneratricesByTag);
    // s->GeneratricesByTag = List_Create(4, 1, sizeof(int));
    for(int j = 0; j < List_Nbr(ll); j++) {
      Curve *c;
      List_Read(ll, j, &c);
      if(unique.find(c->Num) != unique.end()) {
        List_Add(s->Generatrices, &c);
        // List_Add(s->GeneratricesByTag, &c->Num);
      }
    }
    List_Delete(ll);

    if(s->degenerate()) {
      Msg::Info("Coherence: surfface %d is removed (degenerated)", s->Num);
      List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
      for(int k = 0; k < List_Nbr(Vols); k++) {
        Volume *v;
        List_Read(Vols, k, &v);
        List_T *ll = v->Surfaces;
        List_T *ll2 = v->SurfacesOrientations;
        v->Surfaces = List_Create(1, 2, sizeof(Surface *));
        v->SurfacesOrientations = List_Create(1, 2, sizeof(int));
        for(int j = 0; j < List_Nbr(ll); j++) {
          if(CompareSurface(List_Pointer(ll, j), &s)) {
            List_Add(v->Surfaces, List_Pointer(ll, j));
            List_Add(v->SurfacesOrientations, List_Pointer(ll2, j));
          }
        }
        List_Delete(ll);
        List_Delete(ll2);
      }
      DeleteSurface(s->Num);
    }
  }
}

bool Surface::degenerate() const
{
  int N = List_Nbr(Generatrices);
  int Nd = 0;
  for(int i = 0; i < N; i++) {
    Curve *c;
    List_Read(Generatrices, i, &c);
    if(!c->degenerate()) Nd++;
  }
  return Nd == 0;
}

static void ReplaceDuplicateSurfaces(std::map<int, int> *s_report = nullptr)
{
  Surface *s, *s2, **ps, **ps2;
  Volume *vol;
  Tree_T *surfaces2delete = Tree_Create(sizeof(Surface *), CompareSurface);
  Tree_T *allNonDuplicatedSurfaces =
    Tree_Create(sizeof(Surface *), CompareTwoSurfaces);

  // Create unique surfaces
  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Surfaces);

  List_T *All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    if(s->Num > 0) {
      if(!Tree_Search(allNonDuplicatedSurfaces, &s)) {
        Tree_Insert(allNonDuplicatedSurfaces, &s);
      }
      else {
        Tree_Suppress(GModel::current()->getGEOInternals()->Surfaces, &s);
        Tree_Insert(surfaces2delete, &s);

        if(s_report) { // keep track of changes
          auto m_it = (*s_report).find(s->Num);
          if(m_it != s_report->end()) {
            Surface **s_rep =
              (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s);
            if(s_rep) m_it->second = (*s_rep)->Num;
          }
        }
      }
    }
  }
  List_Delete(All);

  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Surfaces);

  if(start == end) {
    List_T *tmp = Tree2List(surfaces2delete);
    for(int i = 0; i < List_Nbr(tmp); i++)
      Tree_Add(GModel::current()->getGEOInternals()->DelSurfaces,
               List_Pointer(tmp, i));
    List_Delete(tmp);
    Tree_Delete(surfaces2delete);
    Tree_Delete(allNonDuplicatedSurfaces);
    return;
  }

  Msg::Debug("Removed %d duplicate surfaces", start - end);

  if(CTX::instance()->geom.oldNewreg) {
    GModel::current()->getGEOInternals()->setMaxTag(2, 0);
    Tree_Action(GModel::current()->getGEOInternals()->Surfaces, MaxNumSurface);
  }

  // Replace old surfaces in surfaces
  All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    // replace extrusion sources
    if(s->Extrude && s->Extrude->geo.Mode == COPIED_ENTITY) {
      s2 = FindSurface(std::abs(s->Extrude->geo.Source), surfaces2delete);
      if(s2) {
        if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s2)))
          Msg::Error("Could not replace surface %d in Coherence", s2->Num);
        else
          s->Extrude->geo.Source = (*ps2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old surfaces in volumes
  All = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &vol);
    // replace bounding surfaces
    for(int j = 0; j < List_Nbr(vol->Surfaces); j++) {
      ps = (Surface **)List_Pointer(vol->Surfaces, j);
      if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, ps)))
        Msg::Error("Could not replace surface %d in Coherence", (*ps)->Num);
      else
        List_Write(vol->Surfaces, j, ps2);
    }
    // replace extrusion sources
    if(vol->Extrude && vol->Extrude->geo.Mode == EXTRUDED_ENTITY) {
      s2 = FindSurface(std::abs(vol->Extrude->geo.Source), surfaces2delete);
      if(s2) {
        if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s2)))
          Msg::Error("Could not replace surface %d in Coherence", s2->Num);
        else
          vol->Extrude->geo.Source = (*ps2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old surfaces in physical groups
  for(int i = 0;
      i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++) {
    PhysicalGroup *p = *(PhysicalGroup **)List_Pointer(
      GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_SURFACE) {
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        int num;
        List_Read(p->Entities, j, &num);
        s2 = FindSurface(std::abs(num), surfaces2delete);
        if(s2) {
          if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s2)))
            Msg::Error("Could not replace surface %d in Coherence", s2->Num);
          else
            List_Write(p->Entities, j, &(*ps2)->Num);
        }
      }
    }
  }

  List_T *tmp = Tree2List(surfaces2delete);
  for(int i = 0; i < List_Nbr(tmp); i++)
    Tree_Add(GModel::current()->getGEOInternals()->DelSurfaces,
             List_Pointer(tmp, i));
  List_Delete(tmp);
  Tree_Delete(surfaces2delete);
  Tree_Delete(allNonDuplicatedSurfaces);
}

static void ReplaceAllDuplicates(std::vector<std::map<int, int> > &report)
{
  std::map<int, int> *vertex_report = nullptr;
  std::map<int, int> *curve_report = nullptr;
  std::map<int, int> *surface_report = nullptr;
  if(report.size() >= 1 && report[0].size()) vertex_report = &(report[0]);
  if(report.size() >= 2 && report[1].size()) curve_report = &(report[1]);
  if(report.size() >= 3 && report[2].size()) surface_report = &(report[2]);

  ReplaceDuplicatePoints(vertex_report);
  ReplaceDuplicateCurves(curve_report);
  ReplaceDuplicateSurfaces(surface_report);

  if(CTX::instance()->geom.autoCoherence == 2) {
    RemoveDegenerateCurves();
    RemoveDegenerateSurfaces();
    RemoveDegenerateVolumes();
  }
}

void ReplaceAllDuplicates()
{
  std::vector<std::map<int, int> > report;
  report.clear();
  ReplaceAllDuplicates(report);
}

void ReplaceAllDuplicatesNew(double tol)
{
  if(tol < 0) tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;
  ReplaceDuplicatePointsNew(tol);
  ReplaceDuplicateCurves(nullptr);
  ReplaceDuplicateSurfaces(nullptr);
}

void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams *e)
{
  double matrix[4][4];
  double T[3];
  Vertex v(x, y, z);

  T[0] = -e->geo.pt[0];
  T[1] = -e->geo.pt[1];
  T[2] = -e->geo.pt[2];
  SetTranslationMatrix(matrix, T);
  ApplyTransformationToPointAlways(matrix, &v);

  SetRotationMatrix(matrix, e->geo.axe, e->geo.angle);
  ApplyTransformationToPointAlways(matrix, &v);

  T[0] = -T[0];
  T[1] = -T[1];
  T[2] = -T[2];
  SetTranslationMatrix(matrix, T);
  ApplyTransformationToPointAlways(matrix, &v);

  x = v.Pos.X;
  y = v.Pos.Y;
  z = v.Pos.Z;

  List_Reset(ListOfTransformedPoints);
}

int ExtrudePoint(int type, int ip, double T0, double T1, double T2, double A0,
                 double A1, double A2, double X0, double X1, double X2,
                 double alpha, Curve **pc, Curve **prc, int final,
                 ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3], d;
  Vertex V, *newp = nullptr;
  Curve *c = nullptr;
  int i;
  bool ok = true;

  Vertex *pv = &V;
  pv->Num = ip;
  *pc = *prc = nullptr;
  if(!Tree_Query(GModel::current()->getGEOInternals()->Points, &pv)) return 0;

  Msg::Debug("Extrude Point %d", ip);

  Vertex *chapeau = DuplicateVertex(pv);

  switch(type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);
    if(!ComparePosition(&pv, &chapeau)) return pv->Num;
    c = CreateCurve(NEWLINE(), MSH_SEGM_LINE, 1, nullptr, nullptr, -1, -1, 0.,
                    1., ok);
    c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e) c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;
  case BOUNDARY_LAYER:
    chapeau->Typ = MSH_POINT_BND_LAYER;
    if(e) chapeau->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    c = CreateCurve(NEWLINE(), MSH_SEGM_BND_LAYER, 1, nullptr, nullptr, -1, -1,
                    0., 1., ok);
    c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e) c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;
  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);
    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);
    if(!ComparePosition(&pv, &chapeau)) return pv->Num;
    c = CreateCurve(NEWLINE(), MSH_SEGM_CIRC, 1, nullptr, nullptr, -1, -1, 0.,
                    1., ok);
    c->Control_Points = List_Create(3, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e) c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    // compute circle center
    newp = DuplicateVertex(pv);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    norme(Ax);
    T[0] = pv->Pos.X - X0;
    T[1] = pv->Pos.Y - X1;
    T[2] = pv->Pos.Z - X2;
    d = prosca(T, Ax);
    newp->Pos.X = X0 + d * Ax[0];
    newp->Pos.Y = X1 + d * Ax[1];
    newp->Pos.Z = X2 + d * Ax[2];
    List_Add(c->Control_Points, &newp);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;
  case TRANSLATE_ROTATE:
    d = CTX::instance()->geom.extrudeSplinePoints;
    d = d ? d : 1;
    c = CreateCurve(NEWLINE(), MSH_SEGM_SPLN, 1, nullptr, nullptr, -1, -1, 0.,
                    1., ok);
    c->Control_Points = List_Create(
      CTX::instance()->geom.extrudeSplinePoints + 1, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e) c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    c->beg = pv;
    for(i = 0; i < CTX::instance()->geom.extrudeSplinePoints; i++) {
      if(i) chapeau = DuplicateVertex(chapeau);
      T[0] = -X0;
      T[1] = -X1;
      T[2] = -X2;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);
      Ax[0] = A0;
      Ax[1] = A1;
      Ax[2] = A2;
      SetRotationMatrix(matrix, Ax, alpha / d);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);
      T[0] = X0;
      T[1] = X1;
      T[2] = X2;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);
      T[0] = T0 / d;
      T[1] = T1 / d;
      T[2] = T2 / d;
      SetTranslationMatrix(matrix, T);
      List_Reset(ListOfTransformedPoints);
      ApplyTransformationToPoint(matrix, chapeau);
      List_Add(c->Control_Points, &chapeau);
    }
    c->end = chapeau;
    break;
  default: Msg::Error("Unknown extrusion type"); return pv->Num;
  }

  EndCurve(c);
  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
  *pc = c;
  *prc = FindCurve(-c->Num);

  List_Reset(ListOfTransformedPoints);

  int chap_num = chapeau->Num;
  int body_num = c->Num;

  if(CTX::instance()->geom.autoCoherence && final) {
    std::vector<std::map<int, int> > report(3);
    report[0][chap_num] = chap_num;
    report[1][body_num] = body_num;
    ReplaceAllDuplicates(report);
    auto m_it = report[0].find(chap_num);
    if(m_it != report[0].end())
      chap_num = report[0][chap_num];
    else
      chap_num = 0;
    if(report[1][body_num] != body_num) *pc = *prc = nullptr;
  }
  return chap_num;
}

int ExtrudeCurve(int type, int ic, double T0, double T1, double T2, double A0,
                 double A1, double A2, double X0, double X1, double X2,
                 double alpha, Surface **ps, int final, ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *CurveBeg, *CurveEnd;
  Curve *ReverseChapeau, *ReverseBeg, *ReverseEnd;
  Curve *pc, *revpc, *chapeau;
  Surface *s;

  pc = FindCurve(ic);
  revpc = FindCurve(-ic);
  *ps = nullptr;

  if(!pc || !revpc) { return 0; }

  if(!pc->beg || !pc->end) {
    Msg::Error("Cannot extrude curve with no begin/end points");
    return 0;
  }

  if(pc->beg == pc->end && type != BOUNDARY_LAYER) {
    Msg::Warning("Extrusion of periodic curves is not supported with the "
                 "built-in kernel");
  }

  Msg::Debug("Extrude Curve %d", ic);

  chapeau = DuplicateCurve(pc);

  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = pc->Num;
  if(e) chapeau->Extrude->mesh = e->mesh;

  switch(type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  case BOUNDARY_LAYER:
    chapeau->Typ = MSH_SEGM_BND_LAYER;
    if(chapeau->beg) {
      chapeau->beg->Typ = MSH_POINT_BND_LAYER;
      if(e) chapeau->beg->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    if(chapeau->end) {
      chapeau->end->Typ = MSH_POINT_BND_LAYER;
      if(e) chapeau->end->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    for(int i = 0; i < List_Nbr(chapeau->Control_Points); i++) {
      Vertex *v;
      List_Read(chapeau->Control_Points, i, &v);
      if(e) v->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    revpc = FindCurve(-chapeau->Num);
    if(revpc) {
      revpc->Typ = MSH_SEGM_BND_LAYER;
      if(chapeau->Extrude) {
        revpc->Extrude = new ExtrudeParams;
        revpc->Extrude->geo = chapeau->Extrude->geo;
      }
    }
    break;
  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  case TRANSLATE_ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToCurve(matrix, chapeau);
    break;
  default: Msg::Error("Unknown extrusion type"); return pc->Num;
  }

  ExtrudePoint(type, pc->beg->Num, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha,
               &CurveBeg, &ReverseBeg, 0, e);
  ExtrudePoint(type, pc->end->Num, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha,
               &CurveEnd, &ReverseEnd, 0, e);

  if(!CurveBeg && !CurveEnd) { return pc->Num; }

  // FIXME: if we extrude by rotation a (non-straight) curve defined by 2 end
  // points, with a rotation axis going through the end points, the resulting
  // surface would have 2 bounding edges (the axis and the curve). We cannot
  // handle this case.

  if(type == BOUNDARY_LAYER)
    s = CreateSurface(NEWSURFACE(), MSH_SURF_BND_LAYER);
  else if(!CurveBeg || !CurveEnd)
    s = CreateSurface(NEWSURFACE(), MSH_SURF_TRIC);
  else
    s = CreateSurface(NEWSURFACE(), MSH_SURF_REGL);

  s->Generatrices = List_Create(4, 1, sizeof(Curve *));
  s->Extrude = new ExtrudeParams;
  s->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  s->Extrude->geo.Source = pc->Num;
  if(e) s->Extrude->mesh = e->mesh;

  ReverseChapeau = FindCurve(-chapeau->Num);

  if(!CurveBeg) {
    List_Add(s->Generatrices, &pc);
    List_Add(s->Generatrices, &CurveEnd);
    List_Add(s->Generatrices, &ReverseChapeau);
  }
  else if(!CurveEnd) {
    List_Add(s->Generatrices, &ReverseChapeau);
    List_Add(s->Generatrices, &ReverseBeg);
    List_Add(s->Generatrices, &pc);
  }
  else {
    List_Add(s->Generatrices, &pc);
    List_Add(s->Generatrices, &CurveEnd);
    List_Add(s->Generatrices, &ReverseChapeau);
    List_Add(s->Generatrices, &ReverseBeg);
  }

  EndSurface(s);
  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);

  List_Reset(ListOfTransformedPoints);

  *ps = s;

  int chap_num = chapeau->Num;
  int body_num = s->Num;

  if(CTX::instance()->geom.autoCoherence && final) {
    std::vector<std::map<int, int> > report(3);
    report[1][chap_num] = chap_num;
    report[2][body_num] = body_num;
    ReplaceAllDuplicates(report);
    auto m_it = report[1].find(chap_num);
    if(m_it != report[1].end())
      chap_num = report[1][chap_num];
    else
      chap_num = 0;
    if(report[2][body_num] != body_num) *ps = nullptr;
  }

  return chap_num;
}

int ExtrudeSurface(int type, int is, double T0, double T1, double T2, double A0,
                   double A1, double A2, double X0, double X1, double X2,
                   double alpha, Volume **pv, ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *c, *c2;
  int i;
  Surface *s, *ps, *chapeau;

  *pv = nullptr;

  // 'is' can be negative, to signify that the surface orientation
  // should be reversed. This orientation information is only used at
  // the moment when creating boundary layers
  if(!(ps = FindSurface(std::abs(is)))) return 0;

  Msg::Debug("Extrude Surface %d", is);

  chapeau = DuplicateSurface(ps);
  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = is; // not ps->Num: we need the sign info
  if(e) chapeau->Extrude->mesh = e->mesh;

  for(i = 0; i < List_Nbr(chapeau->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c2);
    List_Read(chapeau->Generatrices, i, &c);
    c->Extrude = new ExtrudeParams(COPIED_ENTITY);
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    // don't take the abs(): the sign of c2->Num is important (used when copying
    // the mesh in the extrusion routine)
    c->Extrude->geo.Source = c2->Num;
    if(e) c->Extrude->mesh = e->mesh;

    Curve *revc = FindCurve(-c->Num);
    if(!revc) {
      Msg::Error("Unknown GEO curve with tag %d", -c->Num);
      return ps->Num;
    }
    revc->Extrude = new ExtrudeParams(COPIED_ENTITY);
    revc->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    revc->Extrude->geo.Source = c2->Num;
    if(e) c->Extrude->mesh = e->mesh;
  }

  // FIXME: this is a really ugly hack for backward compatibility, so that we
  // don't screw up the old .geo files too much. (Before version 1.54, we didn't
  // always create new volumes during "Extrude Surface". Now we do, but with
  // "CTX::instance()->geom.oldNewreg==1", this bumps the NEWREG() counter, and
  // thus changes the whole automatic numbering sequence.) So we locally force
  // oldNewreg to 0: in most cases, since we define points, curves, etc., before
  // defining volumes, the NEWVOLUME() call below will return a fairly low
  // number, that will not interfere with the other numbers...
  int tmp = CTX::instance()->geom.oldNewreg;
  CTX::instance()->geom.oldNewreg = 0;
  Volume *v = CreateVolume(NEWVOLUME(), MSH_VOLUME);
  CTX::instance()->geom.oldNewreg = tmp;

  v->Extrude = new ExtrudeParams;
  v->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  v->Extrude->geo.Source = is;
  if(e) v->Extrude->mesh = e->mesh;
  int ori = -1;
  List_Add(v->Surfaces, &ps);
  List_Add(v->SurfacesOrientations, &ori);
  ori = 1;
  List_Add(v->Surfaces, &chapeau);
  List_Add(v->SurfacesOrientations, &ori);

  for(i = 0; i < List_Nbr(ps->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c);
    ExtrudeCurve(type, c->Num, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha, &s, 0,
                 e);
    if(s) {
      if(c->Num < 0)
        ori = -1;
      else
        ori = 1;
      List_Add(v->Surfaces, &s);
      List_Add(v->SurfacesOrientations, &ori);
    }
  }

  switch(type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  case BOUNDARY_LAYER:
    chapeau->Typ = MSH_SURF_BND_LAYER;
    for(int i = 0; i < List_Nbr(chapeau->Generatrices); i++) {
      List_Read(chapeau->Generatrices, i, &c);
      c->Typ = MSH_SEGM_BND_LAYER;
      c = FindCurve(-c->Num);
      c->Typ = MSH_SEGM_BND_LAYER;
      if(c->beg) {
        c->beg->Typ = MSH_POINT_BND_LAYER;
        if(e) c->beg->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
      }
      if(c->end) {
        c->end->Typ = MSH_POINT_BND_LAYER;
        if(e) c->end->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
      }
      for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
        Vertex *v;
        List_Read(c->Control_Points, i, &v);
        if(e) v->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
      }
    }
    break;
  case ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  case TRANSLATE_ROTATE:
    T[0] = -X0;
    T[1] = -X1;
    T[2] = -X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    Ax[0] = A0;
    Ax[1] = A1;
    Ax[2] = A2;
    SetRotationMatrix(matrix, Ax, alpha);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    T[0] = X0;
    T[1] = X1;
    T[2] = X2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToSurface(matrix, chapeau);
    break;
  default: Msg::Error("Unknown extrusion type"); break;
  }

  // this is done only for backward compatibility with the old
  // numbering scheme
  Tree_Suppress(GModel::current()->getGEOInternals()->Surfaces, &chapeau);

  chapeau->Num = NEWSURFACE();

  GModel::current()->getGEOInternals()->setMaxTag(2, chapeau->Num);
  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &chapeau);

  Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);

  *pv = v;

  int chap_num = chapeau->Num;

  if(CTX::instance()->geom.autoCoherence) {
    std::vector<std::map<int, int> > report(3);
    report[2][chap_num] = chap_num;
    ReplaceAllDuplicates(report);
    auto m_it = (report[2]).find(chap_num);
    if(m_it != report[2].end())
      chap_num = report[2][chap_num];
    else
      chap_num = 0;
  }

  List_Reset(ListOfTransformedPoints);

  return chap_num;
}

void ExtrudeShapes(int type, List_T *list_in, double T0, double T1, double T2,
                   double A0, double A1, double A2, double X0, double X1,
                   double X2, double alpha, ExtrudeParams *e, List_T *list_out)
{
  for(int i = 0; i < List_Nbr(list_in); i++) {
    Shape shape;
    List_Read(list_in, i, &shape);
    switch(shape.Type) {
    case MSH_POINT: {
      Curve *pc = nullptr, *prc = nullptr;
      Shape top;
      top.Num = ExtrudePoint(type, shape.Num, T0, T1, T2, A0, A1, A2, X0, X1,
                             X2, alpha, &pc, &prc, 1, e);
      top.Type = MSH_POINT;
      List_Add(list_out, &top);
      if(pc) {
        Shape body;
        body.Num = pc->Num;
        body.Type = pc->Typ;
        List_Add(list_out, &body);
      }
    } break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_CIRC_INV:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV:
    case MSH_SEGM_NURBS: {
      Surface *ps = nullptr;
      Shape top;
      top.Num = ExtrudeCurve(type, shape.Num, T0, T1, T2, A0, A1, A2, X0, X1,
                             X2, alpha, &ps, 1, e);
      Curve *pc = FindCurve(top.Num);
      top.Type = pc ? pc->Typ : 0;
      List_Add(list_out, &top);
      if(ps) {
        Shape body;
        body.Num = ps->Num;
        body.Type = ps->Typ;
        List_Add(list_out, &body);
        if(CTX::instance()->geom.extrudeReturnLateral) {
          for(int j = 0; j < List_Nbr(ps->Generatrices); j++) {
            Curve *c;
            List_Read(ps->Generatrices, j, &c);
            if(abs(c->Num) != shape.Num && abs(c->Num) != top.Num) {
              Shape side;
              side.Num = c->Num;
              side.Type = c->Typ;
              List_Add(list_out, &side);
            }
          }
        }
      }
    } break;
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
    case MSH_SURF_DISCRETE: {
      Volume *pv = nullptr;
      Shape top;
      top.Num = ExtrudeSurface(type, shape.Num, T0, T1, T2, A0, A1, A2, X0, X1,
                               X2, alpha, &pv, e);
      Surface *ps = FindSurface(top.Num);
      top.Type = ps ? ps->Typ : 0;

      List_Add(list_out, &top);
      if(pv) {
        Shape body;
        body.Num = pv->Num;
        body.Type = pv->Typ;
        List_Add(list_out, &body);
        if(CTX::instance()->geom.extrudeReturnLateral) {
          for(int j = 0; j < List_Nbr(pv->Surfaces); j++) {
            Surface *s;
            List_Read(pv->Surfaces, j, &s);
            if(abs(s->Num) != shape.Num && abs(s->Num) != top.Num) {
              Shape side;
              side.Num = s->Num;
              side.Type = s->Typ;
              List_Add(list_out, &side);
            }
          }
        }
      }
    } break;
    default:
      Msg::Error("Impossible to extrude entity %d (of type %d)", shape.Num,
                 shape.Type);
      break;
    }
  }
}

// Projection of a point on a surface

struct PointSurface {
  Vertex *p;
  Surface *s;
};

static bool projectPS(fullVector<double> &x, fullVector<double> &res,
                      void *data)
{
  PointSurface *ps = (PointSurface *)data;
  Vertex c = InterpolateSurface(ps->s, x(0), x(1), 0, 0);
  Vertex du = InterpolateSurface(ps->s, x(0), x(1), 1, 1);
  Vertex dv = InterpolateSurface(ps->s, x(0), x(1), 1, 2);
  res(0) = (c.Pos.X - ps->p->Pos.X) * du.Pos.X +
           (c.Pos.Y - ps->p->Pos.Y) * du.Pos.Y +
           (c.Pos.Z - ps->p->Pos.Z) * du.Pos.Z;
  res(1) = (c.Pos.X - ps->p->Pos.X) * dv.Pos.X +
           (c.Pos.Y - ps->p->Pos.Y) * dv.Pos.Y +
           (c.Pos.Z - ps->p->Pos.Z) * dv.Pos.Z;
  return true;
}

bool ProjectPointOnSurface(Surface *s, Vertex &p, double uv[2])
{
  fullVector<double> x(2);
  x(0) = uv[0];
  x(1) = uv[1];
  PointSurface ps = {&p, s};

  Vertex pp = InterpolateSurface(s, uv[0], uv[1], 0, 0);
  double d2 = (pp.Pos.X - p.Pos.X) * (pp.Pos.X - p.Pos.X) +
              (pp.Pos.Y - p.Pos.Y) * (pp.Pos.Y - p.Pos.Y) +
              (pp.Pos.Z - p.Pos.Z) * (pp.Pos.Z - p.Pos.Z);
  if(d2 < 1.e-12) return true;

  double UMIN = 0.;
  double UMAX = 1.;
  double VMIN = 0.;
  double VMAX = 1.;
  int ITER = 0;
  while(1) {
    bool success = newton_fd(projectPS, x, &ps);
    if(success && x(0) >= UMIN && x(0) <= UMAX && x(1) >= VMIN &&
       x(1) <= VMAX) {
      p = InterpolateSurface(s, x(0), x(1), 0, 0);
      uv[0] = x(0);
      uv[1] = x(1);
      if(ITER >= 0)
        Msg::Info(
          "ProjectPoint (%g,%g,%g) On Surface %d converged after %d iterations",
          p.Pos.X, p.Pos.Y, p.Pos.Z, s->Num, ITER);
      return true;
    }
    x(0) = UMIN + (UMAX - UMIN) * ((rand() % 10000) / 10000.);
    x(1) = VMIN + (VMAX - VMIN) * ((rand() % 10000) / 10000.);
    if(ITER++ > 100) break;
  }
  {
    int NSAMPLES = 500;
    double uok = 0.5, vok = 0.5;
    double dmin = 1.e22;
    for(int i = 0; i < NSAMPLES; i++) {
      const double U = i / (double)(NSAMPLES - 1);
      for(int j = 0; j < NSAMPLES; j++) {
        const double V = j / (double)(NSAMPLES - 1);
        Vertex pp = InterpolateSurface(s, U, V, 0, 0);
        double d2 = (pp.Pos.X - p.Pos.X) * (pp.Pos.X - p.Pos.X) +
                    (pp.Pos.Y - p.Pos.Y) * (pp.Pos.Y - p.Pos.Y) +
                    (pp.Pos.Z - p.Pos.Z) * (pp.Pos.Z - p.Pos.Z);
        if(d2 < dmin) {
          dmin = d2;
          uok = U;
          vok = V;
        }
      }
    }
    p = InterpolateSurface(s, uok, vok, 0, 0);
    uv[0] = uok;
    uv[1] = vok;
    if(ITER > 0)
      Msg::Info("Brute force method used for projection of point (%g %g %g) on "
                "surface %d",
                p.Pos.X, p.Pos.Y, p.Pos.Z, s->Num);
    return true;
  }
  return false;
}

static Curve *_create_splitted_curve(Curve *c, List_T *nodes)
{
  int beg, end;
  List_Read(nodes, 0, &beg);
  List_Read(nodes, List_Nbr(nodes) - 1, &end);
  int id = NEWLINE();
  Curve *cnew = nullptr;
  bool ok = true;
  switch(c->Typ) {
  case MSH_SEGM_LINE:
    cnew = CreateCurve(id, c->Typ, 1, nodes, nullptr, -1, -1, 0., 1., ok);
    break;
  case MSH_SEGM_SPLN:
    cnew = CreateCurve(id, c->Typ, 3, nodes, nullptr, -1, -1, 0., 1., ok);
    break;
  case MSH_SEGM_BSPLN:
    cnew = CreateCurve(id, c->Typ, 2, nodes, nullptr, -1, -1, 0., 1., ok);
    break;
  default: // should never reach this point...
    Msg::Error("Cannot split a curve with type %i", c->Typ);
    return nullptr;
  }
  Tree_Add(GModel::current()->getGEOInternals()->Curves, &cnew);
  CreateReversedCurve(cnew);
  return cnew;
}

bool SplitCurve(int line_id, List_T *vertices_id, List_T *curves)
{
  Curve *c = FindCurve(line_id);
  if(!c) {
    Msg::Error("Curve %i does not exists", line_id);
    return false;
  }
  switch(c->Typ) {
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN: break;
  default:
    Msg::Error("Cannot split curve %i with type %i", line_id, c->Typ);
    return false;
  }
  std::set<int> v_break;
  for(int i = 0; i < List_Nbr(vertices_id); i++) {
    int id;
    List_Read(vertices_id, i, &id);
    v_break.insert(id);
  }
  bool is_periodic = (c->beg == c->end);
  bool first_periodic = true;
  bool last_periodic = false;
  List_T *new_list =
    List_Create(1, List_Nbr(c->Control_Points) / 10, sizeof(int));
  List_T *num_shapes = List_Create(2, 1, sizeof(int));
  Vertex *pv;
  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    List_Read(c->Control_Points, i, &pv);
    List_Add(new_list, &pv->Num);
    if(v_break.find(pv->Num) != v_break.end() && List_Nbr(new_list) > 1) {
      if(last_periodic) break;
      if(!(is_periodic && first_periodic)) {
        Curve *cnew = _create_splitted_curve(c, new_list);
        List_Add(curves, &cnew);
        List_Add(num_shapes, &cnew->Num);
      }
      first_periodic = false;
      List_Reset(new_list);
      List_Add(new_list, &pv->Num);
    }
    if(i == (List_Nbr(c->Control_Points) - 1) && is_periodic &&
       !first_periodic) {
      i = 0;
      last_periodic = true;
    }
  }
  if(List_Nbr(new_list) > 1) {
    Curve *cnew = _create_splitted_curve(c, new_list);
    List_Add(curves, &cnew);
    List_Add(num_shapes, &cnew->Num);
  }
  // replace original curve by the new curves in all surfaces (and for
  // the opposite curve)
  List_T *rcurves = List_Create(2, 1, sizeof(Curve *));
  int N = List_Nbr(curves);
  for(int i = 0; i < List_Nbr(curves); i++) {
    Curve *cc, *rcc;
    List_Read(curves, N - i - 1, &cc);
    rcc = FindCurve(-cc->Num);
    List_Add(rcurves, &rcc);
  }
  List_T *Surfs = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      Curve *surface_curve;
      List_Read(s->Generatrices, j, &surface_curve);
      if(surface_curve->Num == c->Num) {
        List_Remove(s->Generatrices, j);
        List_Insert_In_List(curves, j, s->Generatrices);
        j += List_Nbr(curves) - 1;
      }
      else if(surface_curve->Num == -c->Num) {
        List_Remove(s->Generatrices, j);
        List_Insert_In_List(rcurves, j, s->Generatrices);
        j += List_Nbr(curves) - 1;
      }
    }
  }
  List_Delete(Surfs);

  // replace original curve by the new curves in physical groups
  for(int i = 0;
      i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++) {
    PhysicalGroup *p = *(PhysicalGroup **)List_Pointer(
      GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_LINE) {
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
        int num;
        List_Read(p->Entities, j, &num);
        if(num == c->Num) {
          List_Remove(p->Entities, j);
          List_Insert_In_List(num_shapes, j, p->Entities);
          j += List_Nbr(num_shapes) - 1;
        }
      }
    }
  }

  DeleteCurve(c->Num);
  DeleteCurve(-c->Num);
  List_Delete(new_list);
  List_Delete(rcurves);
  List_Delete(num_shapes);
  return true;
}

struct CurveSurface {
  Curve *c;
  Surface *s;
};

static bool intersectCS(fullVector<double> &uvt, fullVector<double> &res,
                        void *data)
{
  CurveSurface *cs = (CurveSurface *)data;
  Vertex vs = InterpolateSurface(cs->s, uvt(0), uvt(1), 0, 0);
  Vertex vc = InterpolateCurve(cs->c, uvt(2), 0);
  res(0) = vs.Pos.X - vc.Pos.X;
  res(1) = vs.Pos.Y - vc.Pos.Y;
  res(2) = vs.Pos.Z - vc.Pos.Z;
  return true;
}

bool IntersectCurvesWithSurface(List_T *curve_ids, int surface_id,
                                List_T *shapes)
{
  Surface *s = FindSurface(surface_id);
  if(!s) {
    Msg::Error("Unknown surface %d", surface_id);
    return false;
  }
  for(int i = 0; i < List_Nbr(curve_ids); i++) {
    double curve_id;
    List_Read(curve_ids, i, &curve_id);
    Curve *c = FindCurve((int)curve_id);
    if(c) {
      CurveSurface cs = {c, s};
      fullVector<double> uvt(3);
      uvt(0) = 0.5;
      uvt(1) = 0.5;
      uvt(2) = 0.5;
      if(newton_fd(intersectCS, uvt, &cs)) {
        Vertex p = InterpolateCurve(c, uvt(2), 0);
        Vertex *v =
          CreateVertex(NEWPOINT(), p.Pos.X, p.Pos.Y, p.Pos.Z, p.lc, p.u);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, &v);
        Shape sh;
        sh.Type = MSH_POINT;
        sh.Num = v->Num;
        List_Add(shapes, &sh);
      }
    }
    else {
      Msg::Error("Unknown curve %d", (int)curve_id);
      return false;
    }
  }
  return true;
}

bool SortEdgesInLoop(int num, List_T *edges, bool reorient)
{
  // This function sorts the edges in an edge loop; if reorient is set, it
  // reorients the edges (and creates reversed edges if necessary). The routine
  // also detects subloops if reorient is not set; this is useful for writing
  // general scriptable surface generation in complex cases.
  Curve *c, *c0, *c1, *c2;
  int nbEdges = List_Nbr(edges);
  List_T *temp = List_Create(nbEdges, 1, sizeof(Curve *));

  for(int i = 0; i < nbEdges; i++) {
    int j;
    List_Read(edges, i, &j);
    if((c = FindCurve(j))) {
      List_Add(temp, &c);
      if(c->Typ == MSH_SEGM_DISCRETE) {
        Msg::Debug("Aborting curve loop sort for discrete curve: "
                   "let's hope you know what you're doing ;-)");
        List_Delete(temp);
        return true;
      }
    }
    else {
      Msg::Debug("Unknown curve %d, aborting curve loop sort: "
                 "let's hope you know what you're doing ;-)",
                 j);
      List_Delete(temp);
      return true;
    }
  }
  List_Reset(edges);

  if(!List_Nbr(temp)) return true;

  bool ok = true;
  int j = 0, k = 0;
  c0 = c1 = *(Curve **)List_Pointer(temp, 0);
  List_Add(edges, &c1->Num);
  List_PSuppress(temp, 0);
  while(List_Nbr(edges) < nbEdges) {
    for(int i = 0; i < List_Nbr(temp); i++) {
      c2 = *(Curve **)List_Pointer(temp, i);
      if(reorient && c1->end == c2->end) {
        Curve *c2R = FindCurve(-c2->Num);
        if(!c2R) {
          Msg::Debug("Creating reversed curve -%d", -c2->Num);
          c2R = CreateReversedCurve(c2);
        }
        c2 = c2R;
      }
      if(c1->end == c2->beg) {
        List_Add(edges, &c2->Num);
        List_PSuppress(temp, i);
        c1 = c2;
        if(c2->end == c0->beg) {
          if(List_Nbr(temp)) {
            Msg::Info(
              "Starting subloop %d in Curve Loop %d (are you sure about this?)",
              ++k, num);
            c0 = c1 = *(Curve **)List_Pointer(temp, 0);
            List_Add(edges, &c1->Num);
            List_PSuppress(temp, 0);
          }
        }
        break;
      }
    }
    if(j++ > nbEdges) {
      Msg::Error("Curve Loop %d is wrong", num);
      ok = false;
      break;
    }
  }
  List_Delete(temp);
  return ok;
}

bool SetSurfaceGeneratrices(Surface *s, List_T *loops)
{
  int nbLoop = List_Nbr(loops);
  List_Delete(s->Generatrices);
  s->Generatrices = List_Create(4, 4, sizeof(Curve *));
  List_Delete(s->GeneratricesByTag);
  s->GeneratricesByTag = List_Create(4, 4, sizeof(int));

  for(int i = 0; i < nbLoop; i++) {
    int iLoop;
    List_Read(loops, i, &iLoop);
    EdgeLoop *el;
    std::vector<int> fromModel;
    if(!(el = FindEdgeLoop(abs(iLoop)))) {
      Msg::Error("Unknown curve loop %d in GEO surface %d", iLoop, s->Num);
      List_Delete(s->Generatrices);
      s->Generatrices = nullptr;
      return false;
    }
    else {
      int ic;
      Curve *c;
      if((i == 0 && iLoop > 0) || // exterior boundary
         (i != 0 && iLoop < 0)) { // hole
        for(int j = 0; j < List_Nbr(el->Curves); j++) {
          List_Read(el->Curves, j, &ic);
          ic *= gmsh_sign(iLoop);
          if(i != 0) ic *= -1; // hole
          if(!(c = FindCurve(ic)))
            fromModel.push_back(ic);
          else
            List_Add(s->Generatrices, &c);
        }
      }
      else {
        for(int j = List_Nbr(el->Curves) - 1; j >= 0; j--) {
          List_Read(el->Curves, j, &ic);
          ic *= gmsh_sign(iLoop);
          if(i != 0) ic *= -1; // hole
          if(!(c = FindCurve(ic)))
            fromModel.push_back(ic);
          else
            List_Add(s->Generatrices, &c);
        }
      }
      for(std::size_t j = 0; j < fromModel.size(); j++) {
        ic = fromModel[j];
        GEdge *ge = GModel::current()->getEdgeByTag(abs(ic));
        if(ge) { List_Add(s->GeneratricesByTag, &ic); }
        else {
          Msg::Error("Unknown curve %d", ic);
          return false;
        }
      }
    }
  }

  return true;
}

bool SetVolumeSurfaces(Volume *v, List_T *loops)
{
  List_Reset(v->Surfaces);
  List_Reset(v->SurfacesOrientations);
  List_Reset(v->SurfacesByTag);
  for(int i = 0; i < List_Nbr(loops); i++) {
    int il;
    List_Read(loops, i, &il);
    SurfaceLoop *sl;
    if(!(sl = FindSurfaceLoop(abs(il)))) {
      Msg::Error("Unknown surface loop %d", il);
      return false;
    }
    else {
      for(int j = 0; j < List_Nbr(sl->Surfaces); j++) {
        int is;
        List_Read(sl->Surfaces, j, &is);
        Surface *s = FindSurface(abs(is));
        if(s) {
          // contrary to curves in edge loops, we don't actually create
          // "negative" surfaces. So we just store the signs in another list
          List_Add(v->Surfaces, &s);
          int tmp = gmsh_sign(is) * gmsh_sign(il);
          if(i > 0) tmp *= -1; // this is a hole
          List_Add(v->SurfacesOrientations, &tmp);
        }
        else {
          GFace *gf = GModel::current()->getFaceByTag(abs(is));
          if(gf) { List_Add(v->SurfacesByTag, &is); }
          else {
            Msg::Error("Unknown surface %d in GEO volume %d", is, v->Num);
            return false;
          }
        }
      }
    }
  }
  return true;
}

// the following routines should be renamed and moved elsewhere

int NEWPOINT()
{
  int tag = GModel::current()->getGEOInternals()->getMaxTag(0) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(0) + 1);
  return tag;
}

int NEWLINE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(1) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(1) + 1);
  return tag;
}

int NEWLINELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-1) + 1;
  if(GModel::current()->getOCCInternals())
    tag =
      std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  return tag;
}

int NEWSURFACE()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(2) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(2) + 1);
  return tag;
}

int NEWSURFACELOOP()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(-2) + 1;
  if(GModel::current()->getOCCInternals())
    tag =
      std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  return tag;
}

int NEWVOLUME()
{
  int tag = 0;
  if(CTX::instance()->geom.oldNewreg)
    tag = NEWREG();
  else
    tag = GModel::current()->getGEOInternals()->getMaxTag(3) + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG()
{
  int tag = 0;
  for(int dim = -2; dim <= 3; dim++) {
    if(dim)
      tag =
        std::max(tag, GModel::current()->getGEOInternals()->getMaxTag(dim) + 1);
  }
  tag = std::max(tag,
                 GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1);
  if(GModel::current()->getOCCInternals()) {
    for(int dim = -2; dim <= 3; dim++) {
      if(dim)
        tag = std::max(
          tag, GModel::current()->getOCCInternals()->getMaxTag(dim) + 1);
    }
  }
  return tag;
}

int NEWFIELD()
{
#if defined(HAVE_MESH)
  return (GModel::current()->getFields()->maxId() + 1);
#else
  return 0;
#endif
}

int NEWPHYSICAL()
{
  if(CTX::instance()->geom.oldNewreg)
    return NEWREG();
  else
    return GModel::current()->getGEOInternals()->getMaxPhysicalTag() + 1;
}
