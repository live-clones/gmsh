// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Marc Ume
//

#include <stdlib.h>
#include <string.h>
#include "MallocUtils.h"
#include "TreeUtils.h"

Tree_T *Tree_Create(int size, int (*fcmp) (const void *a, const void *b))
{
  Tree_T *tree = (Tree_T*)Malloc(sizeof(Tree_T));
  tree->size = size;
  tree->root = avl_init_table(fcmp);
  return tree;
}

void Tree_Delete(Tree_T * tree)
{
  if(!tree) return;
  avl_free_table(tree->root, Free, 0);
  Free(tree);
}

void *Tree_Add(Tree_T * tree, void *data)
{
  if(!tree) return 0;
  void *ptr = Malloc(tree->size);
  memcpy(ptr, data, tree->size);
  avl_insert(tree->root, ptr, ptr);
  return ptr;
}

int Tree_Nbr(Tree_T * tree)
{
  if(!tree) return 0;
  return avl_count(tree->root);
}

int Tree_Insert(Tree_T * tree, void *data)
{
  if(!Tree_Search(tree, data)){
    Tree_Add(tree, data);
    return 1;
  }
  return 0;
}

int Tree_Search(Tree_T * tree, void *data)
{
  if(!tree) return 0;
  void *ptr;
  return avl_lookup(tree->root, data, &ptr);
}

int Tree_Query(Tree_T * tree, void *data)
{
  if(!tree) return 0;
  void *ptr;
  if(!avl_lookup(tree->root, data, &ptr))
    return 0;
  memcpy(data, ptr, tree->size);
  return 1;
}

void *Tree_PQuery(Tree_T * tree, void *data)
{
  if(!tree) return 0;
  void *ptr;
  if(!avl_lookup(tree->root, data, &ptr))
    return 0;
  return ptr;
}

int Tree_Suppress(Tree_T * tree, void *data)
{
  if(!tree) return 0;
  void *ptr = data;
  if(!avl_delete(tree->root, &ptr, &ptr))
    return 0;
  Free(ptr);
  return 1;
}

int Tree_Size(Tree_T * tree)
{
  if(!tree) return 0;
  return tree->size;
}

static List_T *pListTransfer;

void TransferList(void *a, void *b)
{
  List_Add(pListTransfer, a);
}

List_T *Tree2List(Tree_T * pTree)
{
  int Nb;
  Nb = Tree_Nbr(pTree);
  if(Nb == 0)
    Nb = 1;
  pListTransfer = List_Create(Nb, Nb, Tree_Size(pTree));
  Tree_Action(pTree, TransferList);
  return pListTransfer;
}
