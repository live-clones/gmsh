// $Id: SecondOrder.cpp,v 1.15 2003-06-13 22:41:41 geuzaine Exp $
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
#include "Geo.h"
#include "Mesh.h"
#include "Utils.h"
#include "Interpolation.h"
#include "Numeric.h"

extern Mesh *THEM;

static Surface *THES;
static Curve *THEC;

Vertex *middlecurve(Vertex * v1, Vertex * v2)
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

  if(!pv->ListCurves) {
    pv->ListCurves = List_Create(1, 1, sizeof(Curve *));
  }
  List_Add(pv->ListCurves, &THEC);
  return pv;
}

Vertex *middleface(Vertex * v1, Vertex * v2)
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
  return pv;
}

extern int edges_tetra[6][2];
extern int edges_quad[4][2];
static Tree_T *THET;
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
  else if((v = middlecurve(ed->V[0], ed->V[1]))){
    ;
  }
  else if((v = middleface(ed->V[0], ed->V[1]))){
    ;
  }
  else{
    v = Create_Vertex(++THEM->MaxPointNum,
                      0.5 * (ed->V[0]->Pos.X + ed->V[1]->Pos.X),
                      0.5 * (ed->V[0]->Pos.Y + ed->V[1]->Pos.Y),
                      0.5 * (ed->V[0]->Pos.Z + ed->V[1]->Pos.Z),
                      0.5 * (ed->V[0]->lc + ed->V[1]->lc),
                      0.5 * (ed->V[0]->u + ed->V[1]->u));
  }

  ed->newv = v;
  Tree_Insert(THET, &v);

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

void Reset_Degre2(){
  if(TreeEdges){
    Tree_Delete(TreeEdges);
  }
  TreeEdges = Tree_Create(sizeof(Edge), compareedge);
}

void Degre2(Tree_T * AllNodes, Tree_T * TreeNodes, Tree_T * TreeElm,
            Curve * c, Surface * s)
{
  THES = s;
  THEC = c;
  THET = TreeNodes;

  if(THES || THEC){
    EdgesInVolume = 0;
  }

  crEdges(TreeElm, TreeEdges);
  Tree_Action(TreeEdges, PutMiddlePoint);

  EdgesInVolume = 1;
}
