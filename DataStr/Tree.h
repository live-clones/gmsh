/* $Id: Tree.h,v 1.1.1.1 2000-11-23 09:22:47 geuzaine Exp $ */
#ifndef _TREE_H_
#define _TREE_H_

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
void    Tree_Insert(Tree_T *Tree, void *data);
int     Tree_Replace(Tree_T *Tree, void *data);
int     Tree_Search(Tree_T *Tree, void *data);
int     Tree_Query(Tree_T *Tree, void *data);
void   *Tree_PQuery(Tree_T *Tree, void *data);
int     Tree_Suppress(Tree_T *Tree, void *data);
int     Tree_Left(Tree_T *tree, void *data);
int     Tree_Right(Tree_T *tree, void *data);
void    Tree_Action(Tree_T *tree, void (*action) (void *data, void *dummy));
int     Tree_Size(Tree_T *tree) ;

#endif

