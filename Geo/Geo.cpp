// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <string.h>
#include "GmshMessage.h"
#include "Numeric.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GeoInterpolation.h"
#include "Context.h"
#include "MVertexRTree.h"
#include "Parser.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

static List_T *ListOfTransformedPoints = NULL;

int NEWFIELD(void)
{
#if defined(HAVE_MESH)
  return (GModel::current()->getFields()->maxId() + 1);
#else
  return 0;
#endif
}

int NEWPHYSICAL(void)
{
  if(CTX::instance()->geom.oldNewreg)
    return NEWREG();
  else
    return (GModel::current()->getGEOInternals()->MaxPhysicalNum + 1);
}

// Comparison routines

int compareVertex(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;
  return abs(q->Num) - abs(w->Num);
}

static int comparePosition(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;

  // Warning: tolerance! (before 1.61, it was set to 1.e-10 * CTX::instance()->lc)
  double eps = CTX::instance()->geom.tolerance * CTX::instance()->lc;

  if(q->Pos.X - w->Pos.X > eps) return 1;
  if(q->Pos.X - w->Pos.X < -eps) return -1;
  if(q->Pos.Y - w->Pos.Y > eps) return 1;
  if(q->Pos.Y - w->Pos.Y < -eps) return -1;
  if(q->Pos.Z - w->Pos.Z > eps) return 1;
  if(q->Pos.Z - w->Pos.Z < -eps) return -1;
  return 0;
}

int compareSurfaceLoop(const void *a, const void *b)
{
  SurfaceLoop *q = *(SurfaceLoop **)a;
  SurfaceLoop *w = *(SurfaceLoop **)b;
  return q->Num - w->Num;
}

int compareEdgeLoop(const void *a, const void *b)
{
  EdgeLoop *q = *(EdgeLoop **)a;
  EdgeLoop *w = *(EdgeLoop **)b;
  return q->Num - w->Num;
}

int compareCurve(const void *a, const void *b)
{
  Curve *q = *(Curve **)a;
  Curve *w = *(Curve **)b;
  return q->Num - w->Num;
}

int compareSurface(const void *a, const void *b)
{
  Surface *q = *(Surface **)a;
  Surface *w = *(Surface **)b;
  return q->Num - w->Num;
}

int compareVolume(const void *a, const void *b)
{
  Volume *q = *(Volume **)a;
  Volume *w = *(Volume **)b;
  return q->Num - w->Num;
}

int compareLevelSet(const void *a, const void *b)
{
  LevelSet *q = *(LevelSet **)a;
  LevelSet *w = *(LevelSet **)b;
  return q->Num - w->Num;
}

int comparePhysicalGroup(const void *a, const void *b)
{
  PhysicalGroup *q = *(PhysicalGroup **)a;
  PhysicalGroup *w = *(PhysicalGroup **)b;
  int cmp = q->Typ - w->Typ;
  if(cmp)
    return cmp;
  else
    return q->Num - w->Num;
}

void Projette(Vertex *v, double mat[3][3])
{
  double X = v->Pos.X * mat[0][0] + v->Pos.Y * mat[0][1] + v->Pos.Z * mat[0][2];
  double Y = v->Pos.X * mat[1][0] + v->Pos.Y * mat[1][1] + v->Pos.Z * mat[1][2];
  double Z = v->Pos.X * mat[2][0] + v->Pos.Y * mat[2][1] + v->Pos.Z * mat[2][2];
  v->Pos.X = X;
  v->Pos.Y = Y;
  v->Pos.Z = Z;
}

// Basic entity creation/deletion functions

Vertex *Create_Vertex(int Num, double X, double Y, double Z, double lc, double u)
{
  Vertex *pV = new Vertex(X, Y, Z, lc);
  pV->w = 1.0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->MaxPointNum =
    std::max(GModel::current()->getGEOInternals()->MaxPointNum, Num);
  pV->u = u;
  pV->geometry = 0;
  return pV;
}

Vertex *Create_Vertex(int Num, double u, double v, gmshSurface *surf, double lc)
{
  SPoint3 p = surf->point(u, v);
  Vertex *pV = new Vertex(p.x(), p.y(), p.z(), lc);
  pV->w = 1.0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->MaxPointNum =
    std::max(GModel::current()->getGEOInternals()->MaxPointNum, Num);
  pV->u = u;
  pV->geometry = surf;
  pV->pntOnGeometry = SPoint2(u, v);
  surf->vertex_defined_on_surface = true;
  return pV;
}

void Free_Vertex(void *a, void *b)
{
  Vertex *v = *(Vertex **)a;
  if(v) {
    delete v;
    v = NULL;
  }
}

PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T *intlist)
{
  PhysicalGroup *p = new PhysicalGroup;
  p->Entities = List_Create(List_Nbr(intlist), 1, sizeof(int));
  p->Num = Num;
  GModel::current()->getGEOInternals()->MaxPhysicalNum =
    std::max(GModel::current()->getGEOInternals()->MaxPhysicalNum, Num);
  p->Typ = typ;
  p->Visible = 1;
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(p->Entities, &j);
  }
  return p;
}

void Free_PhysicalGroup(void *a, void *b)
{
  PhysicalGroup *p = *(PhysicalGroup **)a;
  if(p) {
    List_Delete(p->Entities);
    delete p;
    p = NULL;
  }
}

EdgeLoop *Create_EdgeLoop(int Num, List_T *intlist)
{
  EdgeLoop *l = new EdgeLoop;
  l->Curves = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  GModel::current()->getGEOInternals()->MaxLineLoopNum =
    std::max(GModel::current()->getGEOInternals()->MaxLineLoopNum, Num);
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Curves, &j);
  }
  return l;
}

void Free_EdgeLoop(void *a, void *b)
{
  EdgeLoop *l = *(EdgeLoop **)a;
  if(l) {
    List_Delete(l->Curves);
    delete l;
    l = NULL;
  }
}

SurfaceLoop *Create_SurfaceLoop(int Num, List_T *intlist)
{
  SurfaceLoop *l = new SurfaceLoop;
  l->Surfaces = List_Create(List_Nbr(intlist), 1, sizeof(int));
  l->Num = Num;
  GModel::current()->getGEOInternals()->MaxSurfaceLoopNum =
    std::max(GModel::current()->getGEOInternals()->MaxSurfaceLoopNum, Num);
  for(int i = 0; i < List_Nbr(intlist); i++) {
    int j;
    List_Read(intlist, i, &j);
    List_Add(l->Surfaces, &j);
  }
  return l;
}

void Free_SurfaceLoop(void *a, void *b)
{
  SurfaceLoop *l = *(SurfaceLoop **)a;
  if(l) {
    List_Delete(l->Surfaces);
    delete l;
    l = NULL;
  }
}

static void direction(Vertex *v1, Vertex *v2, double d[3])
{
  d[0] = v2->Pos.X - v1->Pos.X;
  d[1] = v2->Pos.Y - v1->Pos.Y;
  d[2] = v2->Pos.Z - v1->Pos.Z;
}

void End_Curve(Curve *c)
{
  // if all control points of a curve are on the same geometry, then
  // the curve is also on the geometry
  int NN = List_Nbr(c->Control_Points);
  if(NN){
    Vertex *pV;
    List_Read (c->Control_Points, 0, &pV);
    c->geometry = pV->geometry;
    for(int i = 1; i < NN; i++){
      List_Read (c->Control_Points, i, &pV);
      if(c->geometry != pV->geometry){
        c->geometry = 0;
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
      v[3] = NULL;

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

    double dir12[3], dir32[3], dir42[3] = {0., 0. , 0.};
    direction(v[1], v[0], dir12);
    direction(v[1], v[2], dir32);
    if(v[3])
      direction(v[1], v[3], dir42);

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
    if (norm3(n) < 1.e-15) {
      isValid = false;
    }
    else {
      norme(n);
      if ((fabs(n[0]) < 1.e-5 && fabs(n[1]) < 1.e-5 && fabs(n[2]) < 1.e-5)) {
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
    if(v[3])
      Projette(&v3, mat);

    double R = sqrt(v0.Pos.X * v0.Pos.X + v0.Pos.Y * v0.Pos.Y);
    double R2 = sqrt(v2.Pos.X * v2.Pos.X + v2.Pos.Y * v2.Pos.Y);

    if(!R || !R2){
      // check radius
      Msg::Error("Zero radius in Circle/Ellipse %d", c->Num);
    }
    else if(!v[3] && fabs((R - R2) / (R + R2)) > 0.1){
      // check cocircular pts (allow 10% error)
      Msg::Error("Control points of Circle %d are not cocircular %g %g",
                 c->Num, R, R2);
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
        Msg::Error("Ellipse %d is wrong", c->Num);
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
    if(A1 >= A3)
      A3 += 2 * M_PI;

    c->Circle.t1 = A1;
    c->Circle.t2 = A3;
    c->Circle.incl = A4;
    c->Circle.f1 = f1;
    c->Circle.f2 = f2;

    if(!CTX::instance()->expertMode && c->Num > 0 && A3 - A1 > 1.01 * M_PI){
      Msg::Error("Circle or ellipse arc %d greater than Pi (angle=%g)", c->Num, A3-A1);
      Msg::Error("(If you understand what this implies, you can disable this error");
      Msg::Error("message by selecting `Enable expert mode' in the option dialog.");
      Msg::Error("Otherwise, please subdivide the arc in smaller pieces.)");
    }

  }

  if (c->Typ == MSH_SEGM_COMPOUND) {

    std::list<Curve*> tmp;
    for (std::vector<int>::const_iterator cIter=c->compound.begin();
         cIter!=c->compound.end();++cIter) {
      Curve* comp;
      if (!(comp = FindCurve(*cIter))){
        Msg::Debug("Could not find curve %d as part of compound edge %d. "
                   "Aborting sort.",*cIter,c->Num);
        return;
      }
      tmp.push_back(comp);
    }

    std::list<int> ordered;

    Curve* c0 = *(tmp.begin());
    tmp.pop_front();

    ordered.push_back(c0->Num);
    std::pair<Vertex*,Vertex*> vtcs(c0->beg,c0->end);

    while (tmp.size() != 0) {
      unsigned nbCurrent = tmp.size();
      for (std::list<Curve*>::iterator tIter=tmp.begin();tIter!=tmp.end();tIter++) {
        Curve* c1 = *tIter;
        if (c1->beg == vtcs.first) {
          vtcs.first = c1->end;
          ordered.push_front(c1->Num);
          tmp.erase(tIter);
          break;
        }
        if (c1->end == vtcs.first) {
          vtcs.first = c1->beg;
          ordered.push_front(c1->Num);
          tmp.erase(tIter);
          break;
        }
        if (c1->beg == vtcs.second) {
          vtcs.second = c1->end;
          ordered.push_back(c1->Num);
          tmp.erase(tIter);
          break;
        }
        if (c1->end == vtcs.second) {
          vtcs.second = c1->beg;
          ordered.push_back(c1->Num);
          tmp.erase(tIter);
          break;
        }
      }
      if (tmp.size() == nbCurrent)
        Msg::Error("Could not order compound edge %d to find begin and end vertex",
                   c->Num);
    }
    c->beg = vtcs.first;
    c->end = vtcs.second;
    c->compound.clear();
    c->compound.insert(c->compound.end(), ordered.begin(), ordered.end());
  }
}

void End_Surface(Surface *s)
{
  // if all generatrices of a surface are on the same geometry, then
  // the surface is also on the geometry
  if(List_Nbr(s->Generatrices)){
    Curve *c;
    int NN = List_Nbr(s->Generatrices);
    List_Read (s->Generatrices, 0, &c);
    s->geometry = c->geometry;
    for (int i = 1; i < NN; i++){
      List_Read (s->Generatrices, i, &c);
      if (c->geometry != s->geometry){
        s->geometry = 0;
        break;
      }
    }
  }
}

Curve *Create_Curve(int Num, int Typ, int Order, List_T *Liste,
                    List_T *Knots, int p1, int p2, double u1, double u2)
{
  double matcr[4][4] = { {-0.5, 1.5, -1.5, 0.5},
                         {1.0, -2.5, 2.0, -0.5},
                         {-0.5, 0.0, 0.5, 0.0},
                         {0.0, 1.0, 0.0, 0.0} };
  double matbs[4][4] = { {-1, 3, -3, 1},
                         { 3,-6,  3, 0},
                         {-3, 0,  3, 0},
                         { 1, 4,  1, 0} };
  double matbez[4][4] = { {-1, 3,-3, 1},
                          { 3,-6, 3, 0},
                          {-3, 3, 0, 0},
                          { 1, 0, 0, 0} };

  Curve *pC = new Curve;
  pC->Color.type = 0;
  pC->Visible = 1;
  pC->Extrude = NULL;
  pC->Typ = Typ;
  pC->Num = Num;
  GModel::current()->getGEOInternals()->MaxLineNum =
    std::max(GModel::current()->getGEOInternals()->MaxLineNum, Num);
  pC->Method = MESH_UNSTRUCTURED;
  pC->degre = Order;
  pC->Circle.n[0] = 0.0;
  pC->Circle.n[1] = 0.0;
  pC->Circle.n[2] = 1.0;
  pC->geometry = 0;
  pC->nbPointsTransfinite = 0;
  pC->typeTransfinite = 0;
  pC->coeffTransfinite = 0.;
  pC->ReverseMesh = 0;
  pC->beg = NULL;
  pC->end = NULL;
  pC->Control_Points = NULL;
  pC->degenerated = false;

  if(Typ == MSH_SEGM_SPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matcr[i][j];
  }
  else if(Typ == MSH_SEGM_BSPLN) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matbs[i][j] / 6.0;
  }
  else if(Typ == MSH_SEGM_BEZIER) {
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        pC->mat[i][j] = matbez[i][j];
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
    pC->k = NULL;

  if(List_Nbr(Liste)) {
    pC->Control_Points = List_Create(List_Nbr(Liste), 1, sizeof(Vertex *));
    for(int j = 0; j < List_Nbr(Liste); j++) {
      int iPnt;
      List_Read(Liste, j, &iPnt);
      Vertex *v;
      if((v = FindPoint(iPnt)))
        List_Add(pC->Control_Points, &v);
      else{
        Msg::Error("Unknown control point %d in Curve %d (a)", iPnt, pC->Num);
      }
    }
    if(p1 < 0) {
      if(List_Nbr(pC->Control_Points)){
        List_Read(pC->Control_Points, 0, &pC->beg);
        List_Read(pC->Control_Points, List_Nbr(pC->Control_Points) - 1, &pC->end);
      }
    }
    else {
      Vertex *v;
      if((v = FindPoint(p1))) {
        Msg::Info("Curve %d first control point %d ", pC->Num, v->Num);
        pC->beg = v;
      }
      else {
        Msg::Error("Unknown control point %d in Curve %d (b)", p1, pC->Num);
      }
      if((v = FindPoint(p2))) {
        Msg::Info("Curve %d first control point %d ", pC->Num, v->Num);
        pC->end = v;
      }
      else {
        Msg::Error("Unknown control point %d in Curve %d (c)", p2, pC->Num);
      }
    }
    End_Curve(pC);
  }

  return pC;
}

void Free_Curve(void *a, void *b)
{
  Curve *pC = *(Curve **)a;
  if(pC) {
    delete [] pC->k;
    List_Delete(pC->Control_Points);
    delete pC;
    pC = NULL;
  }
}

Surface *Create_Surface(int Num, int Typ)
{
  Surface *pS = new Surface;
  pS->Color.type = 0;
  pS->Visible = 1;
  pS->Num = Num;
  pS->geometry = 0;
  pS->InSphereCenter = 0;

  GModel::current()->getGEOInternals()->MaxSurfaceNum =
    std::max(GModel::current()->getGEOInternals()->MaxSurfaceNum, Num);
  pS->Typ = Typ;
  pS->Method = MESH_UNSTRUCTURED;
  pS->Recombine = 0;
  pS->RecombineAngle = 45;
  pS->Recombine_Dir = -1;
  pS->TransfiniteSmoothing = -1;
  pS->TrsfPoints = List_Create(4, 4, sizeof(Vertex *));
  pS->Generatrices = NULL;
  pS->GeneratricesByTag = NULL;
  pS->EmbeddedPoints = NULL;
  pS->EmbeddedCurves = NULL;
  pS->Extrude = NULL;
  pS->geometry = NULL;
  pS->ReverseMesh = 0;
  return (pS);
}

void Free_Surface(void *a, void *b)
{
  Surface *pS = *(Surface **)a;
  if(pS) {
    List_Delete(pS->TrsfPoints);
    List_Delete(pS->Generatrices);
    List_Delete(pS->GeneratricesByTag);
    List_Delete(pS->EmbeddedCurves);
    List_Delete(pS->EmbeddedPoints);
    delete pS;
    pS = NULL;
  }
}

Volume *Create_Volume(int Num, int Typ)
{
  Volume *pV = new Volume;
  pV->Color.type = 0;
  pV->Visible = 1;
  pV->Recombine3D = 0;
  pV->Num = Num;
  GModel::current()->getGEOInternals()->MaxVolumeNum =
    std::max(GModel::current()->getGEOInternals()->MaxVolumeNum, Num);
  pV->Typ = Typ;
  pV->Method = MESH_UNSTRUCTURED;
  pV->QuadTri = NO_QUADTRI;
  pV->TrsfPoints = List_Create(6, 6, sizeof(Vertex *));
  pV->Surfaces = List_Create(1, 2, sizeof(Surface *));
  pV->SurfacesOrientations = List_Create(1, 2, sizeof(int));
  pV->SurfacesByTag = List_Create(1, 2, sizeof(int));
  pV->Extrude = NULL;
  pV->EmbeddedSurfaces = NULL;
  pV->EmbeddedCurves = NULL;
  pV->EmbeddedPoints = NULL;
  return pV;
}

void Free_Volume(void *a, void *b)
{
  Volume *pV = *(Volume **)a;
  if(pV) {
    List_Delete(pV->TrsfPoints);
    List_Delete(pV->Surfaces);
    List_Delete(pV->SurfacesOrientations);
    List_Delete(pV->SurfacesByTag);
    List_Delete(pV->EmbeddedSurfaces);
    List_Delete(pV->EmbeddedCurves);
    List_Delete(pV->EmbeddedPoints);
    delete pV;
    pV = NULL;
  }
}

LevelSet *Create_LevelSet(int Num, gLevelset *l)
{
  LevelSet *pL = new LevelSet;
  pL->Num = Num;
  pL->ls = l;
  return pL;
}

void Free_LevelSet(void *a, void *b)
{
  LevelSet *pL = *(LevelSet **)a;
  if(pL) {
    delete pL;
    pL = NULL;
  }
}

static int compare2Lists(List_T *List1, List_T *List2,
                         int (*fcmp) (const void *a, const void *b))
{
  int i, found;

  if(!List_Nbr(List1) && !List_Nbr(List2))
    return 0;

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
  if(Tree_Query(t, &pc)) {
    return pc;
  }
  return NULL;
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
  if(Tree_Query(t, &pc)) {
    return pc;
  }
  return NULL;
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
  if(Tree_Query(t, &ps)) {
    return ps;
  }
  return NULL;
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
  return NULL;
}

LevelSet *FindLevelSet(int inum)
{
  LevelSet L, *pl;
  pl = &L;
  pl->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->LevelSets, &pl)) {
    return pl;
  }
  return NULL;
}

EdgeLoop *FindEdgeLoop(int inum)
{
  EdgeLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->EdgeLoops, &ps)) {
    return ps;
  }
  return NULL;
}

SurfaceLoop *FindSurfaceLoop(int inum)
{
  SurfaceLoop S, *ps;
  ps = &S;
  ps->Num = inum;
  if(Tree_Query(GModel::current()->getGEOInternals()->SurfaceLoops, &ps)) {
    return ps;
  }
  return NULL;
}

PhysicalGroup *FindPhysicalGroup(int num, int type)
{
  PhysicalGroup P, *pp, **ppp;
  pp = &P;
  pp->Num = num;
  pp->Typ = type;
  if((ppp = (PhysicalGroup **)
      List_PQuery(GModel::current()->getGEOInternals()->PhysicalGroups, &pp,
                  comparePhysicalGroup))) {
    return *ppp;
  }
  return NULL;
}

static void GetAllElementaryEntityNumbers(int dim, std::set<int> &nums)
{
  GModel *m = GModel::current();
  switch(dim){
  case 0:
    {
      List_T *l = Tree2List(m->getGEOInternals()->Points);
      Vertex *p;
      for(int i = 0; i < List_Nbr(l); i++){
        List_Read(l, i, &p);
        nums.insert(p->Num);
      }
      List_Delete(l);
      for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
        nums.insert((*it)->tag());
    }
    break;
  case 1:
    {
      List_T *l = Tree2List(m->getGEOInternals()->Curves);
      Curve *p;
      for(int i = 0; i < List_Nbr(l); i++){
        List_Read(l, i, &p);
        if(p->Num >= 0)
          nums.insert(p->Num);
      }
      List_Delete(l);
      for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++){
        if((*it)->tag() >= 0)
          nums.insert((*it)->tag());
      }
    }
    break;
  case 2:
    {
      List_T *l = Tree2List(m->getGEOInternals()->Surfaces);
      Surface *p;
      for(int i = 0; i < List_Nbr(l); i++){
        List_Read(l, i, &p);
        nums.insert(p->Num);
      }
      List_Delete(l);
      for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
        nums.insert((*it)->tag());
    }
    break;
  case 3:
    {
      List_T *l = Tree2List(m->getGEOInternals()->Volumes);
      Volume *p;
      for(int i = 0; i < List_Nbr(l); i++){
        List_Read(l, i, &p);
        nums.insert(p->Num);
      }
      List_Delete(l);
      for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
        nums.insert((*it)->tag());
    }
    break;
  }
}

