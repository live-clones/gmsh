// $Id: 3D_Extrude.cpp,v 1.64 2003-03-21 00:52:41 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Context.h"
#include "Create.h"

extern Context_T CTX;
extern Mesh *THEM;

static int DIM, NUM;            // current dimension of parent entity
static int TEST_IS_ALL_OK;
static Tree_T *Tree_Ares = NULL, *Tree_Swaps = NULL;
static Curve *THEC = NULL;
static Surface *THES = NULL;
static Volume *THEV = NULL;
static ExtrudeParams *ep;

// Point_Bound and Vertex_Bound contain the points and vertices on the
// "boundaries". We cannot check for duplicates in THEM->Points and
// THEM->Vertices directly since the comparison function for these
// trees are on the point/vertex numbers, not the position.
static Tree_T *Point_Bound = NULL, *Vertex_Bound = NULL;

typedef struct
{
  int Dim, Num;
  List_T *List;
}
nxl;

static int compnxl(const void *a, const void *b)
{
  int val;
  nxl *q = (nxl *) a, *w = (nxl *) b;

  if((val = q->Dim - w->Dim) != 0)
    return val;
  return q->Num - w->Num;
}

List_T *getnxl(Vertex * v, Curve * c)
{
  nxl NXL;
  NXL.Dim = 1;
  NXL.Num = abs(c->Num);
  nxl *NXLP = (nxl *) List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP)
    return NXLP->List;
  return NULL;
}

List_T *getnxl(Vertex * v, Surface * s)
{
  nxl NXL;
  NXL.Dim = 2;
  NXL.Num = s->Num;
  nxl *NXLP = (nxl *) List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP)
    return NXLP->List;
  return NULL;
}

List_T *getnxl(Vertex * v, Volume * vol)
{
  nxl NXL;
  NXL.Dim = 3;
  NXL.Num = vol->Num;
  nxl *NXLP = (nxl *) List_PQuery(v->Extruded_Points, &NXL, compnxl);
  if(NXLP)
    return NXLP->List;
  return NULL;
}

List_T *getnxl(Vertex * v, int dim)
{
  int i, j;
  Curve *c;
  Surface *s;
  List_T *list;

  // the test on the source entity is in case we extrude a
  // curve/surface resulting from the extrusion of a point/curve...

  if(dim == 1) {
    if((list = getnxl(v, THEC)))
      return list;
  }
  else if(dim == 2) {
    if((list = getnxl(v, THES)))
      return list;
    else {
      for(i = 0; i < List_Nbr(THES->Generatrices); i++) {
        if((abs(ep->geo.Source) != c->Num) && (list = getnxl(v, c)))
          return list;
      }
    }
  }
  else if(dim == 3) {
    if((list = getnxl(v, THEV)))
      return list;
    else {
      for(i = 0; i < List_Nbr(THEV->Surfaces); i++) {
        List_Read(THEV->Surfaces, i, &s);
        if((ep->geo.Source != s->Num) && (list = getnxl(v, s)))
          return list;
      }
      for(i = 0; i < List_Nbr(THEV->Surfaces); i++) {
        List_Read(THEV->Surfaces, i, &s);
        if(ep->geo.Source != s->Num) {
          for(j = 0; j < List_Nbr(s->Generatrices); j++) {
            List_Read(s->Generatrices, j, &c);
            if((list = getnxl(v, c)))
              return list;
          }
        }
      }
    }
  }

  Msg(FATAL, "Could not find extruded list for vertex %d", v->Num);
  return NULL;
}

void Free_ExtrudedPoints(List_T * Extruded_Points)
{
  nxl *NXL;
  for(int i = 0; i < List_Nbr(Extruded_Points); i++) {
    NXL = (nxl *) List_Pointer(Extruded_Points, i);
    List_Delete(NXL->List);
  }
  List_Delete(Extruded_Points);
}

typedef struct
{
  int a, b;
}
nxn;

static int compnxn(const void *a, const void *b)
{
  nxn *q, *w;
  q = (nxn *) a;
  w = (nxn *) b;
  if(q->a > w->a)
    return 1;
  if(q->a < w->a)
    return -1;
  if(q->b > w->b)
    return 1;
  if(q->b < w->b)
    return -1;
  return 0;
}

void InsertInVertexBound(void *a, void *b)
{
  Tree_Insert(Vertex_Bound, a);
}

