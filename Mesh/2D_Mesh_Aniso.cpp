// $Id: 2D_Mesh_Aniso.cpp,v 1.57 2006-11-25 00:44:25 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

// Anisotropic Delaunay mesh generator

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Interpolation.h"
#include "Create.h"
#include "Context.h"

extern Context_T CTX;
extern double LC2D;

inline void cgsmpl(Simplex * s, double &x, double &y)
{
  x = (1. / 3.) * (s->V[0]->Pos.X + s->V[1]->Pos.X + s->V[2]->Pos.X);
  y = (1. / 3.) * (s->V[0]->Pos.Y + s->V[1]->Pos.Y + s->V[2]->Pos.Y);
}

extern Simplex MyNewBoundary;
extern Mesh *THEM;
extern double MAXIMUM_LC_FOR_SURFACE;
extern int Alerte_Point_Scabreux;
extern PointRecord *gPointArray;
extern Surface *PARAMETRIC;

static Tree_T *Tsd, *Sim_Sur_Le_Bord;
static List_T *Simplexes_Destroyed, *Simplexes_New, *Suppress;
static Simplex *THES;
static Vertex *THEV;
static Surface *SURF;
static Tree_T *FacesTree;
static int ZONEELIMINEE, Methode = 0;
static double volume;
static List_T *coquille;
static Edge *THEEDGE;

double Interpole_lcTriangle(Simplex * s, Vertex * vv)
{
  double Xp, Yp, X[3], Y[3], det, u, v, q1, q2, q3;

  if(CTX.mesh.bgmesh_type == ONFILE){
    Vertex *v2 = Create_Vertex(-1, vv->Pos.X, vv->Pos.Y, 0.0, 0.0, 0.0);
    Vertex *dum;
    Calcule_Z_Plan(&v2, &dum);
    Projette_Inverse(&v2, &dum);
    double val = BGMXYZ(v2->Pos.X, v2->Pos.Y, v2->Pos.Z);
    Free_Vertex(&v2, 0);
    return val;
  }

  Xp = vv->Pos.X;
  Yp = vv->Pos.Y;

  X[0] = s->V[0]->Pos.X;
  X[1] = s->V[1]->Pos.X;
  X[2] = s->V[2]->Pos.X;

  Y[0] = s->V[0]->Pos.Y;
  Y[1] = s->V[1]->Pos.Y;
  Y[2] = s->V[2]->Pos.Y;

  q1 = s->V[0]->lc;
  q2 = s->V[1]->lc;
  q3 = s->V[2]->lc;

  det = (X[2] - X[0]) * (Y[1] - Y[0]) - (Y[2] - Y[0]) * (X[1] - X[0]);

  if(det != 0.0) {
    u = ((Xp - X[0]) * (Y[1] - Y[0]) - (Yp - Y[0]) * (X[1] - X[0])) / det;
    v = ((X[2] - X[0]) * (Yp - Y[0]) - (Y[2] - Y[0]) * (Xp - X[0])) / det;
  }
  else {
    u = v = 0.0;
  }
  return (q1 * (1. - u - v) + q2 * v + q3 * u);
}


/* Au sens Riemannien, trouver le centre de l'ellipse
   triangle de sommets (x1,x2,x3)

   T                   T
   (x-x1)  M (x-x1) = (x-x2)  M (x-x2)
   T                   T
   (x-x1)  M (x-x1) = (x-x3)  M (x-x3)
 */

void matXmat(int n, double mat1[3][3], double mat2[3][3], double Res[3][3])
{
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      Res[i][j] = 0.0;
      for(int k = 0; k < n; k++)
        Res[i][j] += mat1[i][k] * mat2[k][j];
    }
  }
}

void TmatXmat(int n, double mat1[3][3], double mat2[3][3], double Res[3][3])
{
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      Res[i][j] = 0.0;
      for(int k = 0; k < n; k++)
        Res[i][j] += mat1[k][i] * mat2[k][j];
    }
  }
}

Simplex *Create_Simplex_For2dmesh(Vertex * v1, Vertex * v2, Vertex * v3,
                                  Vertex * v4)
{
  Simplex *s;
  double p12, p23, p13;
  double srf = ((v2->Pos.X - v1->Pos.X) *
                (v3->Pos.Y - v2->Pos.Y) -
                (v3->Pos.X - v2->Pos.X) * (v2->Pos.Y - v1->Pos.Y));
  if(srf > 0)
    s = Create_Simplex(v3, v2, v1, v4);
  else
    s = Create_Simplex(v1, v2, v3, v4);

  THEM->Metric->setSimplexQuality(s, PARAMETRIC);

  if(PARAMETRIC) {
    if((!v2->ListCurves && !v3->ListCurves && !v3->ListCurves)) {
      prosca(v1->us, v2->us, &p12);
      p12 = fabs(p12);
      prosca(v1->us, v3->us, &p13);
      p13 = fabs(p13);
      prosca(v2->us, v3->us, &p23);
      p23 = fabs(p23);
      if(s->Quality < CONV_VALUE &&
         (p12 < THEM->Metric->min_cos || p13 < THEM->Metric->min_cos ||
          p23 < THEM->Metric->min_cos))
        s->Quality = 1.0;
    }
  }
  return s;
}

/*En l'honneur de ma femme Stephanie... */