List_T *GetAllElementaryEntityNumbers(int dim)
{
  std::set<int> nums;
  GetAllElementaryEntityNumbers(dim, nums);
  List_T *l = List_Create(nums.size(), 1, sizeof(double));
  for(std::set<int>::iterator it = nums.begin(); it != nums.end(); it++){
    double a = *it;
    List_Add(l, &a);
  }
  return l;
}

static void GetAllPhysicalEntityNumbers(int dim, std::set<int> &nums)
{
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(GModel::current()->getGEOInternals()->PhysicalGroups, i, &p);
    if((dim == 0 && p->Typ == MSH_PHYSICAL_POINT) ||
       (dim == 1 && p->Typ == MSH_PHYSICAL_LINE) ||
       (dim == 2 && p->Typ == MSH_PHYSICAL_SURFACE) ||
       (dim == 3 && p->Typ == MSH_PHYSICAL_VOLUME)){
      nums.insert(p->Num);
    }
  }

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(std::map<int, std::vector<GEntity*> >::iterator it = groups.begin();
      it != groups.end(); it++)
    nums.insert(it->first);
}

List_T *GetAllPhysicalEntityNumbers(int dim)
{
  std::set<int> nums;
  GetAllPhysicalEntityNumbers(dim, nums);
  List_T *l = List_Create(nums.size(), 1, sizeof(double));
  for(std::set<int>::iterator it = nums.begin(); it != nums.end(); it++){
    double a = *it;
    List_Add(l, &a);
  }
  return l;
}

static void CopyVertex(Vertex *v, Vertex *vv)
{
  vv->lc = v->lc;
  vv->u = v->u;
  vv->Pos.X = v->Pos.X;
  vv->Pos.Y = v->Pos.Y;
  vv->Pos.Z = v->Pos.Z;
  if(CTX::instance()->geom.copyDisplayAttributes){
    vv->Visible = v->Visible;
  }
}

static Vertex *DuplicateVertex(Vertex *v)
{
  if(!v) return NULL;
  Vertex *pv = Create_Vertex(NEWPOINT(), 0, 0, 0, 0, 0);
  CopyVertex(v, pv);
  Tree_Insert(GModel::current()->getGEOInternals()->Points, &pv);
  return pv;
}

static int compareAbsCurve(const void *a, const void *b)
{
  Curve *q = *(Curve **)a;
  Curve *w = *(Curve **)b;
  return abs(q->Num) - abs(w->Num);
}

static void CopyCurve(Curve *c, Curve *cc)
{
  cc->Typ = c->Typ;
  if(CTX::instance()->geom.copyMeshingMethod){
    cc->Method = c->Method;
    cc->nbPointsTransfinite = c->nbPointsTransfinite;
    cc->typeTransfinite = c->typeTransfinite;
    cc->coeffTransfinite = c->coeffTransfinite;
    cc->ReverseMesh = c->ReverseMesh;
  }
  if(CTX::instance()->geom.copyDisplayAttributes){
    cc->Visible = c->Visible;
    cc->Color = c->Color;
  }
  cc->l = c->l;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      cc->mat[i][j] = c->mat[i][j];
  cc->beg = c->beg;
  cc->end = c->end;
  cc->ubeg = c->ubeg;
  cc->uend = c->uend;
  cc->Control_Points = List_Create(List_Nbr(c->Control_Points), 1, sizeof(Vertex *));
  List_Copy(c->Control_Points, cc->Control_Points);
  End_Curve(cc);
}

static Curve *DuplicateCurve(Curve *c)
{
  Curve *pc = Create_Curve(NEWLINE(), 0, 1, NULL, NULL, -1, -1, 0., 1.);
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
  // Trevor Strickler modified
  if(s->Typ == MSH_SURF_COMPOUND)
    ss->Typ = MSH_SURF_REGL;
  else
    ss->Typ = s->Typ;
  if(CTX::instance()->geom.copyMeshingMethod){
    ss->Method = s->Method;
    ss->Recombine = s->Recombine;
    ss->RecombineAngle = s->RecombineAngle;
    ss->ReverseMesh = s->ReverseMesh;
    if(List_Nbr(s->TrsfPoints))
      Msg::Warning("Only automatic transfinite surface specifications can be copied");
  }
  if(CTX::instance()->geom.copyDisplayAttributes){
    ss->Visible = s->Visible;
    ss->Color = s->Color;
  }
  ss->Generatrices = List_Create(List_Nbr(s->Generatrices) + 1, 1, sizeof(Curve *));
  ss->GeneratricesByTag = List_Create(List_Nbr(s->GeneratricesByTag) + 1, 1, sizeof(int));
  ss->InSphereCenter = s->InSphereCenter; // FIXME: hack...
  List_Copy(s->Generatrices, ss->Generatrices);
  List_Copy(s->GeneratricesByTag, ss->GeneratricesByTag);
  End_Surface(ss);
}

static Surface *DuplicateSurface(Surface *s)
{
  Surface *ps = Create_Surface(NEWSURFACE(), 0);
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
  if(CTX::instance()->geom.copyMeshingMethod){
    vv->Method = v->Method;
    vv->QuadTri = v->QuadTri;
    vv->Recombine3D = v->Recombine3D;
    if(List_Nbr(v->TrsfPoints))
      Msg::Warning("Only automatic transfinite volume specifications can be copied");
  }
  if(CTX::instance()->geom.copyDisplayAttributes){
    vv->Visible = v->Visible;
    vv->Color = v->Color;
  }
  List_Copy(v->Surfaces, vv->Surfaces);
  List_Copy(v->SurfacesOrientations, vv->SurfacesOrientations);
  List_Copy(v->SurfacesByTag, vv->SurfacesByTag);
}

static Volume *DuplicateVolume(Volume *v)
{
  Volume *pv = Create_Volume(NEWVOLUME(), 0);
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

void CopyShape(int Type, int Num, int *New)
{
  Surface *s, *news;
  Curve *c, *newc;
  Vertex *v, *newv;
  Volume *vol, *newvol;

  switch (Type) {
  case MSH_POINT:
    if(!(v = FindPoint(Num))) {
      Msg::Error("Unknown vertex %d", Num);
      return;
    }
    newv = DuplicateVertex(v);
    *New = newv->Num;
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
    if(!(c = FindCurve(Num))) {
      Msg::Error("Unknown curve %d", Num);
      return;
    }
    newc = DuplicateCurve(c);
    *New = newc->Num;
    break;
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
    if(!(s = FindSurface(Num))) {
      Msg::Error("Unknown surface %d", Num);
      return;
    }
    news = DuplicateSurface(s);
    *New = news->Num;
    break;
  case MSH_VOLUME:
    if(!(vol = FindVolume(Num))) {
      Msg::Error("Unknown volume %d", Num);
      return;
    }
    newvol = DuplicateVolume(vol);
    *New = newvol->Num;
    break;
  default:
    Msg::Error("Impossible to copy entity %d (of type %d)", Num, Type);
    break;
  }
}

static void DeletePoint(int ip)
{
  Vertex *v = FindPoint(ip);
  if(!v)
    return;
  List_T *Curves = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(Curves); i++) {
    Curve *c;
    List_Read(Curves, i, &c);
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      if(!compareVertex(List_Pointer(c->Control_Points, j), &v)){
        List_Delete(Curves);
        // cannot delete: it's a control point of a curve
        return;
      }
    }
  }
  List_Delete(Curves);

  List_T *Surfs = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->EmbeddedPoints); j++) {
      if(!compareVertex(List_Pointer(s->EmbeddedPoints, j), &v)){
        List_Delete(Surfs);
        // cannot delete: it's embedded in a surface
        return;
      }
    }
  }
  List_Delete(Surfs);

  List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(Vols); i++) {
    Volume *v;
    List_Read(Vols, i, &v);
    for(int j = 0; j < List_Nbr(v->EmbeddedPoints); j++) {
      if(!compareAbsCurve(List_Pointer(v->EmbeddedPoints, j), &v)){
        List_Delete(Vols);
        // cannot delete: it's embedded in a volume
        return;
      }
    }
  }
  List_Delete(Vols);

  if(v->Num == GModel::current()->getGEOInternals()->MaxPointNum)
    GModel::current()->getGEOInternals()->MaxPointNum--;
  Tree_Suppress(GModel::current()->getGEOInternals()->Points, &v);
  Free_Vertex(&v, NULL);
}

