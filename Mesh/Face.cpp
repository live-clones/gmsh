// $Id: Face.cpp,v 1.3 2005-01-01 19:35:30 geuzaine Exp $
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

// Simplex faces

int trifaces_tetra[4][3] = {
  {0, 2, 1},
  {0, 1, 3},
  {0, 3, 2},
  {3, 1, 2}
};

int trifaces_prism[2][3] = {
  {0, 2, 1},
  {3, 4, 5}
};

int trifaces_pyramid[4][3] = {
  {0, 1, 4},
  {3, 0, 4},
  {1, 2, 4},
  {2, 3, 4}
};

extern int FACE_DIMENSION;

int compareFace(const void *a, const void *b)
{
  Face *q = (Face *) a;
  Face *w = (Face *) b;

  if(!q->V[0] || !w->V[0])
    Msg(FATAL, "Bad face (are you trying to generate hexahedra with a Delaunay?!)");

  if(q->V[0]->Num > w->V[0]->Num)
    return (1);
  if(q->V[0]->Num < w->V[0]->Num)
    return (-1);

  if(q->V[1]->Num > w->V[1]->Num)
    return (1);
  if(q->V[1]->Num < w->V[1]->Num)
    return (-1);

  if(FACE_DIMENSION == 1 || !q->V[2] || !w->V[2])
    return 0;

  if(q->V[2]->Num > w->V[2]->Num)
    return (1);
  if(q->V[2]->Num < w->V[2]->Num)
    return (-1);
  return (0);
}

// Quad faces

// define the faces to have exterior normals, so that we can use these
// structures directly in the drawing routines

// int quadfaces_hexa[6][4] = {
//   {0, 1, 2, 3},
//   {0, 1, 4, 5},
//   {0, 3, 4, 7},
//   {1, 2, 5, 6},
//   {2, 3, 6, 7},
//   {4, 5, 6, 7}
// };

// int quadfaces_prism[3][4] = {
//   {0, 1, 3, 4},
//   {0, 2, 3, 5},
//   {1, 2, 4, 5}
// };

// int quadfaces_pyramid[1][4] = {
//   {0, 1, 2, 3}
// };

int quadfaces_hexa[6][4] = {
  {0, 3, 2, 1},
  {0, 1, 5, 4},
  {0, 4, 7, 3},
  {1, 2, 6, 5},
  {2, 3, 7, 6},
  {4, 5, 6, 7}
};

int quadfaces_prism[3][4] = {
  {0, 1, 4, 3},
  {0, 3, 5, 2},
  {1, 2, 5, 4}
};

int quadfaces_pyramid[1][4] = {
  {0, 3, 2, 1}
};

QuadFace::QuadFace()
{
  V[0] = V[1] = V[2] = V[3] = NULL;
  newv = NULL;
  quad = NULL;
  hexa[0] = hexa[1] = NULL;
  prism[0] = prism[1] = NULL;
  pyramid[0] = pyramid[1] = NULL;
}

QuadFacesContainer::QuadFacesContainer()
{
  AllFaces = Tree_Create(sizeof(QuadFace), compareQuadFace);
}

QuadFacesContainer::~QuadFacesContainer()
{
  Tree_Delete(AllFaces);
}

void QuadFacesContainer::AddQuadrangleTree(Tree_T *Quadrangles)
{
  Quadrangle *q;
  List_T *temp = Tree2List(Quadrangles);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &q);
    AddQuadFaces(q);
  }
  List_Delete(temp);
}

void QuadFacesContainer::AddHexahedronTree(Tree_T *Hexahedra)
{
  Hexahedron *h;
  List_T *temp = Tree2List(Hexahedra);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &h);
    AddQuadFaces(h);
  }
  List_Delete(temp);
}

void QuadFacesContainer::AddPrismTree(Tree_T *Prisms)
{
  Prism *p;
  List_T *temp = Tree2List(Prisms);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &p);
    AddQuadFaces(p);
  }
  List_Delete(temp);
}

void QuadFacesContainer::AddPyramidTree(Tree_T *Pyramids)
{
  Pyramid *p;
  List_T *temp = Tree2List(Pyramids);
  for(int i = 0; i < List_Nbr(temp); i++) {
    List_Read(temp, i, &p);
    AddQuadFaces(p);
  }
  List_Delete(temp);
}

void QuadFacesContainer::AddQuadFaces(Quadrangle *q)
{
  QuadFace F, *pF;

  F.V[0] = q->V[0];
  F.V[1] = q->V[1];
  F.V[2] = q->V[2];
  F.V[3] = q->V[3];
  qsort(F.V, 4, sizeof(Vertex *), compareVertex);

  if((pF = (QuadFace *) Tree_PQuery(AllFaces, &F))) {
    if(!pF->quad)
      pF->quad = q;
  }
  else {
    F.quad = q;
    F.newv = NULL;
    Tree_Add(AllFaces, &F);
  }
}

