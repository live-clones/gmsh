/**
 * @file base.h
 * @brief Base types etc.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2013, Regents of the University of Minnesota
 * @version 1
 * @date 2013-05-20
 */




#ifndef MTMETIS_BASE_H
#define MTMETIS_BASE_H




/******************************************************************************
* EXTERNAL INCLUDES ***********************************************************
******************************************************************************/

#ifndef __USE_POSIX
#define __USE_POSIX 1
#endif

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <mtmetis.h>
#include <domlib.h>




/******************************************************************************
* MACRO INCLUDES **************************************************************
******************************************************************************/


#include "strings.h"
#include "macros.h"




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


#ifdef MTMETIS_64BIT_THREADS
typedef uint64_t mtmetis_tid_type;
#else
typedef uint32_t mtmetis_tid_type;
#endif


typedef int64_t mtmetis_twgt_type;
typedef uint16_t mtmetis_offset_type;


/* rename mtmetis.h types for internal use */
#define vtx_type mtmetis_vtx_type
#define adj_type mtmetis_adj_type
#define wgt_type mtmetis_wgt_type
#define twgt_type mtmetis_twgt_type
#define pid_type mtmetis_pid_type
#define tid_type mtmetis_tid_type
#define real_type mtmetis_real_type
#define offset_type mtmetis_offset_type




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


/* macros */
#define DEF_NULL_VTX ((vtx_type)-1)
#define DEF_NULL_ADJ ((adj_type)-1)
#define DEF_NULL_PID ((pid_type)-1)
#define DEF_NULL_TID ((tid_type)-1)
#define DEF_NULL_WGT ((wgt_type)-1)
#define DEF_NULL_OFFSET ((offset_type)-1)


/* type null values */
static const vtx_type NULL_VTX = DEF_NULL_VTX;
static const wgt_type NULL_WGT = DEF_NULL_WGT;
static const adj_type NULL_ADJ = DEF_NULL_ADJ;
static const pid_type NULL_PID = DEF_NULL_PID;
static const tid_type NULL_TID = DEF_NULL_TID;
static const offset_type NULL_OFFSET = DEF_NULL_OFFSET;


/* thread specific constants */
static const vtx_type BLOCKSIZE = 0x1000;
static const int BLOCKSHIFT = 12;
static const vtx_type BLOCKMASK = 0x0FFF;




/******************************************************************************
* DOMLIB MACROS ***************************************************************
******************************************************************************/


/* vtx_type */
#define DLMEM_PREFIX vtx
#define DLMEM_TYPE_T vtx_type
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX vtx
#define DLMATH_TYPE_T vtx_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE 
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX vtx
#define DLRAND_TYPE_T vtx_type
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#define DLRAND_STATIC
#include "dlrand_headers.h"
#undef DLRAND_STATIC
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX vtx
#define DLSTATS_TYPE_T vtx_type
#define DLSTATS_STATIC
#include "dlstats_headers.h"
#undef DLSTATS_STATIC
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


#define DLISET_PREFIX vtx
#define DLISET_TYPE_T vtx_type
#define DLISET_STATIC
#include "dliset_headers.h"
#undef DLISET_STATIC
#undef DLISET_TYPE_T
#undef DLISET_PREFIX


#define DLTHREAD_PREFIX vtx
#define DLTHREAD_TYPE_T vtx_type
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX


#define DLSORT_PREFIX vtx
#define DLSORT_TYPE_T vtx_type
#define DLSORT_STATIC
#include "dlsort_headers.h"
#undef DLSORT_STATIC
#undef DLSORT_TYPE_T
#undef DLSORT_PREFIX




/* adj_type */
#define DLMEM_PREFIX adj
#define DLMEM_TYPE_T adj_type
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX adj
#define DLMATH_TYPE_T adj_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX adj
#define DLRAND_TYPE_T adj_type
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#define DLRAND_STATIC
#include "dlrand_headers.h"
#undef DLRAND_STATIC
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX adj
#define DLSTATS_TYPE_T adj_type
#define DLSTATS_STATIC
#include "dlstats_headers.h"
#undef DLSTATS_STATIC
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


#define DLTHREAD_PREFIX adj
#define DLTHREAD_TYPE_T adj_type
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX




/* pid_type */
#define DLMEM_PREFIX pid
#define DLMEM_TYPE_T pid_type
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX pid
#define DLMATH_TYPE_T pid_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE 
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX pid
#define DLRAND_TYPE_T pid_type
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#define DLRAND_STATIC
#include "dlrand_headers.h"
#undef DLRAND_STATIC
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX pid
#define DLSTATS_TYPE_T pid_type
#define DLSTATS_STATIC
#include "dlstats_headers.h"
#undef DLSTATS_STATIC
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


/* tid_type */
#define DLMEM_PREFIX tid
#define DLMEM_TYPE_T tid_type
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX tid
#define DLMATH_TYPE_T tid_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE 
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


