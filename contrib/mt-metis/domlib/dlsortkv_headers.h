/**
 * @file dlsortkv_headers.h
 * @brief Sorting function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-05-12
 */




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


#ifndef DLSORTKV_STATIC


/* prefixing ugliness */
#define DLSORTKV_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSORTKV_PRE1(prefix,suffix) DLSORTKV_PRE2(prefix,suffix)
#define DLSORTKV_PUB(name) DLSORTKV_PRE1(DLSORTKV_PREFIX,name)
#define DLSORTKV_RPI(name) DLSORTKV_PRE1(_,DLSORTKV_PRE1(DLSORTKV_PREFIX,name))


#ifndef DLSORTKV_SIZE_T
  #define DLSORTKV_SIZE_DEFAULT
  #define DLSORTKV_SIZE_T size_t
#endif


DLSORTKV_VAL_T * DLSORTKV_PUB(countingsort_kv)(
    const DLSORTKV_KEY_T * keys, 
    const DLSORTKV_VAL_T * vals,
    DLSORTKV_KEY_T min,
    DLSORTKV_KEY_T max,
    DLSORTKV_SIZE_T n,
    DLSORTKV_VAL_T * out,
    DLSORTKV_SIZE_T ** r_counts);


#undef DLSORTKV_PRE2
#undef DLSORTKV_PRE1
#undef DLSORTKV_PUB
#undef DLSORTKV_PRI

#ifdef DLSORTKV_SIZE_DEFAULT
  #undef DLSORTKV_SIZE_DEFAULT
  #undef DLSORTKV_SIZE_T
#endif

#else


#define DLSORTKV_VISIBILITY static
#include "dlsortkv_funcs.h"
#undef DLSORTKV_VISIBILITY


#endif
