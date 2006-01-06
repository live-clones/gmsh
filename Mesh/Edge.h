#ifndef _EDGE_H_
#define _EDGE_H_

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
#include "Simplex.h"

class Edge {
public :
  int Num;
  Vertex *V[2];
  List_T *Simplexes;
  List_T *Quadrangles;
  List_T *Hexahedra;
  List_T *Prisms;
  List_T *Pyramids;
  Vertex *newv;
  Vertex *O[2];
  double a;
  List_T *Liste;
  List_T *Points;
  Edge(){
    Num = 0;
    Simplexes = NULL;
    Quadrangles = NULL;
    Hexahedra = NULL;
    Prisms = NULL;
    Pyramids = NULL;
    Liste = NULL;
    Points = NULL;
  }
  ~Edge(){ ; }
};

class EdgesContainer
{
  public :
    Tree_T * AllEdges;
    EdgesContainer(Tree_T *Simplexes);
    EdgesContainer(List_T *Surfaces);
    EdgesContainer();
    ~EdgesContainer();
    void AddSimplexTree(Tree_T *Simplexes);
    void AddQuadrangleTree(Tree_T *Quadrangles);
    void AddHexahedronTree(Tree_T *Hexahedra);
    void AddPrismTree(Tree_T *Prisms);    
    void AddPyramidTree(Tree_T *Pyramids);
    void AddEdges(Simplex *s);
    void AddEdges(Quadrangle *q);
    void AddEdges(Hexahedron *h);
    void AddEdges(Prism *p);
    void AddEdges(Pyramid *p);
    void RemoveEdge(Edge *e);
    void SwapEdge(Vertex *v[2]);
    bool Search(Vertex *v1, Vertex *v2);
    void Print();
};

void Free_Edge(void *a, void *b);

int compareEdge(const void *a, const void *b);
int compareEdgePtr(const void *a, const void *b);
int compareEdgeAngle(const void *a, const void *b);

#endif
