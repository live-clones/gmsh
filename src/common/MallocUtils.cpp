// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <stdlib.h>

#include "MallocUtils.h"
#include "GmshMessage.h"

void *Malloc(size_t size)
{
  void *ptr;

  if(!size) return (nullptr);
  ptr = malloc(size);
  if(ptr == nullptr) Msg::Error("Out of memory (buy some more RAM!)");
  return ptr;
}

void *Calloc(size_t num, size_t size)
{
  void *ptr;

  if(!size) return (nullptr);
  ptr = calloc(num, size);
  if(ptr == nullptr) Msg::Error("Out of memory (buy some more RAM!)");
  return ptr;
}

void *Realloc(void *ptr, size_t size)
{
  if(!size) return (nullptr);
  ptr = realloc(ptr, size);
  if(ptr == nullptr) Msg::Error("Out of memory (buy some more RAM!)");
  return ptr;
}

void Free(void *ptr)
{
  if(ptr == nullptr) return;
  free(ptr);
}
