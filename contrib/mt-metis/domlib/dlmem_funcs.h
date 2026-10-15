/**
 * @file dlmem.h
 * @brief Memory functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-08-19
 */




/* prefixing ugliness */
#define DLMEM_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLMEM_PRE1(prefix,suffix) DLMEM_PRE2(prefix,suffix)
#define DLMEM_PUB(name) DLMEM_PRE1(DLMEM_PREFIX,name)
#define DLMEM_RPUB(name) DLMEM_PRE1(r,DLMEM_PRE1(DLMEM_PREFIX,name))
#define DLMEM_PRI(name) DLMEM_PRE1(_,DLMEM_PRE1(DLMEM_PREFIX,name))



/******************************************************************************
* DOUBLE POINTER FUNCTIONS ****************************************************
******************************************************************************/


#ifndef DLMEM_VISIBILITY
  #define DLMEM_VISIBILITY
  #define DLMEM_DEFVIS
#endif


#define __DL_MK_RMEM_FUNCS_DALLOC_CASE(t_t,i,ptr,vec,nvec,alloc) \
  case sizeof(t_t) : \
    for ((i)=0;(i)<(nvec);++(i)) { \
      (ptr)[i] = alloc(((t_t*)(vec))[i]); \
    } \
    break


#define __DL_MK_RMEM_FUNCS_INIT_DALLOC_CASE(t_t,i,val,ptr,vec,nvec,alloc) \
  case sizeof(t_t) : \
    for ((i)=0;(i)<(nvec);++(i)) { \
      (ptr)[i] = alloc(val,((t_t*)(vec))[i]); \
    } \
    break




/******************************************************************************
* FUNCTIONS *******************************************************************
******************************************************************************/


DLMEM_VISIBILITY DLMEM_TYPE_T * DLMEM_PUB(alloc)(
    size_t const n) 
{ 
  DLMEM_TYPE_T * ptr;

  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"Allocated %zu bytes at:\n",n*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif
  ptr = malloc(sizeof(DLMEM_TYPE_T)*n); 

  if (ptr == NULL && n > 0) {
    wprintf("Failed to allocate '%zu' bytes\n",n*sizeof(DLMEM_TYPE_T));
  }
  return ptr;
}


DLMEM_VISIBILITY DLMEM_TYPE_T * DLMEM_PUB(calloc)(
    size_t const n) 
{ 
  DLMEM_TYPE_T * ptr;

  #if defined(DLMEM_DLTYPE) && DLMEM_DLTYPE == DLTYPE_STRUCT && \
      defined(DLMEM_INITFUNCTION)
  size_t i;

  ptr = malloc(n*sizeof(DLMEM_TYPE_T)); 

  if (ptr != NULL) {
    DLMEM_INITFUNCTION(ptr); 
    DLMEM_TYPE_T val = ptr[0]; 
    for (i=1;i<n;++i) { 
      ptr[i] = val; 
    } 
  }
  #else
  ptr = (DLMEM_TYPE_T *) calloc(n,sizeof(DLMEM_TYPE_T)); 
  #endif

  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"cAllocated %zu bytes at:\n",n*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif

  if (ptr == NULL && n > 0) {
    wprintf("Failed to allocate '%zu' bytes\n",n*sizeof(DLMEM_TYPE_T));
  }

  return ptr; 
}


DLMEM_VISIBILITY void DLMEM_PUB(copy)(
    DLMEM_TYPE_T * const __DL_RESTRICT dst, 
    DLMEM_TYPE_T const * const __DL_RESTRICT src, 
    size_t const n) 
{ 
  memcpy(dst,src,sizeof(DLMEM_TYPE_T)*n); 
}


DLMEM_VISIBILITY void DLMEM_PUB(move)(
    DLMEM_TYPE_T * const dst, 
    DLMEM_TYPE_T const * const src, 
    size_t const n) 
{
  memmove(dst,src,sizeof(DLMEM_TYPE_T)*n); 
}


DLMEM_VISIBILITY void DLMEM_PUB(set)(
    DLMEM_TYPE_T * const dst, 
    DLMEM_TYPE_T const val, 
    size_t const n) 
{ 
  size_t i; 
  #if defined(DLMEM_DLTYPE) && \
      (DLMEM_DLTYPE == DLTYPE_INTEGRAL || DLMEM_DLTYPE == DLTYPE_FLOAT)
  unsigned char * data = (unsigned char*)&val; 
  if (sizeof(DLMEM_TYPE_T) == 1) { 
    memset(dst,(int)val,n); 
  } else if (n < 64) { 
    for (i=0;i<n;++i) { 
      dst[i] = val; 
    } 
  } else { 
    for (i=1;i<sizeof(DLMEM_TYPE_T);++i) { 
      if (data[i] != data[0]) { 
        break; 
      } 
    } 
    if (i == sizeof(DLMEM_TYPE_T)) { 
      memset(dst,(int)data[0],n*sizeof(DLMEM_TYPE_T)); 
    } else { 
      for (i=0;i<n;++i) { 
        dst[i] = val; 
      } 
    } 
  } 
  #else
  for (i=0;i<n;++i) { 
    dst[i] = val; 
  } 
  #endif
}


