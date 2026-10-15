/**
 * @file dlbuffer_funcs.h
 * @brief Buffer functions 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */




/* prefixing ugliness */
#define DLBUFFER_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLBUFFER_PRE1(prefix,suffix) DLBUFFER_PRE2(prefix,suffix)
#define DLBUFFER_PUB(name) DLBUFFER_PRE1(DLBUFFER_PREFIX,name)
#define DLBUFFER_PRI(name) DLBUFFER_PRE1(_,DLBUFFER_PRE1(DLBUFFER_PREFIX,name))


#ifndef DLBUFFER_VISIBILITY
  #define DLBUFFER_DEFVIS
  #define DLBUFFER_VISIBILITY
#endif


/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLBUFFER_PUB(buffer)
#define DLMEM_TYPE_T DLBUFFER_PUB(buffer_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_PREFIX 
#undef DLMEM_TYPE_T
#undef DLMEM_STATIC



/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static const size_t DLBUFFER_PRI(DEFAULT_BUFFER_SIZE) = 128;




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


DLBUFFER_VISIBILITY DLBUFFER_PUB(buffer_t) * DLBUFFER_PUB(buffer_init)(
    const size_t size, DLBUFFER_PUB(buffer_t) * const b)
{
  b->size = 0;
  b->maxsize = size;
  b->defsize = size;
  b->elements = (DLBUFFER_TYPE_T*)malloc(sizeof(DLBUFFER_TYPE_T)*b->maxsize);
  return b;
}


DLBUFFER_VISIBILITY DLBUFFER_PUB(buffer_t) * DLBUFFER_PUB(buffer_create)(
    const size_t size)
{
  DLBUFFER_PUB(buffer_t) * b = DLBUFFER_PUB(buffer_alloc)(1);
  return DLBUFFER_PUB(buffer_init)(size,b);
}


DLBUFFER_VISIBILITY size_t DLBUFFER_PUB(buffer_add)(const DLBUFFER_TYPE_T val,
    DLBUFFER_PUB(buffer_t) * const b)
{
  if (b->size >= b->maxsize) {
    if (b->maxsize == 0) {
      b->defsize = b->maxsize = DLBUFFER_PRI(DEFAULT_BUFFER_SIZE);
      b->elements = 
        (DLBUFFER_TYPE_T*)malloc(sizeof(DLBUFFER_TYPE_T)*b->maxsize);
    } else {
      b->maxsize *= 2;
      b->elements = (DLBUFFER_TYPE_T*)realloc(b->elements,
          sizeof(DLBUFFER_TYPE_T)*b->maxsize);
    }
  }
  b->elements[b->size++] = val;
  return b->size;
}


DLBUFFER_VISIBILITY size_t DLBUFFER_PUB(buffer_clear)(
    DLBUFFER_PUB(buffer_t) * const b)
{
  size_t a = b->size;
  b->size = 0;
  return a;
}


DLBUFFER_VISIBILITY size_t DLBUFFER_PUB(buffer_reset)(
    DLBUFFER_PUB(buffer_t) * const b)
{
  size_t a = b->size;
  b->size = 0;
  if (b->maxsize != b->defsize) {
    b->elements = (DLBUFFER_TYPE_T*)
      realloc(b->elements,sizeof(DLBUFFER_TYPE_T)*b->defsize);
    b->maxsize = b->defsize;
  }
  return a;
}


DLBUFFER_VISIBILITY void DLBUFFER_PUB(buffer_free)(
    DLBUFFER_PUB(buffer_t) * b)
{
  if (b->maxsize > 0) {
    dl_free(b->elements);
  }
  dl_free(b);
}



#ifdef DLBUFFER_DEFVIS
  #undef DLBUFFER_DEFVIS
  #undef DLBUFFER_VISIBILITY
#endif


#undef DLBUFFER_PRE2
#undef DLBUFFER_PRE1
#undef DLBUFFER_PUB
#undef DLBUFFER_PRI



