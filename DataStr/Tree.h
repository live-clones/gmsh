#ifndef _TREE_H_
#define _TREE_H_

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
//
// Contributor(s):
//   Marc Ume
//

#include "avl.h"

typedef struct {
  int size;
  avl_tree *root;
} Tree_T;

Tree_T *Tree_Create(int size, int (*fcmp)(const void *a, const void *b));
void    Tree_Delete(Tree_T *Tree);
void    Tree_Add(Tree_T *tree, void *data);
void   *Tree_AddP(Tree_T *tree, void *data);
int     Tree_Nbr(Tree_T *Tree);
int     Tree_Insert(Tree_T *Tree, void *data);
int     Tree_Replace(Tree_T *Tree, void *data);
int     Tree_Search(Tree_T *Tree, void *data);
int     Tree_Query(Tree_T *Tree, void *data);
void   *Tree_PQuery(Tree_T *Tree, void *data);
int     Tree_Suppress(Tree_T *Tree, void *data);
int     Tree_Left(Tree_T *tree, void *data);
int     Tree_Right(Tree_T *tree, void *data);
int     Tree_Size(Tree_T *tree) ;

inline void Tree_Action(Tree_T *tree, void (*action) (void *data, void *dummy))
{
  if(!tree) return;

  avl_foreach(tree->root, action, AVL_FORWARD);
}


#endif

