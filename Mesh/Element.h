#ifndef _ELEMENT_H_
#define _ELEMENT_H_

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

#include "Vertex.h"

class Element {
 public:
  int     Num;           // Number
  int     iEnt;          // Elementary geometrical entity
  int     iPart;         // Mesh partition index
  char    Visible;       // Visualization flag
  Vertex  **VSUP;        // suppl. nodes for higher order elts
  static  int TotalNumber;
  Element();
  virtual ~Element();
};

class Quadrangle : public Element{
 public:
  Vertex *V[4];
  Quadrangle();
  Quadrangle(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
  ~Quadrangle();
};

class Hexahedron : public Element{
 public:
  Vertex *V[8];
  Hexahedron();
  Hexahedron(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4,
	     Vertex *v5, Vertex *v6, Vertex *v7, Vertex *v8);
  ~Hexahedron();
};

class Prism : public Element{
 public:
  Vertex *V[6];
  Prism();
  Prism(Vertex *v1, Vertex *v2, Vertex *v3, 
	Vertex *v4, Vertex *v5, Vertex *v6);
  ~Prism();
};

class Pyramid : public Element{
 public:
  Vertex *V[5];
  Pyramid();
  Pyramid(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4, Vertex *v5);
  ~Pyramid();
};

// C interface

Quadrangle *Create_Quadrangle (Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4);
Hexahedron *Create_Hexahedron(Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4,
			      Vertex * v5, Vertex * v6, Vertex * v7, Vertex * v8);
Prism *Create_Prism(Vertex * v1, Vertex * v2, Vertex * v3,
		    Vertex * v4, Vertex * v5, Vertex * v6);
Pyramid *Create_Pyramid(Vertex * v1, Vertex * v2, Vertex * v3,
			Vertex * v4, Vertex * v5);

void Free_Quadrangle(void *a, void *b);
void Free_Hexahedron(void *a, void *b);
void Free_Prism(void *a, void *b);
void Free_Pyramid(void *a, void *b);

int compareQuadrangle(const void *a, const void *b);
int compareHexahedron(const void *a, const void *b);
int comparePrism(const void *a, const void *b);
int comparePyramid(const void *a, const void *b);

#endif
