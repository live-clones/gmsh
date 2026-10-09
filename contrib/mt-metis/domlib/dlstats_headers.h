/**
 * @file dlstats_headers.h
 * @brief Function prototypes for calculating statistics
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */



#ifndef DLSTATS_STATIC


/* prefixing ugliness */
#define DLSTATS_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSTATS_PRE1(prefix,suffix) DLSTATS_PRE2(prefix,suffix)
#define DLSTATS_PUB(name) DLSTATS_PRE1(DLSTATS_PREFIX,name)
#define DLSTATS_PRI(name) DLSTATS_PRE1(r,DLSTATS_PRE1(DLSTATS_PREFIX,name))




/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


double DLSTATS_PUB(arithmetic_mean)(const DLSTATS_TYPE_T * ptr, size_t n);


double DLSTATS_PUB(geometric_mean)(const DLSTATS_TYPE_T * ptr, size_t n);


double DLSTATS_PUB(stddev)(const DLSTATS_TYPE_T * ptr, size_t n);


DLSTATS_TYPE_T DLSTATS_PUB(median)(const DLSTATS_TYPE_T * ptr, size_t n);


#undef DLSTATS_PRE2
#undef DLSTATS_PRE1
#undef DLSTATS_PUB
#undef DLSTATS_PRI

#else


#define DLSTATS_VISIBILITY static
#include "dlstats_funcs.h"
#undef DLSTATS_VISIBILITY


#endif
