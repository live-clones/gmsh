#ifndef _LIST_UTILS_H_
#define _LIST_UTILS_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <stdio.h>

#define LIST_FORMAT_ASCII       0
#define LIST_FORMAT_BINARY      1

class List_T {
public:
  int nmax;
  int size;
  int incr;
  int n;
  int isorder;
  char *array;
};

List_T *List_Create(int n, int incr, int size);
void    List_Delete(List_T *liste);
void    List_Realloc(List_T *liste,int n);
void    List_Add(List_T *liste, void *data);
int     List_Nbr(List_T *liste);
void    List_Read(List_T *liste, int index, void *data);
void    List_Write(List_T *liste, int index, void *data);
void    List_Put(List_T *liste, int index, void *data);
void    List_Pop(List_T *liste);
void   *List_Pointer(List_T *liste, int index);
void   *List_Pointer_NoChange(List_T *liste, int index);
void   *List_Pointer_Fast(List_T *liste, int index);
void   *List_Pointer_Test(List_T *liste, int index);
void    List_Sort(List_T *liste, int (*fcmp)(const void *a, const void *b));
int     List_Search(List_T *liste, void *data, int (*fcmp)(const void *a, const void *b));
int     List_ISearch(List_T *liste, void *data, int (*fcmp)(const void *a, const void *b));
int     List_ISearchSeq(List_T *liste, void * data, int (*fcmp)(const void *a, const void *b));
void   *List_PQuery(List_T *liste, void *data, int (*fcmp)(const void *a, const void *b));
int     List_PSuppress(List_T *liste, int index);
void    List_Invert(List_T *a, List_T *b);
void    List_Reset(List_T *liste);
void    List_Action(List_T *liste, void (*action)(void *data, void *dummy));
void    List_Copy(List_T *a , List_T *b);
void    List_Merge(List_T *a , List_T *b);
List_T *List_CreateFromFile(int n, int incr, int size, FILE *file, int format, int swap);
void    List_WriteToFile(List_T *liste, FILE *file, int format);

// for backward compatibility
List_T *List_CreateFromFileOld(int n, int incr, int size, FILE *file, int format, int swap);

int fcmp_int(const void *a, const void *b);
int fcmp_absint(const void *a, const void *b);
int fcmp_double(const void *a, const void *b);

List_T *ListOfDouble2ListOfInt(List_T *dList);

#endif