static void DeleteCurve(int ip)
{
  Curve *c = FindCurve(ip);
  if(!c)
    return;
  List_T *Surfs = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      if(!compareAbsCurve(List_Pointer(s->Generatrices, j), &c)){
        List_Delete(Surfs);
        // cannot delete: it's on the boundary of a surface
        return;
      }
    }
    for(int j = 0; j < List_Nbr(s->EmbeddedCurves); j++) {
      if(!compareAbsCurve(List_Pointer(s->EmbeddedCurves, j), &c)){
        List_Delete(Surfs);
        // cannot delete: it's embedded in a surface
        return;
      }
    }
  }
  List_Delete(Surfs);

  List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(Vols); i++) {
    Volume *v;
    List_Read(Vols, i, &v);
    for(int j = 0; j < List_Nbr(v->EmbeddedCurves); j++) {
      if(!compareAbsCurve(List_Pointer(v->EmbeddedCurves, j), &c)){
        List_Delete(Vols);
        // cannot delete: it's embedded in a volume
        return;
      }
    }
  }
  List_Delete(Vols);

  if(c->Num == GModel::current()->getGEOInternals()->MaxLineNum)
    GModel::current()->getGEOInternals()->MaxLineNum--;
  Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c);
  Free_Curve(&c, NULL);
}

static void DeleteSurface(int is)
{
  Surface *s = FindSurface(is);
  if(!s)
    return;
  List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
  for(int i = 0; i < List_Nbr(Vols); i++) {
    Volume *v;
    List_Read(Vols, i, &v);
    for(int j = 0; j < List_Nbr(v->Surfaces); j++) {
      if(!compareSurface(List_Pointer(v->Surfaces, j), &s)){
        List_Delete(Vols);
        // cannot delete: it's on the boundary of a volume
        return;
      }
    }
    for(int j = 0; j < List_Nbr(v->EmbeddedSurfaces); j++) {
      if(!compareSurface(List_Pointer(v->EmbeddedSurfaces, j), &s)){
        List_Delete(Vols);
        // cannot delete: it's embedded in a volume
        return;
      }
    }
  }
  List_Delete(Vols);
  if(s->Num == GModel::current()->getGEOInternals()->MaxSurfaceNum)
    GModel::current()->getGEOInternals()->MaxSurfaceNum--;
  Tree_Suppress(GModel::current()->getGEOInternals()->Surfaces, &s);
  Free_Surface(&s, NULL);
}

static void DeleteVolume(int iv)
{
  Volume *v = FindVolume(iv);
  if(!v)
    return;
  if(v->Num == GModel::current()->getGEOInternals()->MaxVolumeNum)
    GModel::current()->getGEOInternals()->MaxVolumeNum--;
  Tree_Suppress(GModel::current()->getGEOInternals()->Volumes, &v);
  Free_Volume(&v, NULL);
}

void DeletePhysicalPoint(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
  if(p){
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  comparePhysicalGroup);
    Free_PhysicalGroup(&p, NULL);
  }
  GModel::current()->deletePhysicalGroup(0, num);
}

void DeletePhysicalLine(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
  if(p){
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  comparePhysicalGroup);
    Free_PhysicalGroup(&p, NULL);
  }
  GModel::current()->deletePhysicalGroup(1, num);
}

void DeletePhysicalSurface(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
  if(p){
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  comparePhysicalGroup);
    Free_PhysicalGroup(&p, NULL);
  }
  GModel::current()->deletePhysicalGroup(2, num);
}

void DeletePhysicalVolume(int num)
{
  PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
  if(p){
    List_Suppress(GModel::current()->getGEOInternals()->PhysicalGroups, &p,
                  comparePhysicalGroup);
    Free_PhysicalGroup(&p, NULL);
  }
  GModel::current()->deletePhysicalGroup(3, num);
}

void DeleteShape(int Type, int Num)
{
  switch (Type) {
  case MSH_POINT:
  case MSH_POINT_FROM_GMODEL:
    {
      DeletePoint(Num);
      GVertex *gv = GModel::current()->getVertexByTag(Num);
      if(gv) GModel::current()->remove(gv);
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
  case MSH_SEGM_COMPOUND:
  case MSH_SEGM_FROM_GMODEL:
    {
      DeleteCurve(Num);
      DeleteCurve(-Num);
      GEdge *ge = GModel::current()->getEdgeByTag(Num);
      if(ge) GModel::current()->remove(ge);
    }
    break;
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_COMPOUND:
  case MSH_SURF_FROM_GMODEL:
    {
      DeleteSurface(Num);
      GFace *gf = GModel::current()->getFaceByTag(Num);
      if(gf) GModel::current()->remove(gf);
    }
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_COMPOUND:
  case MSH_VOLUME_FROM_GMODEL:
    {
      DeleteVolume(Num);
      GRegion *gr = GModel::current()->getRegionByTag(Num);
      if(gr) GModel::current()->remove(gr);
    }
    break;
  default:
    Msg::Error("Impossible to delete entity %d (of type %d)", Num, Type);
    break;
  }
}

void ColorShape(int Type, int Num, unsigned int Color, bool Recursive)
{
  Curve *c;
  Surface *s;
  Volume *V;

  switch (Type) {
  case MSH_POINT:
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
  case MSH_SEGM_DISCRETE:
    if((c = FindCurve(abs(Num)))) c->SetColor(Color, Recursive);
    break;
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_DISCRETE:
    if((s = FindSurface(abs(Num)))) s->SetColor(Color, Recursive);
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_DISCRETE:
    if((V = FindVolume(abs(Num)))) V->SetColor(Color, Recursive);
    break;
  default:
    break;
  }
}

void VisibilityShape(int Type, int Num, int Mode, bool Recursive)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  Volume *V;

  switch (Type) {
  case MSH_POINT:
  case MSH_POINT_FROM_GMODEL:
    {
      if((v = FindPoint(abs(Num)))) v->SetVisible(Mode, Recursive);
      GVertex *gv = GModel::current()->getVertexByTag(abs(Num));
      if(gv) gv->setVisibility(Mode, Recursive);
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
  case MSH_SEGM_DISCRETE:
  case MSH_SEGM_COMPOUND:
  case MSH_SEGM_FROM_GMODEL:
    {
      if((c = FindCurve(abs(Num)))) c->SetVisible(Mode, Recursive);
      GEdge *ge = GModel::current()->getEdgeByTag(abs(Num));
      if(ge) ge->setVisibility(Mode, Recursive);
    }
    break;
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_DISCRETE:
  case MSH_SURF_COMPOUND:
  case MSH_SURF_FROM_GMODEL:
    {
      if((s = FindSurface(abs(Num)))) s->SetVisible(Mode, Recursive);
      GFace *gf = GModel::current()->getFaceByTag(abs(Num));
      if(gf) gf->setVisibility(Mode, Recursive);
    }
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_DISCRETE:
  case MSH_VOLUME_COMPOUND:
  case MSH_VOLUME_FROM_GMODEL:
    {
      if((V = FindVolume(abs(Num)))) V->SetVisible(Mode, Recursive);
      GRegion *gr = GModel::current()->getRegionByTag(abs(Num));
      if(gr) gr->setVisibility(Mode, Recursive);
    }
    break;
  default:
    break;
  }
}

static int vmode;
static void vis_nod(void *a, void *b){ (*(Vertex **)a)->Visible = vmode; }
static void vis_cur(void *a, void *b){ (*(Curve **)a)->Visible = vmode; }
static void vis_sur(void *a, void *b){ (*(Surface **)a)->Visible = vmode; }
static void vis_vol(void *a, void *b){ (*(Volume **)a)->Visible = vmode; }

void VisibilityShape(char *str, int Type, int Mode, bool Recursive)
{
  vmode = Mode;

  if(!strcmp(str, "all") || !strcmp(str, "*")) {
    switch (Type) {
    case 0:
      Tree_Action(GModel::current()->getGEOInternals()->Points, vis_nod);
      for(GModel::viter it = GModel::current()->firstVertex();
          it != GModel::current()->lastVertex(); it++)
        (*it)->setVisibility(Mode);
      break;
    case 1:
      Tree_Action(GModel::current()->getGEOInternals()->Curves, vis_cur);
      for(GModel::eiter it = GModel::current()->firstEdge();
          it != GModel::current()->lastEdge(); it++)
        (*it)->setVisibility(Mode);
      break;
    case 2:
      Tree_Action(GModel::current()->getGEOInternals()->Surfaces, vis_sur);
      for(GModel::fiter it = GModel::current()->firstFace();
          it != GModel::current()->lastFace(); it++)
        (*it)->setVisibility(Mode);
      break;
    case 3:
      Tree_Action(GModel::current()->getGEOInternals()->Volumes, vis_vol);
      for(GModel::riter it = GModel::current()->firstRegion();
          it != GModel::current()->lastRegion(); it++)
        (*it)->setVisibility(Mode);
      break;
    }
  }
  else {
    VisibilityShape(Type, atoi(str), Mode, Recursive);
  }
}

void SetPartition(int Type, int Num, int Partition)
{
  switch (Type) {
  case MSH_POINT:
  case MSH_POINT_FROM_GMODEL:
    {
      GVertex *gv = GModel::current()->getVertexByTag(Num);
      if(gv){
        for(unsigned int j = 0; j < gv->getNumMeshElements(); j++)
          gv->getMeshElement(j)->setPartition(Partition);
      }
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
  case MSH_SEGM_COMPOUND:
  case MSH_SEGM_FROM_GMODEL:
    {
      GEdge *ge = GModel::current()->getEdgeByTag(Num);
      if(ge){
        for(unsigned int j = 0; j < ge->getNumMeshElements(); j++)
          ge->getMeshElement(j)->setPartition(Partition);
      }
    }
    break;
  case MSH_SURF_TRIC:
  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_COMPOUND:
  case MSH_SURF_FROM_GMODEL:
    {
      GFace *gf = GModel::current()->getFaceByTag(Num);
      if(gf){
        for(unsigned int j = 0; j < gf->getNumMeshElements(); j++)
          gf->getMeshElement(j)->setPartition(Partition);
      }
    }
    break;
  case MSH_VOLUME:
  case MSH_VOLUME_COMPOUND:
  case MSH_VOLUME_FROM_GMODEL:
    {
      GRegion *gr = GModel::current()->getRegionByTag(Num);
      if(gr){
        for(unsigned int j = 0; j < gr->getNumMeshElements(); j++)
          gr->getMeshElement(j)->setPartition(Partition);
      }
    }
    break;
  }
}

Curve *CreateReversedCurve(Curve *c)
{
  Curve *newc = Create_Curve(-c->Num, c->Typ, 1, NULL, NULL, -1, -1, 0., 1.);

  if(List_Nbr(c->Control_Points)){
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

  if(c->Typ == MSH_SEGM_COMPOUND) {
    newc->compound.insert(newc->compound.end(), c->compound.rbegin(),
                          c->compound.rend());
  }

  if(c->Typ == MSH_SEGM_CIRC)
    newc->Typ = MSH_SEGM_CIRC_INV;
  if(c->Typ == MSH_SEGM_CIRC_INV)
    newc->Typ = MSH_SEGM_CIRC;
  if(c->Typ == MSH_SEGM_ELLI)
    newc->Typ = MSH_SEGM_ELLI_INV;
  if(c->Typ == MSH_SEGM_ELLI_INV)
    newc->Typ = MSH_SEGM_ELLI;

  newc->beg = c->end;
  newc->end = c->beg;
  newc->Method = c->Method;
  newc->nbPointsTransfinite = c->nbPointsTransfinite;
  newc->typeTransfinite = -c->typeTransfinite;
  newc->coeffTransfinite = c->coeffTransfinite;
  newc->degre = c->degre;
  newc->ubeg = 1. - c->uend;
  newc->uend = 1. - c->ubeg;
  End_Curve(newc);

  Curve **pc;
  if((pc = (Curve **)Tree_PQuery(GModel::current()->getGEOInternals()->Curves, &newc))) {
    Free_Curve(&newc, NULL);
    return *pc;
  }
  else{
    Tree_Add(GModel::current()->getGEOInternals()->Curves, &newc);
    return newc;
  }
}

int recognize_seg(int typ, List_T *liste, int *seg)
{
  List_T *temp = Tree2List(GModel::current()->getGEOInternals()->Curves);
  int beg, end;
  List_Read(liste, 0, &beg);
  List_Read(liste, List_Nbr(liste) - 1, &end);
  for(int i = 0; i < List_Nbr(temp); i++) {
    Curve *pc;
    List_Read(temp, i, &pc);
    if(pc->Typ == typ && pc->beg->Num == beg && pc->end->Num == end) {
      List_Delete(temp);
      *seg = pc->Num;
      return 1;
    }
  }
  List_Delete(temp);
  return 0;
}

int recognize_loop(List_T *liste, int *loop)
{
  int res = 0;
  *loop = 0;
  List_T *temp = Tree2List(GModel::current()->getGEOInternals()->EdgeLoops);
  for(int i = 0; i < List_Nbr(temp); i++) {
    EdgeLoop *pe;
    List_Read(temp, i, &pe);
    if(!compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

int recognize_surfloop(List_T *liste, int *loop)
{
  int res = 0;
  *loop = 0;
  List_T *temp = Tree2List(GModel::current()->getGEOInternals()->SurfaceLoops);
  for(int i = 0; i < List_Nbr(temp); i++) {
    EdgeLoop *pe;
    List_Read(temp, i, &pe);
    if(!compare2Lists(pe->Curves, liste, fcmp_absint)) {
      res = 1;
      *loop = pe->Num;
      break;
    }
  }
  List_Delete(temp);
  return res;
}

// Linear applications

static void SetTranslationMatrix(double matrix[4][4], double T[3])
{
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      matrix[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }
  for(int i = 0; i < 3; i++)
    matrix[i][3] = T[i];
}

static void SetSymmetryMatrix(double matrix[4][4], double A, double B, double C,
                              double D)
{
  double F = -2.0 / (A * A + B * B + C * C);
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

static void SetDilatationMatrix(double matrix[4][4], double T[3],
                                double A, double B, double C)
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

static void SetRotationMatrix(double matrix[4][4], double Axe[3], double alpha)
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
    for(j = 0; j < 3; j++)
      invplan[i][j] = plan[j][i];
  double interm[3][3];
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      interm[i][j] = 0.0;
      for(k = 0; k < 3; k++)
        interm[i][j] += invplan[i][k] * rot[k][j];
    }
  for(i = 0; i < 4; i++)
    for(j = 0; j < 4; j++)
      matrix[i][j] = 0.0;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) {
      for(k = 0; k < 3; k++)
        matrix[i][j] += interm[i][k] * plan[k][j];
    }
  matrix[3][3] = 1.0;
}

static void vecmat4x4(double mat[4][4], double vec[4], double res[4])
{
  for(int i = 0; i < 4; i++) {
    res[i] = 0.0;
    for(int j = 0; j < 4; j++) {
      res[i] += mat[i][j] * vec[j];
    }
  }
}

#if 0
static void printCurve(Curve *c)
{
  Vertex *v;
  int N = List_Nbr(c->Control_Points);
  Msg::Debug("Curve %d %d cp (%d->%d)", c->Num, N, c->beg->Num, c->end->Num);
  for(int i = 0; i < N; i++) {
    List_Read(c->Control_Points, i, &v);
    Msg::Debug("Vertex %d (%g,%g,%g,%g)", v->Num, v->Pos.X, v->Pos.Y,
               v->Pos.Z, v->lc);
  }
}

static void printSurface(Surface *s)
{
  Curve *c;
  int N = List_Nbr(s->Generatrices);

  Msg::Debug("Surface %d, %d generatrices", s->Num, N);
  for(int i = 0; i < N; i++) {
    List_Read(s->Generatrices, i, &c);
    printCurve(c);
  }
}
#endif

static void ApplyTransformationToPoint(double matrix[4][4], Vertex *v,
                                       bool end_curve_surface=false)
{
  double pos[4], vec[4];

  if(!ListOfTransformedPoints)
    ListOfTransformedPoints = List_Create(50, 50, sizeof(int));

  if(!List_Search(ListOfTransformedPoints, &v->Num, fcmp_absint)) {
    List_Add(ListOfTransformedPoints, &v->Num);
  }
  else
    return;

  vec[0] = v->Pos.X;
  vec[1] = v->Pos.Y;
  vec[2] = v->Pos.Z;
  vec[3] = v->w;
  vecmat4x4(matrix, vec, pos);
  v->Pos.X = pos[0];
  v->Pos.Y = pos[1];
  v->Pos.Z = pos[2];
  v->w = pos[3];

  // Warning: in theory we should always redo these checks if
  // end_curve_surface is true; but in practice this is so slow for
  // big models that we need to provide a way to bypass it (which is
  // OK if the guy who builds the geometry knowns what he's
  // doing). Instead of adding one more option, let's just bypass all
  // the checks if auto_coherence==0...
  if(CTX::instance()->geom.autoCoherence && end_curve_surface){
    List_T *All = Tree2List(GModel::current()->getGEOInternals()->Curves);
    for(int i = 0; i < List_Nbr(All); i++) {
      Curve *c;
      List_Read(All, i, &c);
      for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
        Vertex *pv = *(Vertex **)List_Pointer(c->Control_Points, j);
        if(pv->Num == v->Num){
          End_Curve(c);
          break;
        }
      }
    }
    List_Delete(All);
  }
}

static void ApplyTransformationToCurve(double matrix[4][4], Curve *c)
{
  if(!c->beg || !c->end){
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
  End_Curve(c);
}

static void ApplyTransformationToSurface(double matrix[4][4], Surface *s)
{
  for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
    Curve *c;
    List_Read(s->Generatrices, i, &c);
    Curve *cc = FindCurve(abs(c->Num));
    ApplyTransformationToCurve(matrix, cc);
  }
  End_Surface(s);
}

static void ApplyTransformationToVolume(double matrix[4][4], Volume *v)
{
  for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    ApplyTransformationToSurface(matrix, s);
  }
}

static void ApplicationOnShapes(double matrix[4][4], List_T *shapes)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  Volume *vol;

  List_Reset(ListOfTransformedPoints);

  for(int i = 0; i < List_Nbr(shapes); i++) {
    Shape O;
    List_Read(shapes, i, &O);
    switch (O.Type) {
    case MSH_POINT:
      v = FindPoint(O.Num);
      if(v)
        ApplyTransformationToPoint(matrix, v, true);
      else
        Msg::Error("Unknown point %d", O.Num);
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
      else
        Msg::Error("Unknown curve %d", O.Num);
      break;
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
      s = FindSurface(O.Num);
      if(s)
        ApplyTransformationToSurface(matrix, s);
      else
        Msg::Error("Unknown surface %d", O.Num);
      break;
    case MSH_VOLUME:
      vol = FindVolume(O.Num);
      if(vol)
        ApplyTransformationToVolume(matrix, vol);
      else
        Msg::Error("Unknown volume %d", O.Num);
      break;
    default:
      Msg::Error("Impossible to transform entity %d (of type %d)", O.Num,
                 O.Type);
      break;
    }
  }

  List_Reset(ListOfTransformedPoints);
}

void TranslateShapes(double X, double Y, double Z, List_T *shapes)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence)
    ReplaceAllDuplicates();
}

