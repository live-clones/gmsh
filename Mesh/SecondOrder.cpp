// $Id: SecondOrder.cpp,v 1.19 2004-04-18 03:36:07 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "Geo.h"
#include "Mesh.h"
#include "Utils.h"
#include "Interpolation.h"
#include "Numeric.h"

// FIXME: still todo
// - middle edge nodes for hexas, prisms and pyramids
// - middle face nodes for quads, hexas, prisms and pyramids

// we really need to remove the quads from the simplex tree: it's a
// real mess right now (EdgesInVolume makes sense only if we don't try
// to do a 3D mesh with quads on surfaces)

// -> add a Quad tree in Surface (like the Hax/Prism/Pyramid tree in
// Volume); generalize Edge in terms of Element, and dynamic cast to
// Simplex, Quandrangle, Hexahdra, etc.

extern Mesh *THEM;

static Surface *THES;
static Curve *THEC;

Vertex *oncurve(Vertex * v1, Vertex * v2)
{
  Vertex v, *pv;

  if(!THEC)
    return NULL;

  int ok1 = 1, ok2 = 1;
  double u1 = 0., u2 = 0.;

  if(List_Nbr(v1->ListCurves) == 1){
    u1 = v1->u;
  }
  else if(v1->Num == THEC->beg->Num){
    u1 = THEC->ubeg;
  }
  else if(v1->Num == THEC->end->Num){
    u1 = THEC->uend;
  }
  else{
    ok1 = 0;
  }

  if(List_Nbr(v2->ListCurves) == 1){
    u2 = v2->u;
  }
  else if(v2->Num == THEC->beg->Num){
    u2 = THEC->ubeg;
  }
  else if(v2->Num == THEC->end->Num){
    u2 = THEC->uend;
  }
  else{
    ok2 = 0;
  }

  if(ok1 && ok2){
    v = InterpolateCurve(THEC, 0.5 * (u1 + u2), 0);
  }
  else{
    // too bad (should normally not happen)
    v.Pos.X = (v1->Pos.X + v2->Pos.X) * 0.5;
    v.Pos.Y = (v1->Pos.Y + v2->Pos.Y) * 0.5;
    v.Pos.Z = (v1->Pos.Z + v2->Pos.Z) * 0.5;
  }

  pv = Create_Vertex(++THEM->MaxPointNum, v.Pos.X, v.Pos.Y, v.Pos.Z, v.lc, v.u);
  pv->Degree = 2;

  if(!pv->ListCurves) {
    pv->ListCurves = List_Create(1, 1, sizeof(Curve *));
  }
  List_Add(pv->ListCurves, &THEC);
  return pv;
}

Vertex *onsurface(Vertex * v1, Vertex * v2)
{
  Vertex v, *pv;
  double U, V, U1, U2, V1, V2;

  if(!THES)
    return NULL;
  if(THES->Typ == MSH_SURF_PLAN)
    return NULL;

  XYZtoUV(THES, v1->Pos.X, v1->Pos.Y, v1->Pos.Z, &U1, &V1, 1.0);
  XYZtoUV(THES, v2->Pos.X, v2->Pos.Y, v2->Pos.Z, &U2, &V2, 1.0);

  U = 0.5 * (U1 + U2);
  V = 0.5 * (V1 + V2);
  v = InterpolateSurface(THES, U, V, 0, 0);
  pv = Create_Vertex(++THEM->MaxPointNum, v.Pos.X, v.Pos.Y, v.Pos.Z, v.lc, v.u);
  pv->Degree = 2;

  return pv;
}

extern int edges_tetra[6][2];
extern int edges_quad[4][2];
extern int EdgesInVolume;

void PutMiddlePoint(void *a, void *b)
{
  Edge *ed;
  Simplex *s;
  Vertex *v;
  int i, j, k, N;
  int edges[6][2];

  ed = (Edge *) a;

  if(ed->newv){
    v = ed->newv;
  }
  else if((v = oncurve(ed->V[0], ed->V[1]))){
  }
  else if((v = onsurface(ed->V[0], ed->V[1]))){
  }
  else{
    v = Create_Vertex(++THEM->MaxPointNum,
                      0.5 * (ed->V[0]->Pos.X + ed->V[1]->Pos.X),
                      0.5 * (ed->V[0]->Pos.Y + ed->V[1]->Pos.Y),
                      0.5 * (ed->V[0]->Pos.Z + ed->V[1]->Pos.Z),
                      0.5 * (ed->V[0]->lc + ed->V[1]->lc),
                      0.5 * (ed->V[0]->u + ed->V[1]->u));
    v->Degree = 2;
  }

  ed->newv = v;
  Tree_Insert(THEM->Vertices, &v);

  for(i = 0; i < List_Nbr(ed->Simplexes); i++) {
    List_Read(ed->Simplexes, i, &s);
    if(s->V[3] && EdgesInVolume) { // tetrahedron
      if(!s->VSUP)
        s->VSUP = (Vertex **) Malloc(6 * sizeof(Vertex *));
      N = 6;
      for(k = 0; k < N; k++)
        for(j = 0; j < 2; j++)
          edges[k][j] = edges_tetra[k][j];
    }
    else if(s->V[3]) { // quadrangle
      if(!s->VSUP)
        s->VSUP = (Vertex **) Malloc(4 * sizeof(Vertex *));
      N = 4;
      for(k = 0; k < N; k++)
        for(j = 0; j < 2; j++)
          edges[k][j] = edges_quad[k][j];
    }
    else if(s->V[2]) { // triangle
      if(!s->VSUP)
        s->VSUP = (Vertex **) Malloc(3 * sizeof(Vertex *));
      N = 3;
      for(k = 0; k < N; k++)
        for(j = 0; j < 2; j++)
          edges[k][j] = edges_tetra[k][j];
    }
    else { // line
      if(!s->VSUP)
        s->VSUP = (Vertex **) Malloc(sizeof(Vertex *));
      N = 1;
      for(k = 0; k < N; k++)
        for(j = 0; j < 2; j++)
          edges[k][j] = edges_tetra[k][j];
    }

    for(j = 0; j < N; j++) {
      if((!compareVertex(&s->V[edges[j][0]], &ed->V[0]) &&
          !compareVertex(&s->V[edges[j][1]], &ed->V[1])) ||
         (!compareVertex(&s->V[edges[j][0]], &ed->V[1]) &&
          !compareVertex(&s->V[edges[j][1]], &ed->V[0]))) {
        s->VSUP[j] = v;
      }
    }
  }
}