/* wgt_type */
#define DLMEM_PREFIX wgt
#define DLMEM_TYPE_T wgt_type
#define DLMEM_DLTYPE DLTYPE_INTEGRAL
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX wgt
#define DLMATH_TYPE_T wgt_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLRAND_PREFIX wgt
#define DLRAND_TYPE_T wgt_type
#define DLRAND_DLTYPE DLTYPE_INTEGRAL
#define DLRAND_STATIC
#include "dlrand_headers.h"
#undef DLRAND_STATIC
#undef DLRAND_DLTYPE
#undef DLRAND_PREFIX
#undef DLRAND_TYPE_T


#define DLSTATS_PREFIX wgt
#define DLSTATS_TYPE_T wgt_type
#define DLSTATS_STATIC
#include "dlstats_headers.h"
#undef DLSTATS_STATIC
#undef DLSTATS_PREFIX
#undef DLSTATS_TYPE_T


#define DLTHREAD_PREFIX wgt
#define DLTHREAD_TYPE_T wgt_type
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX


/* twgt_type */
#define DLTHREAD_PREFIX twgt
#define DLTHREAD_TYPE_T twgt_type
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX


#define DLMATH_PREFIX twgt
#define DLMATH_TYPE_T twgt_type
#define DLMATH_DLTYPE DLTYPE_INTEGRAL
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


/* real_type */
#define DLMEM_PREFIX real
#define DLMEM_TYPE_T real_type
#define DLMEM_DLTYPE DLTYPE_FLOAT
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_DLTYPE
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMATH_PREFIX real
#define DLMATH_TYPE_T real_type
#define DLMATH_DLTYPE DLTYPE_FLOAT
#define DLMATH_STATIC
#include "dlmath_headers.h"
#undef DLMATH_STATIC
#undef DLMATH_DLTYPE
#undef DLMATH_PREFIX
#undef DLMATH_TYPE_T


#define DLTHREAD_PREFIX double
#define DLTHREAD_TYPE_T double
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX


/* int */

#define DLTHREAD_PREFIX int
#define DLTHREAD_TYPE_T int
#define DLTHREAD_STATIC 1
#include "dlthread_reduction_headers.h"
#undef DLTHREAD_STATIC
#undef DLTHREAD_TYPE_T
#undef DLTHREAD_PREFIX


/* offset_type */

#define DLMEM_PREFIX offset
#define DLMEM_TYPE_T offset_type
#define DLMEM_STATIC 1
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* MACROS **********************************************************************
******************************************************************************/


#ifdef DEBUG
  #define par_dprintf(...) \
    do { \
      _Pragma("omp master") \
      { \
        dprintf( __VA_ARGS__ ); \
      } \
    } while(0)
#else
  #define par_dprintf(...)
#endif

#define par_vprintf(...) \
  do { \
    _Pragma("omp master") \
    { \
      vprintf( __VA_ARGS__ ); \
    } \
  } while(0)




/******************************************************************************
* INLINE FUNCTIONS ************************************************************
******************************************************************************/


static inline vtx_type gvtx_to_lvtx(
    vtx_type const v, 
    vtx_type const mask)
{
  DL_ASSERT(mask > 0,"The mask is set to 0!\n");
  DL_ASSERT(v > mask,"Global vertex number is smaller than mask (gvtx = %"
      PF_VTX_T", mask = %"PF_VTX_T")\n",v,mask);
  return v & mask;
}


static inline vtx_type lvtx_to_gvtx(
    vtx_type const v, 
    tid_type const t, 
    int const shift)
{
  DL_ASSERT(shift > 0,"The mask size is set to 0!\n");
  DL_ASSERT(v < (vtx_type)(1 << shift),"Local vertex number is greater than "
      "shift (lvtx = %"PF_VTX_T", shift = %d)\n",v,shift);
  return ((t+1) << shift) | v;
}


static inline tid_type gvtx_to_tid(
    vtx_type const v, 
    int const shift)
{
  DL_ASSERT(shift > 0,"The shift size is set to %d!\n",shift);
  DL_ASSERT(v >= (vtx_type)(1 << shift),"Global vertex number is too small "
      "(gvtx = %"PF_VTX_T", shift = %d)\n",v,shift);
  return (v >> shift)-1;
}


static inline vtx_type max_gvtx(
    int const shift, 
    tid_type const nthreads) 
{
  return (vtx_type)(1 << shift)*(nthreads+1);
}


static inline int is_bnd(
    wgt_type const id,
    wgt_type const ed,
    int const greedy)
{
  if (greedy) {
    return ed >= id;
  } else {
    return (ed > 0) || (id == 0);
  }
}


/* avoid having to pass each element */
#define gvtx_to_lvtx(v,dist) gvtx_to_lvtx(v,(dist).mask)
#define lvtx_to_gvtx(v,t,dist) lvtx_to_gvtx(v,t,(dist).shift)
#define gvtx_to_tid(v,dist) gvtx_to_tid(v,(dist).shift)
#define max_gvtx(graph) max_gvtx((graph)->dist.shift,(graph)->dist.nthreads)






#endif
