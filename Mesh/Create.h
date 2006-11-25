#ifndef _CREATE_H_
#define _CREATE_H_

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
#include "Vertex.h"
#include "Mesh.h"

int compareNXE(const void *a, const void *b);
int compareFxE(const void *a, const void *b);
int compareSurfaceLoop(const void *a, const void *b);
int compareEdgeLoop(const void *a, const void *b);
int compareQuality(const void *a, const void *b);
int compareCurve(const void *a, const void *b);
int compareSurface(const void *a, const void *b);
int compareVolume(const void *a, const void *b);
int compareSxF(const void *a, const void *b);
int compareMeshPartitionNum(const void *a, const void *b);
int compareMeshPartitionIndex(const void *a, const void *b);
int comparePhysicalGroup(const void *a, const void *b);

PhysicalGroup *Create_PhysicalGroup(int Num, int typ, List_T * intlist);
Curve         *Create_Curve(int Num, int Typ, int Order, List_T * Liste,
			    List_T * Knots, int p1, int p2, double u1, double u2);
Surface       *Create_Surface(int Num, int Typ);
Volume        *Create_Volume(int Num, int Typ);
EdgeLoop      *Create_EdgeLoop(int Num, List_T * intlist);
SurfaceLoop   *Create_SurfaceLoop(int Num, List_T * intlist);

void Free_PhysicalGroup(void *a, void *b);
void Free_MeshPartition(void *a, void *b);
void Free_Surface(void *a, void *b);
void Free_Volume(void *a, void *b);
void Free_Volume_But_Not_Elements(void *a, void *b);
void Free_Curve(void *a, void *b);
void Free_EdgeLoop(void *a, void *b);
void Free_SurfaceLoop(void *a, void *b);

void End_Curve(Curve * c);
void End_Surface(Surface * s, int reset_orientations=1);

int  Add_MeshPartition(int Num, Mesh * M);

#endif
