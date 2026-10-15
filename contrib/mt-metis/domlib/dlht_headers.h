/**
 * @file dlht_headers.h
 * @brief Hashtable function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */



/* prefixing ugliness */
#define DLHT_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLHT_PRE1(prefix,suffix) DLHT_PRE2(prefix,suffix)
#define DLHT_PUB(name) DLHT_PRE1(DLHT_PREFIX,name)
#define DLHT_PRI(name) DLHT_PRE1(_,DLHT_PRE1(DLHT_PREFIX,name))




typedef struct DLHT_PRI(ht_kv_t) {
  DLHT_KEY_T key;
  DLHT_VAL_T val;
  int next; /* some day may need to be ssize_t */
} DLHT_PRI(ht_kv_t);


typedef struct DLHT_PUB(ht_t) {
  size_t size;
  size_t hashsize;
  size_t maxsize;
  size_t hashmask;
  int csize;
  int cidx;
  DLHT_PRI(ht_kv_t) * __DL_RESTRICT elements;
  DLHT_PRI(ht_kv_t) * __DL_RESTRICT chain;
} DLHT_PUB(ht_t);


#ifndef DLHT_STATIC


DLHT_PUB(ht_t) * DLHT_PUB(ht_create)(
    size_t size, 
    int csize);


DLHT_VAL_T DLHT_PUB(ht_get)(
    DLHT_KEY_T key, 
    DLHT_PUB(ht_t) const * map);


DLHT_VAL_T DLHT_PUB(ht_put)(
    DLHT_KEY_T key, 
    DLHT_VAL_T val, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_min)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_max)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_add)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_multiply)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av,
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_and)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_or)(
    DLHT_KEY_T key, 
    DLHT_VAL_T av, 
    DLHT_PUB(ht_t) * map);


DLHT_VAL_T DLHT_PUB(ht_remove)(
    DLHT_KEY_T key, 
    DLHT_PUB(ht_t) * map);


int DLHT_PUB(ht_contains)(
    DLHT_KEY_T key, 
    DLHT_PUB(ht_t) const * map);


size_t DLHT_PUB(ht_clear)(
    DLHT_PUB(ht_t) * map);


void DLHT_PUB(ht_clear_chains)(
    DLHT_PUB(ht_t) * map);


void DLHT_PUB(ht_clear_slot)(
    DLHT_KEY_T key, 
    DLHT_PUB(ht_t) * map);


int DLHT_PUB(ht_adjust_size)(
    size_t newsize, 
    DLHT_PUB(ht_t) * map);


void DLHT_PUB(ht_free)(
    DLHT_PUB(ht_t) * map);


#undef DLHT_PRE1
#undef DLHT_PRE2
#undef DLHT_PUB
#undef DLHT_PRI


#else


#undef DLHT_PRE1
#undef DLHT_PRE2
#undef DLHT_PUB
#undef DLHT_PRI


#define DLHT_VISIBILITY static
#include "dlht_funcs.h"
#undef DLHT_VISIBILITY


#endif