void VSIM_2D(void *a, void *b)
{
  Simplex *S;

  S = *(Simplex **) a;
  if(S->V[2])
    volume += fabs(S->Volume_Simplexe2D());
}

void Box_2_Triangles(List_T * P, Surface * s)
{
#define FACT 1.1
#define LOIN 0.2

  int i, j;
  static int pts[4][2] = { {0, 0},
			   {1, 0},
			   {1, 1},
			   {0, 1} };
  static int tri[2][3] = { {1, 4, 2},
			   {2, 4, 3} };
  double Xm = 0., Ym = 0., XM = 0., YM = 0., Xc = 0., Yc = 0.;
  Simplex *S, *ps;
  Vertex *V, *v, *pv;
  List_T *smp;

  smp = List_Create(2, 1, sizeof(Simplex *));

  V = (Vertex *) Malloc(4 * sizeof(Vertex));

  for(i = 0; i < List_Nbr(P); i++) {
    List_Read(P, i, &v);
    if(!i) {
      Xm = XM = v->Pos.X;
      Ym = YM = v->Pos.Y;
    }
    else {
      Xm = DMIN(Xm, v->Pos.X);
      XM = DMAX(XM, v->Pos.X);
      Ym = DMIN(Ym, v->Pos.Y);
      YM = DMAX(YM, v->Pos.Y);
    }
  }
  if(Xm == XM)
    XM = Xm + 1.;
  if(Ym == YM)
    YM = Ym + 1.;

  Xc = XM - Xm;
  Yc = YM - Ym;

  /* Longueur Caracteristique */

  LC2D = sqrt(Xc * Xc + Yc * Yc);

  for(i = 0; i < 4; i++) {
    if(pts[i][0])
      V[i].Freeze.X = V[i].Pos.X = Xm - LOIN * Xc;
    else
      V[i].Freeze.X = V[i].Pos.X = XM + LOIN * Xc;
    if(pts[i][1])
      V[i].Freeze.Y = V[i].Pos.Y = Ym - LOIN * Yc;
    else
      V[i].Freeze.Y = V[i].Pos.Y = YM + LOIN * Yc;

    V[i].Freeze.Z = V[i].Pos.Z = 0.0;

    V[i].Num = -(++THEM->MaxPointNum);
    V[i].ListSurf = NULL;
    pv = &V[i];
    pv->lc = 1.0;
    pv->Mov = NULL;
    Tree_Replace(s->Vertices, &pv);
  }

  /* 2 Triangles forment le maillage de la boite */

  for(i = 0; i < 2; i++) {
    S = Create_Simplex_For2dmesh(&V[tri[i][0] - 1], &V[tri[i][1] - 1],
                                 &V[tri[i][2] - 1], NULL);
    List_Add(smp, &S);
    S->iEnt = s->Num;
  }

  Link_Simplexes(smp, NULL);
  for(i = 0; i < List_Nbr(smp); i++) {
    List_Read(smp, i, &ps);
    for(j = 0; j < 3; j++)
      if(ps->S[j] == NULL)
        ps->S[j] = &MyNewBoundary;
    Tree_Replace(s->Simplexes, &ps);
  }

  List_Delete(smp);

}


int Intersect_Edges_2d(Edge * a, Edge * b)
{
  double mat[2][2];
  double rhs[2], x[2];
  mat[0][0] = (a->V[1]->Pos.X - a->V[0]->Pos.X);
  mat[0][1] = -(b->V[1]->Pos.X - b->V[0]->Pos.X);
  mat[1][0] = (a->V[1]->Pos.Y - a->V[0]->Pos.Y);
  mat[1][1] = -(b->V[1]->Pos.Y - b->V[0]->Pos.Y);
  rhs[0] = b->V[0]->Pos.X - a->V[0]->Pos.X;
  rhs[1] = b->V[0]->Pos.Y - a->V[0]->Pos.Y;
  if(!sys2x2(mat, rhs, x))
    return 0;
  if(x[0] > 0.0 && x[0] < 1.0 && x[1] > 0.0 && x[1] < 1.0)
    return 1;
  return 0;
}

void putaindecoquille_2D(void *a, void *b)
{
  Edge *e = (Edge *) a;
  if(!compareVertex(&e->V[0], &THEEDGE->V[0]) ||
     !compareVertex(&e->V[0], &THEEDGE->V[1]) ||
     !compareVertex(&e->V[1], &THEEDGE->V[0]) ||
     !compareVertex(&e->V[1], &THEEDGE->V[1])) {
    return;
  }
  if(Intersect_Edges_2d(e, THEEDGE))
    List_Add(coquille, &e);
}