void InsertInPointBound(void *a, void *b)
{
  Tree_Insert(Point_Bound, a);
}

void InitExtrude()
{
  if(!Tree_Ares)
    Tree_Ares = Tree_Create(sizeof(nxn), compnxn);
  if(!Tree_Swaps)
    Tree_Swaps = Tree_Create(sizeof(nxn), compnxn);

  if(Point_Bound)
    Tree_Delete(Point_Bound);
  Point_Bound = Tree_Create(sizeof(Vertex *), comparePosition);

  if(Vertex_Bound)
    Tree_Delete(Vertex_Bound);
  Vertex_Bound = Tree_Create(sizeof(Vertex *), comparePosition);

  Tree_Action(THEM->Points, InsertInPointBound);
  Tree_Action(THEM->Vertices, InsertInVertexBound);
}

void ExitExtrude()
{
  if(Tree_Ares)
    Tree_Delete(Tree_Ares);
  if(Tree_Swaps)
    Tree_Delete(Tree_Swaps);
  if(Point_Bound)
    Tree_Delete(Point_Bound);
  if(Vertex_Bound)
    Tree_Delete(Vertex_Bound);
  Tree_Ares = Tree_Swaps = Point_Bound = Vertex_Bound = NULL;
}

int are_exist(Vertex * v1, Vertex * v2, Tree_T * t)
{
  nxn n;
  n.a = IMAX(v1->Num, v2->Num);
  n.b = IMIN(v1->Num, v2->Num);
  return Tree_Search(t, &n);
}

void are_cree(Vertex * v1, Vertex * v2, Tree_T * t)
{
  nxn n;
  n.a = IMAX(v1->Num, v2->Num);
  n.b = IMIN(v1->Num, v2->Num);
  Tree_Replace(t, &n);
}

void are_del(Vertex * v1, Vertex * v2, Tree_T * t)
{
  nxn n;
  n.a = IMAX(v1->Num, v2->Num);
  n.b = IMIN(v1->Num, v2->Num);
  Tree_Suppress(t, &n);
}


void Extrude_Simplex_Phase1(void *data, void *dum)
{
  Simplex **pS, *s;
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6;
  List_T *L0, *L1, *L2;

  pS = (Simplex **) data;
  s = *pS;

  L0 = getnxl(s->V[0], DIM);
  L1 = getnxl(s->V[1], DIM);
  L2 = getnxl(s->V[2], DIM);

  k = 0;
  for(i = 0; i < ep->mesh.NbLayer; i++) {
    for(j = 0; j < ep->mesh.NbElmLayer[i]; j++) {
      List_Read(L0, k, &v1);
      List_Read(L1, k, &v2);
      List_Read(L2, k, &v3);
      List_Read(L0, k + 1, &v4);
      List_Read(L1, k + 1, &v5);
      List_Read(L2, k + 1, &v6);
      k++;
      if(!are_exist(v1, v5, Tree_Ares))
        are_cree(v2, v4, Tree_Ares);
      if(!are_exist(v5, v3, Tree_Ares))
        are_cree(v2, v6, Tree_Ares);
      if(!are_exist(v4, v3, Tree_Ares))
        are_cree(v1, v6, Tree_Ares);
    }
  }
}

void Create_HexPri(int iEnt, Vertex * v[8])
{
  int i, j = 0, dup[4];
  Hexahedron *newh;
  Prism *newp;

  if(CTX.mesh.allow_degenerated_extrude) {
    newh = Create_Hexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
    newh->iEnt = iEnt;
    Tree_Add(THEV->Hexahedra, &newh);
    return;
  }

  for(i = 0; i < 4; i++)
    if(v[i]->Num == v[i + 4]->Num)
      dup[j++] = i;

  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      newp = Create_Prism(v[0], v[3], v[7], v[1], v[6], v[2]);
    else if(dup[0] == 1 && dup[1] == 2)
      newp = Create_Prism(v[0], v[1], v[4], v[3], v[2], v[7]);
    else if(dup[0] == 2 && dup[1] == 3)
      newp = Create_Prism(v[0], v[3], v[4], v[1], v[5], v[7]);
    else if(dup[0] == 0 && dup[1] == 3)
      newp = Create_Prism(v[0], v[1], v[5], v[3], v[2], v[6]);
    else {
      Msg(GERROR, "Uncoherent hexahedron  (nodes %d %d %d %d %d %d %d %d)",
          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
      return;
    }
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms, &newp);
  }
  else {
    newh = Create_Hexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
    newh->iEnt = iEnt;
    Tree_Add(THEV->Hexahedra, &newh);
    if(j)
      Msg(GERROR, "Degenerated hexahedron %d (nodes %d %d %d %d %d %d %d %d)",
          newh->Num, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]);
  }
}

