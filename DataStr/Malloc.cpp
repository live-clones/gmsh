// $Id: Malloc.cpp,v 1.10 2002-05-18 07:18:00 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <malloc.h>
#endif

#include "Malloc.h"
#include "Message.h"

void *Malloc(size_t size){
  void *ptr;

  if (!size) return(NULL);
  ptr = malloc(size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void *Calloc(size_t num, size_t size){
  void *ptr;

  if (!size) return(NULL);
  ptr = calloc(num, size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void *Realloc(void *ptr, size_t size){
  if (!size) return(NULL);
  ptr = realloc(ptr,size);
  if (ptr == NULL)
    Msg(FATAL, "Out of memory (buy some more RAM!)");
  return(ptr);
}

void Free(void *ptr){
  if (ptr == NULL) return;
  free(ptr);
}
