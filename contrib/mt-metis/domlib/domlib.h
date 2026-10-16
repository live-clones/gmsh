/**
 * @file domlib.h
 * @brief Master header file for DOMLIB
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DOMLIB_H
#define DOMLIB_H




/******************************************************************************
* INCLUDE MODIFIERS ***********************************************************
******************************************************************************/


#define _GNU_SOURCE 1
#define _FILE_OFFSET_BITS 64


#ifndef __USE_POSIX
#define __USE_POSIX 1
#endif


#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 1
#endif




/******************************************************************************
* C HEADERS *****************************************************************
******************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h> 
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <execinfo.h>
#include <errno.h>




/******************************************************************************
* PRIMITIVES *******************************************************************
******************************************************************************/


#define PF_SIZE_T "%zu"
#define RF_SIZE_T PF_SIZE_T
#define PF_SSIZE_T "%zd"
#define RF_SSIZE_T PF_SSIZE_T
#define PF_CHAR_T "%c"
#define RF_CHAR_T PF_CHAR_T
#define PF_PTR_T "%p"
#define RF_PTR_T PF_PTR_T




/******************************************************************************
* MACRO VARIABLE TYPES ********************************************************
******************************************************************************/


#define DLTYPE_INTEGRAL 0x1000
#define DLTYPE_FLOAT 0x1001
#define DLTYPE_STRUCT 0x1002
#define DLSIGN_SIGNED 0x1100
#define DLSIGN_UNSIGNED 0x1101




/******************************************************************************
* DOMLIB LIBRARIES ************************************************************
******************************************************************************/


/* blue headers */
#include "dlmacros.h"
#include "dldebug.h"
#include "dlsort.h"
/* white headers */
#include "dlutil.h"
#include "dlenv.h"
#include "dlprint.h"
#include "dlstring.h"
#include "dlfile.h"
#include "dlcmdline.h"
#include "dlterm.h"
#include "dlthread.h"
#include "dlthread_pool.h"
/* gklib compatability */
#ifdef USE_GKLIB
  #define __DL_USE_GKLIB__ 1
  #include "dlgklib.h"
#endif




/******************************************************************************
* CODE GENERATION *************************************************************
******************************************************************************/


#ifdef __DL_USE_GKLIB__
  GK_MKALLOC_PROTO(size,size_t)
  GK_MKALLOC_PROTO(ssize,ssize_t)
  GK_MKALLOC_PROTO(char,char)
  GK_MKALLOC_PROTO(int,int)
  GK_MKALLOC_PROTO(void,void)
#endif


/* size_t */
#define DLMEM_PREFIX size
#define DLMEM_TYPE_T size_t
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX size
#define DLMATH_TYPE_T size_t
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_headers.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX size
#define DLSORT_TYPE_T size_t
#include "dlsort_headers.h"
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX size
#define DLRAND_TYPE_T size_t
#include "dlrand_headers.h"
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX size
#define DLSTATS_TYPE_T size_t
#include "dlstats_headers.h"
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


/* ssize_t */
#define DLMEM_PREFIX ssize
#define DLMEM_TYPE_T ssize_t
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX ssize
#define DLMATH_TYPE_T ssize_t
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_headers.h"
#undef DLMATH_DLSIGN
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX ssize
#define DLSORT_TYPE_T ssize_t
#include "dlsort_headers.h"
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX ssize
#define DLRAND_TYPE_T ssize_t
#include "dlrand_headers.h"
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX ssize
#define DLSTATS_TYPE_T ssize_t
#include "dlstats_headers.h"
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


/* int */
#define DLMEM_PREFIX int
#define DLMEM_TYPE_T int 
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX int
#define DLMATH_TYPE_T int
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#include "dlmath_headers.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLSORT_PREFIX int
#define DLSORT_TYPE_T int
#include "dlsort_headers.h"
#undef DLSORT_PREFIX
#undef DLSORT_TYPE_T


#define DLRAND_PREFIX int
#define DLRAND_TYPE_T int
#include "dlrand_headers.h"
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX int
#define DLSTATS_TYPE_T int
#include "dlstats_headers.h"
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


/* char */
#define DLMEM_PREFIX char
#define DLMEM_TYPE_T char
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


/* double */
#define DLMEM_PREFIX double
#define DLMEM_TYPE_T double 
#include "dlmem_headers.h"
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX double
#define DLMATH_TYPE_T double
#define DLMATH_DLTYPE DLTYPE_FLOAT
#include "dlmath_headers.h"
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX double
#define DLRAND_TYPE_T double
#include "dlrand_headers.h"
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T




/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


static inline void dl_free(
    void * ptr)
{
  free(ptr);
}




#endif