void DilatShapes(double X, double Y, double Z, double A, double B, double C,
                 List_T *shapes)
{
  double T[3], matrix[4][4];

  T[0] = X;
  T[1] = Y;
  T[2] = Z;
  SetDilatationMatrix(matrix, T, A, B, C);
  ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence)
    ReplaceAllDuplicates();
}

void RotateShapes(double Ax, double Ay, double Az,
                  double Px, double Py, double Pz,
                  double alpha, List_T *shapes)
{
  double A[3], T[3], matrix[4][4];

  T[0] = -Px;
  T[1] = -Py;
  T[2] = -Pz;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, shapes);

  A[0] = Ax;
  A[1] = Ay;
  A[2] = Az;
  SetRotationMatrix(matrix, A, alpha);
  ApplicationOnShapes(matrix, shapes);

  T[0] = Px;
  T[1] = Py;
  T[2] = Pz;
  SetTranslationMatrix(matrix, T);
  ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence)
    ReplaceAllDuplicates();
}

void SymmetryShapes(double A, double B, double C, double D, List_T *shapes)
{
  double matrix[4][4];

  SetSymmetryMatrix(matrix, A, B, C, D);
  ApplicationOnShapes(matrix, shapes);

  if(CTX::instance()->geom.autoCoherence)
    ReplaceAllDuplicates();
}

class ShapeLessThan{
 public:
  bool operator()(Shape *v1, Shape *v2) const
  {
    if(std::abs(v1->Num) < std::abs(v2->Num)) return true;
    return false;
  }
};

void BoundaryShapes(List_T *shapes, List_T *shapesBoundary, bool combined)
{
  for(int i = 0; i < List_Nbr(shapes); i++) {
    Shape O;
    List_Read(shapes, i, &O);
    switch (O.Type) {
    case MSH_POINT:
    case MSH_POINT_BND_LAYER:
    case MSH_POINT_FROM_GMODEL:
      return;
      break;
    case MSH_SEGM_LINE:
    case MSH_SEGM_SPLN:
    case MSH_SEGM_CIRC:
    case MSH_SEGM_CIRC_INV:
    case MSH_SEGM_ELLI:
    case MSH_SEGM_ELLI_INV:
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_NURBS:
    case MSH_SEGM_BEZIER:
    case MSH_SEGM_BND_LAYER:
    case MSH_SEGM_DISCRETE:
    case MSH_SEGM_FROM_GMODEL:
      {
        Curve *c = FindCurve(O.Num);
        if(c){
          if(c->beg){
            Shape sh;
            sh.Type = MSH_POINT;
            sh.Num = c->beg->Num;
            List_Add(shapesBoundary, &sh);
          }
          if(c->end){
            Shape sh;
            sh.Type = MSH_POINT;
            sh.Num = c->end->Num;
            List_Add(shapesBoundary, &sh);
          }
        }
        else{
          GEdge *ge = GModel::current()->getEdgeByTag(O.Num);
          if(ge){
            if(ge->getBeginVertex()){
              Shape sh;
              sh.Type = MSH_POINT_FROM_GMODEL;
              sh.Num = ge->getBeginVertex()->tag();
              List_Add(shapesBoundary, &sh);
            }
            if(ge->getEndVertex()){
              Shape sh;
              sh.Type = MSH_POINT_FROM_GMODEL;
              sh.Num = ge->getEndVertex()->tag();
              List_Add(shapesBoundary, &sh);
            }
          }
          else
            Msg::Error("Unknown curve %d", O.Num);
        }
      }
      break;
    case MSH_SURF_PLAN:
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_BND_LAYER:
    case MSH_SURF_DISCRETE:
    case MSH_SURF_FROM_GMODEL:
      {
        Surface *s = FindSurface(O.Num);
        if(s){
          for(int j = 0; j < List_Nbr(s->Generatrices); j++){
            Curve *c;
            List_Read(s->Generatrices, j, &c);
            Shape sh;
            sh.Type = c->Typ;
            sh.Num = c->Num;
            List_Add(shapesBoundary, &sh);
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(O.Num);
          if(gf){
            std::list<GEdge*> edges(gf->edges());
            for(std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); it++){
              Shape sh;
              sh.Type = MSH_SEGM_FROM_GMODEL;
              sh.Num = (*it)->tag();
              List_Add(shapesBoundary, &sh);
            }
          }
          else
            Msg::Error("Unknown surface %d", O.Num);
        }
      }
      break;
    case MSH_VOLUME:
    case MSH_VOLUME_DISCRETE:
    case MSH_VOLUME_FROM_GMODEL:
      {
        Volume *v = FindVolume(O.Num);
        if(v){
          for(int j = 0; j < List_Nbr(v->Surfaces); j++){
            Surface *s;
            List_Read(v->Surfaces, j, &s);
            Shape sh;
            sh.Type = s->Typ;
            sh.Num = s->Num;
            List_Add(shapesBoundary, &sh);
          }
        }
        else{
          GRegion *gr = GModel::current()->getRegionByTag(O.Num);
          if(gr){
            std::list<GFace*> faces(gr->faces());
            for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
              Shape sh;
              sh.Type = MSH_SURF_FROM_GMODEL;
              sh.Num = (*it)->tag();
              List_Add(shapesBoundary, &sh);
            }
          }
          else
            Msg::Error("Unknown volume %d", O.Num);
        }
      }
      break;
    default:
      Msg::Error("Impossible to take boundary of entity %d (of type %d)", O.Num,
                 O.Type);
      break;
    }
  }

  if(combined){
    // compute boundary of the combined shapes
    std::set<Shape*, ShapeLessThan> combined;
    for(int i = 0; i < List_Nbr(shapesBoundary); i++){
      Shape *s = (Shape*)List_Pointer(shapesBoundary, i);
      std::set<Shape*, ShapeLessThan>::iterator it = combined.find(s);
      if(it == combined.end())
        combined.insert(s);
      else
        combined.erase(it);
    }
    List_T *tmp = List_Create(combined.size(), 10, sizeof(Shape));
    for(std::set<Shape*, ShapeLessThan>::iterator it = combined.begin();
        it != combined.end(); it++)
      List_Add(tmp, *it);
    List_Reset(shapesBoundary);
    List_Copy(tmp, shapesBoundary);
    List_Delete(tmp);
  }
}

// Added by Trevor Strickler for extruding unique compound surface edges
static List_T *GetCompoundUniqueEdges(Surface *ps)
{
  // Two parts:
  // Part 1: create map of keys with values abs(c->Num) that map to integer
  //   counts of abs(c->num) in compound
  // Part 2: Make the unique list

  std::vector<int> comp_surfs = ps->compound;
  if(comp_surfs.size() == 0 || ps->Typ != MSH_SURF_COMPOUND){
    Msg::Error("Surface %d is not compound", ps->Num);
    return 0;
  }

  int num_surfs = comp_surfs.size();
  List_T *bnd_c = List_Create(4, 1, sizeof(Curve*));

  std::map<int, unsigned int> count_map;

  for(int i = 0; i < num_surfs; i++){
    Surface *s = FindSurface(std::abs(comp_surfs[i]));
    if(!s){
      // don't complain: some compound surfaces are not in old GEO database
      //Msg::Warning("Unknown surface %d", std::abs(comp_surfs[i]) );
      List_Delete(bnd_c);
      return 0;
    }
    int num_in_surf = List_Nbr(s->Generatrices);
    for(int m = 0; m < num_in_surf; m++){
      Curve *c=0;
      List_Read(s->Generatrices, m, &c);
      if(!c){
        Msg::Warning("Unknown curve");
        List_Delete(bnd_c);
        return 0;
      }
      if(!FindCurve(-c->Num)) {
        Msg::Warning("Unknown curve %d", -c->Num);
        List_Delete(bnd_c);
        return 0;
      }
      int abs_Num = std::abs(c->Num) ;
      if(count_map.find( abs_Num ) == count_map.end())
        count_map[ abs_Num ] = 1;
      else
        count_map[ abs_Num ]++;
    }
  }

  // Now, create the list of uniques.  Exclude any repeats of abs(c->num) of
  //   course.
  for(int i = 0; i < num_surfs; i++){
    Surface *s = FindSurface(std::abs(comp_surfs[i]));
    int num_in_surf = List_Nbr(s->Generatrices);
    for( int m = 0; m < num_in_surf; m++ ){
      Curve *c;
      List_Read(s->Generatrices, m, &c);
      std::map<int, unsigned int>::iterator itmap = count_map.find(std::abs(c->Num));
      if( itmap != count_map.end() ){
        if( itmap->second == 1 ){
          List_Add(bnd_c, &c);
	  // for duplicates -- if coherence on, do not need. if coherence off,
	  // should not try to find them
          /*bool unique_flag = true;
          std::map<int, unsigned int>::iterator itmap2 = count_map.begin();

          for( ; itmap2 != count_map.end(); itmap2++ ){
            Curve *c_tmp1 = FindCurve( itmap2->first );
            Curve *c_tmp2 = FindCurve( -itmap2->first );

            if( itmap != itmap2 &&
                ( !compareTwoCurves( &c_tmp1, &c ) ||
                  !compareTwoCurves( &c_tmp2, &c ) ) ){
              unique_flag = false;
              break;
            }
          }
          if( unique_flag )
	    List_Add(bnd_c, &c);
	  */
        }
      }
      else{ // if not found the curve in the count_map
        Msg::Error("A problem in finding unique curves in extrusion of compound surface %d",
                   std::abs(ps->Num));
        List_Delete(bnd_c);
        return 0;
      }
    }
  }

  return bnd_c;
}


// Added by Trevor Strickler

// This function returns a pointer to an allocated List_T type that contains an
// ordered list of unique edges for a compound surface.  The edges are grouped
// into loops if there is more than one loop.  The order is in order around a
// loop.
// Only one problem: Sometimes holes can be selected as the first loop, though
// this should not create many real problems on a copied top surface.
static List_T* GetOrderedUniqueEdges(Surface *s)
{
  List_T* unique = GetCompoundUniqueEdges(s);
  if(!unique) return 0;

  // need to sort out the list into ordered, oriented loops before passing
  // these into the gmsh geometry system.
  // Have to get list of surface numbers
  int numgen = List_Nbr(unique);

  if(!numgen){
    List_Delete(unique);
    return 0;
  }

  List_T *gen_nums = List_Create(numgen, 1, sizeof(int));

  for(int i = 0; i < numgen; i++){
    Curve *ctemp = 0;
    List_Read(unique, i, &ctemp);
    if(!ctemp){
      Msg::Error("No such curve");
      List_Delete(gen_nums);
      List_Delete(unique);
      return 0;
    }
    List_Add(gen_nums, &(ctemp->Num));
  }

  sortEdgesInLoop(0, gen_nums, 1);

  // put sorted list of curve pointers back into compnd_gen and generatrices
  List_Reset(unique);
  for(int i = 0; i < List_Nbr(gen_nums); i++){
    Curve *ctemp = 0;
    int j;
    List_Read(gen_nums, i, &j);
    if(!(ctemp = FindCurve(j))){
      Msg::Error("No such curve %d", j);
      List_Delete(gen_nums);
      List_Delete(unique);
      return 0;
    }
    List_Add(unique, &ctemp);
  }

  List_Delete(gen_nums);
  return unique;
}

// Duplicate removal

