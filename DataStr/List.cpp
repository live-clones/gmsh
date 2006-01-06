// $Id: List.cpp,v 1.37 2006-01-06 00:34:21 geuzaine Exp $
//
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
//
// Contributor(s):
//   Marc Ume
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "Malloc.h"
#include "List.h"
#include "Message.h"
#include "SafeIO.h"

static char *startptr;

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

int List_Nbr(List_T * liste)
{
  return (liste) ? liste->n : 0;
}

void List_Insert(List_T * liste, void *data,
                 int (*fcmp) (const void *a, const void *b))
{
  if(List_Search(liste, data, fcmp) == 0)
    List_Add(liste, data);
}

int List_Replace(List_T * liste, void *data,
                 int (*fcmp) (const void *a, const void *b))
{
  void *ptr;

  if(liste->isorder != 1)
    List_Sort(liste, fcmp);
  liste->isorder = 1;
  ptr = (void *)bsearch(data, liste->array, liste->n, liste->size, fcmp);
  if(ptr == NULL) {
    List_Add(liste, data);
    return (0);
  }
  else {
    memcpy(ptr, data, liste->size);
    return (1);
  }
}

void List_Read(List_T * liste, int index, void *data)
{
  if((index < 0) || (index >= liste->n))
    Msg(FATAL, "Wrong list index (read)");
  memcpy(data, &liste->array[index * liste->size], liste->size);
}

void List_Write(List_T * liste, int index, void *data)
{
  if((index < 0) || (index >= liste->n))
    Msg(GERROR, "Wrong list index (write)");
  else {
    liste->isorder = 0;
    memcpy(&liste->array[index * liste->size], data, liste->size);
  }
}