void Recover_Edge(Surface * s, Edge * e, EdgesContainer & Edges)
{
  THEEDGE = e;
  int i;
  Edge *me, E;
  Vertex *v[2];

  coquille = List_Create(3, 3, sizeof(Edge *));
  /*On cherche la coquille */
  Tree_Action(Edges.AllEdges, putaindecoquille_2D);
  Msg(INFO, "Edge %d->%d, %d intersections",
      e->V[0]->Num, e->V[1]->Num, List_Nbr(coquille));

  if(List_Nbr(coquille) == 1) {
    Msg(WARNING, "Unable to swap edge");
    List_Delete(coquille);
    return;
  }

  /*on swappe au hasard jusqu'a ce qu l'arete soit recuperee */
  while(List_Nbr(coquille)) {

    i = (int)(List_Nbr(coquille) * rand() / (RAND_MAX + 1.0));
    //i = rand () % List_Nbr (coquille);
    List_Read(coquille, i, &me);
    v[0] = me->V[0];
    v[1] = me->V[1];
    List_Suppress(coquille, &me, compareEdgePtr);
    Edges.SwapEdge(v);
    if(Edges.Search(e->V[0], e->V[1]))
      break;
    E.V[0] = v[0];
    E.V[1] = v[1];
    me = (Edge *) Tree_PQuery(Edges.AllEdges, &E);
    putaindecoquille_2D(me, NULL);
  }

  List_Delete(coquille);

  Msg(INFO, "Edge recovered");
  /*On swappe */
}

void constraint_the_edge(int isurf, int iv1, int iv2)
{
  Vertex *v1 = FindVertex(iv1);
  Vertex *v2 = FindVertex(iv2);
  Surface *s = FindSurface(isurf);
  Edge e;

  if(!v1 || !v2)
    return;
  EdgesContainer EdgesOnSurface(s->Simplexes);
  e.V[0] = v1;
  e.V[1] = v2;
  if(!EdgesOnSurface.Search(v1, v2)) {
    Recover_Edge(s, &e, EdgesOnSurface);
  }
}

void missing_edges_2d(Surface * s)
{
  int i, j;
  Curve *c;
  Vertex *v1, *v2;
  Edge e;

  EdgesContainer EdgesOnSurface(s->Simplexes);

  for(i = 0; i < List_Nbr(s->Generatrices); i++) {
    List_Read(s->Generatrices, i, &c);
    for(j = 1; j < List_Nbr(c->Vertices); j++) {
      List_Read(c->Vertices, j - 1, &v1);
      List_Read(c->Vertices, j, &v2);
      e.V[0] = v1;
      e.V[1] = v2;
      if(!EdgesOnSurface.Search(v1, v2)) {
        Msg(INFO, "Missing edge %d->%d", v1->Num, v2->Num);
        Recover_Edge(s, &e, EdgesOnSurface);
      }
    }
  }
}

int Restore_Boundary(Surface * s)
{
  missing_edges_2d(s);
  return 1;
}

int Maillage_Edge(Vertex * v1, Vertex * v2, List_T * Points)
{
  int i;
  static int qq = 1;
  Simplex S, *s;

  s = &S;
  s->F[0].V[0] = v1;
  s->F[0].V[1] = v2;

  if(Tree_Search(FacesTree, &s))
    return 0;

  s = Create_Simplex_For2dmesh(v1, v2, NULL, NULL);
  Tree_Add(FacesTree, &s);

  Curve *c = Create_Curve(qq++, MSH_SEGM_LINE, 1, NULL, NULL, -1, -1, 0, 1);
  Vertex *v;
  c->Control_Points = List_Create(2, 1, sizeof(Vertex *));
  List_Add(c->Control_Points, &v1);
  List_Add(c->Control_Points, &v2);
  c->beg = v1;
  c->end = v2;
  Maillage_Curve(&c, NULL);
  for(i = 1; i < List_Nbr(c->Vertices) - 1; i++) {
    List_Read(c->Vertices, i, &v);
    List_Delete(v->ListCurves);
    v->ListCurves = NULL;
    List_Add(Points, &v);
  }
  List_Delete(c->Vertices);
  List_Delete(c->Control_Points);
  Free_Curve(&c, 0);
  return 1;
}

void Action_First_Simplexes_2D(void *a, void *b)
{
  Simplex *q;

  if(!THES) {
    q = *(Simplex **) a;
    if(q->Pt_In_Ellipse(THEV, THEM->Metric->m)) {
      THES = q;
    }
  }
}

void Fill_Sim_Des_2D(void *a, void *b)
{
  Simplex *S;
  S = *(Simplex **) a;
  if(S->Pt_In_Ellipse(THEV, THEM->Metric->m))
    List_Add(Simplexes_Destroyed, a);
}

void TStoLS_2D(void *a, void *b)
{
  List_Add(Simplexes_Destroyed, a);
}

void TAtoLA_2D(void *a, void *b)
{
  List_Add(Simplexes_New, a);
}

void CrSi_2D(void *a, void *b)
{
  SxF *S;
  Simplex *s;
  S = (SxF *) a;
  if(S->NumFaceSimpl == 1) {
    s = Create_Simplex_For2dmesh(THEV, S->F.V[0], S->F.V[1], NULL);
    s->iEnt = ZONEELIMINEE;
    List_Add(Simplexes_New, &s);
  }
  else if(S->NumFaceSimpl != 2) {
    Msg(GERROR, "Panic in CrSi_2D...");
  }
}