DLMEM_VISIBILITY DLMEM_TYPE_T * DLMEM_PUB(init_alloc)(
    DLMEM_TYPE_T const val, 
    size_t const n) 
{ 
  DLMEM_TYPE_T * ptr; 

  #if defined(DLMEM_DLTYPE) && \
      (DLMEM_DLTYPE == DLTYPE_INTEGRAL || DLMEM_DLTYPE == DLTYPE_FLOAT)
  if (val == (DLMEM_TYPE_T)0) {
    ptr = DLMEM_PUB(calloc)(n);
  } else { 
    ptr = DLMEM_PUB(alloc)(n); 
    if (ptr != NULL && n > 0) {
      DLMEM_PUB(set)(ptr,val,n); 
    }
  }
  #else 
  ptr = DLMEM_PUB(alloc)(n); 
  if (ptr != NULL && n > 0) {
    DLMEM_PUB(set)(ptr,val,n); 
  }
  #endif

  return ptr;
}


DLMEM_VISIBILITY DLMEM_TYPE_T * DLMEM_PUB(realloc)(
    DLMEM_TYPE_T * const ptr, 
    size_t newsize) 
{ 
  DLMEM_TYPE_T * nptr;

  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"reAllocated %zu bytes at:\n",newsize*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif

  nptr = realloc(ptr,newsize*sizeof(DLMEM_TYPE_T)); 

  if (nptr == NULL && newsize > 0) {
    wprintf("Failed to reallocate %zu bytes\n",newsize*sizeof(DLMEM_TYPE_T));
  }

  return nptr;
}


