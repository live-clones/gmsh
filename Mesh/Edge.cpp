// $Id: Edge.cpp,v 1.19 2005-01-01 19:35:30 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Mesh.h"
#include "Edge.h"
#include "Tools.h"

int edges_tetra[6][2] = {
  {0, 1},
  {1, 2},
  {2, 0},
  {3, 0},
  {3, 2},
  {3, 1}
};

int edges_quad[4][2] = {
  {0, 1},
  {1, 2},
  {2, 3},
  {3, 0}
};

int edges_hexa[12][2] = {
  {0, 1},
  {0, 3},
  {0, 4},
  {1, 2},
  {1, 5},
  {2, 3},
  {2, 6},
  {3, 7},
  {4, 5},
  {4, 7},
  {5, 6},
  {6, 7}
};

int edges_prism[9][2] = {
  {0, 1},
  {0, 2},
  {0, 3},
  {1, 2},
  {1, 4},
  {2, 5},
  {3, 4},
  {3, 5},
  {4, 5}
};

int edges_pyramid[8][2] = {
  {0, 1},
  {0, 3},
  {0, 4},
  {1, 2},
  {1, 4},
  {2, 3},
  {2, 4},
  {3, 4}
};

int edges_non[3] = { 2, 0, 1 };

int compareEdge(const void *a, const void *b)
{
  Edge *q = (Edge *) a;
  Edge *w = (Edge *) b;
  int i1 = IMAX(q->V[0]->Num, q->V[1]->Num);
  int i2 = IMAX(w->V[0]->Num, w->V[1]->Num);
  int j1 = IMIN(q->V[0]->Num, q->V[1]->Num);
  int j2 = IMIN(w->V[0]->Num, w->V[1]->Num);

  if(i1 < i2)
    return (1);
  if(i1 > i2)
    return (-1);
  if(j1 < j2)
    return (1);
  if(j1 > j2)
    return (-1);
  return 0;
}

int compareEdgePtr(const void *a, const void *b)
{
  Edge *q = *(Edge **) a;
  Edge *w = *(Edge **) b;

  return compareEdge(q, w);
}

int compareEdgeAngle(const void *a, const void *b)
{
  Edge *q = (Edge *) a;
  Edge *w = (Edge *) b;
  if(q->a >= w->a)
    return (1);
  return (-1);
}

void EdgesContainer::AddEdges(Simplex * s)
{
  int N, i;
  Edge E, *pE;

  if(s->V[3])
    N = 6;
  else if(s->V[2])
    N = 3;
  else
    N = 1;

  for(i = 0; i < N; i++) {
    E.V[0] = s->V[edges_tetra[i][0]];
    E.V[1] = s->V[edges_tetra[i][1]];
    if((pE = (Edge *) Tree_PQuery(AllEdges, &E))) {
      if(!pE->Simplexes) // the edge could belong to a non-simplex
	pE->Simplexes = List_Create(2, 1, sizeof(Simplex *));
      List_Add(pE->Simplexes, &s);
      if(N == 3)
        pE->O[1] = s->V[edges_non[i]];
    }
    else {
      E.Simplexes = List_Create(2, 1, sizeof(Simplex *));
      if(N == 3){
        E.O[0] = s->V[edges_non[i]];
        E.O[1] = NULL;
      }
      List_Add(E.Simplexes, &s);
      E.newv = NULL;
      Tree_Add(AllEdges, &E);
    }
  }
}

void EdgesContainer::AddEdges(Quadrangle * q)
{
  Edge E, *pE;

  for(int i = 0; i < 4; i++) {
    E.V[0] = q->V[edges_quad[i][0]];
    E.V[1] = q->V[edges_quad[i][1]];
    if((pE = (Edge *) Tree_PQuery(AllEdges, &E))) {
      if(!pE->Quadrangles) // the edge could belong to a non-quad
	pE->Quadrangles = List_Create(2, 1, sizeof(Quadrangle *));
      List_Add(pE->Quadrangles, &q);
    }
    else {
      E.Quadrangles = List_Create(2, 1, sizeof(Quadrangle *));
      List_Add(E.Quadrangles, &q);
      E.newv = NULL;
      Tree_Add(AllEdges, &E);
    }
  }
}