void NewSimplexes_2D(Surface * s, List_T * Sim, List_T * news)
{
  int i, j;
  Tree_T *SimXFac;
  Simplex *S;
  SxF SXF, *pSXF;

  SimXFac = Tree_Create(sizeof(SxF), compareSxF);

  for(i = 0; i < List_Nbr(Sim); i++) {
    List_Read(Sim, i, &S);
    if(!i)
      ZONEELIMINEE = S->iEnt;
    else {
      if(S->iEnt != ZONEELIMINEE) {
        Msg(WARNING, "Huh! The elimination failed %d %d",
            S->iEnt, ZONEELIMINEE);
      }
    }
    for(j = 0; j < 3; j++) {
      SXF.F = S->F[j];

      if((pSXF = (SxF *) Tree_PQuery(SimXFac, &SXF))) {
        (pSXF->NumFaceSimpl)++;
      }
      else {
        SXF.NumFaceSimpl = 1;
        Tree_Add(SimXFac, &SXF);
      }
    }
  }

  /* Les faces non communes sont obligatoirement a la frontiere ...
     -> Nouveaux simplexes */

  Tree_Action(SimXFac, CrSi_2D);
  Tree_Delete(SimXFac);
}

int recur_bowyer_2D(Simplex * s)
{
  int i;

  Tree_Insert(Tsd, &s);
  for(i = 0; i < 3; i++) {
    if(s->S[i] && s->S[i] != &MyNewBoundary && !Tree_Query(Tsd, &s->S[i])) {
      if(s->S[i]->Pt_In_Ellipse(THEV, THEM->Metric->m)
         && (s->iEnt == s->S[i]->iEnt)) {
        recur_bowyer_2D(s->S[i]);
      }
      else {
        if(s->iEnt != s->S[i]->iEnt) {
          Alerte_Point_Scabreux = 1;
        }
        Tree_Insert(Sim_Sur_Le_Bord, &s->S[i]);
      }
    }
  }
  return 1;
}


bool draw_simplex2d(Surface * sur, Simplex * s, bool nouv)
{
  if(!CTX.mesh.interactive)
    return false;

  if(s == &MyNewBoundary || !s || !s->iEnt)
    return false;

#if defined(HAVE_FLTK)
  Vertex v1 = InterpolateSurface(sur->Support, s->V[0]->Pos.X, s->V[0]->Pos.Y, 0, 0);
  Vertex v2 = InterpolateSurface(sur->Support, s->V[1]->Pos.X, s->V[1]->Pos.Y, 0, 0);
  Vertex v3 = InterpolateSurface(sur->Support, s->V[2]->Pos.X, s->V[2]->Pos.Y, 0, 0);

  Vertex *pv1 = &v1, *pv2 = &v2, *pv3 = &v3, *dum;
  Calcule_Z_Plan(&pv1, &dum);
  Projette_Inverse(&pv1, &dum);
  Calcule_Z_Plan(&pv2, &dum);
  Projette_Inverse(&pv2, &dum);
  Calcule_Z_Plan(&pv3, &dum);
  Projette_Inverse(&pv3, &dum);

  void Draw_Triangle_Overlay(double, double, double, double*, double*, double*);
  double p1[3] = {pv1->Pos.X, pv1->Pos.Y, pv1->Pos.Z};
  double p2[3] = {pv2->Pos.X, pv2->Pos.Y, pv2->Pos.Z};
  double p3[3] = {pv3->Pos.X, pv3->Pos.Y, pv3->Pos.Z};
  if(nouv)
    Draw_Triangle_Overlay(1., 0., 0., p1, p2, p3);
  else
    Draw_Triangle_Overlay(0., 0., 0., p1, p2, p3);
#endif

  return true;
}