void Create_PriPyrTet(int iEnt, Vertex * v[6])
{
  int i, j = 0, dup[3];
  Prism *newp;
  Pyramid *newpyr;
  Simplex *news;

  if(CTX.mesh.allow_degenerated_extrude) {
    newp = Create_Prism(v[0], v[1], v[2], v[3], v[4], v[5]);
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms, &newp);
    return;
  }

  for(i = 0; i < 3; i++)
    if(v[i]->Num == v[i + 3]->Num)
      dup[j++] = i;

  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      news = Create_Simplex(v[0], v[1], v[2], v[5]);
    else if(dup[0] == 1 && dup[1] == 2)
      news = Create_Simplex(v[0], v[1], v[2], v[3]);
    else
      news = Create_Simplex(v[0], v[1], v[2], v[4]);
    news->iEnt = iEnt;
    Tree_Add(THEV->Simplexes, &news);
  }
  else if(j == 1) {
    if(dup[0] == 0)
      newpyr = Create_Pyramid(v[1], v[4], v[5], v[2], v[0]);
    else if(dup[0] == 1)
      newpyr = Create_Pyramid(v[0], v[2], v[5], v[3], v[1]);
    else
      newpyr = Create_Pyramid(v[0], v[1], v[4], v[3], v[2]);
    newpyr->iEnt = iEnt;
    Tree_Add(THEV->Pyramids, &newpyr);
  }
  else {
    newp = Create_Prism(v[0], v[1], v[2], v[3], v[4], v[5]);
    newp->iEnt = iEnt;
    Tree_Add(THEV->Prisms, &newp);
    if(j)
      Msg(GERROR, "Degenerated prism %d (nodes %d %d %d %d %d %d)",
          newp->Num, v[0], v[1], v[2], v[3], v[4], v[5]);
  }

}


