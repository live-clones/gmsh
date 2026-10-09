/**
 * @file dlgklib.h
 * @brief GKlib compatibility macros 
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */



#ifndef DL_GKLIB_H
#define DL_GKLIB_H

#include "domlib.h"
#include "GKlib/GKlib.h"

/*
 * This file contains the neccessary macros to allow domlib to work with gklib
 * (use all of the gklib memory functions) as best as possible.
 */

/* fix my free */
#ifdef dl_free
  #undef dl_free
#endif
#define dl_free(ptr) \
  gk_free((void**)&(ptr),LTERM)

/* delete previous definitions */
#ifdef DL_MK_MEM_FUNCS
  #undef DL_MK_MEM_FUNCS
#endif

/* put in the correct definitions */
#define DL_MK_MEM_FUNCS(prefix,type) \
  type * prefix ## _alloc(const size_t n) \
  { \
    return prefix ## malloc(n,"domlib:alloc()"); \
  } \
  type * prefix ## _calloc(const size_t n) \
  { \
    type * ptr = prefix ## malloc(n,"domlib:calloc()"); \
    memset(ptr,0,sizeof(type)*n); \
    return ptr; \
  } \
  type * prefix ## _copy(type * dst, const type * src, const size_t n) \
  { \
    return prefix ## copy(n,(type*)src,dst); \
  } \
  type * prefix ## _set(type * dst, const type val, const size_t n) \
  { \
    return prefix ## set(n,val,dst); \
  } \
  type * prefix ## _realloc(type * ptr, size_t n) \
  { \
    return prefix ## realloc(ptr,n,"domlib:realloc()"); \
  } \
  type * prefix ## _duplicate(const type * src, const size_t n) \
  { \
    type * dst = prefix ## _alloc(n); \
    return prefix ## _copy(dst,src,n); \
  }

/* there are no numerically optimized versions in gklib */
#ifdef DL_MK_NMEM_FUNCS
  #undef DL_MK_NMEM_FUNCS
#endif
#define DL_MK_NMEM_FUNCS(prefix,type) \
  DL_MK_MEM_FUNCS(prefix,type)

/* because dllist.h has special structs that need initializing and I want to
 * keep all hacks in here, rather than in multiple files */
#ifdef DL_MK_LIST_HEADERS
  #undef DL_MK_LIST_HEADERS
  #define DL_MK_LIST_HEADERS(prefix,type) \
    __DL_MK_LIST_HEADERS(prefix,type) \
    GK_MKALLOC_PROTO(prefix ## node, prefix ## node_t) \
    GK_MKALLOC_PROTO(prefix ## _linkedlist, prefix ## _linkedlist_t) \
    GK_MKALLOC_PROTO(prefix ## _arraylist, prefix ## _arraylist_t)
#endif
#ifdef DL_MK_LIST_FUNCS
  #undef DL_MK_LIST_FUNCS
  #define DL_MK_LIST_FUNCS(prefix,type) \
    __DL_MK_LIST_FUNCS(prefix,type) \
    GK_MKALLOC(prefix ## node, prefix ## node_t) \
    GK_MKALLOC(prefix ## _linkedlist, prefix ## _linkedlist_t) \
    GK_MKALLOC(prefix ## _arraylist, prefix ## _arraylist_t)
#endif

#endif
