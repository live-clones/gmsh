// $Id: 3D_Coherence.cpp,v 1.37 2006-08-05 10:05:45 geuzaine Exp $
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "3D_Mesh.h"
#include "Create.h"

extern Mesh *THEM;
extern int FACE_DIMENSION;
extern Simplex MyNewBoundary;
extern int edges_tetra[6][2];
extern int edges_non[3];

static Volume *THEVOL;
static Edge *TheEdge;
static Face *TheFace;
static List_T *Teti;

List_T *Missing, *MissingF, *MissingS;
Tree_T *EdgesTree, *FacesTree, *swaps, *touchedvertex;

int memesens(Vertex * v1, Vertex * v2, Vertex * v3,
             Vertex * c1, Vertex * c2, Vertex * c3)
{
  double v12[3], v13[3], n1[3], n2[3], p;

  v12[0] = c1->Pos.X - c2->Pos.X;
  v12[1] = c1->Pos.Y - c2->Pos.Y;
  v12[2] = c1->Pos.Z - c2->Pos.Z;

  v13[0] = c1->Pos.X - c3->Pos.X;
  v13[1] = c1->Pos.Y - c3->Pos.Y;
  v13[2] = c1->Pos.Z - c3->Pos.Z;

  prodve(v12, v13, n1);

  v12[0] = v1->Pos.X - v2->Pos.X;
  v12[1] = v1->Pos.Y - v2->Pos.Y;
  v12[2] = v1->Pos.Z - v2->Pos.Z;

  v13[0] = v1->Pos.X - v3->Pos.X;
  v13[1] = v1->Pos.Y - v3->Pos.Y;
  v13[2] = v1->Pos.Z - v3->Pos.Z;

  prodve(v12, v13, n2);

  prosca(n1, n2, &p);

  return ((p > 0) ? 1 : 0);
}

static void pvertex(void *a, void *b)
{
  /*
     Vertex *v;
     v = (Vertex *) a;
     printf ("noeud %d = (%12.5E,%12.5E,%12.5E)\n", v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z);
   */
}

static void pedge(void *a, void *b)
{
  /*
     Edge *e;
     e = (Edge *) a;
     printf ("arete %d (%12.5E,%12.5E,%12.5E) -> %d (%12.5E,%12.5E,%12.5E)\n",
     e->V[0]->Num, e->V[0]->Pos.X, e->V[0]->Pos.Y, e->V[0]->Pos.Z,
     e->V[1]->Num, e->V[1]->Pos.X, e->V[1]->Pos.Y, e->V[1]->Pos.Z);
   */
}

void find_quads(void *a, void *b)
{
  Edge *q;
  Edge diag;
  Simplex *s1, *s2;
  q = (Edge *) a;

  if(!List_Search(Missing, q, compareEdge))
    return;

  if(List_Nbr(q->Simplexes) != 2)
    return;

  List_Read(q->Simplexes, 0, &s1);
  List_Read(q->Simplexes, 1, &s2);
  if(s1->iEnt != s2->iEnt)
    return;
  if(!q->O[1])
    return;

  diag.V[0] = q->O[0];
  diag.V[1] = q->O[1];

  if(Tree_Search(EdgesTree, &diag)) {
    Tree_Add(swaps, q);
  }
}

void swap_quads(void *a, void *b)
{
  Edge *q;
  Simplex *s1, *s2;

  q = (Edge *) a;
  List_Read(q->Simplexes, 0, &s1);
  List_Read(q->Simplexes, 1, &s2);

  if(Tree_Query(touchedvertex, &q->V[0]))
    return;
  if(Tree_Query(touchedvertex, &q->V[1]))
    return;
  if(Tree_Query(touchedvertex, &q->O[0]))
    return;
  if(Tree_Query(touchedvertex, &q->O[1]))
    return;

  Tree_Add(touchedvertex, &q->V[0]);
  Tree_Add(touchedvertex, &q->V[1]);
  Tree_Add(touchedvertex, &q->O[0]);
  Tree_Add(touchedvertex, &q->O[1]);

  if(memesens(s1->V[0], s1->V[1], s1->V[2], q->O[0], q->O[1], q->V[0])) {
    s1->V[0] = q->O[0];
    s1->V[1] = q->O[1];
    s1->V[2] = q->V[0];
  }
  else {
    s1->V[0] = q->O[1];
    s1->V[1] = q->O[0];
    s1->V[2] = q->V[0];
  }

  if(memesens(s2->V[0], s2->V[1], s2->V[2], q->O[0], q->O[1], q->V[1])) {
    s2->V[0] = q->O[0];
    s2->V[1] = q->O[1];
    s2->V[2] = q->V[1];
  }
  else {
    s2->V[0] = q->O[1];
    s2->V[1] = q->O[0];
    s2->V[2] = q->V[1];
  }

  s1->F[0].V[0] = s1->V[0];
  s1->F[0].V[1] = s1->V[1];
  s1->F[0].V[2] = s1->V[2];

  s2->F[0].V[0] = s2->V[0];
  s2->F[0].V[1] = s2->V[1];
  s2->F[0].V[2] = s2->V[2];

  qsort(s1->F[0].V, 3, sizeof(Vertex *), compareVertex);
  qsort(s2->F[0].V, 3, sizeof(Vertex *), compareVertex);

  List_Suppress(Missing, q, compareEdge);
  q->V[0] = q->O[0];
  q->V[1] = q->O[1];

}

int create_Quads(Volume * V)
{
  int i, n;
  Surface *S;
  swaps = Tree_Create(sizeof(Edge), compareEdge);
  touchedvertex = Tree_Create(sizeof(Vertex *), compareVertex);
  for(i = 0; i < List_Nbr(V->Surfaces); i++) {
    List_Read(V->Surfaces, i, &S);
    Tree_Action(S->Edges, find_quads);
  }
  Tree_Action(swaps, swap_quads);
  n = Tree_Nbr(swaps);
  Tree_Delete(swaps);
  Tree_Delete(touchedvertex);
  return n;
}

void create_Fac(void *a, void *b)
{
  Simplex **ps, *s;
  int i;
  ps = (Simplex **) a;
  s = *ps;
  for(i = 0; i < 4; i++) {
    Tree_Insert(FacesTree, &s->F[i]);
  }
}


void create_Faces(Volume * V)
{
  if(V->Faces) {
    Tree_Delete(V->Faces);
  }
  V->Faces = Tree_Create(sizeof(Face), compareFace);
  FacesTree = V->Faces;
  Tree_Action(V->Simplexes, create_Fac);
}