void Extrude_Simplex_Phase3(void *data, void *dum)
{
  Simplex **pS, *s, *news;
  int i, j, k;
  Vertex *v[8];
  List_T *L0, *L1, *L2, *L3 = NULL;

  pS = (Simplex **) data;
  s = *pS;

  if(s->V[3] && !ep->mesh.Recombine) {
    Msg(GERROR, "You have to use 'Recombine' to extrude quadrangular meshes");
    return;
  }

  L0 = getnxl(s->V[0], DIM);
  L1 = getnxl(s->V[1], DIM);
  L2 = getnxl(s->V[2], DIM);
  if(s->V[3])
    L3 = getnxl(s->V[3], DIM);

  //printf("orig: %d %d %d %d\n",s->V[0]->Num,s->V[1]->Num,s->V[2]->Num,s->V[3]->Num);

  k = 0;
  for(i = 0; i < ep->mesh.NbLayer; i++) {
    for(j = 0; j < ep->mesh.NbElmLayer[i]; j++) {

      if(s->V[3]) {
        List_Read(L0, k, &v[0]);
        List_Read(L1, k, &v[1]);
        List_Read(L2, k, &v[2]);
        List_Read(L3, k, &v[3]);

        //printf("   1: %d %d %d %d\n",v[0]->Num,v[1]->Num,v[2]->Num,v[3]->Num);

        List_Read(L0, k + 1, &v[4]);
        List_Read(L1, k + 1, &v[5]);
        List_Read(L2, k + 1, &v[6]);
        List_Read(L3, k + 1, &v[7]);

        //printf("   2: %d %d %d %d\n",v[4]->Num,v[5]->Num,v[6]->Num,v[7]->Num);

      }
      else {
        List_Read(L0, k, &v[0]);
        List_Read(L1, k, &v[1]);
        List_Read(L2, k, &v[2]);
        List_Read(L0, k + 1, &v[3]);
        List_Read(L1, k + 1, &v[4]);
        List_Read(L2, k + 1, &v[5]);
      }

      k++;
      if(ep->mesh.ZonLayer[i]) {

        if(ep->mesh.Recombine) {
          if(s->V[3])
            Create_HexPri(ep->mesh.ZonLayer[i], v);
          else
            Create_PriPyrTet(ep->mesh.ZonLayer[i], v);
        }
        else {

          if(are_exist(v[3], v[1], Tree_Ares) &&
             are_exist(v[4], v[2], Tree_Ares) &&
             are_exist(v[3], v[2], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[3]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[1], v[3], v[4], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
          if(are_exist(v[3], v[1], Tree_Ares) &&
             are_exist(v[1], v[5], Tree_Ares) &&
             are_exist(v[3], v[2], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[3]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[1]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[1], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
          if(are_exist(v[3], v[1], Tree_Ares) &&
             are_exist(v[1], v[5], Tree_Ares) &&
             are_exist(v[5], v[0], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[1]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[1], v[3], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
          if(are_exist(v[4], v[0], Tree_Ares) &&
             are_exist(v[4], v[2], Tree_Ares) &&
             are_exist(v[3], v[2], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[4]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[0], v[3], v[4], v[2]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
          if(are_exist(v[4], v[0], Tree_Ares) &&
             are_exist(v[4], v[2], Tree_Ares) &&
             are_exist(v[5], v[0], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[4]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[0], v[2], v[4], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
          if(are_exist(v[4], v[0], Tree_Ares) &&
             are_exist(v[1], v[5], Tree_Ares) &&
             are_exist(v[5], v[0], Tree_Ares)) {
            news = Create_Simplex(v[0], v[1], v[2], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[3], v[4], v[5], v[0]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
            news = Create_Simplex(v[0], v[1], v[4], v[5]);
            news->iEnt = ep->mesh.ZonLayer[i];
            Tree_Add(THEV->Simplexes, &news);
          }
        }
      }
    }
  }
}

void Extrude_Simplex_Phase2(void *data, void *dum)
{
  Simplex **pS, *s;
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4, *v5, *v6;
  List_T *L0, *L1, *L2;

  pS = (Simplex **) data;
  s = *pS;

  L0 = getnxl(s->V[0], DIM);
  L1 = getnxl(s->V[1], DIM);
  L2 = getnxl(s->V[2], DIM);

  k = 0;
  for(i = 0; i < ep->mesh.NbLayer; i++) {
    for(j = 0; j < ep->mesh.NbElmLayer[i]; j++) {
      List_Read(L0, k, &v1);
      List_Read(L1, k, &v2);
      List_Read(L2, k, &v3);
      List_Read(L0, k + 1, &v4);
      List_Read(L1, k + 1, &v5);
      List_Read(L2, k + 1, &v6);
      k++;
      //if((double)rand()/(double)RAND_MAX < 0.1) break;
      if(are_exist(v4, v2, Tree_Ares) &&
         are_exist(v5, v3, Tree_Ares) && are_exist(v1, v6, Tree_Ares)) {
        TEST_IS_ALL_OK++;
        if(!are_exist(v4, v2, Tree_Swaps)) {
          are_del(v4, v2, Tree_Ares);
          are_cree(v1, v5, Tree_Ares);
          are_cree(v1, v5, Tree_Swaps);
          are_cree(v4, v2, Tree_Swaps);
        }
        else if(!are_exist(v5, v3, Tree_Swaps)) {
          are_del(v5, v3, Tree_Ares);
          are_cree(v2, v6, Tree_Ares);
          are_cree(v5, v3, Tree_Swaps);
          are_cree(v2, v6, Tree_Swaps);
        }
        else if(!are_exist(v1, v6, Tree_Swaps)) {
          are_del(v1, v6, Tree_Ares);
          are_cree(v4, v3, Tree_Ares);
          are_cree(v1, v6, Tree_Swaps);
          are_cree(v4, v3, Tree_Swaps);
        }
      }
      else if(are_exist(v1, v5, Tree_Ares) &&
              are_exist(v2, v6, Tree_Ares) && are_exist(v4, v3, Tree_Ares)) {
        TEST_IS_ALL_OK++;
        if(!are_exist(v1, v5, Tree_Swaps)) {
          are_del(v1, v5, Tree_Ares);
          are_cree(v4, v2, Tree_Ares);
          are_cree(v1, v5, Tree_Swaps);
          are_cree(v4, v2, Tree_Swaps);
        }
        else if(!are_exist(v2, v6, Tree_Swaps)) {
          are_del(v2, v6, Tree_Ares);
          are_cree(v5, v3, Tree_Ares);
          are_cree(v5, v3, Tree_Swaps);
          are_cree(v2, v6, Tree_Swaps);
        }
        else if(!are_exist(v4, v3, Tree_Swaps)) {
          are_del(v4, v3, Tree_Ares);
          are_cree(v1, v6, Tree_Ares);
          are_cree(v1, v6, Tree_Swaps);
          are_cree(v4, v3, Tree_Swaps);
        }
      }
    }
  }
}


void Extrude_Vertex(void *data, void *dum)
{
  Vertex **vexist, *v, *newv;
  int i, j;
  nxl NXL;

  v = *((Vertex **) data);

  if(!v->Extruded_Points)
    v->Extruded_Points = List_Create(1, 1, sizeof(nxl));

  NXL.Num = NUM;
  NXL.Dim = DIM;
  if(List_Search(v->Extruded_Points, &NXL, compnxl))
    return;
  else
    NXL.List = List_Create(ep->mesh.NbLayer, 1, sizeof(Vertex *));

  List_Add(NXL.List, &v);

  for(i = 0; i < ep->mesh.NbLayer; i++) {
    for(j = 0; j < ep->mesh.NbElmLayer[i]; j++) {
      newv = Create_Vertex(++THEM->MaxPointNum, v->Pos.X,
                           v->Pos.Y, v->Pos.Z, v->lc, v->u);
      ep->Extrude(i, j + 1, newv->Pos.X, newv->Pos.Y, newv->Pos.Z);
      if(Vertex_Bound && (vexist = (Vertex **) Tree_PQuery(Vertex_Bound, &newv))) {
        Free_Vertex(&newv, 0);
        List_Add(NXL.List, vexist);
      }
      else{
	if(Point_Bound && (vexist = (Vertex **) Tree_PQuery(Point_Bound, &newv))) {
	  // keep the new one: we cannot have points and vertices
	  // pointing to the same memory location
	  newv->Num = (*vexist)->Num;
	}
        List_Add(NXL.List, &newv);
        Tree_Add(THEM->Vertices, &newv);
        Tree_Insert(Vertex_Bound, &newv);
      }
    }
  }

  List_Add(v->Extruded_Points, &NXL);
}

void Extrude_Surface1(Surface * s)
{
  THES = s;
  Tree_Action(s->Vertices, Extrude_Vertex);
  if(!ep->mesh.Recombine)
    Tree_Action(s->Simplexes, Extrude_Simplex_Phase1);
}

void Extrude_Surface2(Surface * s)
{
  THES = s;
  Tree_Action(s->Simplexes, Extrude_Simplex_Phase2);
}

void Extrude_Surface3(Surface * s)
{
  THES = s;
  Tree_Action(s->Simplexes, Extrude_Simplex_Phase3);
}


void Create_Tri(Vertex * v1, Vertex * v2, Vertex * v3)
{
  Simplex *s;
  if(CTX.mesh.allow_degenerated_extrude ||
     (v1->Num != v2->Num && v1->Num != v3->Num && v2->Num != v3->Num)) {
    s = Create_Simplex(v1, v2, v3, NULL);
    s->iEnt = THES->Num;
    s->Num = -s->Num;   //Tag triangles to re-extrude
    Tree_Add(THES->Simplexes, &s);
  }
}

void Extrude_Seg(Vertex * V1, Vertex * V2)
{
  int i, j, k;
  Vertex *v1, *v2, *v3, *v4;
  Simplex *s;
  List_T *L1, *L2;

  L1 = getnxl(V1, DIM);
  L2 = getnxl(V2, DIM);

  k = 0;
  for(i = 0; i < ep->mesh.NbLayer; i++) {
    for(j = 0; j < ep->mesh.NbElmLayer[i]; j++) {
      List_Read(L1, k, &v1);
      List_Read(L2, k, &v2);
      List_Read(L1, k + 1, &v3);
      List_Read(L2, k + 1, &v4);
      if(ep->mesh.Recombine) {
        if(CTX.mesh.allow_degenerated_extrude)
          s = Create_Quadrangle(v1, v2, v4, v3);
        else if(v1->Num == v2->Num || v2->Num == v4->Num)
          s = Create_Simplex(v1, v4, v3, NULL);
        else if(v1->Num == v3->Num || v3->Num == v4->Num)
          s = Create_Simplex(v1, v2, v4, NULL);
        else if(v1->Num == v4->Num || v2->Num == v3->Num) {
          Msg(GERROR, "Uncoherent quadrangle  (nodes %d %d %d %d)",
              v1->Num, v2->Num, v3->Num, v4->Num);
          return;
        }
        else
          s = Create_Quadrangle(v1, v2, v4, v3);
        s->iEnt = THES->Num;
        s->Num = -s->Num;       //Tag quadrangles to re-extrude
        Tree_Add(THES->Simplexes, &s);

        // This is horrible
        THEM->Statistics[8] += 1;
      }
      else {
        if(are_exist(v3, v2, Tree_Ares)) {
          Create_Tri(v3, v2, v1);
          Create_Tri(v3, v4, v2);
        }
        else {
          Create_Tri(v3, v4, v1);
          Create_Tri(v1, v4, v2);
        }
      }
      k++;
    }
  }

}

void Extrude_Curve(void *data, void *dum)
{
  Curve **pC, *c;
  Vertex *v1, *v2;
  int i;
  pC = (Curve **) data;
  c = *pC;

  //if (c->Num < 0) return;

  for(i = 0; i < List_Nbr(c->Vertices) - 1; i++) {
    List_Read(c->Vertices, i, &v1);
    List_Read(c->Vertices, i + 1, &v2);
    Extrude_Seg(v1, v2);
  }
}

void copy_mesh(Curve * from, Curve * to, int direction)
{
  List_T *list = from->Vertices;
  Vertex **vexist, *v, *newv;

  int nb = List_Nbr(to->Vertices);
  if(nb) {
    if(nb != List_Nbr(from->Vertices))
      Msg(GERROR, "Incompatible extrusion of curve %d into curve %d",
          from->Num, to->Num);
    return;
  }

  to->Vertices = List_Create(List_Nbr(from->Vertices), 2, sizeof(Vertex *));

  v = to->beg;
  if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &v))) {
    (*vexist)->u = to->ubeg;
    if((*vexist)->ListCurves)
      List_Add((*vexist)->ListCurves, &to);
    List_Add(to->Vertices, vexist);
  }
  else {
    newv = Create_Vertex(v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->lc, to->ubeg);
    Tree_Add(THEM->Vertices, &newv);
    newv->ListCurves = List_Create(1, 1, sizeof(Curve *));
    List_Add(newv->ListCurves, &to);
    List_Add(to->Vertices, &newv);
  }

  for(int i = 1; i < List_Nbr(list) - 1; i++) {
    if(direction < 0)
      List_Read(list, List_Nbr(list) - 1 - i, &v);
    else
      List_Read(list, i, &v);
    newv = Create_Vertex(++THEM->MaxPointNum, v->Pos.X,
			 v->Pos.Y, v->Pos.Z, v->lc,
			 (direction > 0) ? v->u : (1. - v->u));
    ep->Extrude(ep->mesh.NbLayer - 1,
                ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], newv->Pos.X,
                newv->Pos.Y, newv->Pos.Z);
    if(!comparePosition(&newv, &v)) {
      Free_Vertex(&newv, 0);
      newv = v;
    }
    else if(Vertex_Bound && (vexist = (Vertex **) Tree_PQuery(Vertex_Bound, &newv))) {
      Free_Vertex(&newv, 0);
      newv = *vexist;
    }
    else {
      if(Point_Bound && (vexist = (Vertex **) Tree_PQuery(Point_Bound, &newv))) {
	// keep the new one: we cannot have points and vertices
	// pointing to the same memory location
	newv->Num = (*vexist)->Num;
      }
      Tree_Add(THEM->Vertices, &newv);
      Tree_Insert(Vertex_Bound, &newv);
    }
    if(!newv->ListCurves)
      newv->ListCurves = List_Create(1, 1, sizeof(Curve *));
    List_Add(newv->ListCurves, &to);
    List_Add(to->Vertices, &newv);
  }

  v = to->end;
  if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &v))) {
    (*vexist)->u = to->uend;
    if((*vexist)->ListCurves)
      List_Add((*vexist)->ListCurves, &to);
    List_Add(to->Vertices, vexist);
  }
  else {
    newv = Create_Vertex(v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->lc, to->uend);
    Tree_Add(THEM->Vertices, &newv);
    newv->ListCurves = List_Create(1, 1, sizeof(Curve *));
    List_Add(newv->ListCurves, &to);
    List_Add(to->Vertices, &newv);
  }

}

int Extrude_Mesh(Curve * c)
{
  int i;
  Vertex **vexist, *v, *newv;
  List_T *L;

  if(!c->Extrude || !c->Extrude->mesh.ExtrudeMesh)
    return false;

  InitExtrude();
  THEC = c;
  DIM = 1;
  NUM = c->Num;
  ep = c->Extrude;

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    Extrude_Vertex(&c->beg, NULL);
    L = getnxl(c->beg, DIM);
    c->Vertices = List_Create(List_Nbr(L), 2, sizeof(Vertex *));

    v = c->beg;
    if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &v))) {
      (*vexist)->u = c->ubeg;
      if((*vexist)->ListCurves)
        List_Add((*vexist)->ListCurves, &c);
      List_Add(c->Vertices, vexist);
    }
    else {
      newv = Create_Vertex(v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->lc, 0.0);
      newv->ListCurves = List_Create(1, 1, sizeof(Curve *));
      List_Add(newv->ListCurves, &c);
      Tree_Add(THEM->Vertices, &newv);
      List_Add(c->Vertices, &newv);
    }

    for(i = 1; i < List_Nbr(L) - 1; i++) {
      List_Read(L, i, &v);
      if(!v->ListCurves)
        v->ListCurves = List_Create(1, 1, sizeof(Curve *));
      List_Add(v->ListCurves, &c);
      Tree_Insert(THEM->Vertices, &v);
      v->u = (double)i / (double)List_Nbr(L);
      List_Add(c->Vertices, &v);
    }

    v = c->end;
    if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, &v))) {
      (*vexist)->u = c->uend;
      if((*vexist)->ListCurves)
        List_Add((*vexist)->ListCurves, &c);
      List_Add(c->Vertices, vexist);
    }
    else {
      newv = Create_Vertex(v->Num, v->Pos.X, v->Pos.Y, v->Pos.Z, v->lc, 0.0);
      newv->ListCurves = List_Create(1, 1, sizeof(Curve *));
      List_Add(newv->ListCurves, &c);
      Tree_Add(THEM->Vertices, &newv);
      List_Add(c->Vertices, &newv);
    }
    return true;
  }
  else {
    Curve *cc = FindCurve(abs(ep->geo.Source), THEM);
    if(!cc)
      return false;
    copy_mesh(cc, c, sign(ep->geo.Source));
    return true;
  }
}