void List_Put(List_T * liste, int index, void *data)
{
  if(index < 0)
    Msg(GERROR, "Wrong list index (put)");
  else {
    if(index >= liste->n) {
      liste->n = index + 1;
      List_Realloc(liste, liste->n);
      List_Write(liste, index, data);
    }
    else {
      List_Write(liste, index, data);
    }
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
    Msg(FATAL, "Wrong list index (pointer)");

  liste->isorder = 0;
  return (&liste->array[index * liste->size]);
}

void *List_Pointer_NoChange(List_T * liste, int index)
{
  if((index < 0) || (index >= liste->n))
    Msg(FATAL, "Wrong list index (pointer)");

  return (&liste->array[index * liste->size]);
}

void *List_Pointer_Fast(List_T * liste, int index)
{
  return (&liste->array[index * liste->size]);
}

void *List_Pointer_Test(List_T * liste, int index)
{
  if(!liste || (index < 0) || (index >= liste->n))
    return NULL;

  liste->isorder = 0;
  return (&liste->array[index * liste->size]);
}

void List_Sort(List_T * liste, int (*fcmp) (const void *a, const void *b))
{
  qsort(liste->array, liste->n, liste->size, fcmp);
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

int List_ISearch(List_T * liste, void *data,
                 int (*fcmp) (const void *a, const void *b))
{
  void *ptr;

  if(liste->isorder != 1)
    List_Sort(liste, fcmp);
  liste->isorder = 1;
  ptr = (void *)bsearch(data, liste->array, liste->n, liste->size, fcmp);
  if(ptr == NULL)
    return (-1);
  return (((long)ptr - (long)liste->array) / liste->size);
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

int List_ISearchSeqPartial(List_T * liste, void *data, int i_Start,
                           int (*fcmp) (const void *a, const void *b))
{
  int i;

  if(!liste)
    return -1;
  i = i_Start;
  while((i < List_Nbr(liste)) && fcmp(data, (void *)List_Pointer(liste, i)))
    i++;
  if(i == List_Nbr(liste))
    i = -1;
  return i;
}

int List_Query(List_T * liste, void *data,
               int (*fcmp) (const void *a, const void *b))
{
  void *ptr;

  if(liste->isorder != 1)
    List_Sort(liste, fcmp);
  liste->isorder = 1;
  ptr = (void *)bsearch(data, liste->array, liste->n, liste->size, fcmp);
  if(ptr == NULL)
    return (0);

  memcpy(data, ptr, liste->size);
  return (1);
}

void *lolofind(void *data, void *array, int n, int size,
               int (*fcmp) (const void *a, const void *b))
{
  char *ptr;
  int i;

  ptr = (char *)array;
  for(i = 0; i < n; i++) {
    if(fcmp(ptr, data) == 0)
      break;
    ptr += size;
  }
  if(i < n)
    return (ptr);
  return (NULL);
}

int List_LQuery(List_T *liste, void *data,
		 int (*fcmp)(const void *a, const void *b), int first)
{
  char *ptr;
  
  if (first == 1) { 
    ptr = (char *) lolofind(data,liste->array,liste->n,liste->size,fcmp);
  }
  else {
    if (startptr != NULL)
      ptr = (char *) lolofind(data,startptr,
			      liste->n - (startptr-liste->array)/liste->size,
			      liste->size,fcmp);
    else
      return(0);
  }

  if (ptr == NULL) return(0);

  startptr =  ptr + liste->size;
  if ( startptr >= ( liste->array + liste->n * liste->size))
    startptr = NULL;
  memcpy(data,ptr,liste->size);
  return (1);
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

int List_Suppress(List_T * liste, void *data,
                  int (*fcmp) (const void *a, const void *b))
{
  char *ptr;
  int len;

  ptr = (char *)List_PQuery(liste, data, fcmp);
  if(ptr == NULL)
    return (0);

  liste->n--;
  len = liste->n - (((long)ptr - (long)liste->array) / liste->size);
  if(len > 0)
    memmove(ptr, ptr + liste->size, len * liste->size);
  return (1);
}

int List_PSuppress(List_T * liste, int index)
{
  char *ptr;
  int len;

  ptr = (char *)List_Pointer_NoChange(liste, index);
  if(ptr == NULL)
    return (0);

  liste->n--;
  len = liste->n - (((long)ptr - (long)liste->array) / liste->size);
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

  for(i = 0; i < List_Nbr(liste); i++) {
    (*action) (List_Pointer_NoChange(liste, i), &dummy);
  }

}

void List_Action_Inverse(List_T * liste,
                         void (*action) (void *data, void *dummy))
{
  int i, dummy;

  for(i = List_Nbr(liste); i > 0; i--) {
    (*action) (List_Pointer_NoChange(liste, i - 1), &dummy);
  }

}

void List_Copy(List_T * a, List_T * b)
{
  int i, N;
  N = List_Nbr(a);
  for(i = 0; i < N; i++) {
    List_Add(b, List_Pointer(a, i));
  }
}

void swap_bytes(char *array, int size, int n)
{
  int i, c;
  char *x, *a;

  x = (char *)Malloc(size);

  for(i = 0; i < n; i++) {
    a = &array[i * size];
    memcpy(x, a, size);
    for(c = 0; c < size; c++)
      a[size - 1 - c] = x[c];
  }

  Free(x);
}

List_T *List_CreateFromFile(int n, int incr, int size, FILE * file, int format,
                            int swap)
{
  int i;
  List_T *liste;

  if(!n){
    liste = List_Create(1, incr, size);
    return liste;
  }

  liste = List_Create(n, incr, size);
  liste->n = n;
  switch (format) {
  case LIST_FORMAT_ASCII:
    if(size == sizeof(double))
      for(i = 0; i < n; i++)
        fscanf(file, "%lf", (double *)&liste->array[i * size]);
    else if(size == sizeof(float))
      for(i = 0; i < n; i++)
        fscanf(file, "%f", (float *)&liste->array[i * size]);
    else if(size == sizeof(int))
      for(i = 0; i < n; i++)
        fscanf(file, "%d", (int *)&liste->array[i * size]);
    else if(size == sizeof(char)) {
      for(i = 0; i < n; i++)
        liste->array[i * size] = fgetc(file);
    }
    else {
      Msg(GERROR, "Bad type of data to create list from (size = %d)", size);
      return NULL;
    }
    return liste;
  case LIST_FORMAT_BINARY:
    fread(liste->array, size, n, file);
    if(swap)
      swap_bytes(liste->array, size, n);
    return liste;
  default:
    Msg(GERROR, "Unknown list format");
    return NULL;
  }

}

void List_WriteToFile(List_T * liste, FILE * file, int format)
{
  int i, n;

  if(!(n = List_Nbr(liste)))
    return;

  switch (format) {
  case LIST_FORMAT_ASCII:
    if(liste->size == sizeof(double))
      for(i = 0; i < n; i++)
        fprintf(file, " %.16g", *((double *)&liste->array[i * liste->size]));
    else if(liste->size == sizeof(float))
      for(i = 0; i < n; i++)
        fprintf(file, " %.16g", *((float *)&liste->array[i * liste->size]));
    else if(liste->size == sizeof(int))
      for(i = 0; i < n; i++)
        fprintf(file, " %d", *((int *)&liste->array[i * liste->size]));
    else if(liste->size == sizeof(char))
      for(i = 0; i < n; i++)
	fputc(*((char *)&liste->array[i * liste->size]), file);
    else
      Msg(GERROR, "Bad type of data to write list to file (size = %d)",
          liste->size);
    break;
  case LIST_FORMAT_BINARY:
    safe_fwrite(liste->array, liste->size, n, file);
    break;
  default:
    Msg(GERROR, "Unknown list format");
  }
}

// For backward compatibility purposes:

List_T *List_CreateFromFileOld(int n, int incr, int size, FILE * file, int format,
			       int swap)
{
  int i;
  List_T *liste;

  if(!n){
    liste = List_Create(1, incr, size);
    return liste;
  }

  liste = List_Create(n, incr, size);
  liste->n = n;
  switch (format) {
  case LIST_FORMAT_ASCII:
    if(size == sizeof(double))
      for(i = 0; i < n; i++)
        fscanf(file, "%lf", (double *)&liste->array[i * size]);
    else if(size == sizeof(float))
      for(i = 0; i < n; i++)
        fscanf(file, "%f", (float *)&liste->array[i * size]);
    else if(size == sizeof(int))
      for(i = 0; i < n; i++)
        fscanf(file, "%d", (int *)&liste->array[i * size]);
    else if(size == sizeof(char)) {
      for(i = 0; i < n; i++) {
        fscanf(file, "%c", (char *)&liste->array[i * size]);
        if(liste->array[i * size] == '^')
          liste->array[i * size] = '\0';
      }
    }
    else {
      Msg(GERROR, "Bad type of data to create list from (size = %d)", size);
      return NULL;
    }
    return liste;
  case LIST_FORMAT_BINARY:
    fread(liste->array, size, n, file);
    if(swap)
      swap_bytes(liste->array, size, n);
    return liste;
  default:
    Msg(GERROR, "Unknown list format");
    return NULL;
  }

}
