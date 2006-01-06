#ifndef _FACE_H_
#define _FACE_H_

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

#include "List.h"
#include "Tree.h"
#include "Vertex.h"
#include "Element.h"

typedef struct {
  Vertex *V[3];
} Face;

class QuadFace
{
 public:
  Vertex *V[4];
  Vertex *newv;
  Quadrangle *quad;
  Hexahedron *hexa[2];
  Prism *prism[2];
  Pyramid *pyramid[2];
  QuadFace();
  ~QuadFace(){;}
};

class QuadFacesContainer
{
 public :
  Tree_T *AllFaces;
  QuadFacesContainer();
  ~QuadFacesContainer();
  void AddQuadrangleTree(Tree_T *Quadrangles);
  void AddHexahedronTree(Tree_T *Hexahedra);
  void AddPrismTree(Tree_T *Prisms);    
  void AddPyramidTree(Tree_T *Pyramids);
  void AddQuadFaces(Quadrangle *q);
  void AddQuadFaces(Hexahedron *h);
  void AddQuadFaces(Prism *p);
  void AddQuadFaces(Pyramid *p);
  void Print();
};

int compareFace(const void *a, const void *b);
int compareQuadFace(const void *a, const void *b);

#endif