void copy_mesh(Surface * from, Surface * to)
{
  List_T *list = Tree2List(from->Simplexes);
  Simplex *s, *news;
  Vertex **vexist, *v, *newv[4];

  int nb = Tree_Nbr(to->Simplexes);
  if(nb) {
    if(nb != Tree_Nbr(from->Simplexes))
      Msg(GERROR, "Incompatible extrusion of surface %d into surface %d",
          from->Num, to->Num);
    return;
  }

  for(int i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &s);
    for(int j = 0; j < 4; j++) {
      if(s->V[j]) {
        v = s->V[j];
        newv[j] = Create_Vertex(++THEM->MaxPointNum, v->Pos.X,
				v->Pos.Y, v->Pos.Z, v->lc, v->u);
        ep->Extrude(ep->mesh.NbLayer - 1,
                    ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], newv[j]->Pos.X,
                    newv[j]->Pos.Y, newv[j]->Pos.Z);
        if(Vertex_Bound && (vexist = (Vertex **) Tree_PQuery(Vertex_Bound, &newv[j]))) {
          Free_Vertex(&newv[j], 0);
          newv[j] = *vexist;
        }
        else {
	  if(Point_Bound && (vexist = (Vertex **) Tree_PQuery(Point_Bound, &newv[j]))) {
	    // keep the new one: we cannot have points and vertices
	    // pointing to the same memory location
	    newv[j]->Num = (*vexist)->Num;
	  }
          Tree_Add(THEM->Vertices, &newv[j]);
          Tree_Insert(Vertex_Bound, &newv[j]);
        }
      }
      else {
        newv[j] = NULL;
      }
    }
    if(newv[3]) {
      news = Create_Quadrangle(newv[0], newv[1], newv[2], newv[3]);
      // This is horrible
      THEM->Statistics[8] += 1;
    }
    else
      news = Create_Simplex(newv[0], newv[1], newv[2], NULL);
    news->iEnt = to->Num;
    Tree_Add(to->Simplexes, &news);
  }
  List_Delete(list);
}

