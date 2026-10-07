/**
 * @file domlib.c
 * @brief Basic memory and math operations for basic types
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DOMLIB_C
#define DOMLIB_C




#include "domlib.h"




/******************************************************************************
* CODE GENERATION *************************************************************
******************************************************************************/




#ifdef __DL_USE_GKLIB__
  GK_MKALLOC(size,size_t)
  GK_MKALLOC(ssize,ssize_t)
  GK_MKALLOC(char,char)
#endif


/* size_t */
#define DLMEM_PREFIX size
#define DLMEM_TYPE_T size_t
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#include "dlmem_funcs.h"
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX size
#define DLMATH_TYPE_T size_t
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_funcs.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX size
#define DLSORT_TYPE_T size_t
#define DLSORT_DLSIGN DLSIGN_UNSIGNED
#include "dlsort_funcs.h"
#undef DLSORT_DLSIGN
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX size
#define DLRAND_TYPE_T size_t
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#include "dlrand_funcs.h"
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX size
#define DLSTATS_TYPE_T size_t
#include "dlstats_funcs.h"
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


/* ssize_t */
#define DLMEM_PREFIX ssize
#define DLMEM_TYPE_T ssize_t
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#include "dlmem_funcs.h"
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX ssize
#define DLMATH_TYPE_T ssize_t
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_funcs.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX ssize
#define DLSORT_TYPE_T ssize_t
#define DLSORT_DLSIGN DLSIGN_SIGNED
#include "dlsort_funcs.h"
#undef DLSORT_DLSIGN
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX ssize
#define DLRAND_TYPE_T ssize_t
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#include "dlrand_funcs.h"
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T



/* int */
#define DLMEM_PREFIX int
#define DLMEM_TYPE_T int 
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#include "dlmem_funcs.h"
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX int
#define DLMATH_TYPE_T int
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_funcs.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX int
#define DLSORT_TYPE_T int
#define DLSORT_DLSIGN DLSIGN_SIGNED
#include "dlsort_funcs.h"
#undef DLSORT_DLSIGN
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX int
#define DLRAND_TYPE_T int
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#include "dlrand_funcs.h"
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


/* char */
#define DLMEM_PREFIX char
#define DLMEM_TYPE_T char
#include "dlmem_funcs.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


/* double */
#define DLMEM_PREFIX double
#define DLMEM_TYPE_T double 
#define DLMEM_DLTYPE DLTYPE_FLOAT
#include "dlmem_funcs.h"
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX double
#define DLMATH_TYPE_T double
#define DLMATH_DLTYPE DLTYPE_FLOAT
#include "dlmath_funcs.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX double
#define DLRAND_TYPE_T double
#define DLRAND_DLTYPE DLTYPE_FLOAT
#include "dlrand_funcs.h"
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T





#endif