void QuadFacesContainer::AddQuadFaces(Hexahedron *h)
{
  QuadFace F, *pF;

  for(int i = 0; i < 6; i++) {
    F.V[0] = h->V[quadfaces_hexa[i][0]];
    F.V[1] = h->V[quadfaces_hexa[i][1]];
    F.V[2] = h->V[quadfaces_hexa[i][2]];
    F.V[3] = h->V[quadfaces_hexa[i][3]];
    qsort(F.V, 4, sizeof(Vertex *), compareVertex);

    if((pF = (QuadFace *) Tree_PQuery(AllFaces, &F))) {
      if(!pF->hexa[0])
	pF->hexa[0] = h;
      else if(!pF->hexa[1])
	pF->hexa[1] = h;
    }
    else {
      F.hexa[0] = h;
      F.newv = NULL;
      Tree_Add(AllFaces, &F);
    }
  }
}

void QuadFacesContainer::AddQuadFaces(Prism *p)
{
  QuadFace F, *pF;

  for(int i = 0; i < 3; i++) {
    F.V[0] = p->V[quadfaces_prism[i][0]];
    F.V[1] = p->V[quadfaces_prism[i][1]];
    F.V[2] = p->V[quadfaces_prism[i][2]];
    F.V[3] = p->V[quadfaces_prism[i][3]];
    qsort(F.V, 4, sizeof(Vertex *), compareVertex);

    if((pF = (QuadFace *) Tree_PQuery(AllFaces, &F))) {
      if(!pF->prism[0])
	pF->prism[0] = p;
      else if(!pF->prism[1])
	pF->prism[1] = p;
    }
    else {
      F.prism[0] = p;
      F.newv = NULL;
      Tree_Add(AllFaces, &F);
    }
  }
}

void QuadFacesContainer::AddQuadFaces(Pyramid *p)
{
  QuadFace F, *pF;

  F.V[0] = p->V[quadfaces_pyramid[0][0]];
  F.V[1] = p->V[quadfaces_pyramid[0][1]];
  F.V[2] = p->V[quadfaces_pyramid[0][2]];
  F.V[3] = p->V[quadfaces_pyramid[0][3]];
  qsort(F.V, 4, sizeof(Vertex *), compareVertex);

  if((pF = (QuadFace *) Tree_PQuery(AllFaces, &F))) {
    if(!pF->pyramid[0])
      pF->pyramid[0] = p;
    else if(!pF->pyramid[1])
      pF->pyramid[1] = p;
  }
  else {
    F.pyramid[0] = p;
    F.newv = NULL;
    Tree_Add(AllFaces, &F);
  }
}

void QuadFacesContainer::Print()
{
  List_T *temp = Tree2List(AllFaces);
  printf("Print QuadFaces START\n");
  for(int i = 0; i < List_Nbr(temp); i++) {
    QuadFace *f = (QuadFace*)List_Pointer(temp, i);
    printf("quadface %d %d %d %d", 
	   f->V[0]->Num, f->V[1]->Num, f->V[2]->Num, f->V[3]->Num);
    if(f->quad)
      printf(", in quad %d", f->quad->Num);
    if(f->hexa[0])
      printf(", in hexa %d", f->hexa[0]->Num);
    if(f->hexa[1])
      printf(" %d", f->hexa[1]->Num);
    if(f->prism[0])
      printf(", in prism %d", f->prism[0]->Num);
    if(f->prism[1])
      printf(" %d", f->prism[1]->Num);
    if(f->pyramid[0])
      printf(", in pyramid %d", f->pyramid[0]->Num);
    if(f->pyramid[1])
      printf(" %d", f->pyramid[1]->Num);
    printf("\n");
  }
  printf("Print QuadFacess STOP\n");
  List_Delete(temp);
}

int compareQuadFace(const void *a, const void *b)
{
  QuadFace *q = (QuadFace *) a;
  QuadFace *w = (QuadFace *) b;

  if(q->V[0]->Num > w->V[0]->Num)
    return 1;
  if(q->V[0]->Num < w->V[0]->Num)
    return -1;

  if(q->V[1]->Num > w->V[1]->Num)
    return 1;
  if(q->V[1]->Num < w->V[1]->Num)
    return -1;

  if(q->V[2]->Num > w->V[2]->Num)
    return 1;
  if(q->V[2]->Num < w->V[2]->Num)
    return -1;

  if(q->V[3]->Num > w->V[3]->Num)
    return 1;
  if(q->V[3]->Num < w->V[3]->Num)
    return -1;

  return 0;
}