bool Bowyer_Watson_2D(Surface * sur, Vertex * v, Simplex * S, int force)
{
  int i;
  Simplex *s;
  static int init = 1;
  double volumeold, volumenew;

  THEV = v;

  double x = (S->V[0]->Pos.X + S->V[1]->Pos.X + S->V[2]->Pos.X) / 3.;
  double y = (S->V[0]->Pos.Y + S->V[1]->Pos.Y + S->V[2]->Pos.Y) / 3.;

  if(force)
    THEM->Metric->setMetricMin(x, y, sur->Support);
  else
    THEM->Metric->setMetric(x, y, sur->Support);

  Tsd = Tree_Create(sizeof(Simplex *), compareSimplex);
  Sim_Sur_Le_Bord = Tree_Create(sizeof(Simplex *), compareSimplex);
  if(init) {
    Simplexes_New = List_Create(10, 10, sizeof(Simplex *));
    Simplexes_Destroyed = List_Create(10, 10, sizeof(Simplex *));
    init = 0;
  }

  if(Methode) {
    Tree_Action(sur->Simplexes, Fill_Sim_Des_2D);
    S = NULL;
  }
  else {
    recur_bowyer_2D(S);
  }

  Tree_Action(Tsd, TStoLS_2D);
  NewSimplexes_2D(sur, Simplexes_Destroyed, Simplexes_New);

  /* calcul des volumes des simplexes crees */

  if(Alerte_Point_Scabreux || !CTX.mesh.speed_max) {
    volume = 0.0;
    for(i = 0; i < List_Nbr(Simplexes_Destroyed); i++) {
      VSIM_2D(List_Pointer(Simplexes_Destroyed, i), NULL);
    }
    volumeold = volume;
    volume = 0.0;
    for(i = 0; i < List_Nbr(Simplexes_New); i++) {
      VSIM_2D(List_Pointer(Simplexes_New, i), NULL);
    }
    volumenew = volume;
    if(volumeold + volumenew == 0.0)
      volumenew = 1.0;
  }
  else {
    volumeold = 1.0;
    volumenew = 1.0;
  }

  /* critere du volume */

  if((fabs(volumeold - volumenew) / (volumeold + volumenew)) > 1.e-8) {
    if(S) {
      Tree_Suppress(sur->Simplexes, &S);
      S->Quality /= 2.;
      Tree_Add(sur->Simplexes, &S);
    }
    if(force) {
      List_Reset(Simplexes_New);
      List_Reset(Simplexes_Destroyed);
      Tree_Delete(Sim_Sur_Le_Bord);
      Tree_Delete(Tsd);
      return false;
    }
  }
  else {
    Tree_Add(sur->Vertices, &THEV);

    /* Suppression des simplexes elimines */
    for(i = 0; i < List_Nbr(Simplexes_Destroyed); i++) {
      List_Read(Simplexes_Destroyed, i, &s);
      draw_simplex2d(sur, s, 0);
      if(!Tree_Suppress(sur->Simplexes, &s)) {
        Msg(WARNING, "Failed to suppress simplex %d", s->Num);
      }
      Free_Simplex(&s, 0);
    }
    for(i = 0; i < List_Nbr(Simplexes_New); i++) {
      List_Read(Simplexes_New, i, &s);
      if(0 || !force) {
        double xc = s->Center.X;
        double yc = s->Center.Y;
        double rd = s->Radius;
        cgsmpl(s, x, y);
        THEM->Metric->setMetric(x, y, sur->Support);
        THEM->Metric->setSimplexQuality(s, sur->Support);
        s->Center.X = xc;
        s->Center.Y = yc;
        s->Radius = rd;
        if(force)
          THEM->Metric->Identity();
      }
      draw_simplex2d(sur, s, 1);
      Tree_Add(sur->Simplexes, &s);
    }

    /* Creation des liens entre nouveaux simplexes */

    Tree_Action(Sim_Sur_Le_Bord, TAtoLA_2D);
    Link_Simplexes(Simplexes_New, sur->Simplexes);
  }

  List_Reset(Simplexes_New);
  List_Reset(Simplexes_Destroyed);
  Tree_Delete(Sim_Sur_Le_Bord);
  Tree_Delete(Tsd);
  return true;
}

void Convex_Hull_Mesh_2D(List_T * Points, Surface * s)
{
  int i, N;

  N = List_Nbr(Points);

  Box_2_Triangles(Points, s);
  for(i = 0; i < N; i++) {
    THES = NULL;
    List_Read(Points, i, &THEV);
    Tree_Action(s->Simplexes, Action_First_Simplexes_2D);
    /*
       if(i%n == n-1){
       volume = 0.0;
       Tree_Action(s->Simplexes,VSIM_2D);
       Msg(STATUS2, %d->%d Nodes, %d Elements",i+1,N,Tree_Nbr(s->Simplexes));
       } 
     */
    if(!THES) {
      Msg(GERROR, "Vertex (%g,%g,%g) in no simplex", THEV->Pos.X, THEV->Pos.Y,
          THEV->Pos.Z);
      THEV->Pos.X +=
        CTX.mesh.rand_factor * LC2D * (1. -
                                       (double)rand() / (double)RAND_MAX);
      THEV->Pos.Y +=
        CTX.mesh.rand_factor * LC2D * (1. -
                                       (double)rand() / (double)RAND_MAX);
      THEV->Pos.Z +=
        CTX.mesh.rand_factor * LC2D * (1. -
                                       (double)rand() / (double)RAND_MAX);
      Tree_Action(s->Simplexes, Action_First_Simplexes_2D);
    }
    bool ca_marche = Bowyer_Watson_2D(s, THEV, THES, 1);
    while(!ca_marche) {
      double dx =
        CTX.mesh.rand_factor * LC2D * (1. -
                                       (double)rand() / (double)RAND_MAX);
      double dy =
        CTX.mesh.rand_factor * LC2D * (1. -
                                       (double)rand() / (double)RAND_MAX);
      THEV->Pos.X += dx;
      THEV->Pos.Y += dy;
      ca_marche = Bowyer_Watson_2D(s, THEV, THES, 1);
      THEV->Pos.X -= dx;
      THEV->Pos.Y -= dy;
    }
  }

}

/* recuperation de la surface */

static List_T *ListCurves, *ListAllCurves;
static Tree_T *keep;
static Simplex *SIMP;
static int iSurface;

void attribueSurface(void *a, void *b)
{
  Simplex *s;
  s = *(Simplex **) a;
  s->iEnt = iSurface;
}

void Trouve_Simplex_2D(void *a, void *b)
{
  Simplex *s;
  if(SIMP != NULL)
    return;
  s = *(Simplex **) a;
  if(s->iEnt < 0)
    SIMP = s;
}

void Trouve_Simplex_Bord_2D(void *a, void *b)
{
  Simplex *s;

  if(SIMP != NULL)
    return;
  s = *(Simplex **) a;
  if(s->V[0]->Num < 0 || s->V[1]->Num < 0 || s->V[2]->Num < 0)
    SIMP = s;
}