static int compareTwoPoints(const void *a, const void *b)
{
  Vertex *q = *(Vertex **)a;
  Vertex *w = *(Vertex **)b;

  if(q->Typ != w->Typ)
    return q->Typ - w->Typ;

  if(q->boundaryLayerIndex != w->boundaryLayerIndex)
    return q->boundaryLayerIndex - w->boundaryLayerIndex;

  return comparePosition(a, b);
}

static int compareTwoCurves(const void *a, const void *b)
{
  Curve *c1 = *(Curve **)a;
  Curve *c2 = *(Curve **)b;
  int comp;

  if(c1->Typ != c2->Typ){
    if((c1->Typ == MSH_SEGM_CIRC && c2->Typ == MSH_SEGM_CIRC_INV) ||
       (c1->Typ == MSH_SEGM_CIRC_INV && c2->Typ == MSH_SEGM_CIRC) ||
       (c1->Typ == MSH_SEGM_ELLI && c2->Typ == MSH_SEGM_ELLI_INV) ||
       (c1->Typ == MSH_SEGM_ELLI_INV && c2->Typ == MSH_SEGM_ELLI)){
      // this is still ok
    }
    else
      return c1->Typ - c2->Typ;
  }

  if(List_Nbr(c1->Control_Points) != List_Nbr(c2->Control_Points))
    return List_Nbr(c1->Control_Points) - List_Nbr(c2->Control_Points);

  if(!List_Nbr(c1->Control_Points)){
    if(!c1->beg || !c2->beg)
      return 1;
    comp = compareVertex(&c1->beg, &c2->beg);
    if(comp)
      return comp;
    if(!c1->end || !c2->end)
      return 1;
    comp = compareVertex(&c1->end, &c2->end);
    if(comp)
      return comp;
  }
  else {
    for(int i = 0; i < List_Nbr(c1->Control_Points); i++){
      Vertex *v1, *v2;
      List_Read(c1->Control_Points, i, &v1);
      List_Read(c2->Control_Points, i, &v2);
      comp = compareVertex(&v1, &v2);
      if(comp)
        return comp;
    }
  }
  return 0;
}

static int compareTwoSurfaces(const void *a, const void *b)
{
  Surface *s1 = *(Surface **)a;
  Surface *s2 = *(Surface **)b;

  // checking types is the "right thing" to do (see e.g. compareTwoCurves)
  // but it would break backward compatibility (see e.g. tutorial/t2.geo),
  // so let's just do it for boundary layer surfaces for now:
  if(s1->Typ == MSH_SURF_BND_LAYER || s2->Typ == MSH_SURF_BND_LAYER ||
     s1->Typ == MSH_SURF_COMPOUND || s2->Typ == MSH_SURF_COMPOUND ){
    if(s1->Typ != s2->Typ) return s1->Typ - s2->Typ;
  }

  // if both surfaces have no generatrices, stay on the safe side and
  // assume they are different
  if(!List_Nbr(s1->Generatrices) && !List_Nbr(s2->Generatrices))
    return 1;

  return compare2Lists(s1->Generatrices, s2->Generatrices, compareAbsCurve);
}

static void MaxNumPoint(void *a, void *b)
{
  Vertex *v = *(Vertex **)a;
  GModel::current()->getGEOInternals()->MaxPointNum =
    std::max(GModel::current()->getGEOInternals()->MaxPointNum, v->Num);
}

static void MaxNumCurve(void *a, void *b)
{
  Curve *c = *(Curve **)a;
  GModel::current()->getGEOInternals()->MaxLineNum =
    std::max(GModel::current()->getGEOInternals()->MaxLineNum, c->Num);
}

static void MaxNumSurface(void *a, void *b)
{
  Surface *s = *(Surface **)a;
  GModel::current()->getGEOInternals()->MaxSurfaceNum =
    std::max(GModel::current()->getGEOInternals()->MaxSurfaceNum, s->Num);
}

static void ReplaceDuplicatePointsNew(double tol = -1.)
{
  Msg::Info("New Coherence...");
  if (tol < 0)
    tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;

  // create rtree
  MVertexRTree pos(tol);
  std::map<MVertex*, Vertex*> v2V;
  std::vector<MVertex*> used, unused;
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
    if(c->Extrude && c->Extrude->geo.Mode == EXTRUDED_ENTITY){
      Vertex *V = FindPoint(std::abs(c->Extrude->geo.Source));
      if(V) c->Extrude->geo.Source =
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
    for(int j = 0; j < List_Nbr(s->TrsfPoints); j++){
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
    for(int j = 0; j < List_Nbr(vol->TrsfPoints); j++){
      Vertex *V;
      List_Read(vol->TrsfPoints, j, &V);
      List_Write(vol->TrsfPoints, j,
                 &v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]);
    }
  }
  List_Delete(tmp);

  // replace points in physical groups
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(GModel::current()->getGEOInternals()->PhysicalGroups, i, &p);
    if(p->Typ == MSH_PHYSICAL_POINT){
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        Vertex *V = FindPoint(std::abs(num));
        if(V) List_Write(p->Entities, j,
                         &(v2V[pos.find(V->Pos.X, V->Pos.Y, V->Pos.Z)]->Num));
      }
    }
  }

  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Points);
  for(unsigned int i = 0; i < unused.size(); i++){
    Vertex *V = v2V[unused[i]];
    Tree_Suppress(GModel::current()->getGEOInternals()->Points, &V);
    Free_Vertex(&V, NULL);
    delete unused[i];
  }
  for(unsigned int i = 0; i < used.size(); i++){
    delete used[i];
  }
  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Points);
  Msg::Info("Done new Coherence (removed %d additional points)", start - end);
}

static void ReplaceDuplicatePoints(std::map<int, int> * v_report = 0)
{
  // This routine is logically wrong: the compareTwoPoints() function used in
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
  Tree_T *points2delete = Tree_Create(sizeof(Vertex *), compareVertex);
  Tree_T *allNonDuplicatedPoints = Tree_Create(sizeof(Vertex *), compareTwoPoints);

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
      if(v_report){ // keep track of changes
        std::map<int, int>::iterator m_it = v_report->find(v->Num);
        if(m_it != v_report->end()){
	  Vertex **v_rep = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v);
          if(v_rep)
            m_it->second = (*v_rep)->Num;
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
    GModel::current()->getGEOInternals()->MaxPointNum = 0;
    Tree_Action(GModel::current()->getGEOInternals()->Points, MaxNumPoint);
  }

  bool success = true;

  // Replace old points in curves
  All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    // replace begin/end points
    if(!Tree_Query(allNonDuplicatedPoints, &c->beg)){
      Msg::Debug("Could not replace point %d in old Coherence", c->beg->Num);
      Tree_Insert(GModel::current()->getGEOInternals()->Points, &c->beg);
      Tree_Suppress(points2delete, &c->beg);
      success = false;
    }
    if(!Tree_Query(allNonDuplicatedPoints, &c->end)){
      Msg::Debug("Could not replace point %d in old Coherence", c->end->Num);
      Tree_Insert(GModel::current()->getGEOInternals()->Points, &c->end);
      Tree_Suppress(points2delete, &c->end);
      success = false;
    }
    // replace control points
    for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
      pv = (Vertex **)List_Pointer(c->Control_Points, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))){
        Msg::Debug("Could not replace point %d in old Coherence", (*pv)->Num);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, pv);
        Tree_Suppress(points2delete, pv);
        success = false;
      }
      else
        List_Write(c->Control_Points, j, pv2);
    }
    // replace extrusion sources
    if(c->Extrude && c->Extrude->geo.Mode == EXTRUDED_ENTITY){
      v2 = FindPoint(std::abs(c->Extrude->geo.Source), points2delete);
      if(v2){
        if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v2))){
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
    for(int j = 0; j < List_Nbr(s->TrsfPoints); j++){
      pv = (Vertex **)List_Pointer(s->TrsfPoints, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))){
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
    for(int j = 0; j < List_Nbr(vol->TrsfPoints); j++){
      pv = (Vertex **)List_Pointer(vol->TrsfPoints, j);
      if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, pv))){
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
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer
      (GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_POINT){
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        v2 = FindPoint(std::abs(num), points2delete);
        if(v2){
          if(!(pv2 = (Vertex **)Tree_PQuery(allNonDuplicatedPoints, &v2))){
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

  Tree_Action(points2delete, Free_Vertex);
  Tree_Delete(points2delete);
  Tree_Delete(allNonDuplicatedPoints);

  if(!success) ReplaceDuplicatePointsNew();
}

static void ReplaceDuplicateCurves(std::map<int, int> * c_report = 0)
{
  Curve *c, *c2, **pc, **pc2;
  Surface *s;
  Tree_T *curves2delete = Tree_Create(sizeof(Curve *), compareCurve);
  Tree_T *allNonDuplicatedCurves = Tree_Create(sizeof(Curve *), compareTwoCurves);

  // Create unique curves
  int start = Tree_Nbr(GModel::current()->getGEOInternals()->Curves);

  List_T *All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    if(c->Num > 0) {
      if(!Tree_Search(allNonDuplicatedCurves, &c)) {
        Tree_Insert(allNonDuplicatedCurves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg::Error("Unknown curve %d", -c->Num);
          List_Delete(All);
          Tree_Action(curves2delete, Free_Curve);
          Tree_Delete(curves2delete);
          Tree_Delete(allNonDuplicatedCurves);
          return;
        }
        Tree_Insert(allNonDuplicatedCurves, &c2);
      }
      else {
        Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c);
        if(!(c2 = FindCurve(-c->Num))) {
          Msg::Error("Unknown curve %d", -c->Num);
          break;
        }
        Tree_Suppress(GModel::current()->getGEOInternals()->Curves, &c2);
        Tree_Insert(curves2delete, &c);
        Tree_Insert(curves2delete, &c2);

	if(c_report){ // keep track of changes
	  std::map<int, int>::iterator m_it = c_report->find(c->Num);
	  if(m_it != c_report->end()){
	    Curve **c_rep = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c);
            if(c_rep)
              m_it->second = (*c_rep)->Num;
	  }
	  m_it = c_report->find(c2->Num);
	  if(m_it != c_report->end()){
	    Curve **c_rep_neg = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2);
            if(c_rep_neg)
              m_it->second = (*c_rep_neg)->Num;
	  }
	}
      }
    }
  }
  List_Delete(All);

  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Curves);

  if(start == end) {
    Tree_Action(curves2delete, Free_Curve);
    Tree_Delete(curves2delete);
    Tree_Delete(allNonDuplicatedCurves);
    return;
  }

  Msg::Debug("Removed %d duplicate curves", start - end);

  if(CTX::instance()->geom.oldNewreg) {
    GModel::current()->getGEOInternals()->MaxLineNum = 0;
    Tree_Action(GModel::current()->getGEOInternals()->Curves, MaxNumCurve);
  }

  // Replace old curves in curves
  All = Tree2List(GModel::current()->getGEOInternals()->Curves);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &c);
    // replace extrusion sources
    if(c->Extrude && c->Extrude->geo.Mode == COPIED_ENTITY){
      c2 = FindCurve(std::abs(c->Extrude->geo.Source), curves2delete);
      if(c2){
        if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
          Msg::Error("Could not replace curve %d in Coherence", c2->Num);
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
        Msg::Error("Could not replace curve %d in Coherence", (*pc)->Num);
      else {
        List_Write(s->Generatrices, j, pc2);
        // arghhh: check compareTwoCurves!
        End_Curve(*pc2);
      }
    }
    // replace embedded curves
    if (s->EmbeddedCurves){
      for(int j = 0; j < List_Nbr(s->EmbeddedCurves); j++) {
        pc = (Curve **)List_Pointer(s->EmbeddedCurves, j);
        if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, pc)))
          Msg::Error("Could not replace curve %d in Coherence", (*pc)->Num);
        else {
          List_Write(s->EmbeddedCurves, j, pc2);
          End_Curve(*pc2);
        }
      }
    }
    // replace extrusion sources
    if(s->Extrude && s->Extrude->geo.Mode == EXTRUDED_ENTITY){
      c2 = FindCurve(std::abs(s->Extrude->geo.Source), curves2delete);
      if(c2){
        if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
          Msg::Error("Could not replace curve %d in Coherence", c2->Num);
        else
          s->Extrude->geo.Source = (*pc2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old curves in physical groups
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer
      (GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_LINE){
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        c2 = FindCurve(std::abs(num), curves2delete);
        if(c2){
          if(!(pc2 = (Curve **)Tree_PQuery(allNonDuplicatedCurves, &c2)))
            Msg::Error("Could not replace curve %d in Coherence", c2->Num);
          else
            List_Write(p->Entities, j, &(*pc2)->Num);
        }
      }
    }
  }

  Tree_Action(curves2delete, Free_Curve);
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
	if (!c->degenerate()){
	  List_Add(s->Generatrices, &c);
	  // List_Add(s->GeneratricesByTag, &c->Num);
	}
      }
      if (List_Nbr(ll) != List_Nbr(s->Generatrices))
        Msg::Info("Coherence : Surface %d goes from %d to %d boundary curves",
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
	// DeleteCurve(-c->Num);
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
      std::set<int>::iterator it = unique.find(-s->Num);
      if (it == unique.end()) unique.insert(s->Num);
      else unique.erase(it);
    }
    if(N - unique.size())
      Msg::Info("Coherence : Removing %d seams on Volume %d", N-unique.size(), v->Num);

    List_T *ll = v->Surfaces;
    List_T *ll2 = v->SurfacesOrientations;
    v->Surfaces = List_Create(1, 2, sizeof(Surface *));
    v->SurfacesOrientations = List_Create(1, 2, sizeof(int));
    for(int j = 0; j < List_Nbr(ll); j++) {
      Surface *s;
      List_Read(ll, j, &s);
      if (unique.find(s->Num) != unique.end()){
	List_Add(v->Surfaces,&s);
	List_Add(v->SurfacesOrientations, List_Pointer(ll2, j));
      }
    }
    List_Delete(ll);
    List_Delete(ll2);
    if (List_Nbr(v->Surfaces) == 0){
      Msg::Info("Coherence Volume %d is removed (degenerated)",v->Num);
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
      std::set<int>::iterator it = unique.find(-c->Num);
      if (it == unique.end())unique.insert(c->Num);
      else unique.erase(it);
    }

    if (N-unique.size())
      Msg::Info("Coherence : Removing %d seams on Surface %d", N-unique.size(),s->Num);

    List_T *ll = s->Generatrices;
    s->Generatrices = List_Create(4, 1, sizeof(Curve *));
    // List_Delete(s->GeneratricesByTag);
    // s->GeneratricesByTag = List_Create(4, 1, sizeof(int));
    for(int j = 0; j < List_Nbr(ll); j++) {
      Curve *c;
      List_Read(ll, j, &c);
      if (unique.find(c->Num) != unique.end()){
	List_Add(s->Generatrices,&c);
	// List_Add(s->GeneratricesByTag, &c->Num);
      }
    }
    List_Delete(ll);

    if(s->degenerate()) {
      Msg::Info("Coherence Surface %d is removed (degenerated)", s->Num);
      List_T *Vols = Tree2List(GModel::current()->getGEOInternals()->Volumes);
      for(int k = 0; k < List_Nbr(Vols); k++) {
	Volume *v;
	List_Read(Vols, k, &v);
	List_T *ll= v->Surfaces;
	List_T *ll2=  v->SurfacesOrientations;
	v->Surfaces = List_Create(1, 2, sizeof(Surface *));
	v->SurfacesOrientations = List_Create(1, 2, sizeof(int));
	for(int j = 0; j < List_Nbr(ll); j++) {
	  if(compareSurface(List_Pointer(ll, j), &s)){
	    List_Add(v->Surfaces, List_Pointer(ll, j));
	    List_Add(v->SurfacesOrientations, List_Pointer(ll2, j));
	  }
	}
	List_Delete (ll);
	List_Delete (ll2);
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
    if(!c->degenerate())Nd++;
  }
  return Nd == 0;
}