void AddVertsInSurf(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  for(int i = 0; i < 4; i++)
    if(s->V[i])
      Tree_Insert(THES->Vertices, &s->V[i]);
}

int Extrude_Mesh(Surface * s)
{
  int i;
  Vertex *v1;
  Curve *c;
  extern int FACE_DIMENSION;

  if(!s->Extrude || !s->Extrude->mesh.ExtrudeMesh)
    return false;

  InitExtrude();
  THES = s;
  DIM = 2;
  NUM = s->Num;
  ep = s->Extrude;
  FACE_DIMENSION = 2;

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    c = FindCurve(abs(ep->geo.Source), THEM);
    if(!c)
      return false;
    for(i = 0; i < List_Nbr(c->Vertices); i++) {
      List_Read(c->Vertices, i, &v1);
      Extrude_Vertex(&v1, NULL);
    }
    Extrude_Curve(&c, NULL);
  }
  else {
    Surface *ss = FindSurface(ep->geo.Source, THEM);
    if(!ss)
      return false;
    copy_mesh(ss, s);
  }

  Tree_Action(s->Simplexes, AddVertsInSurf);

  return true;
}

static Tree_T *tmp;

void Free_NegativeSimplex(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  if(s) {
    if(s->Num >= 0) {
      Tree_Add(tmp, &s);
    }
    else {
      delete s;
      s = NULL;
    }
  }
}

