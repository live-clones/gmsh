// $Id: Malloc.cpp,v 1.9 2002-02-13 09:20:41 stainier Exp $
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <malloc.h>
#endif

#include "Malloc.h"
#include "Message.h"

void *Malloc(size_t size)
{
  void *ptr;

  if (!size) return(NULL);
  ptr = malloc(size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void *Calloc(size_t num, size_t size)
{
  void *ptr;

  if (!size) return(NULL);
  ptr = calloc(num, size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void *Realloc(void *ptr, size_t size)
{
  if (!size) return(NULL);
  ptr = realloc(ptr,size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void Free(void *ptr)
{
  if (ptr == NULL) return;
  free(ptr);
}
