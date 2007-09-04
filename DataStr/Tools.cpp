// $Id: Tools.cpp,v 1.17 2007-09-04 13:47:00 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <stdlib.h>
#include <math.h>
#include "Tools.h"

static List_T *pListeTransfert;
static Tree_T *pTreeTransfert;
static Tree_T *pTreeTransfert2;

// Comparison functions

int fcmp_int(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int fcmp_absint(const void *a, const void *b)
{
  return (abs(*(int *)a) - abs(*(int *)b));
}

int fcmp_double(const void *a, const void *b)
{
  double cmp;

  cmp = *(double *)a - *(double *)b;
  if(cmp > 1.e-16)
    return 1;
  else if(cmp < -1.e-16)
    return -1;
  else
    return 0;
}

// List utilities

List_T *ListOfDouble2ListOfInt(List_T *dList)
{
  int n = List_Nbr(dList); 
  List_T *iList = List_Create(n, n, sizeof(int));
  for(int i = 0; i < n; i++){
    double d;
    List_Read(dList, i, &d);
    int j = (int)d;
    List_Add(iList, &j);
  }
  return iList;
}

// Tree -> List transfer

void TransfereListe(void *a, void *b)
{
  List_Add(pListeTransfert, a);
}

List_T *Tree2List(Tree_T * pTree)
{
  int Nb;
  Nb = Tree_Nbr(pTree);
  if(Nb == 0)
    Nb = 1;
  pListeTransfert = List_Create(Nb, Nb, Tree_Size(pTree));
  Tree_Action(pTree, TransfereListe);
  return (pListeTransfert);
}

// List -> Tree transfer

void TransfereTree(void *a, void *b)
{
  Tree_Add(pTreeTransfert, a);
}

Tree_T *List2Tree(List_T * pList, int (*fcmp) (const void *a, const void *b))
{
  pTreeTransfert = Tree_Create(pList->size, fcmp);
  List_Action(pList, TransfereTree);
  return (pTreeTransfert);
}

// Algebraic utilities

void DupliqueArbre(void *a, void *b)
{
  Tree_Add(pTreeTransfert, a);
}

Tree_T *Tree_Duplique(Tree_T * pTree)
{
  pTreeTransfert = Tree_Create(pTree->size, pTree->root->compar);
  Tree_Action(pTree, DupliqueArbre);
  return (pTreeTransfert);
}

void UnitArbre(void *a, void *b)
{
  Tree_Replace(pTreeTransfert, a);
}

Tree_T *Tree_Union(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert = Tree_Duplique(pTreeA);
  Tree_Action(pTreeB, UnitArbre);
  return (pTreeTransfert);
}

void Tree_Unit(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert = pTreeA;
  Tree_Action(pTreeB, UnitArbre);
}

void SoustraitArbre(void *a, void *b)
{
  Tree_Suppress(pTreeTransfert, a);
}

Tree_T *Tree_Soustraction(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert = Tree_Duplique(pTreeA);
  Tree_Action(pTreeB, SoustraitArbre);
  return (pTreeTransfert);
}

void Tree_Soustrait(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert = pTreeA;
  Tree_Action(pTreeB, SoustraitArbre);
}

void IntersecteArbre(void *a, void *b)
{
  if(Tree_Query(pTreeTransfert, a))
    Tree_Add(pTreeTransfert2, a);
}

Tree_T *Tree_Intersection(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert = Tree_Duplique(pTreeA);
  pTreeTransfert2 = Tree_Create(pTreeA->size, pTreeA->root->compar);
  Tree_Action(pTreeB, IntersecteArbre);
  Tree_Delete(pTreeTransfert);
  return (pTreeTransfert2);
}

void Tree_Intersecte(Tree_T * pTreeA, Tree_T * pTreeB)
{
  pTreeTransfert2 = pTreeA;
  pTreeTransfert = Tree_Create(pTreeA->size, pTreeA->root->compar);
  Tree_Action(pTreeB, IntersecteArbre);
  pTreeA = pTreeTransfert2;
  Tree_Delete(pTreeA);
}
