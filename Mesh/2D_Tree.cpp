// $Id: 2D_Tree.cpp,v 1.13 2004-03-03 22:26:34 geuzaine Exp $
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
#include "2D_Mesh.h"

// deletes the tree (*not* the data! only the links)

int avltree_remove(avlstruct ** root)
{
  int delete_this_node = 0;

  if(*root == NULL)
    return (1);

  if(((*root)->left == NULL) && ((*root)->right == NULL))
    delete_this_node = 1;
  else {
    if((*root)->left == NULL)
      if(avltree_remove(&(*root)->left)) {
        Free((*root)->left);
        (*root)->left = NULL;
      }
    if((*root)->right == NULL)
      if(avltree_remove(&(*root)->right)) {
        Free((*root)->right);
        (*root)->right = NULL;
      }
    if(((*root)->left == NULL) && ((*root)->right == NULL))
      delete_this_node = 1;
  }
  return delete_this_node;
}

// inserts a node

int avltree_insert(avlstruct ** root, void *item,
                   int (*fcmp) (void *a, void *b))
{
  int cmpresult = 0;

  if(*root != NULL)
    cmpresult = fcmp(item, (*root)->treedata);

  if(*root == NULL) {
    *root = (avlstruct *) Malloc(sizeof(avlstruct));
    (*root)->treedata = item;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if(cmpresult < 0)
    avltree_insert(&(*root)->left, item, fcmp);
  else
    avltree_insert(&(*root)->right, item, fcmp);
  return (1);
}

// deletes a node

int avltree_delete(avlstruct ** root, void *item,
                   int (*fcmp) (void *a, void *b))
{
  avlstruct *t1, *t12;
  int cmpresult = 0;

  if(*root != NULL)
    cmpresult = fcmp(item, (*root)->treedata);

  if(*root == NULL) {
    return (1);
  }
  if(cmpresult < 0) {
    return (avltree_delete(&(*root)->left, item, fcmp));
  }
  else if(cmpresult > 0) {
    return (avltree_delete(&(*root)->right, item, fcmp));
  }
  else if((cmpresult == 0)) {
    if(((*root)->right == NULL) && (&(*root)->left == NULL)) {
      Free(*root);
      *root = NULL;
      return (1);
    }
    else if((*root)->right == NULL) {
      t1 = (*root)->left;
      Free(*root);
      *root = t1;
      return (1);
    }
    else if((*root)->left == NULL) {
      t1 = (*root)->right;
      Free(*root);
      *root = t1;
      return (1);
    }
    else {
      t1 = t12 = (*root)->right;
      while(t12->left != NULL)
        t12 = t12->left;
      t12->left = (*root)->left;
      Free(*root);
      *root = t1;
      return (1);
    }
  }
  else {
    return (avltree_delete(&(*root)->left, item, fcmp));
  }

}

// counts the number of nodes

void avltree_count(avlptr root, int *numtri)
{
  if(root != NULL) {
    avltree_count(root->left, numtri);

    (*numtri)++;

    avltree_count(root->right, numtri);
  }
}

// unrolls the tree into a vector

void avltree_print(avlptr root, Delaunay ** listdel, int *numtri)
{
  if(root != NULL) {
    avltree_print(root->left, listdel, numtri);
    listdel[(*numtri)++] = (Delaunay *) (root)->treedata;
    avltree_print(root->right, listdel, numtri);
  }
}