int Extrude_Mesh(Volume * v)
{
  ep = v->Extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY)
    return true;
  else
    return false;
}

int Extrude_Mesh(Tree_T * Volumes)
{
  int i, j, extrude = 0;
  Surface *s;
  List_T *list;

  InitExtrude();
  DIM = 3;

  List_T *vol = Tree2List(Volumes);

  for(int ivol = 0; ivol < List_Nbr(vol); ivol++) {
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY)
      extrude = 1;
  }
  if(!extrude)
    return false;

  Msg(STATUS2, "Mesh 3D... (initial)");

  for(int ivol = 0; ivol < List_Nbr(vol); ivol++) {
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    NUM = THEV->Num;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) {
      s = FindSurface(ep->geo.Source, THEM);
      if(s) {
        Msg(STATUS3, "Meshing Volume %d", NUM);
        Extrude_Surface1(s);
      }
    }
  }

  j = 0;
  do {
    TEST_IS_ALL_OK = 0;
    for(int ivol = 0; ivol < List_Nbr(vol); ivol++) {
      List_Read(vol, ivol, &THEV);
      ep = THEV->Extrude;
      NUM = THEV->Num;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY &&
         !ep->mesh.Recombine) {
        s = FindSurface(ep->geo.Source, THEM);
        if(s)
          Extrude_Surface2(s);
      }
    }
    Msg(STATUS3, "Swapping %d", TEST_IS_ALL_OK);
    if(TEST_IS_ALL_OK == j) {
      if(j)
        Msg(GERROR, "Unable to swap all edges: try Recombine...");
      break;
    }
    j = TEST_IS_ALL_OK;
  } while(TEST_IS_ALL_OK);

  Msg(STATUS2, "Mesh 3D... (Final)");

  for(int ivol = 0; ivol < List_Nbr(vol); ivol++) {
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    NUM = THEV->Num;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) {
      s = FindSurface(ep->geo.Source, THEM);
      if(s) {
        Msg(STATUS3, "Meshing Volume %d", NUM);
        Extrude_Surface3(s);
      }
    }
  }

  list = List_Create(100, 100, sizeof(Surface *));
  for(int ivol = 0; ivol < List_Nbr(vol); ivol++) {
    List_Read(vol, ivol, &THEV);
    ep = THEV->Extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY &&
       !ep->mesh.Recombine) {
      for(i = 0; i < List_Nbr(THEV->Surfaces); i++) {
        List_Read(THEV->Surfaces, i, &s);
        if(!List_Search(list, &s, compareSurface))
          List_Add(list, &s);
      }
    }
  }
  for(i = 0; i < List_Nbr(list); i++) {
    List_Read(list, i, &s);
    tmp = Tree_Create(sizeof(Simplex *), compareQuality);
    Tree_Action(s->Simplexes, Free_NegativeSimplex);
    Tree_Delete(s->Simplexes);
    s->Simplexes = tmp;
    Msg(STATUS3, "Coherence Surface %d", s->Num);
    Extrude_Mesh(s);
  }

  List_Delete(list);
  List_Delete(vol);

  return true;

}