void EdgesContainer::AddEdges(Hexahedron * h)
{
  Edge E, *pE;

  for(int i = 0; i < 12; i++) {
    E.V[0] = h->V[edges_hexa[i][0]];
    E.V[1] = h->V[edges_hexa[i][1]];
    if((pE = (Edge *) Tree_PQuery(AllEdges, &E))) {
      if(!pE->Hexahedra) // the edge could belong to a non-hexa
	pE->Hexahedra = List_Create(2, 1, sizeof(Hexahedron *));
      List_Add(pE->Hexahedra, &h);
    }
    else {
      E.Hexahedra = List_Create(2, 1, sizeof(Hexahedron *));
      List_Add(E.Hexahedra, &h);
      E.newv = NULL;
      Tree_Add(AllEdges, &E);
    }
  }
}

void EdgesContainer::AddEdges(Prism * p)
{
  Edge E, *pE;

  for(int i = 0; i < 9; i++) {
    E.V[0] = p->V[edges_prism[i][0]];
    E.V[1] = p->V[edges_prism[i][1]];
    if((pE = (Edge *) Tree_PQuery(AllEdges, &E))) {
      if(!pE->Prisms) // the edge could belong to a non-prism
	pE->Prisms = List_Create(2, 1, sizeof(Prism *));
      List_Add(pE->Prisms, &p);
    }
    else {
      E.Prisms = List_Create(2, 1, sizeof(Prism *));
      List_Add(E.Prisms, &p);
      E.newv = NULL;
      Tree_Add(AllEdges, &E);
    }
  }
}

void EdgesContainer::AddEdges(Pyramid * p)
{
  Edge E, *pE;

  for(int i = 0; i < 8; i++) {
    E.V[0] = p->V[edges_pyramid[i][0]];
    E.V[1] = p->V[edges_pyramid[i][1]];
    if((pE = (Edge *) Tree_PQuery(AllEdges, &E))) {
      if(!pE->Pyramids) // the edge could belong to a non-pyramid
	pE->Pyramids = List_Create(2, 1, sizeof(Pyramid *));
      List_Add(pE->Pyramids, &p);
    }
    else {
      E.Pyramids = List_Create(2, 1, sizeof(Pyramid *));
      List_Add(E.Pyramids, &p);
      E.newv = NULL;
      Tree_Add(AllEdges, &E);
    }
  }
}

EdgesContainer::EdgesContainer(Tree_T * Simplexes)
{
  AllEdges = Tree_Create(sizeof(Edge), compareEdge);
  AddSimplexTree(Simplexes);
}

EdgesContainer::EdgesContainer(List_T * Surfaces)
{
  AllEdges = Tree_Create(sizeof(Edge), compareEdge);
  Surface *s;
  for(int i = 0; i < List_Nbr(Surfaces); i++) {
    List_Read(Surfaces, i, &s);
    AddSimplexTree(s->Simplexes);
  }
}

EdgesContainer::EdgesContainer()
{
  AllEdges = Tree_Create(sizeof(Edge), compareEdge);
}

void EdgesContainer::AddSimplexTree(Tree_T * Simplexes)
{
  Simplex *s;
  List_T *temp = Tree2List(Simplexes);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &s);
    AddEdges(s);
  }
  List_Delete(temp);
}

void EdgesContainer::AddQuadrangleTree(Tree_T * Quadrangles)
{
  Quadrangle *q;
  List_T *temp = Tree2List(Quadrangles);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &q);
    AddEdges(q);
  }
  List_Delete(temp);
}

void EdgesContainer::AddHexahedronTree(Tree_T * Hexahedra)
{
  Hexahedron *h;
  List_T *temp = Tree2List(Hexahedra);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &h);
    AddEdges(h);
  }
  List_Delete(temp);
}

void EdgesContainer::AddPrismTree(Tree_T * Prisms)
{
  Prism *p;
  List_T *temp = Tree2List(Prisms);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &p);
    AddEdges(p);
  }
  List_Delete(temp);
}

void EdgesContainer::AddPyramidTree(Tree_T * Pyramids)
{
  Pyramid *p;
  List_T *temp = Tree2List(Pyramids);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &p);
    AddEdges(p);
  }
  List_Delete(temp);
}