void CourbesDansSurface(Surface * s, List_T * ListAllCurves)
{
  int i, iseg;
  Curve *c;
  for(i = 0; i < List_Nbr(s->Generatrices); i++) {
    List_Read(s->Generatrices, i, &c);
    iseg = abs(c->Num);
    List_Replace(ListAllCurves, &iseg, fcmp_int);
  }
}

int isListaSurface(List_T * ListSurf, Surface * s)
{
  int NN, j, srf;
  bool found;
  Curve *c;
  NN = 0;
  found = true;
  for(j = 0; j < List_Nbr(s->Generatrices); j++) {
    List_Read(s->Generatrices, j, &c);
    srf = abs(c->Num);
    if(!List_Search(ListSurf, &srf, fcmp_int)) {
      found = false;
    }
    else
      NN++;
  }
  if(found && NN == List_Nbr(ListSurf))
    return s->Num;
  return 0;
}

static List_T *StackSimp;
#define MAX_DEPTH 500

void recur_trouve_surface(Simplex * s, int *Depth)
{
  int i, j;
  Simplex *pS, S;

  if(s->iEnt != -1)
    return;

  if((*Depth) > MAX_DEPTH) {
    List_Add(StackSimp, &s);
    return;
  }

  (*Depth)++;
  s->iEnt = -2;
  Tree_Add(keep, &s);
  for(i = 0; i < 3; i++) {
    pS = &S;
    pS->F[0] = s->F[i];
    if(Tree_Query(FacesTree, &pS)
       && List_Search(ListAllCurves, &pS->iEnt, fcmp_int)) {
      j = abs(pS->iEnt);
      List_Replace(ListCurves, &j, fcmp_int);
    }
    else if(s->S[i] && s->S[i] != &MyNewBoundary) {
      recur_trouve_surface(s->S[i], Depth);
    }
  }
  (*Depth)--;
}

extern int compareSimpSurf(const void *a, const void *b);

void Restore_Surface(Surface * s)
{
  int N;
  int i, depth;

  StackSimp = List_Create(100, 100, sizeof(Simplex *));
  ListCurves = List_Create(2, 2, sizeof(int));
  iSurface = -1;
  Tree_Action(s->Simplexes, attribueSurface);

  /* Les simplexes sur le bord exterieur sont elimines */
  ListAllCurves = List_Create(10, 3, sizeof(int));
  CourbesDansSurface(s, ListAllCurves);


  SIMP = NULL;
  Tree_Action(s->Simplexes, Trouve_Simplex_Bord_2D);

  if(SIMP) {
    List_Add(StackSimp, &SIMP);
    keep = Tree_Create(sizeof(Simplex *), compareQuality);
    depth = 0;
    i = 0;
    do {
      List_Read(StackSimp, i, &SIMP);
      recur_trouve_surface(SIMP, &depth);
    }
    while(++i < List_Nbr(StackSimp));
    List_Reset(StackSimp);

    N = Tree_Nbr(keep);

    iSurface = 0;
    Tree_Action(keep, attribueSurface);
    Tree_Delete(keep);
    List_Reset(ListCurves);
  }

  while(1) {
    SIMP = NULL;
    keep = Tree_Create(sizeof(Simplex *), compareQuality);
    Tree_Action(s->Simplexes, Trouve_Simplex_2D);
    if(!SIMP)
      break;
    List_Add(StackSimp, &SIMP);
    depth = 0;
    i = 0;
    do {
      List_Read(StackSimp, i, &SIMP);
      recur_trouve_surface(SIMP, &depth);
    } while(++i < List_Nbr(StackSimp));

    iSurface = isListaSurface(ListCurves, s);

    N = Tree_Nbr(keep);
    Msg(INFO,
        "Initial mesh of Surface %d: %d simplices, %d/%d curves, %d faces",
        iSurface, N, List_Nbr(ListCurves), List_Nbr(ListAllCurves),
        Tree_Nbr(FacesTree));

    Tree_Action(keep, attribueSurface);
    Tree_Delete(keep);
    List_Reset(ListCurves);
    List_Reset(StackSimp);
  }
  // MEMORY LEAK (JF)
  List_Delete(StackSimp);
  List_Delete(ListCurves);
  List_Delete(ListAllCurves);

}

void suppress_simplex_2D(void *data, void *dum)
{
  Simplex **pv;

  pv = (Simplex **) data;
  if((*pv)->iEnt == 0)
    List_Add(Suppress, pv);
}