static void ReplaceDuplicateSurfaces(std::map<int, int> *s_report = 0)
{
  Surface *s, *s2, **ps, **ps2;
  Volume *vol;
  Tree_T *surfaces2delete = Tree_Create(sizeof(Surface *), compareSurface);
  Tree_T *allNonDuplicatedSurfaces = Tree_Create(sizeof(Surface *), compareTwoSurfaces);

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

	if(s_report){ // keep track of changes
	  std::map<int, int>::iterator m_it = (*s_report).find(s->Num);
	  if(m_it != s_report->end()){
	    Surface **s_rep = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s);
            if(s_rep)
              m_it->second = (*s_rep)->Num;
	  }
	}
      }
    }
  }
  List_Delete(All);

  int end = Tree_Nbr(GModel::current()->getGEOInternals()->Surfaces);

  if(start == end) {
    Tree_Action(surfaces2delete, Free_Surface);
    Tree_Delete(surfaces2delete);
    Tree_Delete(allNonDuplicatedSurfaces);
    return;
  }

  Msg::Debug("Removed %d duplicate surfaces", start - end);

  if(CTX::instance()->geom.oldNewreg) {
    GModel::current()->getGEOInternals()->MaxSurfaceNum = 0;
    Tree_Action(GModel::current()->getGEOInternals()->Surfaces, MaxNumSurface);
  }

  // Replace old surfaces in surfaces
  All = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(All); i++) {
    List_Read(All, i, &s);
    // replace extrusion sources
    if(s->Extrude && s->Extrude->geo.Mode == COPIED_ENTITY){
      s2 = FindSurface(std::abs(s->Extrude->geo.Source), surfaces2delete);
      if(s2){
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
    if(vol->Extrude && vol->Extrude->geo.Mode == EXTRUDED_ENTITY){
      s2 = FindSurface(std::abs(vol->Extrude->geo.Source), surfaces2delete);
      if(s2){
        if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s2)))
          Msg::Error("Could not replace surface %d in Coherence", s2->Num);
        else
          vol->Extrude->geo.Source = (*ps2)->Num;
      }
    }
  }
  List_Delete(All);

  // Replace old surfaces in physical groups
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer
      (GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_SURFACE){
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        s2 = FindSurface(std::abs(num), surfaces2delete);
        if(s2){
          if(!(ps2 = (Surface **)Tree_PQuery(allNonDuplicatedSurfaces, &s2)))
            Msg::Error("Could not replace surface %d in Coherence", s2->Num);
          else
            List_Write(p->Entities, j, &(*ps2)->Num);
        }
      }
    }
  }

  Tree_Action(surfaces2delete, Free_Surface);
  Tree_Delete(surfaces2delete);
  Tree_Delete(allNonDuplicatedSurfaces);
}

static void ReplaceAllDuplicates(std::vector<std::map<int, int> > &report)
{
  std::map<int, int> *vertex_report = 0;
  std::map<int, int> *curve_report = 0;
  std::map<int, int> *surface_report = 0;
  if(report.size() >=1 && report[0].size())
    vertex_report = &(report[0]);
  if(report.size() >=2 && report[1].size())
    curve_report = &(report[1]);
  if(report.size() >= 3 && report[2].size())
    surface_report = &(report[2]);

  ReplaceDuplicatePoints(vertex_report);
  ReplaceDuplicateCurves(curve_report);
  ReplaceDuplicateSurfaces(surface_report);

  if(CTX::instance()->geom.autoCoherence == 2){
    RemoveDegenerateCurves();
    RemoveDegenerateSurfaces();
    RemoveDegenerateVolumes();
  }
}

void ReplaceAllDuplicates()
{
  std::vector<std::map<int,int> > report;
  report.clear();
  ReplaceAllDuplicates(report);
}

void ReplaceAllDuplicatesNew(double tol)
{
  if (tol < 0)
    tol = CTX::instance()->geom.tolerance * CTX::instance()->lc;
  ReplaceDuplicatePointsNew(tol);
  ReplaceDuplicateCurves(NULL);
  ReplaceDuplicateSurfaces(NULL);
}

// Extrusion routines

