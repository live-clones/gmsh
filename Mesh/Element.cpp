// $Id: Element.cpp,v 1.1 2004-05-25 04:10:05 geuzaine Exp $
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
#include "Mesh.h"
#include "Element.h"

int Element::TotalNumber = 0;

Element::Element()
  : Num(0), iEnt(-1), iPart(-1), Visible(VIS_MESH), VSUP(NULL)
{
}

Element::~Element()
{
}

// Quads

Quadrangle::Quadrangle()
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  for(int i = 0; i < 4; i++) V[i] = NULL;
  VSUP = NULL;
}

Quadrangle::Quadrangle(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4)
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4;
  VSUP = NULL;
}

Quadrangle::~Quadrangle()
{
  if(VSUP) Free(VSUP);
}

Quadrangle *Create_Quadrangle(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4)
{
  Quadrangle *q = new Quadrangle(v1, v2, v3, v4);
  return q;
}

void Free_Quadrangle(void *a, void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  if(q) {
    delete q;
    q = NULL;
  }
}

int compareQuadrangle(const void *a, const void *b)
{
  Quadrangle *q = *(Quadrangle **) a;
  Quadrangle *w = *(Quadrangle **) b;
  return (q->Num - w->Num);
}

// Hexas

Hexahedron::Hexahedron()
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  for(int i = 0; i < 8; i++) V[i] = NULL;
  VSUP = NULL;
}

Hexahedron::Hexahedron(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4,
		       Vertex *v5, Vertex *v6, Vertex *v7, Vertex *v8)
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4;
  V[4] = v5; V[5] = v6; V[6] = v7; V[7] = v8;
  VSUP = NULL;
}

Hexahedron::~Hexahedron()
{
  if(VSUP) Free(VSUP);
}

Hexahedron *Create_Hexahedron(Vertex * v1, Vertex * v2, Vertex * v3,
                              Vertex * v4, Vertex * v5, Vertex * v6,
                              Vertex * v7, Vertex * v8)
{
  Hexahedron *h = new Hexahedron(v1, v2, v3, v4, v5, v6, v7, v8);
  return h;
}

void Free_Hexahedron(void *a, void *b)
{
  Hexahedron *h = *(Hexahedron **) a;
  if(h) {
    delete h;
    h = NULL;
  }
}

int compareHexahedron(const void *a, const void *b)
{
  Hexahedron *q = *(Hexahedron **) a;
  Hexahedron *w = *(Hexahedron **) b;
  return (q->Num - w->Num);
}

// Prisms

Prism::Prism()
{
  iEnt = -1;
  iPart = -1;
  Num = 0;
  Visible = VIS_MESH;
  for(int i = 0; i < 6; i++) V[i] = NULL;
  VSUP = NULL;
}

Prism::Prism(Vertex *v1, Vertex *v2, Vertex *v3, 
	     Vertex *v4, Vertex *v5, Vertex *v6)
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  V[0] = v1; V[1] = v2; V[2] = v3; 
  V[3] = v4; V[4] = v5; V[5] = v6;
  VSUP = NULL;
}

Prism::~Prism()
{
  if(VSUP) Free(VSUP);
}

Prism *Create_Prism(Vertex * v1, Vertex * v2, Vertex * v3,
                    Vertex * v4, Vertex * v5, Vertex * v6)
{
  Prism *p = new Prism(v1, v2, v3, v4, v5, v6);
  return p;
}

void Free_Prism(void *a, void *b)
{
  Prism *p = *(Prism **) a;
  if(p) {
    delete p;
    p = NULL;
  }
}

int comparePrism(const void *a, const void *b)
{
  Prism *q = *(Prism **) a;
  Prism *w = *(Prism **) b;
  return (q->Num - w->Num);
}

// Pyramids

Pyramid::Pyramid()
{
  iEnt = -1;
  iPart = -1;
  Num = 0;
  Visible = VIS_MESH;
  for(int i = 0; i < 5; i++) V[i] = NULL;
  VSUP = NULL;
}

Pyramid::Pyramid(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *v4, Vertex *v5)
{
  iEnt = -1;
  iPart = -1;
  Num = ++TotalNumber;
  Visible = VIS_MESH;
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4; V[4] = v5; 
  VSUP = NULL;
}

Pyramid::~Pyramid()
{
  if(VSUP) Free(VSUP);
}

Pyramid *Create_Pyramid(Vertex * v1, Vertex * v2, Vertex * v3,
                        Vertex * v4, Vertex * v5)
{
  Pyramid *p = new Pyramid(v1, v2, v3, v4, v5);
  return p;
}

void Free_Pyramid(void *a, void *b)
{
  Pyramid *p = *(Pyramid **) a;
  if(p) {
    delete p;
    p = NULL;
  }
}

int comparePyramid(const void *a, const void *b)
{
  Pyramid *q = *(Pyramid **) a;
  Pyramid *w = *(Pyramid **) b;
  return (q->Num - w->Num);
}