Vertex *NewVertex_2D(Simplex * s)
{
  Vertex *v = NULL;
  double lc;
  lc = (s->V[0]->lc + s->V[1]->lc + s->V[2]->lc) / 3.;

  //lc = DMIN(MAXIMUM_LC_FOR_SURFACE,lc);

  /*v = Create_Vertex(  ++THEM->MaxPointNum,
     (s->V[0]->Pos.X + s->V[1]->Pos.X + s->V[2]->Pos.X)/3.,
     (s->V[0]->Pos.Y + s->V[1]->Pos.Y + s->V[2]->Pos.Y)/3.,
     0.0, lc, 0.0);
   */

  if(1){ // INSERTION_CENTROID
    v = Create_Vertex(++THEM->MaxPointNum, s->Center.X, s->Center.Y, 0.0, lc, 0.0);
  }
  else{ // INSERTION_EDGE
    Vertex *vv[2];
    double l = THEM->Metric->getWorstEdge(s, PARAMETRIC, vv);
    double f = 0.5;

    if(vv[0]->lc <= vv[1]->lc)
      f = vv[0]->lc / l;
    else
      f = 1. - (vv[1]->lc / l);

    if(f >= 1)
      v =
        Create_Vertex(++THEM->MaxPointNum, s->Center.X, s->Center.Y, 0.0, lc,
                      0.0);
    else
      v = Create_Vertex(++THEM->MaxPointNum,
                        f * vv[0]->Pos.X + (1. - f) * vv[1]->Pos.X,
                        f * vv[0]->Pos.Y + (1. - f) * vv[1]->Pos.Y, 0.0, lc,
                        0.0);
  }

  v->lc = Interpole_lcTriangle(s, v);

  if(PARAMETRIC) {
    if(!v->ListCurves)
      Normal2Surface(PARAMETRIC->Support, v->Pos.X, v->Pos.Y, v->us);
    else {
      v->us[0] = v->us[1] = v->us[2] = 0.0;
    }
  }
  return (v);
}

void TRIE_MON_GARS(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  s->Fourre_Simplexe(s->V[0], s->V[1], s->V[2], s->V[3]);
  s->iEnt = SURF->Num;
  s->S[0] = s->S[1] = s->S[2] = NULL;
  THEM->Metric->setSimplexQuality(s, PARAMETRIC);
  //SURF->Num;
  //qsort(s->F[0].V,3,sizeof(Vertex*),compareVertex);
}

void RandomSwapEdges2d(Surface * s)
{
  int i, j = 1, k;
  List_T *AllTrg = Tree2List(s->Simplexes);
  Simplex *t;
  for(i = 0; i < List_Nbr(AllTrg); i++) {
    k = rand() % List_Nbr(AllTrg);
    List_Read(AllTrg, k, &t);
    j = rand() % 3;
    if(draw_simplex2d(s, t, false))
      draw_simplex2d(s, t->S[j], false);
    t->SwapEdge(j);
    if(draw_simplex2d(s, t, true))
      draw_simplex2d(s, t->S[j], true);
  }
}

void IntelligentSwapEdges(Surface * s, GMSHMetric * m)
{
  int i, j, k;
  List_T *AllTrg = Tree2List(s->Simplexes);
  Vertex *p[4], *q[4];
  Simplex *t;
  for(i = 0; i < List_Nbr(AllTrg); i++) {
    k = rand() % List_Nbr(AllTrg);
    List_Read(AllTrg, k, &t);
    j = rand() % 3;
    if(t->ExtractOppositeEdges(j, p, q)) {
      double qp = 2. * m->EdgeLengthOnSurface(s, p, 1)
        / (RacineDeTrois * (p[0]->lc + p[1]->lc));
      double qq = 2. * m->EdgeLengthOnSurface(s, q, 1)
        / (RacineDeTrois * (q[0]->lc + q[1]->lc));
      if(fabs(qp) > fabs(qq)) {
        if(draw_simplex2d(s, t, false))
          draw_simplex2d(s, t->S[j], false);
        t->SwapEdge(j);
        if(draw_simplex2d(s, t, true))
          draw_simplex2d(s, t->S[j], true);
      }
    }
  }
  List_Delete(AllTrg);
}

