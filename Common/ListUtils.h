// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LIST_UTILS_H_
#define _LIST_UTILS_H_

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
void    List_Add(List_T *liste, int data);
int     List_Nbr(List_T *liste);
void    List_Read(List_T *liste, int index, void *data);
void    List_Write(List_T *liste, int index, void *data);
void    List_Put(List_T *liste, int index, void *data);
void    List_Pop(List_T *liste);
void   *List_Pointer(List_T *liste, int index);
void   *List_Pointer_NoChange(List_T *liste, int index);
void   *List_Pointer_Fast(List_T *liste, int index);
void    List_Sort(List_T *liste, int (*fcmp)(const void *a, const void *b));
void    List_Unique(List_T *liste, int (*fcmp)(const void *a, const void *b));
int     List_Search(List_T *liste, void *data, int (*fcmp)(const void *a, const void *b));
int     List_ISearchSeq(List_T *liste, void * data, int (*fcmp)(const void *a, const void *b));
void   *List_PQuery(List_T *liste, void *data, int (*fcmp)(const void *a, const void *b));
int     List_PSuppress(List_T *liste, int index);
void    List_Invert(List_T *a, List_T *b);
void    List_Reset(List_T *liste);
void    List_Action(List_T *liste, void (*action)(void *data, void *dummy));
void    List_Copy(List_T *a , List_T *b);
void    List_Remove (List_T *a, int i);
void    List_Insert_In_List (List_T *a, int i, List_T *b);
List_T *ListOfDouble2ListOfInt(List_T *dList);

int fcmp_int(const void *a, const void *b);
int fcmp_absint(const void *a, const void *b);
int fcmp_double(const void *a, const void *b);

#endif