void create_Edge(void *a, void *b)
{
  Simplex **ps, *s;
  int N, i, j;
  Edge E, *pE;
  ps = (Simplex **) a;
  s = *ps;
  int edges[6][2];

  if(s->V[3]) {
    N = 6;
    for(i = 0; i < N; i++)
      for(j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }
  else if(s->V[2]) {
    N = 3;
    for(i = 0; i < N; i++)
      for(j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }
  else {
    N = 1;
    for(i = 0; i < N; i++)
      for(j = 0; j < 2; j++)
        edges[i][j] = edges_tetra[i][j];
  }

  for(i = 0; i < N; i++) {
    E.V[0] = s->V[edges[i][0]];
    E.V[1] = s->V[edges[i][1]];
    if((pE = (Edge *) Tree_PQuery(EdgesTree, &E))) {
      List_Add(pE->Simplexes, ps);
      if(N == 3)
        pE->O[1] = s->V[edges_non[i]];
    }
    else {
      E.Simplexes = List_Create(2, 1, sizeof(Simplex *));
      if(N == 3)
        E.O[0] = s->V[edges_non[i]];
      if(N == 3)
        E.O[1] = NULL;
      List_Add(E.Simplexes, &s);
      E.newv = NULL;
      Tree_Replace(EdgesTree, &E);
    }
  }
}

void create_Edges(Volume * V)
{
  int i;
  Surface *S;

  // MEMORY LEAK (JF)
  if(V->Edges) {
    Tree_Action(V->Edges, Free_Edge);
    Tree_Delete(V->Edges);
  }

  V->Edges = Tree_Create(sizeof(Edge), compareEdge);
  EdgesTree = V->Edges;

  Tree_Action(V->Simplexes, create_Edge);
  for(i = 0; i < List_Nbr(V->Surfaces); i++) {
    List_Read(V->Surfaces, i, &S);
    // MEMORY LEAK (JF)
    if(S->Edges) {
      // BUG BUG BUG (This causes crash)
      //Tree_Action(S->Edges,Free_Edge);
      Tree_Delete(S->Edges);
    }
    S->Edges = Tree_Create(sizeof(Edge), compareEdge);
    EdgesTree = S->Edges;
    Tree_Action(S->Simplexes, create_Edge);
  }
}

void find_missing(void *a, void *b)
{
  Edge *e;

  e = (Edge *) a;

  if(!Tree_Search(EdgesTree, e)) {
    List_Add(Missing, e);
    Tree_Add(EdgesTree, e);
  }
}

void find_missingf(void *a, void *b)
{
  Simplex *s;
  s = *(Simplex **) a;

  if(!FacesTree || !Tree_Search(FacesTree, &s->F[0])) {
    List_Add(MissingF, &s->F[0]);
    List_Add(MissingS, &s);
  }
}


List_T *Missing_Edges(Volume * V)
{
  int i;
  Surface *S;
  Missing = List_Create(10, 10, sizeof(Edge));

  EdgesTree = V->Edges;
  for(i = 0; i < List_Nbr(V->Surfaces); i++) {
    List_Read(V->Surfaces, i, &S);
    Tree_Action(S->Edges, find_missing);
  }
  return Missing;
}

List_T *Missing_Faces(Volume * V)
{
  int i;
  Surface *S;
  MissingF = List_Create(10, 10, sizeof(Face));
  MissingS = List_Create(10, 10, sizeof(Simplex *));

  for(i = 0; i < List_Nbr(V->Surfaces); i++) {
    List_Read(V->Surfaces, i, &S);
    Tree_Action(S->Simplexes, find_missingf);
  }
  return MissingF;
}

/* Creation de listes de tetraedres qui intersectent
   l'arete TheEdge */

List_T *traite;
Tree_T *traited;

void Ajoute_traite(Simplex ** s)
{
  if(!Tree_Search(traited, s)) {
    List_Add(traite, s);
    Tree_Add(traited, s);
  }
}

Intersection *thei;
Vertex *m1, *m2, *e1, *e2;
Face *f1;
int Cloture;

void fillRi(void *a, void *b)
{
  int i, c;
  Simplex *s;

  s = *(Simplex **) a;
  c = 0;
  for(i = 0; i < 4; i++) {
    if(!compareVertex(&e1, &s->V[i]))
      c++;
    if(!compareVertex(&e2, &s->V[i]))
      c++;
  }
  if(c == 2) {
    Ajoute_traite(&s);
  }
}

void fillTeti(void *a, void *b)
{
  int i;
  Simplex *s;

  s = *(Simplex **) a;
  for(i = 0; i < 4; i++) {
    if(!compareVertex(&m1, &s->V[i])) {
      List_Add(Teti, &s);
      return;
    }
  }
}

Tree_T *TreexNewv;

typedef struct{
  int ef;
  Edge e;
  Face *f;
  Vertex *newv;
}xNewv;

int compxNewv(const void *a, const void *b)
{
  xNewv *q, *w;

  q = (xNewv *) a;
  w = (xNewv *) b;
  if(q->ef != w->ef)
    return (q->ef - w->ef);
  if(q->ef == 1)
    return compareEdge(&q->e, &w->e);
  if(q->ef == 2)
    return compareFace(q->f, w->f);
  return 1;
}

/* 
   ---------------------------------------------------
   Pour + de details, voir les travaux de P.L. George.
   ---------------------------------------------------

   Les routines ci dessous ont pour but de retrouver les
   aretes manquantes d'un maillage initial 3-D.

   En resume, il faut d'abord trouver ces aretes : find_missing

   Ensuite, il faut decouvrir les intersections des aretes manquantes
   avec les tetraedres du maillage, les intersections sont de plusieurs 
   types :

   intersection noeud-noeud (type 1)
   intersection arete-face  (type 2)
   intersection face -face  (type 3)
   intersection arete-arete (type 4)
   intersection face -noeud (type 5)
   intersection arete-noeud (type 6)
   intersection noeud seul  (type 7)
   intersection arete seule (type 8)

   Selon le type d'intersection, on appliquera une transformation locale au maillage
   de telle sorte que l'arete manquante est recouvree.
 */


#define eps_prec (-1.e-10)

int Edge_Node(Edge * e, Vertex * v)
{
  double u = 0.0, lc;

  if(!compareVertex(&e->V[0], &v))
    return 1;
  if(!compareVertex(&e->V[1], &v))
    return 1;
  lc =
    myhypot(myhypot
            (e->V[0]->Pos.X - e->V[1]->Pos.X,
             e->V[0]->Pos.Y - e->V[1]->Pos.Y),
            e->V[0]->Pos.Z - e->V[1]->Pos.Z);

  if(e->V[0]->Pos.X != e->V[1]->Pos.X) {
    u = (v->Pos.X - e->V[0]->Pos.X) / (e->V[1]->Pos.X - e->V[0]->Pos.X);
  }
  else if(e->V[0]->Pos.Y != e->V[1]->Pos.Y) {
    u = (v->Pos.Y - e->V[0]->Pos.Y) / (e->V[1]->Pos.Y - e->V[0]->Pos.Y);
  }
  else if(e->V[0]->Pos.Z != e->V[1]->Pos.Z) {
    u = (v->Pos.Z - e->V[0]->Pos.Z) / (e->V[1]->Pos.Z - e->V[0]->Pos.Z);
  }

  if(u < -eps_prec || u > 1. + eps_prec)
    return 0;
  if(fabs((1. - u) * e->V[0]->Pos.X + u * e->V[1]->Pos.X - v->Pos.X) >
     1.e-7 * lc) {
    return 0;
  }
  if(fabs((1. - u) * e->V[0]->Pos.Y + u * e->V[1]->Pos.Y - v->Pos.Y) >
     1.e-7 * lc) {
    return 0;
  }
  if(fabs((1. - u) * e->V[0]->Pos.Z + u * e->V[1]->Pos.Z - v->Pos.Z) >
     1.e-7 * lc) {
    return 0;
  }
  return 2;
}

List_T *SurfComm(List_T * S1, List_T * S2)
{
  int i;
  List_T *List;
  Surface *s;
  List = List_Create(2, 2, sizeof(Surface *));

  if(!S1 || !S2)
    return List;

  for(i = 0; i < List_Nbr(S1); i++) {
    List_Read(S1, i, &s);
    if(List_Search(S2, &s, compareSurface))
      List_Add(List, &s);
  }
  return List;
}


Vertex *Edge_Face(Edge * e, Face * f)
{
  Vertex *v;

  double mat[3][3], det;
  double b[3], res[3];

  if(!compareVertex(&e->V[0], &f->V[0]))
    return NULL;
  if(!compareVertex(&e->V[0], &f->V[1]))
    return NULL;
  if(!compareVertex(&e->V[0], &f->V[2]))
    return NULL;
  if(!compareVertex(&e->V[1], &f->V[0]))
    return NULL;
  if(!compareVertex(&e->V[1], &f->V[1]))
    return NULL;
  if(!compareVertex(&e->V[1], &f->V[2]))
    return NULL;

  mat[0][0] = f->V[1]->Pos.X - f->V[0]->Pos.X;
  mat[0][1] = f->V[2]->Pos.X - f->V[0]->Pos.X;
  mat[0][2] = e->V[0]->Pos.X - e->V[1]->Pos.X;

  mat[1][0] = f->V[1]->Pos.Y - f->V[0]->Pos.Y;
  mat[1][1] = f->V[2]->Pos.Y - f->V[0]->Pos.Y;
  mat[1][2] = e->V[0]->Pos.Y - e->V[1]->Pos.Y;

  mat[2][0] = f->V[1]->Pos.Z - f->V[0]->Pos.Z;
  mat[2][1] = f->V[2]->Pos.Z - f->V[0]->Pos.Z;
  mat[2][2] = e->V[0]->Pos.Z - e->V[1]->Pos.Z;

  b[0] = e->V[0]->Pos.X - f->V[0]->Pos.X;
  b[1] = e->V[0]->Pos.Y - f->V[0]->Pos.Y;
  b[2] = e->V[0]->Pos.Z - f->V[0]->Pos.Z;

  if(!sys3x3_with_tol(mat, b, res, &det))       //???TOLERANCE?????????????
    return NULL;

  /* res donne les coordonnees u,v de l'intersection dans la
     face et donne w la coordonnee de l'intersection dans
     l'arete
   */
  /* coordonnees dans l'arete */
  if(res[2] >= 1.0 - eps_prec || res[2] <= eps_prec)
    return NULL;

  /* coordonnees dans la face */
  if(res[0] >= 1.0 + eps_prec || res[0] <= -eps_prec)
    return NULL;
  if(res[1] <= -eps_prec || res[1] >= 1. + eps_prec - res[0])
    return NULL;


  if(res[0] == 1.0 || res[2] == 0.0 || res[0] == 0.0 ||
     res[1] == 1. - res[0] || res[1] == 0.0 || res[0] == 1.0) {
    Msg(DEBUG1, "Face p1  %g %g %g", f->V[0]->Pos.X, f->V[0]->Pos.Y,
        f->V[0]->Pos.Z);
    Msg(DEBUG2, "facette p2  %g %g %g", f->V[1]->Pos.X, f->V[1]->Pos.Y,
        f->V[1]->Pos.Z);
    Msg(DEBUG2, "facette p3  %g %g %g", f->V[2]->Pos.X, f->V[2]->Pos.Y,
        f->V[2]->Pos.Z);
    Msg(DEBUG2, "edge    e2  %g %g %g", e->V[0]->Pos.X, e->V[0]->Pos.Y,
        e->V[0]->Pos.Z);
    Msg(DEBUG2, "edge    e3  %g %g %g", e->V[1]->Pos.X, e->V[1]->Pos.Y,
        e->V[1]->Pos.Z);
    Msg(DEBUG3, "%g %g %g", res[0], res[1], res[2]);
  }

  v = Create_Vertex(++THEM->MaxPointNum,
                    (1. - res[2]) * e->V[0]->Pos.X + res[2] * e->V[1]->Pos.X,
                    (1. - res[2]) * e->V[0]->Pos.Y + res[2] * e->V[1]->Pos.Y,
                    (1. - res[2]) * e->V[0]->Pos.Z + res[2] * e->V[1]->Pos.Z,
                    (1. - res[2]) * e->V[0]->lc + res[2] * e->V[1]->lc, 0.0);
  v->ListSurf = List_Create(1, 1, sizeof(Surface *));

  return v;
}


Vertex *Edge_Edge(Edge * e, Vertex * v1, Vertex * v2)
{
  Vertex *v;
  int dir;
  //int dx1, dx2, dy1, dy2, dz1, dz2;
  double mat[2][2];
  double b[3], res[3];
  double XmaxS, XminS, YmaxS, YminS, ZmaxS, ZminS, lc;
  double XmaxV, XminV, YmaxV, YminV, ZmaxV, ZminV, val = 0.;

  if(!compareVertex(&e->V[0], &v1))
    return NULL;
  if(!compareVertex(&e->V[1], &v1))
    return NULL;
  if(!compareVertex(&e->V[0], &v2))
    return NULL;
  if(!compareVertex(&e->V[1], &v2))
    return NULL;

  XminS = DMIN(e->V[0]->Pos.X, e->V[1]->Pos.X);
  XmaxS = DMAX(e->V[0]->Pos.X, e->V[1]->Pos.X);
  YminS = DMIN(e->V[0]->Pos.Y, e->V[1]->Pos.Y);
  YmaxS = DMAX(e->V[0]->Pos.Y, e->V[1]->Pos.Y);
  ZminS = DMIN(e->V[0]->Pos.Z, e->V[1]->Pos.Z);
  ZmaxS = DMAX(e->V[0]->Pos.Z, e->V[1]->Pos.Z);

  XminV = DMIN(v1->Pos.X, v2->Pos.X);
  XmaxV = DMAX(v1->Pos.X, v2->Pos.X);
  YminV = DMIN(v1->Pos.Y, v2->Pos.Y);
  YmaxV = DMAX(v1->Pos.Y, v2->Pos.Y);
  ZminV = DMIN(v1->Pos.Z, v2->Pos.Z);
  ZmaxV = DMAX(v1->Pos.Z, v2->Pos.Z);

  if(XmaxS < XminV || XmaxV < XminS)
    return NULL;
  if(YmaxS < YminV || YmaxV < YminS)
    return NULL;
  if(ZmaxS < ZminV || ZmaxV < ZminS)
    return NULL;

  lc = myhypot(myhypot(XminV - XmaxV, YminV - YmaxV), ZminV - ZmaxV);

  /*
     if (e->V[1]->Pos.X != e->V[0]->Pos.X &&
     fabs (e->V[1]->Pos.X - e->V[0]->Pos.X) / lc > 1.e-2)
     dx1 = 1;
     else
     dx1 = 0;
     if (e->V[1]->Pos.Y != e->V[0]->Pos.Y &&
     fabs (e->V[1]->Pos.Y - e->V[0]->Pos.Y) / lc > 1.e-2)
     dy1 = 1;
     else
     dy1 = 0;
     if (e->V[1]->Pos.Z != e->V[0]->Pos.Z &&
     fabs (e->V[1]->Pos.Z - e->V[0]->Pos.Z) / lc > 1.e-2)
     dz1 = 1;
     else
     dz1 = 0;

     if (v1->Pos.X != v2->Pos.X &&
     fabs (v1->Pos.X - v2->Pos.X) / lc > 1.e-2)
     dx2 = 1;
     else
     dx2 = 0;
     if (v1->Pos.Y != v2->Pos.Y &&
     fabs (v1->Pos.Y - v2->Pos.Y) / lc > 1.e-2)
     dy2 = 1;
     else
     dy2 = 0;
     if (v1->Pos.Z != v2->Pos.Z &&
     fabs (v1->Pos.Z - v2->Pos.Z) / lc > 1.e-2)
     dz2 = 1;
     else
     dz2 = 0;

     if(dx1 && dx2){
     mat[0][0] = e->V[1]->Pos.X - e->V[0]->Pos.X;
     mat[0][1] = v1->Pos.X - v2->Pos.X;
     b[0] = - e->V[0]->Pos.X + v1->Pos.X;
     if(dy1 || dy2){
     mat[1][0] = e->V[1]->Pos.Y - e->V[0]->Pos.Y;
     mat[1][1] = v1->Pos.Y - v2->Pos.Y;
     b[1] = - e->V[0]->Pos.Y + v1->Pos.Y;
     dir = 2;
     }
     else if(dz1 || dz2){
     mat[1][0] = e->V[1]->Pos.Z - e->V[0]->Pos.Z;
     mat[1][1] = v1->Pos.Z - v2->Pos.Z;
     b[1] = - e->V[0]->Pos.Z + v1->Pos.Z;
     dir = 3;
     }
     }
     else if (dy1 && dy2){
     mat[0][0] = e->V[1]->Pos.Y - e->V[0]->Pos.Y;
     mat[0][1] = v1->Pos.Y - v2->Pos.Y;
     b[0] = - e->V[0]->Pos.Y + v1->Pos.Y;
     if(dy1 || dy2){
     mat[1][0] = e->V[1]->Pos.Y - e->V[0]->Pos.Y;
     mat[1][1] = v1->Pos.Y - v2->Pos.Y;
     b[1] = - e->V[0]->Pos.Y + v1->Pos.Y;
     dir = 2;
     }
     else if(dz1 || dz2){
     mat[1][0] = e->V[1]->Pos.Z - e->V[0]->Pos.Z;
     mat[1][1] = v1->Pos.Z - v2->Pos.Z;
     b[1] = - e->V[0]->Pos.Z + v1->Pos.Z;
     dir = 3;
     }
     }
   */


  mat[0][0] = e->V[1]->Pos.X - e->V[0]->Pos.X;
  mat[0][1] = v1->Pos.X - v2->Pos.X;
  b[0] = -e->V[0]->Pos.X + v1->Pos.X;
  mat[1][0] = e->V[1]->Pos.Y - e->V[0]->Pos.Y;
  mat[1][1] = v1->Pos.Y - v2->Pos.Y;
  b[1] = -e->V[0]->Pos.Y + v1->Pos.Y;

  if(!sys2x2(mat, b, res)) {
    mat[1][0] = e->V[1]->Pos.Z - e->V[0]->Pos.Z;
    mat[1][1] = v1->Pos.Z - v2->Pos.Z;
    b[1] = -e->V[0]->Pos.Z + v1->Pos.Z;
    if(!sys2x2(mat, b, res)) {
      mat[0][0] = e->V[1]->Pos.Y - e->V[0]->Pos.Y;
      mat[0][1] = v1->Pos.Y - v2->Pos.Y;
      b[0] = -e->V[0]->Pos.Y + v1->Pos.Y;
      if(!sys2x2(mat, b, res)) {
        /* SEGMENTS PARALLELES */
        /* printf("systeme singulier\n");
           printf("arete %d -> %d\n",v1->Num,v2->Num);
           printf("arete %g %g %g --> %g %g %g\n",
           v1->Pos.X,v1->Pos.Y,v1->Pos.Z,v2->Pos.X,v2->Pos.Y,v2->Pos.Z);
           printf("arete %g %g %g --> %g %g %g\n",
           e->V[0]->Pos.X,e->V[0]->Pos.Y,e->V[0]->Pos.Z,
           e->V[1]->Pos.X,e->V[1]->Pos.Y,e->V[1]->Pos.Z);
           printf("%g %g\n",mat[0][0],mat[0][1]);
           printf("%g %g\n",mat[1][0],mat[1][1]);
           getchar();
         */
        return NULL;
      }
      else {
        dir = 1;
      }
    }
    else {
      dir = 2;
    }
  }
  else {
    dir = 3;
  }

  if(res[0] <= eps_prec || res[0] >= 1.0 - eps_prec)
    return NULL;
  if(res[1] <= eps_prec || res[1] >= 1.0 - eps_prec)
    return NULL;

  switch (dir) {
  case 1:
    val = e->V[0]->Pos.X * (1. - res[0]) + e->V[1]->Pos.X * res[0] -
      v1->Pos.X * (1. - res[1]) - v2->Pos.X * res[1];
    break;
  case 2:
    val = e->V[0]->Pos.Y * (1. - res[0]) + e->V[1]->Pos.Y * res[0] -
      v1->Pos.Y * (1. - res[1]) - v2->Pos.Y * res[1];
    break;
  case 3:
    val = e->V[0]->Pos.Z * (1. - res[0]) + e->V[1]->Pos.Z * res[0] -
      v1->Pos.Z * (1. - res[1]) - v2->Pos.Z * res[1];
    break;
  }
  if(fabs(val / lc) > 1.e-08 /*08 */ )
    return NULL;
  v = Create_Vertex(++THEM->MaxPointNum,
                    (1. - res[0]) * e->V[0]->Pos.X + res[0] * e->V[1]->Pos.X,
                    (1. - res[0]) * e->V[0]->Pos.Y + res[0] * e->V[1]->Pos.Y,
                    (1. - res[0]) * e->V[0]->Pos.Z + res[0] * e->V[1]->Pos.Z,
                    (1. - res[0]) * e->V[0]->lc + res[0] * e->V[1]->lc, 0.0);

  v->ListSurf = List_Create(1, 1, sizeof(Surface *));
  return v;

}

int intersection_2_aretes(double Xa, double Ya, double Za,
                          double Xb, double Yb, double Zb,
                          double Xc, double Yc, double Zc,
                          double Xd, double Yd, double Zd,
                          int p1, int p2, int p3, int p4,
                          double *X, double *Y, double *Z)
{
  Vertex *v1, *v2, *v3, *v4, *v;
  Edge e;
  v1 = Create_Vertex(p1, Xa, Ya, Za, 0.0, 0.0);
  v2 = Create_Vertex(p2, Xb, Yb, Zb, 0.0, 0.0);
  v3 = Create_Vertex(p3, Xc, Yc, Zc, 0.0, 0.0);
  v4 = Create_Vertex(p4, Xd, Yd, Zd, 0.0, 0.0);

  e.V[0] = v3;
  e.V[1] = v4;

  if((v = Edge_Edge(&e, v1, v2))) {

    *X = v->Pos.X;
    *Y = v->Pos.Y;
    *Z = v->Pos.Z;

    Free(v1);
    Free(v2);
    Free(v3);
    Free(v4);
    Free(v);
    return 1;
  }
  else {
    Free(v1);
    Free(v2);
    Free(v3);
    Free(v4);
    Free(v);
    return 0;
  }

}

List_T *NewPoints;

void Intersect_Edge_Simplexe(Edge * e, Simplex * s, Intersection * I)
{
  int i, NbInt = 0, NbVer = 0, NbEdg = 0, NbFac = 0, j;
  Vertex *v;
  double XminS, YminS, ZminS, XmaxS, YmaxS, ZmaxS;
  double XminE, YminE, ZminE, XmaxE, YmaxE, ZmaxE;
  xNewv x;

  /* On initialise l'intersection */

  I->NbVertex = I->NbFace = I->NbEdge = 0;
  I->s = s;
  I->e = e;
  I->NbIntersect = 0;

  /*
     On regarde d'abord si une intersection est possible en
     calculant les boites de l'arete et du simplexe 
   */

  if(s->V[3]) {
    NbVer = 4;
    NbEdg = 6;
    NbFac = 4;
    NbInt = 2;
  }
  else if(s->V[2]) {
    NbVer = 3;
    NbEdg = 3;
    NbFac = 1;
    NbInt = 2;
  }

  XminE = DMIN(e->V[0]->Pos.X, e->V[1]->Pos.X);
  XmaxE = DMAX(e->V[0]->Pos.X, e->V[1]->Pos.X);
  YminE = DMIN(e->V[0]->Pos.Y, e->V[1]->Pos.Y);
  YmaxE = DMAX(e->V[0]->Pos.Y, e->V[1]->Pos.Y);
  ZminE = DMIN(e->V[0]->Pos.Z, e->V[1]->Pos.Z);
  ZmaxE = DMAX(e->V[0]->Pos.Z, e->V[1]->Pos.Z);

  XminS = s->V[0]->Pos.X;
  XmaxS = s->V[0]->Pos.X;
  YminS = s->V[0]->Pos.Y;
  YmaxS = s->V[0]->Pos.Y;
  ZminS = s->V[0]->Pos.Z;
  ZmaxS = s->V[0]->Pos.Z;

  for(i = 1; i < NbVer; i++) {
    XminS = DMIN(XminS, s->V[i]->Pos.X);
    XmaxS = DMAX(XmaxS, s->V[i]->Pos.X);
    YminS = DMIN(YminS, s->V[i]->Pos.Y);
    YmaxS = DMAX(YmaxS, s->V[i]->Pos.Y);
    ZminS = DMIN(ZminS, s->V[i]->Pos.Z);
    ZmaxS = DMAX(ZmaxS, s->V[i]->Pos.Z);
  }
  if(XmaxS < XminE || XmaxE < XminS)
    return;
  if(YmaxS < YminE || YmaxE < YminS)
    return;
  if(ZmaxS < ZminE || ZmaxE < ZminS)
    return;

  /*
     On regarde si l'arete coupe un des 4 noeuds du
     simplexe
   */

  for(i = 0; i < NbVer; i++) {
    if((j = Edge_Node(e, s->V[i]))) {
      I->V[I->NbVertex] = s->V[i];
      I->iV[I->NbVertex++] = i;
      (I->NbIntersect)++;
      if(j == 2) {
        List_Replace(NewPoints, &s->V[i], compareVertex);
        //printf("l'arete intersecte un noeud\n");
        pvertex(s->V[i], s->V[i]);
        pedge(e, e);
      }
    }
  }

  if(I->NbIntersect == NbInt) {
    Msg(WARNING, "If the mesh is still correct after this, contact us :-)");
    return;
  }
  /* On regarde si l'arete coupe une autre arete */
  for(i = 0; i < NbEdg; i++) {
    x.ef = 1;
    x.e.V[0] = s->V[edges_tetra[i][0]];
    x.e.V[1] = s->V[edges_tetra[i][1]];
    if(Tree_Query(TreexNewv, &x)) {
      v = x.newv;
      I->E[I->NbEdge] = i;
      I->VE[(I->NbEdge)++] = v;
      (I->NbIntersect)++;
    }
    else if((v = Edge_Edge(e, s->V[edges_tetra[i][0]],
                           s->V[edges_tetra[i][1]]))) {
      List_Add(NewPoints, &v);
      I->E[I->NbEdge] = i;
      I->VE[(I->NbEdge)++] = v;
      (I->NbIntersect)++;
      x.newv = v;
      Tree_Add(TreexNewv, &x);
    }
  }

  if(I->NbIntersect == NbInt)
    return;

  /*
     On regarde si l'arete coupe une face
   */

  for(i = 0; i < NbFac; i++) {
    x.ef = 2;
    x.f = &s->F[i];
    if(Tree_Query(TreexNewv, &x)) {
      v = x.newv;
      I->VF[I->NbFace] = v;
      I->F[I->NbFace] = &s->F[i];
      I->iF[(I->NbFace)++] = i;
      (I->NbIntersect)++;
    }
    else if((v = Edge_Face(e, &s->F[i]))) {
      I->VF[I->NbFace] = v;
      List_Add(NewPoints, &v);
      I->F[I->NbFace] = &s->F[i];
      I->iF[I->NbFace++] = i;
      (I->NbIntersect)++;
      x.newv = v;
      Tree_Add(TreexNewv, &x);
    }
  }
}


void Intersect_Face_Simplexe(Face * f, Simplex * s, Intersection * I)
{
  int i;
  Vertex *v;
  double XminS, YminS, ZminS, XmaxS, YmaxS, ZmaxS;
  double XminE, YminE, ZminE, XmaxE, YmaxE, ZmaxE;
  xNewv x;

  /* On initialise l'intersection */

  I->NbVertex = I->NbFace = I->NbEdge = 0;
  I->s = s;
  I->f = f;
  I->NbIntersect = 0;

  /*
     On regarde d'abord si une intersection est possible en
     calculant les boites de l'arete et du simplexe
   */

  XminE = DMIN(DMIN(f->V[0]->Pos.X, f->V[1]->Pos.X), f->V[2]->Pos.X);
  XmaxE = DMAX(DMAX(f->V[0]->Pos.X, f->V[1]->Pos.X), f->V[2]->Pos.X);
  YminE = DMIN(DMIN(f->V[0]->Pos.Y, f->V[1]->Pos.Y), f->V[2]->Pos.Y);
  YmaxE = DMAX(DMAX(f->V[0]->Pos.Y, f->V[1]->Pos.Y), f->V[2]->Pos.Y);
  ZminE = DMIN(DMIN(f->V[0]->Pos.Z, f->V[1]->Pos.Z), f->V[2]->Pos.Z);
  ZmaxE = DMAX(DMAX(f->V[0]->Pos.Z, f->V[1]->Pos.Z), f->V[2]->Pos.Z);

  XminS = s->V[0]->Pos.X;
  XmaxS = s->V[0]->Pos.X;
  YminS = s->V[0]->Pos.Y;
  YmaxS = s->V[0]->Pos.Y;
  ZminS = s->V[0]->Pos.Z;
  ZmaxS = s->V[0]->Pos.Z;

  for(i = 1; i < 4; i++) {
    XminS = DMIN(XminS, s->V[i]->Pos.X);
    XmaxS = DMAX(XmaxS, s->V[i]->Pos.X);
    YminS = DMIN(YminS, s->V[i]->Pos.Y);
    YmaxS = DMAX(YmaxS, s->V[i]->Pos.Y);
    ZminS = DMIN(ZminS, s->V[i]->Pos.Z);
    ZmaxS = DMAX(ZmaxS, s->V[i]->Pos.Z);
  }
  if(XmaxS < XminE || XmaxE < XminS)
    return;
  if(YmaxS < YminE || YmaxE < YminS)
    return;
  if(ZmaxS < ZminE || ZmaxE < ZminS)
    return;

  /* On regarde si l'arete coupe la facette */
  for(i = 0; i < 6; i++) {
    x.ef = 1;
    x.e.V[0] = s->V[edges_tetra[i][0]];
    x.e.V[1] = s->V[edges_tetra[i][1]];
    if(Tree_Query(TreexNewv, &x)) {
      v = x.newv;
      I->E[I->NbEdge] = i;
      I->VE[(I->NbEdge)++] = v;
      (I->NbIntersect)++;
    }
    else if((v = Edge_Face(&x.e, f))) {
      /* printf("%d %d %d %d\n",s->V[0]->Num,s->V[1]->Num,s->V[2]->Num,s->V[3]->Num); */
      List_Add(NewPoints, &v);
      I->E[I->NbEdge] = i;
      I->VE[I->NbEdge] = v;
      (I->NbEdge)++;
      (I->NbIntersect)++;
      x.newv = v;
      Tree_Add(TreexNewv, &x);
    }
  }
}

Tree_T *Actual_Tree, *TetAdd, *TetDel;

static void _Add(void *data, void *dum)
{
  Tree_Add(Actual_Tree, data);
}
static void _Del(void *data, void *dum)
{
  Tree_Suppress(Actual_Tree, data);
}

void Recover_Edge(void *a, void *b)
{
  Simplex *s;
  Intersection I;

  s = *(Simplex **) a;
  Intersect_Edge_Simplexe(TheEdge, s, &I);
  if(I.NbIntersect) {
    cut_tetraedre(&I, TetAdd, TetDel, THEVOL->Vertices);
  }
}

void Recover_Face(void *a, void *b)
{
  Simplex *s;
  Intersection I;

  s = *(Simplex **) a;
  Intersect_Face_Simplexe(TheFace, s, &I);
  if(I.NbEdge) {
    cut_tetraedre(&I, TetAdd, TetDel, THEVOL->Vertices);
  }
}

static double volume;

static void VSIM(void *a, void *b)
{
  Simplex *S;
  S = *(Simplex **) a;
  if(S->V[3])
    volume += fabs(S->Volume_Simplexe());
}

Vertex *DEPART;

int comparePos(const void *a, const void *b)
{
  Vertex *q, *w;
  double d1, d2;
  q = *(Vertex **) a;
  w = *(Vertex **) b;

  d1 = DSQR(q->Pos.X - DEPART->Pos.X) +
    DSQR(q->Pos.Y - DEPART->Pos.Y) + DSQR(q->Pos.Z - DEPART->Pos.Z);
  d2 = DSQR(w->Pos.X - DEPART->Pos.X) +
    DSQR(w->Pos.Y - DEPART->Pos.Y) + DSQR(w->Pos.Z - DEPART->Pos.Z);
  if(d1 < d2)
    return 1;
  if(d1 > d2)
    return -1;

  exit(1);
  return 1;
}

List_T *ListFaces;

void findFaces(void *a, void *b)
{
  Simplex *s;
  int i;
  s = *(Simplex **) a;
  if(List_Search(NewPoints, &s->V[0], compareVertex) ||
     List_Search(NewPoints, &s->V[1], compareVertex) ||
     List_Search(NewPoints, &s->V[2], compareVertex) ||
     List_Search(NewPoints, &s->V[3], compareVertex))
    /*
       printf("%d %d %d %d\n",s->V[0]->Num,s->V[1]->Num,s->V[2]->Num,s->V[3]->Num);
     */
    for(i = 0; i < 4; i++) {
      if(List_Search(NewPoints, &s->F[i].V[0], compareVertex) &&
         List_Search(NewPoints, &s->F[i].V[1], compareVertex) &&
         List_Search(NewPoints, &s->F[i].V[2], compareVertex))
        List_Replace(ListFaces, &s->F[i], compareFace);
    }
}

void findEdges(void *a, void *b)
{
}

Simplex *Create_Simplex_MemeSens(Simplex * sold, Vertex * v1, Vertex * v2,
                                 Vertex * v3)
{
  Simplex *s;

  if(memesens(sold->V[0], sold->V[1], sold->V[2], v1, v2, v3) > 0.0) {
    s = Create_Simplex(v1, v2, v3, NULL);
  }
  else {
    s = Create_Simplex(v2, v1, v3, NULL);
  }
  s->iEnt = sold->iEnt;
  return s;
}

int Coherence(Volume * v, Mesh * m)
{
  int i, j, k, Np, Nh, nb_swaps = 0;
  Surface *s;
  //Vertex V1, V2, *ver1, *ver2 ;
  Face Face;
  static Edge E, *pE1, *pE2, *pE3;
  Simplex *simp, *simp1;
  List_T *MissingEdges, *MissingFaces;

  FACE_DIMENSION = 2;

  //ver1 = &V1;
  //ver2 = &V2;

  THEVOL = v;

  Remise_A_Zero();

  /* Edge Swapping */
  do {
    create_Edges(v);
    MissingEdges = Missing_Edges(v);
    nb_swaps = create_Quads(v);
    Msg(INFO, "Swapped %d edges", nb_swaps);
  } while(nb_swaps);

  /* Missing Edges */
  create_Edges(v);
  MissingEdges = Missing_Edges(v);

  /* Missing Faces */
  create_Faces(v);
  MissingFaces = Missing_Faces(v);

  /* Edges Recovery */
  Msg(STATUS2, "Boundary edges recovery");

  volume = 0;
  Tree_Action(v->Simplexes, VSIM);
  Msg(INFO, "Volume = %g", volume);

  Msg(INFO1, "===================================================");
  Msg(INFO2, "Number of missing edges = %d", List_Nbr(Missing));
  Msg(INFO3, "===================================================");

  for(i = 0; i < List_Nbr(Missing); i++) {

    pE1 = (Edge *) List_Pointer(Missing, i);
    TheEdge = pE1;

    TreexNewv = Tree_Create(sizeof(xNewv), compxNewv);
    NewPoints = List_Create(1, 1, sizeof(Vertex *));
    TetAdd = Tree_Create(sizeof(Simplex *), compareSimplex);
    TetDel = Tree_Create(sizeof(Simplex *), compareSimplex);

    Tree_Action(v->Simplexes, Recover_Edge);
    Actual_Tree = v->Simplexes;
    Tree_Action(TetAdd, _Add);
    Tree_Action(TetDel, _Del);
    pE1->Liste = NewPoints;
    /*
       if(CTX.mesh.nb_smoothing){
       DEPART = pE1->V[0];
       List_Tri(NewPoints,comparePos);
       for(j=0;j<List_Nbr(NewPoints);j++){
       List_Read(NewPoints,j,&ver1);
       u = (double)(j+1) / (double)(List_Nbr(NewPoints)+1);
       ver1->Pos.X = u * pE1->V[1]->Pos.X + (1.-u) * pE1->V[0]->Pos.X;
       ver1->Pos.Y = u * pE1->V[1]->Pos.Y + (1.-u) * pE1->V[0]->Pos.Y;
       ver1->Pos.Z = u * pE1->V[1]->Pos.Z + (1.-u) * pE1->V[0]->Pos.Z;
       }
       }
     */
    Msg(INFO, "%d/%d: Edge %d->%d => %d division(s)",
        i + 1, List_Nbr(Missing), pE1->V[0]->Num, pE1->V[1]->Num,
        List_Nbr(NewPoints));

    if(!List_Nbr(NewPoints))
      Msg(GERROR,
          "Missing edge without any intersection (%g,%g,%g) (%g,%g,%g)",
          pE1->V[0]->Pos.X, pE1->V[0]->Pos.Y, pE1->V[0]->Pos.Z,
          pE1->V[1]->Pos.X, pE1->V[1]->Pos.Y, pE1->V[1]->Pos.Z);

  }

  Msg(STATUS2, "Boundary faces recovery");
  volume = 0;
  Tree_Action(v->Simplexes, VSIM);
  Msg(INFO, "Volume = %g", volume);

  /* Missing Faces */

  Msg(INFO1, "===================================================");
  Msg(INFO2, "Number of missing faces = %d", List_Nbr(MissingFaces));
  Msg(INFO3, "===================================================");

  for(i = 0; i < List_Nbr(MissingS); i++) {
    List_Read(MissingS, i, &simp);
    TheFace = &simp->F[0];
    Msg(INFO, "%d/%d: Face %d %d %d",
        i + 1, List_Nbr(MissingS), simp->F[0].V[0]->Num,
        simp->F[0].V[1]->Num, simp->F[0].V[2]->Num);
    E.V[0] = simp->F[0].V[0];
    E.V[1] = simp->F[0].V[1];
    pE1 = (Edge *) List_PQuery(Missing, &E, compareEdge);
    E.V[0] = simp->F[0].V[1];
    E.V[1] = simp->F[0].V[2];
    pE2 = (Edge *) List_PQuery(Missing, &E, compareEdge);
    E.V[0] = simp->F[0].V[2];
    E.V[1] = simp->F[0].V[0];
    pE3 = (Edge *) List_PQuery(Missing, &E, compareEdge);

    /* On verifie si c'est simple c a d si les tetraedres
       couvrent entierement la face */
    NewPoints = List_Create(3, 1, sizeof(Vertex *));
    List_Add(NewPoints, &simp->F[0].V[0]);
    if(pE1)
      for(j = 0; j < List_Nbr(pE1->Liste); j++)
        List_Add(NewPoints, List_Pointer(pE1->Liste, j));
    List_Add(NewPoints, &simp->F[0].V[1]);
    if(pE2)
      for(j = 0; j < List_Nbr(pE2->Liste); j++)
        List_Add(NewPoints, List_Pointer(pE2->Liste, j));
    List_Add(NewPoints, &simp->F[0].V[2]);
    if(pE3)
      for(j = 0; j < List_Nbr(pE3->Liste); j++)
        List_Add(NewPoints, List_Pointer(pE3->Liste, j));
    ListFaces = List_Create(2, 2, sizeof(Face));
    Tree_Action(v->Simplexes, findFaces);

    Nh = List_Nbr(NewPoints);

    /* il reste des intersections */

    if(List_Nbr(ListFaces) != Nh - 2) {

      Msg(INFO,
          "Intersections left (the face contains %d initial faces, divided in %d points)",
          List_Nbr(ListFaces), List_Nbr(NewPoints));

      TreexNewv = Tree_Create(sizeof(xNewv), compxNewv);
      TetAdd = Tree_Create(sizeof(Simplex *), compareSimplex);
      TetDel = Tree_Create(sizeof(Simplex *), compareSimplex);
      Tree_Action(v->Simplexes, Recover_Face);

      Msg(INFO,
          "The face is divided in %d points (simplexes added=%d, deleted=%d)",
          List_Nbr(NewPoints), Tree_Nbr(TetAdd), Tree_Nbr(TetDel));

      Actual_Tree = v->Simplexes;
      Tree_Action(TetAdd, _Add);
      Tree_Action(TetDel, _Del);
      ListFaces = List_Create(2, 2, sizeof(Face));
      Tree_Action(v->Simplexes, findFaces);
    }

    Np = List_Nbr(NewPoints);

    if(1 || List_Nbr(ListFaces) == 2 * (Np - 1) - Nh) {

      // provisoire!!!
      if(List_Nbr(ListFaces) != 2 * (Np - 1) - Nh) {
        Msg(WARNING, "*Unrecoverable* face (%d <--> %d=2*(%d-1)-%d)",
            List_Nbr(ListFaces), 2 * (Np - 1) - Nh, Np, Nh);
      }
      else
        Msg(INFO, "Recoverable face (%d <--> %d=2*(%d-1)-%d)",
            List_Nbr(ListFaces), 2 * (Np - 1) - Nh, Np, Nh);

      for(j = 0; j < List_Nbr(v->Surfaces); j++) {
        List_Read(v->Surfaces, j, &s);
        if(Tree_Search(s->Simplexes, &simp)) {
          for(k = 0; k < List_Nbr(ListFaces); k++) {
            List_Read(ListFaces, k, &Face);
            simp1 =
              Create_Simplex_MemeSens(simp, Face.V[0], Face.V[1], Face.V[2]);
            Tree_Add(s->Simplexes, &simp1);
            Tree_Replace(s->Vertices, &Face.V[0]);
            Tree_Replace(s->Vertices, &Face.V[1]);
            Tree_Replace(s->Vertices, &Face.V[2]);
            Tree_Replace(v->Vertices, &Face.V[0]);
            Tree_Replace(v->Vertices, &Face.V[1]);
            Tree_Replace(v->Vertices, &Face.V[2]);
          }
          Tree_Suppress(s->Simplexes, &simp);
        }
      }
    }
    else {
      Msg(GERROR, "*Unrecoverable* face (%d <--> %d=2*(%d-1)-%d)",
          List_Nbr(ListFaces), 2 * (Np - 1) - Nh, Np, Nh);
      for(k = 0; k < List_Nbr(ListFaces); k++) {
        List_Read(ListFaces, k, &Face);
        Msg(STATUS2, "Face %d %d %d", Face.V[0]->Num, Face.V[1]->Num,
            Face.V[2]->Num);
      }
      Tree_Action(v->Simplexes, findEdges);
    }
  }

  volume = 0;
  Tree_Action(v->Simplexes, VSIM);
  Msg(INFO, "Volume after edge/face recovery = %g", volume);

  /* Missing Edges */
  create_Edges(v);
  MissingEdges = Missing_Edges(v);

  /* Missing Faces */
  create_Faces(v);
  MissingFaces = Missing_Faces(v);

  Msg(INFO, "Final check: %d missing edges, %d missing faces",
      List_Nbr(MissingEdges), List_Nbr(MissingFaces));

  Impression_Resultats();

  if(List_Nbr(MissingFaces) || List_Nbr(MissingEdges)) {
    Msg(GERROR, "Could not restore all edges/faces");
    return 0;
  }

  Link_Simplexes(NULL, v->Simplexes);
  Msg(STATUS2, "Volume recovery");
  Restore_Volume(v);

  return 1;
}

/* A partir d'un maillage de volume qui respecte la 
   frontiere, on attribue a chaque tetraedre son 
   numero de volume */

List_T *ListSurfaces, *ListAllSurf;
Tree_T *keep;
Simplex *SIMP;
int iVolume;

void attribueVolume(void *a, void *b)
{
  Simplex *s;
  s = *(Simplex **) a;
  s->iEnt = iVolume;
}

void Trouve_Simplex(void *a, void *b)
{
  Simplex *s;
  if(SIMP != NULL)
    return;
  s = *(Simplex **) a;
  if(s->iEnt < 0)
    SIMP = s;
}

void Trouve_Simplex_Bord(void *a, void *b)
{
  Simplex *s;

  if(SIMP != NULL)
    return;
  s = *(Simplex **) a;
  if(s->V[0]->Num < 0 || s->V[1]->Num < 0 || s->V[2]->Num < 0
     || s->V[3]->Num < 0)
    SIMP = s;
}

void SurfacesDansVolume(Volume * v, List_T * ListAllSurf)
{
  int i, iseg;
  Surface *s;
  for(i = 0; i < List_Nbr(v->Surfaces); i++) {
    List_Read(v->Surfaces, i, &s);
    iseg = abs(s->Num);
    List_Replace(ListAllSurf, &iseg, fcmp_int);
  }
}

int isListaVolume(List_T * ListSurf, Mesh * M)
{
  int NN, i, j, srf;
  bool found;
  Surface *Surf;
  Volume *v;
  List_T *AllVolumes = Tree2List(M->Volumes);

  for(i = 0; i < List_Nbr(AllVolumes); i++) {
    List_Read(AllVolumes, i, &v);
    found = true;
    NN = 0;
    if(v->Typ == MSH_VOLUME) {
      for(j = 0; j < List_Nbr(v->Surfaces); j++) {
        List_Read(v->Surfaces, j, &Surf);
        srf = abs(Surf->Num);
        if(!List_Search(ListSurf, &srf, fcmp_int)) {
          found = false;
        }
        else
          NN++;
      }
      if(found && NN == List_Nbr(ListSurf))
        return v->Num;
    }
  }
  return 0;
}

int compareSimpSurf(const void *a, const void *b)
{
  Simplex *q, *w;
  q = *(Simplex **) a;
  w = *(Simplex **) b;
  return compareFace(&q->F[0], &w->F[0]);
}

List_T *StackSimp;
#define MAX_DEPTH 500

void recur_trouve_volume(Simplex * s, int *Depth)
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
  for(i = 0; i < 4; i++) {
    pS = &S;
    pS->F[0] = s->F[i];
    if(Tree_Query(FacesTree, &pS)
       && List_Search(ListAllSurf, &pS->iEnt, fcmp_int)) {
      j = abs(pS->iEnt);
      List_Replace(ListSurfaces, &j, fcmp_int);
    }
    else if(s->S[i] && s->S[i] != &MyNewBoundary) {
      recur_trouve_volume(s->S[i], Depth);
    }
  }
  (*Depth)--;
}

void Restore_Volume(Volume * v)
{
  int N;
  int j, i, depth;
  Surface *s;

  StackSimp = List_Create(100, 100, sizeof(Simplex *));

  FacesTree = Tree_Create(sizeof(Simplex *), compareSimpSurf);
  Actual_Tree = FacesTree;
  for(j = 0; j < List_Nbr(v->Surfaces); j++) {
    List_Read(v->Surfaces, j, &s);
    Tree_Action(s->Simplexes, _Add);
  }

  ListSurfaces = List_Create(2, 2, sizeof(int));
  iVolume = -1;
  Tree_Action(v->Simplexes, attribueVolume);

  /* Les simplexes sur le bord exterieur sont elimines */

  ListAllSurf = List_Create(10, 3, sizeof(int));
  SurfacesDansVolume(v, ListAllSurf);

  SIMP = NULL;
  Tree_Action(v->Simplexes, Trouve_Simplex_Bord);

  if(SIMP) {
    List_Add(StackSimp, &SIMP);
    keep = Tree_Create(sizeof(Simplex *), compareQuality);
    depth = 0;
    i = 0;
    do {
      List_Read(StackSimp, i, &SIMP);
      recur_trouve_volume(SIMP, &depth);
    } while(++i < List_Nbr(StackSimp));
    List_Reset(StackSimp);

    for(i = 0; i < List_Nbr(ListSurfaces); i++) {
      List_Read(ListSurfaces, i, &j);
      Msg(STATUS2, "Surface %d", j);
    }

    iVolume = 0;
    Tree_Action(keep, attribueVolume);
    Tree_Delete(keep);
    List_Reset(ListSurfaces);
  }

  while(1) {
    SIMP = NULL;
    keep = Tree_Create(sizeof(Simplex *), compareQuality);
    Tree_Action(v->Simplexes, Trouve_Simplex);
    if(!SIMP)
      break;
    List_Add(StackSimp, &SIMP);
    depth = 0;
    i = 0;
    do {
      List_Read(StackSimp, i, &SIMP);
      recur_trouve_volume(SIMP, &depth);
    } while(++i < List_Nbr(StackSimp));

    iVolume = isListaVolume(ListSurfaces, THEM);

    for(i = 0; i < List_Nbr(ListSurfaces); i++) {
      List_Read(ListSurfaces, i, &j);
      Msg(STATUS2, "Surface %d", j);
    }

    N = Tree_Nbr(keep);
    Msg(INFO, "Initial mesh of volume %d: %d simplices", iVolume, N);
    Tree_Action(keep, attribueVolume);
    Tree_Delete(keep);
    List_Reset(ListSurfaces);
    List_Reset(StackSimp);
  }
}