int AlgorithmeMaillage2DAnisotropeModeJF(Surface * s)
{
  List_T *Points = List_Create(100, 100, sizeof(Vertex *));
  int j, i, N, n;
  List_T *c;
  Curve *cur, *curinv;
  extern int FACE_DIMENSION;
  Simplex *simp;
  Vertex *newv;
  static int COUNT = 0;

  FACE_DIMENSION = 1;

  SURF = s;

  if(s->Typ == MSH_SURF_PLAN || s->Typ == MSH_SURF_REGL
     || s->Typ == MSH_SURF_TRIC)
    PARAMETRIC = NULL;

  ZONEELIMINEE = s->Num;

  for(i = 0; i < List_Nbr(s->Contours); i++) {
    List_Read(s->Contours, i, &c);
    for(j = 0; j < List_Nbr(c); j++) {
      Vertex *pv;
      List_Read(c, j, &pv);
      List_Add(Points, &pv);
    }
  }

  N = List_Nbr(Points);
  n = N + 100;

  Msg(STATUS1, "Mesh 2D... (initial)");

  Convex_Hull_Mesh_2D(Points, s);
  List_Reset(Points);
  Link_Simplexes(NULL, s->Simplexes);

  //return 1;

  if(!Restore_Boundary(s)) {
    //s->Simplexes = Tree_Create(sizeof(Simplex*),compareSimplex);
    FACE_DIMENSION = 2;
    Tree_Action(s->Simplexes, TRIE_MON_GARS);
    return 1;
  }

  Tree_Action(s->Simplexes, TRIE_MON_GARS);
  Link_Simplexes(NULL, s->Simplexes);
  List_T *List = Tree2List(s->Simplexes);
  Tree_Delete(s->Simplexes);
  s->Simplexes = Tree_Create(sizeof(Simplex *), compareQuality);
  for(i = 0; i < List_Nbr(List); i++)
    Tree_Add(s->Simplexes, List_Pointer(List, i));
  List_Delete(List);

  //  return 1;

  FacesTree = Tree_Create(sizeof(Simplex *), compareSimpSurf);
  for(i = 0; i < List_Nbr(s->Generatrices); i++) {
    List_Read(s->Generatrices, i, &cur);
    curinv = FindCurve(abs(cur->Num));
    List_T *temp = Tree2List(curinv->Simplexes);
    for(j = 0; j < List_Nbr(temp); j++) {
      Tree_Add(FacesTree, List_Pointer(temp, j));
    }
    List_Delete(temp);
  }

  Restore_Surface(s);

  // MEMORY LEAK (JF)
  Tree_Delete(FacesTree);

  Suppress = List_Create(10, 10, sizeof(Simplex *));
  Tree_Action(s->Simplexes, suppress_simplex_2D);
  for(i = 0; i < List_Nbr(Suppress); i++) {
    Tree_Suppress(s->Simplexes, List_Pointer(Suppress, i));
  }

  if(CTX.mesh.initial_only == 2){
    List = Tree2List(s->Vertices);
    for(i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &THEV);
      if(THEV->Num < 0)
	Tree_Suppress(s->Vertices, &THEV);
    }
    List_Delete(List);
    List_Delete(Points);
    for(i = 0; i < List_Nbr(Suppress); i++)
      Free_Simplex(List_Pointer(Suppress, i), 0);
    List_Delete(Suppress);
    return 1;
  }

  Msg(STATUS1, "Mesh 2D... (final)");

  if(!Tree_Right(s->Simplexes, &simp))
    Msg(WARNING, "No simplex left");
  else {
    i = 0;
    while(simp->Quality > CONV_VALUE) {
      newv = NewVertex_2D(simp);
      while(!simp->Pt_In_Simplex_2D(newv) &&
            (simp->S[0] == &MyNewBoundary
             || !simp->S[0]->Pt_In_Simplex_2D(newv))
            && (simp->S[1] == &MyNewBoundary
                || !simp->S[1]->Pt_In_Simplex_2D(newv))
            && (simp->S[2] == &MyNewBoundary
                || !simp->S[2]->Pt_In_Simplex_2D(newv))) {
        /*
           Msg(INFO,"pt : %12.5E %12.5E",newv->Pos.X,newv->Pos.Y);
           Msg(INFO,"not in : (%12.5E %12.5E) (%12.5E %12.5E) (%12.5E %12.5E)",
           simp->V[0]->Pos.X,simp->V[0]->Pos.Y,simp->V[1]->Pos.X,
           simp->V[1]->Pos.Y,simp->V[2]->Pos.X,simp->V[2]->Pos.Y);
         */
        Tree_Suppress(s->Simplexes, &simp);
        simp->Quality /= 2.;
        Tree_Insert(s->Simplexes, &simp);
        Tree_Right(s->Simplexes, &simp);
        if(simp->Quality < CONV_VALUE)
          break;
        newv = NewVertex_2D(simp);
      }
      if(simp->Quality < CONV_VALUE)
        break;
      i++;
      if(i % n == n - 1) {
        volume = 0.0;
        Tree_Action(s->Simplexes, VSIM_2D);
        Msg(STATUS2, "Nod=%d Elm=%d Sur=%g Conv=%g->%g",
            Tree_Nbr(s->Vertices), Tree_Nbr(s->Simplexes),
	    volume, simp->Quality, CONV_VALUE);
      }
      Bowyer_Watson_2D(s, newv, simp, 0);
      Tree_Right(s->Simplexes, &simp);
      //if(i>COUNT)break;
    }
  }

  //for(i=0;i<3;i++)RandomSwapEdges2d(s);
  //for(i=0;i<2;i++)IntelligentSwapEdges(s,THEM->Metric);

  List_Reset(Points);
  FACE_DIMENSION = 2;
  COUNT++;

  Tree_Action(s->Simplexes, TRIE_MON_GARS);
  Link_Simplexes(NULL, s->Simplexes);
  List = Tree2List(s->Simplexes);
  Tree_Delete(s->Simplexes);
  s->Simplexes = Tree_Create(sizeof(Simplex *), compareSimplex);
  for(i = 0; i < List_Nbr(List); i++)
    Tree_Add(s->Simplexes, List_Pointer(List, i));
  List_Delete(List);

  /*suppression des points de la boite */
  List = Tree2List(s->Vertices);
  for(i = 0; i < List_Nbr(List); i++) {
    List_Read(List, i, &THEV);
    if(THEV->Num < 0) {
      Tree_Suppress(s->Vertices, &THEV);
      // BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG 
      // MEMORY LEAK (JF) BUT THIS CAUSES PROBLEMS AFTER !!      
      // Free(THEV);
      // BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG BUG 
    }
  }
  List_Delete(List);

  if(!Tree_Nbr(s->Simplexes))
    Msg(GERROR, "No triangles in surface %d", s->Num);

  /*
     RandomSwapEdges2d(s);
     for(i=0;i<1;i++)IntelligentSwapEdges(s,THEM->Metric);
   */
  //IntelligentSwapEdges(s,THEM->Metric);

  List_Delete(Points);


  // WAS A MEMORY LEAK
  for(i = 0; i < List_Nbr(Suppress); i++) {
    Free_Simplex(List_Pointer(Suppress, i), 0);
  }
  List_Delete(Suppress);


  return 1;
}