DLMEM_VISIBILITY DLMEM_TYPE_T * DLMEM_PUB(duplicate)(
    DLMEM_TYPE_T const * const src, 
    size_t const n) 
{ 
  size_t i; 
  DLMEM_TYPE_T * ptr;

  ptr = DLMEM_PUB(alloc)(n); 

  if (ptr != NULL) {
    for (i=0;i<n;++i) { 
      ptr[i] = src[i]; 
    } 
  }
  
  return ptr; 
}


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(alloc)(
    size_t n) 
{ 
  DLMEM_TYPE_T ** ptr;

  if (n == 0) {
    n = 1;
  }

  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"Allocated %zu bytes at:\n",n*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif

  ptr = malloc(sizeof(DLMEM_TYPE_T*)*n); 

  if (ptr == NULL) {
    wprintf("Failed to allocate '%zu' bytes\n",n*sizeof(DLMEM_TYPE_T));
  }

  return ptr;
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(calloc)(
    size_t n)
{ 
  DLMEM_TYPE_T ** ptr;

  if (n == 0) {
    n = 1;
  }

  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"cAllocated %zu bytes at:\n",n*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif
  ptr = calloc(n,sizeof(DLMEM_TYPE_T*)); 

  if (ptr == NULL) {
    wprintf("Failed to allocate '%zu' bytes\n",n*sizeof(DLMEM_TYPE_T));
  }
  return ptr;
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(dalloc)(
    void const * const vec, 
    size_t const svec, 
    size_t const nvec) 
{ 
  size_t i; 

  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(nvec); 
  switch (svec) { 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint8_t,i,ptr,vec,nvec, DLMEM_PUB(alloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint16_t,i,ptr,vec,nvec, DLMEM_PUB(alloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint32_t,i,ptr,vec,nvec, DLMEM_PUB(alloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint64_t,i,ptr,vec,nvec, DLMEM_PUB(alloc)); 
    default: 
      dl_error("Unable resolveable vsize = "PF_SIZE_T"\n",svec); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(dcalloc)(
    void const * const vec, 
    size_t const svec,
    size_t const nvec) 
{ 
  size_t i; 
  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(nvec); 
  switch (svec) { 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint8_t,i,ptr,vec,nvec, DLMEM_PUB(calloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint16_t,i,ptr,vec,nvec, DLMEM_PUB(calloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint32_t,i,ptr,vec,nvec, DLMEM_PUB(calloc)); 
    __DL_MK_RMEM_FUNCS_DALLOC_CASE(uint64_t,i,ptr,vec,nvec, DLMEM_PUB(calloc)); 
    default: 
      dl_error("Unable resolveable vsize = "PF_SIZE_T"\n",svec); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY void DLMEM_RPUB(copy)(
    DLMEM_TYPE_T ** const __DL_RESTRICT dst, 
    DLMEM_TYPE_T * const * const __DL_RESTRICT src, 
    size_t const n) 
{ 
  memcpy(dst,src,sizeof(DLMEM_TYPE_T*)*n); 
} 


DLMEM_VISIBILITY void DLMEM_RPUB(move)(
    DLMEM_TYPE_T ** const dst, 
    DLMEM_TYPE_T * const * const src, 
    const size_t n) 
{ 
  memmove(dst,src,sizeof(DLMEM_TYPE_T*)*n); 
}


DLMEM_VISIBILITY void DLMEM_RPUB(set)(
    DLMEM_TYPE_T ** const dst, 
    DLMEM_TYPE_T * const val, 
    size_t const n) 
{ 
  size_t i; 
  for (i=0;i<n;++i) { 
    dst[i] = val; 
  } 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(init_alloc)(
    DLMEM_TYPE_T * const val, 
    size_t const n) 
{ 
  DLMEM_TYPE_T ** ptr; 
  ptr = DLMEM_RPUB(alloc)(n); 
  DLMEM_RPUB(set)(ptr,val,n); 
  return ptr; 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(init_dalloc)(
    DLMEM_TYPE_T const val, 
    void const * const vec, 
    size_t const svec, 
    size_t const nvec) 
{ 
  size_t i; 
  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(nvec); 
  switch (svec) { 
    __DL_MK_RMEM_FUNCS_INIT_DALLOC_CASE(uint8_t,i,val,ptr,vec,nvec, 
        DLMEM_PUB(init_alloc)); 
    __DL_MK_RMEM_FUNCS_INIT_DALLOC_CASE(uint16_t,i,val,ptr,vec,nvec, 
        DLMEM_PUB(init_alloc)); 
    __DL_MK_RMEM_FUNCS_INIT_DALLOC_CASE(uint32_t,i,val,ptr,vec,nvec, 
        DLMEM_PUB(init_alloc)); 
    __DL_MK_RMEM_FUNCS_INIT_DALLOC_CASE(uint64_t,i,val,ptr,vec,nvec, 
        DLMEM_PUB(init_alloc)); 
    default: 
      dl_error("Unable resolveable vsize = "PF_SIZE_T"\n",svec); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(realloc)(
    DLMEM_TYPE_T ** ptr, 
    size_t const newsize) 
{ 
  #ifdef DL_HEAP_PROFILE
  fprintf(stderr,"reAllocated %zu bytes at:\n",newsize*sizeof(DLMEM_TYPE_T));
  __BACKTRACE();
  #endif
  return (DLMEM_TYPE_T**) realloc(ptr,newsize*sizeof(DLMEM_TYPE_T*)); 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(sym_alloc)(
    size_t const m, 
    size_t const n) 
{ 
  size_t i; 

  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(n); 
  for (i=0;i<n;++i) { 
    ptr[i] = DLMEM_PUB(alloc)(m); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(sym_calloc)(
    size_t const m, 
    size_t const n) 
{ 
  size_t i; 

  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(n); 
  for (i=0;i<n;++i) { 
    ptr[i] = DLMEM_PUB(calloc)(m); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY DLMEM_TYPE_T ** DLMEM_RPUB(sym_init_alloc)(
    DLMEM_TYPE_T val, 
    size_t const m, 
    size_t const n) 
{ 
  size_t i; 

  DLMEM_TYPE_T ** ptr = DLMEM_RPUB(alloc)(n); 
  for (i=0;i<n;++i) { 
    ptr[i] = DLMEM_PUB(init_alloc)(val,m); 
  } 
  return ptr; 
} 


DLMEM_VISIBILITY void DLMEM_RPUB(free)(
    DLMEM_TYPE_T ** ptr, 
    size_t const n) 
{ 
  size_t i; 

  for (i=0;i<n;++i) { 
    dl_free(ptr[i]); 
  } 
  dl_free(ptr); 
}

#ifdef DLMEM_DEFVIS
  #undef DLMEM_VISIBILITY
  #undef DLMEM_DEFVIS
#endif

#undef DLMEM_PRE2
#undef DLMEM_PRE1
#undef DLMEM_PUB
#undef DLMEM_RPUB




