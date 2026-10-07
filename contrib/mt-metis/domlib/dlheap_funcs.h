/**
 * @file dlheap_funcs.h
 * @brief Functions for heaps
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */




/* prefixing ugliness */
#define DLHEAP_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLHEAP_PRE1(prefix,suffix) DLHEAP_PRE2(prefix,suffix)
#define DLHEAP_PUB(name) DLHEAP_PRE1(DLHEAP_PREFIX,name)
#define DLHEAP_PRI(name) DLHEAP_PRE1(_,DLHEAP_PRE1(DLHEAP_PREFIX,name))




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static inline size_t DLHEAP_PRI(leftchild)(size_t i)
{
  return (2*i)+1;
}


static inline size_t DLHEAP_PRI(rightchild)(size_t i)
{
  return (2*i)+2;
}


static inline size_t DLHEAP_PRI(parent)(size_t i)
{
  return (i-1)>>1;
}


static inline int DLHEAP_PRI(isorder)(const DLHEAP_TYPE_T a, 
    const DLHEAP_TYPE_T b)
{
  #ifdef DLHEAP_MIN

  #ifdef DLHEAP_KEY
  return a.DLHEAP_KEY < b.DLHEAP_KEY;
  #else
  return a < b;
  #endif /* DLHEAP_KEY */

  #else

  #ifdef DLHEAP_KEY
  return a.DLHEAP_KEY > b.DLHEAP_KEY;
  #else
  return a > b;
  #endif /* DLHEAP_KEY */

  #endif /* DLHEAP_MIN */
}



/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLHEAP_VISIBILITY
  #define DLHEAP_VISIBILITY
  #define DLHEAP_DEFVIS
#endif


DLHEAP_VISIBILITY DLHEAP_PUB(heap_t) * DLHEAP_PUB(heap_create)(
    size_t const n)
{
  DLHEAP_PUB(heap_t) * heap;
  
  heap = (DLHEAP_PUB(heap_t)*)malloc(sizeof(DLHEAP_PUB(heap_t)));
  heap->maxsize = n;
  heap->size = 0;
  heap->elements = DLHEAP_PUB(alloc)(heap->maxsize);

  return heap;
}


DLHEAP_VISIBILITY void DLHEAP_PUB(heap_expand)(
    DLHEAP_PUB(heap_t) * const heap)
{
  heap->elements = DLHEAP_PUB(realloc)(heap->elements,heap->maxsize*=2);
}


DLHEAP_VISIBILITY void DLHEAP_PUB(heap_free)(
    DLHEAP_PUB(heap_t) * heap)
{
  free(heap->elements);
  free(heap);
}


DLHEAP_VISIBILITY void DLHEAP_PUB(heap_push)(
    DLHEAP_TYPE_T const val,
    DLHEAP_PUB(heap_t) * const heap)
{
  size_t i, j;

  if (heap->size == heap->maxsize) {
    DLHEAP_PUB(heap_expand)(heap);
  }
  i = heap->size++;
  j = DLHEAP_PRI(parent)(i);
  while (i > 0 && !DLHEAP_PRI(isorder)(heap->elements[j],val)) {
    heap->elements[i] = heap->elements[j];
    i = j;
    j = DLHEAP_PRI(parent)(i);
  }
  heap->elements[i] = val;
}


DLHEAP_VISIBILITY DLHEAP_TYPE_T DLHEAP_PUB(heap_pop)(
    DLHEAP_PUB(heap_t) * const heap)
{
  size_t i,j,k;
  DLHEAP_TYPE_T num, val;

  i = 0;
  num = heap->elements[i];
  val = heap->elements[--heap->size];
  while (1) {
    heap->elements[i] = val;
    j = DLHEAP_PRI(leftchild)(i);
    k = DLHEAP_PRI(rightchild)(i);
    if (j < heap->size) {
      if (k < heap->size && !DLHEAP_PRI(isorder)(val,heap->elements[k]) && 
          !DLHEAP_PRI(isorder)(heap->elements[j],heap->elements[k])) {
        heap->elements[i] = heap->elements[k];
        i = k;
      } else if (!DLHEAP_PRI(isorder)(val,heap->elements[j])) {
        heap->elements[i] = heap->elements[j];
        i = j;
      } else {
        break;
      }
    } else {
      break;
    }
  }
  return num;
}


DLHEAP_VISIBILITY DLHEAP_TYPE_T DLHEAP_PUB(heap_peek)(
    DLHEAP_PUB(heap_t) const * const heap)
{
  return heap->elements[0];
}




#ifdef DLHEAP_DEFVIS
  #undef DLHEAP_VISIBILITY
  #undef DLHEAP_DEFVIS
#endif


#undef DLHEAP_PRE2
#undef DLHEAP_PRE1
#undef DLHEAP_PUB
#undef DLHEAP_PRI



