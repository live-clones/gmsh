/**
 * @file dlrand_headers.h
 * @brief Function prototypes for generating random numbers and shuffling
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */


#ifndef DLRAND_STATIC


/* prefixing ugliness */
#define DLRAND_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLRAND_PRE1(prefix,suffix) DLRAND_PRE2(prefix,suffix)
#define DLRAND_PUB(name) DLRAND_PRE1(DLRAND_PREFIX,name)
#define DLRAND_RPUB(name) DLRAND_PRE1(r,DLRAND_PRE1(DLRAND_PREFIX,name))


DLRAND_TYPE_T DLRAND_PUB(rand)(DLRAND_TYPE_T min, DLRAND_TYPE_T max);


DLRAND_TYPE_T DLRAND_PUB(rand_r)(DLRAND_TYPE_T min, DLRAND_TYPE_T max, 
    unsigned int * seed);


DLRAND_TYPE_T * DLRAND_PUB(shuffle)(DLRAND_TYPE_T * ptr, size_t n);


DLRAND_TYPE_T * DLRAND_PUB(shuffle_r)(DLRAND_TYPE_T * ptr, size_t n, 
    unsigned int * seed);


DLRAND_TYPE_T * DLRAND_PUB(pseudo_shuffle)(DLRAND_TYPE_T * ptr, 
    size_t nshuffles, size_t n);


DLRAND_TYPE_T * DLRAND_PUB(pseudo_shuffle_r)(DLRAND_TYPE_T * ptr, 
    size_t nshuffles, size_t n, unsigned int * seed);


DLRAND_TYPE_T * DLRAND_PUB(fill_rand)(DLRAND_TYPE_T min, DLRAND_TYPE_T max, 
    DLRAND_TYPE_T * ptr, size_t n);


DLRAND_TYPE_T * DLRAND_PUB(fill_rand_r)(DLRAND_TYPE_T min, DLRAND_TYPE_T max, 
    DLRAND_TYPE_T * ptr, size_t n, unsigned int * seed);


#undef DLRAND_PRE2
#undef DLRAND_PRE1
#undef DLRAND_PUB
#undef DLRAND_PRI


#else


#define DLRAND_VISIBILITY static
#include "dlrand_funcs.h"
#undef DLRAND_VISIBILITY


#endif
