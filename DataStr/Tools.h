#ifndef _TOOLS_H_
#define _TOOLS_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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

#include "List.h"
#include "Tree.h"

int fcmp_int(const void *a, const void *b);
int fcmp_absint(const void *a, const void *b);
int fcmp_double(const void *a, const void *b);

List_T *Tree2List(Tree_T *pTree) ;

Tree_T *Tree_Duplique(Tree_T *pTree) ;
Tree_T *Tree_Union       (Tree_T *pTreeA, Tree_T *pTreeB) ;
Tree_T *Tree_Soustraction(Tree_T *pTreeA, Tree_T *pTreeB) ;
Tree_T *Tree_Intersection(Tree_T *pTreeA, Tree_T *pTreeB) ;

void Tree_Unit      (Tree_T *pTreeA, Tree_T *pTreeB) ;
void Tree_Soustrait (Tree_T *pTreeA, Tree_T *pTreeB) ;
void Tree_Intersecte(Tree_T *pTreeA, Tree_T *pTreeB) ;

#endif
