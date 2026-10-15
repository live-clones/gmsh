/**
 * @file strings.h
 * @brief String defines for mt-Metis
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright 2014, Regents of the University of Minnesota
 * @version 1
 * @date 2014-09-21
 */




#ifndef MTMETIS_STRINGS_H
#define MTMETIS_STRINGS_H




#include <inttypes.h>




/******************************************************************************
* STRINGS *********************************************************************
******************************************************************************/



/* TYPE FORMATS **************************************************************/


#define PF_UINT32_T PRIu32
#define PF_UINT64_T PRIu64
#define PF_INT32_T PRId32
#define PF_INT64_T PRId64
#define PF_FLOAT_T "0.05f"
#define PF_DOUBLE_T "0.05lf"



#ifdef MTMETIS_64BIT_VERTICES
#define PF_VTX_T PF_UINT64_T
#else
#define PF_VTX_T PF_UINT32_T
#endif
#ifdef MTMETIS_64BIT_EDGES
#define PF_ADJ_T PF_UINT64_T
#else
#define PF_ADJ_T PF_UINT32_T
#endif
#ifdef MTMETIS_64BIT_WEIGHTS
#define PF_WGT_T PF_INT64_T
#else
#define PF_WGT_T PF_INT32_T
#endif
#ifdef MTMETIS_64BIT_PARTITIONS
#define PF_PID_T PF_UINT64_T
#else
#define PF_PID_T PF_UINT32_T
#endif
#ifdef MTMETIS_64BIT_THREADS
#define PF_TID_T PF_UINT64_T
#else
#define PF_TID_T PF_UINT32_T
#endif
#ifdef MTMETIS_DOUBLE_REAL
#define PF_REAL_T PF_DOUBLE_T
#else
#define PF_REAL_T PF_FLOAT_T
#endif


/* never changes */
#define PF_TWGT_T PF_INT64_T



/* OPTIONS *******************************************************************/

#define MTMETIS_STR_CTYPE_RM "rm"
#define MTMETIS_STR_CTYPE_SHEM "shem"
#define MTMETIS_STR_CTYPE_FC "fc"

#define MTMETIS_STR_CONTYPE_CLS "ls"
#define MTMETIS_STR_CONTYPE_DENSE "dense"
#define MTMETIS_STR_CONTYPE_SORT "sort"

#define MTMETIS_STR_PTYPE_KWAY "kway"
#define MTMETIS_STR_PTYPE_ESEP "esep"
#define MTMETIS_STR_PTYPE_RB "rb"
#define MTMETIS_STR_PTYPE_VSEP "vsep"
#define MTMETIS_STR_PTYPE_ND "nd"

#define MTMETIS_STR_RTYPE_FM "fm"
#define MTMETIS_STR_RTYPE_SFM "sfm"
#define MTMETIS_STR_RTYPE_SFG "sfg"
#define MTMETIS_STR_RTYPE_GREEDY "greedy"
#define MTMETIS_STR_RTYPE_HS "hs"
#define MTMETIS_STR_RTYPE_KPM "kpm"

#define MTMETIS_STR_VERBOSITY_NONE "none"
#define MTMETIS_STR_VERBOSITY_LOW "low"
#define MTMETIS_STR_VERBOSITY_MEDIUM "medium"
#define MTMETIS_STR_VERBOSITY_HIGH "high"
#define MTMETIS_STR_VERBOSITY_MAXIMUM "maximum"

#define MTMETIS_STR_DISTRIBUTION_BLOCK "block"
#define MTMETIS_STR_DISTRIBUTION_CYCLIC "cyclic"
#define MTMETIS_STR_DISTRIBUTION_BLOCKCYCLIC "blockcyclic"

#define MTMETIS_STR_IGNORE_NONE "none"
#define MTMETIS_STR_IGNORE_VERTEXWEIGHTS "vtx"
#define MTMETIS_STR_IGNORE_EDGEWEIGHTS "edge"
#define MTMETIS_STR_IGNORE_BOTH "both"

#define MTMETIS_STR_SCANTYPE_SQRT "sqrt"
#define MTMETIS_STR_SCANTYPE_1PC "1%"
#define MTMETIS_STR_SCANTYPE_5PC "5%"
#define MTMETIS_STR_SCANTYPE_25PC "25%"
#define MTMETIS_STR_SCANTYPE_FULL "full"



#endif