void Free_Edge(void *a, void *b)
{
  Edge *e = (Edge *) a;
  List_Delete(e->Liste);
  List_Delete(e->Simplexes);
  List_Delete(e->Quadrangles);
  List_Delete(e->Hexahedra);
  List_Delete(e->Prisms);
  List_Delete(e->Pyramids);
  List_Delete(e->Points);
}

EdgesContainer::~EdgesContainer()
{
  Tree_Action(AllEdges, Free_Edge);
  Tree_Delete(AllEdges);
}

bool EdgesContainer::Search(Vertex * v1, Vertex * v2)
{
  Edge E;
  E.V[0] = v1;
  E.V[1] = v2;
  if(!Tree_Search(AllEdges, &E))
    return false;
  return true;
}

void EdgesContainer::Print()
{
  List_T *temp = Tree2List(AllEdges);
  printf("Print Edges START\n");
  for(int i = 0; i < List_Nbr(temp); i++) {
    Edge *e = (Edge*)List_Pointer(temp, i);
    printf("edge %d -> %d", e->V[0]->Num, e->V[1]->Num);
    if(List_Nbr(e->Simplexes)){
      printf(", in simplex");
      for(int j = 0; j < List_Nbr(e->Simplexes); j++){
	Simplex *s = *(Simplex**)List_Pointer(e->Simplexes, j);
	printf(" %d", s->Num);
      }
    }
    if(List_Nbr(e->Quadrangles)){
      printf(", in quad");
      for(int j = 0; j < List_Nbr(e->Quadrangles); j++){
	Quadrangle *q = *(Quadrangle**)List_Pointer(e->Quadrangles, j);
	printf(" %d", q->Num);
      }
    }
    if(List_Nbr(e->Hexahedra)){
      printf(", in hexa");
      for(int j = 0; j < List_Nbr(e->Hexahedra); j++){
	Hexahedron *h = *(Hexahedron**)List_Pointer(e->Hexahedra, j);
	printf(" %d", h->Num);
      }
    }
    if(List_Nbr(e->Prisms)){
      printf(", in prism");
      for(int j = 0; j < List_Nbr(e->Prisms); j++){
	Prism *p = *(Prism**)List_Pointer(e->Prisms, j);
	printf(" %d", p->Num);
      }
    }
    if(List_Nbr(e->Pyramids)){
      printf(", in pyramid");
      for(int j = 0; j < List_Nbr(e->Pyramids); j++){
	Pyramid *p = *(Pyramid**)List_Pointer(e->Pyramids, j);
	printf(" %d", p->Num);
      }
    }
    printf("\n");
  }
  printf("Print Edges STOP\n");
  List_Delete(temp);
}

void EdgesContainer::SwapEdge(Vertex * V[2])
{
  Edge *e, E;
  Simplex *s, *s1, *s2;
  int i, j;
  Vertex *p[2], *q[2];

  E.V[0] = V[0];
  E.V[1] = V[1];
  e = (Edge *) Tree_PQuery(AllEdges, &E);
  E = *e;
  if(!e)
    return;
  if(!e->Simplexes)
    return;
  List_Read(e->Simplexes, 0, &s1);
  List_Read(e->Simplexes, 1, &s2);

  for(i = 0; i < 3; i++) {
    if(s1->S[i] == s2) {
      s1->ExtractOppositeEdges(i, p, q);
      if(!s1->SwapEdge(i))
        return;
      Tree_Suppress(AllEdges, &E);
      E.V[0] = q[0];
      E.V[1] = q[1];
      Tree_Add(AllEdges, &E);

      E.V[0] = q[0];
      E.V[1] = p[0];
      e = (Edge *) Tree_PQuery(AllEdges, &E);
      for(j = 0; j < 2; j++) {
        List_Read(e->Simplexes, j, &s);
        if(s == s2)
          List_Write(e->Simplexes, j, &s1);
      }

      E.V[0] = q[1];
      E.V[1] = p[1];
      e = (Edge *) Tree_PQuery(AllEdges, &E);
      for(j = 0; j < 2; j++) {
        List_Read(e->Simplexes, j, &s);
        if(s == s1)
          List_Write(e->Simplexes, j, &s2);
      }
      V[0] = q[0];
      V[1] = q[1];
    }
  }
}
