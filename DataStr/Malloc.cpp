#define RCSID "$Id: Malloc.cpp,v 1.1.1.1 2000-11-23 09:22:47 geuzaine Exp $"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "Malloc.h"
#include "Message.h"

void *Malloc(size_t size)
{
  void *ptr;

  if (!size) return(NULL);
  ptr = malloc(size);
  if (ptr == NULL)
    Msg(ERROR, "Out of Memory in Malloc");
  return(ptr);
}

void *Calloc(size_t num, size_t size)
{
  void *ptr;

  if (!size) return(NULL);
  ptr = calloc(num, size);
  if (ptr == NULL)
    Msg(ERROR, "Out of Memory in Calloc");
  return(ptr);
}

void *Realloc(void *ptr, size_t size)
{
  if (!size) return(NULL);
  ptr = realloc(ptr,size);
  if (ptr == NULL)
    Msg(ERROR, "Out of Memory in Realloc");
  return(ptr);
}

void Free(void *ptr)
{
  if (ptr == NULL) return;
  free(ptr);
}