void ProtudeXYZ(double &x, double &y, double &z, ExtrudeParams *e)
{
  double matrix[4][4];
  double T[3];
  Vertex v(x, y, z);

  T[0] = -e->geo.pt[0];
  T[1] = -e->geo.pt[1];
  T[2] = -e->geo.pt[2];
  SetTranslationMatrix(matrix, T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  SetRotationMatrix(matrix, e->geo.axe, e->geo.angle);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  T[0] = -T[0];
  T[1] = -T[1];
  T[2] = -T[2];
  SetTranslationMatrix(matrix, T);
  List_Reset(ListOfTransformedPoints);
  ApplyTransformationToPoint(matrix, &v);

  x = v.Pos.X;
  y = v.Pos.Y;
  z = v.Pos.Z;

  List_Reset(ListOfTransformedPoints);
}

int Extrude_ProtudePoint(int type, int ip,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Curve **pc, Curve **prc, int final,
			 ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3], d;
  Vertex V, *pv, *newp, *chapeau;
  Curve *c;
  int i;

  pv = &V;
  pv->Num = ip;
  *pc = *prc = NULL;
  if(!Tree_Query(GModel::current()->getGEOInternals()->Points, &pv))
    return 0;

  Msg::Debug("Extrude Point %d", ip);

  chapeau = DuplicateVertex(pv);

  switch (type) {
  case TRANSLATE:
    T[0] = T0;
    T[1] = T1;
    T[2] = T2;
    SetTranslationMatrix(matrix, T);
    List_Reset(ListOfTransformedPoints);
    ApplyTransformationToPoint(matrix, chapeau);
    if(!comparePosition(&pv, &chapeau))
      return pv->Num;
    c = Create_Curve(NEWLINE(), MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    List_Add(c->Control_Points, &chapeau);
    c->beg = pv;
    c->end = chapeau;
    break;
  case BOUNDARY_LAYER:
    chapeau->Typ = MSH_POINT_BND_LAYER;
    if(e) chapeau->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    c = Create_Curve(NEWLINE(), MSH_SEGM_BND_LAYER, 1, NULL, NULL, -1, -1, 0., 1.);
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
    if(!comparePosition(&pv, &chapeau))
      return pv->Num;
    c = Create_Curve(NEWLINE(), MSH_SEGM_CIRC, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points = List_Create(3, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;
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
    prosca(T, Ax, &d);
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
    c = Create_Curve(NEWLINE(), MSH_SEGM_SPLN, 1, NULL, NULL, -1, -1, 0., 1.);
    c->Control_Points =
      List_Create(CTX::instance()->geom.extrudeSplinePoints + 1, 1, sizeof(Vertex *));
    c->Extrude = new ExtrudeParams;
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    if(e)
      c->Extrude->mesh = e->mesh;
    List_Add(c->Control_Points, &pv);
    c->beg = pv;
    for(i = 0; i < CTX::instance()->geom.extrudeSplinePoints; i++) {
      if(i)
        chapeau = DuplicateVertex(chapeau);
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
  default:
    Msg::Error("Unknown extrusion type");
    return pv->Num;
  }

  End_Curve(c);
  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
  *pc = c;
  *prc = FindCurve(-c->Num);

  List_Reset(ListOfTransformedPoints);

  int chap_num = chapeau->Num;
  int body_num = c->Num;

  if(CTX::instance()->geom.autoCoherence && final){
    std::vector<std::map<int, int> > report(3);
    report[0][chap_num] = chap_num;
    report[1][body_num] = body_num;
    ReplaceAllDuplicates(report);
    std::map<int, int>::iterator m_it = report[0].find(chap_num);
    if(m_it != report[0].end())
      chap_num = report[0][chap_num];
    else
      chap_num = 0;
    if(report[1][body_num] != body_num)
      *pc = *prc = NULL;
  }
  return chap_num;
}

int Extrude_ProtudeCurve(int type, int ic,
			 double T0, double T1, double T2,
			 double A0, double A1, double A2,
			 double X0, double X1, double X2, double alpha,
			 Surface **ps, int final,
			 ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *CurveBeg, *CurveEnd;
  Curve *ReverseChapeau, *ReverseBeg, *ReverseEnd;
  Curve *pc, *revpc, *chapeau;
  Surface *s;

  pc = FindCurve(ic);
  revpc = FindCurve(-ic);
  *ps = NULL;

  if(!pc || !revpc){
    return 0;
  }

  if(!pc->beg || !pc->end){
    Msg::Error("Cannot extrude curve with no begin/end points");
    return 0;
  }

  Msg::Debug("Extrude Curve %d", ic);

  chapeau = DuplicateCurve(pc);

  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = pc->Num;
  if(e)
    chapeau->Extrude->mesh = e->mesh;

  switch (type) {
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
    if(chapeau->beg){
      chapeau->beg->Typ = MSH_POINT_BND_LAYER;
      if(e) chapeau->beg->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    if(chapeau->end){
      chapeau->end->Typ = MSH_POINT_BND_LAYER;
      if(e) chapeau->end->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    for(int i = 0; i < List_Nbr(chapeau->Control_Points); i++){
      Vertex *v;
      List_Read(chapeau->Control_Points, i, &v);
      if(e) v->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
    }
    revpc = FindCurve(-chapeau->Num);
    if(revpc) revpc->Typ = MSH_SEGM_BND_LAYER;
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
  default:
    Msg::Error("Unknown extrusion type");
    return pc->Num;
  }

  Extrude_ProtudePoint(type, pc->beg->Num, T0, T1, T2,
                       A0, A1, A2, X0, X1, X2, alpha,
                       &CurveBeg, &ReverseBeg, 0, e);
  Extrude_ProtudePoint(type, pc->end->Num, T0, T1, T2,
                       A0, A1, A2, X0, X1, X2, alpha,
                       &CurveEnd, &ReverseEnd, 0, e);

  if(!CurveBeg && !CurveEnd){
    return pc->Num;
  }

  // FIXME: if we extrude by rotation a (non-straight) curve defined by 2 end
  // points, with a rotation axis going through the end points, the resulting
  // surface would have 2 bounding edges (the axis and the curve). We cannot
  // handle this case.

  if(type == BOUNDARY_LAYER)
    s = Create_Surface(NEWSURFACE(), MSH_SURF_BND_LAYER);
  else if(!CurveBeg || !CurveEnd)
    s = Create_Surface(NEWSURFACE(), MSH_SURF_TRIC);
  else
    s = Create_Surface(NEWSURFACE(), MSH_SURF_REGL);

  s->Generatrices = List_Create(4, 1, sizeof(Curve *));
  s->Extrude = new ExtrudeParams;
  s->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  s->Extrude->geo.Source = pc->Num;
  if(e)
    s->Extrude->mesh = e->mesh;

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

  End_Surface(s);
  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);

  List_Reset(ListOfTransformedPoints);

  *ps = s;

  int chap_num = chapeau->Num;
  int body_num = s->Num;

  if(CTX::instance()->geom.autoCoherence && final){
    std::vector<std::map<int, int> > report(3);
    report[1][chap_num] = chap_num;
    report[2][body_num] = body_num;
    ReplaceAllDuplicates(report);
    std::map<int, int>::iterator m_it = report[1].find(chap_num);
    if(m_it != report[1].end())
      chap_num = report[1][chap_num];
    else
      chap_num = 0;
    if(report[2][body_num] != body_num)
      *ps = NULL;
  }

  return chap_num;
}


int Extrude_ProtudeSurface(int type, int is,
			   double T0, double T1, double T2,
			   double A0, double A1, double A2,
			   double X0, double X1, double X2, double alpha,
			   Volume **pv, ExtrudeParams *e)
{
  double matrix[4][4], T[3], Ax[3];
  Curve *c, *c2;
  int i;
  Surface *s, *ps, *chapeau;

  *pv = NULL;

  // 'is' can be negative, to signify that the surface orientation
  // should be reversed. This orientation information is only used at
  // the moment when creating boundary layers
  if(!(ps = FindSurface(std::abs(is))))
    return 0;

  Msg::Debug("Extrude Surface %d", is);

  chapeau = DuplicateSurface(ps);
  chapeau->Extrude = new ExtrudeParams(COPIED_ENTITY);
  chapeau->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  chapeau->Extrude->geo.Source = is; // not ps->Num: we need the sign info
  if(e)
    chapeau->Extrude->mesh = e->mesh;

  for(i = 0; i < List_Nbr(chapeau->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c2);
    List_Read(chapeau->Generatrices, i, &c);
    if(c->Num < 0){
      int nn = -c->Num;
      if(!(c = FindCurve(nn))) {
        Msg::Error("Unknown curve %d", nn);
        return ps->Num;
      }
    }
    c->Extrude = new ExtrudeParams(COPIED_ENTITY);
    c->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
    // don't take the abs(): the sign of c2->Num is important (used
    // when copying the mesh in the extrusion routine)
    c->Extrude->geo.Source = c2->Num;
    if(e)
      c->Extrude->mesh = e->mesh;
  }

  // FIXME: this is a really ugly hack for backward compatibility, so
  // that we don't screw up the old .geo files too much. (Before
  // version 1.54, we didn't always create new volumes during "Extrude
  // Surface". Now we do, but with "CTX::instance()->geom.oldNewreg==1", this
  // bumps the NEWREG() counter, and thus changes the whole automatic
  // numbering sequence.) So we locally force oldNewreg to 0: in most
  // cases, since we define points, curves, etc., before defining
  // volumes, the NEWVOLUME() call below will return a fairly low
  // number, that will not interfere with the other numbers...
  int tmp = CTX::instance()->geom.oldNewreg;
  CTX::instance()->geom.oldNewreg = 0;
  Volume *v = Create_Volume(NEWVOLUME(), MSH_VOLUME);
  CTX::instance()->geom.oldNewreg = tmp;

  v->Extrude = new ExtrudeParams;
  v->Extrude->fill(type, T0, T1, T2, A0, A1, A2, X0, X1, X2, alpha);
  v->Extrude->geo.Source = is;
  if(e)
    v->Extrude->mesh = e->mesh;
  int ori = -1;
  List_Add(v->Surfaces, &ps);
  List_Add(v->SurfacesOrientations, &ori);
  ori = 1;
  List_Add(v->Surfaces, &chapeau);
  List_Add(v->SurfacesOrientations, &ori);

  for(i = 0; i < List_Nbr(ps->Generatrices); i++) {
    List_Read(ps->Generatrices, i, &c);
    Extrude_ProtudeCurve(type, c->Num, T0, T1, T2, A0, A1, A2, X0, X1, X2,
                         alpha, &s, 0, e);
    if(s){
      if(c->Num < 0)
        ori = -1;
      else
        ori = 1;
      List_Add(v->Surfaces, &s);
      List_Add(v->SurfacesOrientations, &ori);
    }
  }

  switch (type) {
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
      if(c->beg){
        c->beg->Typ = MSH_POINT_BND_LAYER;
        if(e) c->beg->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
      }
      if(c->end){
        c->end->Typ = MSH_POINT_BND_LAYER;
        if(e) c->end->boundaryLayerIndex = e->mesh.BoundaryLayerIndex;
      }
      for(int i = 0; i < List_Nbr(c->Control_Points); i++){
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
  default:
    Msg::Error("Unknown extrusion type");
    break;
  }

  // this is done only for backward compatibility with the old
  // numbering scheme
  Tree_Suppress(GModel::current()->getGEOInternals()->Surfaces, &chapeau);

  chapeau->Num = NEWSURFACE();

  GModel::current()->getGEOInternals()->MaxSurfaceNum = chapeau->Num;
  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &chapeau);

  Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);

  *pv = v;

  int chap_num = chapeau->Num;

  if(CTX::instance()->geom.autoCoherence){
    std::vector<std::map<int, int> > report(3);
    report[2][chap_num] = chap_num;
    ReplaceAllDuplicates(report);
    std::map<int, int>::iterator m_it = (report[2]).find(chap_num);
    if(m_it != report[2].end())
      chap_num = report[2][chap_num];
    else
      chap_num = 0;
  }

  List_Reset(ListOfTransformedPoints);

  return chap_num;
}

void ExtrudeShape(int extrude_type, int shape_type, int shape_num,
                  double T0, double T1, double T2,
                  double A0, double A1, double A2,
                  double X0, double X1, double X2, double alpha,
                  ExtrudeParams *e,
                  List_T *list_out)
{
  Shape shape;
  shape.Type = shape_type;
  shape.Num = shape_num;
  List_T *tmp = List_Create(1, 1, sizeof(Shape));
  List_Add(tmp, &shape);
  ExtrudeShapes(extrude_type, tmp,
                T0, T1, T2,
                A0, A1, A2,
                X0, X1, X2, alpha,
                e,
                list_out);
  List_Delete(tmp);
}

void ExtrudeShapes(int type, List_T *list_in,
                   double T0, double T1, double T2,
                   double A0, double A1, double A2,
                   double X0, double X1, double X2, double alpha,
                   ExtrudeParams *e,
                   List_T *list_out)
{

  for(int i = 0; i < List_Nbr(list_in); i++){
    Shape shape;
    List_Read(list_in, i, &shape);
    switch(shape.Type){
    case MSH_POINT:
      {
        Curve *pc = 0, *prc = 0;
        Shape top;
        top.Num = Extrude_ProtudePoint(type, shape.Num, T0, T1, T2,
                                       A0, A1, A2, X0, X1, X2, alpha,
                                       &pc, &prc, 1, e);
        top.Type = MSH_POINT;
        List_Add(list_out, &top);
        if(pc){
          Shape body;
          body.Num = pc->Num;
          body.Type = pc->Typ;
          List_Add(list_out, &body);
        }
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
      {
        Surface *ps = 0;
        Shape top;
        top.Num = Extrude_ProtudeCurve(type, shape.Num, T0, T1, T2,
                                       A0, A1, A2, X0, X1, X2, alpha,
                                       &ps, 1, e);
        Curve *pc = FindCurve(top.Num);
        top.Type = pc ? pc->Typ : 0;
        List_Add(list_out, &top);
        if(ps){
          Shape body;
          body.Num = ps->Num;
          body.Type = ps->Typ;
          List_Add(list_out, &body);
          if(CTX::instance()->geom.extrudeReturnLateral){
            for(int j = 0; j < List_Nbr(ps->Generatrices); j++){
              Curve *c;
              List_Read(ps->Generatrices, j, &c);
              if(abs(c->Num) != shape.Num && abs(c->Num) != top.Num){
                Shape side;
                side.Num = c->Num;
                side.Type = c->Typ;
                List_Add(list_out, &side);
              }
            }
          }
        }
      }
      break;
    case MSH_SURF_REGL:
    case MSH_SURF_TRIC:
    case MSH_SURF_PLAN:
    case MSH_SURF_DISCRETE:
    case MSH_SURF_COMPOUND:
      {
        if(shape.Type == MSH_SURF_COMPOUND){
          if(!(e && e->mesh.ExtrudeMesh)){
            Msg::Error("Impossible to extrude compound entity %d without also extruding mesh!",
                       abs(shape.Num) );
            break;
          }
        }

        Volume *pv = 0;
        Shape top;
        top.Num = Extrude_ProtudeSurface(type, shape.Num, T0, T1, T2,
                                         A0, A1, A2, X0, X1, X2, alpha,
                                         &pv, e);
        Surface *ps = FindSurface(top.Num);
        top.Type = ps ? ps->Typ : 0;

        List_Add(list_out, &top);
        if(pv){
          Shape body;
          body.Num = pv->Num;
          body.Type = pv->Typ;
          List_Add(list_out, &body);
          if(CTX::instance()->geom.extrudeReturnLateral){
            for(int j = 0; j < List_Nbr(pv->Surfaces); j++){
              Surface *s;
              List_Read(pv->Surfaces, j, &s);
              if(abs(s->Num) != shape.Num && abs(s->Num) != top.Num){
                Shape side;
                side.Num = s->Num;
                side.Type = s->Typ;
                List_Add(list_out, &side);
              }
            }
          }
        }
      }
      break;
    default:
      Msg::Error("Impossible to extrude entity %d (of type %d)",
                 shape.Num, shape.Type);
      break;
    }
  }

}

// Projection of a point on a surface

struct PointSurface{
  Vertex *p;
  Surface *s;
};

static bool projectPS(fullVector<double> &x, fullVector<double> &res, void *data)
{
  PointSurface *ps = (PointSurface*)data;
  Vertex c = InterpolateSurface(ps->s, x(0), x(1), 0, 0);
  Vertex du = InterpolateSurface(ps->s, x(0), x(1), 1, 1);
  Vertex dv = InterpolateSurface(ps->s, x(0), x(1), 1, 2);
  res(0) =
    (c.Pos.X - ps->p->Pos.X) * du.Pos.X +
    (c.Pos.Y - ps->p->Pos.Y) * du.Pos.Y +
    (c.Pos.Z - ps->p->Pos.Z) * du.Pos.Z;
  res(1) =
    (c.Pos.X - ps->p->Pos.X) * dv.Pos.X +
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
  double d2 =
    (pp.Pos.X - p.Pos.X) * (pp.Pos.X - p.Pos.X) +
    (pp.Pos.Y - p.Pos.Y) * (pp.Pos.Y - p.Pos.Y) +
    (pp.Pos.Z - p.Pos.Z) * (pp.Pos.Z - p.Pos.Z) ;
  if(d2 < 1.e-12) return true;

  double UMIN = 0.;
  double UMAX = 1.;
  double VMIN = 0.;
  double VMAX = 1.;
  int ITER = 0;
  while(1) {
    bool success = newton_fd(projectPS, x, &ps);
    if(success && x(0) >= UMIN && x(0) <= UMAX && x(1) >= VMIN && x(1) <= VMAX){
      p = InterpolateSurface(s, x(0), x(1), 0, 0);
      uv[0] = x(0);
      uv[1] = x(1);
      if (ITER >= 0)
        Msg::Info("ProjectPoint (%g,%g,%g) On Surface %d converged after %d iterations",
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
    for (int i = 0; i < NSAMPLES; i++){
      const double U = i / (double)(NSAMPLES - 1);
      for (int j = 0; j < NSAMPLES; j++){
        const double V = j / (double)(NSAMPLES - 1);
        Vertex pp = InterpolateSurface(s, U, V, 0, 0);
        double d2 =
          (pp.Pos.X - p.Pos.X) * (pp.Pos.X - p.Pos.X) +
          (pp.Pos.Y - p.Pos.Y) * (pp.Pos.Y - p.Pos.Y) +
          (pp.Pos.Z - p.Pos.Z) * (pp.Pos.Z - p.Pos.Z);
        if (d2 < dmin) {
          dmin = d2;
          uok = U;
          vok = V;
        }
      }
    }
    p = InterpolateSurface(s, uok, vok, 0, 0);
    uv[0] = uok;
    uv[1] = vok;
    if (ITER > 0)
      Msg::Info("Brute force method used for projection of point (%g %g %g) on surface %d",
                p.Pos.X, p.Pos.Y, p.Pos.Z, s->Num);
    return true;
  }
  return false;
}

// Split line

static Curve *_create_splitted_curve(Curve *c,List_T *nodes)
{
  int  beg, end;
  List_Read(nodes, 0, &beg);
  List_Read(nodes, List_Nbr(nodes) - 1, &end);
  int id = NEWLINE();
  Curve *cnew = NULL;
  switch(c->Typ){
  case MSH_SEGM_LINE:
    cnew = Create_Curve(id, c->Typ, 1, nodes, NULL, -1, -1, 0., 1.);
    break;
  case MSH_SEGM_SPLN:
    cnew = Create_Curve(id, c->Typ, 3, nodes, NULL, -1, -1, 0., 1.);
    break;
  case MSH_SEGM_BSPLN:
    cnew = Create_Curve(id, c->Typ, 2, nodes, NULL, -1, -1, 0., 1.);
    break;
  default : //should never reach this point...
    Msg::Error("Cannot split a curve with type %i", c->Typ);
    return NULL;
  }
  Tree_Add(GModel::current()->getGEOInternals()->Curves, &cnew);
  CreateReversedCurve(cnew);
  return cnew;
}

bool SplitCurve(int line_id, List_T *vertices_id, List_T *shapes)
{
  Curve *c = FindCurve(line_id);
  if(!c){
    Msg::Error("Curve %i does not exists", line_id);
    return false;
  }
  switch (c->Typ){
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
    break;
  default:
    Msg::Error("Cannot split curve %i with type %i", line_id, c->Typ);
    return false;
  }
  std::set<int> v_break;
  for(int i = 0; i < List_Nbr(vertices_id); i++){
    int id;
    List_Read(vertices_id, i, &id);
    v_break.insert(id);
  }
  bool is_periodic = (c->beg == c->end);
  bool first_periodic = true;
  bool last_periodic = false;
  List_T *new_list = List_Create(1, List_Nbr(c->Control_Points) / 10, sizeof(int));
  List_T *num_shapes = List_Create(2, 1, sizeof(int));
  Vertex *pv;
  for (int i = 0; i < List_Nbr(c->Control_Points); i++){
    List_Read(c->Control_Points, i, &pv);
    List_Add(new_list, &pv->Num);
    if(v_break.find(pv->Num) != v_break.end() && List_Nbr(new_list) > 1){
      if(last_periodic)
        break;
      if(!(is_periodic&&first_periodic)){
        Curve *cnew = _create_splitted_curve(c, new_list);
        List_Add(shapes, &cnew);
        List_Add(num_shapes, &cnew->Num);
      }
      first_periodic = false;
      List_Reset(new_list);
      List_Add(new_list, &pv->Num);
    }
    if( i== (List_Nbr(c->Control_Points) - 1) && is_periodic && ! first_periodic){
      i = 0;
      last_periodic = true;
    }
  }
  if(List_Nbr(new_list) > 1){
    Curve *cnew = _create_splitted_curve(c, new_list);
    List_Add(shapes, &cnew);
    List_Add(num_shapes, &cnew->Num);
  }
  // replace original curve by the new curves in all surfaces (and for
  // the opposite curve)
  List_T *rshapes = List_Create(2, 1, sizeof(Shape));
  int N = List_Nbr(shapes);
  for(int i = 0; i < List_Nbr(shapes); i++){
    Curve *cc, *rcc;
    List_Read(shapes, N - i - 1, &cc);
    rcc=FindCurve(-cc->Num);
    List_Add(rshapes, &rcc);
  }
  List_T *Surfs = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
  for(int i = 0; i < List_Nbr(Surfs); i++) {
    Surface *s;
    List_Read(Surfs, i, &s);
    for(int j = 0; j < List_Nbr(s->Generatrices); j++) {
      Curve *surface_curve;
      List_Read(s->Generatrices, j, &surface_curve);
      if(surface_curve->Num == c->Num){
        List_Remove(s->Generatrices, j);
        List_Insert_In_List(shapes, j, s->Generatrices);
        j += List_Nbr(shapes) - 1;
      }
      else if(surface_curve->Num == -c->Num){
        List_Remove(s->Generatrices, j);
        List_Insert_In_List(rshapes, j, s->Generatrices);
        j += List_Nbr(shapes) - 1;
      }
    }
    if (s->EmbeddedCurves){
      for(int j = 0; j < List_Nbr(s->EmbeddedCurves); j++) {
        Curve *surface_curve;
        List_Read(s->EmbeddedCurves, j, &surface_curve);
        if(surface_curve->Num == c->Num){
          List_Remove(s->EmbeddedCurves, j);
          List_Insert_In_List(shapes, j, s->EmbeddedCurves);
          j += List_Nbr(shapes) - 1;
        }
        else if(surface_curve->Num == -c->Num){
          List_Remove(s->EmbeddedCurves, j);
          List_Insert_In_List(rshapes, j, s->EmbeddedCurves);
          j += List_Nbr(shapes) - 1;
        }
      }
    }
  }
  List_Delete(Surfs);

  // replace original curve by the new curves in physical groups
  for(int i = 0; i < List_Nbr(GModel::current()->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer
      (GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_LINE){
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        if (num == c->Num){
          List_Remove(p->Entities, j);
          List_Insert_In_List(num_shapes, j, p->Entities);
          j += List_Nbr(num_shapes) - 1;
        }
      }
    }
  }

  DeleteShape(c->Typ, c->Num);
  List_Delete(new_list);
  List_Delete(rshapes);
  List_Delete(num_shapes);
  return true;
}

// Intersect a curve with a surface

struct CurveSurface{
  Curve *c;
  Surface *s;
};

static bool intersectCS(fullVector<double> &uvt, fullVector<double> &res, void *data)
{
  CurveSurface *cs = (CurveSurface*)data;
  Vertex vs = InterpolateSurface(cs->s, uvt(0), uvt(1), 0, 0);
  Vertex vc = InterpolateCurve(cs->c, uvt(2), 0);
  res(0) = vs.Pos.X - vc.Pos.X;
  res(1) = vs.Pos.Y - vc.Pos.Y;
  res(2) = vs.Pos.Z - vc.Pos.Z;
  return true;
}


bool IntersectCurvesWithSurface(List_T *curve_ids, int surface_id, List_T *shapes)
{
  Surface *s = FindSurface(surface_id);
  if(!s){
    Msg::Error("Unknown surface %d", surface_id);
    return false;
  }
  for(int i = 0; i < List_Nbr(curve_ids); i++){
    double curve_id;
    List_Read(curve_ids, i, &curve_id);
    Curve *c = FindCurve((int)curve_id);
    if(c){
      CurveSurface cs = {c, s};
      fullVector<double> uvt(3);
      uvt(0) = 0.5;
      uvt(1) = 0.5;
      uvt(2) = 0.5;
      if(newton_fd(intersectCS, uvt, &cs)){
        Vertex p = InterpolateCurve(c, uvt(2), 0);
        Vertex *v = Create_Vertex(NEWPOINT(), p.Pos.X, p.Pos.Y, p.Pos.Z, p.lc, p.u);
        Tree_Insert(GModel::current()->getGEOInternals()->Points, &v);
        Shape sh;
        sh.Type = MSH_POINT;
        sh.Num = v->Num;
        List_Add(shapes, &sh);
      }
    }
    else{
      Msg::Error("Uknown curve %d", (int)curve_id);
      return false;
    }
  }
  return true;
}

// Bunch of utility routines

void sortEdgesInLoop(int num, List_T *edges, bool orient)
{
  // This function sorts the edges in an EdgeLoop and detects any
  // subloops. Warning: the input edges are supposed to be *oriented* (Without
  // this sort, it is very difficult to write general scriptable surface
  // generation in complex cases)
  Curve *c, *c0, *c1, *c2;
  int nbEdges = List_Nbr(edges);
  List_T *temp = List_Create(nbEdges, 1, sizeof(Curve *));

  for(int i = 0; i < nbEdges; i++) {
    int j;
    List_Read(edges, i, &j);
    if((c = FindCurve(j))){
      List_Add(temp, &c);
      if(c->Typ == MSH_SEGM_DISCRETE || c->Typ == MSH_SEGM_COMPOUND){
        Msg::Debug("Aborting line loop sort for discrete or compound edge: "
                   "let's hope you know what you're doing ;-)");
        List_Delete(temp);
        return;
      }
    }
    else{
      Msg::Debug("Unknown curve %d, aborting line loop sort: "
                 "let's hope you know what you're doing ;-)", j);
      List_Delete(temp);
      return;
    }
  }
  List_Reset(edges);

  int j = 0, k = 0;
  c0 = c1 = *(Curve **)List_Pointer(temp, 0);
  List_Add(edges, &c1->Num);
  List_PSuppress(temp, 0);
  while(List_Nbr(edges) < nbEdges) {
    for(int i = 0; i < List_Nbr(temp); i++) {
      c2 = *(Curve **)List_Pointer(temp, i);
      //reverse loop if not ordered correctly !
      if (orient && c1->end == c2->end){
	Curve *c2R = CreateReversedCurve(c2);
	c2 = c2R;
      }
      if(c1->end == c2->beg) {
        List_Add(edges, &c2->Num);
        List_PSuppress(temp, i);
        c1 = c2;
        if(c2->end == c0->beg) {
          if(List_Nbr(temp)) {
            Msg::Info("Starting subloop %d in Line Loop %d (are you sure about this?)",
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
      Msg::Error("Line Loop %d is wrong", num);
      break;
    }
  }
  List_Delete(temp);
}

void setSurfaceEmbeddedPoints(Surface *s, List_T *points)
{
  if(!s->EmbeddedPoints)
    s->EmbeddedPoints = List_Create(4, 4, sizeof(Vertex *));
  int nbPoints = List_Nbr(points);
  for(int i = 0; i < nbPoints; i++) {
    double iPoint;
    List_Read(points, i, &iPoint);
    Vertex *v = FindPoint((int)iPoint);
    if(v)
      List_Add(s->EmbeddedPoints, &v);
    else
      Msg::Error("Unknown point %d", iPoint);
  }
}

void setSurfaceEmbeddedCurves(Surface *s, List_T *curves)
{
  double eps = CTX::instance()->geom.tolerance * CTX::instance()->lc;
  if (!s->EmbeddedCurves)
    s->EmbeddedCurves = List_Create(4, 4, sizeof(Curve *));

  for(int i = 0; i < List_Nbr(curves); i++) {
    double iCurve;
    List_Read(curves, i, &iCurve);
    Curve *cToAddInSurf = FindCurve((int)iCurve);

    if(!cToAddInSurf){
      Msg::Error("Unknown curve %d", (int)iCurve);
      continue;
    }

    if (cToAddInSurf->Typ != MSH_SEGM_LINE){
      // compute intersections only avalaible for straight lines
      List_Add(s->EmbeddedCurves, &cToAddInSurf);
      continue;
    }

    if(!cToAddInSurf->Control_Points)
      continue;

    for(int j = 0; j < List_Nbr(s->EmbeddedCurves) + List_Nbr(s->Generatrices); j++) {
      Curve *cDejaInSurf;
      if (j < s->EmbeddedCurves->n)
        List_Read(s->EmbeddedCurves, j, &cDejaInSurf);
      else
        List_Read(s->Generatrices, j-s->EmbeddedCurves->n, &cDejaInSurf);
      if (cDejaInSurf->Typ != MSH_SEGM_LINE)
        // compute intersections only avalaible for straight lines
        continue;

      if(!cDejaInSurf->Control_Points)
        continue;

      // compute intersection between pair of control points of cDejaInSurf and
      // pair of control points of cToAddInSurf
      Vertex *v1;
      Vertex *v2;
      for(int k = 0; k < cDejaInSurf->Control_Points->n-1; k++) {
        List_Read(cDejaInSurf->Control_Points, k, &v1);
        List_Read(cDejaInSurf->Control_Points, k+1, &v2);

        SPoint3 p1 = SPoint3(v1->Pos.X, v1->Pos.Y, v1->Pos.Z);
        SPoint3 p2 = SPoint3(v2->Pos.X, v2->Pos.Y, v2->Pos.Z);

        // to take into account geometrical tolerance
        SVector3 sv = SVector3( p1, p2);
        sv = sv.unit()*eps;
        SPoint3 p3 = p1 - sv.point();
        SPoint3 p4 = p2 + sv.point();

        Vertex *w1;
        Vertex *w2;
        for(int l = 0; l < List_Nbr(cToAddInSurf->Control_Points) - 1; l++) {
          List_Read(cToAddInSurf->Control_Points, l, &w1);
          List_Read(cToAddInSurf->Control_Points, l+1, &w2);

	  if (w1 == v1 || w1 == v2 || w2 == v1 || w2 == v2)continue;

          SPoint3 q1 = SPoint3(w1->Pos.X, w1->Pos.Y, w1->Pos.Z);
          SPoint3 q2 = SPoint3(w2->Pos.X, w2->Pos.Y, w2->Pos.Z);

          // to take into account geometrical tolerance
          SVector3 sw = SVector3( q1, q2);
          sw = sw.unit()*eps;
          SPoint3 q3 = q1 - sw.point();
          SPoint3 q4 = q2 + sw.point();

          double x[2];
          int inters = intersection_segments(p3, p4, q3, q4, x);
          if (inters && x[0] != 0. && x[1] != 0. && x[0] != 1. && x[1] != 1.){
            SPoint3 p = SPoint3( (1.-x[0])*p3.x() + x[0]*p4.x(),
                                 (1.-x[0])*p3.y() + x[0]*p4.y(),
                                 (1.-x[0])*p3.z() + x[0]*p4.z());
            // case to treat
            bool createPoint = false, mergePoint = false;
            bool splitcToAddInSurf = false, splitcDejaInSurf = false;
            Vertex *v, *w;
            {
              double pp1 = p.distance(p1);
              double pp2 = p.distance(p2);
              double pp;
              if (pp1 <= pp2){
                pp = pp1;
                v = v1;
              }
              else{
                pp = pp2;
                v = v2;
              }
              double pq1 = p.distance(q1);
              double pq2 = p.distance(q2);
              double pq;
              if (pq1 <= pq2){
                pq = pq1;
                w = w1;
              }
              else{
                pq = pq2;
                w = w2;
              }
              if (pq < eps && pp < eps)
                mergePoint = true;
              else if (pq >= eps && pp < eps)
                splitcToAddInSurf = true;
              else if (pq < eps && pp >= eps)
                splitcDejaInSurf = true;
              else{
                createPoint = true;
                splitcToAddInSurf = true;
                splitcDejaInSurf = true;
              }
            }
            if (mergePoint){
              if (v != w){
                Msg::Debug("merge points %d, %d between embedded edges", v->Num, w->Num);
                Tree_Suppress(GModel::current()->getGEOInternals()->Points, &w);
                List_T *Curves = Tree2List(GModel::current()->getGEOInternals()->Curves);
                for(int i = 0; i < List_Nbr(Curves); i++){
                  Curve *c;
                  List_Read(Curves, i, &c);
                  if (c->beg == w)
                    c->beg = v;
                  if (c->end == w)
                    c->end = v;
                  for(int j = 0; j < List_Nbr(c->Control_Points); j++) {
                    if(!compareVertex(List_Pointer(c->Control_Points, j), &w)){
                      List_Write(c->Control_Points, j, &v);
                    }
                  }
                }
                DeletePoint(w->Num);
                List_Delete(Curves);
              }
            }
            if (splitcToAddInSurf || splitcDejaInSurf){
              Msg::Debug("Intersect point between embedded edges at pos : (%g,%g)",
                         p.x(), p.y());
              Vertex *v3;
              if (createPoint){
                v3 = Create_Vertex(NEWPOINT(), p.x(), p.y(), p.z(), MAX_LC, 1.0);
                Tree_Insert(GModel::current()->getGEOInternals()->Points, &v3);
              }
              else if (splitcDejaInSurf)
                v3 = w;
              else
                v3 = v;
              List_T *temp = List_Create(1, 1, sizeof(int));
              List_Add(temp, v3->Num);
              if (splitcDejaInSurf){
                List_Put (cDejaInSurf->Control_Points, k+1, &v3);
                List_T *shapes = List_Create(2, 1, sizeof(Shape*));
                SplitCurve(cDejaInSurf->Num, temp, shapes);
                // getting back cDejaInSurf because it was deleted by SplitCurve
                if (j < s->EmbeddedCurves->n)
                  List_Read(s->EmbeddedCurves, j, &cDejaInSurf);
                else
                  List_Read(s->Generatrices, j-s->EmbeddedCurves->n, &cDejaInSurf);
                List_Delete(shapes);
              }
              if (splitcToAddInSurf){
                List_Put (cToAddInSurf->Control_Points, l+1, &v3);
                List_T *shapes = List_Create(2, 1, sizeof(Shape*));
                SplitCurve(cToAddInSurf->Num, temp, shapes);
                // replacing c with the first shape
                List_Read (shapes, 0, &cToAddInSurf);
                double d = (double)cToAddInSurf->Num;
                List_Write(curves, i, &d);
                // inserting the second shape in curves
                Curve *c2;
                List_Read (shapes, 1, &c2);
                double d2 = (double)c2->Num;
                List_Put (curves, i+1, &d2);
                List_Delete(shapes);
              }
              List_Delete(temp);
            }
          }
        }
      }
    }
    List_Add(s->EmbeddedCurves, &cToAddInSurf);
  }
}

void setVolumeEmbeddedSurfaces(Volume *v, List_T *surfaces)
{
  if (!v->EmbeddedSurfaces)
    v->EmbeddedSurfaces = List_Create(4, 4, sizeof(Surface *));
  int nb = List_Nbr(surfaces);
  for(int i = 0; i < nb; i++) {
    double iSurface;
    List_Read(surfaces, i, &iSurface);
    Surface *s = FindSurface((int)iSurface);
    if(s)
      List_Add(v->EmbeddedSurfaces, &s);
    else
      Msg::Error("Unknown surface %d", (int)iSurface);
  }
}

void setVolumeEmbeddedCurves(Volume *v, List_T *curves)
{
 if (!v->EmbeddedCurves)
    v->EmbeddedCurves = List_Create(4, 4, sizeof(Curve *));
  int nb = List_Nbr(curves);
  for(int i = 0; i < nb; i++) {
    double iCurve;
    List_Read(curves, i, &iCurve);
    Curve *c = FindCurve((int)iCurve);
    if(c)
      List_Add(v->EmbeddedCurves, &c);
    else
      Msg::Error("Unknown curve %d", (int)iCurve);
  }
}

void setVolumeEmbeddedPoints(Volume *v, List_T *points)
{
 if (!v->EmbeddedPoints)
    v->EmbeddedPoints = List_Create(4, 4, sizeof(Vertex *));
  int nb = List_Nbr(points);
  for(int i = 0; i < nb; i++) {
    double iPoint;
    List_Read(points, i, &iPoint);
    Vertex *c = FindPoint((int)iPoint);
    if(c)
      List_Add(v->EmbeddedPoints, &c);
    else
      Msg::Error("Unknown point %d", (int)iPoint);
  }
}


void setSurfaceGeneratrices(Surface *s, List_T *loops)
{
  int nbLoop = List_Nbr(loops);
  List_Delete(s->Generatrices);
  s->Generatrices = List_Create(4, 4, sizeof(Curve *));
  List_Delete(s->GeneratricesByTag);
  s->GeneratricesByTag = List_Create(4, 4, sizeof(int));

  if(s->Typ == MSH_SURF_COMPOUND){
    s->Generatrices = GetOrderedUniqueEdges(s);
    if(!List_Nbr(s->Generatrices)){
      // don't complain: compounds can be not in old GEO database
      //Msg::Warning("Could not make generatrices list for compound surface %d", s->Num);
      return;
    }
  }

  for(int i = 0; i < nbLoop; i++) {
    int iLoop;
    List_Read(loops, i, &iLoop);
    EdgeLoop *el;
    std::vector<int> fromModel;
    if(!(el = FindEdgeLoop(abs(iLoop)))) {
      Msg::Error("Unknown line loop %d", iLoop);
      List_Delete(s->Generatrices);
      s->Generatrices = NULL;
      return;
    }
    else {
      int ic;
      Curve *c;
      if((i == 0 && iLoop > 0) || // exterior boundary
         (i != 0 && iLoop < 0)){  // hole
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
      else{
        for(int j = List_Nbr(el->Curves)-1; j >= 0; j--) {
          List_Read(el->Curves, j, &ic);
          ic *= gmsh_sign(iLoop);
          if(i != 0) ic *= -1; // hole
          if(!(c = FindCurve(ic)))
            fromModel.push_back(ic);
          else
            List_Add(s->Generatrices, &c);
        }
      }
      for(unsigned int j = 0; j < fromModel.size(); j++) {
        ic = fromModel[j];
        GEdge *ge = GModel::current()->getEdgeByTag(abs(ic));
        if(ge) {
          List_Add(s->GeneratricesByTag, &ic);
        }
        else{
          Msg::Error("Unknown curve %d", ic);
          return;
        }
      }
    }
  }
}

void setVolumeSurfaces(Volume *v, List_T *loops)
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
      return;
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
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(is));
          if(gf) {
            List_Add(v->SurfacesByTag, &is);
          }
          else{
            Msg::Error("Unknown surface %d", is);
            return;
          }
        }
      }
    }
  }
}

int select_contour(int type, int num, List_T * List)
{
  int k = 0;

  switch (type) {
  case ENT_LINE:
    k = allEdgesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      int ip;
      List_Read(List, i, &ip);
      GEdge *ge = GModel::current()->getEdgeByTag(abs(ip));
      if(ge) ge->setSelection(1);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      int ip;
      List_Read(List, i, &ip);
      GFace *gf = GModel::current()->getFaceByTag(abs(ip));
      if(gf) gf->setSelection(1);
    }
    break;
  }

  return k;
}