static Tree_T *TreeEdges = NULL;
static List_T *VerticesToDelete = NULL;

void ResetDegre2_Vertex(void *a, void *b)
{
  Vertex *v = *(Vertex**)a;
  if(v->Degree == 2)
    List_Add(VerticesToDelete, &v);
}

void ResetDegre2_Simplex(void *a, void *b)
{
  Simplex *s = *(Simplex**)a;
  Free(s->VSUP);  
  s->VSUP = NULL;
}

void ResetDegre2_Curve(void *a, void *b)
{
  Curve *c = *(Curve**)a;
  if(c->Dirty) return;
  Tree_Action(c->Simplexes, ResetDegre2_Simplex);
}

void ResetDegre2_Surface(void *a, void *b)
{
  Surface *s = *(Surface**)a;
  if(s->Dirty) return;
  Tree_Action(s->Simplexes, ResetDegre2_Simplex);
}

void ResetDegre2_Volume(void *a, void *b)
{
  Volume *v = *(Volume**)a;
  if(v->Dirty) return;
  Tree_Action(v->Simplexes, ResetDegre2_Simplex);
}

void Degre1()
{
  // (re-)initialize the global tree of edges
  if(TreeEdges)
    Tree_Delete(TreeEdges);
  TreeEdges = Tree_Create(sizeof(Edge), compareedge);

  // reset VSUP in each element
  Tree_Action(THEM->Curves, ResetDegre2_Curve);
  Tree_Action(THEM->Surfaces, ResetDegre2_Surface);
  Tree_Action(THEM->Volumes, ResetDegre2_Volume);

  // remove any supp vertex from the database
  if(VerticesToDelete)
    List_Delete(VerticesToDelete);
  VerticesToDelete = List_Create(100, 100, sizeof(Vertex*));
  Tree_Action(THEM->Vertices, ResetDegre2_Vertex);
  for(int i = 0; i < List_Nbr(VerticesToDelete); i++){
    Vertex **v = (Vertex**)List_Pointer(VerticesToDelete, i);
    Tree_Suppress(THEM->Vertices, v);
    Free_Vertex(v, NULL);
  }
}

void Degre2_Curve(void *a, void *b)
{
  Curve *c = *(Curve**)a;
  if(c->Dirty) return;
  THEC = c;
  THES = NULL;
  EdgesInVolume = 0;
  crEdges(c->Simplexes, TreeEdges);
  Tree_Action(TreeEdges, PutMiddlePoint);
}

void Degre2_Surface(void *a, void *b)
{
  Surface *s = *(Surface**)a;
  if(s->Dirty) return;
  THEC = NULL;
  THES = s;
  EdgesInVolume = 0;
  crEdges(s->Simplexes, TreeEdges);
  Tree_Action(TreeEdges, PutMiddlePoint);
}

void Degre2_Volume(void *a, void *b)
{
  Volume *v = *(Volume**)a;
  if(v->Dirty) return;

  // FIXME: warn if we have unhandled elements
  if(Tree_Nbr(v->Hexahedra) || Tree_Nbr(v->Prisms) || Tree_Nbr(v->Pyramids) ||
     THEM->Statistics[8]){
    Msg(GERROR, "Second order hexahedra, prisms and pyramids not supported yet");
    return;
  }

  THEC = NULL;
  THES = NULL;
  EdgesInVolume = 1;
  crEdges(v->Simplexes, TreeEdges);
  Tree_Action(TreeEdges, PutMiddlePoint);
}

void Degre2(int dim)
{
  int old = EdgesInVolume;

  Degre1();
  if(dim >= 1)
    Tree_Action(THEM->Curves, Degre2_Curve);
  if(dim >= 2)
    Tree_Action(THEM->Surfaces, Degre2_Surface);
  if(dim >= 3)
    Tree_Action(THEM->Volumes, Degre2_Volume);

  EdgesInVolume = old;
}

/* new interface
EdgesContainer *edges = NULL;

void Degre2(int dim)
{
  if(edges)
    delete edges;
  edges = new EdgesContainer();
  Degre1();
  if(dim >= 1)
    Tree_Action(THEM->Curves, Degre2_Curve);
  if(dim >= 2)
    Tree_Action(THEM->Surfaces, Degre2_Surface);
  if(dim >= 3)
    Tree_Action(THEM->Volumes, Degre2_Volume);
}
*/
