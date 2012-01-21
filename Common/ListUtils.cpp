// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Marc Ume
//

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include "MallocUtils.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "GmshMessage.h"

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

List_T *List_Create(int n, int incr, int size)
{
  List_T *liste;

  if(n <= 0)
    n = 1;
  if(incr <= 0)
    incr = 1;

  liste = (List_T *) Malloc(sizeof(List_T));

  liste->nmax = 0;
  liste->incr = incr;
  liste->size = size;
  liste->n = 0;
  liste->isorder = 0;
  liste->array = NULL;

  List_Realloc(liste, n);
  return (liste);
}

void List_Delete(List_T * liste)
{
  if(!liste)
    return;
  Free(liste->array);
  Free(liste);
}

void List_Realloc(List_T * liste, int n)
{
  if(n <= 0)
    return;

  if(liste->array == NULL) {
    // This does not permit to allocate lists smaller that liste->incr:
    //liste->nmax = ((n - 1) / liste->incr + 1) * liste->incr;
    // So this is much better
    liste->nmax = n;
    liste->array = (char *)Malloc(liste->nmax * liste->size);
  }
  else if(n > liste->nmax) {
    liste->nmax = ((n - 1) / liste->incr + 1) * liste->incr;
    liste->array = (char *)Realloc(liste->array, liste->nmax * liste->size);
  }
}

void List_Add(List_T * liste, void *data)
{
  liste->n++;

  List_Realloc(liste, liste->n);
  liste->isorder = 0;
  memcpy(&liste->array[(liste->n - 1) * liste->size], data, liste->size);
}

void List_Add(List_T *liste, int data)
{
  List_Add(liste, &data);
}

int List_Nbr(List_T * liste)
{
  return (liste) ? liste->n : 0;
}

void List_Read(List_T * liste, int index, void *data)
{
  if((index < 0) || (index >= liste->n))
    Msg::Fatal("Wrong list index (read)");
  memcpy(data, &liste->array[index * liste->size], liste->size);
}

void List_Write(List_T * liste, int index, void *data)
{
  if((index < 0) || (index >= liste->n))
    Msg::Error("Wrong list index (write)");
  else {
    liste->isorder = 0;
    memcpy(&liste->array[index * liste->size], data, liste->size);
  }
}

void List_Pop(List_T * liste)
{
  if(liste->n > 0)
    liste->n--;
}

void *List_Pointer(List_T * liste, int index)
{
  if((index < 0) || (index >= liste->n))
    Msg::Fatal("Wrong list index (pointer)");

  liste->isorder = 0;
  return (&liste->array[index * liste->size]);
}

void *List_Pointer_NoChange(List_T * liste, int index)
{
  if((index < 0) || (index >= liste->n))
    Msg::Fatal("Wrong list index (pointer)");

  return (&liste->array[index * liste->size]);
}

void *List_Pointer_Fast(List_T * liste, int index)
{
  return (&liste->array[index * liste->size]);
}

void List_Sort(List_T * liste, int (*fcmp) (const void *a, const void *b))
{
  qsort(liste->array, liste->n, liste->size, fcmp);
}

void List_Unique(List_T * liste, int (*fcmp) (const void *a, const void *b))
{
  if(liste->isorder != 1) {
    List_Sort(liste, fcmp);
    liste->isorder = 1;
  }
  if(!List_Nbr(liste))
    return;
  int write_index=0;
  for( int i=1; i < List_Nbr(liste); i++){
     void *data=List_Pointer(liste,i);
    if((fcmp(data,(void*)List_Pointer(liste,write_index))))
      List_Write(liste,++write_index,data);
  }
  liste->n=write_index+1;
}

int List_Search(List_T * liste, void *data,
                int (*fcmp) (const void *a, const void *b))
{
  void *ptr;

  if(liste->isorder != 1) {
    List_Sort(liste, fcmp);
    liste->isorder = 1;
  }
  ptr = (void *)bsearch(data, liste->array, liste->n, liste->size, fcmp);
  if(ptr == NULL)
    return (0);
  return (1);
}

int List_ISearchSeq(List_T * liste, void *data,
                    int (*fcmp) (const void *a, const void *b))
{
  int i;

  if(!liste)
    return -1;
  i = 0;
  while((i < List_Nbr(liste)) && fcmp(data, (void *)List_Pointer(liste, i)))
    i++;
  if(i == List_Nbr(liste))
    i = -1;
  return i;
}

void *List_PQuery(List_T * liste, void *data,
                  int (*fcmp) (const void *a, const void *b))
{
  void *ptr;

  if(liste->isorder != 1)
    List_Sort(liste, fcmp);
  liste->isorder = 1;
  ptr = (void *)bsearch(data, liste->array, liste->n, liste->size, fcmp);
  return (ptr);
}

int List_PSuppress(List_T * liste, int index)
{
  char *ptr;
  int len;

  ptr = (char *)List_Pointer_NoChange(liste, index);
  if(ptr == NULL)
    return (0);

  liste->n--;
  len = liste->n - (((intptr_t)ptr - (intptr_t)liste->array) / liste->size);
  if(len > 0)
    memmove(ptr, ptr + liste->size, len * liste->size);
  return (1);
}

void List_Invert(List_T * a, List_T * b)
{
  int i, N;
  N = List_Nbr(a);
  for(i = 0; i < N; i++) {
    List_Add(b, List_Pointer(a, N - i - 1));
  }
}

void List_Reset(List_T * liste)
{
  if(!liste)
    return;
  liste->n = 0;
}

void List_Action(List_T * liste, void (*action) (void *data, void *dummy))
{
  int i, dummy;

  for(i = 0; i < List_Nbr(liste); i++)
    (*action) (List_Pointer_NoChange(liste, i), &dummy);
}

void List_Copy(List_T * a, List_T * b)
{
  int i, N;
  N = List_Nbr(a);
  for(i = 0; i < N; i++) {
    List_Add(b, List_Pointer(a, i));
  }
}

void List_Remove(List_T *a, int i)
{
  memcpy(&a->array[i * a->size], &a->array[(i + 1) * a->size], 
         a->size * (a->n - i - 1));
  a->n--;
}

//insert a in b before i
void List_Insert_In_List(List_T *a, int i, List_T *b)
{
  int oldn = b->n;
  b->n += a->n;
  List_Realloc(b, b->n);
  for(int j = 0; j < oldn - i; j++)
    memcpy(List_Pointer_Fast(b, b->n - j - 1), List_Pointer_Fast(b, oldn - j - 1),
           b->size);
  for(int j = 0;j < a->n; j++)
    memcpy(List_Pointer_Fast(b, i + j), List_Pointer_Fast(a, j), b->size);
}

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

